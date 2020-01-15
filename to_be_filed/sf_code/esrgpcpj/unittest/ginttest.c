// $Header: /cvsroot/esrg/sfesrg/esrgpcpj/unittest/ginttest.c,v 1.14 2002/05/16 04:21:50 dtashley Exp $

//--------------------------------------------------------------------------------
//Copyright 2002 David T. Ashley
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
#define MODULE_GINTTEST

#include <malloc.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "bstrfunc.h"
#include "fcmiof.h"
#include "ginttest.h"
#include "gmp_ints.h"


int GINTTEST_data_sizes_wrong_test(void)
   {
   printf("Testing the GMP_INTS_data_sizes_are_wrong() function.\n");

   FCMIOF_hline();

   if (GMP_INTS_data_sizes_are_wrong())
      return(1);
   else
      return(0);
   }


int GINTTEST_mpn_add_1_test(void)
   {
   int rv=0;
   int i, j;
   int carry_out;

   GMP_INTS_limb_t inlimbs[5];
   GMP_INTS_limb_t outlimbs[5];

   //These are the test vectors for the
   //add_1 function.
   static struct add_1_test_vector_struct
      {
      char *desc;
         //The purpose of the test vector, what is
         //is trying to show.
      //The starting values of the "input" of up to
      //5 limbs.
      GMP_INTS_limb_t sin4;
      GMP_INTS_limb_t sin3;
      GMP_INTS_limb_t sin2;
      GMP_INTS_limb_t sin1;
      GMP_INTS_limb_t sin0;
      //The fill value for the output struct.
      //It is filled to avoid undetected corruption.
      GMP_INTS_limb_t ofillval;
      int size; //The size of the array of limbs to
                //be added to.
      GMP_INTS_limb_t addval;
                //The value of the single limb to be added.
      //The required values for the output array.
      GMP_INTS_limb_t oreq4;
      GMP_INTS_limb_t oreq3;
      GMP_INTS_limb_t oreq2;
      GMP_INTS_limb_t oreq1;
      GMP_INTS_limb_t oreq0;
      //The required carry out.
      int reqcarry;
      } tvs[] =
      {
         {
         "Zero added to zero in one limb must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         1,
         0,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0xA55AA55A,0,
         0
         },
         {
         "Zero added to zero in two limbs must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         2,
         0,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0,0,
         0
         },
         {
         "Zero added to zero in three limbs must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         3,
         0,
         0xA55AA55A,0xA55AA55A,0,0,0,
         0
         },
         {
         "Checking carry out of single-limb result.",
         0, 0, 0, 0, 3,
         0xA55AA55A,
         1,
         0xFFFFFFFD,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0xA55AA55A,0,
         1
         },
         {
         "Checking rollover out of single-limb result.",
         0, 0, 0, 0, 5,
         0xA55AA55A,
         1,
         0xFFFFFFFD,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0xA55AA55A,2,
         1
         },
         {
         "Checking three limb roll to zero.",
         0, 0, 0xFFFFFFFF, 0xFFFFFFFF, 3,
         0xA55AA55A,
         3,
         0xFFFFFFFD,
         0xA55AA55A,0xA55AA55A,0,0,0,
         1
         },
         {
         "Checking three limb failure to roll.",
         0, 0, 0xFFFFFFFF, 0xFFFFFFFF, 2,
         0xA55AA55A,
         3,
         0xFFFFFFFD,
         0xA55AA55A,0xA55AA55A,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,
         0
         },
      };

   //For each test vector.
   for(i=0; i<sizeof(tvs)/sizeof(tvs[0]); i++)
      {
      struct add_1_test_vector_struct *p;
      p = &(tvs[i]);

      printf("Executing GMP_INTS_mpn_add_1() test vector: %d\n", i);
      printf("Test vector purpose:\n   %s\n", p->desc);

      //Set up for the test vector.
      inlimbs[4] = p->sin4;
      inlimbs[3] = p->sin3;
      inlimbs[2] = p->sin2;
      inlimbs[1] = p->sin1;
      inlimbs[0] = p->sin0;
      for (j=0; j<5; j++)
         {
         outlimbs[j] = p->ofillval;
         }

      carry_out = GMP_INTS_mpn_add_1(outlimbs, 
                                     inlimbs, 
                                     p->size, 
                                     p->addval);

      if (carry_out != p->reqcarry)
         {
         rv = 1;
         printf("   Carry FAILED.\n");
         }
      if (inlimbs[4] != p->sin4)
         {
         rv = 1;
         printf("   inlimbs[4] FAILED.\n");
         }
      if (inlimbs[3] != p->sin3)
         {
         rv = 1;
         printf("   inlimbs[3] FAILED.\n");
         }
      if (inlimbs[2] != p->sin2)
         {
         rv = 1;
         printf("   inlimbs[2] FAILED.\n");
         }
      if (inlimbs[1] != p->sin1)
         {
         rv = 1;
         printf("   inlimbs[1] FAILED.\n");
         }
      if (inlimbs[0] != p->sin0)
         {
         rv = 1;
         printf("   inlimbs[0] FAILED.\n");
         }
      if (outlimbs[4] != p->oreq4)
         {
         rv = 1;
         printf("   outlimbs[4] FAILED.\n");
         }
      if (outlimbs[3] != p->oreq3)
         {
         rv = 1;
         printf("   outlimbs[3] FAILED.\n");
         }
      if (outlimbs[2] != p->oreq2)
         {
         rv = 1;
         printf("   outlimbs[2] FAILED.\n");
         }
      if (outlimbs[1] != p->oreq1)
         {
         rv = 1;
         printf("   outlimbs[1] FAILED.\n");
         }
      if (outlimbs[0] != p->oreq0)
         {
         rv = 1;
         printf("   outlimbs[0] FAILED.\n");
         }

      FCMIOF_hline();
      }

   return(rv);
   }


