<?php
//$Header: /cvsroot/esrg/sfesrg/esrgweba/htdocs/left_nav.php,v 1.14 2003/04/30 08:50:44 dtashley Exp $
//********************************************************************************
//The left navigation pane was done in PHP because when it was HTML, Microsoft
//Front Page would find a new way to mangle it each time it was edited.  With
//the list approach in PHP, the formatting can be changed in one place 
//(in the for() loop) rather than in multiple places.
//********************************************************************************
//
//Outputs the Google search box.
function google_search_box()
{
?>
<!-- Search Google -->
<FORM method=GET action=http://www.google.com/search>
<INPUT TYPE=text name=q size=19 maxlength=255 value="<ENTER> To Search">
<input type=hidden name=sitesearch value="esrg.sourceforge.net">
<br><font size="1"><p style="text-indent: -1; margin-left: 0; margin-top: 2; margin-bottom: -24">This search is powered by</p></font><br>
<a href="http://www.google.com"><IMG SRC="http://www.google.com/logos/Logo_40wht.gif" border=0 ALT=Google width="128" height="53"></a><br>
<font size="1"><p style="text-indent: -1; margin-left: 0; margin-top: -2">There may be up to a 60-90 day delay in site content changes becoming available in searches.</p></font>
</form>
<!-- Search Google -->
<?php
}
function dilbert_icon_and_link()
{
?>
<p><a href="http://www.dilbert.com" target="_blank"><img border="0" src="genimages/link_icon_dilbert_120x90.gif" vspace="0" width="120" height="90"></a></p>
<?php
}
function vc_info()
{
?>
<p style="margin-top: -8; margin-bottom: -1"><font size="1">$RCSfile: left_nav.php,v $<br>
$Date: 2003/04/30 08:50:44 $<br>
$Revision: 1.14 $<br>
$Author: dtashley $</font></p>
<?php
}
?>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
<title>ESRG Tool Set Home Page Left Navigation Pane</title>
<base target="main">
</head>
<body background="bkgnds/bk10.gif">

<font face=arial,sans-serif size=-1>

