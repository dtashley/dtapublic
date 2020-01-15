#----------------------------------------------------------------------------------------
#$Header: svn://localhost/dtapublic/pubs/books/ucbka/trunk/scripts/cp_script.tcl 273 2019-08-11 21:24:46Z dashley $
#----------------------------------------------------------------------------------------
# David T. Ashley (DASHLEY@GMAIL.COM)
#----------------------------------------------------------------------------------------
# Tcl script (using Tk extensions, so it must be run under Tk/Wish) to build and package
# both Dave Ashley's microcontroller software book, and the associated ESRG Tool set.  This
# script is also included with the source code of either so that the script can be used
# by those who have purchased or otherwise obtained the LaTeX source for the book or the
# source for the ESRG Tool Set to do the build.
#----------------------------------------------------------------------------------------
#The version control information below is extracted by this Tcl script and incorporated
#into the back of the title page.  This takes the place of the "main .TEX file" information
#that was there previously.  Since the main files are now generated on the fly by the Tcl
#script, this is the logical replacement.  Version control information is included so
#that if anything goes awry, the origin and what was being used can be tracked down.
#
#AUTOMATIC MARKER:  BEGIN SCRIPT VERSION CONTROL INFORMATION
#$HeadURL: svn://localhost/dtapublic/pubs/books/ucbka/trunk/scripts/cp_script.tcl $
#$Revision: 273 $
#$Date: 2019-08-11 17:24:46 -0400 (Sun, 11 Aug 2019) $
#$Author: dashley $
#AUTOMATIC MARKER:  END SCRIPT VERSION CONTROL INFORMATION
#
#****************************************************************************************
#****************************************************************************************
#****    U T I L I T Y    F U N C T I O N S    ******************************************
#****************************************************************************************
#****************************************************************************************
# Exit procedure.  Exits unconditionally.  Clicked in response
# to the button marked EXIT.
#
proc exitProc { } { \
   global buildlogfilehandle

   #Put the system date and time into the build log and on the console.
   set buildendtimestamp [clock seconds]
   set s0 [clock format $buildendtimestamp -format "Execution ending at: %A, %B %d, %Y; %I:%M:%S %p."]
   outboth $s0
   thickhlineboth
   close $buildlogfilehandle
   exit 0
   }

#-----------------------------------------------------------------------------
#Writes a contiguous group of a number of characters (or strings) to a stream,
#without a terminating newline.

proc contiggrouptostream { thestream thechar howmany } {
   for {set i 0} {$i < $howmany} {incr i} {
      puts -nonewline $thestream $thechar
      }
      
   return
   } 

#----------------------------------------------------------------------------------------
#Copies (binary) from src to dest, destroying dest in advance.
proc destructive_binary_copy { src dest } {
   #Delete dest, if it exists.
   file delete $dest
   
   set srchandle [open $src  "r"]
   set dsthandle [open $dest "w"]   

   fconfigure $srchandle -translation binary
   fconfigure $dsthandle -translation binary
   
   fcopy $srchandle $dsthandle
   
   close $srchandle
   close $dsthandle
   
   return
   }

#****************************************************************************************
#****************************************************************************************
#****    N U M B E R I N G    F U N C T I O N S    **************************************
#****************************************************************************************
#****************************************************************************************
# Each function here has to do with numbering parts, chapters, etc.
#
# Returns the lower-case string corresponding to a digit.
proc lower_case_number_string { arg } { \
   switch -exact $arg {
      "0"     { return zero                        }
      "1"     { return one                         }
      "2"     { return two                         }
      "3"     { return three                       }
      "4"     { return four                        }
      "5"     { return five                        }
      "6"     { return six                         }
      "7"     { return seven                       }
      "8"     { return eight                       }
      "9"     { return nine                        }
      default { return INTERNAL_FUNCTION_PAR_ERROR }
      }
   }


# Returns the upper-case string corresponding to the
# roman numerals of a decimal number.  Algorithm is simple
# case because numbers won't get large enough to prevent
# enumeration.
proc upper_case_roman_numeral_string { arg } { \
   switch -exact $arg {
      "0"     { return ZERO_NOT_SUPPORTED_ROMAN    }
      "1"     { return I                           }
      "2"     { return II                          }
      "3"     { return III                         }
      "4"     { return IV                          }
      "5"     { return V                           }
      "6"     { return VI                          }
      "7"     { return VII                         }
      "8"     { return VIII                        }
      "9"     { return IX                          }
     "10"     { return X                           }
     "11"     { return XI                          }
     "12"     { return XII                         }
     "13"     { return XIII                        }
     "14"     { return XIV                         }
     "15"     { return XV                          }
     "16"     { return XVI                         }
     "17"     { return XVII                        }
     "18"     { return XVIII                       }
     "19"     { return XIX                         }
     "20"     { return XX                          }
     "21"     { return XXI                         }
     "22"     { return XXII                        }
     "23"     { return XXIII                       }
     "24"     { return XXIV                        }
     "25"     { return XXV                         }
     "26"     { return XXVI                        }
     "27"     { return XXVII                       }
     "28"     { return XXVIII                      }
     "29"     { return XXIX                        }
     "30"     { return XXX                         }
     "31"     { return XXXI                        }
     "32"     { return XXXII                       }
     "33"     { return XXXIII                      }
     "34"     { return XXXIV                       }
     "35"     { return XXXV                        }
     "36"     { return XXXVI                       }
     "37"     { return XXXVII                      }
     "38"     { return XXXVIII                     }
     "39"     { return XXXIX                       }
     "40"     { return XXXX                        }
     "41"     { return XXXXI                       }
     "42"     { return XXXXII                      }
     "43"     { return XXXXIII                     }
     "44"     { return XXXXIV                      }
     "45"     { return XXXXV                       }
     "46"     { return XXXXVI                      }
     "47"     { return XXXXVII                     }
     "48"     { return XXXXVIII                    }
     "49"     { return IL                          }
      default { return INTERNAL_FUNCTION_PAR_ERROR }
      }
   }

#****************************************************************************************
#****************************************************************************************
#****    T E X T    M A N I P U L A T I O N    F U N C T I O N S    *********************
#****************************************************************************************
#****************************************************************************************
#
# Replaces all digits in a string with their textual strings.  This is used to form
# commands whose names the LaTeX compiler will accept.
proc replace_digits_with_alphas { arg } { \
   set result ""
   set N [string length $arg]

   for {set i 0} {$i < $N} {incr i} { \
      set c [string index $arg $i]

      if {[string first $c "0123456789"] == -1} { \
         #Isn't a digit, just append.
         append result $c
         } \
      else { 
         #Is a digit, must expand and append.
         append result [lower_case_number_string $c]
         }
      }

   return $result
   }

#Replaces any spaces in a string with the HTML code %20.  This is necessary to
#to achieve the proper HTML syntax when putting filenames in in come contexts.
#
proc replace_spaces_with_HTML_codes { tgt } { \
   set tgt [string map {" " "%20"} $tgt]
   return $tgt
   }


#****************************************************************************************
#****************************************************************************************
#****    V E R S I O N    C O N T R O L    E X T R A C T I O N    F U N C T I O N S    **
#****************************************************************************************
#****************************************************************************************
#Extracts the version control information lines (marked automatically above) from this
#file and returns them as a string.  The string includes all newline characters.

proc extract_this_scripts_version_control_information { } { \
   #Define the strings that we'll accept as beginning the
   #block of version control information and the strings
   #that we'll accept as terminating it.
   set begin_string "AUTOMATIC MARKER:  BEGIN SCRIPT VERSION CONTROL INFORMATION"
   set end_string   "AUTOMATIC MARKER:  END SCRIPT VERSION CONTROL INFORMATION"

   #Initialize our return value to nothing so far.
   set rv ""

   #Open the script for extraction.
   set script_handle [open scripts/cp_script.tcl r]

   #Leaf through the file until we hit the end of file or else the beginning string.
   set eof_found 0
   set beginstring_found 0
   while {!$eof_found && !$beginstring_found} { \
      set current_line [gets $script_handle]
      set beginstring_found_index [string first $begin_string $current_line]
      set beginstring_found [expr $beginstring_found_index >= 0]
      set eof_found [eof $script_handle]
      }

   if {!$eof_found} { \
      #If we're here, we got the begin string we were looking for.  Copy over 
      #until the end string is encountered or until end of file.
      set endstring_found 0
      while {!$eof_found && !$endstring_found} { \
         set current_line [gets $script_handle]

         #If the first character of the line is a Tcl comment delimieter (which it
         #most likely is), trash it.
         set current_line [string trimleft $current_line "#"]

         set endstring_found_index [string first $end_string $current_line]
         set endstring_found [expr $endstring_found_index >= 0]
         set eof_found [eof $script_handle]
         if {!$endstring_found} { \
            append rv $current_line "\n"
            }
         }
      }

   #Close the script file.
   close $script_handle

   #Return the extracted version control information.
   return $rv
   }

#****************************************************************************************
#****************************************************************************************
#****    L O G G I N G    F U N C T I O N S    ******************************************
#****************************************************************************************
#****************************************************************************************
# Each function in this category is called as an aid in maintaing a log file and a
# console display which say exactly the same thing.
#----------------------------------------------------------------------------------------
#Writes a contiguous group of a number of characters to the standard output,
#plus to the build log file.

proc contiggrouptoboth { thechar howmany } {
   global buildlogfilehandle
   
   contiggrouptostream $buildlogfilehandle $thechar  $howmany
   contiggrouptostream stdout              $thechar  $howmany
      
   return
   }

#-----------------------------------------------------------------------------
#Writes a line of $loglinelength hyphens followed by a newline to only the
#console, but not the build log file.

proc hlineconsole {} {
   global loglinelength
   
   contiggrouptostream stdout - $loglinelength
   puts ""
   
   return
   }

#-----------------------------------------------------------------------------
#Writes a line of $loglinelength hyphens followed by a newline to both the 
#console and the build log file.

proc hlineboth {} {
   global loglinelength
   global buildlogfilehandle
   
   contiggrouptoboth - $loglinelength
   puts $buildlogfilehandle ""
   puts ""
   
   return
   }

#-----------------------------------------------------------------------------
#Writes a line of $loglinelength "=" chars followed by a newline to only the
#console but not the build log file.

proc thickhlineconsole {} {
   global loglinelength
   
   contiggrouptostream stdout = $loglinelength
   puts ""
   
   return
   }

#-----------------------------------------------------------------------------
#Writes a line of $loglinelength "=" chars followed by a newline to both the 
#console and the build log file.

proc thickhlineboth {} {
   global loglinelength
   global buildlogfilehandle
   
   contiggrouptoboth = $loglinelength
   puts $buildlogfilehandle ""
   puts ""
   
   return
   }

#-----------------------------------------------------------------------------
#Dumps output to both the console and the log file, with newline attached.
proc outboth { arg } {
   global buildlogfilehandle
   
   puts $buildlogfilehandle $arg
   puts $arg 
   
   return  
   }   

#-----------------------------------------------------------------------------
#Dumps output to both the console and the log file, without newline attached.
proc outbothnonl { arg } {
   global buildlogfilehandle
   
   puts -nonewline $buildlogfilehandle $arg
   puts -nonewline $arg 
   
   return  
   }   

#-----------------------------------------------------------------------------
#Prints a banner to the passed stream indicating success or failure of a build
#script.  The two messages are "*OK*" and "FAIL".  The failflag, if 0, means
#success, or if non-zero, means failure.  The banner will be centered
#in the output.  $nearpadchar and $farpadchar are the characters used to pad
#the centering near the banner letters and farther away.  $nearfarmargin is
#the number of characters for which the near characters extend.  
proc passfailbannertostream { thestream passfailflag nearpadchar farpadchar nearfarmargin} {

    global loglinelength
    
    set passbanner {
       " OOOOO   K     K" \
       "O     O  K   K  " \
       "O     O  K K    " \
       "O     O  KK     " \
       "O     O  K K    " \
       "O     O  K  K   " \
       "O     O  K   K  " \
       "O     O  K    K " \
       " OOOOO   K     K" \
       }
    set failbanner {
       "FFFFFFF    AAA      III    L      " \
       "F         A   A      I     L      " \
       "F        A     A     I     L      " \
       "F        A     A     I     L      " \
       "FFFFFF   AAAAAAA     I     L      " \
       "F        A     A     I     L      " \
       "F        A     A     I     L      " \
       "F        A     A     I     L      " \
       "F        A     A    III    LLLLLLL" \
       }

   #First we need to calculate the number of chars on the left with which
   #to pad the the result.
   
   if {$passfailflag != 0} {
      #Fail
      set banner $failbanner
      } \
   else { 
      #Pass
      set banner $passbanner
      }
      
   #Determine the width of the banner which applies.
   set bannerwidth [string length [lindex $banner 0] ]
   
   #Calculate the size in chars to use for the far padding.
   set farpadwidth [expr "($loglinelength - $bannerwidth - (2 * $nearfarmargin ) ) >> 1"]     
   
   #If by poor choice of all values we ended up with a negative number, clip it to zero.
   if {$farpadwidth < 0} {
      set farpadwidth 0
      }
      
   #Iterate to output the lines of the banner.
   foreach curline $banner {
      for {set i 0} {$i < $farpadwidth} {incr i} {
         puts -nonewline $thestream $farpadchar
         }
         
      for {set i 0} {$i < $nearfarmargin} {incr i} {
         puts -nonewline $thestream $nearpadchar
         }
         
      puts -nonewline $thestream $curline
      
      for {set i 0} {$i < $nearfarmargin} {incr i} {
         puts -nonewline $thestream $nearpadchar
         }

      for {set i 0} {$i < $farpadwidth} {incr i} {
         puts -nonewline $thestream $farpadchar
         }

      puts $thestream ""               
      }
          
   return  
   }   

#****************************************************************************************
#****************************************************************************************
#****    D A T A    S T R U C T U R E    U T I L I T Y    F U N C T I O N S    **********
#****************************************************************************************
#****************************************************************************************
# Each function in this category provides a function related to the data structures
# embedded in the script.  Generally, errors are all fatal.
#----------------------------------------------------------------------------------------
# Indexes the volume list by the 4-letter tag.  This is done for lookup speed.
proc IndexVolumeList { } { \
   global bookVolumeList
   global bookVolumeListStructSize
   global bookVolumeListIndex

   outboth "Indexing volume list."

   set N [llength $bookVolumeList]

   for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
      set elem [lindex $bookVolumeList $i]

      set bookVolumeListIndex($elem) $i

      outboth "   bookVolumeList($elem) = $i"
      }

   hlineboth
   }

#----------------------------------------------------------------------------------------
# Indexes the chapter list by the 4-letter tag.  This is done for lookup speed.
proc IndexChapterList { } { \
   global chapterList
   global chapterListStructSize
   global chapterListIndex

   outboth "Indexing chapter list."

   set N [llength $chapterList]

   for {set i 0} {$i < $N} {incr i $chapterListStructSize} { \
      set elem [lindex $chapterList $i]

      set chapterListIndex($elem) $i

      outboth "   chapterList($elem) = $i"
      }

   hlineboth
   }

#****************************************************************************************
#****************************************************************************************
#****    C H A P T E R    T A B L E    L O O K U P    F U N C T I O N S    **************
#****************************************************************************************
#****************************************************************************************
# Functions which look up chapter table information.
#----------------------------------------------------------------------------------------
#
# Returns the single-volume long title for a chapter.  Input is the 4-character
# chapter tag.  Chapter table must have been indexed in advance.
proc get_chap_long_single_volume_title { ctag } { \
   global chapterList
   global chapterListIndex

   set i $chapterListIndex($ctag)

   return [lindex $chapterList [expr $i + 1]]
   }

# Returns the single-volume short title for a chapter.  Input is the 4-character
# chapter tag.  Chapter table must have been indexed in advance.
proc get_chap_short_single_volume_title { ctag } { \
   global chapterList
   global chapterListIndex

   set i $chapterListIndex($ctag)

   return [lindex $chapterList [expr $i + 2]]
   }

#Mark an individual chapter (by tag) used.
proc mark_chapter_used { ctag } { \
   global chapterList
   global chapterListIndex

   #outboth "Inside chapter marking function, ctag is : $ctag"

   set i $chapterListIndex($ctag)

   set i [expr $i + 7]

   #outboth "Element selected for marking is : $i"

   #outboth "Current value is: [lindex $chapterList $i]"

   set chapterList [lreplace $chapterList $i $i 1]

   #outboth "New value is: [lindex $chapterList $i]"
   }


#Inquire if a given chapter (by tag) has its used flag set.
#Result is "1" if used, "0" otherwise.
proc get_chap_used_flag { ctag } { \
   global chapterList
   global chapterListStructSize
   global chapterListIndex

   set i $chapterListIndex($ctag)

   set i [expr $i + 7]

   return [lindex $chapterList $i]
   }