int GINTTEST_mpn_sub_1_test(void)
   {
   int rv=0;
   int i, j;
   int carry_out;

   GMP_INTS_limb_t inlimbs[5];
   GMP_INTS_limb_t outlimbs[5];

   //These are the test vectors for the
   //add_1 function.
   static struct sub_1_test_vector_struct
      {
      char *desc;
         //The purpose of the test vector, what is
         //is trying to show.
      //The starting values of the "input" of up to
      //5 limbs.
      GMP_INTS_limb_t sin4;
      GMP_INTS_limb_t sin3;
      GMP_INTS_limb_t sin2;
      GMP_INTS_limb_t sin1;
      GMP_INTS_limb_t sin0;
      //The fill value for the output struct.
      //It is filled to avoid undetected corruption.
      GMP_INTS_limb_t ofillval;
      int size; //The size of the array of limbs to
                //be added to.
      GMP_INTS_limb_t subval;
                //The value of the single limb to be subtracted.
      //The required values for the output array.
      GMP_INTS_limb_t oreq4;
      GMP_INTS_limb_t oreq3;
      GMP_INTS_limb_t oreq2;
      GMP_INTS_limb_t oreq1;
      GMP_INTS_limb_t oreq0;
      //The required borrow out.
      int reqborrow;
      } tvs[] =
      {
         {
         "Zero subracted from zero in one limb must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         1,
         0,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0xA55AA55A,0,
         0
         },
         {
         "Zero subtracted from zero in two limbs must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         2,
         0,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0,0,
         0
         },
         {
         "Zero subtracted from zero in three limbs must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         3,
         0,
         0xA55AA55A,0xA55AA55A,0,0,0,
         0
         },
         {
         "Checking borrow out of single-limb result.",
         0, 0, 0, 0, 3,
         0xA55AA55A,
         1,
         4,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0xA55AA55A,0xFFFFFFFF,
         1
         },
         {
         "Checking three limb roll to -1.",
         0, 0, 0, 0, 12,
         0xA55AA55A,
         3,
         13,
         0xA55AA55A,0xA55AA55A,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,
         1
         },
         {
         "Checking three limb failure to roll backwards.",
         0, 0, 0, 0, 2,
         0xA55AA55A,
         3,
         2,
         0xA55AA55A,0xA55AA55A,0,0,0,
         0
         },
      };

   //For each test vector.
   for(i=0; i<sizeof(tvs)/sizeof(tvs[0]); i++)
      {
      struct sub_1_test_vector_struct *p;
      p = &(tvs[i]);

      printf("Executing GMP_INTS_mpn_sub_1() test vector: %d\n", i);
      printf("Test vector purpose:\n   %s\n", p->desc);

      //Set up for the test vector.
      inlimbs[4] = p->sin4;
      inlimbs[3] = p->sin3;
      inlimbs[2] = p->sin2;
      inlimbs[1] = p->sin1;
      inlimbs[0] = p->sin0;
      for (j=0; j<5; j++)
         {
         outlimbs[j] = p->ofillval;
         }

      carry_out = GMP_INTS_mpn_sub_1(outlimbs, 
                                     inlimbs, 
                                     p->size, 
                                     p->subval);

      if (carry_out != p->reqborrow)
         {
         rv = 1;
         printf("   Borrow FAILED.\n");
         }
      if (inlimbs[4] != p->sin4)
         {
         rv = 1;
         printf("   inlimbs[4] FAILED.\n");
         }
      if (inlimbs[3] != p->sin3)
         {
         rv = 1;
         printf("   inlimbs[3] FAILED.\n");
         }
      if (inlimbs[2] != p->sin2)
         {
         rv = 1;
         printf("   inlimbs[2] FAILED.\n");
         }
      if (inlimbs[1] != p->sin1)
         {
         rv = 1;
         printf("   inlimbs[1] FAILED.\n");
         }
      if (inlimbs[0] != p->sin0)
         {
         rv = 1;
         printf("   inlimbs[0] FAILED.\n");
         }
      if (outlimbs[4] != p->oreq4)
         {
         rv = 1;
         printf("   outlimbs[4] FAILED.\n");
         }
      if (outlimbs[3] != p->oreq3)
         {
         rv = 1;
         printf("   outlimbs[3] FAILED.\n");
         }
      if (outlimbs[2] != p->oreq2)
         {
         rv = 1;
         printf("   outlimbs[2] FAILED.\n");
         }
      if (outlimbs[1] != p->oreq1)
         {
         rv = 1;
         printf("   outlimbs[1] FAILED.\n");
         }
      if (outlimbs[0] != p->oreq0)
         {
         rv = 1;
         printf("   outlimbs[0] FAILED.\n");
         }

      FCMIOF_hline();
      }

   return(rv);
   }


