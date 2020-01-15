/* $Header: /cvsroot/esrg/sfesrg/esrgpcpj/gfsw/gfsw.c,v 1.30 2009/11/29 02:16:04 dtashley Exp $ */

#include <windows.h>
#include <commdlg.h>

#include <assert.h>
#include <process.h>
#include <stdio.h>

#include "resource.h"

#include "bstrfunc.h"
#include "build_config.h"
#include "crchashfuncs.h"
#include "esrg_md5.h"
#include "esrg_sha512.h"

//--------------------------------------------------------------------------------
//Copyright 2001 David T. Ashley
//-------------------------------------------------------------------------------------------------
//This source code and any program in which it is compiled/used is provided under the GNU GENERAL
//PUBLIC LICENSE, Version 3, full license text below.
//-------------------------------------------------------------------------------------------------
//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//
//                            Preamble
//
//  The GNU General Public License is a free, copyleft license for
//software and other kinds of works.
//
//  The licenses for most software and other practical works are designed
//to take away your freedom to share and change the works.  By contrast,
//the GNU General Public License is intended to guarantee your freedom to
//share and change all versions of a program--to make sure it remains free
//software for all its users.  We, the Free Software Foundation, use the
//GNU General Public License for most of our software; it applies also to
//any other work released this way by its authors.  You can apply it to
//your programs, too.
//
//  When we speak of free software, we are referring to freedom, not
//price.  Our General Public Licenses are designed to make sure that you
//have the freedom to distribute copies of free software (and charge for
//them if you wish), that you receive source code or can get it if you
//want it, that you can change the software or use pieces of it in new
//free programs, and that you know you can do these things.
//
//  To protect your rights, we need to prevent others from denying you
//these rights or asking you to surrender the rights.  Therefore, you have
//certain responsibilities if you distribute copies of the software, or if
//you modify it: responsibilities to respect the freedom of others.
//
//  For example, if you distribute copies of such a program, whether
//gratis or for a fee, you must pass on to the recipients the same
//freedoms that you received.  You must make sure that they, too, receive
//or can get the source code.  And you must show them these terms so they
//know their rights.
//
//  Developers that use the GNU GPL protect your rights with two steps:
//(1) assert copyright on the software, and (2) offer you this License
//giving you legal permission to copy, distribute and/or modify it.
//
//  For the developers' and authors' protection, the GPL clearly explains
//that there is no warranty for this free software.  For both users' and
//authors' sake, the GPL requires that modified versions be marked as
//changed, so that their problems will not be attributed erroneously to
//authors of previous versions.
//
//  Some devices are designed to deny users access to install or run
//modified versions of the software inside them, although the manufacturer
//can do so.  This is fundamentally incompatible with the aim of
//protecting users' freedom to change the software.  The systematic
//pattern of such abuse occurs in the area of products for individuals to
//use, which is precisely where it is most unacceptable.  Therefore, we
//have designed this version of the GPL to prohibit the practice for those
//products.  If such problems arise substantially in other domains, we
//stand ready to extend this provision to those domains in future versions
//of the GPL, as needed to protect the freedom of users.
//
//  Finally, every program is threatened constantly by software patents.
//States should not allow patents to restrict development and use of
//software on general-purpose computers, but in those that do, we wish to
//avoid the special danger that patents applied to a free program could
//make it effectively proprietary.  To prevent this, the GPL assures that
//patents cannot be used to render the program non-free.
//
//  The precise terms and conditions for copying, distribution and
//modification follow.
//
//                       TERMS AND CONDITIONS
//
//  0. Definitions.
//
//  "This License" refers to version 3 of the GNU General Public License.
//
//  "Copyright" also means copyright-like laws that apply to other kinds of
//works, such as semiconductor masks.
//
//  "The Program" refers to any copyrightable work licensed under this
//License.  Each licensee is addressed as "you".  "Licensees" and
//"recipients" may be individuals or organizations.
//
//  To "modify" a work means to copy from or adapt all or part of the work
//in a fashion requiring copyright permission, other than the making of an
//exact copy.  The resulting work is called a "modified version" of the
//earlier work or a work "based on" the earlier work.
//
//  A "covered work" means either the unmodified Program or a work based
//on the Program.
//
//  To "propagate" a work means to do anything with it that, without
//permission, would make you directly or secondarily liable for
//infringement under applicable copyright law, except executing it on a
//computer or modifying a private copy.  Propagation includes copying,
//distribution (with or without modification), making available to the
//public, and in some countries other activities as well.
//
//  To "convey" a work means any kind of propagation that enables other
//parties to make or receive copies.  Mere interaction with a user through
//a computer network, with no transfer of a copy, is not conveying.
//
//  An interactive user interface displays "Appropriate Legal Notices"
//to the extent that it includes a convenient and prominently visible
//feature that (1) displays an appropriate copyright notice, and (2)
//tells the user that there is no warranty for the work (except to the
//extent that warranties are provided), that licensees may convey the
//work under this License, and how to view a copy of this License.  If
//the interface presents a list of user commands or options, such as a
//menu, a prominent item in the list meets this criterion.
//
//  1. Source Code.
//
//  The "source code" for a work means the preferred form of the work
//for making modifications to it.  "Object code" means any non-source
//form of a work.
//
//  A "Standard Interface" means an interface that either is an official
//standard defined by a recognized standards body, or, in the case of
//interfaces specified for a particular programming language, one that
//is widely used among developers working in that language.
//
//  The "System Libraries" of an executable work include anything, other
//than the work as a whole, that (a) is included in the normal form of
//packaging a Major Component, but which is not part of that Major
//Component, and (b) serves only to enable use of the work with that
//Major Component, or to implement a Standard Interface for which an
//implementation is available to the public in source code form.  A
//"Major Component", in this context, means a major essential component
//(kernel, window system, and so on) of the specific operating system
//(if any) on which the executable work runs, or a compiler used to
//produce the work, or an object code interpreter used to run it.
//
//  The "Corresponding Source" for a work in object code form means all
//the source code needed to generate, install, and (for an executable
//work) run the object code and to modify the work, including scripts to
//control those activities.  However, it does not include the work's
//System Libraries, or general-purpose tools or generally available free
//programs which are used unmodified in performing those activities but
//which are not part of the work.  For example, Corresponding Source
//includes interface definition files associated with source files for
//the work, and the source code for shared libraries and dynamically
//linked subprograms that the work is specifically designed to require,
//such as by intimate data communication or control flow between those
//subprograms and other parts of the work.
//
//  The Corresponding Source need not include anything that users
//can regenerate automatically from other parts of the Corresponding
//Source.
//
//  The Corresponding Source for a work in source code form is that
//same work.
//
//  2. Basic Permissions.
//
//  All rights granted under this License are granted for the term of
//copyright on the Program, and are irrevocable provided the stated
//conditions are met.  This License explicitly affirms your unlimited
//permission to run the unmodified Program.  The output from running a
//covered work is covered by this License only if the output, given its
//content, constitutes a covered work.  This License acknowledges your
//rights of fair use or other equivalent, as provided by copyright law.
//
//  You may make, run and propagate covered works that you do not
//convey, without conditions so long as your license otherwise remains
//in force.  You may convey covered works to others for the sole purpose
//of having them make modifications exclusively for you, or provide you
//with facilities for running those works, provided that you comply with
//the terms of this License in conveying all material for which you do
//not control copyright.  Those thus making or running the covered works
//for you must do so exclusively on your behalf, under your direction
//and control, on terms that prohibit them from making any copies of
//your copyrighted material outside their relationship with you.
//
//  Conveying under any other circumstances is permitted solely under
//the conditions stated below.  Sublicensing is not allowed; section 10
//makes it unnecessary.
//
//  3. Protecting Users' Legal Rights From Anti-Circumvention Law.
//
//  No covered work shall be deemed part of an effective technological
//measure under any applicable law fulfilling obligations under article
//11 of the WIPO copyright treaty adopted on 20 December 1996, or
//similar laws prohibiting or restricting circumvention of such
//measures.
//
//  When you convey a covered work, you waive any legal power to forbid
//circumvention of technological measures to the extent such circumvention
//is effected by exercising rights under this License with respect to
//the covered work, and you disclaim any intention to limit operation or
//modification of the work as a means of enforcing, against the work's
//users, your or third parties' legal rights to forbid circumvention of
//technological measures.
//
//  4. Conveying Verbatim Copies.
//
//  You may convey verbatim copies of the Program's source code as you
//receive it, in any medium, provided that you conspicuously and
//appropriately publish on each copy an appropriate copyright notice;
//keep intact all notices stating that this License and any
//non-permissive terms added in accord with section 7 apply to the code;
//keep intact all notices of the absence of any warranty; and give all
//recipients a copy of this License along with the Program.
//
//  You may charge any price or no price for each copy that you convey,
//and you may offer support or warranty protection for a fee.
//
//  5. Conveying Modified Source Versions.
//
//  You may convey a work based on the Program, or the modifications to
//produce it from the Program, in the form of source code under the
//terms of section 4, provided that you also meet all of these conditions:
//
//    a) The work must carry prominent notices stating that you modified
//    it, and giving a relevant date.
//
//    b) The work must carry prominent notices stating that it is
//    released under this License and any conditions added under section
//    7.  This requirement modifies the requirement in section 4 to
//    "keep intact all notices".
//
//    c) You must license the entire work, as a whole, under this
//    License to anyone who comes into possession of a copy.  This
//    License will therefore apply, along with any applicable section 7
//    additional terms, to the whole of the work, and all its parts,
//    regardless of how they are packaged.  This License gives no
//    permission to license the work in any other way, but it does not
//    invalidate such permission if you have separately received it.
//
//    d) If the work has interactive user interfaces, each must display
//    Appropriate Legal Notices; however, if the Program has interactive
//    interfaces that do not display Appropriate Legal Notices, your
//    work need not make them do so.
//
//  A compilation of a covered work with other separate and independent
//works, which are not by their nature extensions of the covered work,
//and which are not combined with it such as to form a larger program,
//in or on a volume of a storage or distribution medium, is called an
//"aggregate" if the compilation and its resulting copyright are not
//used to limit the access or legal rights of the compilation's users
//beyond what the individual works permit.  Inclusion of a covered work
//in an aggregate does not cause this License to apply to the other
//parts of the aggregate.
//
//  6. Conveying Non-Source Forms.
//
//  You may convey a covered work in object code form under the terms
//of sections 4 and 5, provided that you also convey the
//machine-readable Corresponding Source under the terms of this License,
//in one of these ways:
//
//    a) Convey the object code in, or embodied in, a physical product
//    (including a physical distribution medium), accompanied by the
//    Corresponding Source fixed on a durable physical medium
//    customarily used for software interchange.
//
//    b) Convey the object code in, or embodied in, a physical product
//    (including a physical distribution medium), accompanied by a
//    written offer, valid for at least three years and valid for as
//    long as you offer spare parts or customer support for that product
//    model, to give anyone who possesses the object code either (1) a
//    copy of the Corresponding Source for all the software in the
//    product that is covered by this License, on a durable physical
//    medium customarily used for software interchange, for a price no
//    more than your reasonable cost of physically performing this
//    conveying of source, or (2) access to copy the
//    Corresponding Source from a network server at no charge.
//
//    c) Convey individual copies of the object code with a copy of the
//    written offer to provide the Corresponding Source.  This
//    alternative is allowed only occasionally and noncommercially, and
//    only if you received the object code with such an offer, in accord
//    with subsection 6b.
//
//    d) Convey the object code by offering access from a designated
//    place (gratis or for a charge), and offer equivalent access to the
//    Corresponding Source in the same way through the same place at no
//    further charge.  You need not require recipients to copy the
//    Corresponding Source along with the object code.  If the place to
//    copy the object code is a network server, the Corresponding Source
//    may be on a different server (operated by you or a third party)
//    that supports equivalent copying facilities, provided you maintain
//    clear directions next to the object code saying where to find the
//    Corresponding Source.  Regardless of what server hosts the
//    Corresponding Source, you remain obligated to ensure that it is
//    available for as long as needed to satisfy these requirements.
//
//    e) Convey the object code using peer-to-peer transmission, provided
//    you inform other peers where the object code and Corresponding
//    Source of the work are being offered to the general public at no
//    charge under subsection 6d.
//
//  A separable portion of the object code, whose source code is excluded
//from the Corresponding Source as a System Library, need not be
//included in conveying the object code work.
//
//  A "User Product" is either (1) a "consumer product", which means any
//tangible personal property which is normally used for personal, family,
//or household purposes, or (2) anything designed or sold for incorporation
//into a dwelling.  In determining whether a product is a consumer product,
//doubtful cases shall be resolved in favor of coverage.  For a particular
//product received by a particular user, "normally used" refers to a
//typical or common use of that class of product, regardless of the status
//of the particular user or of the way in which the particular user
//actually uses, or expects or is expected to use, the product.  A product
//is a consumer product regardless of whether the product has substantial
//commercial, industrial or non-consumer uses, unless such uses represent
//the only significant mode of use of the product.
//
//  "Installation Information" for a User Product means any methods,
//procedures, authorization keys, or other information required to install
//and execute modified versions of a covered work in that User Product from
//a modified version of its Corresponding Source.  The information must
//suffice to ensure that the continued functioning of the modified object
//code is in no case prevented or interfered with solely because
//modification has been made.
//
//  If you convey an object code work under this section in, or with, or
//specifically for use in, a User Product, and the conveying occurs as
//part of a transaction in which the right of possession and use of the
//User Product is transferred to the recipient in perpetuity or for a
//fixed term (regardless of how the transaction is characterized), the
//Corresponding Source conveyed under this section must be accompanied
//by the Installation Information.  But this requirement does not apply
//if neither you nor any third party retains the ability to install
//modified object code on the User Product (for example, the work has
//been installed in ROM).
//
//  The requirement to provide Installation Information does not include a
//requirement to continue to provide support service, warranty, or updates
//for a work that has been modified or installed by the recipient, or for
//the User Product in which it has been modified or installed.  Access to a
//network may be denied when the modification itself materially and
//adversely affects the operation of the network or violates the rules and
//protocols for communication across the network.
//
//  Corresponding Source conveyed, and Installation Information provided,
//in accord with this section must be in a format that is publicly
//documented (and with an implementation available to the public in
//source code form), and must require no special password or key for
//unpacking, reading or copying.
//
//  7. Additional Terms.
//
//  "Additional permissions" are terms that supplement the terms of this
//License by making exceptions from one or more of its conditions.
//Additional permissions that are applicable to the entire Program shall
//be treated as though they were included in this License, to the extent
//that they are valid under applicable law.  If additional permissions
//apply only to part of the Program, that part may be used separately
//under those permissions, but the entire Program remains governed by
//this License without regard to the additional permissions.
//
//  When you convey a copy of a covered work, you may at your option
//remove any additional permissions from that copy, or from any part of
//it.  (Additional permissions may be written to require their own
//removal in certain cases when you modify the work.)  You may place
//additional permissions on material, added by you to a covered work,
//for which you have or can give appropriate copyright permission.
//
//  Notwithstanding any other provision of this License, for material you
//add to a covered work, you may (if authorized by the copyright holders of
//that material) supplement the terms of this License with terms:
//
//    a) Disclaiming warranty or limiting liability differently from the
//    terms of sections 15 and 16 of this License; or
//
//    b) Requiring preservation of specified reasonable legal notices or
//    author attributions in that material or in the Appropriate Legal
//    Notices displayed by works containing it; or
//
//    c) Prohibiting misrepresentation of the origin of that material, or
//    requiring that modified versions of such material be marked in
//    reasonable ways as different from the original version; or
//
//    d) Limiting the use for publicity purposes of names of licensors or
//    authors of the material; or
//
//    e) Declining to grant rights under trademark law for use of some
//    trade names, trademarks, or service marks; or
//
//    f) Requiring indemnification of licensors and authors of that
//    material by anyone who conveys the material (or modified versions of
//    it) with contractual assumptions of liability to the recipient, for
//    any liability that these contractual assumptions directly impose on
//    those licensors and authors.
//
//  All other non-permissive additional terms are considered "further
//restrictions" within the meaning of section 10.  If the Program as you
//received it, or any part of it, contains a notice stating that it is
//governed by this License along with a term that is a further
//restriction, you may remove that term.  If a license document contains
//a further restriction but permits relicensing or conveying under this
//License, you may add to a covered work material governed by the terms
//of that license document, provided that the further restriction does
//not survive such relicensing or conveying.
//
//  If you add terms to a covered work in accord with this section, you
//must place, in the relevant source files, a statement of the
//additional terms that apply to those files, or a notice indicating
//where to find the applicable terms.
//
//  Additional terms, permissive or non-permissive, may be stated in the
//form of a separately written license, or stated as exceptions;
//the above requirements apply either way.
//
//  8. Termination.
//
//  You may not propagate or modify a covered work except as expressly
//provided under this License.  Any attempt otherwise to propagate or
//modify it is void, and will automatically terminate your rights under
//this License (including any patent licenses granted under the third
//paragraph of section 11).
//
//  However, if you cease all violation of this License, then your
//license from a particular copyright holder is reinstated (a)
//provisionally, unless and until the copyright holder explicitly and
//finally terminates your license, and (b) permanently, if the copyright
//holder fails to notify you of the violation by some reasonable means
//prior to 60 days after the cessation.
//
//  Moreover, your license from a particular copyright holder is
//reinstated permanently if the copyright holder notifies you of the
//violation by some reasonable means, this is the first time you have
//received notice of violation of this License (for any work) from that
//copyright holder, and you cure the violation prior to 30 days after
//your receipt of the notice.
//
//  Termination of your rights under this section does not terminate the
//licenses of parties who have received copies or rights from you under
//this License.  If your rights have been terminated and not permanently
//reinstated, you do not qualify to receive new licenses for the same
//material under section 10.
//
//  9. Acceptance Not Required for Having Copies.
//
//  You are not required to accept this License in order to receive or
//run a copy of the Program.  Ancillary propagation of a covered work
//occurring solely as a consequence of using peer-to-peer transmission
//to receive a copy likewise does not require acceptance.  However,
//nothing other than this License grants you permission to propagate or
//modify any covered work.  These actions infringe copyright if you do
//not accept this License.  Therefore, by modifying or propagating a
//covered work, you indicate your acceptance of this License to do so.
//
//  10. Automatic Licensing of Downstream Recipients.
//
//  Each time you convey a covered work, the recipient automatically
//receives a license from the original licensors, to run, modify and
//propagate that work, subject to this License.  You are not responsible
//for enforcing compliance by third parties with this License.
//
//  An "entity transaction" is a transaction transferring control of an
//organization, or substantially all assets of one, or subdividing an
//organization, or merging organizations.  If propagation of a covered
//work results from an entity transaction, each party to that
//transaction who receives a copy of the work also receives whatever
//licenses to the work the party's predecessor in interest had or could
//give under the previous paragraph, plus a right to possession of the
//Corresponding Source of the work from the predecessor in interest, if
//the predecessor has it or can get it with reasonable efforts.
//
//  You may not impose any further restrictions on the exercise of the
//rights granted or affirmed under this License.  For example, you may
//not impose a license fee, royalty, or other charge for exercise of
//rights granted under this License, and you may not initiate litigation
//(including a cross-claim or counterclaim in a lawsuit) alleging that
//any patent claim is infringed by making, using, selling, offering for
//sale, or importing the Program or any portion of it.
//
//  11. Patents.
//
//  A "contributor" is a copyright holder who authorizes use under this
//License of the Program or a work on which the Program is based.  The
//work thus licensed is called the contributor's "contributor version".
//
//  A contributor's "essential patent claims" are all patent claims
//owned or controlled by the contributor, whether already acquired or
//hereafter acquired, that would be infringed by some manner, permitted
//by this License, of making, using, or selling its contributor version,
//but do not include claims that would be infringed only as a
//consequence of further modification of the contributor version.  For
//purposes of this definition, "control" includes the right to grant
//patent sublicenses in a manner consistent with the requirements of
//this License.
//
//  Each contributor grants you a non-exclusive, worldwide, royalty-free
//patent license under the contributor's essential patent claims, to
//make, use, sell, offer for sale, import and otherwise run, modify and
//propagate the contents of its contributor version.
//
//  In the following three paragraphs, a "patent license" is any express
//agreement or commitment, however denominated, not to enforce a patent
//(such as an express permission to practice a patent or covenant not to
//sue for patent infringement).  To "grant" such a patent license to a
//party means to make such an agreement or commitment not to enforce a
//patent against the party.
//
//  If you convey a covered work, knowingly relying on a patent license,
//and the Corresponding Source of the work is not available for anyone
//to copy, free of charge and under the terms of this License, through a
//publicly available network server or other readily accessible means,
//then you must either (1) cause the Corresponding Source to be so
//available, or (2) arrange to deprive yourself of the benefit of the
//patent license for this particular work, or (3) arrange, in a manner
//consistent with the requirements of this License, to extend the patent
//license to downstream recipients.  "Knowingly relying" means you have
//actual knowledge that, but for the patent license, your conveying the
//covered work in a country, or your recipient's use of the covered work
//in a country, would infringe one or more identifiable patents in that
//country that you have reason to believe are valid.
//
//  If, pursuant to or in connection with a single transaction or
//arrangement, you convey, or propagate by procuring conveyance of, a
//covered work, and grant a patent license to some of the parties
//receiving the covered work authorizing them to use, propagate, modify
//or convey a specific copy of the covered work, then the patent license
//you grant is automatically extended to all recipients of the covered
//work and works based on it.
//
//  A patent license is "discriminatory" if it does not include within
//the scope of its coverage, prohibits the exercise of, or is
//conditioned on the non-exercise of one or more of the rights that are
//specifically granted under this License.  You may not convey a covered
//work if you are a party to an arrangement with a third party that is
//in the business of distributing software, under which you make payment
//to the third party based on the extent of your activity of conveying
//the work, and under which the third party grants, to any of the
//parties who would receive the covered work from you, a discriminatory
//patent license (a) in connection with copies of the covered work
//conveyed by you (or copies made from those copies), or (b) primarily
//for and in connection with specific products or compilations that
//contain the covered work, unless you entered into that arrangement,
//or that patent license was granted, prior to 28 March 2007.
//
//  Nothing in this License shall be construed as excluding or limiting
//any implied license or other defenses to infringement that may
//otherwise be available to you under applicable patent law.
//
//  12. No Surrender of Others' Freedom.
//
//  If conditions are imposed on you (whether by court order, agreement or
//otherwise) that contradict the conditions of this License, they do not
//excuse you from the conditions of this License.  If you cannot convey a
//covered work so as to satisfy simultaneously your obligations under this
//License and any other pertinent obligations, then as a consequence you may
//not convey it at all.  For example, if you agree to terms that obligate you
//to collect a royalty for further conveying from those to whom you convey
//the Program, the only way you could satisfy both those terms and this
//License would be to refrain entirely from conveying the Program.
//
//  13. Use with the GNU Affero General Public License.
//
//  Notwithstanding any other provision of this License, you have
//permission to link or combine any covered work with a work licensed
//under version 3 of the GNU Affero General Public License into a single
//combined work, and to convey the resulting work.  The terms of this
//License will continue to apply to the part which is the covered work,
//but the special requirements of the GNU Affero General Public License,
//section 13, concerning interaction through a network will apply to the
//combination as such.
//
//  14. Revised Versions of this License.
//
//  The Free Software Foundation may publish revised and/or new versions of
//the GNU General Public License from time to time.  Such new versions will
//be similar in spirit to the present version, but may differ in detail to
//address new problems or concerns.
//
//  Each version is given a distinguishing version number.  If the
//Program specifies that a certain numbered version of the GNU General
//Public License "or any later version" applies to it, you have the
//option of following the terms and conditions either of that numbered
//version or of any later version published by the Free Software
//Foundation.  If the Program does not specify a version number of the
//GNU General Public License, you may choose any version ever published
//by the Free Software Foundation.
//
//  If the Program specifies that a proxy can decide which future
//versions of the GNU General Public License can be used, that proxy's
//public statement of acceptance of a version permanently authorizes you
//to choose that version for the Program.
//
//  Later license versions may give you additional or different
//permissions.  However, no additional obligations are imposed on any
//author or copyright holder as a result of your choosing to follow a
//later version.
//
//  15. Disclaimer of Warranty.
//
//  THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
//APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
//HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY
//OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,
//THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM
//IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF
//ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
//
//  16. Limitation of Liability.
//
//  IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
//WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS
//THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY
//GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE
//USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF
//DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD
//PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS),
//EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF
//SUCH DAMAGES.
//
//  17. Interpretation of Sections 15 and 16.
//
//  If the disclaimer of warranty and limitation of liability provided
//above cannot be given local legal effect according to their terms,
//reviewing courts shall apply local law that most closely approximates
//an absolute waiver of all civil liability in connection with the
//Program, unless a warranty or assumption of liability accompanies a
//copy of the Program in return for a fee.
//
//                     END OF TERMS AND CONDITIONS
//
//            How to Apply These Terms to Your New Programs
//
//  If you develop a new program, and you want it to be of the greatest
//possible use to the public, the best way to achieve this is to make it
//free software which everyone can redistribute and change under these terms.
//
//  To do so, attach the following notices to the program.  It is safest
//to attach them to the start of each source file to most effectively
//state the exclusion of warranty; and each file should have at least
//the "copyright" line and a pointer to where the full notice is found.
//
//    <one line to give the program's name and a brief idea of what it does.>
//    Copyright (C) <year>  <name of author>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//Also add information on how to contact you by electronic and paper mail.
//
//  If the program does terminal interaction, make it output a short
//notice like this when it starts in an interactive mode:
//
//    <program>  Copyright (C) <year>  <name of author>
//    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
//    This is free software, and you are welcome to redistribute it
//    under certain conditions; type `show c' for details.
//
//The hypothetical commands `show w' and `show c' should show the appropriate
//parts of the General Public License.  Of course, your program's commands
//might be different; for a GUI interface, you would use an "about box".
//
//  You should also get your employer (if you work as a programmer) or school,
//if any, to sign a "copyright disclaimer" for the program, if necessary.
//For more information on this, and how to apply and follow the GNU GPL, see
//<http://www.gnu.org/licenses/>.
//
//  The GNU General Public License does not permit incorporating your program
//into proprietary programs.  If your program is a subroutine library, you
//may consider it more useful to permit linking proprietary applications with
//the library.  If this is what you want to do, use the GNU Lesser General
//Public License instead of this License.  But first, please read
//<http://www.gnu.org/philosophy/why-not-lgpl.html>.
//-------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
/*
KNOWN DEFECTS
  a)When window has the focus, edit control does not get page 
    ups and downs and arrows.  This means one cannot really use the widget
    without the mouse.  Need to redirect these keystrokes to the 
    edit control.

  b)The OPEN dialog box does not remember previous paths.  I believe this
    is an option I can set with a little storage--need to investigate.
    In any case, very annoying when each time get thrown back into a different
    directory than where I last opened files.

  c)Does not correctly handle file sharing (Dan Parks, Dave Ashley).  
    For example, if one tries to signature a file which is currently 
    open in a word processor, it won't do it.  Need to get sharing 
    behavior right.

SUGGESTIONS FOR FUTURE ENHANCEMENT:

  a)Should sort files before beginning the signaturing (the drag'n'drop
    interface delivers them in an unpredictable order).

  b)Should accomodate more than 200 files (Cory Pratt).  (Limiting factor
    at present time is size of edit window display buffer.)

  c)Should include a SAVE AS option (Raul Selgado).

  d)Should include a print option (Dave Ashley).
*/


