//$Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/winprojs/scirfmmon/source/c_main.c,v 1.45 2009/01/17 19:16:15 dashley Exp $
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
//This file is part of scirfmmon.
//
//scirfmmon is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//scirfmmon is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with scirfmmon (see the file copying.txt).  If not, 
//see <http://www.gnu.org/licenses/>.
//--------------------------------------------------------------------------------

#define MODULE_C_MAIN

#include <signal.h>
#include <stdio.h>
#include <tchar.h>
#include <sys/timeb.h>
#include <time.h>
#include <windows.h>

#include "c_main.h"

#include "ccmfatal.h"
#include "charfunc.h"
#include "config_release.h"
#include "config_behavior.h"
#include "cw_threads.h"
#include "log.h"
#include "log_char.h"
#include "log_packet.h"
#include "log_pkt_int.h"
#include "log_sys_int.h"
#include "outsf.h"
#include "thread_test.h"
#include "timefunc.h"
#include "vcinfo.h"


static volatile LONG ctrl_c_pressed = 0;
   //Set TRUE if CTRL-C is used.  volatile because Win32 spawns a thread on SIGINT.

//Signal function called if CTRL-C is used.
//
void sigfunc_SIGINT(int n)
   {
   ctrl_c_pressed = 1;
   }


//Parses a communication port name to see if it is sane.  Returns TRUE if sane, FALSE
//otherwise.
//
static int MAIN_C_comport_arg_parse(const wchar_t *s)
   {
   char buf[100];
   size_t i;

   if (wcslen(s) > 6)
      {
      //String too long.
      return(FALSE);
      }
   else if (wcslen(s) < 3)
      {
      //String too short.
      return(FALSE);
      }
   else
      {
      //Convert to a "normal" string for analysis.  There is probably a function for this,
      //but sprintf() should work quick and dirty.
      sprintf_s(buf, sizeof(buf), "%S", s);

      if ((strlen(buf) > 6) || (strlen(buf) < 3))
          return(FALSE);

      //The first three characters must be "COM" or similar.
      if ((buf[0] != 'C') && (buf[0] != 'c'))
          return(FALSE);
      if ((buf[1] != 'O') && (buf[1] != 'o'))
          return(FALSE);
      if ((buf[2] != 'M') && (buf[2] != 'm'))
          return(FALSE);

      //Any remaining characters must be digits.
      for (i=3; i<strlen(buf); i++)
         {
         if (!CHARFUNC_is_digit(buf[i]))
             return(FALSE);
         }

      //If we made it here, looks sane.
      return(TRUE);
      }
}


//Parses a Boolean argument to see if it is sane.  Returns 1 if true, 0 if false, or -1 if error.
//TRUE can be indicated by 1, Y, y, T, or t.  FALSE can be indicated by 0, N, n, F, or f.
//
static int MAIN_C_bool_arg_parse(const wchar_t *s)
   {
   char buf[100];

   if (wcslen(s) > 1)
      {
      //String too long.
      return(-1);
      }
   else if (wcslen(s) < 1)
      {
      //String too short.
      return(-1);
      }
   else
      {
      //Convert to a "normal" string for analysis.  There is probably a function for this,
      //but sprintf() should work quick and dirty.
      sprintf_s(buf, sizeof(buf), "%S", s);

      if ((strlen(buf) > 1) || (strlen(buf) < 1))
          return(-1);

      //Check for FALSE, TRUE, etc.
      if ((buf[0] == '0') || (buf[0] == 'N') || (buf[0] == 'n') || (buf[0] == 'F') || (buf[0] == 'f'))
          return(0);
      else if ((buf[0] == '1') || (buf[0] == 'Y') || (buf[0] == 'y') || (buf[0] == 'T') || (buf[0] == 't'))
          return(1);
      else
          return(-1);
      }
   }