int GINTTEST_mpn_mul_1_test(void)
   {
   int rv=0;
   int i, j;
   GMP_INTS_limb_t carry_out;

   GMP_INTS_limb_t inlimbs[5];
   GMP_INTS_limb_t outlimbs[5];

   //These are the test vectors for the
   //mul_1 function.
   static struct mul_1_test_vector_struct
      {
      char *desc;
         //The purpose of the test vector, what is
         //is trying to show.
      //The starting values of the "input" of up to
      //5 limbs.
      GMP_INTS_limb_t sin4;
      GMP_INTS_limb_t sin3;
      GMP_INTS_limb_t sin2;
      GMP_INTS_limb_t sin1;
      GMP_INTS_limb_t sin0;
      //The fill value for the output struct.
      //It is filled to avoid undetected corruption.
      GMP_INTS_limb_t ofillval;
      int size; //The size of the array of limbs to
                //be added to.
      GMP_INTS_limb_t mulval;
                //The value of the single limb to be multiplied.
      //The required values for the output array.
      GMP_INTS_limb_t oreq4;
      GMP_INTS_limb_t oreq3;
      GMP_INTS_limb_t oreq2;
      GMP_INTS_limb_t oreq1;
      GMP_INTS_limb_t oreq0;
      //The required carry out.
      GMP_INTS_limb_t reqcarry;
      } tvs[] =
      {
         {
         "Zero multiplied by zero in one limb must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         1,
         0,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0xA55AA55A,0,
         0
         },
         {
         "Zero multiplied by zero in two limbs must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         2,
         0,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0,0,
         0
         },
         {
         "Zero multiplied by zero in three limbs must be zero.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         3,
         0,
         0xA55AA55A,0xA55AA55A,0,0,0,
         0
         },
         {
         "Zero times anything must be zero in 3 limbs.",
         0, 0, 0xA5, 0x5A5A5A5A, 33,
         0xA55AA55A,
         3,
         0,
         0xA55AA55A,0xA55AA55A,0,0,0,
         0
         },
         {
         "Anything times zero must be zero in 3 limbs.",
         0, 0, 0, 0, 0,
         0xA55AA55A,
         3,
         0xA55AA55A,
         0xA55AA55A,0xA55AA55A,0,0,0,
         0
         },
         {
         "150001 times 150003 must generate 0x53D23E8C3.",
         0, 0, 0, 0, 150003,
         0xA55AA55A,
         3,
         150001,
         0xA55AA55A,0xA55AA55A,0,0x5,0x3D23E8C3,
         0
         },
         {
         "150001 times 150003 in 1 limb must generate 0x3D23E8C3 and carry of 5.",
         0, 0, 0, 0, 150003,
         0xA55AA55A,
         1,
         150001,
         0xA55AA55A,0xA55AA55A,0xA55AA55A,0xA55AA55A,0x3D23E8C3,
         5
         },
      };


   //For each test vector.
   for(i=0; i<sizeof(tvs)/sizeof(tvs[0]); i++)
      {
      struct mul_1_test_vector_struct *p;
      p = &(tvs[i]);

      printf("Executing GMP_INTS_mpn_mul_1() test vector: %d\n", i);
      printf("Test vector purpose:\n   %s\n", p->desc);

      //Set up for the test vector.
      inlimbs[4] = p->sin4;
      inlimbs[3] = p->sin3;
      inlimbs[2] = p->sin2;
      inlimbs[1] = p->sin1;
      inlimbs[0] = p->sin0;
      for (j=0; j<5; j++)
         {
         outlimbs[j] = p->ofillval;
         }

      carry_out = GMP_INTS_mpn_mul_1(outlimbs, 
                                     inlimbs, 
                                     p->size, 
                                     p->mulval);

      if (carry_out != p->reqcarry)
         {
         rv = 1;
         printf("   Borrow FAILED.\n");
         }
      if (inlimbs[4] != p->sin4)
         {
         rv = 1;
         printf("   inlimbs[4] FAILED.\n");
         }
      if (inlimbs[3] != p->sin3)
         {
         rv = 1;
         printf("   inlimbs[3] FAILED.\n");
         }
      if (inlimbs[2] != p->sin2)
         {
         rv = 1;
         printf("   inlimbs[2] FAILED.\n");
         }
      if (inlimbs[1] != p->sin1)
         {
         rv = 1;
         printf("   inlimbs[1] FAILED.\n");
         }
      if (inlimbs[0] != p->sin0)
         {
         rv = 1;
         printf("   inlimbs[0] FAILED.\n");
         }
      if (outlimbs[4] != p->oreq4)
         {
         rv = 1;
         printf("   outlimbs[4] FAILED.\n");
         }
      if (outlimbs[3] != p->oreq3)
         {
         rv = 1;
         printf("   outlimbs[3] FAILED.\n");
         }
      if (outlimbs[2] != p->oreq2)
         {
         rv = 1;
         printf("   outlimbs[2] FAILED.\n");
         }
      if (outlimbs[1] != p->oreq1)
         {
         rv = 1;
         printf("   outlimbs[1] FAILED.\n");
         }
      if (outlimbs[0] != p->oreq0)
         {
         rv = 1;
         printf("   outlimbs[0] FAILED.\n");
         }

      FCMIOF_hline();
      }

   return(rv);
   }


