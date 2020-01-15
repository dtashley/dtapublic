/* $Archive:: /ACM Rational Approximation Paper And Algorithms/C-Language Implementation/rap_c.c      $ */
/* $Revision: 1.1 $ */
/* $Date: 2001/09/25 21:44:55 $ */
/* $Author: dtashley $ */
/* $Workfile:: rap_c.c                                                                                $ */
/* 
/*
//--------------------------------------------------------------------------------
//Copyright 2008 David T. Ashley
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
** Rational Approximation Software Submitted To CALGO To Accompany TOMS Paper
** Entitled "On Best Rational Approximations Using Large Integers"
** --------------------------------------------------------------------------
** Please see accompanying user's guide for invocation instructions.
*/

#include <process.h>
   /* For the exit() function.                                              */

#include <stdio.h>
   /* printf() and similar functions require the stdio.h header file.       */

#include <string.h>
   /* String functions and memory manipulation functions defined there.     */

#include <malloc.h>
   /* Necessary for memory allocation functions.                            */


/* It wasn't straightforward to locate the file containing the constants TRUE
** and FALSE.  Must define them myself.
*/
#ifndef FALSE
   #define FALSE (0)
#endif
#ifndef TRUE
   #define TRUE  (1)
#endif


/* This source file is broken into segments, each 
** containing a specific family of functions
** that operate on a specific data type, or at a 
** specific level of abstraction.  In C++, these
** would often tend to be made into classes (and 
** this could be done here), but it is a more
** humane experience on anyone who would like to 
** recompile the program to keep everything in a
** single source file.
**
** Functions are arranged from the bottom of the calling tree upward.  This
** way, no function prototypes are needed to ensure the compiler will 
** detect definitions and invocations which are inconsistent.
*/

/****************************************************************************/
/****************************************************************************/
/*************   C O M P I L A T I O N    C O N S T A N T S   ***************/
/****************************************************************************/
/****************************************************************************/
/* Many aspects of the program's behavior can be changed by simply changing
** the constants below.  Many of the values chosen below are intended to 
** keep the software clear of platform-specific limits.  Changes to the
** constants may cause unforeseen difficulties.
*/
#define MAX_CMDLINE_PARS                                                (10)
   /* The maximum number of command-line parameters that will be accepted.
   ** This is ultimately dependent on what the subcommands take, but 
   ** 10 is a safe value, and let's me be lazy and not search to find the
   ** command that takes the most parameters.
   */

#define INPUT_INTEGER_MAX_DIGITS                                       (463)
   /* This value was chosen to allow operation in the Farey series of up to
   ** order 2**1536.
   */
#define INTERMEDIATE_CALC_MAX_DIGITS                                  (4000)
   /* This value wasn't chosen scientifically.  It is just known that
   ** multiplying a 463-digit integer by another will result in at most
   ** a 926-digit result ... it would be quite difficult in the calculations
   ** outlined in the TOMS paper to reach the 4,000 digit limit.  Note that
   ** this is also the limit for the size of the integer components of
   ** rational results.
   */
#define STDIN_MAX_CHARS                                              (32000)
   /* The maximum number of digits that may be read from the standard input
   ** if batch mode is selected.
   */
#define LINE_LEN                                                        (78)
   /* The number of columns assumed to be displayable on the output.
   ** because a standard monitor (legacy) was 80 columns wide, I've chosen
   ** a value just a tad less.
   */
#define NUMBER_DESC_WIDTH                                               (20)
   /* The number of characters at the left reserved for describing a particular
   ** integer.
   */
#define DIGITS_PER_LINE                                                 (27)
   /* The number of digits to be displayed per line for very long
   ** integers.
   */
#define HORIZONTAL_BAR_SEP_CHAR                                        ('-')
   /* The character used to form large horizontal separators.
   */

/****************************************************************************/
/****************************************************************************/
/*********   V E R S I O N    C O N T R O L    F U N C T I O N S  ***********/
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/* vcGetVcData():                                                           */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns the embedded version control information for this program,     */
/*   arranged as a sequence of lines to be displayed on an 80-column        */
/*   monitor.                                                               */
/*                                                                          */
/* INPUTS                                                                   */
/*   n  :  Line number to return.  The first line is number 0.              */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--:  Pointer to a constant character string to display on that line,  */
/*         or NULL if there are no more lines of version control            */
/*         information to display.                                          */
/****************************************************************************/
const char *vcGetVcData(unsigned n)
   {
   const char *RAP_version_string_array[] 
      = {"$Revision: 1.1 $ $Date: 2001/09/25 21:44:55 $"};
      /* Note that the info above is filled in automatically by Visual
      ** Source Safe on every check-in--this is not manually maintained.
      */

   if (n < (sizeof(RAP_version_string_array)/sizeof(RAP_version_string_array[0])))
      {
      return(RAP_version_string_array[n]);
      }
   else
      {
      return(NULL);
      }
   }


/****************************************************************************/
/****************************************************************************/
/******   G E N E R A L    F O R M A T T I N G    F U N C T I O N S   *******/
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/* gfRepChar():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Repeats a character to stdout the specified number of times.           */
/*                                                                          */
/* INPUTS                                                                   */
/*   c  :  The character to repeat.                                         */
/*                                                                          */
/*   n  :  The number of times to repeat it.                                */
/****************************************************************************/
void gfRepChar(char c, unsigned n)
   {
   while(n--)
	   printf("%c", c);
   }


/****************************************************************************/
/* gfHline():                                                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Dumps a horizontal line of the standard length to the standard output. */
/****************************************************************************/
void gfHline(void)
   {
   gfRepChar(HORIZONTAL_BAR_SEP_CHAR, LINE_LEN);
   printf("\n");
   }


/****************************************************************************/
/* gfBannerHeading():                                                       */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Prints a banner heading bracketed by astreisks to the standard output. */
/*   This function is useful for separating different sections of output.   */
/****************************************************************************/
void gfBannerHeading(char *s, int n_extra_lines)
   {
   const int lr_padding = 3;
      /* The number of spaces on each side of what is printed.
      */
   int i;
      /* General iteration variable.
      */
   int n_asterisks;
   int input_arg_len;
   int n_left_spaces;
   int n_right_spaces;

   /* The order of the source deck prevents me from using the assertion
   ** function without function prototypes, and I don't like function
   ** prototypes, and I'm too lazy to move the functions, so I'll just
   ** protect against naughty parameters causing bizarre behavior.
   */
   if (!s)
      s = "";
   if (n_extra_lines < 0)
      n_extra_lines = 0;

   /* Print the right number of solid lines of asterisks to the
   ** standard output.
   */
   for (i=0; i<n_extra_lines; i++)
      {
      gfRepChar('*', LINE_LEN);
      printf("\n");
      }

   /* Figure out how many asterisks to print on each side of the
   ** argument, and how many spaces.  We also need to figure out
   ** how many characters of the input argument to print--if there
   ** are too many characters, we need to truncate.
   */
   input_arg_len = strlen(s);
   if(input_arg_len > (LINE_LEN - 2 * lr_padding - 2))
      input_arg_len = LINE_LEN - 2 * lr_padding - 2;

   n_asterisks = (LINE_LEN - 2*lr_padding - input_arg_len)/2;

   n_left_spaces = lr_padding;

   if ((LINE_LEN - 2*lr_padding - input_arg_len) % 2)
      {
      /* Odd, need to pad the right by one. */
      n_right_spaces = lr_padding+1;
      }
   else
      {
      n_right_spaces = lr_padding;
      }

   /* Print the text. */
   gfRepChar('*', n_asterisks);
   gfRepChar(' ', n_left_spaces);
   for (i=0; i<input_arg_len; i++)
      printf("%c", s[i]);
   gfRepChar(' ', n_right_spaces);
   gfRepChar('*', n_asterisks);
   printf("\n");

   /* Print the right number of solid lines of asterisks to the
   ** standard output.
   */
   for (i=0; i<n_extra_lines; i++)
      {
      gfRepChar('*', LINE_LEN);
      printf("\n");
      }
   }


/****************************************************************************/
/****************************************************************************/
/*******   L O G I C A L    A S S E R T I O N    F U N C T I O N S   ********/
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/* asAssert():                                                              */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Terminates the program abnormally if the logical condition specified   */
/*   is false.  Roughly speaking, this fills the same role as the           */
/*   C-language assert() macro.                                             */
/*                                                                          */
/* INPUTS                                                                   */
/*   c  :  The logical condition tested (or, more precisely, the result of  */
/*         the code inserted by the compiler to stuff this parameter).      */
/*                                                                          */
/*   l  :  The line number on which the call to this function occurs.       */
/*         This is filled in by using a special preprocessor symbol.        */
/****************************************************************************/
void asAssert(unsigned c, unsigned long l)
   {
   if (!c)
      {
      gfHline();
      printf("Abnormal termination; Assertion failed, line: %lu.\n", l);
      gfHline();

      /* Now need to convince the 'C' runtime environment to kill us.
      */
      exit(0);
      }
   }


/****************************************************************************/
/* asFatal():                                                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Terminates the program with a fatal error message.                     */
/*                                                                          */
/* INPUTS                                                                   */
/*   *msg:  The message to use.  Must be fairly short.                      */
/****************************************************************************/
void asFatal(const char *msg)
   {
   asAssert(msg != NULL, __LINE__);

   gfHline();
   printf("FATAL ERROR:  %s.\n", msg);
   gfHline();

   /* Now need to convince the 'C' runtime environment to kill us.
   */
   exit(0);
   }


/****************************************************************************/
/* asInfo():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Prints informational message to stdout and terminates the program.     */
/****************************************************************************/
void asInfo(void)           
   {
   static char *msglines[] =
      {
      "RAP.EXE:  rational approximation calculation program.",
      "!",
      "Copyright 2001, The Association For Computing Machinery (www.acm.org),",
      "David T. Ashley (dtashley@aol.com), Joseph P. DeVoe (jdevoe@visteon.com),",
      "Cory Pratt (cory_pratt@3com.com), Karl Perttunen (kperttun@visteon.com),",
      "and Anatoly Zhigljavsky (zhigljavskyaa@cardiff.ac.uk).",
      "!",
      "Please submit any bug reports or inquiries to all of the e-mail addresses",
      "listed above.",
      "!",
      "This program accompanies a paper entitled \"On Best Rational",
      "Approximations Using Large Integers\" submitted to ACM TOMS in late 2000/",
      "early 2001.  The paper fully documents the algorithms employed in this",
      "software.  In a nutshell, this program will execute algorithms on very",
      "large integers (up to 463 digits) and rational numbers with very large",
      "integer components which are helpful in finding best rational",
      "approximations in Farey series of very large order and in large rectangular",
      "regions of the integer lattice.  The source code for this program should",
      "be available from CALGO (collected algorithms of the ACM).",
      "!",
      "Format legend: MANDATORY_PARAMETER",
      "               [OPTIONAL_PARAMETER]",
      "               {a, b ...} = Exactly one must be chosen from set.",
      "               i...       = Integer",
      "               i+...      = Non-Negative Integer",
      "               i++...     = Positive Integer",
      "               r...       = Rational Number",
      "               r+...      = Non-Negative Rational Number",
      "               r++...     = Positive Rational Number",
      "!",
      "How to specify an integer:",
      "   [-]<digits>",
      "   <digits>.<more_digits>e[{-,+}]<exponent>",
      "      where the exponent creates an integer.  Example: 3.14e2 is an integer",
      "      but 3.14e1 is not (the former is 314, the latter is 31.4).  Note that",
      "      an integer can be substituted for a rational number, but a rational",
      "      number cannot always be substituted for an integer.",
      "!",
      "How to specify a rational number:",
      "   [-]<digits>/<more_digits>",
      "   [-]<digits>.<more_digits>[e[{-,+}]<exponent>]",
      "!",
      "RAP + i1 i2",
      "   Adds two integers to produce an integer result.  Result is i1 + i2.",
      "!",
      "RAP + r1 r2",
      "   Adds two rational numbers to produce a rational or integral result.",
      "   Result is r1 + r2.",
      "!",
      "RAP - i1 i2",
      "   Subtracts two integers to produce an integer result.  Result is i1 - i2.",
      "!",
      "RAP * i1 i2",
      "   Multiplies two integers to produce an integer result.  Result is i1 * i2.",
      "!",
      "RAP / i1 i2",
      "   Divides two integers to produce an integer result.  Result is i1 / i2.",
      "!",
      "RAP / r1 r2",
      "   Divides two rational numbers to produce a rational or integral result.",
      "   Result is r1 / r2.",
      "!",
      "RAP % i1 i2",
      "   Divides two integers and produces the remainder from the division.  The",
      "   result is the same as i1 % i2 as defined by the 'C' programming language",
      "   except that much longer integers are accomodated.",
      "!",
      "RAP ** i1 i2+",
      "   Exponentiates the integer i1 to the i2+'th power.",
      "!",
      "RAP ** r1 i1+",
      "   Exponentiates the rational number r1 to the i1+'th power.",
      "!",
      "RAP gcd i1++ i2++",
      "   Calculates the greatest common divisor of i1 and i2 using Euclid's",
      "   algorithm.",
      "!",
      "RAP dap r1 i1+",
      "   Given rational number r1, forms a rational approximation with a",
      "   different denominator i1.  This functionality is very useful",
      "   for converting a rational number to a more familiar decimal",
      "   approximation.  The accompanying user's manual gives full",
      "   details about the formula used by the DAP command.  DAP is also",
      "   used by several other commands to provide a more familiar",
      "   output form.",
      "!",
      "RAP cf r1+",
      "   Forms the continued fraction partial quotients and convergents",
      "   of a non-negative rational number r1.",
      "!",
      "RAP fn r1+ i1++",
      "   Finds the two best neighboring rational approximations to non-negative",
      "   rational number r1 in the Farey series of order i1.",
      "!",
      "RAP fn r1++ i1++ i2++ i3++",
      "   Same as form above except finds i2 neighbors on either side of r1",
      "   (rather than the default of 1), and uses i3 as the denominator for",
      "   presenting the approximations and errors in decimal form.",
      "!",
      "RAP mind r1+ r2+",
      "   Calculates a rational number in the interval [r1, r2] with the minimum",
      "   denominator.  If the rational number in the interval with the minimum",
      "   denominator is not unique (i.e. there is more than one with the same ",
      "   denominator), no assurances are made about which of the numbers with",
      "   minimum denominator will be returned (however, it is assured that the",
      "   result will be one of them).",
      "!",
      "RAP fab r1+ i1++ i2++",
      "   Finds the two neighbors to r1 in a rectangular area of the integer",
      "   lattice specified by h<=i1 and k<=i2.  This is a similar concept to",
      "   the \"fn\" command, but with numerator and denominator both constrained.",
      "   On output, 4 lines of digits after the decimal point are assumed by",
      "   default.",
      "!",
      "RAP fab r1+ i1++ i2++ i3++ i4++",
      "   Same as form above, except optional parameters i3 and i4 specify the",
      "   number of neighbors on both the left and right to generate, and the",
      "   denominator to use for display of DAP information.",
      "!",
      "RAP fndmax r1+ r2+ i++",
      "   Provides an upper bound on the distance between successive terms of",
      "   the Farey series of order i in the interval [r1, r2].  It is required",
      "   that r1 < r2 and that r1 and r2 are both in the Farey series of order",
      "   i.",
      "!",
      "RAP fndmax r1+ r2+ i++ j++",
      "   Same as form above except j may override the default denominator of",
      "   1e108 for DAP presentation.",
      "!",
      "RAP fabdmax r1+ r2+ i1+ i2+",
      "   Provides an upper bound on the distance between successive terms of",
      "   the \"rectangular\" Farey series (doubly-constrained) with h <= i1 and",
      "   j <= i2 in the interval [r1, r2].  It is required that r1 < r2 and that",
      "   both meet the constraints (i.e. are in the \"rectangular\" series).",
      "!",
      "RAP fabdmax r1+ r2+ i1+ i2+ j++",
      "   Same as form above except j may override the default denominator of 1e108",
      "   for DAP presentation.",
      "!",
      "If this information has scrolled off the screen and can't be read, try re-",
      "directing it to a file (for example, RAP >OUT.TXT) and then viewing the file",
      "with a text editor, or piping it through \"more\" (for example, RAP|MORE).",
      "!"
      };

   int i;

   /* Dump out the whole array and terminate the program.  Lines beginning
   ** with an exclamation point should be replaced with a horizontal line.
   */
   for (i=0; i<sizeof(msglines)/sizeof(msglines[0]); i++)
      {
      if ((msglines[i])[0] == '!')
         {
         gfHline();
         }
      else
         {
         printf("%s\n", msglines[i]);
         }
      }

   exit(0);
   }



/****************************************************************************/
/****************************************************************************/
/***************   D A T A - D R I V E N    F U N C T I O N S   *************/
/****************************************************************************/
/****************************************************************************/
/* This section is reserved for data-driven functions with no I/O 
** requirements and no side-effects.
*/
/****************************************************************************/
/* ddCharToLower():                                                         */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   If a character is upper-case, translates it to lower-case.             */
/****************************************************************************/
char ddCharToLower(char c)
   {
   switch(c)
      {
      case 'A' :  return ('a');
                  break;
      case 'B' :  return ('b');
                  break;
      case 'C' :  return ('c');
                  break;
      case 'D' :  return ('d');
                  break;
      case 'E' :  return ('e');
                  break;
      case 'F' :  return ('f');
                  break;
      case 'G' :  return ('g');
                  break;
      case 'H' :  return ('h');
                  break;
      case 'I' :  return ('i');
                  break;
      case 'J' :  return ('j');
                  break;
      case 'K' :  return ('k');
                  break;
      case 'L' :  return ('l');
                  break;
      case 'M' :  return ('m');
                  break;
      case 'N' :  return ('n');
                  break;
      case 'O' :  return ('o');
                  break;
      case 'P' :  return ('p');
                  break;
      case 'Q' :  return ('q');
                  break;
      case 'R' :  return ('r');
                  break;
      case 'S' :  return ('s');
                  break;
      case 'T' :  return ('t');
                  break;
      case 'U' :  return ('u');
                  break;
      case 'V' :  return ('v');
                  break;
      case 'W' :  return ('w');
                  break;
      case 'X' :  return ('x');
                  break;
      case 'Y' :  return ('y');
                  break;
      case 'Z' :  return ('z');
                  break;
      default:    return(c);
                  break;
      }
   }


/****************************************************************************/
/* ddIsInfoChar():                                                          */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns TRUE if the passed character is a character that should be in  */
/*   a token, or FALSE otherwise.                                           */
/****************************************************************************/
unsigned ddIsInfoChar(char c)
   {
   int i;
   char d;
   const char CONST_info_characters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                          'o', 'p', 'q', 'r', 's', 't', 'u',
                                          'v', 'w', 'x', 'y', 'z', '0', '1',
                                          '2', '3', '4', '5', '6', '7', '8',
                                          '9', '+', '-', '*', '/', '_', '.',
                                          '\\','%' };
   
   d = ddCharToLower(c);

   for (i=0; i<sizeof(CONST_info_characters)/sizeof(CONST_info_characters[0]); i++)
      {
      if (CONST_info_characters[i] == d)
         return(TRUE);
      }

   return(FALSE);
   }


/****************************************************************************/
/* ddIsDiscardChar():                                                       */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns TRUE if the passed character is a character that should be     */
/*   discarded, or FALSE otherwise.                                         */
/****************************************************************************/
unsigned ddIsDiscardChar(char c)
   {
   int i;
   char d;
   const char CONST_discard_characters[] = {','};
   
   d = ddCharToLower(c);

   for (i=0; i<sizeof(CONST_discard_characters)/sizeof(CONST_discard_characters[0]); i++)
      {
      if (CONST_discard_characters[i] == d)
         return(TRUE);
      }

   return(FALSE);
   }


/****************************************************************************/
/* ddIsWhitespaceChar():                                                    */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns TRUE if the passed character is a character that should be     */
/*   treated as whitespace, or FALSE otherwise.                             */
/****************************************************************************/
unsigned ddIsWhitespaceChar(char c)
   {
   int i;
   char d;
   const char CONST_whitespace_chars[] = { ' ', '\t', '\n' };
   
   d = ddCharToLower(c);

   for (i=0; i<sizeof(CONST_whitespace_chars)/sizeof(CONST_whitespace_chars[0]); i++)
      {
      if (CONST_whitespace_chars[i] == d)
         return(TRUE);
      }

   return(FALSE);
   }


/****************************************************************************/
/* ddIsDigit():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns TRUE if the passed argument is a digit, or FALSE otherwise.    */
/*                                                                          */
/* INPUTS                                                                   */
/*   c  :  Character to evaluate for digitness (or is that digiality??).    */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--:  TRUE if a digit, FALSE otherwise.                                */
/****************************************************************************/
unsigned ddIsDigit(char c)
   {
   if ((c >= '0') && (c <= '9'))
      return(TRUE);
   else
      return(FALSE);
   }


/****************************************************************************/
/* ddDigitToValue():                                                        */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Converts from ASCII digit to unsigned integer value.  Fatal to call    */
/*   with non-digit.                                                        */
/*                                                                          */
/* INPUTS                                                                   */
/*   c  :  Character to convert to value.                                   */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--:  Value.                                                           */
/****************************************************************************/
unsigned ddDigitToValue(char c)
   {
   if ((c >= '0') && (c <= '9'))
      {
      return(c - '0');
      }
   else
      {
      asAssert(0, __LINE__);  /* Guaranteed fatal. */
      return(0);              /* To satisfy compiler warning about path not
                              ** returning a value.
                              */
      }
   }


/****************************************************************************/
/* ddValueToDigit():                                                        */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Converts from unsigned value to digit '0'..'9'.  Fatal to call with    */
/*   with value out of range.                                               */
/*                                                                          */
/* INPUTS                                                                   */
/*   i  :  Character to convert to value.                                   */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--:  Value.                                                           */
/****************************************************************************/
char ddValueToDigit(unsigned i)
   {
   if (i < 10)
      {
      return(i + '0');
      }
   else
      {
      asAssert(0, __LINE__);  /* Guaranteed fatal. */
      return('0');              /* To satisfy compiler warning about path not
                              ** returning a value.
                              */
      }
   }


/****************************************************************************/
/* ddStringContains():                                                      */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Determines whether STR1 contains any characters in STR2, and returns   */
/*   TRUE if so or FALSE otherwise.                                         */
/****************************************************************************/
int ddStringContains(const char *str1, const char *str2)
   {
   unsigned s1len, s2len;
   unsigned i, j;

   asAssert(str1 != NULL, __LINE__);
   asAssert(str2 != NULL, __LINE__);

   s1len = strlen(str1);
   s2len = strlen(str2);
   
   for (i=0; i<s1len; i++)
      {
      for (j=0; j<s2len; j++)
         {
         if (str1[i] == str2[j])
            return(TRUE);
         }
      }

   return(FALSE);
   }


/****************************************************************************/
/* ddStringContainsOnly():                                                  */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns TRUE if STR1 contains ONLY characters from STR2, or FALSE      */
/*   otherwise.                                                             */
/****************************************************************************/
int ddStringContainsOnly(const char *str1, const char *str2)
   {
   int i, j;
   int l1, l2;

   asAssert(str1 != NULL, __LINE__);
   asAssert(str2 != NULL, __LINE__);

   l1 = strlen(str1);
   l2 = strlen(str2);

   for (i=0; i<l1; i++)
      {
      for (j=0; j<l2; j++)
         {
         if (str1[i] == str2[j])
            break;
         }

      if (j == l2)
         return(FALSE);
      }

   return(TRUE);
   }


/****************************************************************************/
/* ddStringReverse():                                                       */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Reverses the order of characters in the string s.                      */
/****************************************************************************/
void ddStringReverse(char *s)                  
   {
   unsigned l;
   unsigned i;
   unsigned limit;
   char temp;

   asAssert(s != NULL, __LINE__);

   l = strlen(s);
   limit = l / 2;

   for (i=0; i<limit; i++)
      {
      temp = s[i];
      s[i] = s[l-i-1];
      s[l-i-1] = temp;
      }
   }


/****************************************************************************/
/* ddStringDeleteLeadingChar():                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Deletes the leading character of a string.  If there is no leading     */
/*   character, takes no action.                                            */
/****************************************************************************/
void ddStringDeleteLeadingChar(char *s)                  
   {
   int len;
   int i;

   asAssert(s != NULL, __LINE__);

   len = strlen(s);

   for (i=0; i<len; i++)
      s[i] = s[i+1];
   }


/****************************************************************************/
/* ddFundamentalAdditionCell():                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Fundamental cell of addition, used to add one ASCII digit to another   */
/*   ASCII digit, processing carries in and carries out.  Unexpected values */
/*   will generate a fatal error.                                           */
/*                                                                          */
/* INPUTS                                                                   */
/*   digit1:        Digit 1 in.                                             */
/*   digit2:        Digit 2 in.                                             */
/*   carry_in:      Carry in.  Must be '0' or '1'.                          */
/*                                                                          */
/* OUTPUTS                                                                  */
/*  *digit_out:     Digit result out.                                       */
/*  *carry_out:     Carry out.  Will be '0' or '1'.                         */
/****************************************************************************/
void ddFundamentalAdditionCell(char      digit1,
                               char      digit2,
                               char      carry_in,
                               char     *digit_out,
                               char     *carry_out)
   {
   unsigned vd1;
   unsigned vd2;
   unsigned vci;
   unsigned total;

   asAssert(ddIsDigit(digit1), __LINE__);
   asAssert(ddIsDigit(digit2), __LINE__);
   asAssert(ddDigitToValue(carry_in) <= 1, __LINE__);
   asAssert(digit_out != NULL, __LINE__);
   asAssert(carry_out != NULL, __LINE__);

   vd1 = ddDigitToValue(digit1);
   vd2 = ddDigitToValue(digit2);
   vci = ddDigitToValue(carry_in);

   total = vd1+vd2+vci;

   *digit_out = ddValueToDigit(total % 10);
   *carry_out = ddValueToDigit(total / 10);
   }


/****************************************************************************/
/* ddFundamentalMultiplicationCell():                                       */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Fundamental cell of multiplication, used to multiply one ASCII digit   */
/*   by another, processing carries in and out.  Unexpected inputs will     */
/*   generate a fatal error.                                                */
/*                                                                          */
/* INPUTS                                                                   */
/*   digit1:        Digit 1 in.                                             */
/*   digit2:        Digit 2 in.                                             */
/*   carry_in:      Carry in.  Because of the way multiplication works,     */
/*                  this must always be from '0' through '8'.               */
/*                                                                          */
/* OUTPUTS                                                                  */
/*  *digit_out:     Digit result out.                                       */
/*  *carry_out:     Carry out.  Because of the way multiplication works,    */
/*                  this must always be from '0' through '8'.               */
/****************************************************************************/
void ddFundamentalMultiplicationCell(char      digit1,
                                     char      digit2,
                                     char      carry_in,
                                     char     *digit_out,
                                     char     *carry_out)
   {
   unsigned vd1;
   unsigned vd2;
   unsigned vci;
   unsigned total;

   asAssert(ddIsDigit(digit1), __LINE__);
   asAssert(ddIsDigit(digit2), __LINE__);
   asAssert(ddDigitToValue(carry_in) <= 8, __LINE__);
   asAssert(digit_out != NULL, __LINE__);
   asAssert(carry_out != NULL, __LINE__);

   vd1 = ddDigitToValue(digit1);
   vd2 = ddDigitToValue(digit2);
   vci = ddDigitToValue(carry_in);

   total = (vd1 * vd2) + vci;

   *digit_out = ddValueToDigit(total % 10);
   *carry_out = ddValueToDigit(total / 10);
   }


/****************************************************************************/
/* ddFundamentalSubtractionCell():                                          */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Fundamental cell of subtraction, used to subtract one ASCII digit from */
/*   another ASCII digit, processing borrows in and borrows out.            */
/*   Unexpected values will generate a fatal error.                         */
/*                                                                          */
/* INPUTS                                                                   */
/*   digit1:        Digit 1 in.                                             */
/*   digit2:        Digit 2 in.                                             */
/*   borrow_in:     Borrow in.  Must be '0' or '1'.                         */
/*                                                                          */
/* OUTPUTS                                                                  */
/*  *digit_out:     Digit result out, digit1-digit2-borrow_in.              */
/*  *borrow_out:    Borrow out.  Will be '0' or '1'.                        */
/****************************************************************************/
void ddFundamentalSubtractionCell(char      digit1,
                                  char      digit2,
                                  char      borrow_in,
                                  char     *digit_out,
                                  char     *borrow_out)
   {
   unsigned vd1;
   unsigned vd2;
   unsigned vbi;
   unsigned total;

   asAssert(ddIsDigit(digit1), __LINE__);
   asAssert(ddIsDigit(digit2), __LINE__);
   asAssert(ddDigitToValue(borrow_in) <= 1, __LINE__);
   asAssert(digit_out != NULL, __LINE__);
   asAssert(borrow_out != NULL, __LINE__);

   vd1 = ddDigitToValue(digit1);
   vd2 = ddDigitToValue(digit2);
   vbi = ddDigitToValue(borrow_in);

   total = 10+vd1-vd2-vbi;

   *digit_out = ddValueToDigit(total % 10);
   if (total < 10)
      {
      *borrow_out = '1';
        /* If we went neggy neggy on the subtraction, we need a borrow.
        */
      }
   else
      {
      *borrow_out = '0';  /* No borrow. */
      }
   }


/****************************************************************************/
/* ddUmin():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns the minimum of two unsigned integers.                          */
/*                                                                          */
/* INPUTS                                                                   */
/*   arg1, arg2  :  Unsigned integers to compare.                           */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--         :  Samller of arg1, arg2.                                  */
/****************************************************************************/
unsigned ddUmin(unsigned arg1, unsigned arg2)
   {
   if (arg1 < arg2)
      return(arg1);
   else
      return(arg2);
   }



/****************************************************************************/
/* ddUmax():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns the maximum of two unsigned integers.                          */
/*                                                                          */
/* INPUTS                                                                   */
/*   arg1, arg2  :  Unsigned integers to compare.                           */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--         :  Larger of arg1, arg2.                                   */
/****************************************************************************/
unsigned ddUmax(unsigned arg1, unsigned arg2)
   {
   if (arg1 > arg2)
      return(arg1);
   else
      return(arg2);
   }


/****************************************************************************/
/* ddSmin():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns the minimum of two signed integers.                            */
/*                                                                          */
/* INPUTS                                                                   */
/*   arg1, arg2  :  Signed integers to compare.                             */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--         :  Samller of arg1, arg2.                                  */
/****************************************************************************/
int ddSmin(int arg1, int arg2)
   {
   if (arg1 < arg2)
      return(arg1);
   else
      return(arg2);
   }



/****************************************************************************/
/* ddSmax():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Returns the maximum of two signed integer.                             */
/*                                                                          */
/* INPUTS                                                                   */
/*   arg1, arg2  :  Signed integers to compare.                             */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--         :  Larger of arg1, arg2.                                   */
/****************************************************************************/
int ddSmax(int arg1, int arg2)
   {
   if (arg1 > arg2)
      return(arg1);
   else
      return(arg2);
   }


/****************************************************************************/
/****************************************************************************/
/*******   M E M O R Y    A L L O C A T I O N    F U N C T I O N S   ********/
/****************************************************************************/
/****************************************************************************/
/* These functions are primarily wrappers for the standard 'C' library
** functions.  They will trap "out of memory" errors, and also provide a
** place to insert debugging code if it becomes necessary.
*/
/****************************************************************************/
/* maMalloc():                                                              */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Wrapper for malloc().  See malloc() documentation.                     */
/****************************************************************************/
void *maMalloc(size_t n)
   {
   void *rv;

   rv = malloc(n);

   asAssert(rv != NULL, __LINE__);

   return(rv);
   }


/****************************************************************************/
/* maFree():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Wrapper for free().  See free() documentation.                         */
/****************************************************************************/
void maFree(void *p)
   {
   asAssert(p != NULL, __LINE__);

   free(p);
   }


/****************************************************************************/
/* maRealloc():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Wrapper for realloc().  See realloc() documentation.                   */
/****************************************************************************/
void *maRealloc(void *ptr, size_t n)
   {
   void *rv;

   rv = realloc(ptr, n);

   asAssert(rv != NULL, __LINE__);

   return(rv);
   }


/****************************************************************************/
/****************************************************************************/
/*******   S Y N T H E T I C    I N T E G E R    F U N C T I O N S   ********/
/****************************************************************************/
/****************************************************************************/
/* Definition of a synthetic integer.
*/
struct synthetic_integer_struct
   {
   unsigned nan;
      /* Boolean variable used to remember errors that render the integer
      ** as "non a number", so that its value is invalid or unknown.
      ** NAN's propagate so that performing any operating involving a NAN
      ** also yields a NAN.  A non-zero value here means that an error has
      ** been thrown and the synthetic integer is invalid.
      */
   unsigned neg;
      /* Only the absolute value of the integer is stored as a character
      ** string.  This boolean remembers if the number is negative.
      ** A non-zero value here means the integer is negative.  This may have
      ** either value when the value of zero is represented by the 
      ** synthetic integer.
      */
   unsigned len;
      /* The number of characters in the string representing the integer.
      ** This is the same as would be returned by strlen().  This field
      ** is maintained to avoid the expense of counting characters before
      ** the terminator each time the length is needed.
      */
   unsigned char digits[INTERMEDIATE_CALC_MAX_DIGITS + 1];
      /* The string representing the synthetic integer.  To avoid the need
      ** to move large blocks of characters, the integer is stored with the
      ** least significant digits first.  The string must be \0 terminated--
      ** this is done primarily to make printing things for debugging
      ** easier, although the terminator is redundant with the "len" field
      ** above.  The valid representation of zero is a "len" field of 
      ** zero and a terminating \0 as element [0] here.  No commas or other
      ** characters besides digits are allowed.
      */
   };


typedef struct synthetic_integer_struct SYNTHETIC_INTEGER;
   /* Typedef for more compact reference to data type.
   */


/****************************************************************************/
/* siCreate():                                                              */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Creates a synthetic integer (allocates the memory and initializes) and */
/*   sets value to zero.                                                    */
/*                                                                          */
/* INPUTS                                                                   */
/*   *i :  Pointer to pointer to synthetic integer.  The caller's pointer   */
/*         will be filled in to point to the allocated object.              */
/****************************************************************************/
void siCreate(SYNTHETIC_INTEGER **i)
   {
   asAssert(i != NULL, __LINE__);
      /* Input pointer may not be NULL.
      */

   *i = maMalloc(sizeof(SYNTHETIC_INTEGER));
      /* Allocate the memory, stuff the pointer in the caller's
      ** area.
      */

   /* Initialize the synthetic integer to what is required for
   ** the number zero.
   */
   (*i)->nan = 0;
   (*i)->neg = 0;
   (*i)->len = 0;
   (*i)->digits[0] = 0;
   }


/****************************************************************************/
/* siDestroy():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Destroys a synthetic integer (deallocates the memory and sets the      */
/*   caller's pointer to NULL.                                              */
/*                                                                          */
/* INPUTS                                                                   */
/*   *i :  Pointer to pointer to synthetic integer.  The synthetic integer  */
/*         will be destroyed and the caller's pointer will be filled to     */
/*         NULL.                                                            */
/****************************************************************************/
void siDestroy(SYNTHETIC_INTEGER **i)
   {
   asAssert(i != NULL, __LINE__);
      /* Input pointer to pointer may not be NULL.
      */
   asAssert(*i != NULL, __LINE__);
      /* Input pointer to block of memory may not be NULL.
      */

   maFree(*i);
      /* Deallocate block of memory.
      */

   *i = NULL;
      /* Fill in the caller's variable to NULL.
      */
   }


/****************************************************************************/
/* siCopy():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Copies a synthetic integer.  The integer must already be created.      */
/*                                                                          */
/* INPUTS                                                                   */
/*   *src, *dst  :  Source and destination synthetic integers.              */
/****************************************************************************/
void siCopy(SYNTHETIC_INTEGER **src, SYNTHETIC_INTEGER **dst)
   {
   asAssert(src != NULL, __LINE__);
   asAssert(*src != NULL, __LINE__);
   asAssert(dst != NULL, __LINE__);
   asAssert(*dst != NULL, __LINE__);

   /* There are a lot of ways to copy, and pros and cons.
   ** I'll choose the one that gives the least typing
   ** here in the source code, but maybe I'll need to
   ** optimize it later.
   */
   memcpy(*dst, *src, sizeof(SYNTHETIC_INTEGER));
   }


/****************************************************************************/
/* siMulByTen():                                                            */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Multiplies a synthetic integer by 10, producing a NAN result if there  */
/*   is an overflow in the number of digits.  This is a primitive operation */
/*   used in multiplication of arbitrary integers.                          */
/****************************************************************************/
void siMulByTen(SYNTHETIC_INTEGER **arg)
   {
   asAssert(arg != NULL, __LINE__);
   asAssert(*arg != NULL, __LINE__);

   /* If the integer is already NAN, NAN it stays.
   */
   if (!((*arg)->nan))
      {
      /* If the integer is 0, 0 it stays. */
      if ((*arg)->len)
         {
         /* The result will overflow iff the string is already
         ** at its length limit.  If so, must declare a NAN.  Multiplication
         ** by 10 is guaranteed to add exactly one digit.
         */
         asAssert((*arg)->len <= INTERMEDIATE_CALC_MAX_DIGITS, __LINE__);
         if ((*arg)->len == INTERMEDIATE_CALC_MAX_DIGITS)
            {
            /* Overflow.  Must declare a NAN. */
            (*arg)->digits[0] = '\0';
            (*arg)->len       = 0;
            (*arg)->nan       = TRUE;
            (*arg)->neg       = FALSE;
            }
         else
            {
            /* The digit shift will come off alright.  Carry it out.
            */
            unsigned tgt_idx;

            for (tgt_idx = (*arg)->len; tgt_idx >= 1; tgt_idx--)
               {
               (*arg)->digits[tgt_idx] = (*arg)->digits[tgt_idx-1];
               }
            (*arg)->digits[0] = '0';
            (*arg)->digits[(*arg)->len + 1] = '\0';
            ((*arg)->len)++;
            }
         }
      }
   }


/****************************************************************************/
/* siDivByTen():                                                            */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Divides a synthetic integer by 10 using digit-shifting (remainders     */
/*   are discarded.  This function is used in division of arbitrary         */
/*   integers.                                                              */
/****************************************************************************/
void siDivByTen(SYNTHETIC_INTEGER **arg)
   {
   asAssert(arg != NULL, __LINE__);
   asAssert(*arg != NULL, __LINE__);

   /* If the integer is already NAN, NAN it stays.
   */
   if (!((*arg)->nan))
      {
      /* If the integer is a single digit, it must go to zero.
      */
      if ((*arg)->len == 1)
         {
         (*arg)->len       = 0;
         (*arg)->digits[0] = '\0';
         (*arg)->neg       = FALSE;
         }
      else
         {
         unsigned i;

         asAssert((*arg)->len <= INTERMEDIATE_CALC_MAX_DIGITS, __LINE__);

         /* This is just a normal digit shift. */
         for (i=0; i<((*arg)->len); i++)
            {
            (*arg)->digits[i] = (*arg)->digits[i+1];
            }

         ((*arg)->len)--;
         }
      }
   }


/****************************************************************************/
/* siMulByDigit():                                                          */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Multiplies a synthetic integer by an arbitrary digit, producing a      */
/*   result that may be zero, the argument, or an integer of larger mag-    */
/*   nitude.  A NAN is declared on overflow.  This is a primitive operation */
/*   used in multiplication of arbitrary integers.                          */
/****************************************************************************/
void siMulByDigit(SYNTHETIC_INTEGER **arg, char digit)
   {
   asAssert(arg != NULL, __LINE__);
   asAssert(*arg != NULL, __LINE__);
   asAssert(ddIsDigit(digit), __LINE__);

   /* If the integer is already NAN, NAN it stays.
   */
   if (!((*arg)->nan))
      {
      /* If the integer is 0 or the digit is '0', force the result
      ** to 0.
      */
      if (!((*arg)->len) || (digit == '0'))
         {
         (*arg)->digits[0] = '\0';
         (*arg)->len       = 0;
         (*arg)->nan       = FALSE;
         (*arg)->neg       = FALSE;
         }
      else
         {
         /* This is now a valid multiplication.  Regrettably, we can't
         ** determine an overflow or lack of decisively except by carrying 
         ** the multiplication out to its end.
         */
         char carry;
         char new_digit;
         unsigned cur_digit;

         carry = '0';

         asAssert((*arg)->len <= INTERMEDIATE_CALC_MAX_DIGITS, __LINE__);

         for (cur_digit=0; cur_digit < (*arg)->len; cur_digit++)
            {
            ddFundamentalMultiplicationCell((*arg)->digits[cur_digit],
                                            digit,
                                            carry,
                                            &new_digit,
                                            &carry);

            if (cur_digit == ((*arg)->len - 1)) /* If last digit in loop. */
               {
               if (cur_digit == (INTERMEDIATE_CALC_MAX_DIGITS-1)) /* arg was max len. */
                  {
                  if (carry != '0')
                     {
                     /* We have an SI that was at the length limit, we've processed.
                     ** the last digit, and there is a carry out.  Must declare a NAN.
                     */
                     (*arg)->digits[0] = '\0';
                     (*arg)->len       = 0;
                     (*arg)->nan       = TRUE;
                     (*arg)->neg       = FALSE;
                     }
                  else
                     {
                     /* We have an SI that was max length, but did not overflow.
                     ** Close it up normally.
                     */
                     (*arg)->digits[cur_digit] = new_digit;
                     /* Nothing else to do.  Everything is preset. */
                     }
                  }
               else
                  {
                  /* We are at the last digit of multiplication, but not at the 
                  ** maximum length of a string of digits.  Cleanup without fear
                  ** of overflow.
                  */
                  if (carry == '0')
                     {
                     /* Number stayed same length.  Just assign digit.  Terminator 
                     ** and other info is still valid.
                     */
                     (*arg)->digits[cur_digit] = new_digit;
                     }
                  else
                     {
                     /* At last digit of multiplication.  Number grew by one digit.
                     ** Clean up.
                     */
                     (*arg)->digits[cur_digit]   = new_digit;
                     (*arg)->digits[cur_digit+1] = carry;
                     (*arg)->digits[cur_digit+2] = '\0';
                     ((*arg)->len)++;

                     /* Must break out of the for() loop.  Otherwise, modifying
                     ** the length above will keep us going.
                     */
                     break;
                     }
                  }
               }
            else
               {
               /* Not the last digit in the loop.  Just assign digit.
               */
               (*arg)->digits[cur_digit] = new_digit;
               }
            } /* End for() each digit. */
         }
      }
   }


/****************************************************************************/
/* siCompareAbs():                                                          */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Compares the absolute value of two synthetic integers (this involves   */
/*   comparing only the string representation without considering the       */
/*   sign).  This function is useful from within the full compare function  */
/*   to avoid duplication of code--it isn't very useful in any other        */
/*   context.                                                               */
/*                                                                          */
/* INPUTS                                                                   */
/*   *arg1, *arg2  :  Two synthetic integers whose absolute values should   */
/*                    be compared.                                          */
/*                                                                          */
/* OUTPUT                                                                   */
/*   <--   :   (-1)  : ABS(*arg1) < ABS(*arg2)                              */
/*              (0)  : ABS(*arg1) = ABS(*arg2)                              */
/*              (1)  : ABS(*arg1) > ABS(*arg2)                              */
/****************************************************************************/
int siCompareAbs(SYNTHETIC_INTEGER **arg1, SYNTHETIC_INTEGER **arg2)
   {
   int i;

   asAssert(arg1 != NULL, __LINE__);
   asAssert(*arg1 != NULL, __LINE__);
   asAssert(arg2 != NULL, __LINE__);
   asAssert(*arg2 != NULL, __LINE__);

   if ((*arg1)->len < (*arg2)->len)
      {
      return(-1);
      }
   else if ((*arg1)->len > (*arg2)->len)
      {
      return(1);
      }
   else if (!((*arg1)->len) && !((*arg2)->len))
      {
      /* Both are zero, return equal. */
      return(0);
      }
   else
      {
      /* Lengths of strings are equal--must look at the strings in
      ** more detail.
      */
      for (i = (*arg1)->len; i >= 0; i--)
         {
         if ((*arg1)->digits[i] < (*arg2)->digits[i])
            {
            return(-1);
            }
         else if ((*arg1)->digits[i] > (*arg2)->digits[i])
            {
            return(1);
            }
         }

      /* Have iterated through the strings--couldn't find any differences.
      ** They are equal.  This also covers the zero case.
      */
      return(0);
      }
   }


/****************************************************************************/
/* siCompare():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Establishes the logical ordering of two synthetic integers.            */
/*                                                                          */
/* INPUTS                                                                   */
/*   *arg1, *arg2  :  Two synthetic integers to compare.                    */
/*                                                                          */
/* OUTPUT                                                                   */
/*   <--   :   (-1)  : *arg1 < *arg2.                                       */
/*              (0)  : *arg1 = *arg2                                        */
/*              (1)  : *arg1 > *arg2                                        */
/****************************************************************************/
int siCompare(SYNTHETIC_INTEGER **arg1, SYNTHETIC_INTEGER **arg2)
   {
   asAssert(arg1 != NULL, __LINE__);
   asAssert(*arg1 != NULL, __LINE__);
   asAssert(arg2 != NULL, __LINE__);
   asAssert(*arg2 != NULL, __LINE__);

   /* If either integer has been marked NAN, we shouldn't be
   ** comparing, and there is no reason to handle this case,
   ** as it is a minority case and harmless whatever happens.
   */
   /* Cover the two easiest cases, which are where one operand is
   ** positive and the other is negative.
   */
   if (((*arg1)->neg) && (!((*arg2)->neg)))
      {
      return(-1);
      }
   else if ((!((*arg1)->neg)) && ((*arg2)->neg))
      {
      return(1);
      }
   /* We know both integers are of the same sign.  We can call the
   ** absolute value compare function to get their ordering.
   */
   else if ((*arg1)->neg)
      {
      return(siCompareAbs(arg2, arg1));  /* Reverse the order to negate the
                                         ** results provided by
                                         ** siCompareAbs().
                                         */
      }
   else if (!((*arg1)->neg))
      {
      return(siCompareAbs(arg1, arg2));  /* Normal non-neg compare. 
                                         */
      }
   else
      {
      /* It should be impossible to reach this case.
      */
      asAssert(0, __LINE__);  /* Fatal. */
      return(0);  /* Suppress compiler warning. */
      }
   }


/****************************************************************************/
/* siDump():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Outputs a synthetic integer to the standard output stream.  The output */
/*   includes a title, and provisions are made for NAN, for a description,  */
/*   and prints commas.  It is the caller's responsibility to provide lines */
/*   before and lines after if desired.  Ths function assumes that it       */
/*   starts with the cursor in column 1.                                    */
/*                                                                          */
/* INPUTS                                                                   */
/*   **si          :  The synthetic integer which is being output.          */
/*                                                                          */
/*   *desc         :  The description to use for the integer.  It will be   */
/*                    right-justified up against the start of the integer,  */
/*                    and this function will automatically include a        */
/*                    colon.  If the description is too long, this function */
/*                    will truncate it to fit the space available.          */
/****************************************************************************/
void siDump(SYNTHETIC_INTEGER **si, const char *desc)
   {
   unsigned cur_line;
   unsigned nlines;
   unsigned digits_per_line;

   /* Make sure the caller isn't doing something bad for the program's health.
   */
   asAssert(si != NULL, __LINE__); 
   asAssert(*si != NULL, __LINE__);
   asAssert(desc != NULL, __LINE__);

   /* The number of digits per line that we assume must be a multiple of
   ** three.  Round this up in case the preprocessor constant was set
   ** dubiously.
   */
   digits_per_line = ddUmax(3, ((DIGITS_PER_LINE + 2) /3) * 3);

   /* As the first order of business, figure out how many lines the beast
   ** will require.
   */
   if ((*si)->nan)
      {
      nlines = 1;  /* Only one line required for NAN verbeage. */
      }
   else if (!((*si)->len))
      {
      nlines = 1;  /* The zero value requires one line. */
      }
   else
      {
      /* In any other case, have a formula.
      */
      nlines = 1 + ((*si)->len - 1) / digits_per_line;
      }

   /* Iterate through each line, spitting out whatever is appropriate. */
   for (cur_line = 0; cur_line < nlines; cur_line++)
      {
      unsigned cur_digit_on_line;

      /* If this is the first line, spit out the description, right-aligned.
      ** Otherwise, spit spaces.
      */
      if (!cur_line)
         {
         /* First line. */
         unsigned len;

         len = strlen(desc);

         if (len <= NUMBER_DESC_WIDTH)
            {
            /* Description is shorter or equal, pad on left. */
            gfRepChar(' ', NUMBER_DESC_WIDTH - len);
            printf("%s", desc);
            }
         else
            {
            /* Description is too long, truncate. */
            unsigned i;

            for (i=0; i<len; i++)
               printf("%c", desc[i]);
            }

         printf(": ");

         /* If the number is negative, throw in a minus sign. */
         if ((*si)->neg && !(*si)->nan)
            {
            printf("- ");
            }
         else
            {
            printf("  ");
            }
         }
      else
         {
         /* Every line but first line. */
         gfRepChar(' ', NUMBER_DESC_WIDTH+4);
         }

      for(cur_digit_on_line=0; cur_digit_on_line < digits_per_line; cur_digit_on_line++)
         {
         unsigned idx_into_string;
            /* Index into the string which is our digit of interest.
            */

         /* Compute the index.  The equation is based on the ordering
         ** of presentation, for example,
         **
         **            7 6
         **          5 4 3
         **          2 1 0.
         **
         ** With a little thought, the equation should make sense.
         ** The index won't always be used to index into the string.
         */
         idx_into_string =
           (((nlines-1) - cur_line) * digits_per_line)
           +
           (digits_per_line - 1 - cur_digit_on_line);

         /* Print the appropriate digit or a space.  The NAN case and the 
         ** zero case need to be treated specially.
         */
         if ((*si)->nan)
            {
            /* Not a number.  Everything is blank, except spell out NAN
            ** at the end of the string of digits.
            */
            if (cur_digit_on_line == (digits_per_line - 3))
               {
               printf("N");
               }
            else if (cur_digit_on_line == (digits_per_line - 2))
               {
               printf("A");
               }
            else if (cur_digit_on_line == (digits_per_line - 1))
               {
               printf("N");
               }
            else
               {
               printf(" ");
               }
            }
         else if (!(*si)->len)
            {
            /* This is the zero case.  For zero, there is only one line,
            ** and every character except the last one is a blank.
            */
            if (cur_digit_on_line == (digits_per_line - 1))
               {
               printf("0");
               }
            else
               {
               printf(" ");
               }
            }
         else
            {
            /* This is a valid number which is not zero.  Need to print
            ** the digits.
            */

            if (idx_into_string < (*si)->len)
               {
               printf("%c", (*si)->digits[idx_into_string]);
               }
            else
               {
               printf(" ");
               }
            } /* End of digit case.

         /* Now handle the commas.  The rules for commas are straightforward.
         **    a)NAN never has a comma.
         **    b)Zeros never have a comma.
         **    c)The final line, last digit never has a comma.
         **    d)Everything else in multiples of three ...
         */
         if (!(idx_into_string % 3) && (idx_into_string))
            {
            if ((*si)->nan)
               {
               printf(" ");
               }
            else if (!(*si)->len)
               {
               printf(" ");
               }
            else
               {
               if (idx_into_string < (*si)->len)
                  {
                  printf(",");
                  }
               else
                  {
                  printf(" ");
                  }
               }
            }
         } /* End for each digit on the current line. */
      
      /* For the first line, print out an informative message
      ** advising of the number of digits.  For all other lines
      ** print nothing.
      */
      if (!cur_line && !((*si)->nan))
         {
         if (nlines == 1)
            printf(" ");

         if ((*si)->len <= 1)
            {
            printf("  (    1 digit)\n");
            }
         else if ((*si)->len < 1000)
            {
            printf("  (%5u digits)\n", (*si)->len);
            }
         else
            {
            printf("  (%u,%03u digits)\n", (*si)->len / 1000, (*si)->len % 1000);
            }
         }
      else
         {
         printf("\n");
         }
      } /* End for each line. */
   }


/****************************************************************************/
/* siSetToLong():                                                           */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Sets a synthetic integer (which must already be created) to a long     */
/*   value.  This is used primarily in preliminary unit testing.            */
/*                                                                          */
/* INPUTS                                                                   */
/*   **si          :  The synthetic integer to operate on.                  */
/*                                                                          */
/*   val           :  The value to set the synthetic integer to.            */
/****************************************************************************/
void siSetToLong(SYNTHETIC_INTEGER **si, long val)
   {
   char buf[100];
   char *p;
   unsigned len;
   unsigned idx;

   asAssert(si != NULL, __LINE__); 
   asAssert(*si != NULL, __LINE__);

   sprintf(buf, "%ld", val);

   if (buf[0] == '-')
      p = buf+1;
   else
      p = buf;

   len = strlen(p);

   (*si)->nan = FALSE;

   if (val == 0)
      {
      (*si)->nan = FALSE;
      (*si)->neg = FALSE;
      (*si)->len = 0;
      (*si)->digits[0] = '\0';
      }
   else 
      {
      if (val < 0)
         {
         (*si)->neg = TRUE;
         }
      else
         {
         (*si)->neg = FALSE;
         }
        
      (*si)->len = len;

      for (idx=0; idx<len; idx++)
         {
         (*si)->digits[idx] = p[len - idx - 1];
         }

      (*si)->digits[len] = '\0';
      }
   }


/****************************************************************************/
/* siSetToNan():                                                            */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Sets a synthetic integer (which must already be created) to NAN (not   */
/*   a number).                                                             */
/*                                                                          */
/* INPUTS                                                                   */
/*   **si          :  The synthetic integer to set to NAN.                  */
/*                                                                          */
/* NOTES                                                                    */
/*   This program "evolved", and this function evolved after many of the    */
/*   functions that set a number to NAN.  There are may places in the code  */
/*   where an integer is set to NAN without the use of this function.       */
/****************************************************************************/
void siSetToNan(SYNTHETIC_INTEGER **si)
   {
   asAssert(si != NULL, __LINE__); 
   asAssert(*si != NULL, __LINE__);

   (*si)->digits[0] = '\0';
   (*si)->len       = 0;
   (*si)->nan       = TRUE;
   (*si)->neg       = FALSE;
   }


/****************************************************************************/
/* siSetToPowerOfTen():                                                     */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Sets a synthetic integer (which must already be created) to an         */
/*   integral power of ten.  This function is helpful for math in many      */
/*   cases.                                                                 */
/*                                                                          */
/* INPUTS                                                                   */
/*   **si          :  The synthetic integer to operate on.                  */
/*                                                                          */
/*   exp           :  The integral exponent value (non-negative).  For      */
/*                    example, a value of 0 here will result in the         */
/*                    assignment of 1, 1 here will result in the assignment */
/*                    of 10, 2 here will result in the assignment of 100.   */
/*                                                                          */
/* ERRORS                                                                   */
/*   A negative exponent will result in an assertion failure.  An exponent  */
/*   too large will result in the assignment of NAN.                        */
/*                                                                          */
/* NOTE                                                                     */
/*   This program "evolved", and this function evolved after many of the    */
/*   functions that set a number to a power of 10 "directly".  There may be */
/*   many places in the code where an integer is set to a power of 10       */
/*   without the use of this function.                                      */
/****************************************************************************/
void siSetToPowerOfTen(SYNTHETIC_INTEGER **si, int exp)
   {
   int i;

   asAssert(si != NULL, __LINE__); 
   asAssert(*si != NULL, __LINE__);
   asAssert(exp >= 0, __LINE__);

   if (exp < INTERMEDIATE_CALC_MAX_DIGITS)
      {
      (*si)->len = exp+1;
      (*si)->nan = FALSE;
      (*si)->neg = FALSE;
      (*si)->digits[exp+1] = '\0';
      (*si)->digits[exp] = '1';
      for (i=0; i<exp; i++)
         (*si)->digits[i] = '0';
      }
   else
      {
      siSetToNan(si);
      }
   }


/****************************************************************************/
/* siAddTwoNonnegative():                                                   */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Adds two synthetic integers which are guaranteed to be non-negative.   */
/*   The result may be set NAN if there is an overflow.  This is a low-     */
/*   level function called by other higher-level functions to do more       */
/*   complex arithmetic.                                                    */
/*                                                                          */
/* INPUTS                                                                   */
/*   **arg1, **arg2  :  The two operands to add.  Both operands must be     */
/*                      non-negative.  It is legal for both SI's to         */
/*                      use the same storage or to be the same variable.    */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **result        :  The synthetic integer where the output result is    */
/*                      placed.  This may be the same SI as either or both  */
/*                      of the inputs.                                      */
/****************************************************************************/
void siAddTwoNonnegative(SYNTHETIC_INTEGER **arg1,
                         SYNTHETIC_INTEGER **arg2,
                         SYNTHETIC_INTEGER **result)
   {
   SYNTHETIC_INTEGER *callers_orig_value = NULL;
   unsigned i;
   unsigned len1, len2, lenmax;
   char carry;
   char operand1, operand2, digitresult;

   /* Be sure the caller isn't doing anything silly. */
   asAssert(arg1 != NULL, __LINE__); 
   asAssert(*arg1 != NULL, __LINE__);
   asAssert(!((*arg1)->neg), __LINE__);
   asAssert(arg2 != NULL, __LINE__); 
   asAssert(*arg2 != NULL, __LINE__);
   asAssert(!((*arg2)->neg), __LINE__);
   asAssert(result != NULL, __LINE__); 
   asAssert(*result != NULL, __LINE__);
   asAssert((arg1 != arg2) && (arg2 != result) && (result != arg1), __LINE__);

   /* If either input is NAN, the output is NAN by definition.
   */
   if (((*arg1)->nan) || ((*arg2)->nan))
      {
      (*result)->nan = TRUE;
      }
   else
      {
      /* The two input arguments don't matter because they aren't written,
      ** but if the caller has allowed the result to be the same as the 
      ** either or both of the two inputs, must use a different memory
      ** location.  However, only do this if need to, as will slow things
      ** down to create and destroy.
      */
      if ((*arg1 == *result) || (*arg2 == *result))
         {
         /* Caller has allowed result to be the same as either
         ** or both inputs.  Must replace caller's pointer temporarily.
         */
         callers_orig_value = *result;
         siCreate(result);
         }

      /* Zero out the potential result.
      */
      (*result)->neg = FALSE;
      (*result)->nan = FALSE;
      (*result)->len = 0;
      (*result)->digits[0] = '\0';

      /* Buffer important handy values.
      */
      len1 = (*arg1)->len;
      len2 = (*arg2)->len;
      lenmax = ddUmax(len1, len2);

      /* Be absolutely sure that both lengths are permissible values.  Memory
      ** reference errors can be hard to track down.
      */
      asAssert(lenmax <= INTERMEDIATE_CALC_MAX_DIGITS, __LINE__);

      /* Start off with an LSD carry input of '0', as there is no carry into the
      ** first digit.
      */
      carry = '0';

      /* Iterate through, performing the addition, character by character.
      ** characters that are unpopulated are treated as zero.
      */
      for (i=0; i<lenmax; i++)
         {
         /* Grab the right character from the arguments. */
         if (i < len1)
            operand1 = (*arg1)->digits[i];
         else
            operand1 = '0';
         if (i < len2)
            operand2 = (*arg2)->digits[i];
         else
            operand2 = '0';

         /* Perform the actual addition.  Note that the carry value is copied
         ** copied onto the stack for the function call, so carry can double
         ** as both input and output.
         */
         ddFundamentalAdditionCell(operand1, operand2, carry, &digitresult, &carry);         

         /* Stuff the result digit in the right place. */
         (*result)->digits[i] = digitresult;
         }

      /* After we're out of the loop, there are a few possible outcomes.  If the
      ** carry is zero, then there is no risk of any kind of overflow.
      */
      if (carry == '0')
         {
         /* No risk of overflow. */
         (*result)->digits[i] = '\0';
         (*result)->len = i;
         }
      else
         {
         /* carry == '1' */
         /* There are two possibilities here.  Either the result has grown one
         ** digit more than the longest input operand, and this is legal, or the
         ** result has grown one digit more and there is an overflow,
         ** forcing declaration of a NAN.
         */
         if (i == INTERMEDIATE_CALC_MAX_DIGITS)
            {
            (*result)->nan = TRUE;
            (*result)->len = 0;
            (*result)->digits[0] = '\0';
            }
         else
            {
            (*result)->len = i+1;
            (*result)->digits[i] = carry;
            (*result)->digits[i+1] = '\0';
            }
         }

      /* If it was necessary to evacuate the caller's result area, swap it back
      ** and deallocate memory.
      */
      if (callers_orig_value)
         {
         siCopy(result, &callers_orig_value);
         siDestroy(result);
         *result = callers_orig_value;
         }
      }
   }


/****************************************************************************/
/* siSubtractToProduceNonnegativeResult():                                  */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Subtracts two synthetic integers, with the understanding that the      */
/*   result will be non-negative.  This function is used as a building      */
/*   block for subtraction which can span zero.                             */
/*                                                                          */
/* INPUTS                                                                   */
/*   **arg1, **arg2  :  The two operands to subtract.  Both must be non-    */
/*                      negative.                                           */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **result        :  **arg1 - **arg2, or a fatal error if the result     */
/*                      would be negative.                                  */
/****************************************************************************/
void siSubtractToProduceNonnegativeResult(SYNTHETIC_INTEGER **arg1,
                                          SYNTHETIC_INTEGER **arg2,
                                          SYNTHETIC_INTEGER **result)
   {
   SYNTHETIC_INTEGER *callers_orig_value = NULL;
   unsigned i;
   unsigned len;
   char borrow;
   char operand1, operand2, digitresult;

   /* Be sure the caller isn't doing anything silly. */
   asAssert(arg1 != NULL, __LINE__); 
   asAssert(*arg1 != NULL, __LINE__);
   asAssert(!((*arg1)->neg), __LINE__);
   asAssert(arg2 != NULL, __LINE__); 
   asAssert(*arg2 != NULL, __LINE__);
   asAssert(!((*arg2)->neg), __LINE__);
   asAssert(result != NULL, __LINE__); 
   asAssert(*result != NULL, __LINE__);
   asAssert((arg1 != arg2) && (arg2 != result) && (result != arg1), __LINE__);

   /* If either input is NAN, the output is NAN by definition.
   */
   if (((*arg1)->nan) || ((*arg2)->nan))
      {
      (*result)->nan = TRUE;
      }
   else
      {
      /* The two input arguments don't matter because they aren't written,
      ** but if the caller has allowed the result to be the same as the 
      ** either or both of the two inputs, must use a different memory
      ** location.  However, only do this if need to, as will slow things
      ** down to create and destroy.
      */
      if ((*arg1 == *result) || (*arg2 == *result))
         {
         /* Caller has allowed result to be the same as either
         ** or both inputs.  Must replace caller's pointer temporarily.
         */
         callers_orig_value = *result;
         siCreate(result);
         }

      /* Zero out the potential result.
      */
      (*result)->neg = FALSE;
      (*result)->nan = FALSE;
      (*result)->len = 0;
      (*result)->digits[0] = '\0';

      /* Buffer important handy values.
      */
      len = (*arg1)->len;  /* By definition, this one is the max. */

      /* Be absolutely sure that the length used for iteration is a 
      ** permissible value.
      */
      asAssert(len <= INTERMEDIATE_CALC_MAX_DIGITS, __LINE__);

      /* Start off with an LSD borrow input of '0', as there is no borrow into the
      ** first digit.
      */
      borrow = '0';

      /* Iterate through, performing the subtraction, character by character.
      ** Characters that are unpopulated are treated as zero.
      */
      for (i=0; i<len; i++)
         {
         /* Grab the right character from the arguments. */
         operand1 = (*arg1)->digits[i];
         if (i < (*arg2)->len)
            operand2 = (*arg2)->digits[i];
         else
            operand2 = '0';

         /* Perform the actual subtraction.  Note that the borrow value is
         ** copied onto the stack for the function call, so double can double
         ** as both input and output.
         */
         /* printf("Idx: %u, borrow in: %c, ", i, borrow); */

         ddFundamentalSubtractionCell(operand1, operand2, borrow, &digitresult, &borrow);         

         /* printf("op1: %c, op2: %c, borrow out: %c, result out: %c.\n", 
                operand1,
                operand2,
                borrow,
                digitresult); */

         /* Stuff the result digit in the right place. */
         (*result)->digits[i] = digitresult;
         }

      /* Trim the leading zeros from the subtraction result.  It would be more
      ** elegant to just identify the ripstop during the subtraction, but
      ** this will work, too.
      */
      if (!i)
         {
         /* We had a 0-0 subtraction. */
         (*result)->digits[0] = '\0';
         (*result)->len = 0;
         }
      else
         {
         (*result)->digits[i] = '\0';
         (*result)->len = i;
         while ((i >= 1) && ((*result)->digits[i-1] == '0'))
            {
            (*result)->digits[i-1] = '\0';
            (*result)->len = i-1;
            i--;
            }
         }

      /* If it was necessary to evacuate the caller's result area, swap it back
      ** and deallocate memory.
      */
      if (callers_orig_value)
         {
         siCopy(result, &callers_orig_value);
         siDestroy(result);
         *result = callers_orig_value;
         }
      }
   }


/****************************************************************************/
/* siUnrestrictedAddition():                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Adds two integers of any sign.  NAN is produced if anything overflows. */
/*                                                                          */
/* INPUTS                                                                   */
/*   **arg1, **arg2  :  The two synthetic integer operand to add.  It is    */
/*                      permitted for both to point to the same place.      */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **result        :  The result.  This may point to the same place as    */
/*                      either or both of arg1, arg2.                       */
/****************************************************************************/
void siUnrestrictedAddition(SYNTHETIC_INTEGER **arg1,
                            SYNTHETIC_INTEGER **arg2,
                            SYNTHETIC_INTEGER **result)
   {
   SYNTHETIC_INTEGER *callers_orig_value = NULL;
   int arg1_rel_arg2;
   unsigned arg1_is_neg;
   unsigned arg2_is_neg;
   unsigned case_number;

   /* Be sure the caller isn't doing anything silly. Because double-
   ** indirection is involved, another word of explanation is needed.
   ** The caller is passing a pointer to his pointer.  This isn't necessary
   ** in this circumstance (we'll never need to reallocate his object, for
   ** example), but it is just simpler to keep everthing consistent 
   ** throughout the program.  When I say that the caller can have pointers
   ** the same for the args and the result, I mean that the caller can have
   ** separate physical pointers which point to the same thing.  However, the
   ** caller may not have one physical pointer only and pass us three identical
   ** pointers to the same physical pointer.  This is illegal.  The caller must
   ** have three seperate pointers, even if they point to the same place.
   */
   asAssert(arg1 != NULL, __LINE__); 
   asAssert(*arg1 != NULL, __LINE__);
   asAssert(arg2 != NULL, __LINE__); 
   asAssert(*arg2 != NULL, __LINE__);
   asAssert(result != NULL, __LINE__); 
   asAssert(*result != NULL, __LINE__);
   asAssert((arg1 != arg2) && (arg2 != result) && (result != arg1), __LINE__);

   /* The two input arguments don't matter because they aren't written,
   ** but if the caller has allowed the result to be the same as the 
   ** either or both of the two inputs, must use a different memory
   ** location.  However, only do this if need to, as will slow things
   ** down to create and destroy.
   */
   if ((*arg1 == *result) || (*arg2 == *result))
      {
      /* Caller has allowed result to be the same as either
      ** or both inputs.  Must replace caller's pointer temporarily.
      */
      callers_orig_value = *result;
      siCreate(result);
      }

   /* Zero out the potential result.
   */
   (*result)->neg = FALSE;
   (*result)->nan = FALSE;
   (*result)->len = 0;
   (*result)->digits[0] = '\0';

   /* If either operand is NAN, the result is NAN.  That is all the
   ** needs to be said.
   */
   if (((*arg1)->nan) || ((*arg2)->nan))
      {
      (*result)->nan = TRUE;
      }
   else
      {
      /* Gather some vital statistics about the two numbers passed.  These
      ** will be used to break into cases.
      */
      arg1_rel_arg2 = siCompareAbs(arg1, arg2) + 1;
      arg1_is_neg   = (*arg1)->neg;
      arg2_is_neg   = (*arg2)->neg;

      /* Zero out the signs of the two numbers.  They will be restored
      ** later.
      */
      (*arg1)->neg = FALSE;
      (*arg2)->neg = FALSE;
   
      /* Create a case number based on the above examination.  It is easier
      ** to do it this way so there is only one switch statement.
      */
      case_number =   ((unsigned)arg1_rel_arg2 * 4)
                  + arg1_is_neg * 2
                  + arg2_is_neg;
   
      /* printf("Case number: %u.\n", case_number); */

      switch(case_number)
         {
         /*********************************************************************/
         case 0:
            /* abs(arg1) < abs(arg2)  */
            /* arg1 >= 0              */
            /* arg2 >= 0              */
            /* Both arguments were non-negative.  The result will be non-
            ** negative, perhaps NAN.  Just add the two numbers, perhaps
            ** resulting in NAN.
            */
            siAddTwoNonnegative(arg1, arg2, result);
            break;
         /*********************************************************************/
         case 1:
            /* abs(arg1) < abs(arg2)  */
            /* arg1 >= 0              */
            /* arg2 < 0               */
            /* arg2 is negative, and will overwhelm arg1 and produce a negative
            ** result.  Get the positive result and flip the sign.
            */
            siSubtractToProduceNonnegativeResult(arg2, arg1, result);
            if (!((*result)->nan))
               (*result)->neg = TRUE;
            break;
         /*********************************************************************/
         case 2:
            /* abs(arg1) < abs(arg2)  */
            /* arg1 < 0               */
            /* arg2 >= 0              */
            /* Result will be positive, dominated by arg2. */
            siSubtractToProduceNonnegativeResult(arg2, arg1, result);
            break;
         /*********************************************************************/
         case 3:
            /* abs(arg1) < abs(arg2)  */
            /* arg1 < 0               */
            /* arg2 < 0               */
            /* arg1 and arg2 both negative.  Add them in a positive sense and
            ** negate the result.
            */
            siAddTwoNonnegative(arg1, arg2, result);
            if (!((*result)->nan))
               (*result)->neg = TRUE;
            break;
         /*********************************************************************/
         case 4:
            /* abs(arg1) == abs(arg2) */
            /* arg1 >= 0              */
            /* arg2 >= 0              */
            /* Two are equal and non-negative.  Just add. 
            */
            siAddTwoNonnegative(arg1, arg2, result);
            break;
         /*********************************************************************/
         case 5:
            /* abs(arg1) == abs(arg2) */
            /* arg1 >= 0              */
            /* arg2 < 0               */
            /* Result is zero.  Just leave the result the way it is, as we
            ** set the result to zero higher up in the code.
            */
            break;
         /*********************************************************************/
         case 6:
            /* abs(arg1) == abs(arg2) */
            /* arg1 < 0               */
            /* arg2 >= 0              */
            /* Result is zero.  Just leave the result the way it is, as we
            ** set the result to zero higher up in the code.
            */
            break;
         /*********************************************************************/
         case 7:
            /* abs(arg1) == abs(arg2) */
            /* arg1 < 0               */
            /* arg2 < 0               */
            /* Two are equal and negative.  Add and negate.
            */
            siAddTwoNonnegative(arg1, arg2, result);
            if (!((*result)->nan))
               (*result)->neg = TRUE;
            break;
         /*********************************************************************/
         case 8:
            /* abs(arg1) > abs(arg2)  */
            /* arg1 >= 0              */
            /* arg2 >= 0              */
            /* Both non-negative.  Just add.
            */
            siAddTwoNonnegative(arg1, arg2, result);
            break;
         /*********************************************************************/
         case 9:
            /* abs(arg1) > abs(arg2)  */
            /* arg1 >= 0              */
            /* arg2 < 0               */
            /* Result is positive and driven by arg1.  Subtract. */
            siSubtractToProduceNonnegativeResult(arg1, arg2, result);
            break;
         /*********************************************************************/
         case 10:
            /* abs(arg1) > abs(arg2)  */
            /* arg1 < 0               */
            /* arg2 >= 0              */
            /* Result is negative and driven by arg1.  Subtract and negate.
            */
            siSubtractToProduceNonnegativeResult(arg1, arg2, result);
            if (!((*result)->nan))
               (*result)->neg = TRUE;
            break;
         /*********************************************************************/
         case 11:
            /* abs(arg1) > abs(arg2)  */
            /* arg1 < 0               */
            /* arg2 < 0               */
            /* Result is negative.  Add and negate.
            */
            siAddTwoNonnegative(arg1, arg2, result);
            if (!((*result)->nan))
               (*result)->neg = TRUE;
            break;
         /*********************************************************************/
         default:
            /* Should never be here.  Fatal out. */
            asAssert(0, __LINE__); 
            break;
         /*********************************************************************/
         }
      
      /* Restore the results of the input arguments.  We will really mess up
      ** the caller if we don't.
      */
      (*arg1)->neg = arg1_is_neg;
      (*arg2)->neg = arg2_is_neg;
      }


   /* If it was necessary to evacuate the caller's result area, swap it back
   ** and deallocate memory.
   */
   if (callers_orig_value)
      {
      siCopy(result, &callers_orig_value);
      siDestroy(result);
      *result = callers_orig_value;
      }
   }

/****************************************************************************/
/* siUnrestrictedSubtraction():                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Subtracts two integers of any sign.  NAN is produced if anything       */
/*   overflows.                                                             */
/*                                                                          */
/* INPUTS                                                                   */
/*   **arg1, **arg2  :  The two synthetic integer operand to subtract.      */
/*                      Both may point to the same place.                   */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **result        :  The result, arg1-arg2.  May point to the same       */
/*                      place as either or both of arg1, arg2.              */
/****************************************************************************/
void siUnrestrictedSubtraction(SYNTHETIC_INTEGER **arg1,
                               SYNTHETIC_INTEGER **arg2,
                               SYNTHETIC_INTEGER **result)
   {
   unsigned neg;

   /* Be sure the caller is doing nothing silly. */
   asAssert(arg1 != NULL, __LINE__); 
   asAssert(*arg1 != NULL, __LINE__);
   asAssert(arg2 != NULL, __LINE__); 
   asAssert(*arg2 != NULL, __LINE__);
   asAssert(result != NULL, __LINE__); 
   asAssert(*result != NULL, __LINE__);
   asAssert((arg1 != arg2) && (arg2 != result) && (result != arg1), __LINE__);

   /* If either operand is NAN, the result is NAN. */
   if ((*arg1)->nan || (*arg2)->nan)
      {
      (*result)->digits[0] = '\0';
      (*result)->len       = 0;
      (*result)->nan       = TRUE;
      (*result)->neg       = FALSE;
      }
   else
      {
      /* Subtraction is easy to express in terms of addition, since the
      ** addition function already handles both operands of both signs.
      */
      if ((*arg2)->len)  /* Can't negate zero in this way. */
         {
         neg = (*arg2)->neg;
         (*arg2)->neg = !((*arg2)->neg);
         }

      siUnrestrictedAddition(arg1, arg2, result);

      if ((*arg2)->len)
         (*arg2)->neg = neg;
      }
   }


/****************************************************************************/
/* siUnrestrictedMultiplication():                                          */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Muiltiplies two integers of any sign.  NAN is produced if anything     */
/*   overflows.                                                             */
/*                                                                          */
/* INPUTS                                                                   */
/*   **arg1, **arg2  :  The two synthetic integer operands to multiply.     */
/*                      Both may point to the same place.                   */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **result        :  The result, arg1*arg2.  May point to the same       */
/*                      place as either or both of arg1, arg2.              */
/****************************************************************************/
void siUnrestrictedMultiplication(SYNTHETIC_INTEGER **arg1,
                                  SYNTHETIC_INTEGER **arg2,
                                  SYNTHETIC_INTEGER **result)
   {
   /* Be sure the caller is doing nothing silly. */
   asAssert(arg1 != NULL, __LINE__); 
   asAssert(*arg1 != NULL, __LINE__);
   asAssert(arg2 != NULL, __LINE__); 
   asAssert(*arg2 != NULL, __LINE__);
   asAssert(result != NULL, __LINE__); 
   asAssert(*result != NULL, __LINE__);
   asAssert((arg1 != arg2) && (arg2 != result) && (result != arg1), __LINE__);

   /* If either argument is NAN, the result is NAN. 
   */
   if ((*arg1)->nan || (*arg2)->nan)
      {
      (*result)->digits[0] = '\0';
      (*result)->len       = 0;
      (*result)->nan       = TRUE;
      (*result)->neg       = FALSE;
      }
   /* If either argument is zero, result is zero. */
   else if (!((*arg1)->len) || !((*arg2)->len))
      {
      (*result)->digits[0] = '\0';
      (*result)->len       = 0;
      (*result)->nan       = FALSE;
      (*result)->neg       = FALSE;
      }
   else
      {
      /* We have two non-zero operands, fit to be multiplied.
      */
      SYNTHETIC_INTEGER *rt, *temp, *rt2;
      int cidx, len;
      char     cur_digit;
      unsigned negarg1, negarg2;

      /* Must save the signs of the arguments and restore. */
      negarg1 = (*arg1)->neg;
      negarg2 = (*arg2)->neg;
      (*arg1)->neg = FALSE;
      (*arg2)->neg = FALSE;

      /* Create (allocate) a synthetic integer to contain the result
      ** that will be returned to the caller.
      */
      siCreate(&rt);

      /* Must create an alias.  The reasons for this are complex.  I coded
      ** myself into a corner and have to live with it.
      */
      rt2 = rt;

      /* Create (allocate) a synthetic integer that will be used to hold
      ** the result of multiplying arg2 by a digit.
      */
      siCreate(&temp);

      /* Go through, multiplying in much the same way as one would by hand.
      */
      len = (*arg1)->len;

      for (cidx = len-1; cidx >= 0; cidx--)
         {
         #if 0
         printf("cidx: %d\n", cidx);
         printf("rt before * 10 multiply\n");
         siDump(&rt, "rt before");
         /* Multiply the pending result by 10 */
         #endif
         siMulByTen(&rt);
         /* siDump(&rt, "rt after"); */

         /* Grab the current digit of interest and multiply arg2 by it. */
         cur_digit = (*arg1)->digits[cidx];
         /* printf("cur digit: %c\n", cur_digit); */

         siCopy(arg2, &temp);
         /* siDump(&temp, "copy of arg2"); */
         siMulByDigit(&temp, cur_digit);
         /* siDump(&temp, "arg2 * digit"); */

         /* Add the result of the multiplication to the pending
         ** result.
         */
         siUnrestrictedAddition(&rt2, &temp, &rt);

         #if 0
         siDump(&rt2, "rt2");
         siDump(&rt, "rt");
         siDump(&temp, "temp");
         #endif
         }

      /* We're done with the mathematical operation.  Signs should be a self-
      ** healing matter.
      */
      /* Copy the result back to caller's area. */
      siCopy(&rt, result);

      /* Destroy temporary areas. */
      siDestroy(&rt);
      siDestroy(&temp);

      /* Restore the signs of the integers that were arguments, then the
      ** sign of the result.
      */
      (*arg1)->neg = negarg1;
      (*arg2)->neg = negarg2;

      if ((negarg1 && negarg2) || (!negarg1 && !negarg2))
         (*result)->neg = FALSE;
      else
         (*result)->neg = TRUE;

      /* siDump(result, "result"); */
      }
   }


/****************************************************************************/
/* siUnrestrictedDivision():                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Divides two synthetic integers of any sign, producing an integer       */
/*   quotient and integer remainder.  NAN is assigned to both the quotient  */
/*   and remainder on invalid inputs.  NAN due to overflow is not possible  */
/*   in this function, as any integer divided by 1 or -1 yields an integer  */
/*   of the same magnitude.                                                 */
/*                                                                          */
/* INPUTS                                                                   */
/*   **dividend      :  The dividend of the division.  May be any value.    */
/*                                                                          */
/*   **divisor       :  The divisor of the division.  May be any value      */
/*                      except zero.                                        */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **quotient      :  The integer quotient of the division.  This should  */
/*                      behave identically to the C "/" operator when       */
/*                      applied to integers.                                */
/*                                                                          */
/*   **remainder     :  The remainder of the division.  This should behave  */
/*                      identically to the C "%" operator.  There was some  */
/*                      question in my mind about the best way to define a  */
/*                      remainder with a negative dividend or divisor, but  */
/*                      I simply used the behavior of the "%" operator in   */
/*                      C as a guide.                                       */
/*                                                                          */
/* USAGE NOTES                                                              */
/*   The functions in this program are inconsistent about whether they      */
/*   allow the inputs and the outputs to be pointers to the same memory     */
/*   locations, etc.  This program was constructed impromptu, and I made    */
/*   up the rules as I went along.  I've now decided that it isn't that     */
/*   useful to allow this, so for this function I'll require uniqueness     */
/*   between the four parameters.  This doesn't affect the correctness      */
/*   of the program--just its internal elegance.  These inconsistent        */
/*   decisions are not visible by using the program.                        */
/****************************************************************************/
void siUnrestrictedDivision(SYNTHETIC_INTEGER **dividend,
                            SYNTHETIC_INTEGER **divisor,
                            SYNTHETIC_INTEGER **quotient,
                            SYNTHETIC_INTEGER **remainder)
   {
   /* Be sure the caller is doing nothing silly. */
   /* No first- or second-level pointers may be NULL. */
   asAssert(dividend != NULL, __LINE__); 
   asAssert(*dividend != NULL, __LINE__);
   asAssert(divisor != NULL, __LINE__); 
   asAssert(*divisor != NULL, __LINE__);
   asAssert(quotient != NULL, __LINE__); 
   asAssert(*quotient != NULL, __LINE__);
   asAssert(remainder != NULL, __LINE__); 
   asAssert(*remainder != NULL, __LINE__);
   /* All pointers must be mutually exclusive. */
   asAssert((dividend != divisor) && (dividend != quotient) && (dividend != remainder), __LINE__);
   asAssert((*dividend != *divisor) && (*dividend != *quotient) && (*dividend != *remainder), __LINE__);
   asAssert((divisor != quotient) && (divisor != remainder), __LINE__);
   asAssert((*divisor != *quotient) && (*divisor != *remainder), __LINE__);
   asAssert(quotient != remainder, __LINE__);
   asAssert(*quotient != *remainder, __LINE__);

   /* If either argument is NAN, the results are NAN. Also, if the divisor is zero,
   ** that causes two NAN's, as well.
   */
   if ((*dividend)->nan || (*divisor)->nan || !((*divisor)->len))
      {
      (*quotient)->digits[0]  = '\0';
      (*quotient)->len        = 0;
      (*quotient)->nan        = TRUE;
      (*quotient)->neg        = FALSE;
      (*remainder)->digits[0] = '\0';
      (*remainder)->len       = 0;
      (*remainder)->nan       = TRUE;
      (*remainder)->neg       = FALSE;
      }
   /* Zero in the numerator always gets us zero on both outputs. 
   */
   else if (!((*dividend)->len))  
      {
      siSetToLong(quotient, 0);
      siSetToLong(remainder, 0);
      }
   /* Must do a legitimate long division.  We know for sure that
   ** both dividend and divisor are non-zero.
   */
   else
      {
      unsigned dividend_is_neg;
      unsigned divisor_is_neg;
         /* Signs of dividend and divisor, saved so we only
         ** operate on positive numbers.
         */
      int quotient_ndigits;
         /* The number of digits in the quotient.
         */
      int i;
         /* General-purpose iteration variable.
         */
      char j;
         /* Trial digit for trial multiplication.
         */
      SYNTHETIC_INTEGER *si_temp1 = NULL,
                        *si_temp2 = NULL,
                        *si_temp3 = NULL;
         /* Temporary large integers.  These need to be set
         ** to NULL here, because in the event of an
         ** error or unexpected condition, need to know
         ** which ones to release.
         */

      /* Remember and reset the signs of the passed dividend and 
      ** divisor.  It makes it simpler just to consider positive
      ** numbers.
      */
      dividend_is_neg  = (*dividend)->neg;
      divisor_is_neg   = (*divisor)->neg;
      (*dividend)->neg = 0;
      (*divisor)->neg  = 0;

      /* If the dividend is less (in magnitude) than the divisor,
      ** the quotient is zero and the remainder is the
      ** dividend.
      */
      if (siCompare(dividend, divisor) == -1)
         {
         siSetToLong(quotient, 0);
         siCopy(dividend, remainder);
         (*remainder)->neg = dividend_is_neg;
         }
      else
         {
         /* Allocate all of the temporary integers.
         ** Done all in one place to eliminate paths
         ** through the code where may allocate something
         ** already allocated and cause a memory leak.
         */
         siCreate(&si_temp1);
         siCreate(&si_temp2);
         siCreate(&si_temp3);

         /* Establish the number of digits in the
         ** quotient.  There is a window near the maximum
         ** number of digits where we won't be able to 
         ** successfully start the division because we
         ** can't form an upper bound which is a power
         ** of 10 times the divisor.  In this case,
         ** just return NAN.  This window won't be a problem
         ** in practice.  It could be worked around, but
         ** no need to close it.
         */
         siCopy(divisor, &si_temp1);
         siMulByTen(&si_temp1);
         quotient_ndigits = 1;
         while(siCompare(&si_temp1, dividend) <= 0)
            {
            siMulByTen(&si_temp1);
            if (si_temp1->nan)
               goto nan_return;
            quotient_ndigits++;
            }

         siDivByTen(&si_temp1);

         /* printf("quotient number of digits: %d\n",
                quotient_ndigits);
         siDump(&si_temp1, "trial divisor"); */

         /* We now know the number of digits that the
         ** quotient will contain.  We also know the
         ** starting point to use for trial subtraction.
         ** Count down from the highest order digit to the
         ** lowest-order digit, subtracting the maximum
         ** amount each time.
         */
         /* si_temp1 is the trial divisor reference
         ** copy. 
         */
         /* si_temp2 is a copy of the trial divisor,
         ** used to see what happens as we try multiplying
         ** by various trial digits.
         */
         /* remainder (in the caller's area) is used for
         ** staging the dividend after subtractions made.
         ** This will end up with the remainder in the
         ** end.
         */
         /* quotient (in the caller's area) contains the
         ** quotient.  We'll stage it directly there.
         */
         (*quotient)->len = (unsigned)quotient_ndigits;
         (*quotient)->digits[(*quotient)->len] = '\0';
         siCopy(dividend, remainder);

         /* For each digit in the result, going from most
         ** significant to least significant.
         */
         for (i=quotient_ndigits-1; i>=0; i--)
            {
            /* Try to find the largest digit for the spot
            ** that will not overflow the remainder.
            ** This is the right digit.
            */
            /* For each digit we might try.
            */
            for (j='0'; j<='9'; j++)
               {
               siCopy(&si_temp1, &si_temp2);
                  /* Buffer the value so we can do a trial
                  ** multiplication.
                  */
               siMulByDigit(&si_temp2, j);
                  /* Perform the trial multiplication
                  ** by a digit.
                  */
               siUnrestrictedSubtraction(remainder,
                                         &si_temp2,
                                         &si_temp3);
                  /* Perform a trial subtraction involving the trial
                  ** digit.
                  */

               /* We have success if what is left over after
               ** the trial subtraction is less than the
               ** trial divisor.
               */
               if (siCompare(&si_temp3, &si_temp1) < 0)
                  break;

               /* It is a fatal internal software error if
               ** we are at the digit '9' and the constraint
               ** still is not met.
               */
               asAssert(j != '9', __LINE__);
               } /* End for each possible digit. */

            /* OK, we have the digit, and it is in the 
            ** variable 'j'.  We also have the value
            ** we should subtract and the result.
            ** Stuff the digit, and the result.
            */
            (*quotient)->digits[i] = j;
            siCopy(&si_temp3, remainder);

            /* Divide the trial divisor by 10 for the
            ** next iteration.
            */
            siDivByTen(&si_temp1);
            } /* End for each digit position. */

         /* We now need to figure out what the sign
         ** of the quotient and the remainder are.
         */
         if ((dividend_is_neg && !divisor_is_neg) ||
            (!dividend_is_neg && divisor_is_neg))
            (*quotient)->neg = TRUE;
         else
            (*quotient)->neg = FALSE;

         if (dividend_is_neg && (*remainder)->len)
            (*remainder)->neg = TRUE;
         else
            (*remainder)->neg = FALSE;
         }

      goto normal_return;
      nan_return: ;
      /* This is the return point where the quotient
      ** and remainder are marked NAN.  Thank goodness
      ** they didn't forget about the "goto" in 'C'.
      */

      normal_return:
      /* Restore the signs of the input arguments.
      */
      (*dividend)->neg = dividend_is_neg;
      (*divisor)->neg  = divisor_is_neg;

      /* Deallocate all allocated memory.
      */
      if (si_temp1)
         siDestroy(&si_temp1);
      if (si_temp2)
         siDestroy(&si_temp2);
      if (si_temp3)
         siDestroy(&si_temp3);
      }
   }


/****************************************************************************/
/* siGcd():                                                                 */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Applies Euclid's algorithm to obtain the GCD of two positive integers. */
/*   Any unexpected input operands will generate a NAN for the GCD.         */
/*                                                                          */
/* INPUTS                                                                   */
/*   **arg1, arg2    :  The two positive integers whose GCD is to be found. */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **result        :  gcd(**arg1, **arg2).                                */
/****************************************************************************/
void siGcd(SYNTHETIC_INTEGER **arg1,
           SYNTHETIC_INTEGER **arg2,
           SYNTHETIC_INTEGER **result)
   {

   /* Be sure the caller isn't doing anything silly. */
   asAssert(arg1 != NULL, __LINE__); 
   asAssert(*arg1 != NULL, __LINE__);
   asAssert(arg2 != NULL, __LINE__); 
   asAssert(*arg2 != NULL, __LINE__);
   asAssert(result != NULL, __LINE__); 
   asAssert(*result != NULL, __LINE__);

   /* A NAN input or zero or negative integers gets a NAN result.
   */
   if ((*arg1)->nan || (*arg2)->nan || !(*arg1)->len || !(*arg2)->len
      || (*arg1)->neg || (*arg2)->neg)
      {
      (*result)->digits[0] = '\0';
      (*result)->len       = 0;
      (*result)->nan       = TRUE;
      (*result)->neg       = FALSE;
      }
   else
      {
      /* This algorithm is so well known and documented that I won't insult
      ** the reader with comments.
      */
      SYNTHETIC_INTEGER *h, *k, *q, *r;

      siCreate(&h);
      siCreate(&k);
      siCreate(&q);
      siCreate(&r);

      if (siCompare(arg1, arg2) == -1)
         {
         siCopy(arg1, &h);
         siCopy(arg2, &k);
         }
      else
         {
         siCopy(arg1, &k);
         siCopy(arg2, &h);
         }

      siCopy(&h, &r);

      do 
         {
         siCopy(&r, result);
         siUnrestrictedDivision(&h,&k,&q,&r);
         siCopy(&k, &h);
         siCopy(&r, &k);
         } while (r->len);

      siDestroy(&h);
      siDestroy(&k);
      siDestroy(&q);
      siDestroy(&r);
      }
   }

                             
/****************************************************************************/
/* siIntegerExponentiation():                                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Exponentiates one integer to the integral power of another.  The       */
/*   integer to be exponentiated may be of any sign, but the exponent must  */
/*   be non-negative.  Invalid or overflow conditions result in the         */
/*   assignment of NAN.                                                     */                       
/*                                                                          */
/* INPUTS                                                                   */
/*   **arg           :  Integer to be exponentiated.                        */
/*                                                                          */
/*   **exponent      :  Exponent to use.  Must be non-negative.             */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **result        :  The result, arg1**arg2.                             */
/*                                                                          */
/* NOTE                                                                     */
/*   In other functions (written chronologically earlier), it was allowed   */
/*   for the arguments and the result to be the same physical object.  This */
/*   didn't prove to be a useful feature, so it is disallowed in this       */
/*   function.                                                              */
/****************************************************************************/
void siIntegerExponentiation(SYNTHETIC_INTEGER **arg,
                             SYNTHETIC_INTEGER **exponent,
                             SYNTHETIC_INTEGER **result)
   {
   /* Be sure the caller is doing nothing silly. */
   asAssert(arg != NULL, __LINE__); 
   asAssert(*arg != NULL, __LINE__);
   asAssert(exponent != NULL, __LINE__); 
   asAssert(*exponent != NULL, __LINE__);
   asAssert(result != NULL, __LINE__); 
   asAssert(*result != NULL, __LINE__);
   asAssert((arg != exponent) && (exponent != result) && (result != arg), __LINE__);
   asAssert((*arg != *exponent) && (*exponent != *result) && (*result != *arg), __LINE__);

   /* If either argument is NAN, the result is NAN. */
   if (((*arg)->nan) || ((*exponent)->nan))
      {
      (*result)->digits[0] = '\0';
      (*result)->len       = 0;
      (*result)->nan       = TRUE;
      (*result)->neg       = FALSE;
      }
   /* If we're trying to raise 0 to the 0th power, this is a no-no,
   ** as well.
   */
   else if (!((*arg)->len) && !((*exponent)->len))
      {
      (*result)->digits[0] = '\0';
      (*result)->len       = 0;
      (*result)->nan       = TRUE;
      (*result)->neg       = FALSE;
      }
   /* A negative exponent is a no-no, as well.
   */
   else if ((*exponent)->neg)
      {
      (*result)->digits[0] = '\0';
      (*result)->len       = 0;
      (*result)->nan       = TRUE;
      (*result)->neg       = FALSE;
      }
   /* Zero to any power but zero is zero.
   */
   else if (!((*arg)->len))
      {
      siSetToLong(result, 0);
      }
   /* Any number but zero to the zeroth power is one. */
   else if (!((*exponent)->len))
      {
      siSetToLong(result, 1);
      }
   else
      {
      unsigned binary_exponent;
      SYNTHETIC_INTEGER *temp_si1, *result_copy1, *temp_si2, *temp_si3;

      /* Here we have a non-zero integer raised to a non-zero power.
      ** The best algorithm to do this is to examine the bit pattern
      ** corresponding to the exponent--we can generate arg**2,
      ** arg**4, arg**8, etc., just by repeatedly squaring it.  NAN's
      ** are picked up automatically.
      */
      /* First, it is convenient convert the exponent to an 
      ** unsigned integer, so we can examine the
      ** bit pattern directly.  Will agree that anything over
      ** 32000 is treated as 32000, to avoid platform issues.
      */
      siCreate(&temp_si1);
      siCreate(&temp_si2);
      siCreate(&temp_si3);
      siCreate(&result_copy1);

      siSetToLong(&temp_si1, 32000);

      if (siCompare(exponent, &temp_si1) > 0)
         {
         asFatal("exponent too large (max is 32,000)");
         }
      else
         {
         /* Must convert from the string representation
         ** buried in the synthetic integer to a binary
         ** unsigned integer.  This is a bit tricky because the
         ** string is in reverse order from the traditional.
         */
            {
            int sidx;

            sidx = (*exponent)->len - 1;
            binary_exponent = 0;

            while (sidx >= 0)
               {
               binary_exponent *= 10;
               binary_exponent += ddDigitToValue((*exponent)->digits[sidx]);
               sidx--;
               }
            }
         }

      /* Start off with a result of 1 */
      siSetToLong(result, 1);
      siSetToLong(&result_copy1, 1);

      /* Start off with arg**1 */
      siCopy(arg, &temp_si1);
      siCopy(arg, &temp_si2);
      siCopy(arg, &temp_si3);

      while (binary_exponent)
         {
         /* Multiply result by the working register iff we have a 1 as the
         ** LSB of the exponent. 
         */
         if (binary_exponent & 1)
            {
            siUnrestrictedMultiplication(
               &result_copy1, 
               &temp_si1,
               result);

            /* Clone out the result, because we're keeping an additional copy. */
            siCopy(result, &result_copy1);
            }


         /* Square the quantity cloned from the argument, and clone the copies
         ** back. 
         */
         siUnrestrictedMultiplication(
            &temp_si1, 
            &temp_si2,
            &temp_si3);
         siCopy(&temp_si3, &temp_si1);
         siCopy(&temp_si3, &temp_si2);

         /* Shift the exponent down one bit. */
         binary_exponent >>= 1;
         }

      /* Destroy all of the data structures created on the fly. */
      siDestroy(&temp_si1);
      siDestroy(&temp_si2);
      siDestroy(&temp_si3);
      siDestroy(&result_copy1);

      /* At this point the result should contain the right value and
      ** we should be ready to return.
      */
      }
   }


/****************************************************************************/
/****************************************************************************/
/**********   R A T I O N A L    N U M B E R    F U N C T I O N S   *********/
/****************************************************************************/
/****************************************************************************/
/* This section is reserved for functions which operate on rational numbers.
** For directness, rational numbers are represented as integer pairs (no
** sense adding more data structures to this program.
*/

/****************************************************************************/
/* rnSum():                                                                 */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Calculates the sum of two rational numbers, supplying the results in   */
/*   lowest terms.                                                          */
/*                                                                          */
/* INPUTS                                                                   */
/*   **h1_formal_par_in,                                                    */
/*   **k1_formal_par_in,                                                    */
/*   **h2_formal_par_in,                                                    */
/*   **k2_formal_par_in :  The numerators and denominators of the two       */
/*                         rational numbers to add.  Zero denominators      */
/*                         are not allowed, but duplicate pointers of all   */
/*                         types are.                                       */
/*   **h_result,                                                            */
/*   **k_result         :  The result, in lowest terms.  Zero is  repre-    */
/*                         sented canonically as 0/1.  The memory must be   */
/*                         allocated in the caller's area, and the two      */
/*                         data items must be distinct.                     */
/****************************************************************************/
void rnSum(SYNTHETIC_INTEGER **h1_formal_par_in,
           SYNTHETIC_INTEGER **k1_formal_par_in,
           SYNTHETIC_INTEGER **h2_formal_par_in,
           SYNTHETIC_INTEGER **k2_formal_par_in,
           SYNTHETIC_INTEGER **h_result,
           SYNTHETIC_INTEGER **k_result)
   {
   SYNTHETIC_INTEGER *arg1_h,
                     *arg1_k,
                     *arg2_h,
                     *arg2_k,
                     *common_denominator,
                     *arg1_numerator,
                     *arg2_numerator,
                     *cumulative_numerator,
                     *result_gcd,
                     *trash_remainder;

   unsigned is_neg = FALSE;

   /* Be sure the caller isn't doing anything silly with pointers.
   */
   asAssert(h1_formal_par_in != NULL, __LINE__);
   asAssert(*h1_formal_par_in != NULL, __LINE__);
   asAssert(k1_formal_par_in != NULL, __LINE__);
   asAssert(*k1_formal_par_in != NULL, __LINE__);
   asAssert(h2_formal_par_in != NULL, __LINE__);
   asAssert(*h2_formal_par_in != NULL, __LINE__);
   asAssert(k2_formal_par_in != NULL, __LINE__);
   asAssert(*k2_formal_par_in != NULL, __LINE__);
   asAssert(h_result != NULL, __LINE__);
   asAssert(*h_result != NULL, __LINE__);
   asAssert(k_result != NULL, __LINE__);
   asAssert(*k_result != NULL, __LINE__);
   asAssert(h_result != k_result, __LINE__);
   asAssert(*h_result != *k_result, __LINE__);

   /* Allocate space for temporary variables.
   */
   siCreate(&arg1_h);
   siCreate(&arg1_k);
   siCreate(&arg2_h);
   siCreate(&arg2_k);
   siCreate(&common_denominator);
   siCreate(&arg1_numerator);
   siCreate(&arg2_numerator);
   siCreate(&cumulative_numerator);
   siCreate(&result_gcd);
   siCreate(&trash_remainder);

   /* Copy over the formal parameters to local variables.  This
   ** means we can modify the inputs without worry.
   */
   siCopy(h1_formal_par_in, &arg1_h);
   siCopy(k1_formal_par_in, &arg1_k);
   siCopy(h2_formal_par_in, &arg2_h);
   siCopy(k2_formal_par_in, &arg2_k);

   /* If any of the four inputs are NAN, the results must be
   ** NAN.
   */
   if (arg1_h->nan || arg1_k->nan || arg2_h->nan || arg2_k->nan)
      {
      goto nan_return;
      }
   
   /* If either denominator is zero, the result is NAN.
   */
   if (!(arg1_k->len) || !(arg2_k->len))
      {
      goto nan_return;
      }

   /* Adjust the signs of the the arguments so that the denominators are
   ** always positive.
   */
   if (arg1_h->neg && arg1_k->neg)
      {
      arg1_h->neg = FALSE;
      arg1_k->neg = FALSE;
      }
   else if (!(arg1_h->neg) && arg1_k->neg)
      {
      arg1_h->neg = TRUE;
      arg1_k->neg = FALSE;
      }

   if (arg2_h->neg && arg2_k->neg)
      {
      arg2_h->neg = FALSE;
      arg2_k->neg = FALSE;
      }
   else if (!(arg2_h->neg) && arg2_k->neg)
      {
      arg2_h->neg = TRUE;
      arg2_k->neg = FALSE;
      }

   /* Calculate the common denominator.
   */
   siUnrestrictedMultiplication(&arg1_k, &arg2_k, &common_denominator);

   /* Calculate the arg1 numerator.
   */
   siUnrestrictedMultiplication(&arg1_h, &arg2_k, &arg1_numerator);

   /* Calculate the arg2 numerator.
   */
   siUnrestrictedMultiplication(&arg2_h, &arg1_k, &arg2_numerator);

   /* Add the numerators to get the additive result. */
   siUnrestrictedAddition(&arg1_numerator,
                          &arg2_numerator,
                          &cumulative_numerator);

   /* If we NAN'd out ... 
   */
   if (cumulative_numerator->nan)
      goto nan_return;

   /* If we've reached a result of zero, it won't be legal to form
   ** a gcd().  Assign the canonical form of zero.
   */
   if (!(cumulative_numerator->len))
      {
      siSetToLong(h_result, 0);
      siSetToLong(k_result, 1);
      goto normal_return;
      }

   /* Snatch the sign temporarily.
   */
   if (cumulative_numerator->neg)
      {
      is_neg = TRUE;
      cumulative_numerator->neg = FALSE;
      }

   /* Form the gcd. */
   siGcd(&cumulative_numerator, 
         &common_denominator,
         &result_gcd);

   /* Set the sign back. */
   cumulative_numerator->neg = is_neg;

   /* Divide both numerator and denominator by
   ** the gcd().
   */
   siUnrestrictedDivision(&cumulative_numerator,
                          &result_gcd, 
                          h_result,
                          &trash_remainder);
   siUnrestrictedDivision(&common_denominator,
                          &result_gcd, 
                          k_result,
                          &trash_remainder);

   goto normal_return;
   nan_return: ;
   siSetToNan(h_result);
   siSetToNan(k_result);
   normal_return: ;

   /* Destroy temporary variables.
   */
   siDestroy(&arg1_h);
   siDestroy(&arg1_k);
   siDestroy(&arg2_h);
   siDestroy(&arg2_k);
   siDestroy(&common_denominator);
   siDestroy(&arg1_numerator);
   siDestroy(&arg2_numerator);
   siDestroy(&cumulative_numerator);
   siDestroy(&result_gcd);
   siDestroy(&trash_remainder);
   }


/****************************************************************************/
/* rnDifference():                                                          */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Calculates the difference of two rational numbers, returning the       */
/*   results in lowest terms.                                               */
/*                                                                          */
/* INPUTS                                                                   */
/*   **h1_formal_par_in,                                                    */
/*   **k1_formal_par_in,                                                    */
/*   **h2_formal_par_in,                                                    */
/*   **k2_formal_par_in :  The numerators and denominators of the two       */
/*                         rational numbers to subtract.  Zero denominators */
/*                         are not allowed, but duplicate pointers of all   */
/*                         types are.                                       */
/*   **h_result,                                                            */
/*   **k_result         :  The result, in lowest terms.  Zero is  repre-    */
/*                         sented canonically as 0/1.  The memory must be   */
/*                         allocated in the caller's area, and the two      */
/*                         data items must be distinct.                     */
/****************************************************************************/
void rnDifference(SYNTHETIC_INTEGER **h1_formal_par_in,
                  SYNTHETIC_INTEGER **k1_formal_par_in,
                  SYNTHETIC_INTEGER **h2_formal_par_in,
                  SYNTHETIC_INTEGER **k2_formal_par_in,
                  SYNTHETIC_INTEGER **h_result,
                  SYNTHETIC_INTEGER **k_result)
   {
   SYNTHETIC_INTEGER *arg1_h,
                     *arg1_k,
                     *arg2_h,
                     *arg2_k,
                     *common_denominator,
                     *arg1_numerator,
                     *arg2_numerator,
                     *cumulative_numerator,
                     *result_gcd,
                     *trash_remainder;

   unsigned is_neg = FALSE;

   /* Be sure the caller isn't doing anything silly with pointers.
   */
   asAssert(h1_formal_par_in != NULL, __LINE__);
   asAssert(*h1_formal_par_in != NULL, __LINE__);
   asAssert(k1_formal_par_in != NULL, __LINE__);
   asAssert(*k1_formal_par_in != NULL, __LINE__);
   asAssert(h2_formal_par_in != NULL, __LINE__);
   asAssert(*h2_formal_par_in != NULL, __LINE__);
   asAssert(k2_formal_par_in != NULL, __LINE__);
   asAssert(*k2_formal_par_in != NULL, __LINE__);
   asAssert(h_result != NULL, __LINE__);
   asAssert(*h_result != NULL, __LINE__);
   asAssert(k_result != NULL, __LINE__);
   asAssert(*k_result != NULL, __LINE__);
   asAssert(h_result != k_result, __LINE__);
   asAssert(*h_result != *k_result, __LINE__);

   /* Allocate space for temporary variables.
   */
   siCreate(&arg1_h);
   siCreate(&arg1_k);
   siCreate(&arg2_h);
   siCreate(&arg2_k);
   siCreate(&common_denominator);
   siCreate(&arg1_numerator);
   siCreate(&arg2_numerator);
   siCreate(&cumulative_numerator);
   siCreate(&result_gcd);
   siCreate(&trash_remainder);

   /* Copy over the formal parameters to local variables.  This
   ** means we can modify the inputs without worry.
   */
   siCopy(h1_formal_par_in, &arg1_h);
   siCopy(k1_formal_par_in, &arg1_k);
   siCopy(h2_formal_par_in, &arg2_h);
   siCopy(k2_formal_par_in, &arg2_k);

   /* If any of the four inputs are NAN, the results must be
   ** NAN.
   */
   if (arg1_h->nan || arg1_k->nan || arg2_h->nan || arg2_k->nan)
      {
      goto nan_return;
      }

   /* If either denominator is zero, the result is NAN.
   */
   if (!(arg1_k->len) || !(arg2_k->len))
      {
      goto nan_return;
      }

   /* Adjust the signs of the the arguments so that the denominators are
   ** always positive.
   */
   if (arg1_h->neg && arg1_k->neg)
      {
      arg1_h->neg = FALSE;
      arg1_k->neg = FALSE;
      }
   else if (!(arg1_h->neg) && arg1_k->neg)
      {
      arg1_h->neg = TRUE;
      arg1_k->neg = FALSE;
      }

   if (arg2_h->neg && arg2_k->neg)
      {
      arg2_h->neg = FALSE;
      arg2_k->neg = FALSE;
      }
   else if (!(arg2_h->neg) && arg2_k->neg)
      {
      arg2_h->neg = TRUE;
      arg2_k->neg = FALSE;
      }

   /* Calculate the common denominator.
   */
   siUnrestrictedMultiplication(&arg1_k, &arg2_k, &common_denominator);

   /* Calculate the arg1 numerator.
   */
   siUnrestrictedMultiplication(&arg1_h, &arg2_k, &arg1_numerator);

   /* Calculate the arg2 numerator.
   */
   siUnrestrictedMultiplication(&arg2_h, &arg1_k, &arg2_numerator);

   /* Subtract the numerators to get the result. */
   siUnrestrictedSubtraction(&arg1_numerator,
                             &arg2_numerator,
                             &cumulative_numerator);

   /* If we NAN'd out ... 
   */
   if (cumulative_numerator->nan)
      goto nan_return;

   /* If we've reached a result of zero, it won't be legal to form
   ** a gcd().  Assign the canonical form of zero.
   */
   if (!(cumulative_numerator->len))
      {
      siSetToLong(h_result, 0);
      siSetToLong(k_result, 1);
      goto normal_return;
      }

   /* Snatch the sign temporarily.
   */
   if (cumulative_numerator->neg)
      {
      is_neg = TRUE;
      cumulative_numerator->neg = FALSE;
      }

   /* Form the gcd. */
   siGcd(&cumulative_numerator, 
         &common_denominator,
         &result_gcd);

   /* Set the sign back. */
   cumulative_numerator->neg = is_neg;

   /* Divide both numerator and denominator by
   ** the gcd().
   */
   siUnrestrictedDivision(&cumulative_numerator,
                          &result_gcd, 
                          h_result,
                          &trash_remainder);
   siUnrestrictedDivision(&common_denominator,
                          &result_gcd, 
                          k_result,
                          &trash_remainder);

   goto normal_return;
   nan_return: ;
   siSetToNan(h_result);
   siSetToNan(k_result);
   normal_return: ;

   /* Destroy temporary variables.
   */
   siDestroy(&arg1_h);
   siDestroy(&arg1_k);
   siDestroy(&arg2_h);
   siDestroy(&arg2_k);
   siDestroy(&common_denominator);
   siDestroy(&arg1_numerator);
   siDestroy(&arg2_numerator);
   siDestroy(&cumulative_numerator);
   siDestroy(&result_gcd);
   siDestroy(&trash_remainder);
   }


/****************************************************************************/
/* rnProduct():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Calculates the product of two rational numbers, returning the          */
/*   results in lowest terms.                                               */
/*                                                                          */
/* INPUTS                                                                   */
/*   **h1_formal_par_in,                                                    */
/*   **k1_formal_par_in,                                                    */
/*   **h2_formal_par_in,                                                    */
/*   **k2_formal_par_in :  The numerators and denominators of the two       */
/*                         rational numbers to multiply.  Zero denominators */
/*                         are not allowed, but duplicate pointers of all   */
/*                         types are.                                       */
/*   **h_result,                                                            */
/*   **k_result         :  The result, in lowest terms.  Zero is  repre-    */
/*                         sented canonically as 0/1.  The memory must be   */
/*                         allocated in the caller's area, and the two      */
/*                         data items must be distinct.                     */
/****************************************************************************/
void rnProduct(SYNTHETIC_INTEGER **h1_formal_par_in,
               SYNTHETIC_INTEGER **k1_formal_par_in,
               SYNTHETIC_INTEGER **h2_formal_par_in,
               SYNTHETIC_INTEGER **k2_formal_par_in,
               SYNTHETIC_INTEGER **h_result,
               SYNTHETIC_INTEGER **k_result)
   {
   SYNTHETIC_INTEGER *arg1_h,
                     *arg1_k,
                     *arg2_h,
                     *arg2_k,
                     *result_numerator,
                     *result_denominator,
                     *gcd,
                     *trash_remainder;

   unsigned is_neg = FALSE;

   /* Be sure the caller isn't doing anything silly with pointers.
   */
   asAssert(h1_formal_par_in != NULL, __LINE__);
   asAssert(*h1_formal_par_in != NULL, __LINE__);
   asAssert(k1_formal_par_in != NULL, __LINE__);
   asAssert(*k1_formal_par_in != NULL, __LINE__);
   asAssert(h2_formal_par_in != NULL, __LINE__);
   asAssert(*h2_formal_par_in != NULL, __LINE__);
   asAssert(k2_formal_par_in != NULL, __LINE__);
   asAssert(*k2_formal_par_in != NULL, __LINE__);
   asAssert(h_result != NULL, __LINE__);
   asAssert(*h_result != NULL, __LINE__);
   asAssert(k_result != NULL, __LINE__);
   asAssert(*k_result != NULL, __LINE__);
   asAssert(h_result != k_result, __LINE__);
   asAssert(*h_result != *k_result, __LINE__);

   /* Allocate space for temporary variables.
   */
   siCreate(&arg1_h);
   siCreate(&arg1_k);
   siCreate(&arg2_h);
   siCreate(&arg2_k);
   siCreate(&result_numerator);
   siCreate(&result_denominator);
   siCreate(&gcd);
   siCreate(&trash_remainder);

   /* Copy over the formal parameters to local variables.  This
   ** means we can modify the inputs without worry.
   */
   siCopy(h1_formal_par_in, &arg1_h);
   siCopy(k1_formal_par_in, &arg1_k);
   siCopy(h2_formal_par_in, &arg2_h);
   siCopy(k2_formal_par_in, &arg2_k);

   /* If any of the four inputs are NAN, the results must be
   ** NAN.
   */
   if (arg1_h->nan || arg1_k->nan || arg2_h->nan || arg2_k->nan)
      {
      goto nan_return;
      }

   /* If either denominator is zero, the result is NAN.
   */
   if (!(arg1_k->len) || !(arg2_k->len))
      {
      goto nan_return;
      }

   /* Carry out the multiplication of numerators and denominators to get
   ** the two products.
   */
   siUnrestrictedMultiplication(&arg1_h, &arg2_h, &result_numerator);
   siUnrestrictedMultiplication(&arg1_k, &arg2_k, &result_denominator);

   /* If either result is NAN, the results are NAN.
   */
   if (result_numerator->nan || result_denominator->nan)
      {
      goto nan_return;
      }

   /* If the numerator is zero, we must return canonical zero.
   */
   if (!(result_numerator->len))
      {
      siSetToLong(h_result, 0);
      siSetToLong(k_result, 1);
      goto normal_return;
      }

   /* We need to acquire the sign and make both results positive otherwise
   ** can't obtain the GCD.
   */
   if (result_numerator->neg)
      {
      is_neg = TRUE;
      result_numerator->neg = FALSE;
      }
   if (result_denominator->neg)
      {
      is_neg = !is_neg;
      result_denominator->neg = FALSE;
      }

   /* Form the gcd. */
   siGcd(&result_numerator, 
         &result_denominator,
         &gcd);

   /* Set the sign back. */
   result_numerator->neg = is_neg;

   /* Divide both numerator and denominator by
   ** the gcd().
   */
   siUnrestrictedDivision(&result_numerator,
                          &gcd, 
                          h_result,
                          &trash_remainder);
   siUnrestrictedDivision(&result_denominator,
                          &gcd, 
                          k_result,
                          &trash_remainder);

   goto normal_return;
   nan_return: ;
   siSetToNan(h_result);
   siSetToNan(k_result);
   normal_return: ;

   /* Destroy temporary variables.
   */
   siDestroy(&arg1_h);
   siDestroy(&arg1_k);
   siDestroy(&arg2_h);
   siDestroy(&arg2_k);
   siDestroy(&result_numerator);
   siDestroy(&result_denominator);
   siDestroy(&gcd);
   siDestroy(&trash_remainder);
   }


/****************************************************************************/
/* rnQuotient():                                                            */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Calculates the quotient of two rational numbers, returning the         */
/*   results in lowest terms.                                               */
/*                                                                          */
/* INPUTS                                                                   */
/*   **h1_formal_par_in,                                                    */
/*   **k1_formal_par_in,                                                    */
/*   **h2_formal_par_in,                                                    */
/*   **k2_formal_par_in :  The numerators and denominators of the two       */
/*                         rational numbers to divide.  Zero denominators   */
/*                         and zero divisors are not allowed, but duplicate */
/*                         pointers of all types are.                       */
/*   **h_result,                                                            */
/*   **k_result         :  The result, in lowest terms.  Zero is  repre-    */
/*                         sented canonically as 0/1.  The memory must be   */
/*                         allocated in the caller's area, and the two      */
/*                         data items must be distinct.                     */
/****************************************************************************/
void rnQuotient(SYNTHETIC_INTEGER **h1_formal_par_in,
                SYNTHETIC_INTEGER **k1_formal_par_in,
                SYNTHETIC_INTEGER **h2_formal_par_in,
                SYNTHETIC_INTEGER **k2_formal_par_in,
                SYNTHETIC_INTEGER **h_result,
                SYNTHETIC_INTEGER **k_result)
   {
   SYNTHETIC_INTEGER *arg1_h,
                     *arg1_k,
                     *arg2_h,
                     *arg2_k,
                     *result_numerator,
                     *result_denominator,
                     *gcd,
                     *trash_remainder;

   unsigned is_neg = FALSE;

   /* Be sure the caller isn't doing anything silly with pointers.
   */
   asAssert(h1_formal_par_in != NULL, __LINE__);
   asAssert(*h1_formal_par_in != NULL, __LINE__);
   asAssert(k1_formal_par_in != NULL, __LINE__);
   asAssert(*k1_formal_par_in != NULL, __LINE__);
   asAssert(h2_formal_par_in != NULL, __LINE__);
   asAssert(*h2_formal_par_in != NULL, __LINE__);
   asAssert(k2_formal_par_in != NULL, __LINE__);
   asAssert(*k2_formal_par_in != NULL, __LINE__);
   asAssert(h_result != NULL, __LINE__);
   asAssert(*h_result != NULL, __LINE__);
   asAssert(k_result != NULL, __LINE__);
   asAssert(*k_result != NULL, __LINE__);
   asAssert(h_result != k_result, __LINE__);
   asAssert(*h_result != *k_result, __LINE__);

   /* Allocate space for temporary variables.
   */
   siCreate(&arg1_h);
   siCreate(&arg1_k);
   siCreate(&arg2_h);
   siCreate(&arg2_k);
   siCreate(&result_numerator);
   siCreate(&result_denominator);
   siCreate(&gcd);
   siCreate(&trash_remainder);

   /* Copy over the formal parameters to local variables.  This
   ** means we can modify the inputs without worry.
   */
   siCopy(h1_formal_par_in, &arg1_h);
   siCopy(k1_formal_par_in, &arg1_k);
   siCopy(h2_formal_par_in, &arg2_h);
   siCopy(k2_formal_par_in, &arg2_k);

   /* If any of the four inputs are NAN, the results must be
   ** NAN.
   */
   if (arg1_h->nan || arg1_k->nan || arg2_h->nan || arg2_k->nan)
      {
      goto nan_return;
      }

   /* If either denominator is zero, the result is NAN.
   */
   if (!(arg1_k->len) || !(arg2_k->len))
      {
      goto nan_return;
      }

   /* Carry out the multiplication of numerators and denominators to get
   ** the two products.
   */
   siUnrestrictedMultiplication(&arg1_h, &arg2_k, &result_numerator);
   siUnrestrictedMultiplication(&arg1_k, &arg2_h, &result_denominator);

   /* If either result is NAN, the results are NAN.
   */
   if (result_numerator->nan || result_denominator->nan)
      {
      goto nan_return;
      }

   /* If the denominator of the result is zero, this is a no-no-NAN, too.
   */
   if (!(result_denominator->len))
      {
      goto nan_return;
      }

   /* If the numerator is zero, we must return canonical zero.
   */
   if (!(result_numerator->len))
      {
      siSetToLong(h_result, 0);
      siSetToLong(k_result, 1);
      goto normal_return;
      }

   /* We need to acquire the sign and make both results positive otherwise
   ** can't obtain the GCD.
   */
   if (result_numerator->neg)
      {
      is_neg = TRUE;
      result_numerator->neg = FALSE;
      }
   if (result_denominator->neg)
      {
      is_neg = !is_neg;
      result_denominator->neg = FALSE;
      }

   /* Form the gcd. */
   siGcd(&result_numerator, 
         &result_denominator,
         &gcd);

   /* Set the sign back. */
   result_numerator->neg = is_neg;

   /* Divide both numerator and denominator by
   ** the gcd().
   */
   siUnrestrictedDivision(&result_numerator,
                          &gcd, 
                          h_result,
                          &trash_remainder);
   siUnrestrictedDivision(&result_denominator,
                          &gcd, 
                          k_result,
                          &trash_remainder);

   goto normal_return;
   nan_return: ;
   siSetToNan(h_result);
   siSetToNan(k_result);
   normal_return: ;

   /* Destroy temporary variables.
   */
   siDestroy(&arg1_h);
   siDestroy(&arg1_k);
   siDestroy(&arg2_h);
   siDestroy(&arg2_k);
   siDestroy(&result_numerator);
   siDestroy(&result_denominator);
   siDestroy(&gcd);
   siDestroy(&trash_remainder);
   }


/****************************************************************************/
/* rnCanonize():                                                            */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Puts the rational number passed into a canonical form, which means:    */
/*      a)If either synthetic integer is NAN, both are marked NAN.          */
/*      b)If the denominator is zero, both synthetic integers are marked    */
/*        NAN.                                                              */
/*      c)If the number has a value of zero, it is set to the canonical     */
/*        form of 0/1.                                                      */
/*      d)If the number represents a positive value, the signs of both      */
/*        synthetic integers are set +.  If the number represents a         */
/*        negative value, the numerator will be set - and the denominator   */
/*        -.                                                                */
/*      e)Any g.c.d. will be removed so that the number is in lowest        */
/*        terms.                                                            */
/*                                                                          */
/* INPUTS (AND OUTPUTS)                                                     */
/*   **h_formal_par_in,                                                     */
/*   **k_formal_par_in  :  The numerator and denominator of the number to   */
/*                         operate on.                                      */
/****************************************************************************/
void rnCanonize(SYNTHETIC_INTEGER **h_formal_par_in,
                SYNTHETIC_INTEGER **k_formal_par_in)
   {
   int is_neg = FALSE;
   SYNTHETIC_INTEGER *gcd, *trash_remainder, *si_temp;

   /* Be sure the caller isn't doing anything silly with pointers.
   */
   asAssert(h_formal_par_in != NULL, __LINE__);
   asAssert(*h_formal_par_in != NULL, __LINE__);
   asAssert(k_formal_par_in != NULL, __LINE__);
   asAssert(*k_formal_par_in != NULL, __LINE__);
   asAssert(h_formal_par_in != k_formal_par_in, __LINE__);
   asAssert(*h_formal_par_in != *k_formal_par_in, __LINE__);

   /* Create the local integers.
   */
   siCreate(&gcd);
   siCreate(&trash_remainder);
   siCreate(&si_temp);

   /* If either input is NAN, must mark both NAN.
   */
   if ((*h_formal_par_in)->nan || (*k_formal_par_in)->nan)
      goto nan_return;

   /* If the denominator is zero, must also mark both NAN.
   */
   if (!((*k_formal_par_in)->len))
      goto nan_return;

   /* If the numerator is zero, the right answer is canonical zero, and
   ** must return canonical 0/1.
   */
   if (!((*h_formal_par_in)->len))
      goto zero_return;

   /* If we made it to this point, we have two non-zero integers, and the
   ** result will be non-zero.  Must canonize the sign and factor out
   ** any g.c.d.
   */
   if ((((*h_formal_par_in)->neg) && !((*k_formal_par_in)->neg)) 
      || 
      (!((*h_formal_par_in)->neg) && ((*k_formal_par_in)->neg)))
      {
      is_neg = TRUE;
      }

   (*h_formal_par_in)->neg = FALSE;
   (*k_formal_par_in)->neg = FALSE;

   siGcd(h_formal_par_in, k_formal_par_in, &gcd);

   siUnrestrictedDivision(h_formal_par_in, &gcd,
                          &si_temp, &trash_remainder);
   siCopy(&si_temp, h_formal_par_in);
   siUnrestrictedDivision(k_formal_par_in, &gcd,
                          &si_temp, &trash_remainder);
   siCopy(&si_temp, k_formal_par_in);

   if (is_neg)
      (*h_formal_par_in)->neg = TRUE;

   goto normal_return;
   nan_return: ;
      siSetToNan(h_formal_par_in);
      siSetToNan(k_formal_par_in);
      goto normal_return;
   zero_return:
      siSetToLong(h_formal_par_in, 0);
      siSetToLong(k_formal_par_in, 1);
      goto normal_return;
   normal_return: ;

   /* Destroy the local integers.
   */
   siDestroy(&gcd);
   siDestroy(&trash_remainder);
   siDestroy(&si_temp);
   }


/****************************************************************************/
/* rnCompare():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Compares two rational numbers to determine thier ranking on the number */
/*   line.                                                                  */
/*                                                                          */
/* INPUTS    .                                                              */
/*   **h_1, **k_1,                                                          */
/*   **h_2, **k_2  :  The two rational numbers to compare.  They are not    */
/*                    required to be in canonical form, but the             */
/*                    denominators may not be zero.                         */
/*                                                                          */
/* OUTPUT                                                                   */
/*   <--           :  -1 if h1/k1 < h2/k2                                   */
/*                     0 if h1/k1 = h2/k2                                   */
/*                     1 if h1/k1 > h2/k2                                   */
/****************************************************************************/
int rnCompare(SYNTHETIC_INTEGER **h_1,
              SYNTHETIC_INTEGER **k_1,
              SYNTHETIC_INTEGER **h_2,
              SYNTHETIC_INTEGER **k_2)
   {
   int rv=0;

   SYNTHETIC_INTEGER *h1, 
                     *k1, 
                     *h2, 
                     *k2, 
                     *left_cross_product, 
                     *right_cross_product;

   /* Be sure the caller isn't doing anything silly with pointers.
   */
   asAssert(h_1 != NULL, __LINE__);
   asAssert(*h_1 != NULL, __LINE__);
   asAssert(k_1 != NULL, __LINE__);
   asAssert(*k_1 != NULL, __LINE__);
   asAssert(h_2 != NULL, __LINE__);
   asAssert(*h_2 != NULL, __LINE__);
   asAssert(k_2 != NULL, __LINE__);
   asAssert(*k_2 != NULL, __LINE__);

   /* Allocate all of our temps.
   */
   siCreate(&h1);
   siCreate(&k1);
   siCreate(&h2);
   siCreate(&k2);
   siCreate(&left_cross_product);
   siCreate(&right_cross_product);

   /* Copy the formal parameters to the temps so we can mess
   ** around with them.
   */
   siCopy(h_1, &h1);
   siCopy(k_1, &k1);
   siCopy(h_2, &h2);
   siCopy(k_2, &k2);

   /* The denominators may not be zero.
   */
   asAssert((k1->len != 0) && (k2->len != 0) ,__LINE__);

   /* We need to normalize the signs on the two fractions.
   ** The cross-product inequality utilized breaks down
   ** if either denominator is negative.
   */
   if ((!(h1->neg) && (k1->neg)) || ((h1->neg) && !(k1->neg)))
      {
      h1->neg = TRUE;
      k1->neg = FALSE;
      }
   else
      {
      h1->neg = FALSE;
      k1->neg = FALSE;
      }

   if ((!(h2->neg) && (k2->neg)) || ((h2->neg) && !(k2->neg)))
      {
      h2->neg = TRUE;
      k2->neg = FALSE;
      }
   else
      {
      h2->neg = FALSE;
      k2->neg = FALSE;
      }

   /* Form the left cross-product and right cross-product.  If we get
   ** a NAN, we have to kill this function, as it would compromise
   ** the integrity of the program (there is no notion of NAN for a
   ** comparison result).
   */
   siUnrestrictedMultiplication(&h1, &k2, &left_cross_product);
   siUnrestrictedMultiplication(&h2, &k1, &right_cross_product);
   asAssert(!(left_cross_product->nan) && !(right_cross_product->nan), __LINE__);

   /* The comparison result is the same as the relationship between the
   ** two cross-products.  A few words should be said about this.
   **
   ** Let a/b and c/d be the two rational numbers.
   ** Assume that b>0 and d>0.
   ** ad < bc
   ** -> ad/b < c 
   ** ->a/b < c/d.
   ** and the same logic can be applied to the other relational
   ** operators.
   */
   rv = siCompare(&left_cross_product, &right_cross_product);

#if 0
   siDump(&left_cross_product, "left");
   siDump(&right_cross_product, "right");
#endif

   /* Destroy all of our temps.
   */
   siDestroy(&h1);
   siDestroy(&k1);
   siDestroy(&h2);
   siDestroy(&k2);
   siDestroy(&left_cross_product);
   siDestroy(&right_cross_product);

   /* Return the return value.
   */
   return(rv);
   }


/****************************************************************************/
/* rnDap():                                                                 */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Converts a rational number to an approximately equivalent value        */
/*   with a different denominator.  This functionality is the same as       */
/*   implemented by the DAP command.                                        */
/*                                                                          */
/* INPUTS    .                                                              */
/*   **h, **k      :  The rational number to represent differently.         */
/*                    The denominator may not be zero.                      */
/*                                                                          */
/*   **D           :  The new denominator.  May not be zero.                */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **N           :  The new numerator.                                    */
/****************************************************************************/
void rnDap(SYNTHETIC_INTEGER **h,
           SYNTHETIC_INTEGER **k,
           SYNTHETIC_INTEGER **N,
           SYNTHETIC_INTEGER **D)
   {
   SYNTHETIC_INTEGER *numerator_product,
                     *quotient,
                     *trash_remainder;

   /* Be sure the caller is doing nothing silly with pointers.
   */
   asAssert(h != NULL, __LINE__);
   asAssert(*h != NULL, __LINE__);
   asAssert(k != NULL, __LINE__);
   asAssert(*k != NULL, __LINE__);
   asAssert(N != NULL, __LINE__);
   asAssert(*N != NULL, __LINE__);
   asAssert(D != NULL, __LINE__);
   asAssert(*D != NULL, __LINE__);

   /* Allocate our locals.
   */
   siCreate(&numerator_product);
   siCreate(&quotient);
   siCreate(&trash_remainder);

   /* If anything is NAN, the result is necessarily NAN.
   */
   if ((*h)->nan || (*k)->nan || (*D)->nan)
      goto nan_return;

   /* If the old denominator is zero, the result is necessarily NAN.
   */
   if (!((*k)->len))
      goto nan_return;

   /* If the new denominator requested is zero, the result is necessarily NAN.
   */
   if (!((*D)->len))
      goto nan_return;

   /* Calculate the numerator as specified in the manual under the DAP
   ** command.
   */
   siUnrestrictedMultiplication(h, D, &numerator_product);

   /* Divide to get the value.
   */
   siUnrestrictedDivision(&numerator_product, k, &quotient, &trash_remainder);

   /* Copy to caller's area.
   */
   siCopy(&quotient, N);

   goto normal_return;
   nan_return:
   siSetToNan(N);
   normal_return: ;

   /* Destroy our locals. 
   */
   siDestroy(&numerator_product);
   siDestroy(&quotient);
   siDestroy(&trash_remainder);
   }


/****************************************************************************/
/* rnFareyTraverse():                                                       */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Uses the standard recursive formulas to traverse the Farey series      */
/*   in either direction.  Two successive terms, in lowest terms, are       */
/*   needed.                                                                */
/*                                                                          */
/* INPUTS    .                                                              */
/*   **h1in, **k1in:  The first rational number in the series of interest,  */
/*                    which must have a positive denominator and a non-     */
/*                    negative numerator.                                   */
/*                                                                          */
/*   **h2in, **k2in:  The second rational number in the series of interest, */
/*                    same rules as above and must be greater than first    */
/*                    term h1in/k1in.                                       */
/*                                                                          */
/*   **N           :  The order of the series to form.                      */
/*                                                                          */
/*   dir           :  (-1):  The series is advanced backwards.  r(2)=r(1),  */
/*                           and r(1) = new term < r(2).                    */
/*                    (+1):  The series is advanced forwards.  r(1)=r(2),   */
/*                           and r(2) = new term > r(1).                    */
/****************************************************************************/
void rnFareyTraverse(SYNTHETIC_INTEGER **h1in,
                     SYNTHETIC_INTEGER **k1in,
                     SYNTHETIC_INTEGER **h2in,
                     SYNTHETIC_INTEGER **k2in,
                     SYNTHETIC_INTEGER **N,
                     int                 dir)
   {
   SYNTHETIC_INTEGER *t1, *t2, *t3, *new_h, *new_k;

   /* Be sure the caller isn't doing anything silly with pointers.
   */
   asAssert(h1in != NULL, __LINE__);
   asAssert(*h1in != NULL, __LINE__);
   asAssert(k1in != NULL, __LINE__);
   asAssert(*k1in != NULL, __LINE__);
   asAssert(h2in != NULL, __LINE__);
   asAssert(*h2in != NULL, __LINE__);
   asAssert(k2in != NULL, __LINE__);
   asAssert(*k2in != NULL, __LINE__);
   asAssert(N != NULL, __LINE__);
   asAssert(*N != NULL, __LINE__);

   /* It is also critical that none of the pointers be duplicates,
   ** but this isn't checked.
   */

   /* Allocate local variables. 
   */
   siCreate(&t1);
   siCreate(&t2);
   siCreate(&t3);
   siCreate(&new_h);
   siCreate(&new_k);

   /* Split into cases based on the direction.
   */
   if (dir > 0)
      {
      /* Forward
      */
      /* Calculate the term floor((k[j-2] + N)/k[j-1]), which we'll need
      ** twice.  The result is left in "t2".
      */
      siUnrestrictedAddition(k1in, N, &t1);
      siUnrestrictedDivision(&t1, k2in, &t2, &t3);

      /* Multiply by h[j-1] and place in "t1".
      */
      siUnrestrictedMultiplication(&t2, h2in, &t1);

      /* Subtract off h[j-2] and this is our new h.
      */
      siUnrestrictedSubtraction(&t1, h1in, &new_h);

      /* Multiply intermediate term by k[j-1] and place in "t1".
      */
      siUnrestrictedMultiplication(&t2, k2in, &t1);

      /* Subtract off k[j-2] and this is our new k. 
      */
      siUnrestrictedSubtraction(&t1, k1in, &new_k);

      /* Place the new results. 
      */
      siCopy(h2in, h1in);
      siCopy(k2in, k1in);
      siCopy(&new_h, h2in);
      siCopy(&new_k, k2in);
      }
   else
      {
      /* Reverse:  steps symmetrical with forward.
      */
      siUnrestrictedAddition(k2in, N, &t1);
      siUnrestrictedDivision(&t1, k1in, &t2, &t3);
      siUnrestrictedMultiplication(&t2, h1in, &t1);
      siUnrestrictedSubtraction(&t1, h2in, &new_h);
      siUnrestrictedMultiplication(&t2, k1in, &t1);
      siUnrestrictedSubtraction(&t1, k2in, &new_k);

      /* Place the new results. 
      */
      siCopy(h1in, h2in);
      siCopy(k1in, k2in);
      siCopy(&new_h, h1in);
      siCopy(&new_k, k1in);
      }


   /* Destroy local variables.
   */
   siDestroy(&t1);
   siDestroy(&t2);
   siDestroy(&t3);
   siDestroy(&new_h);
   siDestroy(&new_k);
   }


/****************************************************************************/
/****************************************************************************/
/*******   C O N T I N U E D    F R A C T I O N    F U N C T I O N S   ******/
/****************************************************************************/
/****************************************************************************/
/* This section is reserved for functions which form and manipulate
** continued fractions and convergents.  Note that every number has at
** least a 0th order CF partial quotient and at least a 0th order
** convergent (the integer part).
*/
typedef struct 
   {
   SYNTHETIC_INTEGER *raw_numerator;
   SYNTHETIC_INTEGER *raw_denominator;
      /* The raw numerator and denominator passed to the function which
      ** calculates partial quotients and convergents.  This might
      ** not be in lowest terms.  No negative integers are allowed,
      ** and zero must be represented canonically as 0/(D>0).
      */
   SYNTHETIC_INTEGER *numerator;
   SYNTHETIC_INTEGER *denominator;
      /* The numerator and denominator, in lowest terms, of the 
      ** rational number whose continued fraction expansion we
      ** are forming.  No negative integers are allowed, and
      ** zero must be represented canonically as 0/1.
      */
   int n;
      /* The number of elements in the parallel arrays of partial
      ** quotients, etc., which are maintained.  This must be
      ** at least 1, which would mean that only the 0th-order
      ** items are filled in.
      */
   SYNTHETIC_INTEGER **a;
      /* Pointer to a dynamically allocated array of n pointers,
      ** each of which points to a synthetic integer.  This
      ** pointer may be shifted on any operation on this data
      ** structure (due to the behavior of "realloc()"), so 
      ** a caller should never retain internal pointers when
      ** making function calls which might resize anything
      ** internally in this data structure.  The same sizing arguments
      ** here apply to all the other parallel elements, so it won't
      ** be described again.
      */
   SYNTHETIC_INTEGER **p;
   SYNTHETIC_INTEGER **q;
      /* Convergents of continued fraction expansion of the
      ** rational number.
      */
   } CF_EXPANSION;


/****************************************************************************/
/* pqCreate():                                                              */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Creates the continued fraction partial quotient expansion of a non-    */
/*   negative rational number, and also creates the convergents.            */
/*                                                                          */
/* INPUTS                                                                   */
/*   **h_in                                                                 */
/*   **k_in          :  The numerator and denominator of the rational       */
/*                      number whose continued fraction expansion and       */
/*                      convergents to form.  Both must be positive.        */
/*                                                                          */
/*   **expansion     :  The continued fraction expansion and the            */
/*                      convergents.                                        */
/****************************************************************************/
void pqCreate(SYNTHETIC_INTEGER **h_in,
              SYNTHETIC_INTEGER **k_in,
              CF_EXPANSION      **expansion)
   {
   SYNTHETIC_INTEGER *dividend,
                     *divisor,
                     *quotient,
                     *remainder,
                     *p_k_minus_1,
                     *p_k_minus_2,
                     *q_k_minus_1,
                     *q_k_minus_2,
                     *si_temp1,
                     *si_temp2,
                     *si_temp3,
                     *si_temp4;

   /* Be sure that the caller isn't doing anything silly.
   */
   asAssert(h_in != NULL, __LINE__);
   asAssert(*h_in != NULL, __LINE__);
   asAssert(k_in != NULL, __LINE__);
   asAssert(*k_in != NULL, __LINE__);
   asAssert(expansion != NULL, __LINE__);

   /* The numerator and denominator in cannot be negative,
   ** and the denominator cannot be zero.
   */
   asAssert(!((*h_in)->neg), __LINE__);
   asAssert(!((*k_in)->neg), __LINE__);
   asAssert((*k_in)->len != 0, __LINE__);

   /* Allocate space for all of the temporary integers
   ** we use during the process of forming partial
   ** quotients and convergents.
   */
   siCreate(&dividend);
   siCreate(&divisor);
   siCreate(&quotient);
   siCreate(&remainder);
   siCreate(&p_k_minus_1);
   siCreate(&p_k_minus_2);
   siCreate(&q_k_minus_1);
   siCreate(&q_k_minus_2);
   siCreate(&si_temp1);
   siCreate(&si_temp2);
   siCreate(&si_temp3);
   siCreate(&si_temp4);

   /* printf("Entering function.\n"); */

   /* Allocate the memory for the head data block.
   */
   *expansion = maMalloc(sizeof(CF_EXPANSION));

   /* Set all of the data elements of the head data block
   ** to known default values.
   */
   (*expansion)->raw_numerator   = NULL;
   (*expansion)->raw_denominator = NULL;
   (*expansion)->numerator       = NULL;
   (*expansion)->denominator     = NULL;
   (*expansion)->n               = 0;
   (*expansion)->a               = NULL;
   (*expansion)->p               = NULL;
   (*expansion)->q               = NULL;

   /* Assign in the original raw numerator and
   ** denominator.
   */
   siCreate(&((*expansion)->raw_numerator));
   siCreate(&((*expansion)->raw_denominator));
   siCopy(h_in, &((*expansion)->raw_numerator));
   siCopy(k_in, &((*expansion)->raw_denominator));

   /* Allocate the space for the lowest-terms numerator
   ** and denominator, but let them be zero for now.
   */
   siCreate(&((*expansion)->numerator));
   siCreate(&((*expansion)->denominator));

   /* Begin with the dividend and divisor as the
   ** numerator and denominator.
   */
   siCopy(&((*expansion)->raw_numerator), &dividend);
   siCopy(&((*expansion)->raw_denominator), &divisor);

   /* Enter a do ... while() loop to compute the continued
   ** fraction partial quotients and convergents.  Because
   ** the convergents don't require any "look-ahead" into
   ** the partial quotients, they can be computed
   ** in parallel
   */

   do
      {
      int curidx;
         /* Current index.
         */

      /* Buffer the current index value to the local variable (less
      ** typing).  The current index is what we're currently
      ** operating on.
      */
      curidx = (*expansion)->n;

      /* Increment the number of elements in the 
      ** three parallel arrays.
      */
      ((*expansion)->n)++;

      /* Allocate the memory for the memory block in the
      ** four parallel arrays.  There are two cases to
      ** consider, either this is the first element or
      ** else not the first.
      */
      if (!((*expansion)->a))
         {
         /* First time, first element. 
         */
         (*expansion)->a =
            maMalloc(sizeof(SYNTHETIC_INTEGER *));
         (*expansion)->p =
            maMalloc(sizeof(SYNTHETIC_INTEGER *));
         (*expansion)->q =
            maMalloc(sizeof(SYNTHETIC_INTEGER *));
         }
      else
         {
         /* Not the first time.  Blow up the arrays of 
         ** pointers to a larger size to accomodate one more
         ** pointer.
         */
         (*expansion)->a =
            maRealloc((*expansion)->a, 
                      (sizeof(SYNTHETIC_INTEGER *)) * (curidx+1));
         (*expansion)->p =
            maRealloc((*expansion)->p, 
                      (sizeof(SYNTHETIC_INTEGER *)) * (curidx+1));
         (*expansion)->q =
            maRealloc((*expansion)->q, 
                      (sizeof(SYNTHETIC_INTEGER *)) * (curidx+1));
         }

      /* Allocate the synthetic integers to go along with 
      ** blown-up arrays.
      */
      siCreate((*expansion)->a + curidx);
      siCreate((*expansion)->p + curidx);
      siCreate((*expansion)->q + curidx);

      /* Calculate the current continued fraction partial quotient,
      ** and bump the dividend and divisor for the next round.
      */
      siUnrestrictedDivision(&dividend,
                             &divisor,
                             (*expansion)->a + curidx,
                             &remainder);
      /* siDump((*expansion)->a + curidx, "a_k"); */
      siCopy(&divisor, &dividend);
      siCopy(&remainder, &divisor);

      /* Calculate the convergents using the standard
      ** recursive formulas.
      */
      if (curidx == 0)
         {
         /* p(0) = a(0) */
         siCopy((*expansion)->a + 0, (*expansion)->p + 0);
         /* q(0) = 1 */
         siSetToLong((*expansion)->q + 0, 1);
         }
      else if (curidx == 1)
         {
         /* p(1) = a(1)p(0) + 1 */
         siSetToLong(&si_temp1, 1);
         siUnrestrictedMultiplication((*expansion)->a + 1,
                                      (*expansion)->p + 0,
                                      &si_temp2);
         siUnrestrictedAddition(&si_temp2,
                                &si_temp1,
                                (*expansion)->p + 1);
         /* q(1) = a(1) */
         siCopy((*expansion)->a + 1, (*expansion)->q + 1);
         }
      else /* curidx >= 2 */
         {
         /* In this case, apply the full recursive formulas. */
         /* p(k) = a(k)p(k-1) + p(k-2)                       */
         siUnrestrictedMultiplication((*expansion)->a + curidx,
                                      (*expansion)->p + (curidx-1),
                                      &si_temp2);
         siUnrestrictedAddition(&si_temp2,
                                (*expansion)->p + (curidx-2),
                                (*expansion)->p + curidx);

         /* q(k) = a(k)q(k-1) + q(k-2)                       */
         siUnrestrictedMultiplication((*expansion)->a + curidx,
                                      (*expansion)->q + (curidx-1),
                                      &si_temp2);
         siUnrestrictedAddition(&si_temp2,
                                (*expansion)->q + (curidx-2),
                                (*expansion)->q + curidx);
         }

      /* siDump((*expansion)->p + curidx, "p_k"); */
      /* siDump((*expansion)->q + curidx, "q_k"); */
 
      /* Put in a safety test for the loop.  I've never had this loop fail to
      ** terminate.  Mathematically, it *can't* fail to terminate, but if there
      ** were a bug somewhere in the large integer math or a NAN condition,
      ** I wouldn't want to have a machine lockup without a diagnostic message.
      ** The value of 32000 is used because that approaches the limits of the
      ** minimum that an ANSI 'C' int is required to hold.  If we've gone
      ** around this loop 32000 times, something is very wrong.
      */
      asAssert(curidx < 32000, __LINE__);
      } 
   while (remainder->len);

   /* The lowest terms representation of the rational number supplied will
   ** be the final convergent.  This doesn't apply very much to this program,
   ** because the parsing functions automatically strip out the gcd() before
   ** passing data on, so the "raw" and "final" will be the same.  Will assign 
   ** it anyway.
   */
   siCopy((*expansion)->p + ((*expansion)->n - 1), &((*expansion)->numerator));
   siCopy((*expansion)->q + ((*expansion)->n - 1), &((*expansion)->denominator));

   /* Destroy the temporary integers.
   */
   siDestroy(&dividend);
   siDestroy(&divisor);
   siDestroy(&quotient);
   siDestroy(&remainder);
   siDestroy(&p_k_minus_1);
   siDestroy(&p_k_minus_2);
   siDestroy(&q_k_minus_1);
   siDestroy(&q_k_minus_2);
   siDestroy(&si_temp1);
   siDestroy(&si_temp2);
   siDestroy(&si_temp3);
   siDestroy(&si_temp4);
   }


/****************************************************************************/
/* pqDestroy():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Deallocates the dynamic data structures associated with the CF         */
/*   expansion and convergents, and sets the caller's pointer to NULL.      */
/*                                                                          */
/*   **expansion     :  The continued fraction expansion and the            */
/*                      convergents.                                        */
/****************************************************************************/
void pqDestroy(CF_EXPANSION **expansion)
   {
   int idx;

   /* Be sure the caller isn't doing anything silly. with pointers.
   */
   asAssert(expansion != NULL, __LINE__);
   asAssert(*expansion != NULL, __LINE__);

   /* The general strategy at this point is to deallocate the data structure
   ** from the bottom up.  It must be done this way because once a higher
   ** data structure is deallocated, the memory ain't yours, so any access
   ** even to deallocate "lower" pointers is a violation.  Checks all along
   ** the way are performed to be sure that nothing looks suspicious.
   */

   asAssert((*expansion)->n > 0, __LINE__);  /* Even a 0th order expansion (an integer)
                                             ** has the "n" at 1.
                                             */
   /* Check for suspicious conditions in the base data
   ** structure.
   */
   asAssert((*expansion)->raw_numerator != NULL, __LINE__);
   asAssert((*expansion)->raw_denominator != NULL, __LINE__);
   asAssert((*expansion)->numerator != NULL, __LINE__);
   asAssert((*expansion)->denominator != NULL, __LINE__);
   asAssert((*expansion)->a != NULL, __LINE__);
   asAssert((*expansion)->p != NULL, __LINE__);
   asAssert((*expansion)->q != NULL, __LINE__);


   /* Deallocate the directly linked synthetic integers.
   */
   siDestroy(&((*expansion)->raw_numerator));
   siDestroy(&((*expansion)->raw_denominator));
   siDestroy(&((*expansion)->numerator));
   siDestroy(&((*expansion)->denominator));

   /* Deallocate each of the synthetic integers that are the partial
   ** quotients and convergents.
   */
   for (idx = 0; idx < ((*expansion)->n); idx++)
      {
      asAssert((((*expansion)->a)[idx]) != NULL, __LINE__);
      asAssert((((*expansion)->p)[idx]) != NULL, __LINE__);
      asAssert((((*expansion)->q)[idx]) != NULL, __LINE__);

      siDestroy((*expansion)->a + idx);
      siDestroy((*expansion)->p + idx);
      siDestroy((*expansion)->q + idx);
      }

   /* Deallocate the arrays of pointers.
   */
   maFree((*expansion)->a);
   maFree((*expansion)->p);
   maFree((*expansion)->q);

   /* Deallocate the base data structure and set the caller's pointer
   ** to NULL.
   */
   maFree(*expansion);
   *expansion = NULL;
   }


/****************************************************************************/
/* pqDump():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Prints the entire CF expansion and list of convergents to the standard */
/*   output stream, with an optional description.                           */
/*                                                                          */
/*   **expansion     :  The continued fraction expansion and the            */
/*                      convergents.                                        */
/*   *desc           :  Description to use.  If this is a zero-length       */
/*                      string, omits the description.                      */
/*   p_raw           :  Boolean flag to indicate if the raw numerator and   */
/*                      denominator should be printed distinctly from the   */
/*                      final CF convergent.  For most of the application   */
/*                      in this program, the answer is no, because the      */
/*                      rational number is already reduced at the time it   */
/*                      is CF'd, and the raw rational number will be        */
/*                      identical to the final convergent.  To print it     */
/*                      would just waste space.                             */
/****************************************************************************/
void pqDump(CF_EXPANSION **expansion, char *desc, int p_raw)
   {
   int i;
   char buf[100];

   /* Be sure the caller isn't doing any pointer suicide.
   */
   asAssert(expansion != NULL, __LINE__);
   asAssert(*expansion != NULL, __LINE__);
   asAssert(desc != NULL, __LINE__);

   /* If a description was passed print it out as a banner headline.
   */
   if (strlen(desc))
      {
      gfBannerHeading(desc, 0);
      }

   /* Banner announcing inputs. */
   gfBannerHeading("Inputs To CF Calculation", 0);
   gfHline();

   /* Print out the raw numerator and denominator. */
   siDump(&((*expansion)->raw_numerator), "h_in");
   gfHline();
   siDump(&((*expansion)->raw_denominator), "k_in");
   gfHline();

   /* Print out each of the continued-fraction partial
   ** quotients.
   */
   /* Banner announcing partial quotients. */
   gfBannerHeading("CF Partial Quotients", 0);
   gfHline();

   for (i=0; i<((*expansion)->n); i++)
      {
      sprintf(buf, "a(%d)", i);
      siDump((*expansion)->a + i, buf);
      gfHline();
      }

   /* Priint out the convergents. */
   /* Banner announcing partial convergents. */
   gfBannerHeading("CF Convergents", 0);
   gfHline();

   for (i=0; i<((*expansion)->n); i++)
      {
      sprintf(buf, "p(%d)", i);
      siDump((*expansion)->p + i, buf);
      sprintf(buf, "q(%d)", i);
      siDump((*expansion)->q + i, buf);
      gfHline();
      }
   }


/****************************************************************************/
/* pqBapp():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Extracts the two best rational approximations to a rational number     */
/*   in the Farey series of order N, using a CF decomposition that must     */
/*   have already been done on the rational number.                         */
/*                                                                          */
/*   The function behaves subtly differently depending on whether the       */
/*   rational number passed is in the Farey series of order N.  If the      */
/*   number is not in F_N, the two Farey neighbors are returned, in an      */
/*   order that depends on whether the rational number has an odd or        */
/*   an even number of partial quotients.  If the number is in F_N, the     */
/*   number itself (in lowest terms) is returned, along with the left or    */
/*   right Farey neighbor, with which again depending on whether the number */
/*   has an odd or even number of partial quotients.                        */
/*                                                                          */
/*   This function is typically used to get two consecutive Farey terms     */
/*   so that the recursive formulas can be applied.                         */
/*                                                                          */
/* INPUTS                                                                   */
/*   **expansion  :  The CF expansion that must have already been done on   */
/*                   the [non-negative] number.                             */
/*   **N          :  The [positive] order of the Farey series being         */
/*                   considered.                                            */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   **conv_h,                                                              */
/*   **conv_k     :  The highest-order convergent with a denominator not    */
/*                   larger than N.                                         */
/*   **neigh_h,                                                             */
/*   **neigh_k    :  The intermediate fraction as specified by the          */
/*                   equation in the TOMS paper.  This will be a Farey      */
/*                   neighbor to the rational number of interest.           */
/*    *convergent_number                                                    */
/*                   The index of the convergent that was the highest-order */
/*                   convergent with a denominator not larger than N.       */
/****************************************************************************/
void pqBapp(CF_EXPANSION      **expansion,
            SYNTHETIC_INTEGER **N,
            SYNTHETIC_INTEGER **conv_h,
            SYNTHETIC_INTEGER **conv_k,
            SYNTHETIC_INTEGER **neigh_h,
            SYNTHETIC_INTEGER **neigh_k,
            int                *convergent_number)
   {
   SYNTHETIC_INTEGER *constant_1,
                     *t1,
                     *t2,
                     *t3;

   /* Make sure the caller isn't doing anything silly with pointers.
   ** Catastropies are checked, but not duplicate pointers, etc.
   */
   asAssert(expansion != NULL, __LINE__);
   asAssert(*expansion != NULL, __LINE__);
   asAssert(N != NULL, __LINE__);
   asAssert(*N != NULL, __LINE__);
   asAssert(conv_h != NULL, __LINE__);
   asAssert(*conv_h != NULL, __LINE__);
   asAssert(conv_k != NULL, __LINE__);
   asAssert(*conv_k != NULL, __LINE__);
   asAssert(neigh_h != NULL, __LINE__);
   asAssert(*neigh_h != NULL, __LINE__);
   asAssert(neigh_k != NULL, __LINE__);
   asAssert(*neigh_k != NULL, __LINE__);
   asAssert(convergent_number != NULL, __LINE__);

   /* Allocate all temporary variables.
   */
   siCreate(&constant_1);
   siSetToLong(&constant_1, 1);
   siCreate(&t1);
   siCreate(&t2);
   siCreate(&t3);

   /* Branch based on the order of the decomposition.
   */
   if ((*expansion)->n == 1)
      {
      /* If we have a 0th order expansion, this means that
      ** it is an integer.  We can't process this using the standard
      ** recursive equations because we don't have a p(-1) or a 
      ** q(-1).  However, it can be shown easily that the right
      ** value here is always (N * p(0) + 1)/N.
      */
      siCopy((*expansion)->p + 0, conv_h);
      siCopy((*expansion)->q + 0, conv_k);
      siUnrestrictedMultiplication(N, (*expansion)->p + 0, &t1);
      siUnrestrictedAddition(&constant_1, &t1, neigh_h);
      siCopy(N, neigh_k);
      *convergent_number = 0;
      }
   else
      {
      /* If we have a first-order or greater decomposition, we 
      ** can apply the standard recursive formulas.
      */
      int i = 0;

      /* We need to locate the convergent with the largest denominator
      ** not larger than N.
      */
      if (siCompare((*expansion)->q + ((*expansion)->n - 1), N) <= 0)
         {
         /* The final convergent is equal to N or less than N.  We must
         ** choose the final convergent.
         */
         *convergent_number = i = (*expansion)->n - 1;
         }
      else
         {
         /* Iterate through until we find that the next convergent is too
         ** big.
         */
         while (siCompare((*expansion)->q + (i + 1), N) <= 0)
            {
            i++;
 
            /* Do a sanity check here.  If "i" has grown to where the
            ** next convergent to examine isn't valid, something is
            ** very wrong.
            */
            asAssert((i+1) < ((*expansion)->n), __LINE__);
            }
         }

      /* Assign this convergent, advise the caller of which one.
      */
      siCopy((*expansion)->p + i, conv_h);
      siCopy((*expansion)->q + i, conv_k);
      *convergent_number = i;

      /* We now know the convergent that is the last not greater
      ** than the order N.  Can apply the standard recursive formulas.
      ** Must split into two cases because if the right convergent
      ** to use is the zero'th one, we can't apply the recursive
      ** formulas.
      */
      if (i==0)
         {
         siUnrestrictedMultiplication(N, (*expansion)->p + 0, &t1);
         siUnrestrictedAddition(&constant_1, &t1, neigh_h);
         siCopy(N, neigh_k);
         }
      else
         {
         /* First, calculate the quantity floor((N-q[k-1])/q[k]), as
         ** we'll use this more than once.  Leave this in "t1".
         */
         siUnrestrictedSubtraction(N, (*expansion)->q + (i-1), &t2);
         siUnrestrictedDivision(&t2, (*expansion)->q + i, &t1, &t3);

         /* Calculate the numerator of the neighbor.
         */
         siUnrestrictedMultiplication(&t1, (*expansion)->p + i, &t2);
         siUnrestrictedAddition(&t2, (*expansion)->p + (i-1), neigh_h);

         /* Calculate the denominator of the neighbor.
         */
         siUnrestrictedMultiplication(&t1, (*expansion)->q + i, &t2);
         siUnrestrictedAddition(&t2, (*expansion)->q + (i-1), neigh_k);
         }
      }

   /* Destroy all temporary variables.
   */
   siDestroy(&constant_1);
   siDestroy(&t1);
   siDestroy(&t2);
   siDestroy(&t3);
   }


/****************************************************************************/
/****************************************************************************/
/******   N U M E R I C A L    A L G O R I T H M    F U N C T I O N S   *****/
/****************************************************************************/
/****************************************************************************/
/* This section is reserved for functions which apply specific numerical 
** algorithms (GCD, for example).
*/
/****************************************************************************/
/* naMind():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Locates the rational number with the smallest denominator in an        */
/*   interval, using the continued fraction algorithm presented in the      */
/*   paper.                                                                 */
/****************************************************************************/
void naMind(SYNTHETIC_INTEGER **h1par,
            SYNTHETIC_INTEGER **k1par,
            SYNTHETIC_INTEGER **h2par,
            SYNTHETIC_INTEGER **k2par,
            SYNTHETIC_INTEGER **result_h,
            SYNTHETIC_INTEGER **result_k,
            int emit_midpoint,
            int emit_cfdata,
            int emit_result)
   {
   SYNTHETIC_INTEGER *h1, *k1, *h2, *k2, *midpoint_h, *midpoint_k,
                     *t1, *t2, *t3, *t4, *t5, *t6, 
                     *t7, *t8, *t9, *t10, *t11, *t12,
                     *constant_1, *constant_0, *p_minus_1, *q_minus_1;
   CF_EXPANSION      *midpoint_expansion;
   int k;
   int done;

   /* Be sure there is no pointer nonsense.
   */
   asAssert(h1par != NULL, __LINE__);
   asAssert(*h1par != NULL, __LINE__);
   asAssert(k1par != NULL, __LINE__);
   asAssert(*k1par != NULL, __LINE__);
   asAssert(h2par != NULL, __LINE__);
   asAssert(*h2par != NULL, __LINE__);
   asAssert(k2par != NULL, __LINE__);
   asAssert(*k2par != NULL, __LINE__);
   asAssert(result_h != NULL, __LINE__);
   asAssert(*result_h != NULL, __LINE__);
   asAssert(result_k != NULL, __LINE__);
   asAssert(*result_k != NULL, __LINE__);

   /* Allocate locals
   */
   siCreate(&h1);
   siCreate(&k1);
   siCreate(&h2);
   siCreate(&k2);
   siCreate(&midpoint_h);
   siCreate(&midpoint_k);
   siCreate(&t1);
   siCreate(&t2);
   siCreate(&t3);
   siCreate(&t4);
   siCreate(&t5);
   siCreate(&t6);
   siCreate(&t7);
   siCreate(&t8);
   siCreate(&t9);
   siCreate(&t10);
   siCreate(&t11);
   siCreate(&t12);
   siCreate(&constant_1);
   siSetToLong(&constant_1, 1);
   siCreate(&constant_0);
   siSetToLong(&constant_0, 0);
   siCreate(&p_minus_1);
   siCreate(&q_minus_1);

   /* Copy the input parameters to our locals.
   */
   siCopy(h1par, &h1);
   siCopy(k1par, &k1);
   siCopy(h2par, &h2);
   siCopy(k2par, &k2);

   /* Swap the input parameters if the input parameters
   ** are in the wrong order.
   */
   if (rnCompare(&h1, &k1, &h2, &k2) == 1)
      {
      SYNTHETIC_INTEGER *temp;

      temp = h1;
      h1 = h2;
      h2 = temp;

      temp = k2;
      k1 = k2;
      k2 = temp;
      }

   /* Calculate the midpoint of the interval.  This
   ** is (l+r)/2.
   */
   rnSum(&h1, &k1, &h2, &k2, &midpoint_h, &midpoint_k);   

      {
      SYNTHETIC_INTEGER *constant_2, *tempresult;

      siCreate(&constant_2);
      siCreate(&tempresult);

      siSetToLong(&constant_2, 2);

      siUnrestrictedMultiplication(&midpoint_k, &constant_2, &tempresult);

      siCopy(&tempresult, &midpoint_k);

      rnCanonize(&midpoint_h, &midpoint_k);

      siDestroy(&constant_2);
      siDestroy(&tempresult);
      }

   /* If the midpoint should be printed for informative
   ** purposes, print it.
   */
   if (emit_midpoint)
      {
      siDump(&midpoint_h, "midpoint_h");
      gfHline();
      siDump(&midpoint_k, "midpoint_k");
      gfHline();
      }

   /* Form the partial quotients and convergents of the
   ** midpoint.
   */
   pqCreate(&midpoint_h,
            &midpoint_k,
            &midpoint_expansion);

   /* Print out the partial quotients and convergents, if the
   ** caller has requested it.
   */
   if (emit_cfdata)
      {
      pqDump(&midpoint_expansion, "CF Representation Of Interval Midpoint", FALSE);
      }

   /* At this point, can apply the algorithm listed in the paper.
   */
   done = FALSE;
   for (k=0; k<midpoint_expansion->n && !done; k++)
      /* For each convergent, in order of increasing k.
      */
      {
      /* printf("k is : %d\n", k); */

      /* Calculate the p and q one back.  Must do this
      ** explicitly and can't index into array, because
      ** case of [0] not covered.
      */
      if (k==0)
         {
         siSetToLong(&p_minus_1, 1);
         siSetToLong(&q_minus_1, 0);
         }
      else
         {
         siCopy(&(midpoint_expansion->p[k-1]), &p_minus_1);
         siCopy(&(midpoint_expansion->q[k-1]), &q_minus_1);
         }

      /* Test convergent for membership in [l,r].  This means >= l and 
      ** <= r.  If we have membership, we're done.
      */
      if ((rnCompare(&h1, &k1, &(midpoint_expansion->p[k]), &(midpoint_expansion->q[k])) <= 0) && 
          (rnCompare(&h2, &k2, &(midpoint_expansion->p[k]), &(midpoint_expansion->q[k])) >= 0))
         {
         /* The convergent is in the interval.  Assign result and signal done.
         */
         siCopy(&(midpoint_expansion->p[k]), result_h);
         siCopy(&(midpoint_expansion->q[k]), result_k);
         done = TRUE;
         }
      else 
         {
         /* Must look at potential intermediate fractions.
         */
         if ((k & 0x1) == 0) /* i is even */
            {
            /* Calculate the value of "i" that will be the minimum
            ** required to potentially put the intermediate fraction
            ** in the interval [l,r].  This is in accordance with
            ** the paper.
            */
            siUnrestrictedMultiplication(&h2,
                                         &q_minus_1,
                                         &t1);
            siUnrestrictedMultiplication(&k2,
                                         &p_minus_1,
                                         &t2);
            siUnrestrictedSubtraction(&t1, &t2, &t3);
            siUnrestrictedMultiplication(&k2,
                                         &(midpoint_expansion->p[k]),
                                         &t4);
            siUnrestrictedMultiplication(&h2,
                                         &(midpoint_expansion->q[k]),
                                         &t5);
            siUnrestrictedSubtraction(&t4, &t5, &t6);
   
            /* We have the numerator and denominator.  We would like
            ** to form the ceiling of the quotient.  Using integer math, 
            ** the best way to do that is to add the denominator to the 
            ** numerator minus one and use the integer quotient  However, first
            ** would like to normalize numerator and denominator so 
            ** both neg or both pos.  It should never be possible to
            ** have different signs.
            */ 
            asAssert((t3->neg && t6->neg) || (!(t3->neg) && !(t6->neg)), __LINE__);
            if (t3->neg)
               {
               t3->neg = FALSE;
               t6->neg = FALSE;
               }

            siUnrestrictedAddition(&t6, &t3, &t8);
            siUnrestrictedSubtraction(&t8, &constant_1, &t7);

            /* Now get the quotient.  This quotient should be the 
            ** ceiling, because we added the numerator to the
            ** denominator minus one.  "t8" should contain the "i" as
            ** specified in the paper.
            */
            siUnrestrictedDivision(&t7, &t6, &t8, &t9);

            /* siDump(&t8, "i"); */

            }
         else /* i is odd */
            {
            /* printf("Odd\n"); */

            /* Calculate the value of "i" that will be the minimum
            ** required to potentially put the intermediate fraction
            ** in the interval [l,r].  This is in accordance with
            ** the paper.
            */
            siUnrestrictedMultiplication(&h1,
                                         &q_minus_1,
                                         &t1);
            siUnrestrictedMultiplication(&k1,
                                         &p_minus_1,
                                         &t2);
            siUnrestrictedSubtraction(&t1, &t2, &t3);
            siUnrestrictedMultiplication(&k1,
                                         &(midpoint_expansion->p[k]),
                                         &t4);
            siUnrestrictedMultiplication(&h1,
                                         &(midpoint_expansion->q[k]),
                                         &t5);
            siUnrestrictedSubtraction(&t4, &t5, &t6);
   
            /* We have the numerator and denominator.  We would like
            ** to form the ceiling of the quotient.  Using integer math, 
            ** the best way to do that is to add the denominator to the 
            ** numerator minus one and use the integer quotient  However, first
            ** would like to normalize numerator and denominator so 
            ** both neg or both pos.  It should never be possible to
            ** have different signs.
            */ 
            asAssert((t3->neg && t6->neg) || (!(t3->neg) && !(t6->neg)), __LINE__);
            if (t3->neg)
               {
               t3->neg = FALSE;
               t6->neg = FALSE;
               }

            siUnrestrictedAddition(&t6, &t3, &t8);
            siUnrestrictedSubtraction(&t8, &constant_1, &t7);

            /* Now get the quotient.  This quotient should be the 
            ** ceiling, because we added the numerator to the
            ** denominator minus one.  "t8" should contain the "i" as
            ** specified in the paper.
            */
            siUnrestrictedDivision(&t7, &t6, &t8, &t9);

            /* siDump(&t8, "i"); */

            }

         /* At this point, we have a potential coefficient on intermediate fractions.
         ** Must examine the result.
         */
         /* Disregard if >= partial quotient.
         */
         /* printf("k: %d\n", k); */
         /* siDump(&t8, "i"); */
         /* siDump(&(midpoint_expansion->a[k]), "ak"); */

         /* Need to be extremely careful, because about to index one past k on the
         ** assumption that can't be at last place, or convergent would have matched.
         */
         asAssert((k+1) < midpoint_expansion->n, __LINE__);

         if (siCompare(&(midpoint_expansion->a[k+1]), &t8) > 0)
            {
            /* Form the intermediate fraction involved.  It is guaranteed
            ** to be irreducible.
            */
            siUnrestrictedMultiplication(&t8, &(midpoint_expansion->p[k]), &t1);
            siUnrestrictedAddition(&t1, &p_minus_1, &t2);
            siUnrestrictedMultiplication(&t8, &(midpoint_expansion->q[k]), &t3);
            siUnrestrictedAddition(&t3, &q_minus_1, &t4);

            /* The fraction is t2/t4.
            */
            /* siDump(&t2, "potential_h"); */
            /* siDump(&t4, "potential_k"); */

            /* Evaluate this for membership in [l,r]
            */
            if (rnCompare(&h1, &k1, &t2, &t4) <= 0) /* >= l */
               {
               if (rnCompare(&h2, &k2, &t2, &t4) >= 0) /* <= r */
                  {
                  siCopy(&t2, result_h);
                  siCopy(&t4, result_k);
                  done = TRUE;
                  }
               }
            }
         } /* End if must look at intermediate fractions. */
      } /* End for() */

   /* We should have our answer.  Mathematically, if nothing else, the final
   ** convergent must be in the interval.  Will just put this extra paranoid
   ** assertion in.
   */
   asAssert(done != 0, __LINE__);

   /* Destroy the continued fraction expansion.
   */
   pqDestroy(&midpoint_expansion);

   /* Copy the caller's inputs to our local variables.
   */
   siDestroy(&h1);
   siDestroy(&k1);
   siDestroy(&h2);
   siDestroy(&k2);
   siDestroy(&midpoint_h);
   siDestroy(&midpoint_k);
   siDestroy(&t1);
   siDestroy(&t2);
   siDestroy(&t3);
   siDestroy(&t4);
   siDestroy(&t5);
   siDestroy(&t6);
   siDestroy(&t7);
   siDestroy(&t8);
   siDestroy(&t9);
   siDestroy(&t10);
   siDestroy(&t11);
   siDestroy(&t12);
   siDestroy(&constant_1);
   siDestroy(&constant_0);
   siDestroy(&p_minus_1);
   siDestroy(&q_minus_1);
   }


/****************************************************************************/
/****************************************************************************/
/******************   C O M M A N D    F U N C T I O N S   ******************/
/****************************************************************************/
/****************************************************************************/
/* This section is reserved for functions which carry out the commands which
** are subfunctions of how the RAP program operates.  Each of these commands
** is tabulated to be matched in a template for what it does and the types
** of operands it will accept.
*/
/* The first thing to define is the different types of things that an
** individual input parameter can be.  I don't want to use enum here
** because there are some potential compiler portability annoyances if somebody
** sicks a C++ compiler on this deck.
*/
#define CMDLINE_PAR_TYPE_UNASSIGNED                                       (0)
   /* Not filled in yet.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS                                (1)
   /* The "+" sign alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS                               (2)
   /* The "-" sign alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES                               (3)
   /* The "*" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT                            (4)
   /* The "/" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO                              (5)
   /* The "%" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER                               (6)
   /* The "**" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_GCD                                 (7)
   /* The "GCD" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP                                 (8)
   /* The "DAP" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND                                (9)
   /* The "MIND" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_CF                                 (10)
   /* The "CF" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN                                 (11)
   /* The "FN" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX                             (12)
   /* The "CF" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB                                (13)
   /* The "FAB" token alone.
   */
#define CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX                            (14)
   /* The "FABDMAX" token alone.
   */
#define CMDLINE_PAR_TYPE_INTNEG                                          (15)
   /* A negative integer.
   */
#define CMDLINE_PAR_TYPE_INTZERO                                         (16)
   /* The integer zero.
   */
#define CMDLINE_PAR_TYPE_INTPOS                                          (17)
   /* A positive integer.
   */
#define CMDLINE_PAR_TYPE_RATNEG                                          (18)
   /* A negative rational number.
   */
#define CMDLINE_PAR_TYPE_RATZERO                                         (19)
   /* A rational number whose value is zero.
   */
#define CMDLINE_PAR_TYPE_RATPOS                                          (20)
   /* A positive rational number.
   */
#define CMDLINE_PAR_TYPE_UNKNOWN                                         (21)
   /* Couldn't figure out what it was.
   */

/* The next thing to define is the data type which holds a command-line
** parameter (or parameters from a file, same thing).
*/
typedef struct 
   {
   int ftype;
      /* The fundamental type, using one of the enumerated constants
      ** above.  
      */
   char *orig_string;
      /* The string value that was supplied on the command line, after
      ** everything was converted to upper case and token concatenation
      ** is done.  This will be a dynamically allocated string.
      */
   SYNTHETIC_INTEGER *raw_numerator;
   SYNTHETIC_INTEGER *raw_denominator;
      /* Filled exactly as specified on the command line.  If only an
      ** integer was specified, the denominator pointer is NULL.  If
      ** the caller specified a rational number as a float, the original
      ** rational number formed by adding zeros to the numerator and 
      ** making the denominator a power of ten is placed here.
      */
   SYNTHETIC_INTEGER *canonical_numerator;
   SYNTHETIC_INTEGER *canonical_denominator;
      /* The parsing takes steps to put any numerical argument into
      ** a canonical form.  Here are the steps taken.
      **
      **   a)Any rational number with a zero denominator will terminate
      **     the program with an error message.
      **
      **   b)Integers are left unchanged (there is really nothing more
      **     canonical.
      **   
      **   c)The GCD is always removed from the input argument, using
      **     Euclid's algorithm (directly or indirectly).  If a rational 
      **     number supplied is actually an integer (after GCD calculated),
      **     it is treated as such (NULL denominator pointer).
      **
      **   d)If the rational number is positive and was specified as
      **     the quotient of two negative integers, the "negs" are
      **     removed.
      **
      **   e)Any negative rational number will be expressed as a negative
      **     numerator and positive denominator.
      **
      **   f)Any rational number which has value 0 (such as 0/-1293981),
      **     will be stored canonically as 0/1.
      */
      } CMD_LINE_PAR;


/* A single data structure which holds the complete set of command-line
** parameters.  It is easier to do it this way rather than dynamically
** resized arrays, etc.
*/
struct ipParBlockStruct
   {
   int n;
      /* The number of array elements filled in the array of
      ** command-line parameters.
      */
   CMD_LINE_PAR pars[MAX_CMDLINE_PARS];
      /* Space for the command-line parameters.
      */
   } par_block;


/****************************************************************************/
/* cfSimple2ParIntegerAddition():                                           */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles addition of two arbitrary integers and displaying the result.  */
/*   Called in response to a template match.                                */
/****************************************************************************/
void cfSimple2ParIntegerAddition(void)
   {
   SYNTHETIC_INTEGER *result;

   siCreate(&result);
   siUnrestrictedAddition(&(par_block.pars[1].canonical_numerator),
                          &(par_block.pars[2].canonical_numerator),
                          &result);
   siDump(&(par_block.pars[1].canonical_numerator), "arg1");
   gfHline();
   siDump(&(par_block.pars[2].canonical_numerator), "arg2");
   gfHline();
   siDump(&result, "arg1 + arg2");
   gfHline();
   }


/****************************************************************************/
/* cfSimple2ParRationalRationalAddition():                                  */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles addition of two arbitrary rational numbers.  Called in         */
/*   response to a template match.                                          */
/****************************************************************************/
void cfSimple2ParRationalRationalAddition(void)
   {
   SYNTHETIC_INTEGER *arg1_h,
                     *arg1_k,
                     *arg2_h,
                     *arg2_k,
                     *constant_1,
                     *result_numerator,
                     *result_denominator;

   siCreate(&arg1_h);
   siCreate(&arg1_k);
   siCreate(&arg2_h);
   siCreate(&arg2_k);
   siCreate(&constant_1);
   siSetToLong(&constant_1, 1);
   siCreate(&result_numerator);
   siCreate(&result_denominator);

   /* Since this function handles the general case where either
   ** or both arguments are rational, we need to watch out and
   ** condition any integer argument to be rational.  We need
   ** to watch out for a missing denominator and assign it to
   ** be "1" if it is missing (meaning that the original argument
   ** was an integer.
   */
   /* Copy over to our scratch space, watching out for integers.
   */
   siCopy(&(par_block.pars[1].canonical_numerator), &arg1_h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &arg1_k);
   else
      siSetToLong(&arg1_k, 1);

   siCopy(&(par_block.pars[2].canonical_numerator), &arg2_h);
   if (par_block.pars[2].canonical_denominator)
      siCopy(&(par_block.pars[2].canonical_denominator), &arg2_k);
   else
      siSetToLong(&arg2_k, 1);

   /* Make the call to the rational number addition function.
   */
   rnSum(&arg1_h, &arg1_k, &arg2_h, &arg2_k, &result_numerator, &result_denominator);

   /* Print out the first argument.  We display it differently
   ** depending on if it was rational or integral.
   */
   if (par_block.pars[1].canonical_denominator)
      {
      siDump(&(par_block.pars[1].canonical_numerator),   "arg1_h");
      gfHline();
      siDump(&(par_block.pars[1].canonical_denominator), "arg1_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[1].canonical_numerator),   "arg1");
      gfHline();
      }

   /* Print out the first argument.  We display it differently
   ** depending on if it was rational or integral.
   */
   if (par_block.pars[2].canonical_denominator)
      {
      siDump(&(par_block.pars[2].canonical_numerator),   "arg2_h");
      gfHline();
      siDump(&(par_block.pars[2].canonical_denominator), "arg2_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[2].canonical_numerator),   "arg2");
      gfHline();
      }

   /* Print out the result.  We display it differently, depending
   ** on whether it is rational or integral.
   */
   if (!siCompare(&result_denominator, &constant_1))
      {
      /* Denominator is equal to 1.  This is an integer.
      */
      siDump(&result_numerator, "result");
      gfHline();
      }
   else
      {
      siDump(&result_numerator,                          "result_h");
      gfHline();
      siDump(&result_denominator,                        "result_k");
      gfHline();
      }

   siDestroy(&arg1_h);
   siDestroy(&arg1_k);
   siDestroy(&arg2_h);
   siDestroy(&arg2_k);
   siDestroy(&constant_1);
   siDestroy(&result_numerator);
   siDestroy(&result_denominator);
   }


/****************************************************************************/
/* cfSimple2ParIntegerSubtraction():                                        */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles subtraction of two arbitrary integers and displaying the       */
/*   result.  Called in response to a template match.                       */
/****************************************************************************/
void cfSimple2ParIntegerSubtraction(void)
   {
   SYNTHETIC_INTEGER *result;

   siCreate(&result);
   siUnrestrictedSubtraction(&(par_block.pars[1].canonical_numerator),
                             &(par_block.pars[2].canonical_numerator),
                             &result);
   siDump(&(par_block.pars[1].canonical_numerator), "arg1");
   gfHline();
   siDump(&(par_block.pars[2].canonical_numerator), "arg2");
   gfHline();
   siDump(&result, "arg1 - arg2");
   gfHline();
   siDestroy(&result);
   }


/****************************************************************************/
/* cfSimple2ParRationalRationalSubtraction():                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles subtraction of two arbitrary rational numbers.  Called in      */
/*   response to a template match.                                          */
/****************************************************************************/
void cfSimple2ParRationalRationalSubtraction(void)
   {
   SYNTHETIC_INTEGER *arg1_h,
                     *arg1_k,
                     *arg2_h,
                     *arg2_k,
                     *constant_1,
                     *result_numerator,
                     *result_denominator;

   siCreate(&arg1_h);
   siCreate(&arg1_k);
   siCreate(&arg2_h);
   siCreate(&arg2_k);
   siCreate(&constant_1);
   siSetToLong(&constant_1, 1);
   siCreate(&result_numerator);
   siCreate(&result_denominator);

   /* Since this function handles the general case where either
   ** or both arguments are rational, we need to watch out and
   ** condition any integer argument to be rational.  We need
   ** to watch out for a missing denominator and assign it to
   ** be "1" if it is missing (meaning that the original argument
   ** was an integer.
   */
   /* Copy over to our scratch space, watching out for integers.
   */
   siCopy(&(par_block.pars[1].canonical_numerator), &arg1_h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &arg1_k);
   else
      siSetToLong(&arg1_k, 1);

   siCopy(&(par_block.pars[2].canonical_numerator), &arg2_h);
   if (par_block.pars[2].canonical_denominator)
      siCopy(&(par_block.pars[2].canonical_denominator), &arg2_k);
   else
      siSetToLong(&arg2_k, 1);

   /* Make the call to the rational number addition function.
   */
   rnDifference(&arg1_h, &arg1_k, &arg2_h, &arg2_k, &result_numerator, &result_denominator);

   /* Print out the first argument.  We display it differently
   ** depending on if it was rational or integral.
   */
   if (par_block.pars[1].canonical_denominator)
      {
      siDump(&(par_block.pars[1].canonical_numerator),   "arg1_h");
      gfHline();
      siDump(&(par_block.pars[1].canonical_denominator), "arg1_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[1].canonical_numerator),   "arg1");
      gfHline();
      }

   /* Print out the first argument.  We display it differently
   ** depending on if it was rational or integral.
   */
   if (par_block.pars[2].canonical_denominator)
      {
      siDump(&(par_block.pars[2].canonical_numerator),   "arg2_h");
      gfHline();
      siDump(&(par_block.pars[2].canonical_denominator), "arg2_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[2].canonical_numerator),   "arg2");
      gfHline();
      }

   /* Print out the result.  We display it differently, depending
   ** on whether it is rational or integral.
   */
   if (!siCompare(&result_denominator, &constant_1))
      {
      /* Denominator is equal to 1.  This is an integer.
      */
      siDump(&result_numerator, "result");
      gfHline();
      }
   else
      {
      siDump(&result_numerator,                          "result_h");
      gfHline();
      siDump(&result_denominator,                        "result_k");
      gfHline();
      }

   siDestroy(&arg1_h);
   siDestroy(&arg1_k);
   siDestroy(&arg2_h);
   siDestroy(&arg2_k);
   siDestroy(&constant_1);
   siDestroy(&result_numerator);
   siDestroy(&result_denominator);
   }

   
/****************************************************************************/
/* cfSimple2ParIntegerMultiplication():                                     */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles multiplication of two arbitrary integers and displaying the    */
/*   result.  Called in response to a template match.                       */
/****************************************************************************/
void cfSimple2ParIntegerMultiplication(void)
   {
   SYNTHETIC_INTEGER *result;

   siCreate(&result);
   siUnrestrictedMultiplication(&(par_block.pars[1].canonical_numerator),
                                &(par_block.pars[2].canonical_numerator),
                                &result);
   siDump(&(par_block.pars[1].canonical_numerator), "arg1");
   gfHline();
   siDump(&(par_block.pars[2].canonical_numerator), "arg2");
   gfHline();
   siDump(&result, "arg1 * arg2");
   gfHline();
   siDestroy(&result);
   }


/****************************************************************************/
/* cfSimple2ParRationalRationalMultiplication():                            */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles multiplication of two arbitrary rational numbers.  Called in   */
/*   response to a template match.                                          */
/****************************************************************************/
void cfSimple2ParRationalRationalMultiplication(void)
   {
   SYNTHETIC_INTEGER *arg1_h,
                     *arg1_k,
                     *arg2_h,
                     *arg2_k,
                     *constant_1,
                     *result_numerator,
                     *result_denominator;

   siCreate(&arg1_h);
   siCreate(&arg1_k);
   siCreate(&arg2_h);
   siCreate(&arg2_k);
   siCreate(&constant_1);
   siSetToLong(&constant_1, 1);
   siCreate(&result_numerator);
   siCreate(&result_denominator);

   /* Since this function handles the general case where either
   ** or both arguments are rational, we need to watch out and
   ** condition any integer argument to be rational.  We need
   ** to watch out for a missing denominator and assign it to
   ** be "1" if it is missing (meaning that the original argument
   ** was an integer.
   */
   /* Copy over to our scratch space, watching out for integers.
   */
   siCopy(&(par_block.pars[1].canonical_numerator), &arg1_h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &arg1_k);
   else
      siSetToLong(&arg1_k, 1);

   siCopy(&(par_block.pars[2].canonical_numerator), &arg2_h);
   if (par_block.pars[2].canonical_denominator)
      siCopy(&(par_block.pars[2].canonical_denominator), &arg2_k);
   else
      siSetToLong(&arg2_k, 1);

   /* Call the function to calculate the rational product.
   */
   rnProduct(&arg1_h, &arg1_k, &arg2_h, &arg2_k, &result_numerator, &result_denominator);

   /* Print out the first argument.  We display it differently
   ** depending on if it was rational or integral.
   */
   if (par_block.pars[1].canonical_denominator)
      {
      siDump(&(par_block.pars[1].canonical_numerator),   "arg1_h");
      gfHline();
      siDump(&(par_block.pars[1].canonical_denominator), "arg1_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[1].canonical_numerator),   "arg1");
      gfHline();
      }

   /* Print out the first argument.  We display it differently
   ** depending on if it was rational or integral.
   */
   if (par_block.pars[2].canonical_denominator)
      {
      siDump(&(par_block.pars[2].canonical_numerator),   "arg2_h");
      gfHline();
      siDump(&(par_block.pars[2].canonical_denominator), "arg2_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[2].canonical_numerator),   "arg2");
      gfHline();
      }

   /* Print out the result.  We display it differently, depending
   ** on whether it is rational or integral.
   */
   if (!siCompare(&result_denominator, &constant_1))
      {
      /* Denominator is equal to 1.  This is an integer.
      */
      siDump(&result_numerator, "result");
      gfHline();
      }
   else
      {
      siDump(&result_numerator,                          "result_h");
      gfHline();
      siDump(&result_denominator,                        "result_k");
      gfHline();
      }

   siDestroy(&arg1_h);
   siDestroy(&arg1_k);
   siDestroy(&arg2_h);
   siDestroy(&arg2_k);
   siDestroy(&constant_1);
   siDestroy(&result_numerator);
   siDestroy(&result_denominator);
   }


/****************************************************************************/
/* cfSimple2ParIntegerExponentiation():                                     */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles simple integer exponentiation.  Called in response to a        */
/*   template match.                                                        */
/****************************************************************************/
void cfSimple2ParIntegerExponentiation(void)
   {
   SYNTHETIC_INTEGER *result;

   siCreate(&result);
   siIntegerExponentiation(&(par_block.pars[1].canonical_numerator),
                           &(par_block.pars[2].canonical_numerator),
                           &result);
   siDump(&(par_block.pars[1].canonical_numerator), "arg");
   gfHline();
   siDump(&(par_block.pars[2].canonical_numerator), "exponent");
   gfHline();
   siDump(&result, "arg ** exponent");
   gfHline();
   siDestroy(&result);
   }


/****************************************************************************/
/* cfSimple2ParIntegerExponentiationOfRational():                                     */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles a rational raised to an integer power.  Called in response     */
/*   to a template match.                                                   */
/****************************************************************************/
void cfSimple2ParIntegerExponentiationOfRational(void)
   {
   /* There isn't a need to do any conversion, before or after.  Since
   ** the gcd() is removed from numerator and denominator, and since
   ** it isn't an integer, then the numerator and denominator have
   ** different prime components, exponentiating to any power
   ** can't create an integer or even anything that can be reduced.
   ** It would be fruitless to GCD the result.
   */
   SYNTHETIC_INTEGER *result_numerator;
   SYNTHETIC_INTEGER *result_denominator;

   siCreate(&result_numerator);
   siCreate(&result_denominator);

   siIntegerExponentiation(&(par_block.pars[1].canonical_numerator),
                           &(par_block.pars[2].canonical_numerator),
                           &result_numerator);
   siIntegerExponentiation(&(par_block.pars[1].canonical_denominator),
                           &(par_block.pars[2].canonical_numerator),
                           &result_denominator);

   siDump(&(par_block.pars[1].canonical_numerator), "arg_h");
   gfHline();
   siDump(&(par_block.pars[1].canonical_denominator), "arg_k");
   gfHline();
   siDump(&(par_block.pars[2].canonical_numerator), "exponent");
   gfHline();
   siDump(&result_numerator, "arg_h ** exponent");
   gfHline();
   siDump(&result_denominator, "arg_k ** exponent");
   gfHline();

   siDestroy(&result_numerator);
   siDestroy(&result_denominator);
   }


/****************************************************************************/
/* cfSimple2ParIntegerQuotient():                                           */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles simple integer division.  As a courtesy, the remainder is      */
/*   returned as well.                                                      */
/****************************************************************************/
void cfSimple2ParIntegerQuotient(void)         
   {
   SYNTHETIC_INTEGER *quotient;
   SYNTHETIC_INTEGER *remainder;

   siCreate(&quotient);
   siCreate(&remainder);
   siUnrestrictedDivision(&(par_block.pars[1].canonical_numerator),
                          &(par_block.pars[2].canonical_numerator),
                          &quotient,
                          &remainder);
   siDump(&(par_block.pars[1].canonical_numerator), "dividend");
   gfHline();
   siDump(&(par_block.pars[2].canonical_numerator), "divisor");
   gfHline();
   siDump(&remainder, "dividend % divisor");
   gfHline();
   siDump(&quotient, "dividend / divisor");
   gfHline();
   siDestroy(&quotient);
   siDestroy(&remainder);
   }


/****************************************************************************/
/* cfSimple2ParIntegerRemainder():                                          */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles simple integer remainder.  As a courtesy, the quotient is      */
/*   returned as well.                                                      */
/****************************************************************************/
void cfSimple2ParIntegerRemainder(void)         
   {
   SYNTHETIC_INTEGER *quotient;
   SYNTHETIC_INTEGER *remainder;

   siCreate(&quotient);
   siCreate(&remainder);
   siUnrestrictedDivision(&(par_block.pars[1].canonical_numerator),
                          &(par_block.pars[2].canonical_numerator),
                          &quotient,
                          &remainder);
   siDump(&(par_block.pars[1].canonical_numerator), "dividend");
   gfHline();
   siDump(&(par_block.pars[2].canonical_numerator), "divisor");
   gfHline();
   siDump(&quotient, "dividend / divisor");
   gfHline();
   siDump(&remainder, "dividend % divisor");
   gfHline();
   siDestroy(&quotient);
   siDestroy(&remainder);
   }


/****************************************************************************/
/* cfSimple2ParRationalRationalQuotient():                                  */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Handles division of two arbitrary rational numbers.  Called in         */
/*   response to a template match.                                          */
/****************************************************************************/
void cfSimple2ParRationalRationalQuotient(void)
   {
   SYNTHETIC_INTEGER *arg1_h,
                     *arg1_k,
                     *arg2_h,
                     *arg2_k,
                     *constant_1,
                     *result_numerator,
                     *result_denominator;

   siCreate(&arg1_h);
   siCreate(&arg1_k);
   siCreate(&arg2_h);
   siCreate(&arg2_k);
   siCreate(&constant_1);
   siSetToLong(&constant_1, 1);
   siCreate(&result_numerator);
   siCreate(&result_denominator);

   /* Since this function handles the general case where either
   ** or both arguments are rational, we need to watch out and
   ** condition any integer argument to be rational.  We need
   ** to watch out for a missing denominator and assign it to
   ** be "1" if it is missing (meaning that the original argument
   ** was an integer.
   */
   /* Copy over to our scratch space, watching out for integers.
   */
   siCopy(&(par_block.pars[1].canonical_numerator), &arg1_h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &arg1_k);
   else
      siSetToLong(&arg1_k, 1);

   siCopy(&(par_block.pars[2].canonical_numerator), &arg2_h);
   if (par_block.pars[2].canonical_denominator)
      siCopy(&(par_block.pars[2].canonical_denominator), &arg2_k);
   else
      siSetToLong(&arg2_k, 1);

   /* Call the function to calculate the rational product.
   */
   rnQuotient(&arg1_h, &arg1_k, &arg2_h, &arg2_k, &result_numerator, &result_denominator);

   /* Print out the first argument.  We display it differently
   ** depending on if it was rational or integral.
   */
   if (par_block.pars[1].canonical_denominator)
      {
      siDump(&(par_block.pars[1].canonical_numerator),   "arg1_h");
      gfHline();
      siDump(&(par_block.pars[1].canonical_denominator), "arg1_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[1].canonical_numerator),   "arg1");
      gfHline();
      }

   /* Print out the first argument.  We display it differently
   ** depending on if it was rational or integral.
   */
   if (par_block.pars[2].canonical_denominator)
      {
      siDump(&(par_block.pars[2].canonical_numerator),   "arg2_h");
      gfHline();
      siDump(&(par_block.pars[2].canonical_denominator), "arg2_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[2].canonical_numerator),   "arg2");
      gfHline();
      }

   /* Print out the result.  We display it differently, depending
   ** on whether it is rational or integral.
   */
   if (!siCompare(&result_denominator, &constant_1))
      {
      /* Denominator is equal to 1.  This is an integer.
      */
      siDump(&result_numerator, "result");
      gfHline();
      }
   else
      {
      siDump(&result_numerator,                          "result_h");
      gfHline();
      siDump(&result_denominator,                        "result_k");
      gfHline();
      }

   siDestroy(&arg1_h);
   siDestroy(&arg1_k);
   siDestroy(&arg2_h);
   siDestroy(&arg2_k);
   siDestroy(&constant_1);
   siDestroy(&result_numerator);
   siDestroy(&result_denominator);
   }

   
/****************************************************************************/
/* cfSimple2ParIntegerGcd():                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Applies Euclid's algorithm to obtain the gcd() of two positive         */
/*   integers.                                                              */
/****************************************************************************/
void cfSimple2ParIntegerGcd(void)         
   {
   SYNTHETIC_INTEGER *result;

   siCreate(&result);
   siGcd(&(par_block.pars[1].canonical_numerator),
         &(par_block.pars[2].canonical_numerator),
         &result);
   siDump(&(par_block.pars[1].canonical_numerator), "arg1");
   gfHline();
   siDump(&(par_block.pars[2].canonical_numerator), "arg2");
   gfHline();
   siDump(&result, "gcd(arg1, arg2)");
   gfHline();
   siDestroy(&result);
   }


/****************************************************************************/
/* cfDap():                                                                 */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Applies the DAP function as outlined in the manual.                    */
/****************************************************************************/
void cfDap(void)         
   {
   SYNTHETIC_INTEGER *D,          /* The denominator chosen.                */
                     *hD,         /* Product of input h and D.              */
                     *k,          /* Denominator to be used.                */
                     *hD_over_k,  /* Final result.                          */
                     *trash_remainder;  /* Remainder not used.              */

   /* Create all of our locals.
   */
   siCreate(&D);
   siCreate(&hD);
   siCreate(&k);
   siCreate(&hD_over_k);
   siCreate(&trash_remainder);

   /* There are two cases to consider.  Either the user has 
   ** specified a second parameter (the denominator to use),
   ** or we use a default.  Let's assign the default, then
   ** overwrite it with the user's choice.
   */
   siSetToPowerOfTen(&D, DIGITS_PER_LINE * 4);

   /* If the user has specified a second parameter, set D to be
   ** that second parameter.  This overwrites the default
   ** choice of four lines.
   */
   if (par_block.pars[2].ftype == CMDLINE_PAR_TYPE_INTPOS)
      {
      asAssert(par_block.pars[2].canonical_numerator != NULL, __LINE__);

      siCopy(&(par_block.pars[2].canonical_numerator), &D);
      }

   /* Assign the value of k, in case the user is trying to DAP an integer,
   ** which doesn't make sense.
   */
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &k);
   else
      siSetToLong(&k, 1);

   /* Perform the actual DAP calculation. */
   asAssert(par_block.pars[1].canonical_numerator != NULL, __LINE__);
   siUnrestrictedMultiplication(&(par_block.pars[1].canonical_numerator),
                                &D,
                                &hD);
   siUnrestrictedDivision(&hD,
                          &k,
                          &hD_over_k,
                          &trash_remainder);

   /* Print the results. */
   if (par_block.pars[1].canonical_denominator)
      {
      siDump(&(par_block.pars[1].canonical_numerator), "arg_h");
      gfHline();
      siDump(&(par_block.pars[1].canonical_denominator), "arg_k");
      gfHline();
      }
   else
      {
      siDump(&(par_block.pars[1].canonical_numerator), "arg");
      gfHline();
      }

   siDump(&hD_over_k, "N");
   gfHline();
   siDump(&D, "D");
   gfHline();

   /* Destroy all of our locals.
   */
   siDestroy(&D);
   siDestroy(&hD);
   siDestroy(&k);
   siDestroy(&hD_over_k);
   siDestroy(&trash_remainder);
   }


/****************************************************************************/
/* cfCf():                                                                  */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Forms the continued fraction decomposition and convergents of a        */
/*   non-negative rational number.                                          */
/****************************************************************************/
void cfCf(void)         
   {
   SYNTHETIC_INTEGER *h, *k;  /* The numerator and denominator to use
                              ** for the continued fraction expansion.
                              */
   CF_EXPANSION *e;           /* The continued fraction expansion.
                              */

   /* Allocate the integers.
   */
   siCreate(&h);
   siCreate(&k);

   /* Be absolutely sure that we have a viable numerator, and
   ** copy it to what we are using for our numerator.
   */
   asAssert(par_block.pars[1].canonical_numerator != NULL, __LINE__);
   siCopy(&(par_block.pars[1].canonical_numerator), &h);

   /* Use the denominator available, unless it doesn't exist, in
   ** which case will use "1".
   */
   if (par_block.pars[1].canonical_denominator)
      {
      siCopy(&(par_block.pars[1].canonical_denominator), &k);
      }
   else
      {
      siSetToLong(&k, 1);
      }

   /* Create the CF expansion.
   */
   pqCreate(&h, &k, &e);

   /* Print it out.  No description is required.
   */
   pqDump(&e, "", 0);

   /* Destroy the expansion.
   */
   pqDestroy(&e);

   /* Destroy the integers.
   */
   siDestroy(&h);
   siDestroy(&k);
   }


/****************************************************************************/
/* cfFn():                                                                  */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Locates the enclosing Farey neighbors and prints them out.  This func- */
/*   tion is called in response to a template match.                        */
/****************************************************************************/
void cfFn(void)         
   {
   int convergent_number;
   int nneighbors;
   int arg_in_series = FALSE;
   int cur_series_term;

   SYNTHETIC_INTEGER *D, *h, *k, *N, *conv_h, *conv_k, *neigh_h, *neigh_k,
                     *hleft, *kleft, *hright, *kright, *error_h, *error_k,
                     *dap_h, *dap_k, *t1, *t2;
   CF_EXPANSION *expansion;
   char buf[100];

   /* Create all temporary variables.
   */
   siCreate(&D);
   siCreate(&h);
   siCreate(&k);
   siCreate(&N);
   siCreate(&conv_h);
   siCreate(&conv_k);
   siCreate(&neigh_h);
   siCreate(&neigh_k);
   siCreate(&hleft);
   siCreate(&kleft);
   siCreate(&hright);
   siCreate(&kright);
   siCreate(&error_h);
   siCreate(&error_k);
   siCreate(&dap_h);
   siCreate(&dap_k);
   siCreate(&t1);
   siCreate(&t2);

   /* There are either two or four parameters to this command.  For
   ** the optional parameters, they override defaults.
   ** Assign the defaults first, before the optional parameters are
   ** processed.
   */

   /* By default, just generate one Farey neighbor on each side of
   ** the rational number supplied.
   */
   nneighbors = 1;

   /* By default, the denominator used for presentation is good for
   ** four lines of zeros.
   */
   siSetToPowerOfTen(&D, DIGITS_PER_LINE * 4);

   /* Copy the rational number specified for this command to our area,
   ** and if it is an integer provide a denominator of 1 automatically.
   */
   siCopy(&(par_block.pars[1].canonical_numerator), &h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &k);
   else
      siSetToLong(&k, 1);

   /* Copy the order of the series to our area.
   */
   siCopy(&(par_block.pars[2].canonical_numerator), &N);

   /* Convert the number of neighbors to an integer if this command has
   ** the optional arguments.
   */
   if (par_block.pars[3].canonical_numerator)
      {
      SYNTHETIC_INTEGER *n;

      siCreate(&n);

      siSetToLong(&n, 10000);

      if (siCompare(&n, &(par_block.pars[3].canonical_numerator)) <= 0)
         {
         nneighbors = 10000;
         }
      else
         {
         sscanf(par_block.pars[3].orig_string, "%d", &nneighbors);
         }

      siDestroy(&n);
      }

   /* Override the denominator if that parameter is present.
   */
   if (par_block.pars[4].canonical_numerator)
      siCopy(&(par_block.pars[4].canonical_numerator), &D);

   /* Form the continued fraction representation of the 
   ** rational number.
   */
   pqCreate(&h, &k, &expansion);
   
   /* Print out the number and expansion and other input parameters
   ** as output.
   */
   gfBannerHeading("Rational Number h_in/k_in To Approximate", 0);
   gfHline();
   siDump(&h, "h_in");
   gfHline();
   siDump(&k, "k_in");
   gfHline();
   gfBannerHeading("Other Solution Parameters", 0);
   gfHline();
   siDump(&N, "Order");
   gfHline();

      {
      SYNTHETIC_INTEGER *scratch;

      siCreate(&scratch);

      siSetToLong(&scratch, nneighbors);

      siDump(&scratch, "NNEIGHBORS");

      siDestroy(&scratch);
      }

   gfHline();
   siDump(&D, "DAP Denominator");
   gfHline();
   gfBannerHeading("Continued Fraction Expansion Of h_in/k_in", 0);
   gfHline();
   pqDump(&expansion, "", 0);

   /* Obtain the two best rational approximations to the number.
   */
   pqBapp(&expansion,
          &N,
          &conv_h,
          &conv_k,
          &neigh_h,
          &neigh_k,
          &convergent_number);

   /* Print out the information generated by the call above
   */
   gfBannerHeading("Highest-Order Convergent With q(i)<=N", 0);
   gfHline();
   sprintf(buf, "p(%d)", convergent_number);
   siDump(&conv_h, buf);
   sprintf(buf, "q(%d)", convergent_number);
   siDump(&conv_k, buf);
   gfHline();
   gfBannerHeading("Accompanying Intermediate Fraction", 0);
   gfHline();
   siDump(&neigh_h, "intermediate_h");
   siDump(&neigh_k, "intermediate_k");
   gfHline();

   /* Decide, remember, and announce if the term of interest is already in
   ** the Farey series of interest.  This will be true if and only if
   ** the convergent chosen has the same value as the rational argument.
   */
   if (!rnCompare(&conv_h, &conv_k, &h, &k))
      {
      gfBannerHeading("h_in/k_in IS In Farey Series Of Interest", 1);
      arg_in_series = TRUE;
      }
   else
      {
      gfBannerHeading("h_in/k_in IS NOT In Farey Series Of Interest", 1);
      }
   gfHline();

   /* We need to sort the convergent and neighbor back from the cfBapp()
   ** function.  But there is a bit of a catch.  We need to know the
   ** correct index to go along with the left one.  This gets a bit
   ** complicated if the convergent was already in the Farey series.
   ** We'll only give the subscript of 0 if the rational number is
   ** in the Farey series.
   */
   if (rnCompare(&conv_h, &conv_k, &neigh_h, &neigh_k) < 0)
      {
      siCopy(&conv_h, &hleft);
      siCopy(&conv_k, &kleft);
      siCopy(&neigh_h, &hright);
      siCopy(&neigh_k, &kright);

      if (arg_in_series)
         cur_series_term = 0;
      else
         cur_series_term = -1;
      }
   else
      {
      siCopy(&neigh_h, &hleft);
      siCopy(&neigh_k, &kleft);
      siCopy(&conv_h,  &hright);
      siCopy(&conv_k,  &kright);

      cur_series_term = -1;
      }

   /* Loop backwards through the Farey series until either we hit zero
   ** or we hit the number of neighbors we need.
   */
   while ((hleft->len) && (cur_series_term > -nneighbors))
      {
      rnFareyTraverse(&hleft, &kleft, &hright, &kright, &N, -1);
      cur_series_term--;
      }

   /* Now, go forward.  If the rational number specified was already in
   ** the series, we use the subscript zero, otherwise not.
   */
   while (cur_series_term <= nneighbors)
      {
      /* Heading */
      sprintf(buf, "Farey Neighbor Index %d", cur_series_term);
      gfBannerHeading(buf, 0);
      gfHline();

      /* The actual term. */
      sprintf(buf, "h(%d)", cur_series_term);
      siDump(&hleft, buf);
      gfHline();
      buf[0] = 'k';
      siDump(&kleft, buf);
      gfHline();

      /* Also present the rational number as a decimal.
      */
      siCopy(&D, &dap_k);
      rnDap(&hleft, &kleft, &dap_h, &dap_k);
      sprintf(buf, "DAP_N(%d)", cur_series_term);
      siDump(&dap_h, buf);
      gfHline();
      sprintf(buf, "DAP_D(%d)", cur_series_term);
      siDump(&dap_k, buf);
      gfHline();

      /* Rational difference between the rational number we're trying 
      ** to approximate and the approximation we have.  Canonically, we
      ** want a larger approximation to have a positive error, so we 
      ** define error as (approximation - actual).
      */
      /* Calculate the difference as a rational number.
      */
      rnDifference(&hleft, &kleft, &h, &k, &error_h, &error_k);

      /* Present it as a rational number. */
      sprintf(buf, "error_h(%d)", cur_series_term);
      siDump(&error_h, buf);
      gfHline();
      sprintf(buf, "error_k(%d)", cur_series_term);
      siDump(&error_k, buf);
      gfHline();


      /* Present it as a DAP. */
      siCopy(&D, &dap_k);
      rnDap(&error_h, &error_k, &dap_h, &dap_k);
      sprintf(buf, "ERROR_DAP_N(%d)", cur_series_term);
      siDump(&dap_h, buf);
      gfHline();
      sprintf(buf, "ERROR_DAP_D(%d)", cur_series_term);
      siDump(&dap_k, buf);
      gfHline();


      rnFareyTraverse(&hleft, &kleft, &hright, &kright, &N, 1);

      if (arg_in_series)
         {
         cur_series_term++;
         }
      else
         {
         if (cur_series_term == -1)
            cur_series_term = 1;
         else
            cur_series_term++;
         }
      }

   /* Destroy all local variables. 
   */
   siDestroy(&D);
   siDestroy(&h);
   siDestroy(&k);
   siDestroy(&N);
   siDestroy(&conv_h);
   siDestroy(&conv_k);
   siDestroy(&neigh_h);
   siDestroy(&neigh_k);
   siDestroy(&hleft);
   siDestroy(&kleft);
   siDestroy(&hright);
   siDestroy(&kright);
   siDestroy(&error_h);
   siDestroy(&error_k);
   siDestroy(&dap_h);
   siDestroy(&dap_k);
   siDestroy(&t1);
   siDestroy(&t2);
   }


/****************************************************************************/
/* cfMind():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Locates the enclosing Farey neighbors and prints them out.  This func- */
/*   tion is called in response to a template match.                        */
/****************************************************************************/
void cfMind(void)         
   {
   SYNTHETIC_INTEGER *r1_h, *r1_k, *r2_h, *r2_k,
                     *result_h, *result_k;

   /* Allocate all of our local variables.
   */
   siCreate(&r1_h);
   siCreate(&r1_k);
   siCreate(&r2_h);
   siCreate(&r2_k);
   siCreate(&result_h);
   siCreate(&result_k);

   /* State the two input parameters as rational numbers, in case
   ** on or both are integers.
   */
   asAssert(par_block.pars[1].canonical_numerator != NULL, __LINE__);
   asAssert(par_block.pars[2].canonical_numerator != NULL, __LINE__);
   siCopy(&(par_block.pars[1].canonical_numerator), &r1_h);
   siCopy(&(par_block.pars[2].canonical_numerator), &r2_h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &r1_k);
   else
      siSetToLong(&r1_k, 1);
   if (par_block.pars[2].canonical_denominator)
      siCopy(&(par_block.pars[2].canonical_denominator), &r2_k);
   else
      siSetToLong(&r2_k, 1);

   /* If the parameters for the interval are out of order,
   ** swap them.
   */
   if (rnCompare(&r1_h, &r1_k, &r2_h, &r2_k) == 1)
      {
      SYNTHETIC_INTEGER *temp;

      /* Out of order, swap them.  For our application,
      ** can just play with pointers.
      */
      temp = r1_h;
      r1_h = r2_h;
      r2_h = temp;
      temp = r1_k;
      r1_k = r2_k;
      r2_k = temp;
      }

   /* Echo back the parameters for the caller.
   */
   siDump(&r1_h, "l_h");
   gfHline();
   siDump(&r1_k, "l_k");
   gfHline();
   siDump(&r2_h, "r_h");
   gfHline();
   siDump(&r2_k, "r_k");
   gfHline();

   /* Do the calculation proper.
   */
   naMind(&r1_h,
          &r1_k,
          &r2_h,
          &r2_k,
          &result_h,
          &result_k,
          TRUE,
          TRUE,
          FALSE
          );

   /* Emit the results.
   */
   gfBannerHeading("A Rational Number With Smallest Denominator In Interval", 0);
   gfHline();
   siDump(&result_h, "result_h");
   gfHline();
   siDump(&result_k, "result_k");
   gfHline();

   /* Destroy the locals.
   */
   siDestroy(&r1_h);
   siDestroy(&r1_k);
   siDestroy(&r2_h);
   siDestroy(&r2_k);
   siDestroy(&result_h);
   siDestroy(&result_k);
   }


/****************************************************************************/
/* cfFab():                                                                 */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Locates the enclosing Farey neighbors in the doubly-constrained series */
/*   and prints them out.  Called in response to a template match.          */
/****************************************************************************/
void cfFab(void)         
   {
   int convergent_number;
      /* The convergent number we are iterating through.
      */
   int nneighbors;
      /* The number of neighbors on both sides to generate.
      */
   int arg_in_series = FALSE;
      /* TRUE if the rational argument supplied is in the
      ** series, or FALSE otherwise.
      */
   int cur_series_term;
      /* The current series term we're iterating through.
      ** Terms are indexed backwards and forwards from
      ** zero.
      */
   int done = FALSE;
      /* Flag used to exit from the forward-generation loop, as successive
      ** Farey terms are displayed.
      */

   SYNTHETIC_INTEGER *D, /* The denominator that will be used for
                         ** decimal approximation.
                         */
                     *h, *k, 
                         /* Numerator and denominator of rational
                         ** number that we are bracketing with
                         ** Farey terms.
                         */
                     *hmax,
                     *kmax,
                         /* The maximum numerator and denominator,
                         ** i.e. this defines the rectangular
                         ** area of the integer lattice we are
                         ** considering.
                         */
                     *canonical_hmax,
                     *canonical_kmax,
                         /* The reduced form of hmax and kmax, i.e.
                         ** with the g.c.d. removed.  This is necessary
                         ** because hmax and kmax proper are used to
                         ** test denominators, but this value will
                         ** show up in the Farey series.
                         */
                     *normal_corner_predecessor_h,
                     *normal_corner_predecessor_k,
                         /* The predecessor to the corner point
                         ** along the "right" edge of the rectangle.
                         */
                     *reciprocal_corner_successor_h,
                     *reciprocal_corner_successor_k,
                         /* The successor to the corner point
                         ** in the series along the "top" of
                         ** the rectangle.
                         */
                     *constant_1,
                     *constant_0,
                         /* Numerical constants for easy comparison.
                         */
                     *conv_h, 
                     *conv_k, 
                         /* The highest-order convergent with denominator
                         ** not larger than the order of the Farey series.
                         ** Used for calls to pqBapp().
                         */
                     *neigh_h, 
                     *neigh_k,
                         /* The neighbor to the number of interest.  Used for
                         ** calls to pqBapp().
                         */
                     *hleft, 
                     *kleft, 
                     *hright, 
                     *kright, 
                         /* The left and right numbers used to iterate through the
                         ** Farey series using the recursive formulas.
                         */
                     *error_h, 
                     *error_k,
                         /* The error for an approximation, as a rational number.
                         */
                     *dap_h, 
                     *dap_k, 
                         /* The error for an approximation, expressed with a
                         ** different denominator, chosen either by default
                         ** or from the command line.
                         */
                     *t1, 
                     *t2;
                         /* General-purpose temporary variables.
                         */

   CF_EXPANSION *rn_expansion = NULL,
                   /* The continued fraction and convergent
                   ** expansion of the rational number to approximate.
                   */
                *rn_reciprocal_expansion = NULL,
                   /* The continued fraction and convergent expansion
                   ** of the reciprocal of the number to be
                   ** approximated.  This can only be done if the 
                   ** number is non-zero.
                   */
                *corner_point_expansion = NULL,
                   /* The CF expansion of the corner point.  This is
                   ** necessary to get the neighbor just to the left
                   ** in F_N.
                   */
                *corner_point_reciprocal_expansion = NULL;
                   /* The expansion of the reciprocal of the
                   ** corner point.  This is necessary to get
                   ** the neighbor along the "top" of the lattice.
                   */

   char buf[100];
      /* String buffer, used to stage things to be printed.
      */

   /* Create all temporary variables.
   */
   siCreate(&D);
   siCreate(&h);
   siCreate(&k);
   siCreate(&hmax);
   siCreate(&kmax);
   siCreate(&canonical_hmax);
   siCreate(&canonical_kmax);
   siCreate(&normal_corner_predecessor_h);
   siCreate(&normal_corner_predecessor_k);
   siCreate(&reciprocal_corner_successor_h);
   siCreate(&reciprocal_corner_successor_k);
   siCreate(&constant_1);
   siSetToLong(&constant_1, 1);
   siCreate(&constant_0);
   siSetToLong(&constant_0, 0);
   siCreate(&conv_h);
   siCreate(&conv_k);
   siCreate(&neigh_h);
   siCreate(&neigh_k);
   siCreate(&hleft);
   siCreate(&kleft);
   siCreate(&hright);
   siCreate(&kright);
   siCreate(&error_h);
   siCreate(&error_k);
   siCreate(&dap_h);
   siCreate(&dap_k);
   siCreate(&t1);
   siCreate(&t2);

   /* There are either three or five parameters to this command.  For
   ** the optional parameters, they override defaults.
   ** Assign the defaults first, before the optional parameters are
   ** processed.
   */

   /* By default, just generate one Farey neighbor on each side of
   ** the rational number supplied.
   */
   nneighbors = 1;

   /* By default, the denominator used for presentation is good for
   ** four lines of zeros.
   */
   siSetToPowerOfTen(&D, DIGITS_PER_LINE * 4);

   /* Copy the rational number specified for this command to our area,
   ** and if it is an integer provide a denominator of 1 automatically.
   */
   siCopy(&(par_block.pars[1].canonical_numerator), &h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &k);
   else
      siSetToLong(&k, 1);

   /* Copy the maximum h and maximum k to our area.
   */
   siCopy(&(par_block.pars[2].canonical_numerator), &hmax);
   siCopy(&(par_block.pars[3].canonical_numerator), &kmax);

   /* Copy an extra copy of these to the canonical values,
   ** and must remove the GCD.
   */
   siCopy(&hmax, &canonical_hmax);
   siCopy(&kmax, &canonical_kmax);
   rnCanonize(&canonical_hmax, &canonical_kmax);

   /* Convert the number of neighbors to an integer if this command has
   ** the optional arguments.
   */
   if (par_block.pars[4].canonical_numerator)
      {
      SYNTHETIC_INTEGER *n;

      siCreate(&n);

      siSetToLong(&n, 10000);

      if (siCompare(&n, &(par_block.pars[4].canonical_numerator)) <= 0)
         {
         nneighbors = 10000;
         }
      else
         {
         sscanf(par_block.pars[4].orig_string, "%d", &nneighbors);
         }

      siDestroy(&n);
      }

   /* Override the denominator if that parameter is present.
   */
   if (par_block.pars[5].canonical_numerator)
      siCopy(&(par_block.pars[5].canonical_numerator), &D);

   /* Form the continued fraction representation of the 
   ** rational number.
   */
   pqCreate(&h, &k, &rn_expansion);
   
   /* Form the continued fraction representation of the
   ** reciprocal in any case besides the number
   ** zero.
   */
   if (h->len)
      pqCreate(&k, &h, &rn_reciprocal_expansion);

   /* Print out the number and expansion and other input parameters
   ** as output.
   */
   gfBannerHeading("Rational Number h_in/k_in To Approximate", 0);
   gfHline();
   siDump(&h, "h_in");
   gfHline();
   siDump(&k, "k_in");
   gfHline();
   gfBannerHeading("Other Solution Parameters", 0);
   gfHline();
   siDump(&hmax, "hmax");
   gfHline();
   siDump(&kmax, "kmax");
   gfHline();

      {
      SYNTHETIC_INTEGER *scratch;

      siCreate(&scratch);

      siSetToLong(&scratch, nneighbors);

      siDump(&scratch, "NNEIGHBORS");

      siDestroy(&scratch);
      }

   gfHline();
   siDump(&D, "DAP Denominator");
   gfHline();
   gfBannerHeading("Continued Fraction Expansion Of h_in/k_in", 0);
   gfHline();
   pqDump(&rn_expansion, "", 0);

   if (rn_reciprocal_expansion)
      {
      gfBannerHeading("Continued Fraction Expansion Of k_in/h_in", 0);
      gfHline();
      pqDump(&rn_reciprocal_expansion, "", 0);
      }

   /* Now we need to obtain the neighbors of the "corner point"
   ** in both of the Farey series involved.  It is more
   ** straightforward to generate them in advance.
   */
   /* First, get the continued fraction expansion of the
   ** corner point in normal coordinates, and output the result.
   */
   pqCreate(&canonical_hmax, &canonical_kmax, &corner_point_expansion);
   gfBannerHeading("Continued Fraction Expansion Of Corner Point", 0);
   gfHline();
   pqDump(&corner_point_expansion, "", 0);

   /* Now, get the continued fraction expansion of the
   ** corner point in inverted coordinates, and output the result.
   */
   pqCreate(&canonical_kmax, &canonical_hmax, &corner_point_reciprocal_expansion);
   gfBannerHeading("Continued Fraction Expansion Of Corner Point Reciprocal", 0);
   gfHline();
   pqDump(&corner_point_reciprocal_expansion, "", 0);

   /* Find the best approximation along the right edge to the corner
   ** point.  Depending on whether have even or odd convergents,
   ** may get above or below the corner point.  If get above,
   ** must go down using standard recursive formulas.
   */
   pqBapp(&corner_point_expansion,
          &kmax,
          &conv_h,
          &conv_k,
          &normal_corner_predecessor_h,
          &normal_corner_predecessor_k,
          &convergent_number);
   /* We may have the Farey term either left or right.  If right,
   ** must backtrack by one.
   */
   if (rnCompare(&canonical_hmax, &canonical_kmax,
                 &normal_corner_predecessor_h, &normal_corner_predecessor_k)
                 < 0)
      {
      SYNTHETIC_INTEGER *temp_h, *temp_k;

      /* printf("REVERSE! (corner point predecessor)\n"); */

      /* Must get the predecessor.
      */
      siCreate(&temp_h);
      siCreate(&temp_k);

      siCopy(&canonical_hmax, &temp_h);
      siCopy(&canonical_kmax, &temp_k);

      rnFareyTraverse(&temp_h, 
                      &temp_k, 
                      &normal_corner_predecessor_h, 
                      &normal_corner_predecessor_k, 
                      &kmax, 
                      -1);
      siCopy(&temp_h, &normal_corner_predecessor_h);
      siCopy(&temp_k, &normal_corner_predecessor_k);

      siDestroy(&temp_h);
      siDestroy(&temp_k);
      }

   gfBannerHeading("Corner Point Neighbors", 0);
   gfHline();
   siDump(&normal_corner_predecessor_h, "corner_pred_h");
   siDump(&normal_corner_predecessor_k, "corner_pred_k");
   gfHline();

   /* Find the best approximation along the top edge to the corner
   ** point.  Depending on whether have even or odd convergents,
   ** may get left or right of the corner point.  If get left,
   ** must go right using standard recursive formulas.  There is, however,
   ** one exception.  If kmax = 1, there will be nothing to the right
   ** of the corner point, and must just keep value as zero over zero
   ** as a marker.
   */
   if (siCompare(&constant_1, &kmax) == 0)
      {
      /* In this case, there is no point to the right.
      ** Assign the successor to be be 0/0, as a marker.
      */
      siSetToLong(&reciprocal_corner_successor_h, 0);
      siSetToLong(&reciprocal_corner_successor_k, 0);
      }
   else
      {
      /* There is a successor to the right.
      */

      SYNTHETIC_INTEGER *temph, *tempk;

      siCreate(&temph);
      siCreate(&tempk); 

      /* There is a point to the right.  It will take a few
      ** contortions to find it.
      */
      /* What this statement does is to operate in the
      ** inverted series along the top edge of the 
      ** rectangle.
      */
      pqBapp(&corner_point_reciprocal_expansion,
             &hmax,
             &conv_k,
             &conv_h,
             &reciprocal_corner_successor_k,
             &reciprocal_corner_successor_h,
             &convergent_number);

      /* We may have either the left or the right neighbor, but we
      ** need the right.  This gets messy.  We need to invert when finding, including
      ** inverting the order.
      */
      if (rnCompare(&canonical_hmax, 
                    &canonical_kmax, 
                    &reciprocal_corner_successor_h, 
                    &reciprocal_corner_successor_k) == 1)
         {
         /* We wanted something to the right, but we got it to the left.
         ** We need to find the PREDECESSOR (not the successor) 
         ** in the inverted Farey series.
         */

         /* printf("REVERSE! (corner point successor)\n"); */
         /* Must get the predecessor.
         */

         siCopy(&canonical_hmax, &temph);
         siCopy(&canonical_kmax, &tempk);

         rnFareyTraverse(&tempk, 
                         &temph, 
                         &reciprocal_corner_successor_k, 
                         &reciprocal_corner_successor_h, 
                         &hmax, 
                         -1);
         siCopy(&temph, &reciprocal_corner_successor_h);
         siCopy(&tempk, &reciprocal_corner_successor_k);
         }

      siDestroy(&temph);
      siDestroy(&tempk); 
      }

   siDump(&reciprocal_corner_successor_h, "corner_succ_h");
   siDump(&reciprocal_corner_successor_k, "corner_succ_k");
   gfHline();

   /* Decide, remember, and announce if the term of interest is already in
   ** the Farey series of interest.  The easiest test for this under two
   ** constraints is that both numerator and denominator would be in bounds.
   */
   if ((siCompare(&h,&hmax) <= 0) && (siCompare(&k, &kmax) <= 0))
      {
      gfBannerHeading("h_in/k_in IS In Rectangular Farey Series Of Interest", 1);
      arg_in_series = TRUE;
      }
   else
      {
      gfBannerHeading("h_in/k_in IS NOT In Rectangular Farey Series Of Interest", 1);
      }
   gfHline();


   /* Obtain the two best rational approximations to the number.  We want to create
   ** two numbers such that the left one is either our number or its left neighbor,
   ** and the right one is our numbers's right neighbor, if it has one.
   ** 
   ** There are four cases to consider:
   **
   **    hmax/1 <= h/k
   **       In this case, the right neighbor is undefined and the left
   **       neighbor is hmax/1.
   **
   **    hmax/kmax < h/k < hmax/1
   **       The neighbors can be found by searching in the "inverted"
   **       Farey series.
   **
   **    h/k = hmax/kmax
   **       The left neighbor is h/k, the right is an adjacent point to the
   **       corner point.
   **    
   **    0 <= h/k < hmax/kmax
   **       The neighbors can be found by searching in the normal Farey
   **       series.
   */
   if (rnCompare(&hmax, &constant_1, &h, &k) <= 0)
      {
      /*    hmax/1 <= h/k
      **       In this case, the right neighbor is undefined and the left
      **       neighbor is hmax/1.
      */
      /* This is a much simpler case.  Can just assign.      
      */
      gfBannerHeading("hmax/1 <= h/k", 0);
      gfHline();

      siCopy(&hmax, &hleft);
      siSetToLong(&kleft, 1);
      siSetToLong(&hright, 0);
      siSetToLong(&kright, 0);

      if (arg_in_series)
         cur_series_term = 0;
      else
         cur_series_term = -1;
      }
   else if (rnCompare(&hmax, &kmax, &h, &k) < 0)
      {
      /*    hmax/kmax < h/k < hmax/1
      **       The neighbors can be found by searching in the "inverted"
      **       Farey series.
      */
      pqBapp(&rn_reciprocal_expansion,
             &hmax,
             &conv_k,
             &conv_h,
             &neigh_k,
             &neigh_h,
             &convergent_number);

      /* Print out the information generated by the call above
      */
      gfBannerHeading("hmax/kmax < h/k < hmax/1", 0);
      gfHline();
      gfBannerHeading("Highest-Order Convergent With q(i)<=N", 0);
      gfHline();
      sprintf(buf, "p(%d)", convergent_number);
      siDump(&conv_h, buf);
      sprintf(buf, "q(%d)", convergent_number);
      siDump(&conv_k, buf);
      gfHline();
      gfBannerHeading("Accompanying Intermediate Fraction", 0);
      gfHline();
      siDump(&neigh_h, "intermediate_h");
      siDump(&neigh_k, "intermediate_k");
      gfHline();

      /* We need to sort the convergent and neighbor back from the cfBapp()
      ** function.  But there is a bit of a catch.  We need to know the
      ** correct index to go along with the left one.  This gets a bit
      ** complicated if the convergent was already in the Farey series.
      ** We'll only give the subscript of 0 if the rational number is
      ** in the Farey series.
      */
      if (rnCompare(&conv_h, &conv_k, &neigh_h, &neigh_k) < 0)
         {
         /* Convergent and neighbor are ascending in order.  Can
         ** leave exactly as is.
         */
         siCopy(&conv_h, &hleft);
         siCopy(&conv_k, &kleft);
         siCopy(&neigh_h, &hright);
         siCopy(&neigh_k, &kright);

         if (arg_in_series)
            cur_series_term = 0;
         else
            cur_series_term = -1;
         }
      else
         {
         /* Convergent and neighbor are descending in order.
         ** There are two possibilities.  If the number
         ** is in the rectangular series, need to traverse.
         ** Otherwise, will need to swap, as number is in
         ** between.
         */
         if (arg_in_series)
            {
            siCopy(&neigh_h, &hleft);
            siCopy(&neigh_k, &kleft);
            siCopy(&conv_h,  &hright);
            siCopy(&conv_k,  &kright);

            rnFareyTraverse(&kright, &hright, &kleft, &hleft, &hmax, -1);

            cur_series_term = 0;
            }
         else
            {
            siCopy(&neigh_h, &hleft);
            siCopy(&neigh_k, &kleft);
            siCopy(&conv_h,  &hright);
            siCopy(&conv_k,  &kright);

            cur_series_term = -1;
            }
         }
      }
   else if (rnCompare(&hmax, &kmax, &h, &k) == 0)
      {
      /* printf("Reached equality case.\n"); */

      /*    h/k = hmax/kmax
      **       The left neighbor is h/k, the right is an adjacent point to the
      **       corner point.
      */
      /* This is a much simpler case.  Can just assign, as we have calculated everything
      ** of interest about the corner point already.
      */
      gfBannerHeading("h_in/k_in == hmax/kmax", 0);
      gfHline();
      gfBannerHeading("Point To Right Of Corner Point", 0);
      gfHline();
      siDump(&reciprocal_corner_successor_h, "successor_h");
      siDump(&reciprocal_corner_successor_k, "successor_k");
      gfHline();

      siCopy(&canonical_hmax, &hleft);
      siCopy(&canonical_kmax, &kleft);
      siCopy(&reciprocal_corner_successor_h, &hright);
      siCopy(&reciprocal_corner_successor_k, &kright);

      cur_series_term = 0;  /* Left member is exactly equal to h/k. */
      }
   else
      {
      /*    0 <= h/k < hmax/kmax
      **       The neighbors can be found by searching in the normal Farey
      **       series.
      */
      pqBapp(&rn_expansion,
             &kmax,
             &conv_h,
             &conv_k,
             &neigh_h,
             &neigh_k,
             &convergent_number);

      /* Print out the information generated by the call above
      */
      gfBannerHeading("0 <= h_in/k_in < hmax/kmax", 0);
      gfHline();
      gfBannerHeading("Highest-Order Convergent With q(i)<=N", 0);
      gfHline();
      sprintf(buf, "p(%d)", convergent_number);
      siDump(&conv_h, buf);
      sprintf(buf, "q(%d)", convergent_number);
      siDump(&conv_k, buf);
      gfHline();
      gfBannerHeading("Accompanying Intermediate Fraction", 0);
      gfHline();
      siDump(&neigh_h, "intermediate_h");
      siDump(&neigh_k, "intermediate_k");
      gfHline();

      /* We need to sort the convergent and neighbor back from the cfBapp()
      ** function.  But there is a bit of a catch.  We need to know the
      ** correct index to go along with the left one.  This gets a bit
      ** complicated if the convergent was already in the Farey series.
      ** We'll only give the subscript of 0 if the rational number is
      ** in the Farey series.
      */
      if (rnCompare(&conv_h, &conv_k, &neigh_h, &neigh_k) < 0)
         {
         siCopy(&conv_h, &hleft);
         siCopy(&conv_k, &kleft);
         siCopy(&neigh_h, &hright);
         siCopy(&neigh_k, &kright);

         if (arg_in_series)
            cur_series_term = 0;
         else
            cur_series_term = -1;
         }
      else
         {
         siCopy(&neigh_h, &hleft);
         siCopy(&neigh_k, &kleft);
         siCopy(&conv_h,  &hright);
         siCopy(&conv_k,  &kright);

         if (arg_in_series)
            rnFareyTraverse(&hleft, &kleft, &hright, &kright, &kmax, 1);

         if (arg_in_series)
            cur_series_term = 0;
         else
            cur_series_term = -1;
         }
      }

   #if 0
   printf ("Past Bap\n");
   siDump(&hleft, "hleft");
   siDump(&kleft, "kleft");
   siDump(&hright, "hright");
   siDump(&kright, "kright");
   printf("cur_series_term: %d\n", cur_series_term);
   #endif

   /* At this point we know the neighbors of the corner point, and the neighbors
   ** of the h/k.  We want to search downward until we exhaust the number of 
   ** neighbors required or until we hit zero.  The complicated thing is that
   ** in the rectangular case, there are special cases, especially as we round 
   ** the corner.
   */
   while ((hleft->len) && (cur_series_term > -nneighbors))
      {
      if (rnCompare(&hleft,&kleft,&canonical_hmax,&canonical_kmax)==0)
         {
         /* The left term is the corner point.  Need to "round the corner".
         */
         siCopy(&hleft, &hright);
         siCopy(&kleft, &kright);
         siCopy(&normal_corner_predecessor_h, &hleft);
         siCopy(&normal_corner_predecessor_k, &kleft);
         cur_series_term--;
         }
      else if (rnCompare(&hleft, &kleft, &hmax, &constant_1) == 0)
         {
         /* The left term is hmax/1.  Need to get the correct right neighbor
         ** and go backwards by 1 in the inverted Farey series.
         */
         siSetToLong(&hright, 1);
         siSetToLong(&kright, 0);
         rnFareyTraverse(&kright, &hright, &kleft, &hleft, &hmax, 1);
         cur_series_term--;
         }
      else if (rnCompare(&hleft, &kleft, &hmax, &kmax) > 0)
         {
         /* We are to the right of the corner point.  Need to progress
         ** in the inverted Farey series.
         */
         rnFareyTraverse(&kright, &hright, &kleft, &hleft, &hmax, 1);
         cur_series_term--;
         }
      else
         {
         /* We are to the left of the corner point.  Simply go
         ** backwards in the Farey series.
         */
         rnFareyTraverse(&hleft, &kleft, &hright, &kright, &kmax, -1);
         cur_series_term--;
         }
      }

   #if 0
   printf("Past reverse traversal.\n");
   siDump(&hleft, "hleft");
   siDump(&kleft, "kleft");
   siDump(&hright, "hright");
   siDump(&kright, "kright");
   printf("cur_series_term: %d\n", cur_series_term);
   #endif

   /* Now, go forward.  If the rational number specified was already in
   ** the series, we use the subscript zero, otherwise not.
   */
   while ((cur_series_term <= nneighbors) && !done)
      {
      /* Heading */
      sprintf(buf, "Rectangular Farey Neighbor Index %d", cur_series_term);
      gfBannerHeading(buf, 0);
      gfHline();

      /* The actual term. */
      sprintf(buf, "h(%d)", cur_series_term);
      siDump(&hleft, buf);
      gfHline();
      buf[0] = 'k';
      siDump(&kleft, buf);
      gfHline();

      /* Also present the rational number as a decimal.
      */
      siCopy(&D, &dap_k);
      rnDap(&hleft, &kleft, &dap_h, &dap_k);
      sprintf(buf, "DAP_N(%d)", cur_series_term);
      siDump(&dap_h, buf);
      gfHline();
      sprintf(buf, "DAP_D(%d)", cur_series_term);
      siDump(&dap_k, buf);
      gfHline();

      /* Rational difference between the rational number we're trying 
      ** to approximate and the approximation we have.  Canonically, we
      ** want a larger approximation to have a positive error, so we 
      ** define error as (approximation - actual).
      */
      /* Calculate the difference as a rational number.
      */
      rnDifference(&hleft, &kleft, &h, &k, &error_h, &error_k);

      /* Present it as a rational number. */
      sprintf(buf, "error_h(%d)", cur_series_term);
      siDump(&error_h, buf);
      gfHline();
      sprintf(buf, "error_k(%d)", cur_series_term);
      siDump(&error_k, buf);
      gfHline();

      /* Present it as a DAP. */
      siCopy(&D, &dap_k);
      rnDap(&error_h, &error_k, &dap_h, &dap_k);
      sprintf(buf, "ERROR_DAP_N(%d)", cur_series_term);
      siDump(&dap_h, buf);
      gfHline();
      sprintf(buf, "ERROR_DAP_D(%d)", cur_series_term);
      siDump(&dap_k, buf);
      gfHline();

      /* Advance the series counter.  We need to skip zero if the 
      ** number ain't in the series.
      */
      if (arg_in_series)
         {
         cur_series_term++;
         }
      else
         {
         if (cur_series_term == -1)
            cur_series_term = 1;
         else
            cur_series_term++;
         }

      /* Advance the rectangular series forward.  There are special cases
      ** as we "round the corner", plus need to set a "done" flag if can
      ** go no further.
      */
      if (rnCompare(&hleft, &kleft, &hmax, &constant_1) == 0)
         {
         /* The left term is hmax/1.  Can't go any further.
         */
         done = TRUE;
         }
      else if (rnCompare(&hright,&kright,&canonical_hmax,&canonical_kmax)==0)
         {
         /* The right term is the corner point.  Need to "round the corner".
         */
         siCopy(&hright, &hleft);
         siCopy(&kright, &kleft);
         siCopy(&reciprocal_corner_successor_h, &hright);
         siCopy(&reciprocal_corner_successor_k, &kright);
         }
      else if (rnCompare(&hleft, &kleft, &hmax, &kmax) >= 0)
         {
         /* We are to the right of the corner point.  Need to progress
         ** in the inverted Farey series.
         */
         #if 0
         printf("Before.\n");
         siDump(&kright, "kright");
         siDump(&hright, "hright");
         siDump(&kleft,  "kleft");
         siDump(&hleft,  "hleft");
         siDump(&hmax,   "hmax");
         #endif
         rnFareyTraverse(&kright, &hright, &kleft, &hleft, &hmax, -1);
         #if 0
         printf("After.\n");
         siDump(&kright, "kright");
         siDump(&hright, "hright");
         siDump(&kleft,  "kleft");
         siDump(&hleft,  "hleft");
         siDump(&hmax,   "hmax");
         #endif
         }
      else
         {
         /* We are left of the corner point.  Normal Farey progression.
         */
         rnFareyTraverse(&hleft, &kleft, &hright, &kright, &kmax, 1);
         }
      }

   /* Destroy CF expansions.
   */
   if (rn_expansion)
      pqDestroy(&rn_expansion);
   if (rn_reciprocal_expansion)
      pqDestroy(&rn_reciprocal_expansion);
   if (corner_point_expansion)
      pqDestroy(&corner_point_expansion);
   if (corner_point_reciprocal_expansion);
      pqDestroy(&corner_point_reciprocal_expansion);

   /* Destroy all local variables. 
   */
   siDestroy(&D);
   siDestroy(&h);
   siDestroy(&k);
   siDestroy(&hmax);
   siDestroy(&kmax);
   siDestroy(&canonical_hmax);
   siDestroy(&canonical_kmax);
   siDestroy(&normal_corner_predecessor_h);
   siDestroy(&normal_corner_predecessor_k);
   siDestroy(&reciprocal_corner_successor_h);
   siDestroy(&reciprocal_corner_successor_k);
   siDestroy(&constant_1);
   siDestroy(&constant_0);
   siDestroy(&conv_h);
   siDestroy(&conv_k);
   siDestroy(&neigh_h);
   siDestroy(&neigh_k);
   siDestroy(&hleft);
   siDestroy(&kleft);
   siDestroy(&hright);
   siDestroy(&kright);
   siDestroy(&error_h);
   siDestroy(&error_k);
   siDestroy(&dap_h);
   siDestroy(&dap_k);
   siDestroy(&t1);
   siDestroy(&t2);
   }


/****************************************************************************/
/* cfFndmax():                                                              */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Calculates an upper bound between the terms in the Farey series of     */
/*   a certain order in an interval.                                        */
/****************************************************************************/
void cfFndmax(void)         
   {
   SYNTHETIC_INTEGER 
      *r1_h, *r1_k, 
         /* Left interval endpoint.
         */
      *r2_h, *r2_k,
         /* Right interval endpoint.
         */
      *result_h, *result_k, 
         /* The fraction in the interval with the
         ** smallest denominator.
         */
      *D, 
         /* The DAP denominator to be used.
         */
      *kmax,
         /* The maximum denominator (i.e. the order of the
         ** Farey series of interest).
         */
      *kmax_minus_qmin,
         /* The order of the Farey series minus the minimum
         ** denominator.
         */
      *error_h, *error_k,
         /* The error bound, expressed as a rational
         ** number.
         */
      *dap_N;
         /* The DAP numerator.
         */

   /* Allocate all of our local variables.
   */
   siCreate(&r1_h);
   siCreate(&r1_k);
   siCreate(&r2_h);
   siCreate(&r2_k);
   siCreate(&result_h);
   siCreate(&result_k);
   siCreate(&D);
   siCreate(&kmax);
   siCreate(&kmax_minus_qmin);
   siCreate(&error_h);
   siCreate(&error_k);
   siCreate(&dap_N);

   /* Record the order of the series in which we are operating.
   */
   asAssert(par_block.pars[3].canonical_numerator != NULL, __LINE__);
   siCopy(&(par_block.pars[3].canonical_numerator), &kmax);

   /* If a different DAP denominator is specified, record that.
   */
   if (par_block.pars[4].canonical_numerator)
      {
      siCopy(&(par_block.pars[4].canonical_numerator), &D);
      }
   else
      {
      siSetToPowerOfTen(&D, DIGITS_PER_LINE * 4);
      }

   /* State the two interval endpoints as rational numbers, in case
   ** one or both are integers.
   */
   asAssert(par_block.pars[1].canonical_numerator != NULL, __LINE__);
   asAssert(par_block.pars[2].canonical_numerator != NULL, __LINE__);
   siCopy(&(par_block.pars[1].canonical_numerator), &r1_h);
   siCopy(&(par_block.pars[2].canonical_numerator), &r2_h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &r1_k);
   else
      siSetToLong(&r1_k, 1);
   if (par_block.pars[2].canonical_denominator)
      siCopy(&(par_block.pars[2].canonical_denominator), &r2_k);
   else
      siSetToLong(&r2_k, 1);

   /* Echo back the parameters for the caller.
   */
   siDump(&r1_h, "l_h");
   gfHline();
   siDump(&r1_k, "l_k");
   gfHline();
   siDump(&r2_h, "r_h");
   gfHline();
   siDump(&r2_k, "r_k");
   gfHline();
   siDump(&kmax, "k_max");
   gfHline();
   siDump(&D,    "dap_D");
   gfHline();

   /* If the parameters for the interval are out of order,
   ** declare an error.  This probably means that the
   ** user of the command is doing something unintended.
   */
   if (rnCompare(&r1_h, &r1_k, &r2_h, &r2_k) >= 0)
      {
      asFatal("interval endpoints equal or out of order");
      }

   /* Be sure that both endpoints are in the Farey series
   ** of interest.
   */
   if ((siCompare(&r1_k, &kmax) > 0) || (siCompare(&r2_k, &kmax) > 0))
      {
      asFatal("interval endpoints must be in Farey series of interest");
      }

   /* Do the calculation proper.
   */
   naMind(&r1_h,
          &r1_k,
          &r2_h,
          &r2_k,
          &result_h,
          &result_k,
          TRUE,
          TRUE,
          FALSE
          );

   /* If both endpoints are in the interval, the fraction with
   ** the smallest denominator must be in the interval.  However,
   ** let's just be sure ...
   */
   asAssert(siCompare(&result_k, &kmax) <= 0, __LINE__);

   /* Emit the results from determining the rational number with
   ** the smallest denominator.
   */
   gfBannerHeading("A Rational Number With Smallest Denominator In Interval", 0);
   gfHline();
   siDump(&result_h, "result_h");
   gfHline();
   siDump(&result_k, "result_k");
   gfHline();

   /* Apply the formula in the paper to get the error result
   ** as a rational number.
   */
   siUnrestrictedSubtraction(&kmax, &result_k, &kmax_minus_qmin);

   siSetToLong(&error_h, 1);

   if (siCompare(&result_k, &kmax_minus_qmin) > 0)
      {
      SYNTHETIC_INTEGER *temp;

      siCreate(&temp);

      siCopy(&result_k, &temp);
      siUnrestrictedMultiplication(&result_k, &temp, &error_k);

      siDestroy(&temp);
      }
   else
      {
      siUnrestrictedMultiplication(&result_k, &kmax_minus_qmin, &error_k);
      }

   /* Print out these results. */
   gfBannerHeading("Upper Bound On Distance Between Farey Terms As Rational Number", 0);
   gfHline();
   siDump(&error_h, "error_ub_h");
   gfHline();
   siDump(&error_k, "error_up_k");
   gfHline();

   /* Calculate and display DAP results. */
   rnDap(&error_h, &error_k, &dap_N, &D);
   gfBannerHeading("Upper Bound On Distance Between Farey Terms As Decimal Approximation", 0);
   gfHline();
   siDump(&dap_N, "dap_h");
   gfHline();
   siDump(&D, "dap_k");
   gfHline();

   /* Destroy the locals.
   */
   siDestroy(&r1_h);
   siDestroy(&r1_k);
   siDestroy(&r2_h);
   siDestroy(&r2_k);
   siDestroy(&result_h);
   siDestroy(&result_k);
   siDestroy(&D);
   siDestroy(&kmax);
   siDestroy(&kmax_minus_qmin);
   siDestroy(&error_h);
   siDestroy(&error_k);
   siDestroy(&dap_N);
   }


/****************************************************************************/
/* cfFabdmax():                                                             */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Calculates an upper bound between the terms in the "rectangular" Farey */
/*   series of a certain order (2 constrints) in an interval.               */
/****************************************************************************/
void cfFabdmax(void)        
   {
   int case_1_applies = FALSE,
       case_2_applies = FALSE,
       case_3_applies = FALSE,
       /* Boolean variables to record which cases apply.
       */
       highest = 0;
       /* Integer representing the case with the largest error.
       ** This should always be the highest-numbered case
       ** evaluated. 1=Case I, 2=Case II, 3=Case III.
       */
       
   SYNTHETIC_INTEGER 
      *r1_h, *r1_k, 
         /* Left interval endpoint.
         */
      *r2_h, *r2_k,
         /* Right interval endpoint.
         */
      *min_k_h, *min_k_k, 
         /* The fraction in the interval with the
         ** smallest denominator.
         */
      *D, 
         /* The DAP denominator to be used.
         */
      *constant_1h,
         /* The constant 1, useful for comparisons.
         */
      *constant_1k,
         /* Second copy of the constant 1, useful for comparisons.
         ** The reason for requiring a second copy is that some of the 
         ** internal functions won't accept two operands which are physically
         ** the same.
         */
      *hmax,
         /* The maximum numerator for the "rectangular"
         ** Farey series.
         */
      *kmax,
         /* The maximum denominator (i.e. the order of the
         ** Farey series of interest).
         */
      *kmax_minus_qmin,
         /* The order of the Farey series minus the minimum
         ** denominator.
         */
      *case_1_error_h, 
      *case_1_error_k,
         /* The error bound from the Case I calculation, 
         ** expressed as a rational number.
         */
      *dap_N,
         /* The DAP numerator.
         */
      *case_1_right_h,
      *case_1_right_k,
         /* The right interval endpoint for application of Case I.  Case I
         ** does not apply any further than hmax/kmax, so this may be
         ** different than the right point of the interval.
         */
      *case_2_right_limit_h,
      *case_2_right_limit_k,
         /* The right limit for application of Case II.  This is 
         ** the lesser of 1 and the interval right endpoint.
         */
      *case_2_error_h,
      *case_2_error_k,
         /* The error bound from the Case II calculation
         ** expressed as a rational number.
         */
      *case_3_error_h,
      *case_3_error_k,
         /* The error bound from the Case III calculation
         ** expressed as a rational number.
         */
      *t0, *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9;
         /* Temporary integers.
         */

   /* Allocate all of our local variables.
   */
   siCreate(&r1_h);
   siCreate(&r1_k);
   siCreate(&r2_h);
   siCreate(&r2_k);
   siCreate(&min_k_h);
   siCreate(&min_k_k);
   siCreate(&D);
   siCreate(&constant_1h);
   siSetToLong(&constant_1h, 1);
   siCreate(&constant_1k);
   siSetToLong(&constant_1k, 1);
   siCreate(&hmax);
   siCreate(&kmax);
   siCreate(&kmax_minus_qmin);
   siCreate(&case_1_error_h);
   siCreate(&case_1_error_k);
   siCreate(&dap_N);
   siCreate(&case_1_right_h);
   siCreate(&case_1_right_k);
   siCreate(&case_2_right_limit_h);
   siCreate(&case_2_right_limit_k);
   siCreate(&case_2_error_h);
   siCreate(&case_2_error_k);
   siCreate(&case_3_error_h);
   siCreate(&case_3_error_k);
   siCreate(&t0);
   siCreate(&t1);
   siCreate(&t2);
   siCreate(&t3);
   siCreate(&t4);
   siCreate(&t5);
   siCreate(&t6);
   siCreate(&t7);
   siCreate(&t8);
   siCreate(&t9);

   /****************************************************************************/
   /***************** PROCESS INPUTS *******************************************/
   /****************************************************************************/
   /* Record the numerator order of the series in which we are 
   ** operating.
   */
   asAssert(par_block.pars[3].canonical_numerator != NULL, __LINE__);
   siCopy(&(par_block.pars[3].canonical_numerator), &hmax);

   /* Record the denominator order of the series in which we are 
   ** operating.
   */
   asAssert(par_block.pars[4].canonical_numerator != NULL, __LINE__);
   siCopy(&(par_block.pars[4].canonical_numerator), &kmax);

   /* If a different DAP denominator is specified, record that.
   */
   if (par_block.pars[5].canonical_numerator)
      {
      siCopy(&(par_block.pars[5].canonical_numerator), &D);
      }
   else
      {
      siSetToPowerOfTen(&D, DIGITS_PER_LINE * 4);
      }

   /* State the two interval endpoints as rational numbers, in case
   ** one or both are integers.
   */
   asAssert(par_block.pars[1].canonical_numerator != NULL, __LINE__);
   asAssert(par_block.pars[2].canonical_numerator != NULL, __LINE__);
   siCopy(&(par_block.pars[1].canonical_numerator), &r1_h);
   siCopy(&(par_block.pars[2].canonical_numerator), &r2_h);
   if (par_block.pars[1].canonical_denominator)
      siCopy(&(par_block.pars[1].canonical_denominator), &r1_k);
   else
      siSetToLong(&r1_k, 1);
   if (par_block.pars[2].canonical_denominator)
      siCopy(&(par_block.pars[2].canonical_denominator), &r2_k);
   else
      siSetToLong(&r2_k, 1);

   /* Echo back the parameters for the caller.
   */
   gfBannerHeading("Input Parameters", 2);
   gfHline();
   siDump(&r1_h, "l_h");
   gfHline();
   siDump(&r1_k, "l_k");
   gfHline();
   siDump(&r2_h, "r_h");
   gfHline();
   siDump(&r2_k, "r_k");
   gfHline();
   siDump(&hmax, "h_max");
   gfHline();
   siDump(&kmax, "k_max");
   gfHline();
   siDump(&D,    "dap_D");
   gfHline();

   /* If the parameters for the interval are out of order,
   ** declare an error.  This probably means that the
   ** user of the command is doing something unintended.
   */
   if (rnCompare(&r1_h, &r1_k, &r2_h, &r2_k) >= 0)
      {
      asFatal("interval endpoints equal or out of order");
      }

   /* Be sure that both endpoints are in the Farey series
   ** of interest.
   */
   if ((siCompare(&r1_k, &kmax) > 0) || (siCompare(&r2_k, &kmax) > 0)
      ||
      (siCompare(&r1_h, &hmax) > 0) || (siCompare(&r2_h, &hmax) > 0))
      {
      asFatal("interval endpoints must be in Farey series of interest");
      }

   /****************************************************************************/
   /***************** DECIDE WHICH CASES APPLY *********************************/
   /****************************************************************************/
   /* For Case I to apply, the interval must protrude below HMAX/KMAX.
   */
   if (rnCompare(&r1_h, &r1_k, &hmax, &kmax) < 0)
      case_1_applies = TRUE;
   else
      case_1_applies = FALSE;

   /* For Case II to apply, the HMAX/KMAX must be less than 1, and the
   ** interval must protrude into [HMAX/KMAX, 1].
   */
   if ((rnCompare(&hmax, &kmax, &constant_1h, &constant_1k) < 0) && 
       (rnCompare(&r2_h, &r2_k, &hmax, &kmax) > 0) && 
       (rnCompare(&r1_h, &r1_k, &constant_1h, &constant_1k) < 0))
      case_2_applies = TRUE;
   else
      case_2_applies = FALSE;

   /* For Case III to apply, the interval must protrude above 1 and
   ** above hmax/kmax.
   */
   if ((rnCompare(&r2_h, &r2_k, &constant_1h, &constant_1k) > 0)
      && (rnCompare(&r2_h, &r2_k, &hmax, &kmax) > 0))
      case_3_applies = TRUE;
   else
      case_3_applies = FALSE;

   /* Announce what applies.
   */
   gfBannerHeading("Case Selection Results", 2);
   gfHline();
   if (case_1_applies)
      printf("Case I applies and will be evaluated.\n");
   else
      printf("Case I does not apply and will not be evaluated.\n");

   if (case_2_applies)
      printf("Case II applies and will be evaluated.\n");
   else
      printf("Case II does not apply and will not be evaluated.\n");

   if (case_3_applies)
      printf("Case III applies and will be evaluated.\n");
   else
      printf("Case III does not apply and will not be evaluated.\n");

   gfHline();

   /* At this point I'm too lazy to go through the Boolean algebra to make
   ** sure that for any interval at least one case applies.  I *believe* I got
   ** it right, but just in case, let's assert that at least one case applies.
   */
   asAssert(case_1_applies || case_2_applies || case_3_applies, __LINE__);

   /****************************************************************************/
   /***************** CASE I ***************************************************/
   /****************************************************************************/
   if (case_1_applies)
      {
      gfBannerHeading("Start Of Case I Results", 2);
      gfHline();

      /* Must select an interval over which to operate for Case I.  If the
      ** right endpoint of the interval is > hmax/kmax, must knock it back
      ** to hmax/kmax for evaluation of Case I.  For Case I, can only evaluate
      ** to the left of hmax/kmax.
      */
      if (rnCompare(&r2_h, &r2_k, &hmax, &kmax) > 0)
         {
         siCopy(&hmax, &case_1_right_h);
         siCopy(&kmax, &case_1_right_k);
         }
      else
         {
         siCopy(&r2_h, &case_1_right_h);
         siCopy(&r2_k, &case_1_right_k);
         }

      gfBannerHeading("Possibly Truncated Interval For Case I", 0);
      gfHline();
      siDump(&r1_h, "l_h");
      gfHline();
      siDump(&r1_k, "l_k");
      gfHline();
      siDump(&case_1_right_h, "r_h");
      gfHline();
      siDump(&case_1_right_k, "r_k");
      gfHline();

      /* Do the calculation proper.
      */
      naMind(&r1_h,
             &r1_k,
             &case_1_right_h,
             &case_1_right_k,
             &min_k_h,
             &min_k_k,
             TRUE,
             TRUE,
             FALSE
             );

      /* If both endpoints are in the Farey series, the fraction with
      ** the smallest denominator must be in the Farey series.  However,
      ** let's just be sure ...
      */
      asAssert(siCompare(&min_k_k, &kmax) <= 0, __LINE__);

      /* Emit the results from determining the rational number with
      ** the smallest denominator.
      */
      gfBannerHeading("A Rational Number With Smallest Denominator In Interval", 0);
      gfHline();
      siDump(&min_k_h, "result_h");
      gfHline();
      siDump(&min_k_k, "result_k");
      gfHline();

      /* Apply the formula in the paper to get the error result
      ** as a rational number.
      */
      siUnrestrictedSubtraction(&kmax, &min_k_k, &kmax_minus_qmin);

      siSetToLong(&case_1_error_h, 1);

      if (siCompare(&min_k_k, &kmax_minus_qmin) > 0)
         {
         SYNTHETIC_INTEGER *temp;

         siCreate(&temp);
 
         siCopy(&min_k_k, &temp);
         siUnrestrictedMultiplication(&min_k_k, &temp, &case_1_error_k);

         siDestroy(&temp);
         }
      else
         {
         siUnrestrictedMultiplication(&min_k_k, &kmax_minus_qmin, &case_1_error_k);
         }

      /* Print out these results. */
      gfBannerHeading("Upper Bound On Distance Between Farey Terms As Rational Number", 0);
      gfHline();
      siDump(&case_1_error_h, "error_ub_h");
      gfHline();
      siDump(&case_1_error_k, "error_up_k");
      gfHline();

      /* Calculate and display DAP results. */
      rnDap(&case_1_error_h, &case_1_error_k, &dap_N, &D);
      gfBannerHeading("Upper Bound On Distance Between Farey Terms As Decimal Approximation", 0);
      gfHline();
      siDump(&dap_N, "dap_h");
      gfHline();
      siDump(&D, "dap_k");
      gfHline();
      }

   /****************************************************************************/
   /***************** CASE II **************************************************/
   /****************************************************************************/
   if (case_2_applies)
      {
      gfBannerHeading("Start Of Case II Results", 2);
      gfHline();

      /* If Case II applies, the maximum error will occur at the
      ** right limit of the interval or at 1, whichever is less.  Can
      ** just evaluate the error at this point.
      */
      if (rnCompare(&r2_h, &r2_k,
                    &constant_1h, &constant_1k) > 0)
         {
         siSetToLong(&case_2_right_limit_h, 1);
         siSetToLong(&case_2_right_limit_k, 1);
         }
      else
         {
         siCopy(&r2_h, &case_2_right_limit_h);
         siCopy(&r2_k, &case_2_right_limit_k);
         }

      /* We know the upper limit to apply.  Announce it.
      */
      gfBannerHeading("Case II Right Limit", 0);
      gfHline();
      siDump(&case_2_right_limit_h, "case_2_right_h");
      gfHline();
      siDump(&case_2_right_limit_k, "case_2_right_k");
      gfHline();

      /* Now evaluate the maximum error per the equations
      ** in the TOMS paper, and give that error
      ** and the DAP approximation as output.
      */
      /* Calculate the expression:
      **    floor(HMAX/RI)
      ** This will require a little fancy footwork.
      */
      siUnrestrictedMultiplication(&hmax, &case_2_right_limit_k, &t1);
      siUnrestrictedDivision(&t1, &case_2_right_limit_h, 
                             &t0, &t2);

      /* This quantity should now be in t0.  Now square it and add,
      ** leave in t1.  This is the denominator on the error expression.
      */
      siCopy(&t0, &t1);
      siUnrestrictedMultiplication(&t0, &t1, &t2);
      siUnrestrictedAddition(&t0, &t2, &t1);
      siCopy(&t1, &case_2_error_k);
      
      /* The numerator is HMAX. */
      siCopy(&hmax, &case_2_error_h);

      /* Put the rational number in lowest terms. 
      */
      rnCanonize(&case_2_error_h, &case_2_error_k);

      /* Print out these results. */
      gfBannerHeading("Upper Bound On Distance Between Farey Terms As Rational Number", 0);
      gfHline();
      siDump(&case_2_error_h, "error_ub_h");
      gfHline();
      siDump(&case_2_error_k, "error_up_k");
      gfHline();

      /* Calculate and display DAP results. */
      rnDap(&case_2_error_h, &case_2_error_k, &dap_N, &D);
      gfBannerHeading("Upper Bound On Distance Between Farey Terms As Decimal Approximation", 0);
      gfHline();
      siDump(&dap_N, "dap_h");
      gfHline();
      siDump(&D, "dap_k");
      gfHline();
      }

   /****************************************************************************/
   /***************** CASE III *************************************************/
   /****************************************************************************/
   if (case_3_applies)
      {
      gfBannerHeading("Start Of Case III Results", 2);
      gfHline();

      /* Case III is pretty simple.  Just 1/(simple_expression).
      ** For r_I we should use the upper limit on the interval, if
      ** Case III applies at all.
      */
      /* Calculate the expression:
      **    floor(HMAX/RI)
      ** This will require a little fancy footwork.
      */
      siUnrestrictedMultiplication(&hmax, &r2_k, &t1);
      siUnrestrictedDivision(&t1, &r2_h, 
                             &t0, &t2);

      /* t0 now contains the denominator, and the numerator is 1.
      */
      siSetToLong(&case_3_error_h, 1);
      siCopy(&t0, &case_3_error_k);

      /* Present that result and the DAP result.
      */
      gfBannerHeading("Upper Bound On Distance Between Farey Terms As Rational Number", 0);
      gfHline();
      siDump(&case_3_error_h, "error_ub_h");
      gfHline();
      siDump(&case_3_error_k, "error_up_k");
      gfHline();

      /* Calculate and display DAP results. */
      rnDap(&case_3_error_h, &case_3_error_k, &dap_N, &D);
      gfBannerHeading("Upper Bound On Distance Between Farey Terms As Decimal Approximation", 0);
      gfHline();
      siDump(&dap_N, "dap_h");
      gfHline();
      siDump(&D, "dap_k");
      gfHline();
      }

   /****************************************************************************/
   /***************** CUMULATIVE RESULTS ***************************************/
   /****************************************************************************/
   /* At this point, can compare the results to see which of the active
   ** cases generated the largest error.  It should always be the
   ** highest-numbered case, but can compare anyway.
   */
   gfBannerHeading("Start Of Cumulative Results", 2);
   gfHline();
   siSetToLong(&t0, 0);
   siSetToLong(&t1, 0);

   if (case_1_applies)
      {
      siCopy(&case_1_error_h, &t0);
      siCopy(&case_1_error_k, &t1);
      highest = 1;
      }
   else if (case_2_applies)
      {
      siCopy(&case_2_error_h, &t0);
      siCopy(&case_2_error_k, &t1);
      highest = 2;
      }
   else if (case_3_applies)
      {
      siCopy(&case_3_error_h, &t0);
      siCopy(&case_3_error_k, &t1);
      highest = 3;
      }
   else
      {
      asAssert(0, __LINE__);
      }

   /* OK, one case has been copied to t0/t1.  Compare
   ** to see if there is a larger one.
   */
   if (case_2_applies)
      {
      if (rnCompare(&case_2_error_h, &case_2_error_k,
                    &t0, &t1) > 0)
         {
         siCopy(&case_2_error_h, &t0);
         siCopy(&case_2_error_k, &t1);
         highest = 2;
         }
      }
   if (case_3_applies)
      {
      if (rnCompare(&case_3_error_h, &case_3_error_k,
                    &t0, &t1) > 0)
         {
         siCopy(&case_3_error_h, &t0);
         siCopy(&case_3_error_k, &t1);
         highest = 3;
         }
      }
   
   /* Announce the results.
   */
      {
      char buf1[100], buf2[100];

      switch (highest)
         {
         case 1 : strcpy(buf1, "I"); break;
         case 2 : strcpy(buf1, "II"); break;
         case 3 : strcpy(buf1, "III"); break;
         default: strcpy(buf1, "???"); break;
         }

      sprintf(buf2, "Largest Error (Case %s)", buf1);

      gfBannerHeading(buf2, 2);
      gfHline();
      }

   /* Present that result and the DAP result.
   */
   gfBannerHeading("Upper Bound On Distance Between Farey Terms As Rational Number", 0);
   gfHline();
   siDump(&t0, "error_ub_h");
   gfHline();
   siDump(&t1, "error_up_k");
   gfHline();

   /* Calculate and display DAP results. */
   rnDap(&t0, &t1, &dap_N, &D);
   gfBannerHeading("Upper Bound On Distance Between Farey Terms As Decimal Approximation", 0);
   gfHline();
   siDump(&dap_N, "dap_h");
   gfHline();
   siDump(&D, "dap_k");
   gfHline();
   
   /* Destroy the locals.
   */
   siDestroy(&r1_h);
   siDestroy(&r1_k);
   siDestroy(&r2_h);
   siDestroy(&r2_k);
   siDestroy(&min_k_h);
   siDestroy(&min_k_k);
   siDestroy(&D);
   siDestroy(&constant_1h);
   siDestroy(&constant_1k);
   siDestroy(&hmax);
   siDestroy(&kmax);
   siDestroy(&kmax_minus_qmin);
   siDestroy(&case_1_error_h);
   siDestroy(&case_1_error_k);
   siDestroy(&dap_N);
   siDestroy(&case_1_right_h);
   siDestroy(&case_1_right_k);
   siDestroy(&case_2_right_limit_h);
   siDestroy(&case_2_right_limit_k);
   siDestroy(&case_2_error_h);
   siDestroy(&case_2_error_k);
   siDestroy(&case_3_error_h);
   siDestroy(&case_3_error_k);
   siDestroy(&t0);
   siDestroy(&t1);
   siDestroy(&t2);
   siDestroy(&t3);
   siDestroy(&t4);
   siDestroy(&t5);
   siDestroy(&t6);
   siDestroy(&t7);
   siDestroy(&t8);
   siDestroy(&t9);
   }


/****************************************************************************/
/****************************************************************************/
/**********   I N P U T    P A R A M E T E R    F U N C T I O N S   *********/
/****************************************************************************/
/****************************************************************************/
/* This section is reserved for functions which process the input parameters
** and get them properly arranged in a data structure for the program
** internals to process.
*/


/* A simple structure to implement a linked list of strings.  This is used
** to hold the tokens of both the command-line or the processing from the
** standard input.
*/
struct ipSimpleStringLlNodeStruct
   {
   char *s;
      /* Dynamically allocated string.
      */
   struct ipSimpleStringLlNodeStruct *next;
      /* Link to next, or NULL if end of list.
      */
   };


/****************************************************************************/
/* ipBufferStandardInputStream():                                           */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Buffers the entire standard input stream into an array of characters,  */
/*   up to a maximum of STDIN_MAX_CHARS.                                    */
/*                                                                          */
/* OUTPUTS                                                                  */
/*   <--     :   Pointer to allocated array, terminated with '\0'.  Should  */
/*               be deallocated at some point.                              */
/****************************************************************************/
char *ipBufferStandardInputStream(void)
   {
   char *rv;
   char c;
   unsigned i;

   rv = maMalloc(((unsigned long)(sizeof(char))) * (STDIN_MAX_CHARS + 1));

   i = 0;
   rv[0] = '\0';

   while ((c = getchar()) != EOF)
      {
      if (i >= STDIN_MAX_CHARS)
         {
         asFatal("standard input exceeds 32000 characters");
         }

      rv[i] = c;
      rv[i+1] = '\0';
      i++;
      }

   return(rv);
   }


/****************************************************************************/
/* ipTranslateStdinToRawTokens():                                           */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Translates from the array of characters buffered from the standard     */
/*   input to a linked list of raw tokens.  By "raw" I mean that the        */
/*   possibility of concatenation has not been handled.                     */
/****************************************************************************/
void ipTranslateStdinToRawTokens(
                char *stdin_array, 
                struct ipSimpleStringLlNodeStruct **ptr_to_callers_ptr
                )
   {
    /* Make sure the caller isn't doing anything silly.
   */
   asAssert(stdin_array != NULL, __LINE__);
   asAssert(ptr_to_callers_ptr != NULL, __LINE__);

   /* Scan the buffer for unexpected characters that can't be handled.
   ** If one exists, generate a fatal error and message.
   */
      {
      char *p;
      unsigned i;
      char buf[100];

      i = 0;
      p = stdin_array;

      while (*p)
         {
         if (!ddIsInfoChar(*p) && !ddIsDiscardChar(*p) && !ddIsWhitespaceChar(*p))
            {
            sprintf( buf,
                     "illegal char in stdin at offset=%u, val=%u, char=%c",
                     i,
                     (int)(*p),
                     (unsigned)(*p));
            asFatal(buf);
            }
         i++;
         p++;
         }
      }


   /* Convert the entire buffer to lower case.
   */
      {
      unsigned len = strlen(stdin_array);
      unsigned i;

      for (i=0; i<len; i++)
         stdin_array[i] = ddCharToLower(stdin_array[i]);
      }

   /* Delete all the characters from the buffer that are the "ignore"
   ** characters.
   */
      {
      char *srcptr, *dstptr;

      srcptr = dstptr = stdin_array;

      while (*srcptr)
         {
         if (!ddIsDiscardChar(*srcptr))
            {
            *dstptr = *srcptr;
            dstptr++;
            }

         srcptr++;
         }

      *dstptr = '\0';
      }


   /* Break the stream into tokens, ignoring any concatenation.  What will be
   ** formed is a linked list.
   */
      {
      char *srcptr;
      struct ipSimpleStringLlNodeStruct **insert_point = NULL;
      struct ipSimpleStringLlNodeStruct *newnode;

      /* Set up to build a linked list. */
      *ptr_to_callers_ptr = NULL;

      srcptr = stdin_array;

      /* Advance pointer past any initial whitespace. */
      while ((*srcptr) && (ddIsWhitespaceChar(*srcptr)))
         srcptr++;

      /* While we're not at the end, get us a new token and put it
      ** into the linked list.
      */
      while (*srcptr)
         {
         unsigned memblocklen;
         char *snipleftptr;
         unsigned i;

         /* Snapshot the start of the token so we don't forget it. */
         snipleftptr = srcptr;

         /* Advance the source pointer so that it points one past the
         ** last character of the token.
         */
         while (ddIsInfoChar(*srcptr))
            srcptr++;

         /* Calculate the size of the memory block to hold the token's string
         ** representation.  We must add one to include the '\0' terminator.
         */
         memblocklen = srcptr - snipleftptr + 1;
      
         /* Allocate a new node to be put into the linked list. */
         newnode = maMalloc(sizeof(struct ipSimpleStringLlNodeStruct));

         /* For now, NEXT points nowhere. */
         newnode->next = NULL;

         /* Allocate the space to hold the string for the token. */
         newnode->s = maMalloc(memblocklen * sizeof(char));

         /* Copy the token, not including a terminator. */
         for (i=0; i<(memblocklen - 1); i++)
            newnode->s[i] = snipleftptr[i];

         /* Insert the string terminator. */
         newnode->s[memblocklen-1] = '\0';

         /* Insert the newly created node into the linked list.  There
         ** are two different ways to do it, depending on if this is our
         ** first element or not.
         */
         if (*ptr_to_callers_ptr)
            {
            /* Head of list is not NULL.  This is not our first element. */
            *insert_point = newnode;
            insert_point = &(newnode->next);
            }
         else
            {
            /* Head of list is NULL.  This is our first element. */
            *ptr_to_callers_ptr = newnode;
            insert_point = &(newnode->next);
            }

         /* Advance pointer past any whitespace until next token or end of string. */
         while ((*srcptr) && (ddIsWhitespaceChar(*srcptr)))
            srcptr++;
         }  /* End while() */
      } /* End block. */
   } /* End function. */


/****************************************************************************/
/* ipPackCmdLineArgsIntoLinkedList():                                       */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Translates the command-line arguments into a linked list of strings.   */
/*   The first argument (the program name) is omitted.                      */
/****************************************************************************/
void ipPackCmdLineArgsIntoLinkedList(
                      int argc, 
                      char * argv[], 
                      struct ipSimpleStringLlNodeStruct **ptr_to_callers_ptr)
   {
   int i;
   struct ipSimpleStringLlNodeStruct *newnode;
   unsigned len;
   struct ipSimpleStringLlNodeStruct **insert_point = NULL;

   /* Be sure that the caller isn't doing anything silly. */
   asAssert(argv != NULL, __LINE__);
   asAssert(ptr_to_callers_ptr != NULL, __LINE__);

   /* NULL out the caller's pointer, consistent with an empty linked list. */
   *ptr_to_callers_ptr = NULL;

   /* For each command-line argument, add it to the linked list.  Slightly
   ** different actions are necessary if the linked list is empty versus
   ** if it has at least one element.
   */

   for (i=1; i<argc; i++)
      {
      /* Figure out how long the string will be. */
      len = strlen(argv[i]);

      /* Allocate the memory for the new node. */
      newnode = maMalloc(sizeof(struct ipSimpleStringLlNodeStruct));

      /* For now, the node points nowhere. */
      newnode->next = NULL;

      /* Allocate space for the string. */
      newnode->s = maMalloc((len + 1) * sizeof(char));

      /* Copy from the argument list to the string. */
      strcpy(newnode->s, argv[i]);

      /* Insert the node into the list. */
      if (*ptr_to_callers_ptr)
         {
         /* Head of list is not NULL.  This is not our first element. */
         *insert_point = newnode;
         insert_point = &(newnode->next);
         }
      else
         {
         /* Head of list is NULL.  This is our first element. */
         *ptr_to_callers_ptr = newnode;
         insert_point = &(newnode->next);
         }
      }

   /* printf("Into check for illegals.\n"); */
   /* There are two tasks still to be performed to make the treatment
   ** of command-line args consistent with the treatment of the stdin
   ** stream.  First, check for illegal characters.  Second, remove the
   ** "ignore" characters.
   */
      {
      struct ipSimpleStringLlNodeStruct *p;
      unsigned i;

      p = *ptr_to_callers_ptr;
      i = 1;

      while(p)
         {
         char *cp;

         cp = p->s;

         while(*cp)
            {
            char buf[100];

            if (ddIsWhitespaceChar(*cp) || (!ddIsInfoChar(*cp) && !ddIsDiscardChar(*cp)))
               {
               sprintf( buf,
                     "illegal char in cmdline arg #%u, val=%u, char=%c",
                     i,
                     (unsigned)(*cp),
                     *cp);
               asFatal(buf);
               }

            cp++;
            }

         i++;
         p = p->next;
         }
      }

   /* printf("into discards\n"); */
   /* Now, remove any of the "discard" characters. */
      {
      struct ipSimpleStringLlNodeStruct *p;

      p = *ptr_to_callers_ptr;

      while(p)
         {
         char *srcptr, *dstptr;

         srcptr = dstptr = p->s;

         while (*srcptr)
            {
            *srcptr = ddCharToLower(*srcptr);

            if (!ddIsDiscardChar(*srcptr))
               {
               *dstptr = *srcptr;
               dstptr++;
               }

            srcptr++;
            }

         *dstptr = '\0';

         p = p->next;
         }
      }
   }


/****************************************************************************/
/* ipProcessLinkedListParameterContinuationCharacters():                    */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Processes the continuation characters.  If any token ends with a '\',  */
/*   combines it with next token.                                           */
/****************************************************************************/
void ipProcessLinkedListParameterContinuationCharacters
   (struct ipSimpleStringLlNodeStruct **ptr_to_callers_ptr)
   {
   struct ipSimpleStringLlNodeStruct **p, *removed_node;
   unsigned len_a, len_b;

   /* Be sure that the caller isn't doing anything silly. */
   asAssert(ptr_to_callers_ptr != NULL, __LINE__);

   p = ptr_to_callers_ptr;

   while (*p)
      {
      asAssert((*p)->s != NULL, __LINE__);

      len_a = strlen((*p)->s);
      if (len_a)
         {
         if ((*p)->s[len_a-1] == '\\')
            {
            /* Final character of this token is a backslash.  Must concatenate it with
            ** next token.
            */
            if (!((*p)->next))
               asFatal("final parameter ends in continuation character ('\\')");

            removed_node = (*p)->next;

            (*p)->next = removed_node->next;

            len_b = strlen(removed_node->s);

            (*p)->s = maRealloc((*p)->s, (len_a + len_b) * sizeof(char));

            (*p)->s[len_a-1] = '\0';
               /* Trash the terminating continuation character.  This also
               ** makes the Realloc() just above valid, don't need to add
               ** "+1", because have shorted string containing termination
               ** character by 1.
               */

            strcat((*p)->s, removed_node->s);

            maFree(removed_node->s);

            maFree(removed_node);
            }
         }

      len_a = strlen((*p)->s);
      if (len_a)
         {
         if ((*p)->s[len_a-1] != '\\')
            p = &((*p)->next);
         }
      }
   }


/****************************************************************************/
/* ipParseAsRationalNumber():                                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Attempts to parse a string (subscript in par_block passed) as a        */
/*   rational number.  Looks for errors, fills in the raw values, converts  */
/*   to canonical form, and fills in the ftype fields.                      */
/****************************************************************************/
void ipParseAsRationalNumber(int i)
   {
   SYNTHETIC_INTEGER *constant_1  = NULL,
                     *h_raw       = NULL,
                     *k_raw       = NULL,
                     *h_canonical = NULL,
                     *k_canonical = NULL,
                     *si_temp1    = NULL,
                     *si_temp2    = NULL,
                     *si_temp3    = NULL,
                     *si_temp4    = NULL;
   int is_neg = FALSE;
   char *s, *t;

   /* Make sure the caller isn't doing anything silly. */
   asAssert(i >= 0, __LINE__);
   asAssert(i < MAX_CMDLINE_PARS, __LINE__);

   /* Allocate all of the temporary synthetic integers that we'll
   ** use, and assign the constant 1.
   */
   siCreate(&constant_1);
   siSetToLong(&constant_1, 1);
   siCreate(&h_raw);
   siCreate(&k_raw);
   siCreate(&h_canonical);
   siCreate(&k_canonical);
   siCreate(&si_temp1);
   siCreate(&si_temp2);
   siCreate(&si_temp3);
   siCreate(&si_temp4);

   /* There are two parsing cases to cover.  Either the user is trying to
   ** specify a rational number as integer/integer, or as a floating point
   ** number.  The two cases can be differentiated by the presence of a
   ** forward slash in the input.
   */
   if (ddStringContains(par_block.pars[i].orig_string, "/"))
      {
      /* Integer/Integer Case */
      /* Parse off any leading minus sign. */

      /* Form a pointer to the start of the string. */
      s = par_block.pars[i].orig_string;

      /* Process any leading '-' sign. */
      if (*s == '-')
         {
         s++;
         is_neg = TRUE;
         }

      /* Parse off a group of digits, up to any non-digit character.
      ** We'll come to rest one past the last digit.
      */
      t = s;
      while (*t && ddIsDigit(*t))
         {
         t++;
         }

      /* Guard against the case where we could find no digits.
      */
      if (s == t)
         {
         asFatal("missing numerator in rational number");
         }

      /* Guard against the case where we have a leading zero on a string
      ** of digits that contains more than a zero.
      */
      if ((*s == '0') && ((t-s) > 1))
         {
         asFatal("leading zeros on non-zero integers not allowed");
         }

      /* If we've made it this far, we have a contiguous group of digits,
      ** with no leading zeroes.  Process it.
      */
      if (*s=='0')
         {
         /* Our digit was zero. */
         siSetToLong(&h_raw, 0);
         if (is_neg)
            asFatal("can't negate zero");
         }
      else if ((t-s) > INPUT_INTEGER_MAX_DIGITS)
         {
         asFatal("numerator too long");
         }
      else
         {
         char *u, *v;
         
         u = s;
         v = &(h_raw->digits[0]);
         while (u != t)
            {
            *v = *u;
            u++;
            v++;
            }
         *v = '\0';
         ddStringReverse(h_raw->digits);
         h_raw->len = strlen(h_raw->digits);
         h_raw->neg = is_neg;
         }

      /* OK, the first group of digits is done.  Now advance
      ** past the slash.
      */
      s = t;
      if (*s != '/')
         asFatal("missing '/' in rational number");
      s++;

      /* Guard against case of being at end of string. */
      if (!(*s))
         asFatal("missing denominator in rational number");

      /* Be sure nothing else left in the string except digits. 
      */
      if (!ddStringContainsOnly(s, "0123456789"))
         asFatal("unexpected non-digit character in rational number denominator");

      /* As before, parse past digits, copy, etc., except that no
      ** '-' sign is allowed.
      */
      /* Parse off a group of digits, up to any non-digit character.
      ** We'll come to rest one past the last digit.
      */
      t = s;
      while (*t && ddIsDigit(*t))
         {
         t++;
         }

      /* Guard against the case where we could find no digits.
      */
      if (s == t)
         {
         asFatal("missing denominator in rational number");
         }

      /* Guard against the case where we have a leading zero on a string
      ** of digits that contains more than a zero.
      */
      if ((*s == '0') && ((t-s) > 1))
         {
         asFatal("leading zeros on non-zero integers not allowed");
         }

      /* If we've made it this far, we have a contiguous group of digits,
      ** with no deading zeroes.  Process it.
      */
      if (*s=='0')
         {
         /* Our digit was zero. */
         asFatal("zero denominator in rational number");
         }
      else if ((t-s) > INPUT_INTEGER_MAX_DIGITS)
         {
         asFatal("denominator too long");
         }
      else
         {
         char *u, *v;
         
         u = s;
         v = &(k_raw->digits[0]);
         while (u != t)
            {
            *v = *u;
            u++;
            v++;
            }
         *v = '\0';
         ddStringReverse(k_raw->digits);
         k_raw->len = strlen(k_raw->digits);
         }
#if 0
      siDump(&h_raw, "h_raw");
      siDump(&k_raw, "k_raw");
#endif
      }
   else
      {
      char *before_decimal    = NULL;
      int  decimal_found      = FALSE;
      char *after_decimal     = NULL;
      int  e_found            = FALSE;
      char e_sign             = '+';
      char *exponent_mag      = NULL;
      char *concat_mantissa   = NULL;
      int  effective_exponent = 0;

      /* Floating-Point Constant Case */
      /* We've identified this number as a floating point constant of
      ** some kind.  Parse it out.  It will be re-expressed as a rational
      ** number.
      */
      s = par_block.pars[i].orig_string;

      /* Process any leading '-' sign. */
      if (*s == '-')
         {
         s++;
         is_neg = TRUE;
         }

      /* Parse off the first group of digits.  Keep parsing until hit a
      ** non-digit.  Form into a string.
      */
      /* Parse off a group of digits, up to any non-digit character.
      ** We'll come to rest one past the last digit.
      */
      t = s;
      while (*t && ddIsDigit(*t))
         {
         t++;
         }

      if (t != s)
         {
         int i;

         before_decimal = maMalloc((sizeof(char)) * (t-s+1));

         for (i=0; i<(t-s); i++)
            before_decimal[i] = s[i];

         before_decimal[i] = '\0';
         }
      else
         {
         before_decimal = maMalloc((sizeof(char)) * (1));
         strcpy(before_decimal, "");
         }

      s = t;

      /* Now, rip off any decimal point that exists. */
      if (*s == '.')
         {
         decimal_found = TRUE;
         s++;
         t++;
         }

      /* Rip off any remaining group of digits before 
      ** the 'e' character.
      */
      while (*t && ddIsDigit(*t))
         {
         t++;
         }

      if (t != s)
         {
         int i;

         after_decimal = maMalloc((sizeof(char)) * (t-s+1));

         for (i=0; i<(t-s); i++)
            after_decimal[i] = s[i];

         after_decimal[i] = '\0';
         }
      else
         {
         after_decimal = maMalloc((sizeof(char)) * (1));
         strcpy(after_decimal, "");
         }

      s = t;

      /* Rip off any e-character, should it exist. */
      if (*s == 'e')
         {
         e_found = TRUE;
         s++;
         t++;
         }

      /* Rip any sign off the e, should it exist. */
      if ((*s == '+') || (*s == '-'))
         {
         e_sign = *s;
         s++;
         t++;
         }

      /* Finally, rip off any final digits, which are
      ** the exponent.
      */
      while (*t && ddIsDigit(*t))
         {
         t++;
         }

      if (t != s)
         {
         int i;

         exponent_mag = maMalloc((sizeof(char)) * (t-s+1));

         for (i=0; i<(t-s); i++)
            exponent_mag[i] = s[i];

         exponent_mag[i] = '\0';
         }
      else
         {
         exponent_mag = maMalloc((sizeof(char)) * (1));
         strcpy(exponent_mag, "");
         }

      s = t;

      /* If we're not at the end of the string, something
      ** is wrong.
      */
      if (*s)
         asFatal("unable to parse floating-point number");

      /* If "e" was specified but no exponent was captured, this is an error.
      */
      if (!strlen(exponent_mag) && e_found)
         asFatal("missing floating-point exponent digits");

      /* Parse the exponent into a number.  The exponent is about the
      ** only place where leading zeros are allowed.  Start off believing 
      ** the exponent is zero.
      */
      effective_exponent = 0;
      while (exponent_mag[0] == '0')
         ddStringDeleteLeadingChar(exponent_mag);

      if (strlen(exponent_mag) > 3)
         asFatal("floating-point exponent magnitude too large");

      if (strlen(exponent_mag))
         sscanf(exponent_mag, "%d", &effective_exponent);

      if (e_sign == '-')
         effective_exponent = -effective_exponent;

      /* If there was a decimal point but no digits before or no digits
      ** after, this is an error.
      */
      if (decimal_found && (!strlen(before_decimal) || !strlen(after_decimal)))
         asFatal("improper floating-point mantissa");

      /* If there were no digits at all, this is an error */
      if (!strlen(before_decimal) && !strlen(after_decimal))
         asFatal("missing floating-point mantissa");

      /* Concatenate the before decimal and after decimal
      ** parts.
      */
      concat_mantissa = maMalloc((sizeof(char)) * (strlen(before_decimal) + strlen(after_decimal) + 1));
      strcpy(concat_mantissa, before_decimal);
      strcat(concat_mantissa, after_decimal);

      /* Delete all leading zeroes. */
      while (concat_mantissa[0] == '0')
         ddStringDeleteLeadingChar(concat_mantissa);

      /* If we've depleted the concatenated string, then
      ** there are two possibilities.  Either the number is zero,
      ** or there is an error of a '-' sign was specified.
      */
      if (!strlen(concat_mantissa))
         {
         if (is_neg)
            {
            asFatal("zero cannot be negated");
            }
         else
            {
            siSetToLong(&h_raw, 0);
            siSetToLong(&k_raw, 1);
            goto float_parsing_end;
            }
         }

      /* We start off believing that the exponent is the one given in the
      ** exponent field.  But we also need to adjust downward for the
      ** number of digits after the decimal point.
      */
      effective_exponent -= strlen(after_decimal);

      /* We are now poised to resolve what we have into a
      ** rational number.  Assign the concatenated string
      ** to h_raw, and 1 to k_raw.  For each negative
      ** count in the exponent, we multiply the denominator
      ** by 10.  For each postive count in the exponent,
      ** we multiply the numerator by 10.
      */
      if (strlen(concat_mantissa) > INPUT_INTEGER_MAX_DIGITS)
         {
         asFatal("floating-point mantissa too long");
         }

      ddStringReverse(concat_mantissa);
      strcpy(h_raw->digits, concat_mantissa);
      h_raw->len = strlen(h_raw->digits);
      h_raw->neg = is_neg;

      siSetToLong(&k_raw, 1);
      siSetToLong(&si_temp1, 10);

      while (effective_exponent)
         {
         if (effective_exponent < 0)
            {
            siUnrestrictedMultiplication(&k_raw, &si_temp1, &si_temp2);
            if (si_temp2->nan || (si_temp2->len > INPUT_INTEGER_MAX_DIGITS))
               asFatal("floating-point number magnitude too small");
            siCopy(&si_temp2, &k_raw);
            effective_exponent++;
            }
         else
            {
            siUnrestrictedMultiplication(&h_raw, &si_temp1, &si_temp2);
            if (si_temp2->nan || (si_temp2->len > INPUT_INTEGER_MAX_DIGITS))
               asFatal("floating-point number magnitude too large");
            siCopy(&si_temp2, &h_raw);
            effective_exponent--;
            }
         }

      float_parsing_end: ;
      /* Print out information for debugging. */
#if 0
      if (before_decimal)
         printf("before_decimal: %s\n", before_decimal);
      else
         printf("before_decimal: NULL\n");

      printf("decimal_found: %d\n", decimal_found);

      if (after_decimal)
         printf("after_decimal: %s\n", after_decimal);
      else
         printf("after_decimal: NULL\n");

      printf("e_found: %d\n", e_found);

      printf("e_sign: %c\n", e_sign);

      if (exponent_mag)
         printf("exponent_mag: %s\n", exponent_mag);
      else
         printf("exponent_mag: NULL\n");

      if (concat_mantissa)
         printf("concat_mantissa: %s\n", concat_mantissa);
      else
         printf("concat_mantissa: NULL\n");
#endif

      /* Free all of the memory that was potentially allocated. 
      */
      if (before_decimal)
         maFree(before_decimal);
      if (after_decimal)
         maFree(after_decimal);
      if (exponent_mag)
         maFree(exponent_mag);
      if (concat_mantissa)
         maFree(concat_mantissa);
      }

   /* At this point h_raw and k_raw contain a viable rational number.  Now
   ** we need to bring it into a normalized form.  This involves these steps.
   **
   **   a)If the number specified was negative, the rational number must
   **     have a neg numerator and pos denominator (this is done for us earlier).
   **
   **   b)If the number is zero, the canonical form of 0 must be used.
   **
   **   c)If the number is actually an integer, it must be stored in that
   **     form (NULL denominator SI).
   **
   **   d)Any gcd() must be factored out.
   */
   /* The zero test first. */
   if (!(h_raw->len))
      {
      siSetToLong(&h_canonical, 0);
      siDestroy(&k_canonical);
      }
   else
      {
      /* The number is not zero.  Remove any gcd().  This will have the added
      ** benefit of identifying any integers easily.
      */
      siCopy(&h_raw, &si_temp1);
      siCopy(&k_raw, &si_temp2);
      si_temp1->neg = FALSE;
      siGcd(&si_temp1, &si_temp2, &si_temp3);

#if 0
      siDump(&si_temp3, "gcd");
#endif

      siUnrestrictedDivision(&h_raw, &si_temp3, &h_canonical, &si_temp4);
      siUnrestrictedDivision(&k_raw, &si_temp3, &k_canonical, &si_temp4);

      /* The gcd is removed.  If the denominator is "1", trash the denominator.
      */
      if (!siCompare(&constant_1, &k_canonical))
         {
         siDestroy(&k_canonical);
         }
      }

   /* Assign the raw values and canonical values to the four variables involved.
   ** Must NULL any moved pointers to prevent a subsequent FREE of something that
   ** now does not belong to us.
   */
   par_block.pars[i].raw_numerator         = h_raw;
   h_raw = NULL;
   par_block.pars[i].raw_denominator       = k_raw;
   k_raw = NULL;
   par_block.pars[i].canonical_numerator   = h_canonical;
   h_canonical = NULL;
   par_block.pars[i].canonical_denominator = k_canonical;
   k_canonical = NULL;

   /* Now set the ftype.  This is easy to determine.  The sign comes from the
   ** canonical numerator, and the type comes from the NULLness of the
   ** canonical denominator.
   */
   if (par_block.pars[i].canonical_numerator->neg)
      {
      /* Neg */
      if (par_block.pars[i].canonical_denominator)
         {
         /* Rational number negative */
         par_block.pars[i].ftype = CMDLINE_PAR_TYPE_RATNEG;
         }
      else
         {
         /* Integral */
         if (par_block.pars[i].canonical_numerator->len)
            {
            /* Integer negative. */
            par_block.pars[i].ftype = CMDLINE_PAR_TYPE_INTNEG;
            }
         else
            {
            /* Invalid case. */
            asAssert(FALSE, __LINE__);
            }
         }
      }
   else
      {
      /* Pos */
      if (par_block.pars[i].canonical_denominator)
         {
         /* Rational number positive */
         par_block.pars[i].ftype = CMDLINE_PAR_TYPE_RATPOS;
         }
      else
         {
         /* Integral */
         if (par_block.pars[i].canonical_numerator->len)
            {
            /* Integer positive */
            par_block.pars[i].ftype = CMDLINE_PAR_TYPE_INTPOS;
            }
         else
            {
            /* Integer zero. */
            par_block.pars[i].ftype = CMDLINE_PAR_TYPE_INTZERO;
            }
         }
      }

   /* Destroy all of the temporary synthetic integers that were not
   ** otherwise destroyed or reassigned.
   */
   if (constant_1)
      siDestroy(&constant_1);
   if (h_raw)
      siDestroy(&h_raw);
   if (k_raw)
      siDestroy(&k_raw);
   if (h_canonical)
      siDestroy(&h_canonical);
   if (k_canonical)
      siDestroy(&k_canonical);
   if (si_temp1)
      siDestroy(&si_temp1);
   if (si_temp2)
      siDestroy(&si_temp2);
   if (si_temp3)
      siDestroy(&si_temp3);
   if (si_temp4)
      siDestroy(&si_temp4);

   /* Print out diagnostic information */
#if 0
   if(par_block.pars[i].raw_numerator)
      siDump(&(par_block.pars[i].raw_numerator), "raw_num");
   else
      printf("raw_num is NULL\n");

   if(par_block.pars[i].raw_denominator)
      siDump(&(par_block.pars[i].raw_denominator), "raw_den");
   else
      printf("raw_den is NULL\n");

   if(par_block.pars[i].canonical_numerator)
      siDump(&(par_block.pars[i].canonical_numerator), "can_num");
   else
      printf("can_num is NULL\n");

   if(par_block.pars[i].canonical_denominator)
      siDump(&(par_block.pars[i].canonical_denominator), "can_den");
   else
      printf("can_den is NULL\n");

   printf("ftype is : %d\n", par_block.pars[i].ftype);
#endif
   }

            
/****************************************************************************/
/* ipParseAsSimpleInteger():                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Attempts to parse a string (subscript in par_block passed) as a        */
/*   simple integer.  Looks for errors and fills in the raw integer.  There */
/*   isn't much to think about with a raw integer, so fills in ftype.       */
/****************************************************************************/
void ipParseAsSimpleInteger(int i)
   {
   int int_is_neg = FALSE;
   char *s;

   /* Make sure the caller isn't doing anything silly. */
   asAssert(i >= 0, __LINE__);
   asAssert(i < MAX_CMDLINE_PARS, __LINE__);

   s = par_block.pars[i].orig_string;

   /* Process any leading '-' sign. */
   if (*s == '-')
      {
      s++;
      int_is_neg = TRUE;
      }

   /* The remainder of the string must a)exist, and b)contain only digits.
   */
   if (!(*s))
      asFatal("bad parameter while expecting simple integer");

   if (!ddStringContainsOnly(s, "0123456789"))
      asFatal("unexpected non-digit character while expecting simple integer");

   /* If there is a leading zero, that must be the only character, and then
   ** we can know we have zero.
   */
   if (*s == '0')
      {
      if (s[1])
         asFatal("leading zeroes not allowed on integers");

      if (int_is_neg)
         asFatal("can't negate zero");

      /* Beavis, we have a zero.  Form it.
      */
      siCreate(&(par_block.pars[i].raw_numerator));
         /* Zero is created by default, so no need to go further.
         */
      }
   else
      {
      /* String contains a non-zero integer, which may or may not be 
      ** negated.  We know it contains only digits and no leading
      ** 0.
      */
      if (strlen(s) > INPUT_INTEGER_MAX_DIGITS)
         asFatal("input integer too long");

      /* If we're here, we're clean.  The string is ready to go as is,
      ** except the order must be reversed.
      */
      siCreate(&(par_block.pars[i].raw_numerator));
      par_block.pars[i].raw_numerator->neg = int_is_neg;
      strcpy(par_block.pars[i].raw_numerator->digits, s);
      par_block.pars[i].raw_numerator->len 
         = strlen(par_block.pars[i].raw_numerator->digits);

         {
         /* Reverse the digits. */
         int len, idx;
         char temp;

         len = par_block.pars[i].raw_numerator->len;

         for (idx=0; idx < (len/2); idx++)
            {
            temp = par_block.pars[i].raw_numerator->digits[idx];
            par_block.pars[i].raw_numerator->digits[idx]
               = par_block.pars[i].raw_numerator->digits[len - 1 - idx];
            par_block.pars[i].raw_numerator->digits[len - 1 - idx] = temp;
            }
         }
      }

   /* Can also fill in the ftype field.
   */
   if (!(par_block.pars[i].raw_numerator->len))
      par_block.pars[i].ftype = CMDLINE_PAR_TYPE_INTZERO;
   else if (par_block.pars[i].raw_numerator->neg)
      par_block.pars[i].ftype = CMDLINE_PAR_TYPE_INTNEG;
   else
      par_block.pars[i].ftype = CMDLINE_PAR_TYPE_INTPOS;

   /* In parsing a simple integer, there is no distinction between
   ** the raw and the canonical forms.  Still, should copy all over
   ** to the canonical area.
   */

   siCreate(&(par_block.pars[i].canonical_numerator));
   siCopy(&(par_block.pars[i].raw_numerator), &(par_block.pars[i].canonical_numerator));

   /* We know the denominator is NULL, because of the way the parameter block
   ** is initialized.
   */
   }


/****************************************************************************/
/* ipParseCommandLineParameters():                                          */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Parses the command line parameters, as passed in the linked list.      */
/*   This includes:                                                         */
/*     a)Checking for an excessive number of parameters.                    */
/*     b)Deciding on the type of the parameters, and converting them to     */
/*       integers, rational numbers, etc.                                   */
/*     c)Placing the quantities into canonical form.                        */
/****************************************************************************/
void ipParseCommandLineParameters 
   (
   struct ipSimpleStringLlNodeStruct **ptr_to_callers_ptr
   )
   {
   /* Make sure the caller isn't doing anything silly. */
   asAssert(ptr_to_callers_ptr != NULL, __LINE__);

   /* Completely initialize the array of command-line parameters.
   */
      {
      int i;

      par_block.n = 0;

      for(i=0; i<MAX_CMDLINE_PARS; i++)
         {
         par_block.pars[i].ftype = CMDLINE_PAR_TYPE_UNASSIGNED;
         par_block.pars[i].orig_string = NULL;
         par_block.pars[i].raw_numerator = NULL;
         par_block.pars[i].raw_denominator = NULL;
         par_block.pars[i].canonical_numerator = NULL;
         par_block.pars[i].canonical_denominator = NULL;
         }
      }

   /* Count up the total number of parameters.  Crap out of too
   ** many.
   */
      {
      unsigned i;
      struct ipSimpleStringLlNodeStruct *p;
      char buf[100];

      p = *ptr_to_callers_ptr;
      i = 0;

      while(p)
         {
         p = p->next;
         i++;
         }

      if (i > MAX_CMDLINE_PARS)
         {
         sprintf(buf, "too many cmd line pars, actual=%u, max=%u",
                 i,
                 MAX_CMDLINE_PARS);
         asFatal(buf);
         }
      }

   /* Loop through the linked list of parameters, assigning each
   ** string into the parameter block, and dismantle the linked list
   ** in the process.  The strings are kept.
   */
      {
      struct ipSimpleStringLlNodeStruct *node_to_destroy;

      par_block.n = 0;

      while(*ptr_to_callers_ptr)
         {
         par_block.pars[par_block.n].orig_string = (*ptr_to_callers_ptr)->s;
         node_to_destroy = *ptr_to_callers_ptr;
         *ptr_to_callers_ptr = node_to_destroy->next;
         maFree(node_to_destroy);
         (par_block.n)++;
         }
      }

   /* Parse the first parameter specially.  The first parameter must be one of
   ** the commands.  There must be at least a command.
   */
      {
      static struct 
         {
         char *s;
         unsigned v;
         } cmdtable[] = 
            {
               {"+",               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS       },
               {"-",               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS      },
               {"*",               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES      },
               {"/",               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT   },
               {"%",               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO     },
               {"**",              CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER      },
               {"gcd",             CMDLINE_PAR_TYPE_CMD_KEYTOKEN_GCD        },
               {"dap",             CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP        },
               {"mind",            CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND       },
               {"cf",              CMDLINE_PAR_TYPE_CMD_KEYTOKEN_CF         },
               {"fn",              CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN         },
               {"fndmax",          CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX     },
               {"fab",             CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB        },
               {"fabdmax",         CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX    }
           };
      unsigned i;
      char buf[100];

      if (par_block.n < 1)
         asFatal("too few parameters--at least a command required");

      /* Try to match the first parameter against the table above. */
      for (i=0; i<sizeof(cmdtable)/sizeof(cmdtable[0]); i++)
         {
         if (!strcmp(cmdtable[i].s, par_block.pars[0].orig_string))
            {
            break;
            }
         }

      if (i == sizeof(cmdtable)/sizeof(cmdtable[0]))
         {
         sprintf(buf, "unknown command \"%s\"", par_block.pars[0].orig_string);
         asFatal(buf);
         }
         
      par_block.pars[0].ftype = cmdtable[i].v;
      }

   /* For the remaining parameters, parse them as numbers.  The rules are
   ** easy.  If the number contains a '/', a '.', or an 'e', we must attempt
   ** to parse it as a rational number, otherwise we attempt as an
   ** integer.
   */
      {
      int i;

      for (i=1; i<par_block.n; i++)
         {
         if (ddStringContains(par_block.pars[i].orig_string, "e/."))
            {
            /* Attempt to parse as a rational number. */
            ipParseAsRationalNumber(i);
            }
         else
            {
            /* Attempt to parse as a simple integer. */
            ipParseAsSimpleInteger(i);
            }
         }
      }
   }


/****************************************************************************/
/* ipExecuteCommand():                                                      */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Matches a command against the built-in templates and executes a        */
/*   command iff the inputs match a template that a command will accept.    */
/****************************************************************************/
void ipExecuteCommand(void)
   {
   /* The structure below gives the "templates" for commands--what is allowed
   ** to be passed as parameters, and how it maps to commands.  In retrospect,
   ** the system for classification could be optimized (it is necessary to
   ** spell out too may cases), but the template-matching happens only
   ** once.
   */
   static struct
      {
      void (*fptr)(void);
         /* Function pointer to execute.
         */
      int template[MAX_CMDLINE_PARS];
         /* Template to match.
         */
      } cmd_templates[]
         =
         {
            /* Simple addition of two integers.  Multiple templates are
            ** required.
            */
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple addition of two rational numbers.
            ** Multiple templates are required.
            */
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalAddition,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_PLUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple subtraction of two integers.  Multiple templates are
            ** required.
            */
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple subtraction of two rational numbers.
            ** Multiple templates are required.
            */
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalSubtraction,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MINUS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple multiplication of two integers.  Multiple templates are
            ** required.
            */
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple multiplication of two rational numbers.
            ** Multiple templates are required.
            */
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalMultiplication,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_TIMES,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple exponentiation of two integers.  Multiple templates are
            ** required.
            */
            {
            cfSimple2ParIntegerExponentiation,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerExponentiation,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerExponentiation,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerExponentiation,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerExponentiation,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple exponentiation of rational number to an
            ** integer power.  Multiple templates are
            ** required.
            */
            {
            cfSimple2ParIntegerExponentiationOfRational,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerExponentiationOfRational,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerExponentiationOfRational,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_RATZERO, /* Can't happen because will
                                         ** be converted to integer
                                         ** zero, but no harm in 
                                         ** including in table.
                                         */
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerExponentiationOfRational,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerExponentiationOfRational,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_POWER,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple division of two integers.  Multiple templates are
            ** required.
            */
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple modulo of two integers.  Multiple templates are
            ** required.
            */
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParIntegerRemainder,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MODULO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Simple division of two rational numbers.
            ** Multiple templates are required.
            */
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfSimple2ParRationalRationalQuotient,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_QUOTIENT,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* GCD 
            */
            {
            cfSimple2ParIntegerGcd,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_GCD,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* DAP */
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_RATNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_INTNEG,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfDap,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_DAP,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* CF--forming the continued fraction partial quotients and
            ** convergents of a non-negative rational number.
            */
            {
            cfCf,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_CF,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfCf,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_CF,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfCf,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_CF,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfCf,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_CF,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Farey series neighbor functionality.  Multiple
            ** templates required.
            */
            {
            cfFn,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFn,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFn,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFn,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFn,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFn,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFn,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFn,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FN,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfMind,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_MIND,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Farey series double-constrained neighbor functionality.  
            ** Multiple templates required.
            */
            {
            cfFab,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFab,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFab,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFab,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFab,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFab,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFab,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFab,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FAB,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Maximum distance between terms of Farey series.
            ** Only two forms possible, one with DAP alternate
            ** denominator, one without.
            */
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFndmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FNDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            /* Maximum distance between terms of "rectangular" Farey
            ** series.  Only two forms possible, one with DAP alternate
            ** denominator, one without.
            */
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,    
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATZERO,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
            {
            cfFabdmax,
               {
               CMDLINE_PAR_TYPE_CMD_KEYTOKEN_FABDMAX,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_RATPOS,
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_INTPOS,     
               CMDLINE_PAR_TYPE_INTPOS,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED,
               CMDLINE_PAR_TYPE_UNASSIGNED
               }
            },
         };

   int i;
   int j;

   /* Try to match the par_block against the templates, and call the first
   ** function that gives a match.  If there isn't a match in the table,
   ** this is an error, as the user has specified something that the program
   ** isn't prepared to handle.
   */

   for (i=0; i<sizeof(cmd_templates)/sizeof(cmd_templates[0]); i++)
      /* For each template.
      */
      {
      /* printf("Processing table entry: %d\n", i); */

      for (j=0; j<MAX_CMDLINE_PARS; j++)
         {

         /* printf("   Processing template entry: %d, tbl: %d, pars: %d\n", j,
                    cmd_templates[i].template[j],
                    par_block.pars[j].ftype); */
         
         if ((cmd_templates[i].template[j]) != (par_block.pars[j].ftype))
            break;
         }

      if (j==MAX_CMDLINE_PARS)
         {
         (cmd_templates[i].fptr)();
         break;
         }
      }

   if (i==sizeof(cmd_templates)/sizeof(cmd_templates[0]))
      {
      asFatal("no match of command and pars to cmd template");
      }
   }


/****************************************************************************/
/****************************************************************************/
/****************   U N I T    T E S T    F U N C T I O N S   ***************/
/****************************************************************************/
/****************************************************************************/
/* These functions constitute a crude unit test.  This code will be
** preprocessed out before this is released to the ACM.
*/

#if 0
/****************************************************************************/
/* utFunc1():                                                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Double-checks the way that integers are presented (titles, commas,     */
/*   etc.).                                                                 */
/****************************************************************************/
void utFunc1(void)
   {
   long vectors[] = {-876437264, -10, -9, -2, -1, 0, 1, 2, 3, 10, 99, 29343432};
   unsigned i;
   SYNTHETIC_INTEGER *si1;
   char buf[100];

   /* Create a synthetic integer.
   */
   siCreate(&si1);

   /* Run through each of the test vectors.
   */
   for (i=0; i<sizeof(vectors)/sizeof(vectors[0]); i++)
      {
      /* Assign it to be the integer 0. */
      siSetToLong(&si1, vectors[i]);

      /* Print the value. */
      sprintf(buf, "Vector[%u]", i);
      siDump(&si1, buf);

      /* Add a horizontal line. */
      gfHline();
      }

   /* Destroy the synthetic integer. */
   siDestroy(&si1 );
   }


/****************************************************************************/
/* utFunc2():                                                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Double-checks the way that integers are added, and also the NAN which  */
/*   should occur on overflow.  Powers of two are generated by doubling.    */
/****************************************************************************/
void utFunc2(void)
   {
   SYNTHETIC_INTEGER *arg1, *arg2, *result;
   int i; 
   char buf[100];

   siCreate(&arg1);
   siCreate(&arg2);
   siCreate(&result);

   siSetToLong(&arg1, 0);
   siSetToLong(&arg2, 1);
     /* Ln(2)/Ln(10) is 0.30, so we should run out of space
     ** in around 4000/0.30 = 13,300 or so iterations.
     */

   for (i=0; i<13300; i++)
      {
      siAddTwoNonnegative(&arg1, &arg2, &result);
      siCopy(&result, &arg1);
      siCopy(&result, &arg2);
      sprintf(buf, "Iteration %d", i);
      siDump(&result, buf);
      gfHline();
      }

   siDestroy(&arg1);
   siDestroy(&arg2);
   siDestroy(&result);
   }


/****************************************************************************/
/* utFunc3():                                                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Double-checks the behavior of the non-negative result subtraction      */
/*   function.                                                              */
/****************************************************************************/
void utFunc3(void)
   {
   long vectors[] = {      0,          0,  /* zero minus zero should be zero */
                           1000,       0,
                           9,          0,
                           1000,       1,
                           99,         33,
                           99,         99,
                           99,         98,
                           99,         97,
                           99,         96,
                           99,         95,
                           99,         94,
                           99,         93,
                           99,         92,
                           99,         91,
                           99,         90,
                           99,         89,
                           99,         88,   
                           99,         97,
                           10101,      101,
                           10101,      102,
                           10101,      100,
                           };

   unsigned i;
   SYNTHETIC_INTEGER *si1, *si2, *result;
   char buf[100];

   /* Create the synthetic integers
   */
   siCreate(&si1);
   siCreate(&si2);
   siCreate(&result);

   /* Run through each of the test vectors.
   */
   for (i=0; i< sizeof(vectors)/sizeof(vectors[0]); i+=2)
      {
      /* Assign the value to be subtracted from. */
      siSetToLong(&si1, vectors[i]);

      /* Assign the value to be subtracted. */
      siSetToLong(&si2, vectors[i+1]);

      /* Make the subtraction. */
      siSubtractToProduceNonnegativeResult(&si1, &si2, &result);

      /* Print the values. */
      sprintf(buf, "Vector[%u] Arg 1", i/2);
      siDump(&si1, buf);
      gfHline();
      sprintf(buf, "Vector[%u] Arg 2", i/2);
      siDump(&si2, buf);
      gfHline();
      sprintf(buf, "Vector[%u] Result", i/2);
      siDump(&result, buf);
      gfHline();
      }

   /* Destroy the synthetic integers. */
   siDestroy(&si1 );
   siDestroy(&si2 );
   siDestroy(&result );
   }


/****************************************************************************/
/* utFunc4():                                                               */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Double-checks the behavior of the general addition function.           */
/****************************************************************************/
void utFunc4(void)
   {
   long vectors[] = {      /* This group is the vectors copied from the
                           ** table in the function above.  These are 
                           ** non-specific, but can do no harm to run them
                           ** through.
                           */
                           0,          0,  /* zero minus zero should be zero */
                           1000,       0,
                           9,          0,
                           1000,       1,
                           99,         33,
                           99,         99,
                           99,         98,
                           99,         97,
                           99,         96,
                           99,         95,
                           99,         94,
                           99,         93,
                           99,         92,
                           99,         91,
                           99,         90,
                           99,         89,
                           99,         88,   
                           99,         97,
                           10101,      101,
                           10101,      102,
                           10101,      100,
                           /* These are the specific vectors.  Want to run them
                           ** through each of the 12 cases in the function.
                           */
                           0,          0,
                           0,         -583,
                           -583,       0,
                           0,          583,
                           583,        0,
                           583,        -12,
                           -12,        583,
                           -609,       11,
                           11,         -609,
                           329,        329,
                           -329,       -329,
                           327,        252,
                           252,        329,
                           -21,        -591,
                           321,        -321,
                           -322,       322,
                           -42923,     -31998,
                           };

   unsigned i;
   SYNTHETIC_INTEGER *si1, *si2, *result;
   char buf[100];

   /* Create the synthetic integers
   */
   siCreate(&si1);
   siCreate(&si2);
   siCreate(&result);

   /* Run through each of the test vectors.
   */
   for (i=0; i< sizeof(vectors)/sizeof(vectors[0]); i+=2)
      {
      /* Assign the value to be subtracted from. */
      siSetToLong(&si1, vectors[i]);

      /* Assign the value to be subtracted. */
      siSetToLong(&si2, vectors[i+1]);

      /* Make the addition. */
      siUnrestrictedAddition(&si1, &si2, &result);

      /* Print the values. */
      sprintf(buf, "Vector[%u] Arg 1", i/2);
      siDump(&si1, buf);
      gfHline();
      sprintf(buf, "Vector[%u] Arg 2", i/2);
      siDump(&si2, buf);
      gfHline();
      sprintf(buf, "Vector[%u] Result", i/2);
      siDump(&result, buf);
      gfHline();
      }

   /* Destroy the synthetic integers. */
   siDestroy(&si1 );
   siDestroy(&si2 );
   siDestroy(&result );
   }


/****************************************************************************/
/* utUnittestAll():                                                         */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Sequentially runs all unit tests.                                      */
/****************************************************************************/
void utUnitTestAll(void)
   {
   /* utFunc1(); */
   /* utFunc2(); */
   /* utFunc3(); */
   /* utFunc4(); */
   }
#endif


/****************************************************************************/
/****************************************************************************/
/********************   M A I N    F U N C T I O N   ************************/
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/* main_c():                                                                */
/*--------------------------------------------------------------------------*/ 
/* DESCRIPTION                                                              */
/*   Main function of the program.  If this program is ported, main_c()     */
/*   must be renamed to main().  The name of main_c() [different than       */
/*   main()] was chosen because the main() function of Visual C++ is in     */
/*   another source file (it is a C++ wrapper), and two functions cannot    */
/*   both have the name main().                                             */
/*                                                                          */
/* INPUTS                                                                   */
/*   argc, argv :  The count of command-line parameters and the command-    */
/*                 line parameters.                                         */
/****************************************************************************/
int main_c(int argc, char* argv[])
   {
   /*************************************************************************/
   char *stdin_array = NULL;
      /* The characters read from the standard input, verbatim, before
      ** further parsing.  This pointer, if it is assigned, is a
      ** dynamically allocated block, terminated with '\0', and should
      ** be free'd at some point.
      */
   /*************************************************************************/
   struct ipSimpleStringLlNodeStruct *raw_tokens_list = NULL;
      /* Linked list of raw tokens from either the command-line or
      ** the standard input if running in batch mode.
      */

#if 0
      {
      int idx;

      SYNTHETIC_INTEGER *h1, *h2, *k1, *k2, *N;

      siCreate(&h1);
      siCreate(&h2);
      siCreate(&k1);
      siCreate(&k2);
      siCreate(&N);

      siSetToLong(&h1, 0);
      siSetToLong(&k1, 1);
      siSetToLong(&h2, 1);
      siSetToLong(&k2, 1000);
      siSetToLong(&N, 1000);

      for (idx=0; idx<10000; idx++)
         {
         rnFareyTraverse(&h1, &k1, &h2, &k2, &N, 1);

         printf("index: %d\n", idx);
         siDump(&h1, "h1");
         siDump(&k1, "k1");
         siDump(&h2, "h2");
         siDump(&k2, "k2");
         siDump(&N, "N");
         gfHline();
         }

      for (idx=9999; idx>=0; idx--)
         {
         rnFareyTraverse(&h1, &k1, &h2, &k2, &N, -1);

         printf("index: %d\n", idx);
         siDump(&h1, "h1");
         siDump(&k1, "k1");
         siDump(&h2, "h2");
         siDump(&k2, "k2");
         siDump(&N, "N");
         gfHline();
         }

      exit(0);
      }

#endif
#if 0
      {
      int i;

      for (i=-10; i <= 10; i++)
         {
         printf("i: %d, i mod 3: %d\n", i, i%3);
         }

      for (i=-10; i <= 10; i++)
         {
         printf("i: %d, i mod -3: %d\n", i, i%(-3));
         }

      exit(0);
      }
#endif

   /*************************************************************************/
   /* Write introductory message, including version control information.    */
   gfHline();printf("RAP (");{unsigned i = 0;while (vcGetVcData(i)){printf(
   "%s",vcGetVcData(i));i++;}}printf(") execution begins.\n");gfHline();
   /*************************************************************************/
   /* Run all built-in unit tests (used only for development).              */
   /* utUnitTestAll(); */
   /*************************************************************************/
   /* Split into two cases.  Either the command-line pars are on the
   ** command-line, or they are coming from stdin.  In this section get to
   ** the point of having an array of tokens, before concatenation is
   ** performed.
   */

#if 0   
      {
      SYNTHETIC_INTEGER *i, *j, *k;

      siCreate(&i);

      siSetToLong(&i, 788);

      siDump(&i, "788");

      siMulByDigit(&i, '3');

      siDump(&i, "3*788");

      }
#endif

   
   if (argc==0)
      {
      asFatal("argc can't be zero--runtime environment anomaly");
      }
   if (argc==1)
      {
      /* "rap" used alone on command line.  Probably this is a user trying
      ** to figure out what this executable on his hard drive is.  Print out
      ** an informational message and exit.
      */
      asInfo();
      }
   else if (argc==2)
      {
      /* If there are two arguments, the second one must be "batch" or the
      ** program can't process the input.
      */
      if (_stricmp("batch", argv[1]))
         {
         asFatal("if only one command-line parameter specified, must be \"batch\"");
         }
      else
         {
         /* We're running batch mode.  Must take our parameters from a file as if they
         ** came from the command line.
         */
         /* First, buffer the entire standard input stream to a character buffer.
         */
         stdin_array = ipBufferStandardInputStream();
         /* printf("%d\n", strlen(stdin_array)); */
         /* printf("%s\n", stdin_array); */

         /* Make the transformation from the buffered standard input array to 
         ** a linked list of tokens.
         */
         ipTranslateStdinToRawTokens(stdin_array, &raw_tokens_list);

         /* At this point, the array of characters taken from the standard
         ** input is disposable.  Free it up.
         */
         maFree(stdin_array);
         stdin_array = NULL;
         }
      }
   else
      {
      /* argc > 2.  In this case, can take the command-line arguments and
      ** pack them into a linked list, same as would do with stdin input.
      */
      ipPackCmdLineArgsIntoLinkedList(argc, argv, &raw_tokens_list);
      }

   /* In either case (whether we obtained the linked list from the command-line
   ** or from stdin), we must process continuation characters and concatenate tokens.
   */
   ipProcessLinkedListParameterContinuationCharacters(&raw_tokens_list);

   /* Parse the command-line or stdin parameters.
   */
   ipParseCommandLineParameters(&raw_tokens_list);

#if 1
   /* Search for a matching command template and execute the command if appropriate
   ** or error out if no template match.
   */
   ipExecuteCommand();
#endif


#if 0
   /* For diagnostic purposes, print out the linked list. */
      {
      struct ipSimpleStringLlNodeStruct *p;
      
      p = raw_tokens_list;

      while (p)
         {
         printf("%s\n", p->s);

         p = p->next;
         }

      }
#endif
#if 0
   gfBannerHeading("Test 21", 2);
#endif

   /*************************************************************************/
   printf("RAP execution ends.\n");gfHline();
   /*************************************************************************/
   return(0);  /* Return value not set for caller--zero used in all cases.  */
   /*************************************************************************/
   }


/* $History: rap_c.c $ 
 * 
 * *****************  Version 21  *****************
 * User: Dashley1     Date: 11/13/00   Time: 3:59a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Final versions for submission to the ACM.
 * 
 * *****************  Version 20  *****************
 * User: Dashley1     Date: 11/10/00   Time: 10:49a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Completion of FAB functionality.
 * 
 * *****************  Version 19  *****************
 * User: Dashley1     Date: 11/09/00   Time: 1:04a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Completion of minimum denominator work.
 * 
 * *****************  Version 18  *****************
 * User: Dashley1     Date: 11/01/00   Time: 6:21p
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * FN functionality completed.
 * 
 * *****************  Version 17  *****************
 * User: Dashley1     Date: 11/01/00   Time: 4:42a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * FN functionality mostly complete.  Throws an OS exception when rational
 * number to approximate is < 1/N, need to proofread and diagnose.
 * 
 * *****************  Version 16  *****************
 * User: Dashley1     Date: 10/30/00   Time: 6:40p
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Completion of CF expansion functionality.
 * 
 * *****************  Version 15  *****************
 * User: Dashley1     Date: 10/29/00   Time: 10:09p
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * DAP function finished and checked.
 * 
 * *****************  Version 14  *****************
 * User: Dashley1     Date: 10/29/00   Time: 4:00a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Safety check-in.
 * 
 * *****************  Version 13  *****************
 * User: Dashley1     Date: 10/28/00   Time: 4:23a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Rational number parsing complete.
 * 
 * *****************  Version 12  *****************
 * User: Dashley1     Date: 10/27/00   Time: 4:03a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * gcd() functionality implemented and tested.
 * 
 * *****************  Version 11  *****************
 * User: Dashley1     Date: 10/27/00   Time: 3:18a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Division function checked in and tested.  Safety check-in.
 * 
 * *****************  Version 10  *****************
 * User: Dashley1     Date: 10/26/00   Time: 3:05a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Safety check-in.  Integer exponentiation complete.
 * 
 * *****************  Version 9  *****************
 * User: Dashley1     Date: 10/25/00   Time: 3:28a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Safety check-in.
 * 
 * *****************  Version 8  *****************
 * User: Dashley1     Date: 10/23/00   Time: 7:18p
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Safety check-in.
 * 
 * *****************  Version 7  *****************
 * User: Dashley1     Date: 10/23/00   Time: 12:01a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Major progress, safety check-in.
 * 
 * *****************  Version 6  *****************
 * User: Dashley1     Date: 10/20/00   Time: 3:30p
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Safety check-in.
 * 
 * *****************  Version 5  *****************
 * User: Dashley1     Date: 10/20/00   Time: 5:12a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Test of keyword expansion when keywords on same line.
 * 
 * *****************  Version 4  *****************
 * User: Dashley1     Date: 10/20/00   Time: 4:35a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Test checkin to test keyword expansion changes.
 * 
 * *****************  Version 3  *****************
 * User: Dashley1     Date: 10/18/00   Time: 4:15a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Second check-in to test VC embedding.
 * 
 * *****************  Version 2  *****************
 * User: Dashley1     Date: 10/18/00   Time: 4:08a
 * Updated in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Check-in to test version embedding functionality.
 * 
 * *****************  Version 1  *****************
 * User: Dashley1     Date: 10/18/00   Time: 3:58a
 * Created in $/ACM Rational Approximation Paper And Algorithms/C-Language Implementation
 * Initial check-in.
 */

/* End of file RAP_C.C */