#define GFSW_MAXFILES (200)
   //Maximum number of files that will be processed and displayed.
   //Limited to avoid filling up the edit control's buffer.
   
#define GFSW_DISPBUFLEN (55000)
   //The point at which we say the edit control buffer has too
   //many characters in it.

#define GFSW_FILE_READ_BUF_SIZE (0x10000)
   //The number of bytes for each read buffer.  It is difficult to know
   //how to size this value.  On one hand, larger is better, as it 
   //enables the disk to operate in blocks.  On the other hand, too 
   //large is probably not a good idea, as it will take a lot of
   //time to fill the buffer.  Suspect that 16K-64K is about the 
   //optimum, but may go larger, anyway.

static char GFSW_dialog_file_open_buffer[15000];
   //Buffer from the "open files" dialog box, for it to store results
   //in.

static char GFSW_dispbuf[GFSW_DISPBUFLEN+1];
   //The buffer which holds the contents of the edit control (the main control, the
   //text box).  This is a mirror buffer, probably not a very efficient way of doing
   //things.

static int GFSW_use_sound = 1;
   //Remembers the state of the "use sound" option.  Default is YES.

static int GFSW_always_on_top = 1;
   //Remembers whether the main window should always be on top.
   //This can be annoying in some applications, so it can be turned off.