int GINTTEST_alloca_test(void)
   {
   int rv=0;
   GMP_INTS_limb_ptr p1, p2;
   time_t t;
   int i;

   printf("Testing _alloca() function.\n");

   //Grab the time to get a random element.  Will use
   //the last two bits of this to decide what order to
   //try things.  The danger in doing it another way
   //has to do once stack segments allocated are not
   //automatically unallocated--any sequential (rather than
   //random) approach may not reveal holes.

   t = time(NULL);

   //Grab two pointers to outrageous max chunks of memory.
   //This is expected to be beyond worst case.


   p1 = _alloca((GMP_INTS_MAXIMUM_LIMBS_PER_INT+100) * sizeof(GMP_INTS_limb_t));
   p2 = _alloca((GMP_INTS_MAXIMUM_LIMBS_PER_INT+200) * sizeof(GMP_INTS_limb_t));

   switch (t&0x7)
      {
      case 0:  
         printf("Case 0:  p1 ascending, then p2 ascending.\n");
         for (i=0; i<GMP_INTS_MAXIMUM_LIMBS_PER_INT+100; i++)
           p1[i] = (0xA55AA55A ^ t);
         for (i=0; i<GMP_INTS_MAXIMUM_LIMBS_PER_INT+200; i++)
           p2[i] = (0xA55AA55A ^ t);
         break;
      case 1:  
         printf("Case 1:  p1 ascending, then p2 descending.\n");
         for (i=0; i<GMP_INTS_MAXIMUM_LIMBS_PER_INT+100; i++)
           p1[i] = (0xA55AA55A ^ t);
         for (i=GMP_INTS_MAXIMUM_LIMBS_PER_INT+200-1; i>=0; i--)
           p2[i] = (0xA55AA55A ^ t);
         break;
      case 2:  
         printf("Case 2:  p1 descending, then p2 ascending.\n");
         for (i=GMP_INTS_MAXIMUM_LIMBS_PER_INT+100-1; i>=0; i--)
           p1[i] = (0xA55AA55A ^ t);
         for (i=0; i<GMP_INTS_MAXIMUM_LIMBS_PER_INT+200; i++)
           p2[i] = (0xA55AA55A ^ t);
         break;
      case 3:
         printf("Case 3:  p1 descending, then p2 descending.\n");
         for (i=GMP_INTS_MAXIMUM_LIMBS_PER_INT+100-1; i>=0; i--)
           p1[i] = (0xA55AA55A ^ t);
         for (i=GMP_INTS_MAXIMUM_LIMBS_PER_INT+200-1; i>=0; i--)
           p2[i] = (0xA55AA55A ^ t);
         break;
      case 4:  
         printf("Case 4:  p2 ascending, then p1 ascending.\n");
         for (i=0; i<GMP_INTS_MAXIMUM_LIMBS_PER_INT+200; i++)
           p2[i] = (0xA55AA55A ^ t);
         for (i=0; i<GMP_INTS_MAXIMUM_LIMBS_PER_INT+100; i++)
           p1[i] = (0xA55AA55A ^ t);
         break;
      case 5:  
         printf("Case 5:  p2 descending, then p1 ascending.\n");
         for (i=GMP_INTS_MAXIMUM_LIMBS_PER_INT+200-1; i>=0; i--)
           p2[i] = (0xA55AA55A ^ t);
         for (i=0; i<GMP_INTS_MAXIMUM_LIMBS_PER_INT+100; i++)
           p1[i] = (0xA55AA55A ^ t);
         break;
      case 6:  
         printf("Case 6:  p2 ascending, then p1 descending.\n");
         for (i=0; i<GMP_INTS_MAXIMUM_LIMBS_PER_INT+200; i++)
           p2[i] = (0xA55AA55A ^ t);
         for (i=GMP_INTS_MAXIMUM_LIMBS_PER_INT+100-1; i>=0; i--)
           p1[i] = (0xA55AA55A ^ t);
         break;
      case 7: 
         printf("Case 7:  p2 descending, p1 descending.\n");
         for (i=GMP_INTS_MAXIMUM_LIMBS_PER_INT+200-1; i>=0; i--)
           p2[i] = (0xA55AA55A ^ t);
         for (i=GMP_INTS_MAXIMUM_LIMBS_PER_INT+100-1; i>=0; i--)
           p1[i] = (0xA55AA55A ^ t);
         break;
      default:
         abort();
         break;
      }


   FCMIOF_hline();

   return(rv);
   }


int GINTTEST_mpz_set_simple_char_str_test(void)
   {
   int rv=0;
   int i;
   GMP_INTS_mpz_struct x;

   char *sa[] =
      {
      "0",
      "1",
      "-1",
      "2",
      "-2",
      "3",
      "-3",
      "9",
      "-9",
      "10",
      "-10",
      "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319",
      };

   printf("Testing GMP_INTS_mpz_set_simple_char_str() function.\n");
   printf("This test will consist of setting an integer to several\n");
   printf("string values and examining the result.\n");
   FCMIOF_hline();

   //Initialize the integer.
   GMP_INTS_mpz_init(&x);

   for (i=0; i<sizeof(sa)/sizeof(sa[0]); i++)
      {
      printf("Trying value: %s\n", sa[i]);
      GMP_INTS_mpz_set_simple_char_str(&x, sa[i]);
      GMP_INTS_mpz_print_int(stdout, &x, "Result.");
      FCMIOF_hline();
      }

   //Destroy the integer.
   GMP_INTS_mpz_clear(&x);

   return(rv);
   }



int GINTTEST_mpz_add_test(void)
   {
   int rv=0;
   int i;

   GMP_INTS_mpz_struct k0, k1, k2, k3, k1000, kneg1, x, y, z;

   //First, check the move upwards from zero.
   printf("Preparing to test mpz_add() function.\n");
   FCMIOF_hline();
   printf("Allocating integers.\n");
   GMP_INTS_mpz_init(&k0);
   GMP_INTS_mpz_init(&k1);
   GMP_INTS_mpz_init(&k2);
   GMP_INTS_mpz_init(&k3);
   GMP_INTS_mpz_init(&k1000);
   GMP_INTS_mpz_init(&kneg1);
   GMP_INTS_mpz_init(&x);
   GMP_INTS_mpz_init(&y);
   GMP_INTS_mpz_init(&z);
   FCMIOF_hline();

   printf("Setting constants to prescribed values.\n");
   GMP_INTS_mpz_set_si (&k0, 0);
   GMP_INTS_mpz_set_si (&k1, 1);
   GMP_INTS_mpz_set_si (&k2, 2);
   GMP_INTS_mpz_set_si (&k3, 3);
   GMP_INTS_mpz_set_si (&k1000, 1000);
   GMP_INTS_mpz_set_si (&kneg1, -1);


   printf("Starting from zero and going up by 1's.\n");
   GMP_INTS_mpz_set_si (&x, 0);

   for (i=0; i<15; i++)
      {
      GMP_INTS_mpz_add(&x, &k1, &x);
      GMP_INTS_mpz_print_int(stdout, &x, "Addition result.");
      FCMIOF_hline();
      }

   printf("Adding a negative number, going back by 1's.\n");
   for (i=0; i<29; i++)
      {
      GMP_INTS_mpz_add(&x, &kneg1, &x);
      GMP_INTS_mpz_print_int(stdout, &x, "Addition result.");
      FCMIOF_hline();
      }

   printf("Now checking exponential growth until overflow.\n");
   FCMIOF_hline();

   i=0;
   while (!GMP_INTS_mpz_get_flags(&x))
      {
      i++;
      GMP_INTS_mpz_add(&x, &x, &x);
      //GMP_INTS_mpz_print_int(stdout, &x, "Addition result.");
      //FCMIOF_hline();
      }

   printf("Exponential growth terminated in %d iterations.\n", i);

   printf("Deallocating integers.\n");
   GMP_INTS_mpz_clear(&k0);
   GMP_INTS_mpz_clear(&k1);
   GMP_INTS_mpz_clear(&k2);
   GMP_INTS_mpz_clear(&k3);
   GMP_INTS_mpz_clear(&k1000);
   GMP_INTS_mpz_clear(&x);
   GMP_INTS_mpz_clear(&y);
   GMP_INTS_mpz_clear(&z);
   GMP_INTS_mpz_clear(&kneg1);
   FCMIOF_hline();

   return(rv);
   }