#Marks each of the chapters as unused (resets all of the "used" flags to zero).
proc mark_all_chaps_unused { } { \
   global chapterList
   global chapterListStructSize

   set N [llength $chapterList]

   for {set i 0} {$i < $N} {incr i $chapterListStructSize} { \
      set j [expr $i + 7]

      set chapterList [lreplace $chapterList $j $j 0]
      }
   }

#****************************************************************************************
#****************************************************************************************
#****    V O L U M E    T A B L E    L O O K U P    F U N C T I O N S    ****************
#****************************************************************************************
#****************************************************************************************
# Functions which lookup volume table information.
#----------------------------------------------------------------------------------------
# Returns the part string associated with a volume record in the volume table.  
# Input is the 4-character volume tag.  Volume table must have been indexed in advance.
proc get_vol_part_title { vtag } { \
   global bookVolumeList
   global bookVolumeListIndex

   set i $bookVolumeListIndex($vtag)

   return [lindex $bookVolumeList [expr $i + 3]]
   }

# Returns the multiple-volume long title associated with a volume.                
# Input is the 4-character volume tag.  Volume table must have been indexed in advance.
proc get_multi_vol_long_title { vtag } { \
   global bookVolumeList
   global bookVolumeListIndex

   set i $bookVolumeListIndex($vtag)

   return [lindex $bookVolumeList [expr $i + 4]]
   }

#Marks each of the volumes as unused (resets all of the "used" flags to zero).
proc mark_all_volumes_unused { } { \
   global bookVolumeList
   global bookVolumeListStructSize

   set N [llength $bookVolumeList]

   for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
      set j [expr $i + 7]

      set bookVolumeList [lreplace $bookVolumeList $j $j 0]
      }
   }

#Mark an individual volume (by tag) used.
proc mark_volume_used { vtag } { \
   global bookVolumeList
   global bookVolumeListIndex

   set i $bookVolumeListIndex($vtag)

   set i [expr $i + 7]

   set bookVolumeList [lreplace $bookVolumeList $i $i 1]
   }


#Inquire if a given volume (by tag) has its used flag set.
#Result is "1" if used, "0" otherwise.
proc get_volume_used_flag { vtag } { \
   global bookVolumeList
   global bookVolumeListStructSize
   global bookVolumeListIndex

   set i $bookVolumeListIndex($vtag)

   set i [expr $i + 7]

   return [lindex $bookVolumeList $i]
   }


#****************************************************************************************
#****************************************************************************************
#****    L A T E X    C O M P I L E    F U N C T I O N S    *****************************
#****************************************************************************************
#****************************************************************************************
# Each function in this category performs a function related to LaTeX compilation or 
# indexing.                        
#----------------------------------------------------------------------------------------
# Performs the LaTeX compile of the passed filename, in the "root" directory of the book.
# Any errors will cause the script to terminate.  It gets more attention that way, when
# an error kills the script.
#
proc LatexCompileFile { filename } { \
   global execLatexCompiler
   global errorCode

   #The error-handling strategy taken in this function is to terminate with a log file
   #entry if the LaTeX compiler chokes.  First of all, generally the LaTeX code is
   #debugged in the 4AllTex GUI, so we shouldn't be compiling bad LaTeX code here.
   #Second, this is a utility script, and not required to be graceful.  Third,
   #terminating the program will definitely get the user's attention, whereas any
   #lesser approach might not.
   outbothnonl "Using LaTeX to compile: $filename"
   outboth .
   hlineboth

   #The full path to the LaTeX compiler has already been calculated for us at
   #script startup.

   #Delete existing intermediate files if they exist.
   file delete tcl00out.txt
   file delete tcl00err.txt
               
   #Open the intermediate files for writing.
   set stdouthandle [open "tcl00out.txt" "w"]
   set stderrhandle [open "tcl00err.txt" "w"]

   #Execute exec and suppress errors.
   set catchreturncode 0
   set catchreturncode [catch {exec -- $execLatexCompiler -progname=latex &latex $filename >@ $stdouthandle 2>@ $stderrhandle}]
   set catcherrorcode $errorCode

   #Close both open files.
   close $stderrhandle
   close $stdouthandle
         
   if {$catchreturncode} {
      outbothnonl "$execLatexCompiler generated errors (information follows): $catchreturncode $catcherrorcode"
      outboth "."
      outboth "The build must be aborted."
      set compilefailed 1
      hlineboth
      } \
   else {
      outboth "$execLatexCompiler did not generate errors."
      set compilefailed 0
      hlineboth
      }

   set stdouthandle [open "tcl00out.txt" "r"]
   set stderrhandle [open "tcl00err.txt" "r"]
   set stdoutoutput [read $stdouthandle]
   set stderroutput [read $stderrhandle]
   close $stdouthandle
   close $stderrhandle

   #Delete existing intermediate files if they exist.
   file delete tcl00out.txt
   file delete tcl00err.txt
         
   outboth "Standard output stream from $execLatexCompiler invocation:"
   hlineboth
   outboth $stdoutoutput
   hlineboth
   outboth "Standard error stream from $execLatexCompiler invocation:"
   hlineboth
   outboth $stderroutput
   hlineboth

   if {$compilefailed} { \
      outboth "Compile has failed.  Must abort script."
      exitProc
      }

   update
   }

#----------------------------------------------------------------------------------------
# Runs the MAKEINDEX program for a file located in the root directory of the book.
# File parameter passed is just the "base" file name.
#
proc MakeOrdinaryIndexFile { filename } { \
   global execMakeindex
   global errorCode

   #The error-handling strategy taken in this function is to terminate with a log file
   #entry if the Makeindex utility chokes.  First of all, generally the LaTeX code is
   #debugged in the 4AllTex GUI, so we shouldn't be compiling bad LaTeX code here.
   #Second, this is a utility script, and not required to be graceful.  Third,
   #terminating the program will definitely get the user's attention, whereas any
   #lesser approach might not.
   outbothnonl "Using MAKEINDEX to process: $filename"
   outboth .
   hlineboth

   #The full path to the MAKEINDEX utility has already been calculated for us at
   #script startup.

   #Delete existing intermediate files if they exist.
   file delete tcl00out.txt
   file delete tcl00err.txt
               
   #Open the intermediate files for writing.
   set stdouthandle [open "tcl00out.txt" "w"]
   set stderrhandle [open "tcl00err.txt" "w"]

   #Execute exec and suppress errors.
   set catchreturncode 0
   set catchreturncode [catch {exec -- $execMakeindex $filename >@ $stdouthandle 2>@ $stderrhandle}]
   set catcherrorcode $errorCode

   #Close both open files.
   close $stderrhandle
   close $stdouthandle
         
   if {$catchreturncode} {
      outbothnonl "$execMakeindex generated errors (information follows): $catchreturncode $catcherrorcode"
      outboth "."
      outboth "The build must be aborted."
      set compilefailed 1
      hlineboth
      } \
   else {
      outboth "$execMakeindex did not generate errors."
      set compilefailed 0
      hlineboth
      }

   set stdouthandle [open "tcl00out.txt" "r"]
   set stderrhandle [open "tcl00err.txt" "r"]
   set stdoutoutput [read $stdouthandle]
   set stderroutput [read $stderrhandle]
   close $stdouthandle
   close $stderrhandle

   #Delete existing intermediate files if they exist.
   file delete tcl00out.txt
   file delete tcl00err.txt
         
   outboth "Standard output stream from $execMakeindex invocation:"
   hlineboth
   outboth $stdoutoutput
   hlineboth
   outboth "Standard error stream from $execMakeindex invocation:"
   hlineboth
   outboth $stderroutput
   hlineboth

   if {$compilefailed} { \
      outboth "$execMakeindex has failed.  Must abort script."
      exitProc
      }

   update
   }

#----------------------------------------------------------------------------------------
# Runs the DVIPS program to generate postscript output for a file located in the root 
# directory of the book.  File parameter passed is just the "base" file name.
#
proc RunDvipsToGenPsOutput { filename } { \
   global execDvips
   global errorCode
   global pathUcBookA

   #The error-handling strategy taken in this function is to terminate with a log file
   #entry if the DVIPS utility chokes.  First of all, generally the LaTeX code is
   #debugged in the 4AllTex GUI, so we shouldn't be compiling bad LaTeX code here.
   #Second, this is a utility script, and not required to be graceful.  Third,
   #terminating the program will definitely get the user's attention, whereas any
   #lesser approach might not.
   outbothnonl "Using DVIPS to process: $filename"
   outboth .
   hlineboth

   #The full path to the DVIPS utility has already been calculated for us at
   #script startup.

   #Delete existing intermediate files if they exist.
   file delete tcl00out.txt
   file delete tcl00err.txt
               
   #Open the intermediate files for writing.
   set stdouthandle [open "tcl00out.txt" "w"]
   set stderrhandle [open "tcl00err.txt" "w"]

   #Generate the full path names of interest.  We need to convert the forward slashes
   #in both names to backslashes because DVIPS accepts the file name and opens the file
   #itself.
   set dvips_input ""
   append dvips_input $pathUcBookA / $filename .dvi
   set dvips_input [string map {/ \\} $dvips_input]
   set dvips_output ""
   append dvips_output $pathUcBookA / $filename .ps
   set dvips_output [string map {/ \\} $dvips_output]

   #outboth $dvips_input
   #outboth $dvips_output

   #d:\4tex5.0\bin\win32\dvips.exe -P ljfive -o"c:\esrgubka\llr0.ps" "c:\esrgubka\llr0.dvi"

   #Execute exec and suppress errors.
   set catchreturncode 0
   set catchreturncode [catch {exec -- $execDvips -T 8.5in,11in -o$dvips_output $dvips_input >@ $stdouthandle 2>@ $stderrhandle}]
   set catcherrorcode $errorCode

   #Close both open files.
   close $stderrhandle
   close $stdouthandle
         
   if {$catchreturncode} {
      outbothnonl "$execDvips generated errors (information follows): $catchreturncode $catcherrorcode"
      outboth "."
      outboth "The build must be aborted."
      set compilefailed 1
      hlineboth
      } \
   else {
      outboth "$execDvips did not generate errors."
      set compilefailed 0
      hlineboth
      }

   set stdouthandle [open "tcl00out.txt" "r"]
   set stderrhandle [open "tcl00err.txt" "r"]
   set stdoutoutput [read $stdouthandle]
   set stderroutput [read $stderrhandle]
   close $stdouthandle
   close $stderrhandle

   #Delete existing intermediate files if they exist.
   file delete tcl00out.txt
   file delete tcl00err.txt
         
   outboth "Standard output stream from $execDvips invocation:"
   hlineboth
   outboth $stdoutoutput
   hlineboth
   outboth "Standard error stream from $execDvips invocation:"
   hlineboth
   outboth $stderroutput
   hlineboth

   if {$compilefailed} { \
      outboth "$execDvips has failed.  Must abort script."
      exitProc
      }

   update
   }

#----------------------------------------------------------------------------------------
# Modifies a PS file generated by DVIPS to be duplex.  This is done in a very crude way,
# by inserting PostScript.  It can probably be done more elegantly by using the configuration
# and startup files of DVIPS
#
proc ModifyPsToDuplex { filebasename } { \
   global errorCode
   global pathUcBookA

   outbothnonl "Modifying postscript to get duplex form of: $filebasename"
   outboth .
   update

   #Form the full path of both file names.
   set mod_input  ""
   set mod_output ""
   append mod_input  $pathUcBookA / $filebasename .ps
   append mod_output $pathUcBookA / $filebasename _duplex.ps

   set inhandle  [open $mod_input  "r"]
   set outhandle [open $mod_output "w"]

   #Set larger buffers to speed the I/O operations.
   fconfigure $inhandle  -buffering full -buffersize 200000
   fconfigure $outhandle -buffering full -buffersize 200000

   set oneshot 0

   while {! [eof $inhandle] } { \
      set line [gets $inhandle]
      puts $outhandle $line

      if { ! $oneshot } { \
	     if { [string match "*DVIPSSource*" $line] } { \
		    puts $outhandle "<< /Duplex true >> setpagedevice"
			set oneshot 1
		    }
	     }
      }

   #Close both open files.
   close $inhandle
   close $outhandle

   hlineboth

   update
   }


#****************************************************************************************
#****************************************************************************************
#****    L A T E X    S O U R C E    F I L E    G E N E R A T I O N    ******************
#****************************************************************************************
#****************************************************************************************
#Outputs the file title line of a LaTeX book source file.
#
proc output_title_line { handle filename desc} { \
   puts $handle "%[string toupper $filename]:  $desc"
   puts $handle "%"

   set preamble {
      "%-----------------------------------------------------------------------------------"                   \
      "%This is an automatically generated file and not version-controlled.  This file is"                     \
      "%generated by the script CP_SCRIPT.TCL."                                                                \
      "%-----------------------------------------------------------------------------------"                   \
      "%"                                                                                                      \
      }

   for {set i 0} {$i < [llength $preamble]} {incr i} { \
      puts $handle [lindex $preamble $i]
      }
   }

#Outputs the LaTeX document class and package includes.
#
proc output_doc_class_and_package_includes { handle } { \
   set preamble {
      "\\documentclass[letterpaper,10pt,titlepage]\{custbook\}"                                                \
      "%"                                                                                                      \
      "\\pagestyle\{headings\}"                                                                                \
      "%"                                                                                                      \
      "\\usepackage\{amsmath\}"                                                                                \
      "\\usepackage\{amsfonts\}"                                                                               \
      "\\usepackage\{amssymb\}"                                                                                \
      "\\usepackage[ansinew]\{inputenc\}"                                                                      \
      "\\usepackage[OT1]\{fontenc\}"                                                                           \
      "\\usepackage\{graphicx\}"                                                                               \
      "\\usepackage\{makeidx\}"                                                                                \
      "%"                                                                                                      \
      }

   for {set i 0} {$i < [llength $preamble]} {incr i} { \
      puts $handle [lindex $preamble $i]
      }
   }


#Outputs the final matter in both types of volumes.  The "final matter" is the 
#stuff after the chapter includes up until but not including final
#file annunciator.
#
proc output_tex_volume_final_matter { handle } { \
   set final_matter {
      "%Glossary Of Terms"                                                                                     \
      "\\cleardoublepage"                                                                                      \
      "\\addcontentsline\{toc\}\{chapter\}\{Glossary Of Terms\}"                                               \
      "\\input\{c_glo0/c_glo0\}"                                                                               \
      "%"                                                                                                      \
      "%Glossary Of Mathematical Notation"                                                                     \
      "\\cleardoublepage"                                                                                      \
      "\\addcontentsline\{toc\}\{chapter\}\{Glossary Of Mathematical Notation\}"                               \
      "\\input\{c_glo1/c_glo1\}"                                                                               \
      "%"                                                                                                      \
      "%Bibliography"                                                                                          \
      "\\cleardoublepage"                                                                                      \
      "\\addcontentsline\{toc\}\{chapter\}\{Bibliography\}"                                                    \
      "\\input\{volshare/workbibl\}"                                                                           \
      "%"                                                                                                      \
      "%Index Must Be Formed At This Directory Level"                                                          \
      "\\cleardoublepage"                                                                                      \
      "\\addcontentsline\{toc\}\{chapter\}\{Index\}"                                                           \
      "\\printindex"                                                                                           \
      "%"                                                                                                      \
      "\\end\{document\}"                                                                                      \
      "%"                                                                                                      \
      }

   for {set i 0} {$i < [llength $final_matter]} {incr i} { \
      puts $handle [lindex $final_matter $i]
      }
   }


#Marks the end of a TEX volume file, for aesthetics.
proc mark_end_of_tex_volume_files_for_aesthetics { handle filename } { \
   puts $handle "%End of file [string toupper $filename]."
   }


#Output code to import the external document labels, used for cross-referencing
#This is a bit tricky because don't want to include ourselves.  This applies
#to the multi-volume work only.  For the single-volume work, all reference are
#internal.
proc output_external_document_symbol_imports { handle vtag }  { \
   global bookVolumeList
   global bookVolumeListStructSize

   puts $handle "%External document symbol imports.  These imports allow one volume"
   puts $handle "%to cross-reference to another, and create one large namespace for"
   puts $handle "%LaTeX symbols."

   set N [llength $bookVolumeList]

   #Iterate through the list.  Everything gets output unless
   #it is our tag name.
   for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
      if {[get_volume_used_flag [lindex $bookVolumeList $i]]} { \
         set iter_vtag [lindex $bookVolumeList $i]
         if {[string compare $iter_vtag $vtag]} { \
            set lineout \\externaldocument\{$iter_vtag\}
            puts $handle $lineout
            }
         }
      }

   puts $handle "%"
   }

