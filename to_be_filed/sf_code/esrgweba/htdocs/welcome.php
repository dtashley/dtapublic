<?php
//$Header: /cvsroot/esrg/sfesrg/esrgweba/htdocs/welcome.php,v 1.7 2003/04/28 08:53:39 dtashley Exp $
?>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<meta name="ProgId" content="FrontPage.Editor.Document">
<title>Welcome To The ESRG Tool Set</title>
<base target="_self">
<bgsound src="gensounds/carlin_pa/stupid_half.wav" loop="0">
</head>

<body background="bkgnds/bk10.gif">

<p align="center"><img border="0" src="genimages/welcome.gif" width="211" height="164"></p>

<p align="center"><font size="6" face="Arial">To The ESRG Tool Set Home Page!</font></p>
<p align="center"><font face="Arial">(Generously hosted by </font><font size="6" face="Arial"> <A href="http://sourceforge.net"> 
<IMG src="http://sourceforge.net/sflogo.php?group_id=78227" border="0" align="middle" alt="SourceForge Logo"></A></font><font face="Arial">)</font></p>

<hr>

<p align="center">The navigation bar at the left provides an overview of our
open-source endeavors and their associated site content.&nbsp; Please use this
navigation bar to visit the desired pages.</p>
<hr>
<p align="center" style="margin-top: -3; margin-bottom: -1"><font size="1">This
web page is maintained by <a href="mailto:dtashley@users.sourceforge.net">David
T. Ashley</a>, and has been visited 
<?php
/* Under the SourceForge schema, "apache" does not have write permission in
** the directory where the hit counter goes.  So, hit counters must be created
** manually and given write permission to others.  If the necessary file
** does not exist, a hit count of one is assumed.
*/

$hit_count = 1;     /* Will be reassigned if can find the file. */
$last_accessed = 1; /* Need some value if can't open the file.  */
if (file_exists("hit_counter_01.txt"))
   {
   /* From this time forward we don't want to be interrupt by a lost
   ** connection.  Need to check semantics of this.
   */
   ignore_user_abort(1);

   /* Get the mtime on the hit counter.  This will tell us when the
   ** page was last accessed.
   */
   $last_accessed = filemtime("hit_counter_01.txt");

   /* Acquire a presumptive file pointer. */
   $fptr = fopen("hit_counter_01.txt", "a+");
   
   //echo "Success was " . $ftpr . "<br>";

   /* Acquire an exclusive lock on the file.  This may block. */
   flock($fptr, LOCK_EX);

   /* Move to the beginning of the file. */
   fseek($fptr, 0);

   /* Read in the contents of the hit counter file. */
   $hit_count = Fread($fptr, 25);

   /* Increment the hit count. */
   $hit_count++;

   /* Move back to the beginning of the file and truncate the file. */
   fseek($fptr, 0);
   ftruncate($fptr, 0);

   /* Write the updated hit counter to the file. */
   Fputs($fptr, $hit_count);

   /* Flush the data to be sure it is back. */
   fflush($fptr);

   /* Release the lock on the hit counter file. */
   flock($fptr, LOCK_UN);

   /* Close the file. */
   fclose($fptr);
   } 

/* Format the hit counter with commas and all that. */
$hit_count = number_format($hit_count);

/* Dump it out. */
echo " " . $hit_count . " ";
?>
times since it was automatically refreshed 
from <a href="http://www.cvshome.org" target="_blank">CVS</a> archives on
<?php
$welcome_date = date("F j, Y", filemtime("welcome.php"));
$last_accessed_time = date("g:i:s A", $last_accessed);
$last_accessed_zone = date("O", $last_accessed);
$last_accessed_date = date("l, F j, Y", $last_accessed);
echo " " . $welcome_date . ".&nbsp; The most recent previous access to this page was at "  .
     $last_accessed_time . " (GMT" . $last_accessed_zone . ") on " . $last_accessed_date . ".&nbsp; ";
?>
Sound credit:  George Carlin from <i>Parental Advisory</i>.<br>
$Header: /cvsroot/esrg/sfesrg/esrgweba/htdocs/welcome.php,v 1.7 2003/04/28 08:53:39 dtashley Exp $</font></p>
<hr noshade size="5">
</body>

</html>