#define WM_USER_EV_CHILD_THREAD_PROGRESS  (WM_USER + 1)
   //The child thread has progress to report (updated information that
   //can be used by the parent).

#define WM_USER_EV_CHILD_THREAD_ENDING    (WM_USER + 2)
   //The child thread is reporting that it is ending.  After this event is
   //posted for the parent, there may be some delay until the thread is actually
   //terminated, so additional OS interaction is required to know the thread
   //is actually dead.

static char GFSW_szAppName[] = "FileHash";
   //The application name.

static WNDPROC GFSW_old_win_edit_handler = NULL;
   //The old edit control handler.  This is used to remember the function pointer,
   //in order to subclass the behavior, because we must catch the drop files event.

static volatile int GFSW_thread_abort_request = 0;
   //This is set TRUE by the main thread if the child thread
   //should abort.  This means the application will terminate
   //(this is the only reason for setting this flag).  This 
   //variable is set by the main thread and read by the
   //child thread.

static DWORD GFSW_parent_thread_id = 0;
   //The thread ID of the parent obtained using the 
   //GetCurrentThreadId() call.  The child needs to know this
   //in order to post a message.

static HWND GFSW_parent_thread_main_window_handle = 0;
   //Window handle of main window.

static int GFSW_child_thread_is_active = 0;
   //Set TRUE when the child thread is kicked off.  Set
   //FALSE when a message from the child thread is received
   //indicating that the thread has terminated and when the
   //thread is confirmed dead.  This variable is used only
   //by the main thread.