<?php
//The list below is a list of category headings and subheadings, and the list
//takes the following form ...
//
//Each item to be displayed is four array elments, which are:
//  a)The display level, currently only 0 and 1 are supported.
//  b)The text to be displayed, which might include <a> and <i> markup only.
//  c)At level 0 only, a "W" if the line is a "widow" line, (it has no
//    children at a lower level).  At other levels, this value is ignored.
//  d)An "L" if all the text is a link.  Currently this is not used.
$ta = array(
	    "0",
            "<a href=\"welcome.php\">Welcome Page</a>",
            "W",
            "L",
	    "0",
            "<a href=\"esrgdesc/index.html\">What Is <i>The ESRG</i>, Anyway?</a>",
            "W",
            "L",
	    "0",
            "<a href=\"prod_ovw/overview.htm\">Overview Of Offered Products</a>",
            "W",
            "L",
	    "0",
            "<a href=\"license/license.htm\" target=\"_top\">Product Licenses</a>",
            "W",
            "L",
	    "0",
            "Windows Tool Set",
            "",
            "",
	    "1",
            "<a href=\"win_ts/desc.htm\">Description</a>.",
            "",
            "",
	    "1",
            "<a href=\"win_ts/download.htm\">Download tool set</a>.",
            "",
            "",
	    "1",
            "<a href=\"win_ts/download_source.htm\">Download source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"win_ts/build_from_source.htm\">Build the tool set from source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"win_ts/report_bug.htm\">Report a bug</a>.",
            "",
            "",
	    "1",
            "<a href=\"win_ts/view_cvs.htm\">Browse CVS archives</a>.",
            "",
            "",
	    "1",
            "<a href=\"win_ts/join_mail_list.htm\">Join a mailing list</a>.",
            "",
            "",
	    "1",
            "<a href=\"win_ts/contribute.htm\">Contribute</a>.",
            "",
            "",
	    "",
            "*nix Tool Set",
            "",
            "",
	    "1",
            "<a href=\"nix_ts/desc.htm\">Description</a>.",
            "",
            "",
	    "1",
            "<a href=\"nix_ts/download.htm\">Download tool set</a>.",
            "",
            "",
	    "1",
            "<a href=\"nix_ts/download_source.htm\">Download source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"nix_ts/build_from_source.htm\">Build the tool set from source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"nix_ts/report_bug.htm\">Report a bug</a>.",
            "",
            "",
	    "1",
            "<a href=\"nix_ts/view_cvs.htm\">Browse CVS archives</a>.",
            "",
            "",
	    "1",
            "<a href=\"nix_ts/join_mail_list.htm\">Join a mailing list</a>.",
            "",
            "",
	    "1",
            "<a href=\"nix_ts/contribute.htm\">Contribute</a>.",
            "",
            "",
	    "0",
            "Book",
            "",
            "",
	    "1",
            "<a href=\"bk_prac_guide/desc.htm\">Description</a>.",
            "",
            "",
	    "1",
            "<a href=\"bk_prac_guide/download.htm\">Download the book</a>.",
            "",
            "",
	    "1",
            "<a href=\"bk_prac_guide/download_source.htm\">Download book source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"bk_prac_guide/build_from_source.htm\">Build the book from source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"bk_prac_guide/report_bug.htm\">Report a mistake</a>.",
            "",
            "",
	    "1",
            "<a href=\"bk_prac_guide/view_cvs.htm\">Browse CVS archives</a>.",
            "",
            "",
	    "1",
            "<a href=\"bk_prac_guide/join_mail_list.htm\">Join a mailing list</a>.",
            "",
            "",
	    "1",
            "<a href=\"bk_prac_guide/contribute.htm\">Contribute</a>.",
            "",
            "",
	    "0",
            "Embedded System Libraries",
            "",
            "",
	    "1",
            "<a href=\"es_libs/desc.htm\">Description</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_libs/download.htm\">Download the libraries</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_libs/download_source.htm\">Download library source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_libs/build_from_source.htm\">Build the libraries from source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_libs/report_bug.htm\">Report a bug</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_libs/view_cvs.htm\">Browse CVS archives</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_libs/join_mail_list.htm\">Join a mailing list</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_libs/contribute.htm\">Contribute</a>.",
            "",
            "",
	    "0",
            "Embedded System RTOS's, Kernels, Schedulers, And Integrated Software Components",
            "",
            "",
	    "1",
            "<a href=\"es_rtoss/desc.htm\">Description</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_rtoss/download.htm\">Download the products</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_rtoss/download_source.htm\">Download product source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_rtoss/build_from_source.htm\">Build the products from source code</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_rtoss/report_bug.htm\">Report a bug</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_rtoss/view_cvs.htm\">Browse CVS archives</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_rtoss/join_mail_list.htm\">Join a mailing list</a>.",
            "",
            "",
	    "1",
            "<a href=\"es_rtoss/contribute.htm\">Contribute</a>.",
            "",
            "",
	    "0",
            "PHP Library",
            "",
            "",
	    "1",
            "<a href=\"php_lib/desc.htm\">Description</a>.",
            "",
            "",
	    "1",
            "<a href=\"php_lib/download.htm\">Download the library</a>.",
            "",
            "",
	    "1",
            "<a href=\"php_lib/report_bug.htm\">Report a bug</a>.",
            "",
            "",
	    "1",
            "<a href=\"php_lib/view_cvs.htm\">Browse CVS archives</a>.",
            "",
            "",
	    "1",
            "<a href=\"php_lib/join_mail_list.htm\">Join a mailing list</a>.",
            "",
            "",
	    "1",
            "<a href=\"php_lib/contribute.htm\">Contribute</a>.",
            "",
            "",
	    "0",
            "Site Web Content",
            "",
            "",
	    "1",
            "<a href=\"web_content/desc.htm\">Description</a>.",
            "",
            "",
	    "1",
            "<a href=\"web_content/download.htm\">Download the web content</a>.",
            "",
            "",
	    "1",
            "<a href=\"web_content/report_bug.htm\">Report a bug</a>.",
            "",
            "",
	    "1",
            "<a href=\"web_content/view_cvs.htm\">Browse CVS archives</a>.",
            "",
            "",
	    "1",
            "<a href=\"web_content/join_mail_list.htm\">Join a mailing list</a>.",
            "",
            "",
	    "1",
            "<a href=\"web_content/contribute.htm\">Contribute</a>.",
            "",
            "",
	    "0",
            "Frequently Requested Standalone Windows Utilities",
            "",
            "",
	    "1",
            "<a href=\"winutils/md5sum/index.html\">MD5 calculation utility</a>.",
            "",
            "",
	    "1",
            "<a href=\"winutils/brap/index.html\">Best rational approximation utility</a>.",
            "",
            "",
	    "0",
            "CGI-BIN Number Theory Utilities",
            "",
            "",
	    "1",
            "<a href=\"nth_cgi_utils/desc.htm\">Description</a>.",
            "",
            "",
	    "1",
            "<a href=\"phpcgibin/euclid_gcd.php\">GCD calculator (Euclid's classic algorithm)</a>.",
            "",
            "",
	    "1",
            "<a href=\"phpcgibin/miller_rabin.php\">Miller-Rabin probable primality test</a>.",
            "",
            "",
	    "1",
            "<a href=\"phpcgibin/pfact18digit.php\">Prime factorization of an integer (18 or fewer digits)</a>.",
            "",
            "",
	    "1",
            "<a href=\"nth_cgi_utils/brap.htm\">Best rational approximation calculator (continued fraction algorithm)</a>.",
            "",
            "",
	    "1",
            "<a href=\"nth_cgi_utils/rn_min_d.htm\">Rational number with smallest denominator in an interval calculator (continued fraction algorithm)</a>.",
            "",
            "",
	    "0",
            "Other CGI-BIN Utilities",
            "",
            "",
	    "1",
            "<a href=\"phpcgibin/htpasswd_gen.php\"><i>htpasswd</i>-style password hash generator</a>.",
            "",
            "",
	    "0",
            "<a href=\"howtos/index.html\">Technical Resources And Howtos</a>",
            "W",
            "L",
	    "0",
            "<a href=\"links/index.html\">Embedded Systems Links</a>",
            "W",
            "L",
	    "0",
            "Employment Resources",
            "",
            "",
	    "1",
            "<a href=\"employ_rscs/geninfo.htm\">General information and suggestions</a>.",
            "",
            "",
	    "1",
            "<a href=\"employ_rscs/pprofs.htm\">List of placement professionals and some contributed resources</a>.",
            "",
            "",
	    "0",
            "<a href=\"http://www.sourceforge.net\">SourceForge</a> Project And Site",
            "",
            "",
	    "1",
            "<a href=\"search/index.html\">Search (both site and WWW)</a>.",
            "",
            "",
	    "1",
            "<a href=\"http://sourceforge.net/project/stats/?group_id=78227\" target=\"_top\">Site statistics</a>.",
            "",
            "",
	    "1",
            "<a href=\"http://sourceforge.net/project/showfiles.php?group_id=78227\" target=\"_top\">ESRG downloads</a>.",
            "",
            "",
	    "1",
            "<a href=\"http://cvs.sourceforge.net/cgi-bin/viewcvs.cgi/esrg/\" target=\"_top\">Browse CVS archives</a>.",
            "",
            "",
	    "0",
            "Author Web Pages",
            "",
            "",
	    "1",
            "<a href=\"authindiv/dtashley/index.html\" target=\"_top\">Dave Ashley</a>",
            "",
            "",
	    "0",
            "For Developers And Collaborators",
            "",
            "",
	    "1",
            "<a href=\"devels/index.html\" target=\"_top\">Policies, procedures, checklists, and other information for developers and collaborators</a>.",
            "",
            "",
	    "0",
            "<a href=\"glossary/glossary.htm\">Glossary Of Products, Terms, Etc.</a>",
            "W",
            "L",
	    "0",
            "<a href=\"acknowledgements/index.html\">Acknowledgements</a>",
            "W",
            "L",
           );

