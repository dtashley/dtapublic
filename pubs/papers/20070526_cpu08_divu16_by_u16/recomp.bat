rem $Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/dtaipubs/cron/2007/cpu08div16by16a/recomp.bat,v 1.1 2007/05/17 03:09:06 dashley Exp $
latex cpu08div16by16a
rem makeindex wvecprob
latex cpu08div16by16a
dvips -T 8.5in,11in cpu08div16by16a