int GINTTEST_mpz_tdiv_qr_test(void)
   {
   int rv=0;
   int i;

   GMP_INTS_mpz_struct dividend, divisor, quotient, remainder;

   //For each of these tests, we want to walk through the division
   //routine (with a debugger) to make sure that everything is
   //as expected.  The table below is a list of dividends
   //and divisors.
   static struct 
      {
      char *dividend;
      char *divisor;
      } ttbl[]
      =  {
            {
            "0",
            "0"
            },
            {
            "14",
            "25"
            },
            {
            "25",
            "14"
            },
            {
            "259414911",
            "1479"
            },
         };


   //Initialize all four of the arbitrary integers.
   GMP_INTS_mpz_init(&dividend);
   GMP_INTS_mpz_init(&divisor);
   GMP_INTS_mpz_init(&quotient);
   GMP_INTS_mpz_init(&remainder);

   //For each of the sets of integers, go through and
   //try them out.  Will take a debugger on these.
   for (i=0; i<sizeof(ttbl)/sizeof(ttbl[0]); i++)
      {
      //Announce what is happening.
      printf("Testing GINTTEST_mpz_tdiv_qr().\n");
      printf("Dividend: %s\n", ttbl[i].dividend);
      printf("Divisor:  %s\n", ttbl[i].divisor);
      FCMIOF_hline();

      //Set the integers.
      GMP_INTS_mpz_set_simple_char_str(&dividend, ttbl[i].dividend);
      GMP_INTS_mpz_set_simple_char_str(&divisor,  ttbl[i].divisor);

      //Announce what has been set, plus the other parameters.
      GMP_INTS_mpz_print_int(stdout, &dividend, "Dividend before division.");
      FCMIOF_hline();
      GMP_INTS_mpz_print_int(stdout, &divisor,  "Divisor before division.");
      FCMIOF_hline();
      GMP_INTS_mpz_print_int(stdout, &quotient, "Quotient before division.");
      FCMIOF_hline();
      GMP_INTS_mpz_print_int(stdout, &remainder,"Remainder before division.");
      FCMIOF_hline();

      //Perform the actual division.
      printf("Performing division ... ");
      GMP_INTS_mpz_tdiv_qr (&quotient, &remainder, &dividend, &divisor);
      printf("done.\n");
      FCMIOF_hline();

      //Print out the results after the division.
      GMP_INTS_mpz_print_int(stdout, &quotient, "Quotient after division.");
      FCMIOF_hline();
      GMP_INTS_mpz_print_int(stdout, &remainder,"Remainder after division.");
      FCMIOF_hline();
      GMP_INTS_mpz_print_int(stdout, &dividend, "Dividend after division.");
      FCMIOF_hline();
      GMP_INTS_mpz_print_int(stdout, &divisor,  "Divisor after division.");
      FCMIOF_hline();
      }

   //Deallocate all four of the arbitrary integers.
   GMP_INTS_mpz_clear(&dividend);
   GMP_INTS_mpz_clear(&divisor);
   GMP_INTS_mpz_clear(&quotient);
   GMP_INTS_mpz_clear(&remainder);

   return(rv);
   }


int GINTTEST_mpz_mul_test(void)
   {
   int rv=0;
   GMP_INTS_mpz_struct x;

   printf("Preparing to test mpz_mul() function.\n");

   //There isn't a lot that can be tested without more test
   //cases.
   //For now, just be sure that large powers of two show a 
   //corresponding bit pattern.

   GMP_INTS_mpz_init(&x);

   //This string constant was obtained from the RAP program
   //and is known to be 2**4000.  This is my only test case
   //for now.
   GMP_INTS_mpz_set_simple_char_str
      (
      &x,
      "13,182,040,934,309,431,"
      "001,038,897,942,365,913,631,840,191,"
      "610,932,727,690,928,034,502,417,569,"
      "281,128,344,551,079,752,123,172,122,"
      "033,140,940,756,480,716,823,038,446,"
      "817,694,240,581,281,731,062,452,512,"
      "184,038,544,674,444,386,888,956,328,"
      "970,642,771,993,930,036,586,552,924,"
      "249,514,488,832,183,389,415,832,375,"
      "620,009,284,922,608,946,111,038,578,"
      "754,077,913,265,440,918,583,125,586,"
      "050,431,647,284,603,636,490,823,850,"
      "007,826,811,672,468,900,210,689,104,"
      "488,089,485,347,192,152,708,820,119,"
      "765,006,125,944,858,397,761,874,669,"
      "301,278,745,233,504,796,586,994,514,"
      "054,435,217,053,803,732,703,240,283,"
      "400,815,926,169,348,364,799,472,716,"
      "094,576,894,007,243,168,662,568,886,"
      "603,065,832,486,830,606,125,017,643,"
      "356,469,732,407,252,874,567,217,733,"
      "694,824,236,675,323,341,755,681,839,"
      "221,954,693,820,456,072,020,253,884,"
      "371,226,826,844,858,636,194,212,875,"
      "139,566,587,445,390,068,014,747,975,"
      "813,971,748,114,770,439,248,826,688,"
      "667,129,237,954,128,555,841,874,460,"
      "665,729,630,492,658,600,179,338,272,"
      "579,110,020,881,228,767,361,200,603,"
      "478,973,120,168,893,997,574,353,727,"
      "653,998,969,223,092,798,255,701,666,"
      "067,972,698,906,236,921,628,764,772,"
      "837,915,526,086,464,389,161,570,534,"
      "616,956,703,744,840,502,975,279,094,"
      "087,587,298,968,423,516,531,626,090,"
      "898,389,351,449,020,056,851,221,079,"
      "048,966,718,878,943,309,232,071,978,"
      "575,639,877,208,621,237,040,940,126,"
      "912,767,610,658,141,079,378,758,043,"
      "403,611,425,454,744,180,577,150,855,"
      "204,937,163,460,902,512,732,551,260,"
      "539,639,221,457,005,977,247,266,676,"
      "344,018,155,647,509,515,396,711,351,"
      "487,546,062,479,444,592,779,055,555,"
      "421,362,722,504,575,706,910,949,376");

   GMP_INTS_mpz_print_int(stdout, &x, "2**4000 (I hope)");

   GMP_INTS_mpz_clear(&x);

   FCMIOF_hline();

   return(rv);
   }