#Outputs the common things in a document, from the "\makeindex" command
#through the "\begin{document}" command.
#
proc output_common_lines_through_begindoc { handle } { \
   set preamble {
      "%Embarrassingly, I've forgotten why \"makeindex\" is necessary ..."                                     \
      "\\makeindex"                                                                                            \
      "%"                                                                                                      \
      "%Shared mathematical definitions"                                                                       \
      "\\input\{volshare/workmdef\}"                                                                           \
      "%"                                                                                                      \
      "%Hyphenation exceptions"                                                                                \
      "\\input\{volshare/workhxcp\}"                                                                           \
      "%"                                                                                                      \
      "%New environments, etc."                                                                                \
      "\\input\{volshare/worknenv\}"                                                                           \
      "%"                                                                                                      \
      "\\begin\{document\}"                                                                                    \
      "%"                                                                                                      \
      "%Index \"see\" definitions"                                                                             \
      "\\input\{volshare/workidxs\}"                                                                           \
      "%"                                                                                                      \
      }

   for {set i 0} {$i < [llength $preamble]} {incr i} { \
      puts $handle [lindex $preamble $i]
      }
   }

#Outputs multi-volume volume and chapter definitions for a specific
#volume.
#
#Inputs:
#  handle : File handle to write to.
#  vtag   : Volume tag of the volume whose master file is being formed.
#  volnum : The ordinal number of the volume, as a decimal integer.
#           This is used to create ordinary numbers, roman numbers,
#           etc.
#  
proc output_multi_volume_volume_and_chapter_definitions { handle vtag volnum } { \
   global bookVolumeList
   global bookVolumeListStructSize
   global mcl

   #Get the roman-numeral representation of the volume.
   set volnum_roman [upper_case_roman_numeral_string $volnum]

   #Get the long title of the volume.
   set vol_long_title [get_multi_vol_long_title $vtag]

   #Output the "current volume" LaTeX commands.
   puts $handle "%Constants for the current volume."
   puts $handle "\\newcommand\\curvolarabic\{$volnum\}"
   puts $handle "\\newcommand\\curvolroman\{$volnum_roman\}"
   puts $handle "\\newcommand\\curvoltitle\{$vol_long_title\}"
   puts $handle "\\newcommand\\curvoltitlepagesep\{:  \}"
   puts $handle "\\newcommand\\curvoltitlepageprefix\{Volume \}"
   puts $handle "%"

   #Output definitions for all volumes.  There is no need to exclude the
   #current volume, as this could just as well be cited in this framework.
   puts $handle "%Constants for all volumes."
   puts $handle "%"
   set temp_ordinal_volume_number 0
   set N [llength $bookVolumeList]
   for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
      set cur_iter_volume [lindex $bookVolumeList $i]

      if {[get_volume_used_flag [lindex $bookVolumeList $i]]} { \
         incr temp_ordinal_volume_number
         puts $handle "%%%% [string toupper [lindex $bookVolumeList $i]]:  Volume $temp_ordinal_volume_number:  [get_multi_vol_long_title [lindex $bookVolumeList $i]] %%%%"
         puts $handle "\\newcommand\\v[replace_digits_with_alphas [lindex $bookVolumeList $i]]arabic\{$temp_ordinal_volume_number\}"
         puts $handle "\\newcommand\\v[replace_digits_with_alphas [lindex $bookVolumeList $i]]roman\{[upper_case_roman_numeral_string $temp_ordinal_volume_number]\}"
         puts $handle "\\newcommand\\v[replace_digits_with_alphas [lindex $bookVolumeList $i]]title\{[get_multi_vol_long_title [lindex $bookVolumeList $i]]\}"
         puts $handle "\\newcommand\\v[replace_digits_with_alphas [lindex $bookVolumeList $i]]citecomma\{[string toupper [lindex $bookVolumeList $i]], \}"
         puts $handle "\\newcommand\\v[replace_digits_with_alphas [lindex $bookVolumeList $i]]citehyphen\{[string toupper [lindex $bookVolumeList $i]]-\}"
         puts $handle "%"         

         #Output definitions for all chapters which are enclosed by the current volume.  This is a bit tricky
         #because must traverse the mcl table and pick out the right portion.
         set state 0
            #"state" is a state variable which keeps track of where we are parsing the mcl table.
            #State values are as follows:
            #  0 -- have not yet found the right volume.
            #  1 -- are in the midst of the right volume.
            #  2 -- are into subsequent volumes.

         set cur_vol ""
         set chapter_or_appendix ""

         for {set j 0} {$j < [llength $mcl]} {incr j 4} { \
            set rectype [lindex $mcl [expr $j + 0]]
            set par1    [lindex $mcl [expr $j + 1]]
            set par2    [lindex $mcl [expr $j + 2]]
            set par3    [lindex $mcl [expr $j + 3]]
         
            if {$state == 0} { \
               if {! [string compare $rectype v] || ! [string compare $rectype w]} { \
                  #This is a volume record that has meaning for us.  In either case,
                  #the vtag comes from par1.

                  #Have not yet encountered our volume of interest.  If this is
                  #it, record and change state.
                  if {![string compare $cur_iter_volume $par1]} { \
                     set cur_vol $par1
                     set chapter_or_appendix "Chapter"
                     set state 1
                     }
                  } 
               } \
            elseif {$state == 1} { \
               #We are within the volume of interest.  Looking for chapter records.
               if {! [string compare $rectype c] || ! [string compare $rectype e]} { \
                  set cur_chap_lc $par1
                  set cur_chap_uc [string toupper $cur_chap_lc]
                  set cur_chap_idstring [replace_digits_with_alphas $cur_chap_lc]
                  set cur_chap_short_title [get_chap_short_single_volume_title $cur_chap_lc]
                  set cur_chap_long_title [get_chap_long_single_volume_title $cur_chap_lc]
                  set cur_chap_vol_arabic $temp_ordinal_volume_number
                  set cur_chap_vol_roman [upper_case_roman_numeral_string $temp_ordinal_volume_number]
                  set cur_chap_vol_title [get_multi_vol_long_title [lindex $bookVolumeList $i]]

                  puts $handle "%%%% Chapter C$cur_chap_uc:  $cur_chap_long_title %%%%"
                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "volarabic\{$cur_chap_vol_arabic\}"
                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "volroman\{$cur_chap_vol_roman\}"
                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "voltitle\{$cur_chap_vol_title\}"
                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "shorttitle\{$cur_chap_short_title\}"
                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "title\{$cur_chap_long_title\}"
                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "longtitle\{$cur_chap_long_title\}"

                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"

                  #For the cite, there are two cases to cover.  If the chapter is in the
                  #volume we're doing, the cite is the empty string.  Otherwise, it
                  #is the volume tag.
                  if {![string compare $vtag $cur_iter_volume]} { \
                     set cur_chap_xref_cite ""
                     } \
                  else {
                     set cur_chap_xref_cite "[string toupper [lindex $bookVolumeList $i]]"
                     }

                  if {[string length $cur_chap_xref_cite]} { \
                     puts $handle "xrefhyphen\{$cur_chap_xref_cite-\}"
				     } \
				  else {
                     puts $handle "xrefhyphen\{\}"
				     }

                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"

                  if {[string length $cur_chap_xref_cite]} { \
                     puts $handle "xrefcomma\{$cur_chap_xref_cite, \}"
				     } \
				  else {
                     puts $handle "xrefcomma\{\}"
				     }

                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "mcclass\{$chapter_or_appendix\}"
                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "ucclass\{[string toupper $chapter_or_appendix]\}"
                  puts -nonewline $handle "\\newcommand\\c$cur_chap_idstring"
                  puts $handle "lcclass\{[string tolower $chapter_or_appendix]\}"
                  puts $handle "%"
                  } \
               elseif {! [string compare $rectype y]} { \
                  #This is the beginning of the appendix material for a multi-volume work.
                  set chapter_or_appendix "Appendix"
                  } \
               elseif {! [string compare $rectype v] || ! [string compare $rectype w]} { \
                  set state 2
                  }
               } \
            elseif {$state == 2} { \
               #Do nothing.  We are in the parsing state where we have done the volume of interest
               #and can't do more.
               } \
            else {
               error "Bad state variable."
               }
            }
         }
      }
   }


#Outputs the matter between the volume and chapter definitions and
#the chapters.
proc output_matter_between_chapter_defs_and_chapters { handle vtag script_vcinfo sv_or_mv} { \
   puts $handle "%Title page(s)"
   puts $handle "\\input\{volshare/workttla\}"
   puts $handle "%"
   puts $handle "\\vspace\{-0.45in\}"
   puts $handle "%"
   puts $handle "%Version control information for this script."
   puts $handle "\\noindent\\begin\{minipage\}\{\\textwidth\}"
   puts $handle "\\noindent\\rule\[-0.25in\]\{\\textwidth\}\{1pt\}"
   puts $handle "\\begin\{tiny\}"
   puts $handle "\\begin\{verbatim\}"
   puts -nonewline $handle $script_vcinfo
   puts $handle "\\end\{verbatim\}"
   puts $handle "\\end\{tiny\}"
   puts $handle "\\noindent\\rule\[0.25in\]\{\\textwidth\}\{1pt\}"
   puts $handle "\\end\{minipage\}"
   puts $handle "%"
   puts $handle "%Declare this as frontmatter, the front portion before the meat"
   puts $handle "%of the book."
   puts $handle "\\frontmatter\{\}"
   puts $handle "%"
   puts $handle "%Preface"

   copy_preface_to_stream $handle $sv_or_mv

   puts $handle "%"
   puts $handle "%Acknowledgements"
   puts $handle "\\input\{volshare/workacks\}"
   puts $handle "%"
   puts $handle "%Table of contents"
   puts $handle "\\tableofcontents"
   puts $handle "%"
   puts $handle "%List of tables"
   puts $handle "\\listoftables"
   puts $handle "%"
   puts $handle "%List of figures"
   puts $handle "\\listoffigures"
   puts $handle "%"
   puts $handle "%List of algorithms"
   puts $handle "\\listofalgorithms"
   puts $handle "%"
   puts $handle "%Everything after this is the main matter, the \"meat\""
   puts $handle "%of the book."
   puts $handle "\\mainmatter\{\}"
   puts $handle "%"
   }

#Copies the contents of the preface to the master file being formed.  To accomodate
#single-volume versus multi-volume builds, the two tags "<sv>" and "<mv>", which
#must occur starting in column 1, are supported.  These two tags indicate that the
#line goes only to the single-volume build or the multi-volume build files.
#The paramter sv or mv must be "s" or "m" for single or multi.
#
proc copy_preface_to_stream { handle sv_or_mv } { \
   #Set the compare tag based on the input parameter.
   if {![string compare $sv_or_mv "s"]} { \
      set compare_tag "<sv>"
      } \
   elseif {![string compare $sv_or_mv "m"]} {
      set compare_tag "<mv>"
      } \
   else {
      error
      }

   #Open the preface for processing.
   set phandle [open volshare/workprfa.tex r]

   #For each line, just copy it in, discarding lines with the wrong tag.
   set eof_found 0
   while {!$eof_found} { \
      #Grab a line.
      set line_in [gets $phandle]

      #Set a boolean if it contains a tag of any sort.  Remove the tag from the line.
      set tag ""
      set tag_found 0
      set sf_result_1 [string first "<" $line_in]
      set sf_result_2 [string first ">" $line_in]
      set sf_result_3 [string first $compare_tag $line_in]
      if {( $sf_result_1 == 0 ) && ( $sf_result_2 == 3 ) } { \
         set tag_found 1
         }

      if {$tag_found && ! ($sf_result_3 == 0)} { \
         #There was a tag, but it is not for us.  Discard the line.
         } \
      elseif {$tag_found && ($sf_result_3 == 0)} { 
         #The tag was found, and it is for us.  Remove the tag from the line and
         #put the line to the output.
         set line_in [string range $line_in 4 end]
         puts $handle $line_in
         } \
      else {
         #There was no tag found.  Just pass the line through.
         puts $handle $line_in
         }

      set eof_found [eof $phandle]      
      }

   #Close the preface, we are done with it.
   close $phandle
   }


#Outputs the chapter and appendix includes for one volume of a multi-volume work
#
proc output_multi_volume_chapter_and_appendix_includes { handle vtag } { \
   global mcl

   #Output definitions for all chapters which are enclosed by the current volume.  This is a bit tricky
   #because must traverse the mcl table and pick out the right portion.
   set state 0
      #"state" is a state variable which keeps track of where we are parsing the mcl table.
      #State values are as follows:
      #  0 -- have not yet found the right volume.
      #  1 -- are in the midst of the right volume.
      #  2 -- are into subsequent volumes.

   for {set i 0} {$i < [llength $mcl]} {incr i 4} { \
      set rectype [lindex $mcl [expr $i + 0]]
      set par1    [lindex $mcl [expr $i + 1]]
      set par2    [lindex $mcl [expr $i + 2]]
      set par3    [lindex $mcl [expr $i + 3]]
         
      if {$state == 0} { \
         if {! [string compare $rectype v] || ! [string compare $rectype w]} { \
            #This is a volume record that has meaning for us.  In either case,
            #the vtag comes from par1.

            #Have not yet encountered our volume of interest.  If this is
            #it, record and change state.
            if {![string compare $vtag $par1]} { \
               set cur_vol $par1
               set chapter_or_appendix "Chapter"
               set state 1
               }
            } 
         } \
      elseif {$state == 1} { \
         #We are within the volume of interest.  Looking for chapter records.
         if {! [string compare $rectype c] || ! [string compare $rectype e]} { \
            set cur_chap_lc $par1
            set cur_chap_uc [string toupper $cur_chap_lc]
            set cur_chap_idstring [replace_digits_with_alphas $cur_chap_lc]
            set cur_chap_short_title [get_chap_short_single_volume_title $cur_chap_lc]
            set cur_chap_long_title [get_chap_long_single_volume_title $cur_chap_lc]

            puts $handle "%%%% $chapter_or_appendix C$cur_chap_uc:  $cur_chap_long_title %%%%"
            puts $handle "\\input\{c_$cur_chap_lc/c_$cur_chap_lc\}"
            puts $handle "%"
            } \
         elseif {! [string compare $rectype y]} { \
            #This is the beginning of the appendix material for a multi-volume work.
            set chapter_or_appendix "Appendix"
            puts $handle "\\appendix"
            puts $handle "%"
            } \
         elseif {! [string compare $rectype v] || ! [string compare $rectype w]} { \
            set state 2
            }
         } \
      elseif {$state == 2} { \
         #Do nothing.  We are in the parsing state where we have done the volume of interest
         #and can't do more.
         } \
      else {
         error "Bad state variable."
         }
      }
   }


#Builds one volume of a multi-volume work, passed the volume tag and the volume
#number.  The volume number is an ordinal number, and is used for normal
#and roman numerals and stuff.
#
proc createMultiVolumeWork { vtag volume_number script_vcinfo } { \
   #Form the filename, based on the input tag.  All that is required is a .TEX 
   #suffix.
   set filename $vtag
   append filename .tex

   #Open the file for writing.
   set handle [open $filename w]

   #Insert the title line.
   output_title_line $handle $filename "Volume of multi-volume work."

   #Insert the document class and package includes.
   output_doc_class_and_package_includes $handle

   #For the multi-volume only, use the "XR" package.
   puts $handle "%Must use \"xr\" package to import symbols from other volumes."
   puts $handle "\\usepackage\{xr\}"
   puts $handle "%"

   #Insert the external document symbol imports.
   output_external_document_symbol_imports $handle $vtag

   #Insert common lines through the begindoc.
   output_common_lines_through_begindoc $handle

   #Insert the volume and chapter definitions.
   output_multi_volume_volume_and_chapter_definitions $handle $vtag $volume_number

   #Insert the matter after the volume and chapter definitions but before 
   #the chapters and appendices.
   output_matter_between_chapter_defs_and_chapters $handle $vtag $script_vcinfo m

   #Insert the chapter and appendix includes.
   output_multi_volume_chapter_and_appendix_includes $handle $vtag

   #Output the final matter.
   output_tex_volume_final_matter $handle

   #Output the final line of the file, with the file name, for aesthetics.
   mark_end_of_tex_volume_files_for_aesthetics $handle $filename

   #Close the file.
   close $handle
   }

