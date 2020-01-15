# $Header: /cvsroot/esrg/sfesrg/esrgpcpj/unittest/readme.txt,v 1.2 2001/07/15 02:59:34 dtashley Exp $

SUBDIRECTORY
   c:\swprojs\unittest

CONTENTS
   This subdirectory is the main subdirectory for the UNITTEST
   program.  The UNITTEST program is a program that is used for
   unit-testing the shared software modules of The Iju Tool Set.

   The UNITTEST program is not distributed with the Iju Tool Set,
   although the source code for the program can be obtained from the
   CVS archives at SourceForge and anyone who wants to rebuild the
   program can do so (although it is hard to image exactly why
   anyone not involved with development of The Iju Tool Set would
   want to do so).  The reason that this program exists is that it 
   was found to be convenient to create a separate program (i.e. a
   MSVC++ project) to combine all unit tests of shared software
   components.  This also gives a convenient way to perform 
   regression testing (just recompile the UNITTEST program and run
   it).

MNEMONIC
   "UNITTEST" is an unabbreviated directory name and the mnemonics
   behind this choice should be clear.

#**************************************************************************
# $Log: readme.txt,v $
# Revision 1.2  2001/07/15 02:59:34  dtashley
# Description of directory contents refined.
#
# Revision 1.1  2001/07/12 05:44:05  dtashley
# Initial checkin.
#
#**************************************************************************
# End of README.TXT.