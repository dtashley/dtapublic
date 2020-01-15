rem $Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/dtaipubs/cron/2006/wvecprob/recomp.bat,v 1.1 2006/12/23 19:06:00 dashley Exp $
latex wvecprob
rem makeindex wvecprob
latex wvecprob
dvips -T 8.5in,11in wvecprob