//Inpsects a received TSE and flags it if there is something
//amiss.
//
static void C_MAIN_tse_inspect_and_flag(const QCHAR_TSE *ev)
   {
   char bufmsg[200];
   char buflog[200];

   if (ev->ev == QCHAR_EV_CHAR)
      {
	  //This is the normal case.  Do exactly nothing.
	  }
   else if ((ev->ev < 0) || (ev->ev >= QCHAR_EV_MAX))
      {
	  //The event is wrong.  This indicates an internal software error and is fatal.
     sprintf_s(buflog, sizeof(buflog), "Bad event enum, ch: %d, value: %d.  Exiting.", ev->channel, ev->ev);
     LOG_write_ls(&(ev->ts), 
                  LOG_MT_ALERT, 
                  LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                  buflog);
      C_MAIN_pthrd_error_nonspecific = TRUE;
      }
   else
      {
	   //The event is a reportable serial communication error or anomaly.
      //
      //First decide what it is.
      switch(ev->ev)
         {
         case QCHAR_EV_BREAK:
            sprintf_s(bufmsg, sizeof(bufmsg), "Serial BREAK detected, ");
            break;
         case QCHAR_EV_FRAME:
            sprintf_s(bufmsg, sizeof(bufmsg), "Serial framing error detected, ");
            break;
         case QCHAR_EV_OVERRUN:
            sprintf_s(bufmsg, sizeof(bufmsg), "Serial overrun error detected, ");
            break;
         case QCHAR_EV_RXOVER:
            sprintf_s(bufmsg, sizeof(bufmsg), "Serial receive overrun error detected, ");
            break;
         case QCHAR_EV_RXPARITY:
            sprintf_s(bufmsg, sizeof(bufmsg), "Serial parity error detected, ");
            break;
         default:
            sprintf_s(bufmsg, sizeof(bufmsg), "Serious fatal internal software error detected, ");
            C_MAIN_pthrd_error_nonspecific = TRUE;
            break;
         }

      //Tack on the rest of the message.
      sprintf_s(buflog, sizeof(buflog), "%sch %d.", bufmsg, ev->channel);

      //Emit it.
      LOG_write_ls(&(ev->ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                   buflog);
      }
   }

//Initializes a DCB per desired settings.
//
static void C_MAIN_dcb_config(DCB *out_arg)
   {
   BOOL rv;
   size_t n_converted;
   errno_t ecode;
   wchar_t wbuf[150];

   //Be sure nothing funky happens (although function documentation says will always
   //have terminator on string).
   wbuf[0] = 0;

   //Convert the nominal string to the wide character version.
   ecode = mbstowcs_s(&n_converted, wbuf, sizeof(wbuf)/sizeof(wbuf[0]), CFG_BHV_COMM_SETTINGS, 100);
   if (ecode)
      {
      CCMFATAL_fatal("Failure code from mbstowcs_s().",
                    __FILE__,
                    __LINE__);
      }

   //Zero out the DCB and assign its size appropriately.  This was copied from the recommendations
   //in a Microsoft application note.
   FillMemory(out_arg, sizeof(DCB), 0);
   out_arg->DCBlength = sizeof(DCB);

   rv = BuildCommDCB(wbuf, out_arg);
   if (!rv)
      {
      //In this case really have no alternative but to declare a fatal error.
      CCMFATAL_fatal("Failure code from BuildCommDCB().",
                    __FILE__,
                    __LINE__);
      }

   //Be sure that the "Abort On Error" field is set.
   out_arg->fAbortOnError = TRUE;
   }


int c_main(int argc, _TCHAR* argv[])
   {
   int return_value = 0;
      //Default return is no error.
   errno_t errno_return;
      //Return value from functions that return errno_t.
   int main_loop_exit_flag = FALSE;
      //TRUE if should exit the main loop.
   int main_loop_first_time = TRUE;
      //TRUE if first time through main loop.
   int must_close_com0 = FALSE;
   int must_close_com1 = FALSE;
      //TRUE if must close this port (meaning had successfully opened it).
   int may_restore_com0_state = FALSE;
   int may_restore_com1_state = FALSE;
      //TRUE if state from port has been retrieved and is available to store back
      //at program termination.
   int must_end_thread0 = FALSE;
   int must_end_thread1 = FALSE;
      //TRUE if must end communication worker threads.
   int con_write_char_log = FALSE;
   int con_write_packet_log = TRUE;
   int con_write_packet_interaction_log = TRUE;
   int con_write_system_interaction_log = TRUE;
      //This program should ideally process keystrokes and modify its behavior, i.e.
      //give the user the ability to dynamically adjust what gets sent to the console.
      //However, my single attempt to do this didn't go as planned.  The variables above
      //are placeholders for the possibility that this will be added.  First one is whether
      //the character log should be mirrored to the console, the second one is
      //whether the packet log should be mirrored, third one is whether the packet
      //interaction log should be mirrored, and the fourth one is whether the system
      //interaction log should be mirrored.

   //Be sure the queues are zero'd.  I think C guarantees they are, but need to check.  These statement
   //can probably be removed after this is verified.
   FillMemory(&C_MAIN_tsceq0, sizeof(C_MAIN_tsceq0), 0);
   FillMemory(&C_MAIN_tsceq1, sizeof(C_MAIN_tsceq1), 0);
   FillMemory(&C_MAIN_ptceq0, sizeof(C_MAIN_ptceq0), 0);
   FillMemory(&C_MAIN_ptceq1, sizeof(C_MAIN_ptceq1), 0);
   FillMemory(&C_MAIN_cceq0_charlog, sizeof(C_MAIN_cceq0_charlog), 0);
   FillMemory(&C_MAIN_cceq1_charlog, sizeof(C_MAIN_cceq1_charlog), 0);
   FillMemory(&C_MAIN_cceq0_packetparselog, sizeof(C_MAIN_cceq0_packetparselog), 0);
   FillMemory(&C_MAIN_cceq1_packetparselog, sizeof(C_MAIN_cceq1_packetparselog), 0);

   signal(SIGINT, sigfunc_SIGINT);
      //Set up so that if CTRL-C is used, the passed function is called.
      //The function is called asynchronously in its own thread.

   //Form the self identity string.
   {
   char self_id_string[100];     //String identifying software, including VC hash.
   VCINFO_SIGNATURE vcinfo_sig;

   VCINFO_signature(&vcinfo_sig);

   sprintf_s(self_id_string, sizeof(self_id_string), 
           #ifdef NDEBUG   //If assertions enabled, capital "A" else lower-case "a".
              "%s, v%d.%d%c (%s, a, %s)",
           #else
              "%s, v%d.%d%c (%s, A, %s)",
           #endif
           CONFIG_RELEASE_PRODUCT_NAME, 
	       CONFIG_RELEASE_VERSION_MAJOR, 
		   CONFIG_RELEASE_VERSION_MINOR, 
	       CHARFUNC_int_to_lower(CONFIG_RELEASE_VERSION_SUFFIX_ALPHA),
		   __DATE__,
           vcinfo_sig.sig);

   //Get the current time.
   errno_return = _ftime64_s(&C_MAIN_time_current);
   if (errno_return)
      CCMFATAL_fatal("Failure code from _ftime64_s().",
                    __FILE__,
                    __LINE__);

   //Try to open up the log files.
   LOG_open(&C_MAIN_time_current, self_id_string);
   }

   //Write the first line to the console and all log files.
   {
   char buf[200];
   TIMEFUNC_TIME_ASCII_RESULT ts;

   TIMEFUNC_to_ascii_hr_form(&C_MAIN_time_current, &ts);
   strcpy_s(buf, sizeof(buf), "Execution begins on ");
   strcat_s(buf, sizeof(buf), ts.result);
   strcat_s(buf, sizeof(buf), ".");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, buf);
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "This application is multi-threaded (two threads to handle");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "incoming received characters and one primary thread).  Each");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "thread maintains time separately, so there can be a slight ");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "discrepancy in timestamps.  The primary thread processes");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "characters that were timestamped as they were queued by the");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "two serial communication worker threads.  Timestamps issued");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "by the primary thread as it processes characters will thus");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "be later than the timestamps of the characters it is");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, 
	            "processing.");

   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_STDOUT | LOG_LI_COMP, 
	            "");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_STDOUT | LOG_LI_COMP, 
	            "Use CONTROL-C to terminate this program.");
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_STDOUT | LOG_LI_COMP, 
	            "");
   }

   main_loop_exit_flag = FALSE;

   while (! main_loop_exit_flag)
      {
	  //********************************************************************************
	  //********************************************************************************
	  //*****  T I M E    S N A P S H O T  *********************************************
	  //********************************************************************************
	  //********************************************************************************
      //Snapshot the current time.
      errno_return = _ftime64_s(&C_MAIN_time_current);

	  //Crap out if can't get the time.
	  if (errno_return)
         CCMFATAL_fatal("Failure code from _ftime64_s().",
                        __FILE__,
                        __LINE__);


      //********************************************************************************
	  //********************************************************************************
	  //*****  F I R S T    T I M E    A C T I V I T Y  ********************************
	  //********************************************************************************
	  //********************************************************************************
      //This portion of the loop handles the activities that should happen once only,
      //first time through.  They generally also could have been placed outside the
      //loop, but easier to have them occur after the logs are started up.
      //
      if (main_loop_first_time)
         {
         //================================================================================
         //=====  N U M B E R    O F    P A R A M E T E R S  ==============================
         //================================================================================
         if ((! main_loop_exit_flag) && (argc != 5))
            {
            char buf_n[100];

            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "This program must be invoked as");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");
		      sprintf_s(buf_n, sizeof(buf_n), "   \"%s PORT0 PORT1 CHARLOGTOCON PACKETLOGTOCON\",", CONFIG_RELEASE_PRODUCT_NAME);
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         buf_n);
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "where \"PORT0\" is the name of the serial port capturing data");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "from the host microcontroller to the RF daughterboard,");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "\"PORT1\" is the name of the serial port capturing data from");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "the RF daughterboard to the host microcontroller,");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "\"CHARLOGTOCON\" is Y/N to indicate whether the character");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "log should be duplicated to the console, and \"PACKETLOGTOCON\"");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "is Y/N to indicate whether the packet log should be");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "duplicated to the console.");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "\"COM3\" is a typical name for a communication port.  In");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "Windows, the names of serial ports can typically be found");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "under Control Panel->System->Device Manager->Ports.");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "Exiting.");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");

            main_loop_exit_flag = TRUE;

            //printf("Exiting clause.\n");
            }
         //================================================================================
         //=====  F I R S T    P A R A M E T E R    P A R S E  ============================
         //================================================================================
         if ((! main_loop_exit_flag) && (!MAIN_C_comport_arg_parse(argv[1])))
            {
            char buf_n[100];

		      sprintf_s(buf_n, sizeof(buf_n), "The first communication port specified (%S) appears", argv[1]);
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         buf_n);
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "to be invalid.  Only ports of the form \"COMn\" may be");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "specified.");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "Exiting.");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");

            main_loop_exit_flag = TRUE;
            }
         //================================================================================
         //=====  S E C O N D    P A R A M E T E R    P A R S E  ==========================
         //================================================================================
         if ((! main_loop_exit_flag) && (!MAIN_C_comport_arg_parse(argv[2])))
            {
            char buf_n[100];

		      sprintf_s(buf_n, sizeof(buf_n), "The second communication port specified (%S) appears", argv[2]);
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         buf_n);
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "to be invalid.  Only ports of the form \"COMn\" may be");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "specified.");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "Exiting.");
            LOG_write_ls(&C_MAIN_time_current, 
                         LOG_MT_ALERT, 
                         LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                         "");

            main_loop_exit_flag = TRUE;
            }
         //================================================================================
         //=====  T H I R D    P A R A M E T E R    P A R S E  ============================
         //================================================================================
         if (! main_loop_exit_flag)
            {
            if (MAIN_C_bool_arg_parse(argv[3]) < 0)
               {
               char buf_n[100];

	   	      sprintf_s(buf_n, sizeof(buf_n), "The CHARLOGTOCON parameter (%S) appears", argv[3]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                           buf_n);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "to be invalid.");
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "");
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "Exiting.");
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "");

               main_loop_exit_flag = TRUE;
               }
            else
               {
               con_write_char_log = MAIN_C_bool_arg_parse(argv[3]);
               }
            }
         //================================================================================
         //=====  F O U R T H    P A R A M E T E R    P A R S E  ==========================
         //================================================================================
         if (! main_loop_exit_flag)
            {
            if (MAIN_C_bool_arg_parse(argv[4]) < 0)
               {
               char buf_n[100];

   		      sprintf_s(buf_n, sizeof(buf_n), "The PACKETLOGTOCON parameter (%S) appears", argv[4]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "to be invalid.");
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "");
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "Exiting.");
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "");

               main_loop_exit_flag = TRUE;
               }
            else
               {
               con_write_packet_log = MAIN_C_bool_arg_parse(argv[4]);
               }
            }
         //================================================================================
         //=====  F I R S T    C O M    P O R T    O P E N  ===============================
         //================================================================================
         if (! main_loop_exit_flag)
            {
            size_t n_converted;
            wchar_t namebuf[50];

            //Start with the \\.\ sequence (required to handle COM port numbers of 10 or
            //larger.
            mbstowcs_s(&n_converted, namebuf, sizeof(namebuf)/sizeof(namebuf[0]), "\\\\.\\", 10);

            //Tack on the parameter specified by the user as the COM port name.
            wcscat_s(namebuf, sizeof(namebuf)/sizeof(namebuf[0]), argv[1]);

            //Try to open the port.
            C_MAIN_hCommPort0 = CreateFile(namebuf,
		                                   GENERIC_READ | GENERIC_WRITE,
						                   0,
						                   0,
						                   OPEN_EXISTING,
						                   0,
						                   0);

            if (C_MAIN_hCommPort0 == INVALID_HANDLE_VALUE)
               {
               char buf_n[100];

		       sprintf_s(buf_n, sizeof(buf_n), "Failed to open \"%S\".  Exiting.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "");

               main_loop_exit_flag = TRUE;
               }
            else
               {
               char buf_n[100];

		       sprintf_s(buf_n, sizeof(buf_n), "\"%S\" opened successfully.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);

               must_close_com0 = TRUE;
               }
            }
         //================================================================================
         //=====  S E C O N D    C O M    P O R T    O P E N  =============================
         //================================================================================
         if (! main_loop_exit_flag)
            {
            size_t n_converted;
            wchar_t namebuf[50];

            //Start with the \\.\ sequence (required to handle COM port numbers of 10 or
            //larger.
            mbstowcs_s(&n_converted, namebuf, sizeof(namebuf)/sizeof(namebuf[0]), "\\\\.\\", 10);

            //Tack on the parameter specified by the user as the COM port name.
            wcscat_s(namebuf, sizeof(namebuf)/sizeof(namebuf[0]), argv[2]);

            //Try to open the port.
            C_MAIN_hCommPort1 = CreateFile(namebuf,
		                                   GENERIC_READ | GENERIC_WRITE,
						                   0,
						                   0,
						                   OPEN_EXISTING,
						                   0,
						                   0);

            if (C_MAIN_hCommPort1 == INVALID_HANDLE_VALUE)
               {
               char buf_n[100];

		       sprintf_s(buf_n, sizeof(buf_n), "Failed to open \"%S\".  Exiting.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            "");

               main_loop_exit_flag = TRUE;
               }
            else
               {
               char buf_n[100];

		       sprintf_s(buf_n, sizeof(buf_n), "\"%S\" opened successfully.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);

               must_close_com1 = TRUE;
               }
            }
         //================================================================================
         //=====  F I R S T    C O M M    P O R T    S T A T E    R E T R I E V A L  ======
         //================================================================================
         if (! main_loop_exit_flag)
            {
            BOOL rv;
            char buf_n[100];

            rv = GetCommState(C_MAIN_hCommPort0, &C_MAIN_CommPort0SavedState);
            if (rv)
               {
		       sprintf_s(buf_n, sizeof(buf_n), "\"%S\" state retrieval successful.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);

               may_restore_com0_state = TRUE;
               }
            else
               {
		       sprintf_s(buf_n, sizeof(buf_n), "Failed to retrieve \"%S\" state.  Exiting.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);

               main_loop_exit_flag = TRUE;
               }
            }
         //================================================================================
         //=====  S E C O N D    C O M M    P O R T    S T A T E    R E T R I E V A L  ====
         //================================================================================
         if (! main_loop_exit_flag)
            {
            BOOL rv;
            char buf_n[100];

            rv = GetCommState(C_MAIN_hCommPort1, &C_MAIN_CommPort1SavedState);
            if (rv)
               {
		       sprintf_s(buf_n, sizeof(buf_n), "\"%S\" state retrieval successful.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);

               may_restore_com1_state = TRUE;
               }
            else
               {
		       sprintf_s(buf_n, sizeof(buf_n), "Failed to retrieve \"%S\" state.  Exiting.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);

               main_loop_exit_flag = TRUE;
               }
            }
         //================================================================================
         //=====  F I R S T    C O M M    P O R T    S E T U P  ===========================
         //================================================================================
         if (! main_loop_exit_flag)
            {
            BOOL rv;
            DCB dcb_scratch;
            char buf_n[100];

            C_MAIN_dcb_config(&dcb_scratch);

            rv = SetCommState(C_MAIN_hCommPort0, &dcb_scratch);

            if (rv)
               {
	           sprintf_s(buf_n, sizeof(buf_n), "\"%S\" setup successful.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);
               }
            else
               {
	           sprintf_s(buf_n, sizeof(buf_n), "Failed to set up \"%S\".  Exiting.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);

               main_loop_exit_flag = TRUE;
               }
            }
         //================================================================================
         //=====  S E C O N D    C O M M    P O R T    S E T U P  =========================
         //================================================================================
         if (! main_loop_exit_flag)
            {
            BOOL rv;
            DCB dcb_scratch;
            char buf_n[100];

            C_MAIN_dcb_config(&dcb_scratch);

            rv = SetCommState(C_MAIN_hCommPort1, &dcb_scratch);

            if (rv)
               {
	           sprintf_s(buf_n, sizeof(buf_n), "\"%S\" setup successful.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);
               }
            else
               {
	           sprintf_s(buf_n, sizeof(buf_n), "Failed to set up \"%S\".  Exiting.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);

               main_loop_exit_flag = TRUE;
               }
            }
         //================================================================================
         //=====  F I R S T    C O M M    P O R T    T I M E O U T S    S E T U P  ========
         //================================================================================
         if (! main_loop_exit_flag)
            {
            BOOL rv;
            char buf_n[100];
            COMMTIMEOUTS to;

            //Zero out the data structure, just in case the definition changes later, to
            //get consistent results.
            FillMemory(&to, sizeof(to), 0);

            //Assign the values.
            to.ReadIntervalTimeout           = CFG_BHV_COMM_TO_READ_INTERVAL_TO;
            to.ReadTotalTimeoutMultiplier    = CFG_BHV_COMM_TO_READ_TOTAL_TO_MULTIPLIER;
            to.ReadTotalTimeoutConstant      = CFG_BHV_COMM_TO_READ_TOTAL_TO_CONSTANT;
            to.WriteTotalTimeoutMultiplier   = CFG_BHV_COMM_TO_WRITE_TOTAL_TO_MULTIPLIER;
            to.WriteTotalTimeoutConstant     = CFG_BHV_COMM_TO_WRITE_TOTAL_TO_CONSTANT;

            //Do the deed.
            rv = SetCommTimeouts(C_MAIN_hCommPort0, &to);

            //Process the result code.
            if (rv)
               {
	           sprintf_s(buf_n, sizeof(buf_n), "\"%S\" communication timeout setup successful.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);
               }
            else
               {
	           sprintf_s(buf_n, sizeof(buf_n), "Failed to set up \"%S\" communication timeouts.  Exiting.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);

               main_loop_exit_flag = TRUE;
               }
            }
         //================================================================================
         //=====  S E C O N D    C O M M    P O R T    T I M E O U T S    S E T U P  ======
         //================================================================================
         if (! main_loop_exit_flag)
            {
            BOOL rv;
            char buf_n[100];
            COMMTIMEOUTS to;

            //Zero out the data structure, just in case the definition changes later, to
            //get consistent results.
            FillMemory(&to, sizeof(to), 0);

            //Assign the values.
            to.ReadIntervalTimeout           = CFG_BHV_COMM_TO_READ_INTERVAL_TO;
            to.ReadTotalTimeoutMultiplier    = CFG_BHV_COMM_TO_READ_TOTAL_TO_MULTIPLIER;
            to.ReadTotalTimeoutConstant      = CFG_BHV_COMM_TO_READ_TOTAL_TO_CONSTANT;
            to.WriteTotalTimeoutMultiplier   = CFG_BHV_COMM_TO_WRITE_TOTAL_TO_MULTIPLIER;
            to.WriteTotalTimeoutConstant     = CFG_BHV_COMM_TO_WRITE_TOTAL_TO_CONSTANT;

            //Do the deed.
            rv = SetCommTimeouts(C_MAIN_hCommPort1, &to);

            //Process the result code.
            if (rv)
               {
	           sprintf_s(buf_n, sizeof(buf_n), "\"%S\" communication timeout setup successful.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);
               }
            else
               {
	           sprintf_s(buf_n, sizeof(buf_n), "Failed to set up \"%S\" communication timeouts.  Exiting.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);

               main_loop_exit_flag = TRUE;
               }
            }
         //================================================================================
         //=====  F I R S T    C O M M    P O R T    C O M M    M A S K    S E T U P  =====
         //================================================================================
         if (! main_loop_exit_flag)
            {
            BOOL rv;
            char buf_n[100];

            //Do the deed.
            rv = SetCommMask(C_MAIN_hCommPort0, 0);

            //Process the result code.
            if (rv)
               {
	           sprintf_s(buf_n, sizeof(buf_n), "\"%S\" communication comm mask setup successful.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);
               }
            else
               {
	           sprintf_s(buf_n, sizeof(buf_n), "Failed to set up \"%S\" comm mask.  Exiting.", argv[1]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);

               main_loop_exit_flag = TRUE;
               }
            }
         //================================================================================
         //=====  S E C O N D    C O M M    P O R T    C O M M    M A S K    S E T U P  ===
         //================================================================================
         if (! main_loop_exit_flag)
            {
            BOOL rv;
            char buf_n[100];

            //Do the deed.
            rv = SetCommMask(C_MAIN_hCommPort1, 0);

            //Process the result code.
            if (rv)
               {
	           sprintf_s(buf_n, sizeof(buf_n), "\"%S\" communication comm mask setup successful.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            buf_n);
               }
            else
               {
	           sprintf_s(buf_n, sizeof(buf_n), "Failed to set up \"%S\" comm mask.  Exiting.", argv[2]);
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                            buf_n);

               main_loop_exit_flag = TRUE;
               }
            }
         //================================================================================
         //=====  F I R S T    C O M M    W O R K E R    T H R E A D    S T A R T  ========
         //================================================================================
         if (! main_loop_exit_flag)
            {
            C_MAIN_hCwThread0 = CreateThread(
                                             NULL,
                                             0,
                                             CW_THREADS_Cw0,
                                             (LPVOID)0,
                                             0,
                                             &C_MAIN_dwCwThread0Id);
            if (C_MAIN_hCwThread0 != NULL)
               {
               //Success
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            "Communication worker thread 0 started successfully.");
               must_end_thread0 = TRUE;
               }
            else
               {
               //Failure
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            "Failure starting communication worker thread 0.  Exiting");
               }
            }
         //================================================================================
         //=====  S E C O N D    C O M M    W O R K E R    T H R E A D    S T A R T  ======
         //================================================================================
         if (! main_loop_exit_flag)
            {
            C_MAIN_hCwThread1 = CreateThread(
                                             NULL,
                                             0,
                                             CW_THREADS_Cw1,
                                             (LPVOID)0,
                                             0,
                                             &C_MAIN_dwCwThread1Id);
            if (C_MAIN_hCwThread1 != NULL)
               {
               //Success
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            "Communication worker thread 1 started successfully.");
               must_end_thread1 = TRUE;
               }
            else
               {
               //Failure
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_ALERT, 
                            LOG_LI_STDOUT | LOG_LI_COMP, 
                            "Failure starting communication worker thread 1.  Exiting");
               }
            }
         //================================================================================
         //================================================================================
         main_loop_first_time = FALSE;
         }
         //================================================================================
         //================================================================================

	  //********************************************************************************
	  //********************************************************************************
	  //*****  T R A N S F E R    T O    P T C E Q  ************************************
	  //********************************************************************************
	  //********************************************************************************
	  //The transfer out of the TSCEQs has to be coordinated with the worker threads,
	  //hence the use of the semaphore variables.  Without coordination, bizarre
	  //effects could result with interleaving of access.
	  //
      if (! main_loop_exit_flag)
         {
         //printf("Transfer to PTCEQ.\n");
         if (C_MAIN_TsQueueSyncSemaphore0 != 0) //Belongs to primary thread.
            {
            QCHAR_tsceq_ptceq_transfer(&C_MAIN_tsceq0, &C_MAIN_ptceq0);
            C_MAIN_TsQueueSyncSemaphore0 = 0;  //Belongs to worker thread.
            }
         if (C_MAIN_TsQueueSyncSemaphore1 != 0) //Belongs to primary thread.
            {
            QCHAR_tsceq_ptceq_transfer(&C_MAIN_tsceq1, &C_MAIN_ptceq1);
            C_MAIN_TsQueueSyncSemaphore1 = 0;  //Belongs to worker thread.
            }
         }
      //
	   //********************************************************************************
	   //********************************************************************************
	   //*****  E V E N T    F A N O U T  ***********************************************
	   //********************************************************************************
	   //********************************************************************************
      //The incoming events from the communication channels need to be fanned out.
	   //This involves propagating the events to multiple queues.
	   //
	   //This is also a good time to flag any errors related to flag any non-fatal
	   //errors related to serial communication that might otherwise be missed.
      if (! main_loop_exit_flag)
         {
         QCHAR_TSE tse;

         //printf("Event fanout.\n");

         //Fan out the Channel 0 events.
         while(QCHAR_ptceq_nelem(&C_MAIN_ptceq0))
	         {
	         QCHAR_ptceq_get(&C_MAIN_ptceq0, &tse);
            C_MAIN_tse_inspect_and_flag(&tse);
            QCHAR_cceq_put(&C_MAIN_cceq0_charlog, &tse);
		      QCHAR_cceq_put(&C_MAIN_cceq0_packetparselog, &tse);
	         }

         //Fan out the Channel 1 events.
	      while(QCHAR_ptceq_nelem(&C_MAIN_ptceq1))
	         {
	         QCHAR_ptceq_get(&C_MAIN_ptceq1, &tse);
            C_MAIN_tse_inspect_and_flag(&tse);
		      QCHAR_cceq_put(&C_MAIN_cceq1_charlog, &tse);
		      QCHAR_cceq_put(&C_MAIN_cceq1_packetparselog, &tse);
	         }

         //printf("%d %d %d %d\n", 
         //       QCHAR_cceq_nelem(&C_MAIN_cceq0_charlog),
         //       QCHAR_cceq_nelem(&C_MAIN_cceq0_packetparselog),
         //       QCHAR_cceq_nelem(&C_MAIN_cceq1_charlog),
         //       QCHAR_cceq_nelem(&C_MAIN_cceq1_packetparselog));
         }

      //********************************************************************************
      //********************************************************************************
      //*****  C H A R A C T E R    L O G G I N G  *************************************
      //********************************************************************************
      //********************************************************************************
      //Form the log at the character level.  It is the callee's responsibility to
      //consume the queues.
      //
      if (! main_loop_exit_flag)
         {
         //printf("Character logging.\n");
         LOG_CHAR_advance(&C_MAIN_cceq0_charlog, 
                          &C_MAIN_cceq1_charlog,  
                          &C_MAIN_time_current, 
                          con_write_char_log);
         }
      //
      //********************************************************************************
      //********************************************************************************
      //*****  P A C K E T    P A R S I N G    A N D   L O G G I N G  ******************
      //********************************************************************************
      //********************************************************************************
      //Form the log at the character level.  It is the callee's responsibility to
      //consume the queues.
      //
      if (! main_loop_exit_flag)
         {
         //printf("Packet logging.\n");
         LOG_PACKET_advance(&C_MAIN_cceq0_packetparselog, 
                            &C_MAIN_cceq1_packetparselog,  
                            &C_MAIN_time_current, 
                            con_write_packet_log);
         }
      //
      //**********************************************************************************************
      //**********************************************************************************************
      //*****  P A C K E T    I N T E R A C T I O N    A N A L Y S I S   A N D    L O G G I N G  *****
      //**********************************************************************************************
      //**********************************************************************************************
      //Form the log at the character level.  It is the callee's responsibility to
      //consume the queues.
      //
      //TBD.
      //
      //********************************************************************************
      //********************************************************************************
      //*****  A L I V E N E S S    L O G G I N G  *************************************
      //********************************************************************************
      //********************************************************************************
      if (! main_loop_exit_flag)
         {
         //printf("Aliveness logging.\n");
         #if (CFG_BHV_LIVENESS_ANNOUNCE_MOD_TIME > 0)
            {
            static int state_n = 0;
	         //Small state machine so that only print the liveness announcement
	         //once each time the modulo time test is met.  Otherwise, would
	         //print repeatedly for entire second.
	         char buf_n[100];

	         switch(state_n)
	            {
	            default:
	            case 0:
  	               if ((C_MAIN_time_current.time % CFG_BHV_LIVENESS_ANNOUNCE_MOD_TIME) > (CFG_BHV_LIVENESS_ANNOUNCE_MOD_TIME / 2))
			         state_n = 1;
			         break;
		         case 1:
	               if ((C_MAIN_time_current.time % CFG_BHV_LIVENESS_ANNOUNCE_MOD_TIME) <= (CFG_BHV_LIVENESS_ANNOUNCE_MOD_TIME / 2))
		               {
		               sprintf_s(buf_n, sizeof(buf_n), "%s primary thread alive.", CONFIG_RELEASE_PRODUCT_NAME);
                     LOG_write_ls(&C_MAIN_time_current, LOG_MT_ROUTINE, LOG_LI_ALL, 
	                               buf_n);
			            state_n = 2;
			            }
			         break;
		         case 2:
  	               if ((C_MAIN_time_current.time % CFG_BHV_LIVENESS_ANNOUNCE_MOD_TIME) > (CFG_BHV_LIVENESS_ANNOUNCE_MOD_TIME / 2))
			            state_n = 1;
			         break;
	               }
	            }
         #endif
         }

      //********************************************************************************
      //********************************************************************************
      //*****  L O G    F I L E    F L U S H I N G  ************************************
      //********************************************************************************
      //********************************************************************************
      //This ensures that opening the logs concurrently with a text editor will work
      //OK.
      if (! main_loop_exit_flag) 
         {
         static __time64_t tref = 0;
         __time64_t tcmp;

         tcmp = _time64(NULL);

         if ((tcmp - tref) > C_MAIN_FILE_FLUSH_INTERVAL_S)
            {
            //printf("Log file flush.\n");
            LOG_flush();
            tref = tcmp;
            }
         }

	  //********************************************************************************
	  //********************************************************************************
	  //*****  S L A C K  **************************************************************
	  //********************************************************************************
	  //********************************************************************************
      //The rationale for slack is to make the PC overall more responsive in case the
      //user is running multiple applications.  The queues that by default are set up
      //under direct control of the worker threads can handle on the order of 10
      //seconds of data.  The slack won't cause lost data.  Because the queues are
      //so large, lost data won't occur until the average rate of data input exceeds
      //the average rate at which it can be processed.
      //printf("Slack.\n");
      Sleep(C_MAIN_SLACK_TIME_MS);
      //
      //********************************************************************************
	  //********************************************************************************
	  //*****  L O O P    E X I T    C R I T E R I A  **********************************
	  //********************************************************************************
	  //********************************************************************************
     //printf("Loop exit criteria.\n");
	  if (   ctrl_c_pressed 
		  || C_MAIN_queue_overflow 
		  || C_MAIN_overrun_hw_rx
		  || C_MAIN_pthrd_error_nonspecific
		  || C_MAIN_wthrd_error_nonspecific
		  )
	     {
         if (ctrl_c_pressed)
            {
            main_loop_exit_flag = TRUE;
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, "CTRL-C pressed.  Exiting.");
            }
         if (C_MAIN_queue_overflow)
            {
            main_loop_exit_flag = TRUE;
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_ALL, "Queue overflow (lost data).  Exiting.");
            }
		   if (C_MAIN_overrun_hw_rx)
		      {
            main_loop_exit_flag = TRUE;
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_ALL, "Hardware communication buffers have been overrun.  Exiting.");
		      }
         if (C_MAIN_pthrd_error_nonspecific)
            {
            main_loop_exit_flag = TRUE;
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_ALL, "Nonspecific error from primary thread.  Exiting.");
            }
         if (C_MAIN_wthrd_error_nonspecific)
            {
            main_loop_exit_flag = TRUE;
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_ALL, "Nonspecific error from worker thread(s).  Exiting.");
            }
	     }
      }

   //================================================================================
   //=====  T I M E    S N A P S H O T  =============================================
   //================================================================================
   //printf("Time snapshot.\n");
   errno_return = _ftime64_s(&C_MAIN_time_current);
   if (errno_return)
      CCMFATAL_fatal("Failure code from _ftime64_s().",
                    __FILE__,
                    __LINE__);

   //================================================================================
   //=====  T H R E A D    0    T E R M I N A T I O N  ==============================
   //================================================================================
   //Try to end the first communication worker thread if we are so required.
   //printf("Thread 0 termination.\n");
   if (must_end_thread0)
      {
      int i = 50;
      int killed_gracefully = FALSE;
      int status_query_error = FALSE;
      BOOL rv;
      DWORD exit_code;

      C_MAIN_SigTermCwThread0 = TRUE;

      while((i--) && (!killed_gracefully) && (!status_query_error))
         {
         Sleep(100);
         rv = GetExitCodeThread(C_MAIN_hCwThread0, &exit_code);
         if (!rv)
            {
            //Failure on the function call.
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                         "Error determining status of worker thread 0.  Cannot terminate thread.");
            }
         else
            {
            //Success on the function call.
            if (exit_code == STILL_ACTIVE)
               {
               //Can't do anything.  Thread still going.
               }
            else
               {
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                            "Worker thread 0 gracefully terminated.");
               killed_gracefully = TRUE;
               }
            }
         }

      if ((!killed_gracefully) && (!status_query_error))
         {
         //Forcible termination.
         rv = TerminateThread(C_MAIN_hCwThread0, 0);
         if (rv)
            {
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                         "Forced termination of worker thread 0.");
            }
         else
            {
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                         "Failed call to force termination of worker thread 0.");
            }
         }

      //In any case, we have no further use for the handle to the thread.
      rv = CloseHandle(C_MAIN_hCwThread0);
      if (!rv)
         {
         LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                      "Failed call to close handle of worker thread 0.");
         }
      }

   //================================================================================
   //=====  T I M E    S N A P S H O T  =============================================
   //================================================================================
   //printf("Time snapshot.\n");
   errno_return = _ftime64_s(&C_MAIN_time_current);
   if (errno_return)
      CCMFATAL_fatal("Failure code from _ftime64_s().",
                    __FILE__,
                    __LINE__);

   //================================================================================
   //=====  T H R E A D    1    T E R M I N A T I O N  ==============================
   //================================================================================
   //printf("Thread 1 termination.\n");
   if (must_end_thread1)
      {
      int i = 50;
      int killed_gracefully = FALSE;
      int status_query_error = FALSE;
      BOOL rv;
      DWORD exit_code;

      C_MAIN_SigTermCwThread1 = TRUE;

      while((i--) && (!killed_gracefully) && (!status_query_error))
         {
         Sleep(100);
         rv = GetExitCodeThread(C_MAIN_hCwThread1, &exit_code);
         if (!rv)
            {
            //Failure on the function call.
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                         "Error determining status of worker thread 1.  Cannot terminate thread.");
            }
         else
            {
            //Success on the function call.
            if (exit_code == STILL_ACTIVE)
               {
               //Can't do anything.  Thread still going.
               }
            else
               {
               LOG_write_ls(&C_MAIN_time_current, 
                            LOG_MT_STARTSTOP, 
                            LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                            "Worker thread 1 gracefully terminated.");
               killed_gracefully = TRUE;
               }
            }
         }

      if ((!killed_gracefully) && (!status_query_error))
         {
         //Forcible termination.
         rv = TerminateThread(C_MAIN_hCwThread1, 0);
         if (rv)
            {
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                         "Forced termination of worker thread 1.");
            }
         else
            {
            LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                         "Failed call to force termination of worker thread 1.");
            }
         }

      //In any case, we have no further use for the handle to the thread.
      rv = CloseHandle(C_MAIN_hCwThread1);
      if (!rv)
         {
         LOG_write_ls(&C_MAIN_time_current, LOG_MT_ALERT, LOG_LI_STDOUT | LOG_LI_ALERT | LOG_LI_COMP, 
                      "Failed call to close handle of worker thread 1.");
         }
      }

   //================================================================================
   //=====  T I M E    S N A P S H O T  =============================================
   //================================================================================
   //printf("Time snapshot.\n");
   errno_return = _ftime64_s(&C_MAIN_time_current);
   if (errno_return)
      CCMFATAL_fatal("Failure code from _ftime64_s().",
                    __FILE__,
                    __LINE__);

   //================================================================================
   //=====  C O M M    0    S T A T E    R E S T O R A T I O N  =====================
   //================================================================================
   //printf("COMM 0 state restoration.\n");
   if (may_restore_com0_state)
      {
      BOOL rv;
      char buf_n[100];

      rv = SetCommState(C_MAIN_hCommPort0, &C_MAIN_CommPort0SavedState);

      if (rv)
         {
	     sprintf_s(buf_n, sizeof(buf_n), "\"%S\" state restoration successful.", argv[1]);
         LOG_write_ls(&C_MAIN_time_current, 
                      LOG_MT_STARTSTOP, 
                      LOG_LI_STDOUT | LOG_LI_COMP, 
                      buf_n);
         }
      else
         {
	     sprintf_s(buf_n, sizeof(buf_n), "Failed to restore \"%S\" state.  Exiting.", argv[1]);
         LOG_write_ls(&C_MAIN_time_current, 
                      LOG_MT_ALERT, 
                      LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                      buf_n);
         }
      }

   //================================================================================
   //=====  T I M E    S N A P S H O T  =============================================
   //================================================================================
   //printf("Time snapshot.\n");
   errno_return = _ftime64_s(&C_MAIN_time_current);
   if (errno_return)
      CCMFATAL_fatal("Failure code from _ftime64_s().",
                    __FILE__,
                    __LINE__);

   //================================================================================
   //=====  C O M M    1    S T A T E    R E S T O R A T I O N  =====================
   //================================================================================
   //printf("COMM 1 state restoration.\n");
   if (may_restore_com1_state)
      {
      BOOL rv;
      char buf_n[100];

      rv = SetCommState(C_MAIN_hCommPort1, &C_MAIN_CommPort1SavedState);

      if (rv)
         {
	     sprintf_s(buf_n, sizeof(buf_n), "\"%S\" state restoration successful.", argv[2]);
         LOG_write_ls(&C_MAIN_time_current, 
                      LOG_MT_STARTSTOP, 
                      LOG_LI_STDOUT | LOG_LI_COMP, 
                      buf_n);
         }
      else
         {
	     sprintf_s(buf_n, sizeof(buf_n), "Failed to restore \"%S\" state.  Exiting.", argv[2]);
         LOG_write_ls(&C_MAIN_time_current, 
                      LOG_MT_ALERT, 
                      LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                      buf_n);
         }
      }

   //================================================================================
   //=====  T I M E    S N A P S H O T  =============================================
   //================================================================================
   //printf("Time snapshot.\n");
   errno_return = _ftime64_s(&C_MAIN_time_current);
   if (errno_return)
      CCMFATAL_fatal("Failure code from _ftime64_s().",
                    __FILE__,
                    __LINE__);

   //================================================================================
   //=====  C O M M    0    C L O S U R E  ==========================================
   //================================================================================
   //printf("COMM 0 closure.\n");
   if (must_close_com0)
      {
      BOOL rv;
      
      rv = CloseHandle(C_MAIN_hCommPort0);

      if (rv)
         {
         char buf_n[100];
         
         //Success
		 sprintf_s(buf_n, sizeof(buf_n), "\"%S\" closed successfully.", argv[1]);
         LOG_write_ls(&C_MAIN_time_current, 
                      LOG_MT_STARTSTOP, 
                      LOG_LI_STDOUT | LOG_LI_COMP, 
                      buf_n);
         }
      else
         {
         char buf_n[100];

         //Failure
		 sprintf_s(buf_n, sizeof(buf_n), "Failed to close \"%S\".", argv[1]);
         LOG_write_ls(&C_MAIN_time_current, 
                      LOG_MT_ALERT, 
                      LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                      buf_n);

         }
      }

   //================================================================================
   //=====  T I M E    S N A P S H O T  =============================================
   //================================================================================
   //printf("Time snapshot.\n");
   errno_return = _ftime64_s(&C_MAIN_time_current);
   if (errno_return)
      CCMFATAL_fatal("Failure code from _ftime64_s().",
                    __FILE__,
                    __LINE__);

   //================================================================================
   //=====  C O M M    1    C L O S U R E  ==========================================
   //================================================================================
   //printf("COMM 1 closure.\n");
   if (must_close_com1)
      {
      BOOL rv;
      
      rv = CloseHandle(C_MAIN_hCommPort1);

      if (rv)
         {
         char buf_n[100];
         
         //Success
		 sprintf_s(buf_n, sizeof(buf_n), "\"%S\" closed successfully.", argv[2]);
         LOG_write_ls(&C_MAIN_time_current, 
                      LOG_MT_STARTSTOP, 
                      LOG_LI_STDOUT | LOG_LI_COMP, 
                      buf_n);
         }
      else
         {
         char buf_n[100];

         //Failure
		 sprintf_s(buf_n, sizeof(buf_n), "Failed to close \"%S\".", argv[2]);
         LOG_write_ls(&C_MAIN_time_current, 
                      LOG_MT_ALERT, 
                      LOG_LI_STDOUT | LOG_LI_COMP | LOG_LI_ALERT, 
                      buf_n);

         }
      }

   //Get the current time.
   errno_return = _ftime64_s(&C_MAIN_time_current);
   if (errno_return)
      CCMFATAL_fatal("Failure code from _ftime64_s().",
                    __FILE__,
                    __LINE__);

   //Write the last line.
   LOG_write_ls(&C_MAIN_time_current, LOG_MT_STARTSTOP, LOG_LI_ALL, "Execution ends.");

   //Close up the log files.
   //printf("Log file closure.\n");
   LOG_close(&C_MAIN_time_current);

   return(0);
   }


