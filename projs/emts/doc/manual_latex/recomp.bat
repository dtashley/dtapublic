rem ---------------------------------------------------------------------------
rem Run three times to be sure index entries are correct.
rem ---------------------------------------------------------------------------
latex emts_usr_se_man
makeindex emts_usr_se_man
latex emts_usr_se_man
makeindex emts_usr_se_man
latex emts_usr_se_man
makeindex emts_usr_se_man
rem ---------------------------------------------------------------------------
rem Create print output.
rem ---------------------------------------------------------------------------
dvips -T 8.5in,11in emts_usr_se_man
rem ---------------------------------------------------------------------------