#
# Builds the two single-volume works (the two source files SVF.TEX and SVD.TEX).  These
# are quite a bit simpler than the multi-volume generations.
#
proc createSingleVolumeWorks { script_vcinfo } { \
   global mcl

   #Define the preamble number 1 for both of the files.  This is text up until the chapter
   #definitions.
   set preamble1 {
      "%Definitions For Chapter Citations"                                                                     \
      "%--------------------------------------------------------------"                                        \
      "%These definitions are created automatically by the Wish Script"                                        \
      "%\"CP_SCRIPT.TCL\"."                                                                                    \
      "%--------------------------------------------------------------"                                        \
      "%Note that for the single-volume works, there is no concept of"                                         \
      "%the \"xref\" prefix, as everything is in the same volume."                                             \
      "%That is why this prefix is set to the empty string in all"                                             \
      "%cases."                                                                                                \
      "%--------------------------------------------------------------"                                        \
      }

   #Define the matter between the chapter constants and the start of the version control information
   #for this script.
   set midamble1 {
      "\\newcommand\\curvoltitle\{\Full Edition (All Content)\}"                                               \
      "\\newcommand\\curvolroman\{\}"                                                                          \
      "\\newcommand\\curvoltitlepagesep\{\}"                                                                   \
      "\\newcommand\\curvoltitlepageprefix\{\}"                                                                \
      ""                                                                                                       \
      }

   #Define the matter between the main volume's version control information and the start of the chapter
   #includes.
   set midamble2 {
      ""                                                                                                       \
      }

   #outboth "Generating single-volume work main TEX source files (SVF.TEX, SVD.TEX)."
   outboth "Generating single-volume work main TEX source file (SVF.TEX)."

   #Open the two files we want to write.
   set fhandle [open svf.tex w]

   #Output the title and descriptions for the files.
   output_title_line $fhandle SVF.TEX "Final Version Of Single-Volume Work"

   #Insert the document class and package includes.
   output_doc_class_and_package_includes $fhandle

   #Output common things through "begindoc"
   output_common_lines_through_begindoc $fhandle

   #Output the first preamble to the files.
   for {set i 0} {$i < [llength $preamble1]} {incr i} { \
      #puts $dhandle [lindex $preamble1 $i]
      puts $fhandle [lindex $preamble1 $i]
      }

   #Remembers whether the fundamental unit (the chapter) is a chapter or an
   #appendix.  After the LaTeX "appendix" mark, everything gets numbered as
   #an appendix (A, B, C, etc.).  This is included because if one Chapter or
   #Appendix needs to refer to another one symbolically (or to itself for that
   #matter) it needs to know if it is a chapter or appendix.  This preserves
   #the ability to have something be an appendix in one compilation and a chapter
   #in another compilation.
   set chapter_or_appendix Chapter

   #Output the chapter citations for the files.  The chapter citations are how one
   #chapter refers to another.  For the "single-volume" works, there is no concept
   #of volume (there is only one), so the cites are just straight chapter cites.
   for {set i 0} {$i < [llength $mcl]} {incr i 4} { \
      set rectype [lindex $mcl $i]
         
      if {! [string compare $rectype d] || ! [string compare $rectype e]} { \
         #This is a chapter record that we need to be concerned with.
              
         #Get the chapter tag.
         set ctag [lindex $mcl [expr $i + 1]]

         #Output a header line to both files indicating which chapter.
         #puts -nonewline $dhandle %C
         puts -nonewline $fhandle %C
         set ucctag [string toupper $ctag]
         #puts -nonewline $dhandle $ucctag
         puts -nonewline $fhandle $ucctag
         #puts -nonewline $dhandle ": "
         puts -nonewline $fhandle ": "
         #puts $dhandle [get_chap_long_single_volume_title $ctag]
         puts $fhandle [get_chap_long_single_volume_title $ctag]
                  
         #Output the data for the chapter, as LaTeX commands.
         set textag [replace_digits_with_alphas $ctag]

         #xref command.  This is how one chapter refers to another (the
         #prefix).  Set constant empty here, because no prefix required.
         set linebuf ""
         append linebuf \\newcommand \\ c $textag xrefhyphen \{ \}
         #puts $dhandle $linebuf
         puts $fhandle $linebuf
         set linebuf ""
         append linebuf \\newcommand \\ c $textag xrefcomma \{ \}
         #puts $dhandle $linebuf
         puts $fhandle $linebuf

         #Long title.  This is normally used for the chapter unless there
         #are space constraints, such as would occur on page headers.
         set linebuf ""
         append linebuf \\newcommand \\ c $textag longtitle \{ [get_chap_long_single_volume_title $ctag] \}
         #puts $dhandle $linebuf
         puts $fhandle $linebuf

         #Title (same as long title).
         set linebuf ""
         append linebuf \\newcommand \\ c $textag title \{ [get_chap_long_single_volume_title $ctag] \}
         #puts $dhandle $linebuf
         puts $fhandle $linebuf
         
         #Short title.  This is used in confined areas, such as on page headers.
         set linebuf ""
         append linebuf \\newcommand \\ c $textag shorttitle \{ [get_chap_short_single_volume_title $ctag] \}
         #puts $dhandle $linebuf
         puts $fhandle $linebuf

         #Fill in the "Class", whether this is a chapter or an appendix.
         set linebuf ""
         append linebuf \\newcommand \\ c $textag mcclass \{ $chapter_or_appendix \}
         puts $fhandle $linebuf
         set linebuf ""
         append linebuf \\newcommand \\ c $textag ucclass \{ [string toupper $chapter_or_appendix] \}
         puts $fhandle $linebuf
         set linebuf ""
         append linebuf \\newcommand \\ c $textag lcclass \{ [string tolower $chapter_or_appendix] \}
         puts $fhandle $linebuf

         #Put in a blank line for aesthetics
         #puts $dhandle ""
         puts $fhandle ""
         } \
      elseif {! [string compare $rectype z]} {
         #This tag indicates the location of the beginning of the appendices.  We
         #need to switch from chapter to appendix.
         set chapter_or_appendix Appendix
         } 
      }

   #Put in the "midamble" before the version control information.
   for {set i 0} {$i < [llength $midamble1]} {incr i} { \
      #puts $dhandle [lindex $midamble1 $i]
      puts $fhandle [lindex $midamble1 $i]
      }

   #Put in matter including title page and version control information.
   output_matter_between_chapter_defs_and_chapters $fhandle "" $script_vcinfo s

   #Put in the "midamble" until the chapter includes.
   for {set i 0} {$i < [llength $midamble2]} {incr i} { \
      #puts $dhandle [lindex $midamble2 $i]
      puts $fhandle [lindex $midamble2 $i]
      }

   #Put in the chapter includes.  This will involve looping through the mcl table and
   #inserting things.  There is a differentiation between draft chapters and non-draft
   #chapters.
   set chapter_or_appendix Chapter
   for {set i 0} {$i < [llength $mcl]} {incr i 4} { \
      set rectype [lindex $mcl $i]
         
      if {! [string compare $rectype d] || ! [string compare $rectype e]} { \
         #This is a chapter record that we need to be concerned with.
         #Can easily form the file name by a simple string concat with the 
         #tag.  For aesthetics, will also throw in the title.
         set ctag [lindex $mcl [expr $i + 1]]
         set ctitle [get_chap_long_single_volume_title $ctag]

         set line1 "%$chapter_or_appendix:  $ctitle"
         set line2 ""
         append line2 \\input\{c_ $ctag /c_ $ctag \}

         #puts $dhandle $line1
         puts $fhandle $line1
         #puts $dhandle $line2
         puts $fhandle $line2
         #puts $dhandle ""
         puts $fhandle ""
         } \
      elseif {! [string compare $rectype p] || ! [string compare $rectype w]} {
         #This indicates that we need to spin a new part in the book.  There are
         #two cases to consider.  Either we yank the title from the volume information,
         #or else we yank the title from the par2 of the record.  Set the title.
         set par1 [lindex $mcl [expr $i + 1]]
         set par2 [lindex $mcl [expr $i + 2]]

         if {[string length $par2]} { \
            set part_title $par2
            } \
         else {
            set part_title [get_vol_part_title $par1]
            }

         #We have the part title.  Output the part record.
         set line1 "% New part: $part_title"
         set line2 "\\part\{$part_title\}"
         #puts $dhandle $line1
         puts $fhandle $line1
         #puts $dhandle $line2
         puts $fhandle $line2
         #puts $dhandle ""
         puts $fhandle ""
         } \
      elseif {! [string compare $rectype z]} {
         #This tag indicates the location of the beginning of the appendices.  We
         #need to switch from chapter to appendix.
         set chapter_or_appendix Appendix

         #Also need to decorate the output files to reflect that we're going into
         #appendix mode.
         set appendix_mark {
            "%Mark the start of appendices.  This causes numbering to be with letters"                         \
            "%instead of numbers."                                                                             \
            "\\appendix"                                                                                       \
            ""                                                                                                 \
            }
         for {set j 0} {$j < [llength $appendix_mark]} {incr j} { \
            #puts $dhandle [lindex $appendix_mark $j]
            puts $fhandle [lindex $appendix_mark $j]
            }
         }
      }

   #Now can put in the final matter.
   output_tex_volume_final_matter $fhandle

   #Mark the end of the files, for aesthetics.
   mark_end_of_tex_volume_files_for_aesthetics $fhandle svf.tex

   #Close the files.
   #close $dhandle
   close $fhandle

   hlineboth
   }


#Write the preamble to the _README_.HTM file.  This is everything up to the variable part that depends
#on the parts and sections defined in the script.
proc rebuildReadmeWritePreamble { fhandle } {
   set preamble {
      "<html>"                                                                                                 \
      ""                                                                                                       \
      "<head>"                                                                                                 \
      "<title>README File:&nbsp; CD Accompanying &quot;A Practitioner's Guide ...&quot;</title>"               \
      "</head>"                                                                                                \
      ""                                                                                                       \
      "<body BACKGROUND=\"wbbkgnds/bkblue01.gif\" TEXT=\"\#000000\">"                                          \
      ""                                                                                                       \
      "<h1 ALIGN=\"center\">README File:  CD Accompanying \"A Practitioner's Guide ...\"</h1>"                 \
      ""                                                                                                       \
      "<hr>"                                                                                                   \
      ""                                                                                                       \
      "<p>This HTML file contains links to all of the files distributed with the book"                         \
      "&quot;A Practitioner's Guide To The Design And Development Of Small Microcontroller Software&quot;, and"\
      "explains what each of the files is.&nbsp; This file is automatically generated by the Wish script"      \
      "SCRIPTS\\CP_SCRIPT.TCL.&nbsp; Note that some chapter titles"                                            \
      "and other information in this HTML file may differ subtly from the book, because the Wish script"       \
      "is aware of both long and short names for many titles -- the"                                           \
      "long titles are used here, but the short titles may be used in some places in"                          \
      "the book.&nbsp; For LaTeX builds of the book,&nbsp; it is assumed that the"                             \
      "contents of this CD are present, with the subdirectory tree prserved, in the"                           \
      "directory C:\\ESRGUBKA, i.e. so that the full"                                                           \
      "path of this HTML file is C:\\ESRGUBKA\\_README_.HTM.&nbsp; All path names supplied"                     \
      "below are with respect to C:\\ESRGUBKA.</p>"                                                             \
      ""                                                                                                       \
      "<hr>"                                                                                                   \
      ""                                                                                                       \
      }

   for {set i 0} {$i < [llength $preamble]} {incr i} { \
      puts $fhandle [lindex $preamble $i]
      }
   }


#Write the "meat" to the file.  This is the table and variable stuff.
proc rebuildReadmeWriteMeat { fhandle } {
   global readme_build_list

   #For indentation, the code supplied by Microsoft Front page was used as a guide.

   #Write the start of the table.
   puts $fhandle "<table border=\"1\" width=\"100%\">"

   #Set state variables to remember if anything must be closed as we iterate.
   set tr_active 0
      #True if in a <tr> block.
   set td_active 0
      #True if in a <td> block.
   set ul_active 0
      #True if in a <ul> block.
   set li_active 0
      #True if in a <li> item.

   #Loop through the list, processing each record.  Front Page HTML was used as a 
   #guide.
   for {set i 0} {$i < [llength $readme_build_list]} {incr i} { \
      #Loop effort-savers.
	  set cur_rec [lindex $readme_build_list $i]
	  set cur_tag [string range $cur_rec 0 0]
	  set cur_meat [string range $cur_rec 2 end]

      #puts $cur_rec

      #Split into cases, one for each possible tag.
      if {! [string compare -nocase $cur_tag F]} { \
         #If a <tr> block is not active, must start one.
         if {! $tr_active} { \
            puts $fhandle "  <tr>"
            set tr_active 1
            }
         #If a <td> block is not active, must start one.
         if {! $td_active} { \
            puts $fhandle "    <td width=\"100%\">"
            set td_active 1
            }
         #If a <ul> block is not active, must start one.
         if {! $ul_active} { \
            puts $fhandle "      <ul>"
            set ul_active 1
            }
         #OK, can now write the filename and the associated markers.  Will start
         #a list item in this endeavor, so must set this flag TRUE.
         #If a <li> block is active, must end it.
         if {$li_active} { \
            puts $fhandle "        </li>"
            set li_active 0
            }
         set li_active 1
         puts $fhandle "        <li><b><a href=\"" nonewline
         #When we stuff the file name in this context, need to change spaces to
         #the string "%20".  The reasons for this are HTML syntax.
         puts $fhandle [replace_spaces_with_HTML_codes [string tolower $cur_meat]] nonewline
         puts $fhandle "\">" nonewline
         puts $fhandle [string toupper $cur_meat] nonewline
         puts $fhandle "</a>:</b>&nbsp; "
         } \
      elseif {! [string compare -nocase $cur_tag M]} { \
         #The first thing we need to do is close out any nested blocks that we are in.
         #If a <li> block is active, must end it.
         if {$li_active} { \
            puts $fhandle "        </li>"
            set li_active 0
            }
         #If a <ul> block is active, must end it.
         if {$ul_active} { \
            puts $fhandle "      </ul>"
            set ul_active 0
            }
         #If a <td> block is active, must end it.
         if {$td_active} { \
            puts $fhandle "    </td>"
            set td_active 0
            }
         #If a <tr> block is active, must end it.
         if {$tr_active} { \
            puts $fhandle "  </tr>"
            set tr_active 0
            }

	     #Manually-generated header.  Just stuff it in.
		 puts $fhandle "  <tr>"
		 puts $fhandle "    <td width=\"100%\"><b><font size=\"5\">" nonewline
		 puts $fhandle "[string toupper $cur_meat]" nonewline
		 puts $fhandle "</font></b></td>"
		 puts $fhandle "  </tr>"
	     } \
      elseif {! [string compare -nocase $cur_tag C]} { \
         #If a <li> block is active, must end it.
         if {$li_active} { \
            puts $fhandle "        </li>"
            set li_active 0
            }
         #If a <ul> block is active, must end it.
         if {$ul_active} { \
            puts $fhandle "      </ul>"
            set ul_active 0
            }
         #If a <td> block is active, must end it.
         if {$td_active} { \
            puts $fhandle "    </td>"
            set td_active 0
            }
         #If a <tr> block is active, must end it.
         if {$tr_active} { \
            puts $fhandle "  </tr>"
            set tr_active 0
            }

	     #This is one with a chapter tag.  We need to look up the tag.
         set mc_ct [get_chap_long_single_volume_title $cur_meat]
		 set uc_ct [string toupper $mc_ct]
		 puts $fhandle "  <tr>"
		 puts $fhandle "    <td width=\"100%\"><b><font size=\"5\">" nonewline
		 puts $fhandle "CHAPTER " nonewline
         puts $fhandle [string toupper $cur_meat] nonewline
         puts $fhandle ":&nbsp;  " nonewline
		 puts $fhandle $uc_ct nonewline
		 puts $fhandle "</font></b></td>"
		 puts $fhandle "  </tr>"
	     } \
      elseif {! [string compare -nocase $cur_tag D]} { \
         #For descriptions, we just dump it in verbatim.  There is no need to do any processing.
         puts $fhandle "          " nonewline
         puts $fhandle $cur_meat
	     } \
      else { 
	     error "Unexpected tag in readme_build_list."
	     }
      }

   #Write the end of the table.
   puts $fhandle "</table>"
   puts $fhandle ""
   }

   
#Write the postamble to the file.  This is everything after the variable part.
proc rebuildReadmeWritePostamble { fhandle } {
   #First, grab the time as seconds since a time mark unknown.
   set tref [clock seconds]

   #Convert the time obtained to date.
   set date [clock format $tref -format "%m/%d/%y"]

   #Convert the time obtained to hour and minute.
   set time [clock format $tref -format "%H:%M"]

   #This part has to be manually generated because of the date and time.
   puts $fhandle ""
   puts $fhandle "<hr>"
   puts $fhandle ""
   puts $fhandle "<p align=\"center\">This file automatically generated on " nonewline
   puts $fhandle $date nonewline 
   puts $fhandle " at " nonewline
   puts $fhandle $time nonewline
   puts $fhandle            " by "
   puts $fhandle "Wish script SCRIPTS\\CP_SCRIPT.TCL.</p>"
   puts $fhandle ""
   puts $fhandle "<hr noshade size=\"10\" color=\"\#000000\">"
   puts $fhandle "</body>"
   puts $fhandle "</html>"
   }