//Do our Google search box.
google_search_box();

//Iterate through the table, tossing out HTML.  This should be very self-explanatory.
$limit = count($ta);

for ($i=0; $i<$limit; $i+=4)
   {
     if (($ta[$i] == 0) && ($ta[$i+2] == "W"))
       {
	 echo "<p>";
	 echo "<b>";
	 echo $ta[$i+1];
	 echo "</b>";
	 echo "</p>";
         echo "\n";
       }
     if (($ta[$i] == 0) && ($ta[$i+2] != "W"))
       {
	 echo "<p style=\"margin-bottom: -18\">";
	 echo "<b>";
         echo "<u>";
	 echo $ta[$i+1];
	 echo "</b>";
         echo "</u>";
	 echo "</p>";
         echo "\n";
       }
     elseif ($ta[$i] == 1)
       {
	 echo "<li>";
	 echo "<p style=\"margin-left: -12; margin-bottom: 0\">";
         echo "<font size=\"2\">";
	 echo $ta[$i+1];
	 echo "</font>";
	 echo "</p>";
	 echo "</li>";
         echo "\n";
       }

     //We need to do some voodo to start and end lists.
     //We start a list if the current item is level 0 and the next one is level 1.
     //We end a list on the reverse.
     //Rules may get more complicated in the future, but for now these are OK.
     if (($i+4) >= $limit)
       {
       //We are at last element.
	 if ($ta[$i] == 1)
	   {
   	   echo "</ul>\n";
	   }
       }
     else
       {
	 if (($ta[$i] == 1) && ($ta[$i+4] == 0))
	   {
   	   echo "</ul>\n";
	   }
	 elseif (($ta[$i] == 0) && ($ta[$i+4] == 1))
	   {
   	   echo "<ul>\n";
	   }
       }

   }  //End for()

//Do the Dilbert icon and link.
dilbert_icon_and_link();
//
echo "<hr style=\"margin-top: -12; margin-bottom: -12\">\n";
//
//Do the version control information.
vc_info();
?>
</font>
</body>
</html>