int GINTTEST_speed_tests(void)
   {
   int rv=0;
   int fnum;
   int i;
   unsigned long lc;
   time_t time1, time2;
   GMP_INTS_limb_t arg1[10];
   GMP_INTS_limb_t arg2[10];
   GMP_INTS_limb_t arg3[10];

   GMP_INTS_mpz_struct ten_limber_a, ten_limber_b, result;

   //Initialize (allocate space) for three arbitrary integers.
   GMP_INTS_mpz_init(&ten_limber_a);
   GMP_INTS_mpz_init(&ten_limber_b);
   GMP_INTS_mpz_init(&result);

   //Assign two different integers to be 10-limb integers.
   GMP_INTS_mpz_set_simple_char_str(
     &ten_limber_a,
     "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
   GMP_INTS_mpz_set_simple_char_str(
     &ten_limber_b,
     "232754932472365498327432654903279999966943265932609327423947234793297873254943265943265943265319");

   //Set up sets of test limbs.
   for (i=0; i<10; i++)
      {
      arg1[i] = 0xA55AA55A;
      arg2[i] = 0x5AA55AA5;
      arg3[i] = 0xA55AA55A;
      }


   printf("Beginning speed testing of GMP_INTS module functions.\n");

   FCMIOF_hline();

   for (fnum=0; fnum<14; fnum++)
      {
      printf("Speed-testing function:  ");

      switch(fnum)
         {
         case  0: printf("GMP_INTS_data_sizes_are_wrong()");
                  break;
         case  1: printf("GMP_INTS_mpz_sgn()");
                  break;
         case  2: printf("GMP_INTS_is_neg()");
                  break;
         case  3: printf("GMP_INTS_is_zero()");
                  break;
         case  4: printf("GMP_INTS_is_pos()");
                  break;
         case  5: printf("GMP_INTS_is_odd()");
                  break;
         case  6: printf("GMP_INTS_is_even()");
                  break;
         case  7: printf("GMP_INTS_mpn_add_1()");
                  break;
         case  8: printf("GMP_INTS_mpn_sub_1()");
                  break;
         case  9: printf("GMP_INTS_mpn_mul_1()");
                  break;
         case 10: printf("GMP_INTS_mpn_add_n()");
                  break;
         case 11: printf("GMP_INTS_mpz_add()");
                  break;
         case 12: printf("GMP_INTS_mpz_set_simple_char_str()");
                  break;
         case 13: printf("GMP_INTS_mpz_mul()");
                  break;
         default:
                  abort();
                  break;
         }

      printf("\n");
      printf("All operands are 10 limbs (320 bits) long.\n");

      //Synchronize to a change in seconds.
      time1 = time(NULL);
      while (time1 == (time2 = time(NULL)));
      //We had a transition.  time2 has the new time.

      lc = 0;
      while (time2 == time(NULL))
         {
         lc ++;

         switch(fnum)
            {
            case  0: GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     GMP_INTS_data_sizes_are_wrong();
                     break;
            case  1: //Can't test int GMP_INTS_mpz_sgn()
                     //yet.
                     break;
            case  2: //Can't test int GMP_INTS_mpz_is_neg()
                     //yet.
                     break;
            case  3: //Can't test int GMP_INTS_mpz_is_zero()
                     //yet.
                     break;
            case  4: //Can't test int GMP_INTS_mpz_is_pos()
                     //yet.
                     break;
            case  5: //Can't test int GMP_INTS_mpz_is_odd()
                     //yet.
                     break;
            case  6: //Can't test int GMP_INTS_mpz_is_even()
                     //yet.
                     break;
            case  7: GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_add_1(arg3, arg1, 10, arg2[0]);
                     break;
            case  8: GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_sub_1(arg3, arg1, 10, arg2[0]);
                     break;
            case  9: GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     GMP_INTS_mpn_mul_1(arg3, arg1, 10, arg2[0]);
                     break;
            case 10: GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);  
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     GMP_INTS_mpn_add_n(arg3, arg2, arg1, 10);
                     break;
            case 11: GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     GMP_INTS_mpz_add(&result, &ten_limber_a, &ten_limber_b);                       
                     break;
            case 12: GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     GMP_INTS_mpz_set_simple_char_str(&result, "232754932472365498327432654903274693266943265932609327423947234793297873254943265943265943265319");
                     break;
            case 13: GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     GMP_INTS_mpz_mul(&result, &ten_limber_a, &ten_limber_b);
                     break;
            default:
                     abort();
                     break;
            }
         
         }


      lc *= 15;
      printf("%ld executions in 1 second, ignoring time() call.\n", lc);
      

      FCMIOF_hline();
      }

   printf("Ending speed testing of GMP_INTS module functions.\n");

   //Clear (deallocate storage) for three integers.
   GMP_INTS_mpz_clear(&ten_limber_a);
   GMP_INTS_mpz_clear(&ten_limber_b);
   GMP_INTS_mpz_clear(&result);

   FCMIOF_hline();

   return(rv);
   }