#****************************************************************************************
#****************************************************************************************
#****    B U T T O N    P R E S S    F U N C T I O N S    *******************************
#****************************************************************************************
#****************************************************************************************
# Each of the functions in this category is called in response to a button on the main
# graphical window being pressed.
#----------------------------------------------------------------------------------------
# Performs a full LaTeX compilation and indexing of all volumes.  It isn't necessary to
# subdivide this operation any further because the full build is rare enough that any     
# reasonable amount of time is OK.  In the long term, it will be necessary to have the
# tools build a full index spanning all volumes, but this isn't done yet.               
#
proc fullLatexCompileAndIndexProc { } { \
   global bookVolumeList
   global bookVolumeListStructSize
   global pathUcBookA
   global execAcrobatDistiller
   global mcl
   global chapterList
   global chapterListStructSize

   outboth "BUTTON PRESS:  Full LaTeX compile and index."
   hlineboth

   #As a first step, extract this script's version control information.  This is used in
   #building the .TEX main files, to stamp them with the script's version control
   #information.
   set script_vcinfo [extract_this_scripts_version_control_information]

   #Set up the list of volumes and chapters to be processed.  This involves scanning the mcl to see
   #what is used and what is not used, and setting flags accordingly.  Volume "used" flags affect
   #how volumes are numbered and how they are cross-referenced.  Chapter "used" flags are safely
   #ignored--it does no harm to include chapter cite information in the LaTeX output files--what will
   #happen is if the referenced chapter isn't included, the unresolvable references will be "pushed"
   #onto LaTeX.

   #Zero out all of the volume used flags.
   outbothnonl "Marking all volumes unused ... "
   mark_all_volumes_unused
   outboth "done."

   #Zero out all of the chapter used flags.
   outbothnonl "Marking all chapters unused ... "
   mark_all_chaps_unused
   outboth "done."

   #Iterate through the mcl list, figuring out which volumes and chapters are used.  A "volume" is used
   #if it contains at least one chapter in the mcl list.  A "chapter" is used if it appears either as
   #part of a volume or in the standalone work.
   outbothnonl "Scanning mcl list for used volumes and used chapters ... "
   set used_volumes 0
   set unused_volumes [expr [llength $bookVolumeList] / $bookVolumeListStructSize]
   set used_chapters 0
   set unused_chapters [expr [llength $chapterList] / $chapterListStructSize]
   set cur_vol ""
   set N [llength $mcl]
   #Iterate through the list, taking notes.
   for {set i 0} {$i < $N} {incr i 4} { \
      set mcl_rectype [lindex $mcl [expr $i + 0]]
      set mcl_par1    [lindex $mcl [expr $i + 1]]
      set mcl_par2    [lindex $mcl [expr $i + 2]]
      set mcl_par3    [lindex $mcl [expr $i + 3]]

      if {! [string compare $mcl_rectype v] || ! [string compare $mcl_rectype w]} \
         {
         #The v record type declares a new volume, and the w declares both a new volume and
         #a new part.  Either of these record types mean that we've hit a new volume boundary.
         #Remember this.
         set cur_vol $mcl_par1
         } \
      elseif {! [string compare $mcl_rectype c] || ! [string compare $mcl_rectype e]} { \
         #Either of these declare a chapter in the current volume.  Process.
         #Mark the chapter as used, and update chapter statistics.
         if {[get_chap_used_flag $mcl_par1]} { \
            #The chapter is already used.  Don't want to count the chapter as used
            #again.
            } \
         else {

            #outboth "Marking $mcl_par1"

            #The chapter isn't yet marked used.
            mark_chapter_used $mcl_par1
            incr used_chapters
            incr unused_chapters -1
            }
         #Mark the volume used if it is used.
         if {[string length $cur_vol]} { \
            if {![get_volume_used_flag $cur_vol]} { \
               #Mark that volume (the nearest above enclosing one) as used.
               mark_volume_used $cur_vol 
               incr used_volumes
               incr unused_volumes -1
               }
            } 
         }
      }

   outboth "done."

   #Output statistics about what is used and not used.  This is helpful for diagnosis.
   outbothnonl "Used chapters:  $used_chapters  Unused chapters:  $unused_chapters"
   outboth .
   outboth "Enumeration of unused chapters (if any):"
   set N [llength $chapterList]
   #Iterate through the list, taking notes.
   for {set i 0} {$i < $N} {incr i $chapterListStructSize} { \
      #outboth "i: $i"
      if { ! [get_chap_used_flag [lindex $chapterList $i]]} { \
         outboth "   [lindex $chapterList $i]"
         }
      }

   outbothnonl "Used volumes:   $used_volumes   Unused volumes:   $unused_volumes" 
   outboth .
   outboth "Enumeration of used volumes (if any):"
   set N [llength $bookVolumeList]
   #Iterate through the list, taking notes.
   for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
      #outboth "i: $i"
      if {[get_volume_used_flag [lindex $bookVolumeList $i]]} { \
         outboth "   [lindex $bookVolumeList $i]"
         }
      }
   outboth "Enumeration of unused volumes (if any):"
   set N [llength $bookVolumeList]
   #Iterate through the list, taking notes.
   for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
      #outboth "i: $i"
      if { ! [get_volume_used_flag [lindex $bookVolumeList $i]]} { \
         outboth "   [lindex $bookVolumeList $i]"
         }
      }

   #Delete all the output files.  This guards against misunderstandings and accidents.  In the deletion of output
   #files, whether volumes are used or not is not taken into account.  The reason for this is neatness--if
   #the list of used volumes changes, it is helpful to get all of those files gone.

   #Delete the two single-volume files.
   set pathbase ""
   append pathbase $pathUcBookA / sv
   #set svlist {f.dvi f.ps f.pdf d.dvi d.ps d.pdf}
   set svlist {f.dvi f.ps f.pdf}
   set N [llength $svlist]

   #Iterate through, delete each single-volume file.
   for {set i 0} {$i < $N} {incr i} { \
      set target $pathbase
      append target [lindex $svlist $i]

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }
      }         

   #Get number of elements in the list of volumes.
   set N [llength $bookVolumeList]

   #Iterate through, delete each file.
   for {set volnum 0} {$volnum < $N} {incr volnum $bookVolumeListStructSize} { \
      set voltag [lindex $bookVolumeList $volnum]

      set target ""
      append target $pathUcBookA / $voltag .dvi

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .ps

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .pdf

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .idx

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .ilg

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .ind

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .toc

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .aux

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      }
   hlineboth

   #Create the master files for the two single volume works (the draft and the final).
   createSingleVolumeWorks $script_vcinfo

   #Create the master files for the volumes.  The volumes are automatically numbered,
   #based on those that are used, starting with 1.
   set volume_number 0
   set N [llength $bookVolumeList]
   #Iterate through, delete each file.
   for {set volnum 0} {$volnum < $N} {incr volnum $bookVolumeListStructSize} { \
      set voltag [lindex $bookVolumeList $volnum]

      if {[get_volume_used_flag $voltag]} { \
         incr volume_number
         createMultiVolumeWork $voltag $volume_number $script_vcinfo
         }
      }   

   #Do four full rounds of LaTeX compiles and index builds.  This is necessary
   #to resolve cross-dependencies and be sure no page numbering changes.
   for {set round 0} {$round < 4} {incr round} { \
      outbothnonl "LaTeX compile, Round "
      outbothnonl $round
      outboth .
      hlineboth

      #Do the single-volume works.
      #LatexCompileFile svd.tex
      #MakeOrdinaryIndexFile svd
      LatexCompileFile svf.tex
      MakeOrdinaryIndexFile svf

      #Get number of elements in the list of volumes.  Compile only the used ones.
      set N [llength $bookVolumeList]

      #Iterate through, compile each file.
      for {set volnum 0} {$volnum < $N} {incr volnum $bookVolumeListStructSize} { \
         set voltag [lindex $bookVolumeList $volnum]
         if {[get_volume_used_flag $voltag]} { \
            outbothnonl "Latex compile: $voltag"
            outboth .
            hlineboth

            set fullfilename ""
            append fullfilename $voltag .tex

            LatexCompileFile $fullfilename

            MakeOrdinaryIndexFile $voltag
            }
         }
      update
      }

   #DVIPS the single-volume file.
   outbothnonl "DVIPS: svf"
   RunDvipsToGenPsOutput svf

   #Modify the postscript in the single volume file to
   #generate a duplex file.
   ModifyPsToDuplex svf

   #PDF the two single-volume file.
   set psfilepath ""
   append psfilepath $pathUcBookA / svf.ps
   exec $execAcrobatDistiller $psfilepath &

   #Get number of elements in the list of volumes.
   set N [llength $bookVolumeList]

   #Iterate through, DVIPS each file.
   for {set volnum 0} {$volnum < $N} {incr volnum $bookVolumeListStructSize} { \
      set voltag [lindex $bookVolumeList $volnum]
      if {[get_volume_used_flag $voltag]} { \
         outbothnonl "DVIPS: $voltag"
         outboth .
         hlineboth

         RunDvipsToGenPsOutput $voltag
         ModifyPsToDuplex      $voltag

         set psfilepath ""
         append psfilepath $pathUcBookA / $voltag .ps

         #There is no barrier at this point to also running Distiller.  Distiller gives us
         #no information back.
         exec $execAcrobatDistiller $psfilepath &
         }
      update
      }

   outboth "DONE:  BUTTON PRESS:  Full LaTeX compile and index."
   hlineboth
   update
   }

#----------------------------------------------------------------------------------------
# Rebuilds all the master files.  This operation can be useful if one isn't using 4AllTex
# but wants to build the automatically-generated files anyway, perhaps to use another
# version of LaTeX.
#
proc masterFileRebuildProc { } { \
   global bookVolumeList
   global bookVolumeListStructSize
   global pathUcBookA
   global execAcrobatDistiller
   global mcl
   global chapterList
   global chapterListStructSize

   outboth "BUTTON PRESS:  Rebuild single-volume and multi-volume master files."
   hlineboth

   #As a first step, extract this script's version control information.  This is used in
   #building the .TEX main files, to stamp them with the script's version control
   #information.
   set script_vcinfo [extract_this_scripts_version_control_information]

   #Set up the list of volumes and chapters to be processed.  This involves scanning the mcl to see
   #what is used and what is not used, and setting flags accordingly.  Volume "used" flags affect
   #how volumes are numbered and how they are cross-referenced.  Chapter "used" flags are safely
   #ignored--it does no harm to include chapter cite information in the LaTeX output files--what will
   #happen is if the referenced chapter isn't included, the unresolvable references will be "pushed"
   #onto LaTeX.

   #Zero out all of the volume used flags.
   outbothnonl "Marking all volumes unused ... "
   mark_all_volumes_unused
   outboth "done."

   #Zero out all of the chapter used flags.
   outbothnonl "Marking all chapters unused ... "
   mark_all_chaps_unused
   outboth "done."

   #Iterate through the mcl list, figuring out which volumes and chapters are used.  A "volume" is used
   #if it contains at least one chapter in the mcl list.  A "chapter" is used if it appears either as
   #part of a volume or in the standalone work.
   outbothnonl "Scanning mcl list for used volumes and used chapters ... "
   set used_volumes 0
   set unused_volumes [expr [llength $bookVolumeList] / $bookVolumeListStructSize]
   set used_chapters 0
   set unused_chapters [expr [llength $chapterList] / $chapterListStructSize]
   set cur_vol ""
   set N [llength $mcl]
   #Iterate through the list, taking notes.
   for {set i 0} {$i < $N} {incr i 4} { \
      set mcl_rectype [lindex $mcl [expr $i + 0]]
      set mcl_par1    [lindex $mcl [expr $i + 1]]
      set mcl_par2    [lindex $mcl [expr $i + 2]]
      set mcl_par3    [lindex $mcl [expr $i + 3]]

      if {! [string compare $mcl_rectype v] || ! [string compare $mcl_rectype w]} \
         {
         #The v record type declares a new volume, and the w declares both a new volume and
         #a new part.  Either of these record types mean that we've hit a new volume boundary.
         #Remember this.
         set cur_vol $mcl_par1
         } \
      elseif {! [string compare $mcl_rectype c] || ! [string compare $mcl_rectype e]} { \
         #Either of these declare a chapter in the current volume.  Process.
         #Mark the chapter as used, and update chapter statistics.
         if {[get_chap_used_flag $mcl_par1]} { \
            #The chapter is already used.  Don't want to count the chapter as used
            #again.
            } \
         else {

            #outboth "Marking $mcl_par1"

            #The chapter isn't yet marked used.
            mark_chapter_used $mcl_par1
            incr used_chapters
            incr unused_chapters -1
            }
         #Mark the volume used if it is used.
         if {[string length $cur_vol]} { \
            if {![get_volume_used_flag $cur_vol]} { \
               #Mark that volume (the nearest above enclosing one) as used.
               mark_volume_used $cur_vol 
               incr used_volumes
               incr unused_volumes -1
               }
            } 
         }
      }

   outboth "done."

   #Output statistics about what is used and not used.  This is helpful for diagnosis.
   outbothnonl "Used chapters:  $used_chapters  Unused chapters:  $unused_chapters"
   outboth .
   outboth "Enumeration of unused chapters (if any):"
   set N [llength $chapterList]
   #Iterate through the list, taking notes.
   for {set i 0} {$i < $N} {incr i $chapterListStructSize} { \
      #outboth "i: $i"
      if { ! [get_chap_used_flag [lindex $chapterList $i]]} { \
         outboth "   [lindex $chapterList $i]"
         }
      }

   outbothnonl "Used volumes:   $used_volumes   Unused volumes:   $unused_volumes" 
   outboth .
   outboth "Enumeration of used volumes (if any):"
   set N [llength $bookVolumeList]
   #Iterate through the list, taking notes.
   for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
      #outboth "i: $i"
      if {[get_volume_used_flag [lindex $bookVolumeList $i]]} { \
         outboth "   [lindex $bookVolumeList $i]"
         }
      }
   outboth "Enumeration of unused volumes (if any):"
   set N [llength $bookVolumeList]
   #Iterate through the list, taking notes.
   for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
      #outboth "i: $i"
      if { ! [get_volume_used_flag [lindex $bookVolumeList $i]]} { \
         outboth "   [lindex $bookVolumeList $i]"
         }
      }

   #Delete all the output files.  This guards against misunderstandings and accidents.  In the deletion of output
   #files, whether volumes are used or not is not taken into account.  The reason for this is neatness--if
   #the list of used volumes changes, it is helpful to get all of those files gone.

   #Delete the two single-volume files.
   set pathbase ""
   append pathbase $pathUcBookA / sv
   #set svlist {f.dvi f.ps f.pdf d.dvi d.ps d.pdf}
   set svlist {f.dvi f.ps f.pdf}
   set N [llength $svlist]

   #Iterate through, delete each single-volume file.
   for {set i 0} {$i < $N} {incr i} { \
      set target $pathbase
      append target [lindex $svlist $i]

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }
      }         

   #Get number of elements in the list of volumes.
   set N [llength $bookVolumeList]

   #Iterate through, delete each file.
   for {set volnum 0} {$volnum < $N} {incr volnum $bookVolumeListStructSize} { \
      set voltag [lindex $bookVolumeList $volnum]

      set target ""
      append target $pathUcBookA / $voltag .dvi

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .ps

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .pdf

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .idx

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .ilg

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .ind

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .toc

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      set target ""
      append target $pathUcBookA / $voltag .aux

      if {[file exists $target]} { \
         outbothnonl "Deleting $target"
         outboth .
         file delete $target
         } \
      else {
         outboth "Skipping $target : file does not exist."
         }

      }
   hlineboth

   #Create the master files for the two single volume works (the draft and the final).
   createSingleVolumeWorks $script_vcinfo

   #Create the master files for the volumes.  The volumes are automatically numbered,
   #based on those that are used, starting with 1.
   set volume_number 0
   set N [llength $bookVolumeList]
   #Iterate through, delete each file.
   for {set volnum 0} {$volnum < $N} {incr volnum $bookVolumeListStructSize} { \
      set voltag [lindex $bookVolumeList $volnum]

      if {[get_volume_used_flag $voltag]} { \
         incr volume_number
         createMultiVolumeWork $voltag $volume_number $script_vcinfo
         }
      }   

   outboth "DONE:  Rebuild single-volume and multi-volume master files.."
   hlineboth
   update
   }