static HANDLE GFSW_child_handle = 0;
   //The handle of the child process.  This is only valid
   //if a thread is active.  This variable is used only
   //by the main thread to check on status.

static unsigned char GFSW_file_read_buf[GFSW_FILE_READ_BUF_SIZE];
   //File read buffer.

struct GFSW_FileInfoStructPerFile
   {
   volatile char fpath[MAX_PATH + 1];
      //The full path to the file, which should be recognized by the operating system.
      //If this string is empty, it is a signal that no file is in this slot.
   volatile int  is_directory_valid;
      //TRUE if the is_directory flag is assigned by the child process and so the 
      //parent can rely on it.
   volatile int  is_directory_error;
      //TRUE if the child process could not obtain directory information.
   volatile int  is_directory;
      //TRUE if the file is actually a directory.  This means it cannot be processed.
   volatile int  file_size_valid;
      //TRUE if file size has been assigned by child (or an attempt to assign it was made).
   volatile int  file_size_error;
      //There was an error in the attempt to obtain file size.
   volatile unsigned __int64 file_size;
      //The number of bytes in the file.
   volatile int  crc32_valid;
      //TRUE if the CRC32 has been assigned, or an attempt was made to assign it.  This
      //means the child has filled in the string.
   volatile char crc32[100];
      //A string representation of the CRC-32, or else an error message from the child.
   volatile int  md5_valid;
      //TRUE if the md5 is valid or an attempt was made.
   volatile char md5[100];
      //A string representation of the MD5 or else an error message from the child.
   volatile int  sha512_valid;
      //TRUE if the SHA512 is valid or an attempt was made.
   volatile char sha512[200];
      //A string representation of the SHA512 or else an error message from the child.
   };

struct GFSW_FileInfoStruct
   {
   volatile struct GFSW_FileInfoStructPerFile file_info[GFSW_MAXFILES];
   volatile int terminated_normally;
   volatile int aborted;
   };


volatile struct GFSW_FileInfoStruct GFSW_file_info;
   //This is the major structure that holds file information.  Here are the three
   //roles it fills:
   //
   //   a)The parent thread fills in this information in preparation for starting
   //     up the child thread.
   //
   //   b)The child thread fills in the information (file size, CRC, MD5) as it
   //     goes down this list, and notifies the parent thread with an event,
   //     which causes the updating of displayed information.
   //
   //   c)After the child thread is absolutely complete, another event is send
   //     to indicate this.


//Function prototypes, to be sure no strange accidents.
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow);
LRESULT CALLBACK GFSW_ReplacementEditProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
static unsigned __stdcall GFSW_ChildThreadFunc(void *pArguments);
static void GFSW_ChildThreadHardSyncStop(void);
static void GFSW_ChildThreadStart(void);
static void GFSW_MakeGenericSound(void);



//Main function for Windows.
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
   {
   HWND         hwnd ;
   HMENU        hmenu;
   MSG          msg ;
   WNDCLASS     wndclass ;

   //Store our current parent thread ID.  The child process will need
   //to know this to post a message.  This is expected to be
   //invariant for the life of the program.
   GFSW_parent_thread_id = GetCurrentThreadId();

   //Zero out the file information block.
   memset((char *)&GFSW_file_info, 0, sizeof(GFSW_file_info));

   wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
   wndclass.lpfnWndProc   = WndProc ;
   wndclass.cbClsExtra    = 0 ;
   wndclass.cbWndExtra    = 0 ;
   wndclass.hInstance     = hInstance ;
   wndclass.hIcon         = LoadIcon (hInstance, MAKEINTRESOURCE(IDI_ICON)) ;
   wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
   wndclass.hbrBackground = (HBRUSH) (COLOR_BTNFACE+1) ;
   wndclass.lpszMenuName  = NULL ;
   wndclass.lpszClassName = GFSW_szAppName ;

   if (!RegisterClass (&wndclass))
      {
      MessageBox (NULL, 
                 TEXT ("Error code from RegisterClass() Win32 API function.    \nMost probable cause is incompatible operating system."), 
                 GFSW_szAppName, 
                 MB_ICONERROR) ;
      return 0 ;
      }
     
   //We need to do some voodoo to figure out how large to make the main window.
   //The feeling is that the window should be as small as possible to display the
   //results from an individual file (the most common application), and if the user
   //wants it bigger s/he can resize it.  Four lines are required (file name, file 
   //size, file CRC-32, and file MD5), so that needs to be the height.  A file
   //MD5 is 128 bits = 32 characters.  In addition, there is the constraint that we
   //cannot go beyond the width and height of a screen.  The guess below is quite
   //crude, assuming that the edit box has a larger font, etc.
   {
   int initial_width = 0;
   int initial_height = 0;

   //Get a crude measure of how big text is.
   initial_width =  LOWORD(GetDialogBaseUnits());
   initial_height = HIWORD(GetDialogBaseUnits());

   //Dope it up linearly.
   initial_width  = (initial_width * 1500)/10;
   initial_height = (initial_height * 150)/10; 

   {
   int temp;

   //Be sure nothing is bigger than 2/3 screen dimensions.
   temp = (GetSystemMetrics(SM_CXFULLSCREEN) * 2) / 3;
   if (initial_width > temp)
      initial_width = temp;
   temp = (GetSystemMetrics(SM_CYFULLSCREEN) * 2) / 3;
   if (initial_height > temp)
      initial_height = temp;
   }

   //Load up the menu resources.  I have verified in documentation that this will be destroyed
   //automatically.
   hmenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_GFSW));

   //Create the window.  The "Ex" call is used to make it a topmost window.
   hwnd = CreateWindowEx (
                       WS_EX_TOPMOST,
                       GFSW_szAppName,             // window class name
                       TEXT ("FileHash v0.1"),     // window caption
                       WS_OVERLAPPEDWINDOW,        // window style
                       CW_USEDEFAULT,              // initial x position
                       CW_USEDEFAULT,              // initial y position
                       initial_width,              // initial x size
                       initial_height,             // initial y size
                       NULL,                       // parent window handle
                       hmenu,                      // window menu handle
                       hInstance,                  // program instance handle
                       NULL) ;                     // creation parameters
   }
     
   
   GFSW_parent_thread_main_window_handle = hwnd;

   //This is standard code from Petzold's book.  Don't know _exactly_ what it does, but
   //every Windows program seems to have it.
   ShowWindow (hwnd, iCmdShow) ;
   UpdateWindow (hwnd) ;
     
   while (GetMessage (&msg, NULL, 0, 0))
      {
      TranslateMessage (&msg) ;
      DispatchMessage (&msg) ;
      }

   return msg.wParam ;
   }