int GINTTEST_to_string_test(void)
   {
   int rv=0;
   int predicted, actual;
   char *p;

   GMP_INTS_mpz_struct old_arg;
   GMP_INTS_mpz_struct arg;
   GMP_INTS_mpz_struct k3;

   printf("Testing string formatting.\n");
   FCMIOF_hline();

   //Initialize (allocate space) for integer.
   GMP_INTS_mpz_init(&old_arg);
   GMP_INTS_mpz_init(&arg);
   GMP_INTS_mpz_init(&k3);

   //The central strategy of this
   //function is just to keep on going until
   //overflow.
   GMP_INTS_mpz_set_si(&k3, -1097116912);
   GMP_INTS_mpz_set_ui(&arg, 1);

   do
      {
      //Multiply the arg by k3 until we hit a fair size.
      GMP_INTS_mpz_copy(&old_arg, &arg);
      GMP_INTS_mpz_mul(&arg, &arg, &k3);
      }
   while (arg.size < 100);

   GMP_INTS_mpz_copy(&arg, &old_arg);

   //Figure out and announce how many characters are
   //required to hold result.
   predicted = GMP_INTS_mpz_size_in_base_10(&arg);

   printf("Predicting %d chars to hold value.\n", predicted);

   p = malloc(sizeof(char) * predicted * 2);

   printf("Formatting string.\n");

   GMP_INTS_mpz_to_string(p, &arg);

   printf("Done.  String is below.\n");

   FCMIOF_hline();

   printf("%s\n", p);

   FCMIOF_hline();

   actual = strlen(p);

   printf("Actual space consumption before commas: %d\n", actual+1);

   FCMIOF_hline();

   printf("Adding commas now ...");
   BSTRFUNC_commanate(p);
   printf("Done.  String is below.\n");
   FCMIOF_hline();

   FCMIOF_hline();

   printf("%s\n", p);

   FCMIOF_hline();

   actual = strlen(p);

   printf("Actual space consumption after commas: %d\n", actual+1);

   FCMIOF_hline();
   if ((actual+1) > predicted)
     rv = 1;

   free(p);

   //Deallocate integer space.
   GMP_INTS_mpz_clear(&old_arg);
   GMP_INTS_mpz_clear(&arg);
   GMP_INTS_mpz_clear(&k3);

   //FCMIOF_hline();

   return(rv);
   }


int GMP_long_int_format_to_stream_test(void)
   {
   int rv=0, j;
   GMP_INTS_mpz_struct i;

   printf("Testing GMP_long_int_format_to_stream() function.\n");
   FCMIOF_hline();

   //We need an integer to take through the paces to see what it does.
   //Let's start with 0, then go to 1, and keep alternating on both
   //sides of 0.  Must also test NAN cases.

   //Initialize (allocate space) for integer.
   GMP_INTS_mpz_init(&i);

   //Test how the error conditions are output.
   i.flags = GMP_INTS_EF_INTOVF_POS;
   GMP_INTS_mpz_long_int_format_to_stream(stdout, &i, "+ Overflow");
   FCMIOF_hline();
   i.flags = GMP_INTS_EF_INTOVF_NEG;
   GMP_INTS_mpz_long_int_format_to_stream(stdout, &i, "- Overflow");
   FCMIOF_hline();
   i.flags = GMP_INTS_EF_INTOVF_TAINT_POS;
   GMP_INTS_mpz_long_int_format_to_stream(stdout, &i, "+ Overflow");
   FCMIOF_hline();
   i.flags = GMP_INTS_EF_INTOVF_TAINT_NEG;
   GMP_INTS_mpz_long_int_format_to_stream(stdout, &i, "- Overflow");
   FCMIOF_hline();


   //Zero test.
   GMP_INTS_mpz_set_si(&i, 0);
   GMP_INTS_mpz_long_int_format_to_stream(stdout, &i, "Should Be 0");
   FCMIOF_hline();

   //Now, walk from -100 to 100.

   for (j=-100; j<=100; j++)
      {
      GMP_INTS_mpz_set_si(&i, j);
      GMP_INTS_mpz_long_int_format_to_stream(stdout, &i, "Should Be [-100,100]");
      FCMIOF_hline();
      }

   //Now, start with 1 and multiply by -371 repeatedly until about 500
   //digits.  500 digits is about 50 limbs.
   GMP_INTS_mpz_set_si(&i, 1);

   do 
      {
      GMP_INTS_mpz_long_int_format_to_stream(stdout, &i, "Longer Test");
      FCMIOF_hline();
      GMP_INTS_mpz_mul_si(&i, &i, -371);
      }
   while (i.size < 55);

   //Destroy the space.
   GMP_INTS_mpz_clear(&i);

   return(rv);
   }


int GINTTEST_mpz_fac_ui_test(void)
   {
   int rv=0;
   unsigned long j;
   GMP_INTS_mpz_struct i;

   printf("Testing GMP_INTS_mpz_fac_ui() function.\n");
   FCMIOF_hline();

   GMP_INTS_mpz_init(&i);

   j = 0;


   do 
      {
      printf("Calculating the factorial of %lu ... ", j);
      GMP_INTS_mpz_fac_ui(&i, j);
      printf("Done.\n");
      GMP_INTS_mpz_long_int_format_to_stream(stdout, &i, "Factorial");
      FCMIOF_hline();
      j++;
      }
   while (i.size < 55);

   //Destroy the space.
   GMP_INTS_mpz_clear(&i);

   return(rv);
   }