#----------------------------------------------------------------------------------------
# Rebuilds the _README_.HTM file for the book, using the list of files and descriptions   
# embedded in the script.  Also identifies files which files and directories which should 
# be present but are not.
#
proc rebuildReadmeHtmForBookProc { } { \
   #Entry message.
   outboth "Rebuild README.HTM for book button clicked."

   #First, open the _README_.HTM file for writing.  This will automatically empty the
   #file if it already exists.
   set fhandle [open _README_.HTM "w"]

   #Write the preamble to the file.
   rebuildReadmeWritePreamble $fhandle

   #Write the meat of the file.
   rebuildReadmeWriteMeat $fhandle

   #Write the postamble to the file.
   rebuildReadmeWritePostamble $fhandle

   #Close the file which was opened.
   close $fhandle
   
   #Termination message.
   outboth "DONE:  BUTTON PRESS:  Build of _README_.HTM."
   hlineboth
   }

#----------------------------------------------------------------------------------------
# Copies all of the book .PDF files to the places where they are needed (there may be   
# multiple locations for each file).  This is a simple copy operation. 
#
proc copyBookPdfsProc { } { \

   global bookVolumeList
   global bookVolumeListStructSize
   global readme_build_list

   set paths { \
      "c:/distribs/common/supmatls/books/embedded_control/dta_ucswbk_a"                       \
      "f:/wrootdta/proftopics/pubs_distributions_downloads/ucswbook01/outline_and_pdfs"       \
      }

   outboth "BUTTON PRESS:  Copy book .PDFs to other locations that must be"
   outboth "               mirrored."
   hlineboth

   #These are the names of the two single-volume files.   
   #set svlist {svf.pdf svd.pdf}
   set svlist {svf.pdf}

   foreach path $paths { \
      outbothnonl "Copying to "
      outboth $path

      #Iterate through, copy each single-volume file.
      set N [llength $svlist]
      for {set i 0} {$i < $N} {incr i} { \
         set source [lindex $svlist $i]
         set dest $path
         append dest / [lindex $svlist $i]
         if {[file exists $source]} { \
            outboth "   Copying from: $source"
            outboth "             to: $dest."
            file copy -force -- $source $dest
            } \
         else {
            outboth "   Can't copy $source:  does not exist."
            }
         update
         }         

      #Get number of elements in the list of volumes.
      set N [llength $bookVolumeList]

      #Iterate through, copy each file.
      for {set i 0} {$i < $N} {incr i $bookVolumeListStructSize} { \
         set source [lindex $bookVolumeList $i]
         append source .pdf
         set dest $path
         append dest / [lindex $bookVolumeList $i] .pdf
         if {[file exists $source]} { \
            outboth "   Copying from: $source"
            outboth "             to: $dest."
            file copy -force -- $source $dest
            } \
         else {
            outboth "   Can't copy $source:  does not exist."
            }
         update
         }
      }

   hlineboth

   #The above just copies the .PDF files to a few needed locations.  The portion below 
   #performs a full directory copy (just of the files mentioned in the list which
   #defines the _README_.HTM file) to a set of target directories.  The directories
   #themselves are wiped in advance.
   set fullcopypaths { \
      "f:/wrootdta/proftopics/pubs_distributions_downloads/ucswbook01/outline_and_pdfs"       \
      "f:/ftproot/anonymous_user_common_area/books/ucswbka"                                   \
      }

   foreach fullcopypath $fullcopypaths { \
      #Destroy the subdirectory and all subcomponents.
      outbothnonl "Destroying: "
      outboth $fullcopypath
      file delete -force $fullcopypath

      #Create the base directory.  This will be at the same level as the directory
      #"c:/esrgubka" in the build on Dave Ashley's computer.
      file mkdir $fullcopypath

      #For each of the files in the list to build the _README_.HTM file, create the
      #directory in which the file exists, the copy the file.
      foreach cur_line $readme_build_list { \
         #Update the display so there is not an apparent freeze.
         update

         #Iteration timesavers.
         set cur_tag [string range $cur_line 0 0]
         set cur_meat [string range $cur_line 2 end]

         if {! [string compare -nocase $cur_tag "F"]} { \

            #puts $cur_tag
            #puts $cur_meat

            #Replace any backslashes in the string with forward slashes.
            set fname $cur_meat
            set fname [string map {"\\" "/"} $fname]

            #Concatenate the target directory with the file name to get the full name.
            set fullfname ""
            append fullfname $fullcopypath
            append fullfname "/"
            append fullfname $fname

            #Rip off the final path component to get the directory that must exist, and 
            #create the required directory.
            set location [string last "/" $fullfname]
            if {$location >= 0} { \
               set dir_to_create [string range $fullfname 0 [expr $location - 1]]
               outbothnonl "   Creating directory: "
               set dir_to_create [string tolower $dir_to_create]
               outboth $dir_to_create
               file mkdir $dir_to_create
               } \
            else {
               outboth "No directory to create."
               }

            #Convert everything to lower case.  It looks more aesthetically pleasing
            #that way.
            set fname [string tolower $fname]
            set fullfname [string tolower $fullfname]

            #The directory that needs to exist definitely exists.  Perform the copy.
            outbothnonl "   Copying from: "
            outboth $fname
            outbothnonl "             to: "
            outboth $fullfname
            file copy -force -- $fname $fullfname
            }
         }
      }

   hlineboth
   }

#----------------------------------------------------------------------------------------
# Removes known extraneous and disposable ESRG Tool Set files and directories.               
#
proc removeESRGToolSetKnownExtraneousFilesAndDirectoriesProc { } { \
   outboth "ESRG Tool Set remove extraneous files and directories button clicked."
   hlineboth
   }

#----------------------------------------------------------------------------------------
# Identifies extraneous ESRG Tool Set files and directories, which are foreign but at the
# same time not known to be deletable.  It is safest to let the user look at these.
#
proc identifyESRGToolSetExtraneousFilesAndDirectoriesProc { } { \
   outboth "ESRG Tool Set identify extraneous files and directories button clicked."
   hlineboth
   }

#----------------------------------------------------------------------------------------
# Performs a full clean build of all executable versions of ESRGScripter.  This consists
# of:
#    o Deletion of all existing .OBJ and .EXE files to assure a clean build.
#    o Deletion of all other copy targets.
#    o A full clean build.
#    o A full re-copy to destinations for assembly.
#    o Generation of README.HTM files, watching for missing files.
#
proc fullBuildOfAllESRGToolSetExecutableVersionsProc { } { \
   outboth "ESRG Tool Set full build button clicked."
   hlineboth
   }


#----------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------
# Main script.

console show
   #We have to use this, or the console won't be created when running a script
   #directly on invocation.

#----------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------
#------  C O N S T A N T S   ----------------------------------------------------------__
#----------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------
#***************************************************************************
#Logging constants.
set loglinelength 78
   #The length of a line in the log.

set buildlogfilename cp_log.txt
   #The name of the log file which we'll use.

#***************************************************************************
#Directory path constants.  These can be configured for a different machine
#which might have a different drive name, etc.
#
#Path where Tex executables are located.
set pathTexExecutables "C:/Program Files/MiKTeX 2.9/miktex/bin/x64"
#
#Path where the the book source code is located.  Everything is assumed in
#a static arrangement below this directory.
set pathUcBookA c:/svnsbx/dtapublic/pubs/books/ucbka/trunk


#***************************************************************************
#Executable path constants.  There should be very little variation in these
#from machine to machine.  I've used 4AllTex (a distribution of LaTeX), but
#my understanding is that all distributions of LaTeX are the same executable
#names, etc.--usually just different GUI wrappers.
#
#File where the LaTeX compiler resides.
set execLatexCompiler ""
append execLatexCompiler $pathTexExecutables / latex.exe

#File where the MAKEINDEX program resides.
set execMakeindex ""
append execMakeindex $pathTexExecutables / makeindex.exe

#File where the DVIPS program resides.
set execDvips ""
append execDvips $pathTexExecutables / dvips.exe

#Executable for Acrobat Distiller.
set execAcrobatDistiller "C:/Program Files (x86)/Adobe/Acrobat 2017/Acrobat/acrodist.exe"


#***************************************************************************
#Volumes of the book, with their long and short titles, in the
#single-volume and multi-volume versions of the book, respectively.
#Order is:
#   Single volume long name (used when longer description is required in
#      single volume build).
#   Single volume short name (used when shorter description is required in
#      single volume build).
#   Single volume part name (used to actually name the "Part" in the
#      single-volume compile).  (May not be used.)
#   Multi-volume long name (used when longer description required).
#   Multi-volume short name (used when shorter description required).
#   Multi-volume cover name (the name which actually appears on the volume
#      cover).
#   Used flag (1 or 0), a scratch flag.
#      
#Each of these is a LaTeX compilation unit.  All 
#compilations and builds are based on this set of names.  These should be
#arranged in order of ascending volume numbers, not in alphabetical order.
#This is to protect for the case of moving to the Tcl script generating
#certain of the files automatically and numbering automatically.
#
#As of 08/27/01, this list contains many unused volumes that were deleted (and
#turned into chapters).  These will be kept around for a while, in case they 
#are added again in the future as the work grows.
set bookVolumeList {
                   con0                                                            \
                      "Concepts"                                                   \
                      "Concepts"                                                   \
                      "Concepts"                                                   \
                      "Concepts"                                                   \
                      "Concepts"                                                   \
                      "Concepts"                                                   \
                      "1"                                                          \
                   mfr0                                                            \
                      "Mathematical Frameworks And Results"                        \
                      "Mathematical Frameworks And Results"                        \
                      "Mathematical Frameworks And Results"                        \
                      "Mathematical Frameworks And Results"                        \
                      "Mathematical Frameworks And Results"                        \
                      "Mathematical Frameworks And Results"                        \
                      "1"                                                          \
                   csw0                                                            \
                      "Construction Of Embedded Software"                          \
                      "Construction Of Embedded Software"                          \
                      "Construction Of Embedded Software"                          \
                      "Construction Of Embedded Software"                          \
                      "Construction Of Embedded Software"                          \
                      "Construction Of Embedded Software"                          \
                      "1"                                                          \
                   alg0                                                            \
                      "Embedded System Algorithms And Techniques"                  \
                      "Embedded System Algorithms And Techniques"                  \
                      "Embedded System Algorithms And Techniques"                  \
                      "Embedded System Algorithms And Techniques"                  \
                      "Embedded System Algorithms And Techniques"                  \
                      "Embedded System Algorithms And Techniques"                  \
                      "1"                                                          \
                   pac0                                                            \
                      "Practical, Administrative, Incidental, And Miscellaneous Topics" \
                      "Practical, Administrative, Incidental, And Miscellaneous Topics" \
                      "Practical, Administrative, Incidental, And Miscellaneous Topics" \
                      "Practical, Administrative, Incidental, And Miscellaneous Topics" \
                      "Practical, Administrative, Incidental, And Miscellaneous Topics" \
                      "Practical, Administrative, Incidental, And Miscellaneous Topics" \
                      "1"                                                          \
                   isk0                                                            \
                      "Insektengericht And Lessons Learned"                        \
                      "Insektengericht And Lessons Learned"                        \
                      "Insektengericht And Lessons Learned"                        \
                      "Insektengericht And Lessons Learned"                        \
                      "Insektengericht And Lessons Learned"                        \
                      "Insektengericht And Lessons Learned"                        \
                      "1"                                                          \
                   ijt0                                                            \
                      "ESRG Workstation-Based Tool Set Reference Guide"            \
                      "ESRG Workstation-Based Tool Set Reference Guide"            \
                      "ESRG Workstation-Based Tool Set Reference Guide"            \
                      "ESRG Workstation-Based Tool Set Reference Guide"            \
                      "ESRG Workstation-Based Tool Set Reference Guide"            \
                      "ESRG Workstation-Based Tool Set Reference Guide"            \
                      "1"                                                          \
                   ijv0                                                            \
                      "ESRG Server-Based Tool Set Reference Guide"                 \
                      "ESRG Server-Based Tool Set Reference Guide"                 \
                      "ESRG Server-Based Tool Set Reference Guide"                 \
                      "ESRG Server-Based Tool Set Reference Guide"                 \
                      "ESRG Server-Based Tool Set Reference Guide"                 \
                      "ESRG Server-Based Tool Set Reference Guide"                 \
                      "1"                                                          \
                   sma0                                                            \
                      "Solutions Manual"                                           \
                      "Solutions Manual"                                           \
                      "Solutions Manual"                                           \
                      "Solutions Manual"                                           \
                      "Solutions Manual"                                           \
                      "Solutions Manual"                                           \
                      "1"                                                          \
                   rta0                                                            \
                      "Real-Time Analysis"                                         \
                      "Real-Time Analysis"                                         \
                      "Real-Time Analysis"                                         \
                      "Real-Time Analysis"                                         \
                      "Real-Time Analysis"                                         \
                      "Real-Time Analysis"                                         \
                      "1"                                                          \
                   scr0                                                            \
                      "Support Of Common Software Requirements And Design Scenarios"\
                      "Support Of Common Software Requirements And Design Scenarios"\
                      "Support Of Common Software Requirements And Design Scenarios"\
                      "Support Of Common Software Requirements And Design Scenarios"\
                      "Support Of Common Software Requirements And Design Scenarios"\
                      "Support Of Common Software Requirements And Design Scenarios"\
                      "1"                                                          \
                   soc0                                                            \
                      "Support Of On-Chip Peripherals And Systems"                 \
                      "Support Of On-Chip Peripherals And Systems"                 \
                      "Support Of On-Chip Peripherals And Systems"                 \
                      "Support Of On-Chip Peripherals And Systems"                 \
                      "Support Of On-Chip Peripherals And Systems"                 \
                      "Support Of On-Chip Peripherals And Systems"                 \
                      "1"                                                          \
                   sfc0                                                            \
                      "Support Of Off-Chip Peripherals And Systems"                \
                      "Support Of Off-Chip Peripherals And Systems"                \
                      "Support Of Off-Chip Peripherals And Systems"                \
                      "Support Of Off-Chip Peripherals And Systems"                \
                      "Support Of Off-Chip Peripherals And Systems"                \
                      "Support Of Off-Chip Peripherals And Systems"                \
                      "1"                                                          \
                   caf0                                                            \
                      "Implementation Of Common Automotive Features"               \
                      "Implementation Of Common Automotive Features"               \
                      "Implementation Of Common Automotive Features"               \
                      "Implementation Of Common Automotive Features"               \
                      "Implementation Of Common Automotive Features"               \
                      "Implementation Of Common Automotive Features"               \
                      "1"                                                          \
                   snw0                                                            \
                      "Support Of Networks And Communication Protocols"            \
                      "Support Of Networks And Communication Protocols"            \
                      "Support Of Networks And Communication Protocols"            \
                      "Support Of Networks And Communication Protocols"            \
                      "Support Of Networks And Communication Protocols"            \
                      "Support Of Networks And Communication Protocols"            \
                      "1"                                                          \
                   nal0                                                            \
                      "Numerical Algorithms, Results, And Techniques"              \
                      "Numerical Algorithms, Results, And Techniques"              \
                      "Numerical Algorithms, Results, And Techniques"              \
                      "Numerical Algorithms, Results, And Techniques"              \
                      "Numerical Algorithms, Results, And Techniques"              \
                      "Numerical Algorithms, Results, And Techniques"              \
                      "1"                                                          \
                   nna0                                                            \
                      "Non-Numerical Algorithms, Results, And Techniques"          \
                      "Non-Numerical Algorithms, Results, And Techniques"          \
                      "Non-Numerical Algorithms, Results, And Techniques"          \
                      "Non-Numerical Algorithms, Results, And Techniques"          \
                      "Non-Numerical Algorithms, Results, And Techniques"          \
                      "Non-Numerical Algorithms, Results, And Techniques"          \
                      "1"                                                          \
                   sdm0                                                            \
                      "Software Design Methods"                                    \
                      "Software Design Methods"                                    \
                      "Software Design Methods"                                    \
                      "Software Design Methods"                                    \
                      "Software Design Methods"                                    \
                      "Software Design Methods"                                    \
                      "1"                                                          \
                   cpc0                                                            \
                      "Microcontroller And CPU Core Usage Application Notes"       \
                      "Microcontroller And CPU Core Usage Application Notes"       \
                      "Microcontroller And CPU Core Usage Application Notes"       \
                      "Microcontroller And CPU Core Usage Application Notes"       \
                      "Microcontroller And CPU Core Usage Application Notes"       \
                      "Microcontroller And CPU Core Usage Application Notes"       \
                      "1"                                                          \
                   sti0                                                            \
                      "Software Tool Descriptions And Information"                 \
                      "Software Tool Descriptions And Information"                 \
                      "Software Tool Descriptions And Information"                 \
                      "Software Tool Descriptions And Information"                 \
                      "Software Tool Descriptions And Information"                 \
                      "Software Tool Descriptions And Information"                 \
                      "1"                                                          \
                   stn0                                                            \
                      "Software Tool Usage And Application Notes"                  \
                      "Software Tool Usage And Application Notes"                  \
                      "Software Tool Usage And Application Notes"                  \
                      "Software Tool Usage And Application Notes"                  \
                      "Software Tool Usage And Application Notes"                  \
                      "Software Tool Usage And Application Notes"                  \
                      "1"                                                          \
                   hti0                                                            \
                      "Hardware Tool Descriptions And Information"                 \
                      "Hardware Tool Descriptions And Information"                 \
                      "Hardware Tool Descriptions And Information"                 \
                      "Hardware Tool Descriptions And Information"                 \
                      "Hardware Tool Descriptions And Information"                 \
                      "Hardware Tool Descriptions And Information"                 \
                      "1"                                                          \
                   htn0                                                            \
                      "Hardware Tool Usage And Application Notes"                  \
                      "Hardware Tool Usage And Application Notes"                  \
                      "Hardware Tool Usage And Application Notes"                  \
                      "Hardware Tool Usage And Application Notes"                  \
                      "Hardware Tool Usage And Application Notes"                  \
                      "Hardware Tool Usage And Application Notes"                  \
                      "1"                                                          \
                   hwd0                                                            \
                      "Hardware Design"                                            \
                      "Hardware Design"                                            \
                      "Hardware Design"                                            \
                      "Hardware Design"                                            \
                      "Hardware Design"                                            \
                      "Hardware Design"                                            \
                      "1"                                                          \
                   pte0                                                            \
                      "Product Testing"                                            \
                      "Product Testing"                                            \
                      "Product Testing"                                            \
                      "Product Testing"                                            \
                      "Product Testing"                                            \
                      "Product Testing"                                            \
                      "1"                                                          \
                   pas0                                                            \
                      "Product Manufacturing And Assembly"                         \
                      "Product Manufacturing And Assembly"                         \
                      "Product Manufacturing And Assembly"                         \
                      "Product Manufacturing And Assembly"                         \
                      "Product Manufacturing And Assembly"                         \
                      "Product Manufacturing And Assembly"                         \
                      "1"                                                          \
                   pro0                                                            \
                      "Process, Administrative, And Personnel Issues"              \
                      "Process, Administrative, And Personnel Issues"              \
                      "Process, Administrative, And Personnel Issues"              \
                      "Process, Administrative, And Personnel Issues"              \
                      "Process, Administrative, And Personnel Issues"              \
                      "Process, Administrative, And Personnel Issues"              \
                      "1"                                                          \
                   orq0                                                            \
                      "Open Research Questions"                                    \
                      "Open Research Questions"                                    \
                      "Open Research Questions"                                    \
                      "Open Research Questions"                                    \
                      "Open Research Questions"                                    \
                      "Open Research Questions"                                    \
                      "1"                                                          \
                   llr0                                                            \
                      "Lessons Learned"                                            \
                      "Lessons Learned"                                            \
                      "Lessons Learned"                                            \
                      "Lessons Learned"                                            \
                      "Lessons Learned"                                            \
                      "Lessons Learned"                                            \
                      "1"                                                          \
                   bpr0                                                            \
                      "Best Practices"                                             \
                      "Best Practices"                                             \
                      "Best Practices"                                             \
                      "Best Practices"                                             \
                      "Best Practices"                                             \
                      "Best Practices"                                             \
                      "1"                                                          \
                   hpj0                                                            \
                      "Hardware Projects"                                          \
                      "Hardware Projects"                                          \
                      "Hardware Projects"                                          \
                      "Hardware Projects"                                          \
                      "Hardware Projects"                                          \
                      "Hardware Projects"                                          \
                      "1"                                                          \
                   sca0                                                            \
                      "Software Case Studies"                                      \
                      "Software Case Studies"                                      \
                      "Software Case Studies"                                      \
                      "Software Case Studies"                                      \
                      "Software Case Studies"                                      \
                      "Software Case Studies"                                      \
                      "1"                                                          \
                   hca0                                                            \
                      "Hardware Case Studies"                                      \
                      "Hardware Case Studies"                                      \
                      "Hardware Case Studies"                                      \
                      "Hardware Case Studies"                                      \
                      "Hardware Case Studies"                                      \
                      "Hardware Case Studies"                                      \
                      "1"                                                          \
                   cdt0                                                            \
                      "Correspondence And Discussion Threads"                      \
                      "Correspondence And Discussion Threads"                      \
                      "Correspondence And Discussion Threads"                      \
                      "Correspondence And Discussion Threads"                      \
                      "Correspondence And Discussion Threads"                      \
                      "Correspondence And Discussion Threads"                      \
                      "1"                                                          \
                   dtm0                                                            \
                      "Document Templates"                                         \
                      "Document Templates"                                         \
                      "Document Templates"                                         \
                      "Document Templates"                                         \
                      "Document Templates"                                         \
                      "Document Templates"                                         \
                      "1"                                                          \
                   }