//This is the subclass WndProc.   This had to be done to allow the edit 
//control to catch the WM_DROPFILES event.
LRESULT CALLBACK GFSW_ReplacementEditProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
   {
   static int iDeltaPerLine = 120, iAccumDelta = 0;
      //These are for mouse wheel logic.  It may happen in the future that more
      //precise mice without notches are introduced.

   //We need to watch for the drop target notification message, and take action 
   //in that case.
   switch(message)
      {
      case WM_DROPFILES:
         {
         int iFiles;
         int i;
         HDROP hDropInfo = (HANDLE)wParam;

         //Do a hard sync stop on the child thread.  This should not take
         //very long.  A new drag'n'drop event will just cause restart
         //with the new set of files.
         GFSW_ChildThreadHardSyncStop();

         //Zero out the file information area and the text buffer mirror.
         memset((char *)&GFSW_file_info, 0, sizeof(GFSW_file_info));
         GFSW_dispbuf[0] = 0;

         // Get the number of files and folders that were dropped.
         iFiles = DragQueryFile (hDropInfo, (DWORD)(-1), (LPSTR)NULL, 0);

         //Copy the paths to the right buffer area.
         for (i=0; (i<iFiles) && (i<GFSW_MAXFILES); i++)
            {
            DragQueryFile (hDropInfo, i, (LPSTR)(GFSW_file_info.file_info[i].fpath), MAX_PATH);
            }

         //Start up the child thread.
         GFSW_ChildThreadStart();

         break;
         }
      case WM_MOUSEWHEEL:
         {
         iAccumDelta += (short) HIWORD (wParam);

         while (iAccumDelta >= iDeltaPerLine)
            {
            SendMessage(hwnd, WM_VSCROLL, SB_PAGEUP, 0);
            iAccumDelta -= iDeltaPerLine;
            //iAccumDelta = 0;
            }

         while (iAccumDelta <= -iDeltaPerLine)
            {
            SendMessage(hwnd, WM_VSCROLL, SB_PAGEDOWN, 0);
            iAccumDelta += iDeltaPerLine;
            //iAccumDelta = 0;
            }

         break;
         }
      }

   //Call the old Window procedure.
   return (CallWindowProc(GFSW_old_win_edit_handler, hwnd, message, wParam, lParam));
   }


//Stages the display buffer in preparation for outputting it out
//to the edit child window.  This function generally interacts
//with the file information data structure even while the
//child thread is running.  This is OK, as race conditions are
//covered.  Essentially, as the child thread proceeds, it updates
//data then afterwards flags it as valid.  This function
//never proceeds into invalid data.
static void GFSW_StageDisplayBuffer(void)
   {
   int dispbufidx;
   int nfiles;
   int len;
   int i;
   char buf[2*MAX_PATH+200];

   //Count the number of files queued, and put that in the buffer.
   dispbufidx = 0;
   nfiles=0;
   for (i=0; i<GFSW_MAXFILES; i++)
      {
      if (GFSW_file_info.file_info[i].fpath[0])
         {
         nfiles++;
         }
      else
         {
         break;
         }
      }
   sprintf_s(buf, sizeof(buf), "Files to signature:  %d.\x0d\x0a", nfiles);
   len = strlen(buf);
   if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
      {
      strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf) - dispbufidx,buf);
      dispbufidx += len;
      }

   //Loop through and output the information for each file.
   for (i=0; i<GFSW_MAXFILES; i++)
      {
      if ((GFSW_file_info.file_info[i].fpath[0]) && (GFSW_file_info.file_info[i].is_directory_valid))
         {
         sprintf_s(buf, sizeof(buf), "--------------------\x0d\x0a");
         len = strlen(buf);
         if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
            {
            strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
            dispbufidx += len;
            }

         sprintf_s(buf, sizeof(buf), "[%03d/%03d] %s\x0d\x0a", i+1, nfiles, GFSW_file_info.file_info[i].fpath);
         len = strlen(buf);
         if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
            {
            strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
            dispbufidx += len;
            }

         //If the file is actually a directory or there was an error, we can't
         //do further processing on it.
         if (GFSW_file_info.file_info[i].is_directory_error)
            {
            sprintf_s(buf, sizeof(buf), "\tError obtaining file attributes--cannot process this file.\x0d\x0a");
            len = strlen(buf);
            if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
               {
               strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
               dispbufidx += len;
               }
            }
         else if (GFSW_file_info.file_info[i].is_directory)
            {
            sprintf_s(buf, sizeof(buf), "\tThis item is a directory and will not be signatured.\x0d\x0a");
            len = strlen(buf);
            if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
               {
               strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
               dispbufidx += len;
               }
            }
         else
            {
            //This is not a directory.  We can print the rest of the 
            //information.
            //
            //First, the file size.
            if (GFSW_file_info.file_info[i].file_size_valid)
               {
               char buf2[100];

               buf2[0] = 0;  //Just in case conversion doesn't go right.
               sprintf_s(buf2, sizeof(buf2), "%I64u", GFSW_file_info.file_info[i].file_size);
               BSTRFUNC_commanate(buf2);
               sprintf_s(buf, sizeof(buf), "\tSize:\t%s\x0d\x0a", buf2);

               len = strlen(buf);
               if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
                  {
                  strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
                  dispbufidx += len;
                  }
               }

            //Now, the CRC-32.
            if (GFSW_file_info.file_info[i].crc32_valid)
               {
               sprintf_s(buf, sizeof(buf), "\tCRC-32:\t%s\x0d\x0a", GFSW_file_info.file_info[i].crc32);
               len = strlen(buf);
               if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
                  {
                  strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
                  dispbufidx += len;
                  }
               }

            //Now, the MD-5.
            if (GFSW_file_info.file_info[i].md5_valid)
               {
               sprintf_s(buf, sizeof(buf), "\tMD-5:\t%s\x0d\x0a", GFSW_file_info.file_info[i].md5);
               len = strlen(buf);
               if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
                  {
                  strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
                  dispbufidx += len;
                  }
               }

			//Now, the SHA512.
            if (GFSW_file_info.file_info[i].sha512_valid)
               {
               sprintf_s(buf, sizeof(buf), "\tSHA-512:\t%s\x0d\x0a", GFSW_file_info.file_info[i].sha512);
               len = strlen(buf);
               if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
                  {
                  strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
                  dispbufidx += len;
                  }
               }
            }
         }
      else
         {
         break;
         }

      }

   //Process the termination condition information.
   if (GFSW_file_info.aborted)
      {
      sprintf_s(buf, sizeof(buf), "-------------------- FILE SIGNATURE ABORTED --------------------");
      }
   else if (GFSW_file_info.terminated_normally)
      {
      sprintf_s(buf, sizeof(buf), "-------------------- FILE SIGNATURE COMPLETE --------------------");
      }
   else
      {
      sprintf_s(buf, sizeof(buf), "-------------------- FILE SIGNATURE IN PROGRESS -------------------");
      }

   len = strlen(buf);
   if ((len + dispbufidx + 2) < GFSW_DISPBUFLEN)
      {
      strcpy_s(GFSW_dispbuf+dispbufidx, sizeof(GFSW_dispbuf)-dispbufidx, buf);
      dispbufidx += len;
      }
   }


//Pushes the display buffer out to the edit cotrol.
static int GFSW_UpdateEditControl(HWND te_wind)
   {
   SetWindowText(te_wind, GFSW_dispbuf);

   //Must set the buffer position (i.e. the display position) to the end.
   //The "/10" assumes that there can't be more than 8 chars or so per line--
   //couldn't find a way to go to the end automatically.
   SendMessage(te_wind,EM_LINESCROLL,0,GFSW_DISPBUFLEN/8);

   return(0);
   }