int GINTTEST_mpz_pow_ui_test(void)
   {
   int rv=0;
   int i;
   char *p;
   int chars_reqd;

   GMP_INTS_mpz_struct arb_base, arb_result;
  
   //These are the test vectors for testing exponentiation.
   struct 
      {
      char *base;
      unsigned exp;
      char *result;
      } tvs[] =
      {
         {
         "0",
          0,
         "1"
         },
         {
         "93274374615",
          0,
         "1"
         },
         {
         "2",
         32,
         "4294967296"
         },
         {
         "10",
         99,
         "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
         },
      };


   printf("Testing GMP_INTS_mpz_pow_ui() function.\n");
   FCMIOF_hline();

   //Allocate space for the base and result.
   GMP_INTS_mpz_init(&arb_base);
   GMP_INTS_mpz_init(&arb_result);

   for (i=0; i<sizeof(tvs)/sizeof(tvs[0]); i++)
      {
      //Assign the base to be the value in the test vectors.
      GMP_INTS_mpz_set_simple_char_str(&arb_base, tvs[i].base);

      //Calculate the exponential.
      GMP_INTS_mpz_pow_ui(&arb_result, &arb_base, tvs[i].exp);

      //Figure out how much string space will be required
      //for the result.
      chars_reqd = GMP_INTS_mpz_size_in_base_10(&arb_result);

      //Allocate the string space.
      p = malloc(chars_reqd * sizeof(char));

      //Convert from the arbitary integer to a string.
      GMP_INTS_mpz_to_string(p, &arb_result);

      //Compare the result of that conversion with the 
      //expected value.  If they are different, throw an error.
      if (strcmp(p, tvs[i].result))
         rv = 1;

      //Deallocate the string space.
      free(p);

      //If an error ...
      if (rv)
         break;
      }

   //Deallocate the variables.
   GMP_INTS_mpz_clear(&arb_base);
   GMP_INTS_mpz_clear(&arb_result);

   return(rv);
   }


int GINTTEST_main(void)
   {
   int rv;
   rv = 0;

   printf("Beginning unit testing of GMP_INTS module.\n");

   FCMIOF_hline();

   rv = GINTTEST_mpz_pow_ui_test();
   if (rv) return(rv);

   rv = GINTTEST_mpz_fac_ui_test();
   if (rv) return(rv);

   rv = GMP_long_int_format_to_stream_test();
   if (rv) return(rv);

   rv = GINTTEST_to_string_test();
   if (rv) return(rv);

   rv = GINTTEST_mpz_tdiv_qr_test();
   if (rv) return(rv);

   rv = GINTTEST_data_sizes_wrong_test();
   if (rv) return(rv);

   rv = GINTTEST_alloca_test();
   if (rv) return(rv);

   rv = GINTTEST_mpn_add_1_test();
   if (rv) return(rv);

   rv = GINTTEST_mpn_sub_1_test();
   if (rv) return(rv);

   rv = GINTTEST_mpn_mul_1_test();
   if (rv) return(rv);

   rv = GINTTEST_mpz_mul_test();
   if (rv) return(rv);

   rv = GINTTEST_mpz_add_test();
   if (rv) return(rv);

   rv = GINTTEST_mpz_set_simple_char_str_test();
   if (rv) return(rv);

   rv = GINTTEST_speed_tests();
   if (rv) return(rv);

   printf("Ending unit testing of GMP_INTS module.\n");

   FCMIOF_hline();

   return(rv);
   }


const char *GINTTEST_cvcinfo(void)
   {
   return("$Header: /cvsroot/esrg/sfesrg/esrgpcpj/unittest/ginttest.c,v 1.14 2002/05/16 04:21:50 dtashley Exp $");
   }


const char *GINTTEST_hvcinfo(void)
   {
   return(GINTTEST_H_VERSION);
   }


//**************************************************************************
// $Log: ginttest.c,v $
// Revision 1.14  2002/05/16 04:21:50  dtashley
// Substantial progress on unit test functionality.
//
// Revision 1.13  2001/07/25 23:40:02  dtashley
// Completion of INTFAC program, many changes to handling of large
// integers.
//
// Revision 1.12  2001/07/21 03:32:44  dtashley
// Addition of several files.
//
// Revision 1.11  2001/07/21 01:39:02  dtashley
// Safety check-in.  Major function to output an integer as rows of digits
// has been completed.  This was the last major function that needed to be
// completed before useful command-line utilities can be constructed.
//
// Revision 1.10  2001/07/19 20:06:05  dtashley
// Division finished.  String formatting functions underway.  Safety check-in.
//
// Revision 1.9  2001/07/18 21:53:10  dtashley
// Division function finished and passes preliminary tests.  Safety check-in.
//
// Revision 1.8  2001/07/17 22:30:15  dtashley
// Safety check-in.  Division function under construction.
//
// Revision 1.7  2001/07/16 17:46:48  dtashley
// Multiplication finished, and only indirectly unit-tested.  More detailed unit
// test must follow, but expect no problems.
//
// Revision 1.6  2001/07/16 00:28:22  dtashley
// Safety check-in.  Addition and subtraction functions finished.
//
// Revision 1.5  2001/07/14 07:03:41  dtashley
// Safety check-in.  Modifications and progress.
//
// Revision 1.4  2001/07/14 02:05:03  dtashley
// Safety check-in.  Almost ready for first unit-testing.
//
// Revision 1.3  2001/07/13 21:02:20  dtashley
// Version control reporting changes.
//
// Revision 1.2  2001/07/13 19:04:06  dtashley
// New files added, plus safety check-in.
//
// Revision 1.1  2001/07/13 18:17:18  dtashley
// Safety check-in.  Additionally, new files added.
//
//**************************************************************************
// End of GINTTEST.C.