const char *C_MAIN_cvcinfo(void)
   {
   return("$Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/winprojs/scirfmmon/source/c_main.c,v 1.45 2009/01/17 19:16:15 dashley Exp $");
   }


const char *C_MAIN_hvcinfo(void)
   {
   return(C_MAIN_H_VERSION);
   }


//$Log: c_main.c,v $
//Revision 1.45  2009/01/17 19:16:15  dashley
//Edits.
//
//Revision 1.44  2009/01/17 06:20:45  dashley
//Edits.
//
//Revision 1.43  2009/01/16 18:18:26  dashley
//Log file flushing added.
//
//Revision 1.42  2009/01/14 00:13:42  dashley
//Is working, but a little rough around the edges.
//
//Revision 1.41  2009/01/12 06:16:42  dashley
//Edits.
//
//Revision 1.40  2009/01/11 18:37:23  dashley
//Edits.
//
//Revision 1.39  2009/01/11 16:53:55  dashley
//Edits.
//
//Revision 1.38  2009/01/11 06:11:31  dashley
//Edits.
//
//Revision 1.37  2009/01/11 05:06:36  dashley
//Edits.
//
//Revision 1.36  2009/01/11 04:10:46  dashley
//Edits.
//
//Revision 1.35  2009/01/09 22:04:42  dashley
//Commit before working at home.
//
//Revision 1.34  2008/12/18 22:00:36  dashley
//Edits.
//
//Revision 1.33  2008/12/18 21:12:59  dashley
//Edits.
//
//Revision 1.32  2008/12/18 19:46:25  dashley
//Substantial edits.
//
//Revision 1.31  2008/12/18 17:18:08  dashley
//Edits.
//
//Revision 1.30  2008/12/18 03:51:02  dashley
//Slack time added in main loop.
//
//Revision 1.29  2008/12/18 03:37:08  dashley
//Updated to set communication mask using SetCommMask().
//
//Revision 1.28  2008/12/18 00:34:28  dashley
//Edits.
//
//Revision 1.27  2008/12/17 23:43:02  dashley
//Edits.
//
//Revision 1.26  2008/12/17 22:46:45  dashley
//Edits.
//
//Revision 1.25  2008/12/17 21:40:57  dashley
//Edits.
//
//Revision 1.24  2008/12/17 17:02:55  dashley
//Configuration of timeouts moved.
//
//Revision 1.23  2008/12/17 05:22:28  dashley
//Edits.
//
//Revision 1.22  2008/12/17 03:17:38  dashley
//Edits.
//
//Revision 1.21  2008/12/17 02:04:29  dashley
//Edits.
//
//Revision 1.20  2008/12/16 22:08:45  dashley
//Edits.
//
//Revision 1.19  2008/12/16 21:59:55  dashley
//Edits.
//
//Revision 1.18  2008/12/16 20:14:19  dashley
//Snapshot of console input (which didn't work as expected).  Saving
//this in version control.  May come back to it.
//
//Revision 1.17  2008/12/16 19:40:32  dashley
//Safety checkin.
//
//Revision 1.16  2008/12/15 23:21:17  dashley
//Edits.
//
//Revision 1.15  2008/12/15 21:10:08  dashley
//GPL license text added to source code and also to program output.
//
//End of $RCSfile: c_main.c,v $.