//This is the Windows procedure and event loop for the 
//main Window.
//
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
   {
   HDC         hdc ;
   PAINTSTRUCT ps ;
   static RECT        rect ;
   static HWND te_wind = 0;

   switch (message)
      {
      case WM_CREATE:
         {
         //Need to get the size of our current window so we can create the
         //child same size.
         //
         GetClientRect (hwnd, &rect);

         te_wind = CreateWindow ("EDIT",                     // window class name
                             "",                         // window caption
                             WS_CHILD|WS_VISIBLE|WS_BORDER|ES_MULTILINE|ES_AUTOVSCROLL|ES_WANTRETURN,        // window style
                             0,                          // initial x position
                             0,                          // initial y position
                             rect.right,                        // initial x size
                             rect.bottom,                         // initial y size
                             hwnd,                       // parent window handle
                             (HMENU) 1,                          // window menu handle
                             ((LPCREATESTRUCT)lParam)->hInstance, // program instance handle
                             NULL) ;                     // creation parameters
         //Print initial usage instructions.
         SetWindowText(te_wind, "To calculate CRC-32 cyclic redundancy codes, MD-5 message digests, "
			                   "and SHA-512 message digests, just "
                               "drag and drop files into this box (from Windows Explorer "
                               "or a similar application), or use the FILE->OPEN "
                               "menu selection.  Text can be freely selected and "
                               "copied from this window (select the desired text "
                               "and use the right mouse button for a popup menu "
                               "which includes COPY).");

         //Tell Windows that this child is a fair drop target for files.
         DragAcceptFiles (te_wind, TRUE);

         //We need to subclass the child window, which is to define a new wndproc
         //for it.
         GFSW_old_win_edit_handler = (WNDPROC) SetWindowLong(te_wind, GWL_WNDPROC, (long) GFSW_ReplacementEditProc);

         return 0 ;
         }
      case WM_SIZE:
         {
         rect.left = 0;
         rect.top = 0;
         rect.right = LOWORD(lParam);
         rect.bottom = HIWORD(lParam);
         MoveWindow(te_wind, 0, 0, rect.right, rect.bottom, TRUE);
         return 0;
         }
      case WM_PAINT:
         {
         hdc = BeginPaint (hwnd, &ps) ;

         GetClientRect (hwnd, &rect) ;
          
         EndPaint (hwnd, &ps) ;
         return 0 ;
         }
      case WM_DESTROY:
         {
         PostQuitMessage (0) ;
         GFSW_ChildThreadHardSyncStop();
         return 0 ;
         }
      //This is a home-spun event which means that there are files to be processed.
      //This is sent once when the drop is initially done and then each time a file
      //is processed another event is used to continue the process, until finally
      //there are no more files to do.
      case WM_USER_EV_CHILD_THREAD_PROGRESS:
         {
         //Just recalc the mirror buffer and redisplay it.
         GFSW_StageDisplayBuffer();
         GFSW_UpdateEditControl(te_wind);
         return 0;
         }
      case WM_USER_EV_CHILD_THREAD_ENDING:
         {
         HMENU hMenu;

         //Just recalc the mirror buffer and redisplay it.
         GFSW_StageDisplayBuffer();
         GFSW_UpdateEditControl(te_wind);
         GFSW_MakeGenericSound();

         hMenu = GetMenu(GFSW_parent_thread_main_window_handle);

         EnableMenuItem(hMenu, ID_ACTIONS_HALTSIGOP, MF_GRAYED);

         return 0;
         }
      case WM_COMMAND:
         {
         switch(LOWORD(wParam))
            {
            case ID_FILE_OPEN_FOR_SIG:
               {
               OPENFILENAME ofn;
               static char szFilter[] = "All Files (*.*)\0*.*\0\0";

               //Set up for the dialog.
               GFSW_dialog_file_open_buffer[0] = 0;  //Be sure that initial name zero'd out.
               GFSW_dialog_file_open_buffer[1] = 0;

               ofn.lStructSize = sizeof(OPENFILENAME);
               ofn.hwndOwner         = hwnd ;
               ofn.hInstance         = NULL ;
               ofn.lpstrFilter       = szFilter;
               ofn.lpstrCustomFilter = NULL ;
               ofn.nMaxCustFilter    = 0 ;
               ofn.nFilterIndex      = 0 ;
               ofn.lpstrFile         = GFSW_dialog_file_open_buffer;
               ofn.nMaxFile          = sizeof(GFSW_dialog_file_open_buffer) - 1;
               ofn.lpstrFileTitle    = NULL;
               ofn.nMaxFileTitle     = 0;
               ofn.lpstrInitialDir   = NULL ;
               ofn.lpstrTitle        = "Open File(s) For Signature Calculation" ;
               ofn.Flags             = OFN_ALLOWMULTISELECT
                                     | OFN_FILEMUSTEXIST
                                     | OFN_HIDEREADONLY
                                     | OFN_NODEREFERENCELINKS
                                     | OFN_PATHMUSTEXIST
                                     | OFN_EXPLORER
                                     | OFN_SHAREAWARE;           
               ofn.nFileOffset       = 0 ;
               ofn.nFileExtension    = 0 ;
               ofn.lpstrDefExt       = NULL;
               ofn.lCustData         = 0L ;
               ofn.lpfnHook          = NULL ;
               ofn.lpTemplateName    = NULL ;
     
               //Zero out the dialog return area buffer.
               GFSW_dialog_file_open_buffer[0] = 0;
               GFSW_dialog_file_open_buffer[1] = 0;

               if (GetOpenFileName (&ofn))
                  {
                  int dstarridx=0;
                  int srccharidx=0;

                  //There was success and something specified.  This means we must
                  //kill the child thread if it is running.
                  //Do a hard sync stop on the child thread.  This should not take
                  //very long.  A new drag'n'drop event will just cause restart
                  //with the new set of files.
                  GFSW_ChildThreadHardSyncStop();

                  //Zero out the file information area and the text buffer mirror.
                  memset((char *)&GFSW_file_info, 0, sizeof(GFSW_file_info));
                  GFSW_dispbuf[0] = 0;

                  dstarridx=0;
                  srccharidx=0;

                  //Advance to first string terminator.
                  while (GFSW_dialog_file_open_buffer[srccharidx] != 0)
                     srccharidx++;

                  //In the special case where the double-null is encountered immediately, there is
                  //only one file, and full path is specified.
                  //
                  if (!GFSW_dialog_file_open_buffer[srccharidx+1])
                     {
                     strcpy_s((char *)GFSW_file_info.file_info[0].fpath, sizeof(GFSW_file_info.file_info[0].fpath), GFSW_dialog_file_open_buffer);
                     }
                  else
                     {
                     //This is the multiple file case.
                     while ((dstarridx < GFSW_MAXFILES) && (GFSW_dialog_file_open_buffer[srccharidx+1]))
                        {
                        int len;

                        srccharidx++;
                        strcpy_s((char *)GFSW_file_info.file_info[dstarridx].fpath, sizeof(GFSW_file_info.file_info[dstarridx].fpath), GFSW_dialog_file_open_buffer);

                        //Watch out for adding two backslashes.  This can happen if the path
                        //contains only a drive letter ("c:\", for example) so that the OS
                        //adds a path on.
                        len = strlen(GFSW_dialog_file_open_buffer);
                        if ((len != 0) && (GFSW_dialog_file_open_buffer[len-1]=='\\'))
                           {
                           //Do nothing.  Watch out in modifying this.  The "len != 0" test
                           //above is to prevent an access violation in the second test--watch
                           //out when modifying this if-then-else construct.
                           }
                        else
                           {
                           strcat_s((char *)GFSW_file_info.file_info[dstarridx].fpath, sizeof(GFSW_file_info.file_info[dstarridx].fpath), "\\");
                           }
                        strcat_s((char *)GFSW_file_info.file_info[dstarridx].fpath, sizeof(GFSW_file_info.file_info[dstarridx].fpath), GFSW_dialog_file_open_buffer+srccharidx);
                        while (GFSW_dialog_file_open_buffer[srccharidx] != 0)
                           srccharidx++;
                        dstarridx++;
                        }
                     }

                  //Start up the child thread.
                  GFSW_ChildThreadStart();

                  //Redisplay the edit buffer.
                  GFSW_StageDisplayBuffer();
                  GFSW_UpdateEditControl(te_wind);
                  }

               return 0;
               }
            case ID_FILE_EXIT:
               {
               SendMessage(hwnd, WM_CLOSE, 0, 0);
               return 0;
               }
            case ID_ACTIONS_HALTSIGOP:
               {
               GFSW_ChildThreadHardSyncStop();
               GFSW_MakeGenericSound();
               GFSW_StageDisplayBuffer();
               GFSW_UpdateEditControl(te_wind);
               return 0;
               }
            case ID_OPTIONS_USE_SOUND:
               {
               if (GFSW_use_sound)
                  {
                  HMENU hMenu;

                  hMenu = GetMenu(GFSW_parent_thread_main_window_handle);
                  GFSW_use_sound = 0;
                  CheckMenuItem(hMenu, ID_OPTIONS_USE_SOUND, MF_UNCHECKED);
                  }
               else
                  {
                  HMENU hMenu;

                  hMenu = GetMenu(GFSW_parent_thread_main_window_handle);
                  GFSW_use_sound = 1;
                  CheckMenuItem(hMenu, ID_OPTIONS_USE_SOUND, MF_CHECKED);
                  }
               return 0;
               }
            case ID_OPTIONS_WINDOWALWAYSONTOP:
               {
               if (GFSW_always_on_top)
                  {
                  HMENU hMenu;

                  hMenu = GetMenu(GFSW_parent_thread_main_window_handle);
                  GFSW_always_on_top = 0;
                  CheckMenuItem(hMenu, ID_OPTIONS_WINDOWALWAYSONTOP, MF_UNCHECKED);
                  SetWindowPos(GFSW_parent_thread_main_window_handle,
                               HWND_NOTOPMOST,
                               0,
                               0,
                               0,
                               0,
                               SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
                  }
               else
                  {
                  HMENU hMenu;

                  hMenu = GetMenu(GFSW_parent_thread_main_window_handle);
                  GFSW_always_on_top = 1;
                  CheckMenuItem(hMenu, ID_OPTIONS_WINDOWALWAYSONTOP, MF_CHECKED);
                  SetWindowPos(GFSW_parent_thread_main_window_handle,
                               HWND_TOPMOST,
                               0,
                               0,
                               0,
                               0,
                               SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
                  }
               return 0;
               }
            case ID_HELP_ABOUT:
               {
               char *msg;
               char *first_line = "FileHash (GUI file message digest widget)\n\n";
               char *second_line = "[Built on " __DATE__ " at " __TIME__ "]\n\n";
			   char *third_line = "Please contact Dave Ashley (DASHLEY@GMAIL.COM) with any issues.";

               msg = malloc(strlen(first_line)+strlen(second_line)+strlen(third_line)+1);

               assert(msg != NULL);

               if (msg)
                  {
                  strcpy_s(msg, strlen(first_line)+strlen(second_line)+strlen(third_line)+1,   first_line);
                  strcat_s(msg, strlen(first_line)+strlen(second_line)+strlen(third_line)+1,   second_line);
                  strcat_s(msg, strlen(first_line)+strlen(second_line)+strlen(third_line)+1,   third_line);
                  MessageBox (hwnd, 
                              msg, 
                              GFSW_szAppName, 
                              MB_OK|MB_ICONINFORMATION) ;
                  free(msg);
                  }
               return 0 ;
               }
            case ID_HELP_HELP:
               {
               MessageBox (hwnd, 
                           "This program was written by Dave Ashley\n"
						   "(DASHLEY@GMAIL.COM).  Please feel free\n"
                           "to correspond by e-mail.",
                           GFSW_szAppName, 
                           MB_OK|MB_ICONINFORMATION) ;
               return 0 ;
               }
            }
         break;
         }
      }

   return DefWindowProc (hwnd, message, wParam, lParam) ;
   }


//This is the child thread which is deployed in order to calculate the CRC-32
//and MD5 of a single file.  This is done because a single-threaded approach
//does not allow the GUI to continue to receive Windows events, and it
//clogs up the desktop with an unmoveable unresponsive blob.  This child
//thread keeps its eye on the abort flag, and will terminate if it sees that.
//It takes its input from the top of the list of filenames, and returns
//the CRC-32 and MD5, whic take some time to compute.
static unsigned __stdcall GFSW_ChildThreadFunc(void *pArguments)
   {
   int fidx;
      //The index of the table entry we're currently processing.
   DWORD file_attributes;
      //The returned file attributes from the OS.
   HANDLE hFile = (HANDLE) -1;
      //The file handle used to get size and to open for reading.  This being
      //not the error value signals that it is valid and will need to be closed.
   DWORD file_size=0;
      //File size obtained from a call to the GetFileSize() function.
   DWORD file_size_high=0;
      //High 32 bits of same.
   DWORD last_error=0;
      //Result of the GetLastError() function.  This is required to properly decode
      //the file size when very large files are involved.
   DWORD rc = 0;
      //Return code from file seek.
   BOOL  rv = 0;

   struct CRCHASHFUNCS_Crc32StateStruct crc32s;
   struct ESRG_MD5_Md5StateStruct md5s;
   struct ESRG_MD5_Md5ResultStruct md5r;
   struct ESRG_SHA512_Sha512StateStruct  sha512s;
   struct ESRG_SHA512_Sha512ResultStruct sha512r;
   int exit_flag = 0;
   DWORD bytes_read = 0;
   unsigned crc32;


   //We have been invoked.  We now just signature files until the list is
   //done or until we are asked to gracefully abort.
   for (
       fidx = 0; 
       (fidx<GFSW_MAXFILES) && (GFSW_file_info.file_info[fidx].fpath[0] != 0) && (!GFSW_thread_abort_request);
       fidx++
       )
      {
      //Set any values here that are critical to have right in case we must abort.
      hFile = (HANDLE) -1;
         //This has to be the error value.  If we abort, need to know whether
         //to try to close this.

      /********************************************************************************/
      /********************************************************************************/
      /*******  F I L E    A T T R I B U T E S  ***************************************/
      /********************************************************************************/
      /********************************************************************************/
      file_attributes = GetFileAttributes((char *)GFSW_file_info.file_info[fidx].fpath);
      if (file_attributes == 0xFFFFFFFF)
         {
         GFSW_file_info.file_info[fidx].is_directory_error = 1;
            //Signal trouble trying to figure out if this is a directory.  This also
            //signals that the OS does not understand the file path, so can't do much.
         }
      else if (file_attributes & FILE_ATTRIBUTE_DIRECTORY)
         {
         GFSW_file_info.file_info[fidx].is_directory = 1;
            //This is a directory.
         }

      //In any case, the is_directory information is now valid.
      GFSW_file_info.file_info[fidx].is_directory_valid = 1;

      /********************************************************************************/
      /********************************************************************************/
      /*******  F I L E    S I Z E  ***************************************************/
      /********************************************************************************/
      /********************************************************************************/
      //If this is a directory or if there was an error getting information, we
      //cannot go forward with finding file size information.
      if (GFSW_file_info.file_info[fidx].is_directory || GFSW_file_info.file_info[fidx].is_directory_error)
         {
         GFSW_file_info.file_info[fidx].file_size_error = 1;
         }
      else
         {
         hFile = CreateFile ((char *)GFSW_file_info.file_info[fidx].fpath,
                             GENERIC_READ,
                             FILE_SHARE_READ | FILE_SHARE_WRITE,
                             NULL,
                             OPEN_EXISTING,
                             FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
                             (HANDLE)NULL);
            //Try to open the file to look at it.  The documentation
            //of the CreateFile() call is misleading in the MSDN help.
            //A web reference said that the flag combination above,
            //
            //   FILE_SHARE_READ | FILE_SHARE_WRITE,
            //
            //means "exclude none", i.e. allow others to have file open for both read
            //and write.  This seems to be the right combination to allow
            //the signaturing of documents that are open with Microsoft
            //Word or other applications.  I have no idea what will happen
            //if the file size changes while the file is open, but I
            //assume that the EOF will become true or there will be an error,
            //either of which will terminate processing of the file.
         if (hFile == (HANDLE) -1)
            {
            //Open error.  Can't go further.
            GFSW_file_info.file_info[fidx].file_size_error = 1;
            }
         else
            {
            //Try to obtain the file size.
            file_size = GetFileSize(hFile, &file_size_high);

            //Try to get the error flags, which we may need.
            last_error = GetLastError();
 
            //There is some voodoo involved with file size and the
            //error code.  This is documented in the GetFileSize() docs.
            if ((file_size == 0xFFFFFFFF) && (last_error != NO_ERROR))
               {
               GFSW_file_info.file_info[fidx].file_size_error = 1;
               }
            else
               {
               unsigned __int64 lo, hi, composite;
               //If we're here, we have a clean size.  Convert it and display it.

               //Play the bit games to get the size.
               lo = (unsigned __int64)file_size;
               hi = (unsigned __int64)file_size_high;
               composite = lo + (hi << 32);
               GFSW_file_info.file_info[fidx].file_size = composite;
               }
            }
         }

      //The file size information is now valid in any case.
      GFSW_file_info.file_info[fidx].file_size_valid = 1;

      //At this point there is potentially progress to report to
      //the main thread.  We will sit and spin until the main
      //thread will accept a posted event announcing progress
      //or until we are aborted.
      while (!PostMessage(GFSW_parent_thread_main_window_handle,
                          WM_USER_EV_CHILD_THREAD_PROGRESS,
                          0,
                          0)
             &&
             !GFSW_thread_abort_request)
         {
         Sleep(1000);  //Wait 1 second until trying again.
                       //1000ms is a long time for a modern computer,
                       //and this should be OK to ease the load if
                       //the system is seriously busy or something.
         }
 
      /********************************************************************************/
      /********************************************************************************/
      /*******  F I L E    C R C - 3 2,    M D - 5,    A N D    S H A - 5 1 2   *******/
      /********************************************************************************/
      /********************************************************************************/
      if (hFile == (HANDLE) -1)      
         {
         //File handle signals an error condition.  We cannot
         //even read the file for CRC-32, MD-5, and SHA-512.  Just set info
         //and boogie.
         strcpy_s((char *)GFSW_file_info.file_info[fidx].crc32,  sizeof(GFSW_file_info.file_info[fidx].crc32),  "INVALID FILE HANDLE");
         strcpy_s((char *)GFSW_file_info.file_info[fidx].md5,    sizeof(GFSW_file_info.file_info[fidx].md5),    "INVALID FILE HANDLE");
         strcpy_s((char *)GFSW_file_info.file_info[fidx].sha512, sizeof(GFSW_file_info.file_info[fidx].sha512), "INVALID FILE HANDLE");
         }
      else
         {
         //This is the meat of the matter where we read the file contents and do
         //the hash calculations.  The assumption made is the the buffer size
         //will be somewhere in the range of 16K-1M, so that the time to process
         //that much data is fairly small.  This should be enough granularity 
         //for a graceful voluntary thread abort.
         //
         //Rewind the file to positon 0.
         rc = SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
         if (rc == 0xFFFFFFFF)
            {
            strcpy_s((char *)GFSW_file_info.file_info[fidx].crc32,  sizeof(GFSW_file_info.file_info[fidx].crc32),  "FILE SEEK ERROR");
            strcpy_s((char *)GFSW_file_info.file_info[fidx].md5,    sizeof(GFSW_file_info.file_info[fidx].md5),    "FILE SEEK ERROR");
            strcpy_s((char *)GFSW_file_info.file_info[fidx].sha512, sizeof(GFSW_file_info.file_info[fidx].sha512), "FILE SEEK ERROR");
            goto file_read_loop_endpoint;
            }

         //Initialize the CRC-32 and MD-5 state blocks.
         CRCHASHFUNCS_Crc32StateStructOpen(&crc32s);
         ESRG_MD5_Md5StateStructOpen(&md5s);
         ESRG_SHA512_Sha512StateStructOpen(&sha512s);

         //Iterate through, reading the file and processing the blocks.  In the case
         //of an abort, we assign the strings appropriately.

         exit_flag = 0;
         while (!exit_flag)
            {
            rv = ReadFile(hFile, GFSW_file_read_buf, GFSW_FILE_READ_BUF_SIZE, &bytes_read, NULL);

            //Add whatever has been read to the running calculation.
            if (bytes_read)
               {
               CRCHASHFUNCS_Crc32StateStructAddData(&crc32s,  GFSW_file_read_buf, bytes_read);
               ESRG_MD5_Md5StateStructAddData      (&md5s,    GFSW_file_read_buf, bytes_read);
               ESRG_SHA512_Sha512StateStructAddData(&sha512s, GFSW_file_read_buf, bytes_read);
               }

            //Process error conditions.
            if (!rv)
               {
               strcpy_s((char *)GFSW_file_info.file_info[fidx].crc32,  sizeof(GFSW_file_info.file_info[fidx].crc32),  "FILE READ ERROR");
               strcpy_s((char *)GFSW_file_info.file_info[fidx].md5,    sizeof(GFSW_file_info.file_info[fidx].md5),    "FILE READ ERROR");
               strcpy_s((char *)GFSW_file_info.file_info[fidx].sha512, sizeof(GFSW_file_info.file_info[fidx].sha512), "FILE READ ERROR");
               goto file_read_loop_endpoint;
               }

            if (!bytes_read)
               {
               //This is the no-error abort when we hit the end of the file naturally.
               exit_flag = 1;
               }
            else if (GFSW_thread_abort_request)
               {
               strcpy_s((char *)GFSW_file_info.file_info[fidx].crc32,  sizeof(GFSW_file_info.file_info[fidx].crc32),  "OPERATION ABORTED");
               strcpy_s((char *)GFSW_file_info.file_info[fidx].md5,    sizeof(GFSW_file_info.file_info[fidx].md5),    "OPERATION ABORTED");
               strcpy_s((char *)GFSW_file_info.file_info[fidx].sha512, sizeof(GFSW_file_info.file_info[fidx].sha512), "OPERATION ABORTED");
               goto file_read_loop_endpoint;
               }
            }

         //This is the natural fallthrough when there was no error.
         //
         //Close up the CRC-32 structure.
         crc32 = CRCHASHFUNCS_Crc32Extract(&crc32s);
         CRCHASHFUNCS_Crc32StateStructClose(&crc32s);

         //Close up the MD-5 structure.
         ESRG_MD5_Md5StateStructClose(&md5s, &md5r);

		 //Close up the SHA-512 structure.
         ESRG_SHA512_Sha512StateStructClose(&sha512s, &sha512r);

         //Form up a CRC-32 string.
         sprintf_s((char *)GFSW_file_info.file_info[fidx].crc32, sizeof(GFSW_file_info.file_info[fidx].crc32), "%8.8X", crc32);

         //Form up an MD-5 string.
         strcpy_s((char *)GFSW_file_info.file_info[fidx].md5,    sizeof(GFSW_file_info.file_info[fidx].md5), md5r.md5_chars);

         //Form up an SHA-512 string.
         strcpy_s((char *)GFSW_file_info.file_info[fidx].sha512, sizeof(GFSW_file_info.file_info[fidx].sha512), sha512r.sha512_chars);

         //Report progress to parent thread.
         while (!PostMessage(GFSW_parent_thread_main_window_handle,
                             WM_USER_EV_CHILD_THREAD_PROGRESS,
                             0,
                             0))
            {
            Sleep(1000);  //Wait 1 second until trying again.
            }

         file_read_loop_endpoint: ;
         }

      //In any case both CRC32 and MD5 info filled in.
      GFSW_file_info.file_info[fidx].crc32_valid  = 1;
      GFSW_file_info.file_info[fidx].md5_valid    = 1;
      GFSW_file_info.file_info[fidx].sha512_valid = 1;

      //If the file handle is valid (i.e. we opened the file) we must
      //close it, regardless of cause.
      if (hFile != (HANDLE)-1)
         {
         BOOL close_result;

         close_result = CloseHandle(hFile);

         if (!close_result)
            {
            strcpy_s((char *)GFSW_file_info.file_info[fidx].crc32,  sizeof(GFSW_file_info.file_info[fidx].crc32),  "FILE HANDLE CLOSE ERROR");
            strcpy_s((char *)GFSW_file_info.file_info[fidx].md5,    sizeof(GFSW_file_info.file_info[fidx].md5),    "FILE HANDLE CLOSE ERROR");
            strcpy_s((char *)GFSW_file_info.file_info[fidx].sha512, sizeof(GFSW_file_info.file_info[fidx].sha512), "FILE HANDLE CLOSE ERROR");
            }
         }
      } // End for() each table entry loop.  


   //Report completion to parent thread.
   if (GFSW_thread_abort_request)
         GFSW_file_info.aborted = 1;
   else
         GFSW_file_info.terminated_normally = 1;

   while (!PostMessage(GFSW_parent_thread_main_window_handle,
                       WM_USER_EV_CHILD_THREAD_ENDING,
                       0,
                       0))
      {
      Sleep(1000);  //Wait 1 second until trying again.
      }

   return 0;
   }


//This function does a hard sync stop on the child thread if it is running.
//If not running, returns immediately.  Because the time to CRC32 or MD5 a
//single buffer is negligible, it shouldn't take long for the thread to 
//gracefully end itself.
static void GFSW_ChildThreadHardSyncStop(void)
   {
   if (GFSW_child_thread_is_active)
      {
      HMENU hMenu;

      GFSW_thread_abort_request = 1;

      WaitForSingleObject(GFSW_child_handle, INFINITE);

      //The thread is done.
      GFSW_child_thread_is_active = 0;
      GFSW_thread_abort_request   = 0;
      GFSW_child_handle           = 0;

      hMenu = GetMenu(GFSW_parent_thread_main_window_handle);

      EnableMenuItem(hMenu, ID_ACTIONS_HALTSIGOP, MF_GRAYED);
      }
   }


//Starts up a child thread.
static void GFSW_ChildThreadStart(void)
   {
   unsigned thread_id;
     //We just discard this.

   //We don't dare start up our single child thread unless none is already running.
   //In the release version, such an error is just ignored, but in the debug version,
   //hard stop.
   assert(!GFSW_child_thread_is_active);

   if (!GFSW_child_thread_is_active)
      {
      //Test compilation of second thread invocation.
      GFSW_child_handle = (HANDLE) _beginthreadex(NULL, 
                                                  0, 
                                                  &GFSW_ChildThreadFunc, 
                                                  NULL,
                                                  0,
                                                  &thread_id);
      if (!GFSW_child_handle)
         {
         //This is an error return from _beginthreadex.
         assert(0);
         }
      else
         {
         HMENU hMenu;

         GFSW_child_thread_is_active = 1;

         hMenu = GetMenu(GFSW_parent_thread_main_window_handle);

         EnableMenuItem(hMenu, ID_ACTIONS_HALTSIGOP, MF_ENABLED);
         }
      }
   }


//Makes a generic sound to alert user.  Honors the GFSW_use_sound state.
//
static void GFSW_MakeGenericSound(void)
   {
   if (GFSW_use_sound)
      {
      MessageBeep(MB_ICONEXCLAMATION);
      }
   }


/******************************************************************************
** $Log: gfsw.c,v $
** Revision 1.30  2009/11/29 02:16:04  dtashley
** Passed final review.
**
** Revision 1.29  2009/11/28 18:17:03  dtashley
** Development edits.
**
** Revision 1.28  2009/11/28 02:00:09  dtashley
** SHA-512 function calls added.
**
** Revision 1.27  2009/11/28 00:09:41  dtashley
** Addition of SHA512 module.
**
** Revision 1.26  2009/11/27 22:30:37  dtashley
** Warnings from newer version of Visual Studio addressed.
**
** Revision 1.25  2002/06/24 05:01:12  dtashley
** Additional documentation added for CreateFile() call.
**
** Revision 1.24  2002/06/23 07:11:55  dtashley
** Defect where would not CRC/MD5 files which were open in an application
** has been corrected.
**
** Revision 1.23  2002/05/21 06:11:07  dtashley
** Addition of version information including date and time compiled.
** Feedback from Dan Parks, Cory Pratt, and Raul Selgado moved to
** top of file and more tersely stated.
**
** Revision 1.22  2002/05/19 05:16:36  dtashley
** Additional usability by Cory Pratt added.
**
** Revision 1.21  2002/05/15 20:07:47  dtashley
** Feedback from Dan Parks, Dick McKamie, and Raul Selgado added.  This
** feedback represents things to do.
**
** Revision 1.20  2002/05/15 04:56:23  dtashley
** Minor issue with two contiguous backslashes appearing in file paths
** corrected.
**
** Revision 1.19  2002/05/14 09:50:36  dtashley
** Nearing completion of initial release of GFSW.
**
** Revision 1.18  2002/05/14 07:32:51  dtashley
** Safety checkin.
**
** Revision 1.17  2002/05/06 07:11:24  dtashley
** Safety checkin.
**
** Revision 1.16  2002/05/04 09:07:51  dtashley
** Substantial strides towards completion.
**
** Revision 1.15  2002/05/03 09:42:04  dtashley
** Completion of work on laptop.  Current solution has trouble when doing
** an exit while child thread running--need to see if this also happens
** on Win2k and resolve.  Near completion.
**
** Revision 1.14  2002/05/03 07:31:16  dtashley
** Preparing to work on laptop again.
**
** Revision 1.13  2002/05/03 05:08:28  dtashley
** Work complete on laptop.
**
** Revision 1.12  2002/05/03 04:31:30  dtashley
** Checkins before working on laptop computer.
**
** Revision 1.11  2002/05/03 00:32:23  dtashley
** Checkins before working on laptop computer.
**
** Revision 1.10  2002/05/02 12:08:59  dtashley
** Edits on laptop towards multithreading.
**
** Revision 1.9  2002/05/02 04:06:25  dtashley
** MD5 module working correctly, pending review of code.
**
** Revision 1.8  2002/05/01 21:51:44  dtashley
** Completion of MD5 implementation.  Implementation does not work correctly,
** and need to debug.  Noticed in MD5 result that first hex digit of MD5 digest
** is always "8"--this is definitely a problem as this can't happen in practice.
** Checking in for baseline to debug.
**
** Revision 1.7  2002/04/30 05:31:21  dtashley
** Minor mouse wheel handling change.  Suspect that somehow integer counts
** were getting out of sync.  May need to resolve later.
**
** Revision 1.6  2002/04/30 05:03:42  dtashley
** Final checkin before addition of MD5.
**
** Revision 1.5  2002/04/30 00:03:12  dtashley
** Code straightened up--ready for line-by-line review.
**
** Revision 1.4  2002/04/29 19:43:54  dtashley
** Safety checkin.
**
** Revision 1.3  2002/04/29 06:18:04  dtashley
** Evening safety checkin.
**
** Revision 1.2  2002/04/28 06:15:48  dtashley
** Safety checkin.
**
** Revision 1.1  2002/04/28 05:37:39  dtashley
** Initial checkin.
*******************************************************************************
** End of GFSW.C. */