set bookVolumeListStructSize 8
   #The numer of physical records per each logical record in the list above.  This
   #minimizes tearup if things are added to what is above.

set bookVolumeListIndex(NOT_USED) 0
   #Used to initialize the associative index array for the book volumes, so there are
   #no problems declaring it global to procs before it is first defined.  This index
   #is associative by the 4-character volume code, and stores an integer which is the
   #base array index into the group of info for that volume name.  This is done to
   #avoid repeated searches of the entire space.  I would guess the Tcl hash function
   #is faster than a linear search.

# The list of chapters in the entire work.  They don't have to be in any particular
# order (so I've arranged them alphabetically by tag).  The fields are, in order:
#    a)The tag.
#    b)Single volume long name.
#    c)Single volume short name.
#    d)Multiple volume long name.
#    e)Multiple volume short name.
#    f)Single volume status ("D" or "F").  "D" indicates that chapter should be treated as a
#      draft chapter for the single volume work and only included in the draft version.  "F" indicates
#      should be included in both draft and final versions.
#    g)Multi-volume status ("D" or "F").  See description immediately above, except
#      applies to multi-volume work.
#    h)"Used" flag ("Y" or "N").  This flag is set by the software as it runs to remember if a chapter
#      is referenced in the mcl or not.  This is a scratch flag.
#
# As of 08/27/01, this list contains many unused chapters that were deleted.  These will
# be kept around for a while, in case they are added again in the future as the work grows.
set chapterList {
                add0                                                                                 \
                   "Addition"                                                                        \
                   "Addition"                                                                        \
                   "Addition"                                                                        \
                   "Addition"                                                                        \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                bal0                                                                                 \
                   "Boolean Algebra And Simplification Of Boolean Functions"                         \
                   "Simplification Of Boolean Functions"                                             \
                   "Boolean Algebra And Simplification Of Boolean Functions"                         \
                   "Simplification Of Boolean Functions"                                             \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                bas0                                                                                 \
                   "Solutions:  Boolean Algebra And Simplification Of Boolean Functions"             \
                   "Solutions:  Boolean Algebra"                                                     \
                   "Solutions:  Boolean Algebra And Simplification Of Boolean Functions"             \
                   "Solutions:  Boolean Algebra"                                                     \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                ber0                                                                                 \
                   "Build Environment Research Questions"                                            \
                   "Build Environment Research Questions"                                            \
                   "Build Environment Research Questions"                                            \
                   "Build Environment Research Questions"                                            \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                bma0                                                                                 \
                   "Bad Management And Unpleasant Work Situations"                                   \
                   "Bad Management"                                                                  \
                   "Bad Management And Unpleasant Work Situations"                                   \
                   "Bad Management"                                                                  \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                cch0                                                                                 \
                   "CRC, Checksum, And Hash Function Extensions"                                     \
                   "CRC, Checksum, And Hash Extensions"                                              \
                   "CRC, Checksum, And Hash Function Extensions"                                     \
                   "CRC, Checksum, And Hash Extensions"                                              \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                cfr0                                                                                 \
                   "Continued Fractions And Related Topics"                                          \
                   "Continued Fractions And Related Topics"                                          \
                   "Continued Fractions And Related Topics"                                          \
                   "Continued Fractions And Related Topics"                                          \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                cfs0                                                                                 \
                   "Solutions:  Continued Fractions And Related Topics"                              \
                   "Solutions:  Continued Fractions"                                                 \
                   "Solutions:  Continued Fractions And Related Topics"                              \
                   "Solutions:  Continued Fractions"                                                 \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                cil0                                                                                 \
                   "Classical And Simple Integer Algorithms And Techniques"                          \
                   "Simple Integer Algorithms"                                                       \
                   "Classical And Simple Integer Algorithms And Techniques"                          \
                   "Simple Integer Algorithms"                                                       \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                cis0                                                                                 \
                   "Solutions:  Classical And Simple Integer Algorithms And Techniques"              \
                   "Solutions:  Simple Integer Algorithms"                                           \
                   "Solutions:  Classical And Simple Integer Algorithms And Techniques"              \
                   "Solutions:  Simple Integer Algorithms"                                           \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                css1                                                                                 \
                   "Canonical Server Setup"                                                          \
                   "Canonical Server Setup"                                                          \
                   "Canonical Server Setup"                                                          \
                   "Canonical Server Setup"                                                          \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                cst0                                                                                 \
                   "Coding Standards"                                                                \
                   "Coding Standards"                                                                \
                   "Coding Standards"                                                                \
                   "Coding Standards"                                                                \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                daa0                                                                                 \
                   "Decoration And Automatic Assembly"                                               \
                   "Decoration And Automatic Assembly"                                               \
                   "Decoration And Automatic Assembly"                                               \
                   "Decoration And Automatic Assembly"                                               \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                dcm0                                                                                 \
                   "DOS Console-Mode Utilities"                                                      \
                   "DOS Console-Mode Utilities"                                                      \
                   "DOS Console-Mode Utilities"                                                      \
                   "DOS Console-Mode Utilities"                                                      \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                div0                                                                                 \
                   "Division"                                                                        \
                   "Division"                                                                        \
                   "Division"                                                                        \
                   "Division"                                                                        \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                dta0                                                                                 \
                   "Discrete-Time And Complex Integer Algorithms And Techniques"                     \
                   "Complex Integer Algorithms"                                                      \
                   "Discrete-Time And Complex Integer Algorithms And Techniques"                     \
                   "Complex Integer Algorithms"                                                      \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                edc0                                                                                 \
                   "Error-Detecting And Error-Correcting Codes, With Microcontroller Applications"   \
                   "Error-Detecting And Correcting Codes"                                            \
                   "Error-Detecting And Error-Correcting Codes, With Microcontroller Applications"   \
                   "Error-Detecting And Correcting Codes"                                            \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                eds0                                                                                 \
                   "Solutions:  Error-Detecting And Error-Correcting Codes, With Microcontroller Applications"   \
                   "Solutions:  Error-Detecting And Correcting Codes"                                \
                   "Solutions:  Error-Detecting And Error-Correcting Codes, With Microcontroller Applications"   \
                   "Solutions:  Error-Detecting And Correcting Codes"                                \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                faq0                                                                                 \
                   "Frequently Asked Questions And Frequently Encountered Problems"                  \
                   "FAQs And Common Problems"                                                        \
                   "Frequently Asked Questions And Frequently Encountered Problems"                  \
                   "FAQs And Common Problems"                                                        \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                frs0                                                                                 \
                   "Solutions:  Farey Series And Related Topics"                                     \
                   "Solutions:  Farey Series"                                                        \
                   "Solutions:  Farey Series And Related Topics"                                     \
                   "Solutions:  Farey Series"                                                        \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                fry0                                                                                 \
                   "Farey Series And Related Topics"                                                 \
                   "Farey Series And Related Topics"                                                 \
                   "Farey Series And Related Topics"                                                 \
                   "Farey Series And Related Topics"                                                 \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                fte0                                                                                 \
                   "File Transformation Extension"                                                   \
                   "File Transformation Extension"                                                   \
                   "File Transformation Extension"                                                   \
                   "File Transformation Extension"                                                   \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                hgr0                                                                                 \
                   "The Holy Grail"                                                                  \
                   "The Holy Grail"                                                                  \
                   "The Holy Grail"                                                                  \
                   "The Holy Grail"                                                                  \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                hrq0                                                                                 \
                   "Hardware Research Questions"                                                     \
                   "Hardware Research Questions"                                                     \
                   "Hardware Research Questions"                                                     \
                   "Hardware Research Questions"                                                     \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                int0                                                                                 \
                   "Introduction To Small Microcontroller Work"                                      \
                   "Introduction To Small Microcontroller Work"                                      \
                   "Introduction To Small Microcontroller Work"                                      \
                   "Introduction To Small Microcontroller Work"                                      \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                ird0                                                                                 \
                   "Interrupt-Related Software Defects"                                              \
                   "Interrupt-Related Software Defects"                                              \
                   "Interrupt-Related Software Defects"                                              \
                   "Interrupt-Related Software Defects"                                              \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                isa1                                                                                 \
                   "Introduction and Server Architecture"                                            \
                   "Introduction and Server Architecture"                                            \
                   "Introduction and Server Architecture"                                            \
                   "Introduction and Server Architecture"                                            \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                isk0                                                                                 \
                   "Insektengericht And Lessons Learned"                                             \
                   "Insektengericht And Lessons Learned"                                             \
                   "Insektengericht And Lessons Learned"                                             \
                   "Insektengericht And Lessons Learned"                                             \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                lie0                                                                                 \
                   "Long Integer Extensions"                                                         \
                   "Long Integer Extensions"                                                         \
                   "Long Integer Extensions"                                                         \
                   "Long Integer Extensions"                                                         \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                mpd0                                                                                 \
                   "Management Of Product Development Materials"                                     \
                   "Management Of Product Development Materials"                                     \
                   "Management Of Product Development Materials"                                     \
                   "Management Of Product Development Materials"                                     \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                mtn0                                                                                 \
                   "Miscellaneous Topics From Mathematics And Number Theory"                         \
                   "Miscellaneous Mathematical Topics"                                               \
                   "Miscellaneous Topics From Mathematics And Number Theory"                         \
                   "Miscellaneous Mathematical Topics"                                               \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                mul0                                                                                 \
                   "Multiplication"                                                                  \
                   "Multiplication"                                                                  \
                   "Multiplication"                                                                  \
                   "Multiplication"                                                                  \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                nam0                                                                                 \
                   "Naming Conventions"                                                              \
                   "Naming Conventions"                                                              \
                   "Naming Conventions"                                                              \
                   "Naming Conventions"                                                              \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                nnu0                                                                                 \
                   "Non-Numerical Algorithms And Techniques"                                         \
                   "Non-Numerical Algorithms And Techniques"                                         \
                   "Non-Numerical Algorithms And Techniques"                                         \
                   "Non-Numerical Algorithms And Techniques"                                         \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                nth0                                                                                 \
                   "Number Theory Extensions"                                                        \
                   "Number Theory Extensions"                                                        \
                   "Number Theory Extensions"                                                        \
                   "Number Theory Extensions"                                                        \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                orq0                                                                                 \
                   "Open Research Questions"                                                         \
                   "Open Research Questions"                                                         \
                   "Open Research Questions"                                                         \
                   "Open Research Questions"                                                         \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                pbc0                                                                                 \
                   "Product Build- And Configuration-Related Software Defects"                       \
                   "Build And Configuration Defects"                                                 \
                   "Product Build- And Configuration-Related Software Defects"                       \
                   "Build And Configuration Defects"                                                 \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                pco0                                                                                 \
                   "General Practical Construction Of Embedded Software"                             \
                   "General Practical Construction Of Embedded Software"                             \
                   "General Practical Construction Of Embedded Software"                             \
                   "General Practical Construction Of Embedded Software"                             \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                pit0                                                                                 \
                   "Practical Interface And Test Circuits"                                           \
                   "Practical Interface And Test Circuits"                                           \
                   "Practical Interface And Test Circuits"                                           \
                   "Practical Interface And Test Circuits"                                           \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                pri0                                                                                 \
                   "Integers, Prime Numbers, And Related Topics"                                     \
                   "Integers, Primes, And Related Topics"                                            \
                   "Integers, Prime Numbers, And Related Topics"                                     \
                   "Integers, Primes, And Related Topics"                                            \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                prs0                                                                                 \
                   "Solutions:  Integers, Prime Numbers, And Related Topics"                         \
                   "Solutions:  Integers, Primes, And Related Topics"                                \
                   "Solutions:  Integers, Prime Numbers, And Related Topics"                         \
                   "Solutions:  Integers, Primes, And Related Topics"                                \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                pxf0                                                                                 \
                   "Products Of Exceptional Functionality"                                           \
                   "Products Of Exceptional Functionality"                                           \
                   "Products Of Exceptional Functionality"                                           \
                   "Products Of Exceptional Functionality"                                           \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                qua0                                                                                 \
                   "Quantization"                                                                    \
                   "Quantization"                                                                    \
                   "Quantization"                                                                    \
                   "Quantization"                                                                    \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                rat0                                                                                 \
                   "Rational Approximation"                                                          \
                   "Rational Approximation"                                                          \
                   "Rational Approximation"                                                          \
                   "Rational Approximation"                                                          \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                ras0                                                                                 \
                   "Solutions:  Rational Approximation"                                              \
                   "Solutions:  Rational Approximation"                                              \
                   "Solutions:  Rational Approximation"                                              \
                   "Solutions:  Rational Approximation"                                              \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                rcs0                                                                                 \
                   "Ratiometric Conversion And Measurement Systems"                                  \
                   "Ratiometric Measurement Systems"                                                 \
                   "Ratiometric Conversion And Measurement Systems"                                  \
                   "Ratiometric Measurement Systems"                                                 \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                rnd1                                                                                 \
                   "Random Number Generation Extensions"                                             \
                   "Random Number Generation Extensions"                                             \
                   "Random Number Generation Extensions"                                             \
                   "Random Number Generation Extensions"                                             \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                rne0                                                                                 \
                   "Rational Number Extensions"                                                      \
                   "Rational Number Extensions"                                                      \
                   "Rational Number Extensions"                                                      \
                   "Rational Number Extensions"                                                      \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                rta0                                                                                 \
                   "Real-Time Analysis"                                                              \
                   "Real-Time Analysis"                                                              \
                   "Real-Time Analysis"                                                              \
                   "Real-Time Analysis"                                                              \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                sds0                                                                                 \
                   "Standard Directory Structures"                                                   \
                   "Standard Directory Structures"                                                   \
                   "Standard Directory Structures"                                                   \
                   "Standard Directory Structures"                                                   \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                sfo0                                                                                 \
                   "Support Of Frequently-Occurring Requirements"                                    \
                   "Support Of Frequently-Occurring Requirements"                                    \
                   "Support Of Frequently-Occurring Requirements"                                    \
                   "Support Of Frequently-Occurring Requirements"                                    \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                snc0                                                                                 \
                   "Support Of Communication Protocols And Networks"                                 \
                   "Support Of Communication Protocols And Networks"                                 \
                   "Support Of Communication Protocols And Networks"                                 \
                   "Support Of Communication Protocols And Networks"                                 \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                soc0                                                                                 \
                   "Support Of On-Chip Peripherals And Subsystems"                                   \
                   "Support Of On-Chip Peripherals And Subsystems"                                   \
                   "Support Of On-Chip Peripherals And Subsystems"                                   \
                   "Support Of On-Chip Peripherals And Subsystems"                                   \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                soc1                                                                                 \
                   "Support Of Off-Chip Peripherals And Subsystems"                                  \
                   "Off-Chip Peripherals And Subsystems"                                             \
                   "Support Of Off-Chip Peripherals And Subsystems"                                  \
                   "Off-Chip Peripherals And Subsystems"                                             \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                sub0                                                                                 \
                   "Subtraction"                                                                     \
                   "Subtraction"                                                                     \
                   "Subtraction"                                                                     \
                   "Subtraction"                                                                     \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                tcm0                                                                                 \
                   "Tcl Command Reference"                                                           \
                   "Tcl Command Reference"                                                           \
                   "Tcl Command Reference"                                                           \
                   "Tcl Command Reference"                                                           \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                tin0                                                                                 \
                   "Introduction And Overview Of The ESRG Tool Set"                                  \
                   "ESRG Tool Set Overview/Introduction"                                             \
                   "Introduction And Overview Of The ESRG Tool Set"                                  \
                   "ESRG Tool Set Overview/Introduction"                                             \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                tkm0                                                                                 \
                   "Tk Command Reference"                                                            \
                   "Tk Command Reference"                                                            \
                   "Tk Command Reference"                                                            \
                   "Tk Command Reference"                                                            \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                vct0                                                                                 \
                   "Version Control Extensions"                                                      \
                   "Version Control Extensions"                                                      \
                   "Version Control Extensions"                                                      \
                   "Version Control Extensions"                                                      \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                wrl0                                                                                 \
                   "Watchdog-Related Lessons Learned"                                                \
                   "Watchdog-Related Lessons Learned"                                                \
                   "Watchdog-Related Lessons Learned"                                                \
                   "Watchdog-Related Lessons Learned"                                                \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                xtn0                                                                                 \
                   "Tcl/Tk Extensions"                                                               \
                   "Tcl/Tk Extensions"                                                               \
                   "Tcl/Tk Extensions"                                                               \
                   "Tcl/Tk Extensions"                                                               \
                   "F"                                                                               \
                   "F"                                                                               \
                   "0"                                                                               \
                }

