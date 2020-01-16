rem ---------------------------------------------------------------------------
rem When producing a final document, this batch file should be run at least 
rem three times to resolve all references and index entries.  During
rem development, once may be enough depending on what references and/or
rem index entries have changed.
rem ---------------------------------------------------------------------------
latex emts_usr_se_man
makeindex emts_usr_se_man
dvips -T 8.5in,11in emts_usr_se_man
rem ---------------------------------------------------------------------------
