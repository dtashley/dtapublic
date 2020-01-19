rem ---------------------------------------------------------------------------
rem Run three times to be sure index entries are correct.
rem ---------------------------------------------------------------------------
latex ucbka
makeindex ucbka
latex ucbka
makeindex ucbka
latex ucbka
makeindex ucbka
rem ---------------------------------------------------------------------------
rem Create Postscript output.
rem ---------------------------------------------------------------------------
dvips -T 8.5in,11in ucbka
rem ---------------------------------------------------------------------------
rem Creation of a .PDF will be done manually.
rem ---------------------------------------------------------------------------