set chapterListStructSize 8
   # The number of physical records per logical record.  Makes modifications easier if records added
   # to end.

set chapterListIndex(NOT_USED) 0
   #Used to initialize the associative index array for the book chapters, so there are
   #no problems declaring it global to procs before it is first defined.  This index
   #is associative by the 4-character chapter code, and stores an integer which is the
   #base array index into the group of info for that chapter name.  This is done to
   #avoid repeated searches of the entire space.  I would guess the Tcl hash function
   #is faster than a linear search.


# This is the master compilation list.  This indicates the bindings between volumes and chapters
# and so forth.  The two major compilation themes are "Single-Volume" (the entire book in one
# document) and "Multi-Volume" (the work is broken up into volumes).  Each type of compilation loops
# through the list to extract the records of interest to it.  There is commonization possible, but it
# is also possible that the two types of work are disjoint enough that they are nearly separate.  The
# list format accomodates both.  Each list item is a record, with the record type followed by three
# parameters, any or all of which may be optional.  Record types are as follows:
#
# v:  Start of a new volume.  In this case, par1 is the 4-character tag of the volume.  par2
#     and par3 are ignored.
#
# p:  Start of a new part.  In this case, there are two possibilities.  par1 may indicate the
#     4-character tag of the volume to use for info (the part name is extracted from there), or par2 may
#     indicate the actual title of the part.
#
# w:  Start of both new volume and new part.  par1 contains the 4-character tag of the volume,
#     and par2 contains an optional title string.  The volume title is always taken from the data
#     for par1.  The part name is taken from the same data if par2 is empty, or else par2 overrides
#     the part name.  par3 is ignored.
#
# c:  Volume chapter.  par1 provides the 4-character chapter tag.  par2 and par3 are ignored.
#
# d:  Part chapter.  par1 provides the 4-character chapter tag.  par2 and par3 are ignored.
#
# e:  Both volume and part chapter.  par1 provides the 4-character chapter tag.  par2 and par3 are
#     ignored.
# 
# y:  Beginning of "appendix" matter of volume of multi-volume work.  par1, par2, and par3 are ignored.
#
# z:  Beginning of "appendix" matter of single-volume work.  par1, par2, and par3 are ignored.
#
# Based on this table plus the volume and chapter tables earlier, this Tcl script prepares the following files:
#   svf.tex
#      The single-volume final master TEX file.
#   svd.tex
#      The single-volume draft master TEX file.
#   ????f.tex
#      For each volume, the master volume final TEX file.
#   ????d.tex
#      For each volume, the master volume draft TEX file.
#
# The differentiation between "final" and "draft" is that in a "final" work, the chapters marked as
# draft aren't included.
#   
set mcl {
        "v"                                                                                                   \
        "con0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "p"                                                                                                   \
        ""                                                                                                    \
        "Concepts"                                                                                            \
        ""                                                                                                    \
        "e"                                                                                                   \
        "int0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "hgr0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "y"                                                                                                   \
        ""                                                                                                    \
        ""                                                                                                    \
        ""                                                                                                    \
        "w"                                                                                                   \
        "mfr0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "pri0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "fry0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "cfr0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "edc0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "bal0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "qua0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "mtn0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "w"                                                                                                   \
        "csw0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "pco0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "soc0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "soc1"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "snc0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "sfo0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "rta0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "w"                                                                                                   \
        "alg0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "cil0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "rat0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "dta0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "nnu0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "w"                                                                                                   \
        "pac0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "mpd0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "pit0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "bma0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "pxf0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "orq0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "isk0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "w"                                                                                                   \
        "ijt0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "tin0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "tcm0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "tkm0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "faq0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "xtn0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "dcm0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "w"                                                                                                   \
        "ijv0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "isa1"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "css1"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "w"                                                                                                   \
        "sma0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "prs0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "frs0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "cfs0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "eds0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "bas0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "cis0"                                                                                              \
        ""                                                                                                    \
        ""                                                                                                    \
        "e"                                                                                                   \
        "ras0"                                                                                                \
        ""                                                                                                    \
        ""                                                                                                    \
        "p"                                                                                                   \
        ""                                                                                                    \
        "Glossaries, Bibliography, And Index"                                                                                            \
        ""                                                                                                    \
        "z"                                                                                                   \
        ""                                                                                                    \
        ""                                                                                                    \
        ""                                                                                                    \
        }

#List which gives instructions for forming the _README_.HTM file.  Each string in the
#list is one of the following types:
#  F:  filename : specifies a filename to be incorporated as a link.  Also used
#      as a reference to copy files which will eventually go into the CD for
#      the book.  If it doesn't appear in this list and in the _README_.HTM
#      file, it won't be copied.
#  H:  Manually specified header.  This is a banner header with a title
#      we get to specify.
#  C:  Chapter header.  We use the chapter tag for this.
#  D:  Description line following filename.
#
set readme_build_list {
        "M:PDF Versions Of This Work"                                                                         \
        "F:SVF.PDF"                                                                                           \
        "D:PDF version of the single-volume work."                                                            \
        "M:Outline Of This Work (And FTP Information)"                                                        \
        "F:INDEX2.HTM"                                                                                        \
        "D:Outline of this work.  Also includes information about how to obtain the complete set of LaTeX"    \
        "D:build materials via anonymous FTP."                                                                \
        "M:Utility And Build Files"                                                                           \
        "F:_README_.HTM"                                                                                      \
        "D:This file."                                                                                        \
        "F:WBBKGNDS\\BKBLUE01.GIF"                                                                            \
        "D:Blue background used for some HTML documents."                                                     \
        "F:WBBKGNDS\\BKYELL01.GIF"                                                                            \
        "D:Yellow background used for some HTML documents."                                                   \
        "F:SCRIPTS\\CP_SCRIPT.TCL"                                                                            \
        "D:The Wish (i.e. Tcl/Tk) script used to build the book and peform utility functions"                 \
        "D:(such as copying the resulting files to locations on the server in Dave Ashley's"                  \
        "D:apartment).&nbsp; This script must be checked and modified to run on any computer"                 \
        "D:(besides Dave Ashley's) because it makes assumptions about the location and presence"              \
        "D:of LaTeX, LaTeX utilities, and other programs.&nbsp; To build the book without using"              \
        "D:this script, use a LaTeX compiler to compile the file"                                             \
        "D:<a href=\"svf.tex\">SVF.TEX</a>."                                                                  \
        "F:SCRIPTS\\IJC.EXE"                                                                                  \
        "D:The statically compiled Wish interpreter used to interpret the Wish script above.&nbsp; This"      \
        "D:executable is usable &quot;as-is&quot;; however, the full distribution of this Wish interpreter"   \
        "D:can be obtained as <a href=\"http://www.digibuy.com/cgi-bin/product.html?97647721717\">Digibuy"    \
        "D:Product \#97647721717</a>, and the full source code can be obtained as"                            \
        "D:<a href=\"http://www.digibuy.com/cgi-bin/product.html?97647784511\">Digibuy Product"               \
        "D:#97647784511</a>.&nbsp; Please note that newer versions of these Digibuy products"                 \
        "D:may be available."                                                                                 \
        "F:SCRIPTS\\BOOK BUILD SCRIPT.LNK"                                                                    \
        "D:The Windows 98 shortcut which allows the Wish script (above) to be run using the static"           \
        "D:Wish interpreter (above).&nbsp; This shortcut comes from a Windows '98 system and it is"           \
        "D:not known which Windows systems it is compatible with."                                            \
        "C:int0"                                                                                              \
        "F:C_INT0\\C_INT0.TEX"                                                                                \
        "D:LaTeX source code for the chapter."                                                                \
        "C:hgr0"                                                                                              \
        "F:C_HGR0\\C_HGR0.TEX"                                                                                \
        "D:LaTeX source code for the chapter."                                                                \
        "C:pri0"                                                                                              \
        "F:C_PRI0\\C_PRI0.TEX"                                                                                \
        "D:LaTeX source code for the chapter."                                                                \
        "F:C_FRY0\\C_FRY0.TEX"                                                                                \
        "D:LaTeX source code for the chapter."                                                                \
        "F:C_FRY0\\FAREY01A.DSF"                                                                              \
        "D:Micrografx Designer document for the diagram showing the integer lattice interpretation"           \
        "D:of the Farey series with numerator and denominator both constrained."                              \
        "F:C_FRY0\\FAREY01A.EPS"                                                                              \
        "D:Postscript version of C_FRY0\\FAREY01A.DSF, used with LaTeX."                                      \
        "F:C_FRY0\\FAREY01B.DSF"                                                                              \
        "D:Micrografx Designer document for the diagram showing the graphical construction of the Farey"      \
        "D:series with numerator and denominator both constrained."                                           \
        "F:C_FRY0\\FAREY01B.EPS"                                                                              \
        "D:Postscript version of C_FRY0\\FAREY01B.DSF, used with LaTeX."                                      \
        "C:cfr0"                                                                                              \
        "F:C_CFR0\\C_CFR0.TEX"                                                                                \
        "D:LaTeX source code for the chapter."                                                                \
        }


#*************************************
#Graphical button display constants
set buttonPadx 5
set buttonPady 5
set buttonWidth 45
set buttonHeight 2
set exitButtonColor #f88
set bookButtonColor #3d3
set esrgtoolsetButtonColor #99d

#----------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------
#-----   L O G    F I L E    O P E N    -----------------------------------------------__
#----------------------------------------------------------------------------------------
#----------------------------------------------------------------------------------------
#Write a thick horizontal line to the console.
thickhlineconsole

#Need to change working directories to the root directory for the book.
#The log file goes there.
cd $pathUcBookA

#Attempt to get the build log file open.  If this file is read only (which I
#don't care to override from the script), or if there are other problems, 
#just abort.  We cannot proceed unless we can make a log.
#      
puts -nonewline "Attempting to open the build log file ($buildlogfilename) ... "   
set buildlogfilehandle [open $buildlogfilename "w+"]
puts "success."
puts -nonewline "Build log file handle is:  $buildlogfilehandle"; puts "."
puts "All console output from this point forward will be echoed to the log file."

#-----------------------------------------------------------------------------
#Thick horizontal line to denote start.
thickhlineboth

#Annunciation, what we are trying to build.
outboth "*** Book And ESRG Tool Set Utility Script Log ***"
hlineboth

#Put the system date and time into the build log and on the console.
set buildbegintimestamp [clock seconds]
set s0 [clock format $buildbegintimestamp -format "Execution beginning at: %A, %B %d, %Y; %I:%M:%S %p."]
outboth $s0
hlineboth

#Index the list of volumes for quicker access and manipulation.
IndexVolumeList

#Index the list of chapters for quicker access and manipulation.
IndexChapterList


#*************************************

set exitButton      [button .b1 -padx $buttonPadx -pady $buttonPady \
                    -text "Exit" \
					-command exitProc -width $buttonWidth -height $buttonHeight \
					-background $exitButtonColor]

set rebuildMasterFilesButton \
                    [button .b2 -padx $buttonPadx -pady $buttonPady \
                    -text "BOOK:  Rebuild\nmaster .TEX files" \
					-command masterFileRebuildProc -width $buttonWidth -height $buttonHeight \
					-background $bookButtonColor]

set rebuildReadmeHtmBookButton \
                    [button .b3 -padx $buttonPadx -pady $buttonPady \
                    -text "BOOK:  Rebuild\nREADME.HTM" \
					-command rebuildReadmeHtmForBookProc -width $buttonWidth -height $buttonHeight \
					-background $bookButtonColor]

set fullLatexCompileBookButton \
                    [button .b4 -padx $buttonPadx -pady $buttonPady \
                    -text "BOOK:  Full LaTeX Compile\nAnd Index" \
					-command fullLatexCompileAndIndexProc -width $buttonWidth -height $buttonHeight \
					-background $bookButtonColor]

grid $rebuildMasterFilesButton   -row 0 -column 1
grid $rebuildReadmeHtmBookButton -row 1 -column 1
grid $fullLatexCompileBookButton -row 2 -column 1

grid $exitButton -row 3 -column 1

outboth "Buttons formed and awaiting press."
hlineboth

#----------------------------------------------------------------------------------------
# End of CP_SCRIPT.TCL
#----------------------------------------------------------------------------------------
