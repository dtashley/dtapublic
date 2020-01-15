//$Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/winprojs/scirfmmon/source/log_packet.c,v 1.24 2009/01/17 22:12:37 dashley Exp $
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
#define MODULE_LOG_PACKET

#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>

#include "log_packet.h"

#include "c_main.h"
#include "ccmfatal.h"
#include "log.h"
#include "miscfunc.h"
#include "qchar.h"


static void LOG_PACKET_log_f_setpanid                      (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetpanid                   (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_querypanid                    (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_resppanid                     (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_settransad                    (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksettransad                 (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_querytransad                  (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_resptransad                   (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setrfchannel                  (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetrfchannel               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_queryrfchannel                (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_resprfchannel                 (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_endisallrfmsgs                (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_ackendisallrfmsgs             (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_queryrxallrfmsgsstatus        (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_resprxallrfmsgsstatus         (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_endisrfacksretries            (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_ackendisrfacksretries         (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_queryrfacksretriesstatus      (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_resprfacksretriesstatus       (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setradiofeaturesoptions       (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetradiofeaturesoptions   (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_queryradiofeaturesoptions     (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respradiofeaturesoptions      (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_querystatistics               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respstatistics                (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_clearstatistics               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_ackclearstatistics            (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_settxpowerlevel               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksettxpowerlevel            (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_querytxpowerlevel             (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_resptxpowerlevel              (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_savecfgnvm                    (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksavecfgnvm                 (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_queryfirmwareversion          (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respfirmwareversion           (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setlowpowermode               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetlowpowermode               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_senddata                      (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksenddata                   (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_rxeddata                      (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_resetrequest                  (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_ackresetrequest               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_sendmsgapp                    (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksendmsgapp                 (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_rxedmsgapp                    (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_initfirmwaredownload          (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_ackinitfirmwaredownload       (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_transferfirmwareblock         (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acktransferfirmwareblock      (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_terminatedownload             (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_ackterminatedownload          (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setdigpincfg                  (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetdigpincfg               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_querydigpincfg                (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respdigpincfg                 (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setdigpinstate                (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetdigpinstate             (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_querydigpinstate              (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respdigpinstate               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_queryanalogpinvalues          (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respanalogpinvalues           (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setanalogpinsleepstate        (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetanalogpinsleepstate     (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_queryanalogpinsleepstate      (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respanalogpinsleepstate       (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setdigpinsleepstate           (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetdigpinsleepstate        (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_querydigpinsleepstate         (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respdigpinsleepstate          (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setdebugmode                  (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetdebugmode               (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setledfunctionality           (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetledfunctionality        (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_rxbytesidtoid                 (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_setprogrammablesettings       (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_acksetprogrammablesettings    (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_queryprogrammablesettings     (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);
static void LOG_PACKET_log_f_respprogrammablesettings      (int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);


struct LOG_PACKET_pkt_types_struct
   {
   char *tag_terse;                             //Terse tag for the log file and so on identifying this packet type.
   int  type_byte;                              //The type byte value.
   int  length_byte_min;                        //The minimum length byte value.
   int  length_byte_max;                        //The maximum length byte value.
   int  valid_from_host;                        //TRUE if this is valid transmitted from the host microcontroller.
   int  valid_from_rf_mod;                      //TRUE if this is valid transmitted from the RF module.
   void (*logptr)(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console);  
                                                //Function that will parse the full packet and log any errors,
                                                //then log the contents of the packet.  Note that gross packet formatting
                                                //errors (bad type, length, or checksum) are handled at a higher level.  This
                                                //only needs to flag errors in a packet with a correct type, length,
                                                //and checksum.
   };


static const struct LOG_PACKET_pkt_types_struct LOG_PACKET_pkt_type_lut_a[] =
   {
      //Tabulated in same order that appear in LSR documentation.
      //p. 9
      {
      "SET_PAN_ID (0x01)",
      0x01,
      0x07, 
      0x07, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setpanid
      },
      //p. 9
      {
      "ACK_SET_PAN_ID (0x81)",
      0x81,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetpanid
      },
      //p. 10
      {
      "QUERY_PAN_ID (0x02)",
      0x02,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_querypanid
      },
      //p. 10
      {
      "RESP_PAN_ID (0x82)",
      0x82,
      0x07, 
      0x07, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_resppanid
      },
      //p. 11
      {
      "SET_TRANS_AD (0x03)",
      0x03,
      0x0F, 
      0x0F, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_settransad
      },
      //p. 11
      {
      "ACK_SET_TRANS_AD (0x83)",
      0x83,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksettransad
      },
      //p. 12
      {
      "QUERY_TRANS_AD (0x04)",
      0x04,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_querytransad
      },
      //p. 12
      {
      "RESP_TRANS_AD (0x84)",
      0x84,
      0x0F, 
      0x0F, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_resptransad
      },
      //p. 13
      {
      "SET_RF_CHANNEL (0x05)",
      0x05,
      0x06, 
      0x06, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setrfchannel
      },
      //p. 13
      {
      "ACK_SET_RF_CHANNEL (0x85)",
      0x85,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetrfchannel
      },
      //p. 14
      {
      "QUERY_RF_CHANNEL (0x06)",
      0x06,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_queryrfchannel
      },
      //p. 14
      {
      "RESP_RF_CHANNEL (0x86)",
      0x86,
      0x06, 
      0x06, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_resprfchannel
      },
      //p. 15
      {
      "EN_DIS_ALL_RF_MSGS (0x07)",
      0x07,
      0x06, 
      0x06, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_endisallrfmsgs
      },
      //p. 15
      {
      "ACK_EN_DIS_ALL_RF_MSGS (0x87)",
      0x87,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_ackendisallrfmsgs
      },
      //p. 16
      {
      "QUERY_RX_ALL_RF_MSGS_STATUS (0x08)",
      0x08,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_queryrxallrfmsgsstatus
      },
      //p. 16
      {
      "RESP_RX_ALL_RF_MSGS_STATUS (0x88)",
      0x88,
      0x06, 
      0x06, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_resprxallrfmsgsstatus
      },
      //p. 17
      {
      "EN_DIS_RF_ACKS_RETRIES (0x09)",
      0x09,
      0x06, 
      0x06, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_endisrfacksretries
      },
      //p. 17
      {
      "ACK_EN_DIS_RF_ACKS_RETRIES (0x89)",
      0x89,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_ackendisrfacksretries
      },
      //p. 18
      {
      "QUERY_RF_ACKS_RETRIES_STATUS (0x0A)",
      0x0A,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_queryrfacksretriesstatus
      },
      //p. 18
      {
      "RESP_RF_ACKS_RETRIES_STATUS (0x8A)",
      0x8A,
      0x06, 
      0x06, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_resprfacksretriesstatus
      },
      //p. 19
      {
      "SET_RADIO_FEATURES_OPTIONS (0x0B)",
      0x0B,
      0x07, 
      0x07, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setradiofeaturesoptions
      },
      //p. 19
      {
      "ACK_SET_RADIO_FEATURES_OPTIONS (0x8B)",
      0x8B,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetradiofeaturesoptions
      },
      //p. 20
      {
      "QUERY_RADIO_FEATURES_OPTIONS (0x0C)",
      0x0C,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_queryradiofeaturesoptions
      },
      //p. 20
      {
      "RESP_RADIO_FEATURES_OPTIONS (0x8C)",
      0x8C,
      0x07, 
      0x07, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respradiofeaturesoptions
      },
      //p. 21
      {
      "QUERY_STATISTICS (0x0D)",
      0x0D,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_querystatistics
      },
      //p. 21
      {
      "RESP_STATISTICS (0x8D)",
      0x8D,
      0x15, 
      0x15, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respstatistics
      },
      //p. 22
      {
      "CLEAR_STATISTICS (0x0E)",
      0x0E,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_clearstatistics
      },
      //p. 22
      {
      "ACK_CLEAR_STATISTICS (0x8E)",
      0x8E,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_ackclearstatistics
      },
      //p. 23
      {
      "SET_TX_POWER_LEVEL (0x0F)",
      0x0F,
      0x06, 
      0x06, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_settxpowerlevel
      },
      //p. 23
      {
      "ACK_SET_TX_POWER_LEVEL (0x8F)",
      0x8F,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksettxpowerlevel
      },
      //p. 24
      {
      "QUERY_TX_POWER_LEVEL (0x10)",
      0x10,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_querytxpowerlevel
      },
      //p. 24
      {
      "RESP_TX_POWER_LEVEL (0x90)",
      0x90,
      0x06, 
      0x06, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_resptxpowerlevel
      },
      //p. 25
      {
      "SAVE_CFG_NVM (0x11)",
      0x11,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_savecfgnvm
      },
      //p. 25
      {
      "ACK_SAVE_CFG_NVM (0x91)",
      0x91,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksavecfgnvm
      },
      //p. 26
      {
      "QUERY_FIRMWARE_VERSION (0x12)",
      0x12,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_queryfirmwareversion
      },
      //p. 26
      {
      "RESP_FIRMWARE_VERSION (0x92)",
      0x92,
      11, 
      43, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respfirmwareversion
      },
      //p. 27
      {
      "SET_LOW_POWER_MODE (0x13)",
      0x13,
      0x06, 
      0x06, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setlowpowermode
      },
      //p. 27
      {
      "ACK_SET_LOW_POWER_MODE (0x93)",
      0x93,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetlowpowermode
      },
      //p. 28
      {
      "SEND_DATA (0x14)",
      0x14,
      11, 
      255, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_senddata
      },
      //p. 28
      {
      "ACK_SEND_DATA (0x94)",
      0x94,
      0x08, 
      0x08, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksenddata
      },
      //p. 29
      {
      "RXED_DATA (0x95)",
      0x95,
      14, 
      255, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_rxeddata
      },

      //p. 30
      {
      "RESET_REQUEST (0x18)",
      0x18,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_resetrequest
      },
      //p. 30
      {
      "ACK_RESET_REQUEST (0x98)",
      0x98,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_ackresetrequest
      },
      //p. 31
      {
      "SEND_MSG_APP (0x19)",
      0x19,
      6, 
      255, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_sendmsgapp
      },
      //p. 31
      {
      "ACK_SEND_MSG_APP (0x99)",
      0x99,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksendmsgapp
      },
      //p. 32
      {
      "RXED_MSG_APP (0x9A)",
      0x9A,
      6, 
      255, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_rxedmsgapp
      },
      //p. 33
      {
      "INIT_FIRMWARE_DOWNLOAD (0x1B)",
      0x1B,
      0x0F, 
      0x0F, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_initfirmwaredownload
      },
      //p. 33
      {
      "ACK_INIT_FIRMWARE_DOWNLOAD (0x9B)",
      0x9B,
      0x0E, 
      0x0E, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_ackinitfirmwaredownload
      },
      //p. 34
      {
      "TRANSFER_FIRMWARE_BLOCK (0x1C)",
      0x1C,
      0x4F, 
      0x4F, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_transferfirmwareblock
      },
      //p. 34
      {
      "ACK_TRANSFER_FIRMWARE_BLOCK (0x9C)",
      0x9C,
      0x10, 
      0x10, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acktransferfirmwareblock
      },
      //p. 35
      {
      "TERMINATE_DOWNLOAD (0x1D)",
      0x1D,
      0x0D, 
      0x0D, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_terminatedownload
      },
      //p. 35
      {
      "ACK_TERMINATE_DOWNLOAD (0x9D)",
      0x9D,
      0x0D, 
      0x0D, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_ackterminatedownload
      },
      //p. 36
      {
      "SET_DIG_PIN_CFG (0x1E)",
      0x1E,
      0x08, 
      0x08, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setdigpincfg
      },
      //p. 36
      {
      "ACK_SET_DIG_PIN_CFG (0x9E)",
      0x9E,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetdigpincfg
      },
      //p. 37
      {
      "QUERY_DIG_PIN_CFG (0x1F)",
      0x1F,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_querydigpincfg
      },
      //p. 37
      {
      "RESP_DIG_PIN_CFG (0x9F)",
      0x9F,
      0x08, 
      0x08, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respdigpincfg
      },
      //p. 38
      {
      "SET_DIG_PIN_STATE (0x20)",
      0x20,
      0x06, 
      0x06, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setdigpinstate
      },
      //p. 38
      {
      "ACK_SET_DIG_PIN_STATE (0xA0)",
      0xA0,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetdigpinstate
      },
      //p. 39
      {
      "QUERY_DIG_PIN_STATE (0x21)",
      0x21,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_querydigpinstate
      },
      //p. 39
      {
      "RESP_DIG_PIN_STATE (0xA1)",
      0xA1,
      0x06, 
      0x06, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respdigpinstate
      },
      //p. 40
      {
      "QUERY_ANALOG_PIN_VALUES (0x22)",
      0x22,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_queryanalogpinvalues
      },
      //p. 40
      {
      "RESP_ANALOG_PIN_VALUES (0xA2)",
      0xA2,
      0x09, 
      0x09, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respanalogpinvalues
      },
      //p. 41
      {
      "SET_ANALOG_PIN_SLEEP_STATE (0x23)",
      0x23,
      0x07, 
      0x07, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setanalogpinsleepstate
      },
      //p. 41
      {
      "ACK_SET_ANALOG_PIN_SLEEP_STATE (0xA3)",
      0xA3,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetanalogpinsleepstate
      },
      //p. 42
      {
      "QUERY_ANALOG_PIN_SLEEP_STATE (0x24)",
      0x24,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_queryanalogpinsleepstate
      },
      //p. 42
      {
      "RESP_ANALOG_PIN_SLEEP_STATE (0xA4)",
      0xA4,
      0x07, 
      0x07, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respanalogpinsleepstate
      },
      //p. 43
      {
      "SET_DIG_PIN_SLEEP_STATE (0x25)",
      0x25,
      0x08, 
      0x08, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setdigpinsleepstate
      },
      //p. 43
      {
      "ACK_SET_DIG_PIN_SLEEP_STATE (0xA5)",
      0xA5,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetdigpinsleepstate
      },
      //p. 44
      {
      "QUERY_DIG_PIN_SLEEP_STATE (0x26)",
      0x26,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_querydigpinsleepstate
      },
      //p. 44
      {
      "RESP_DIG_PIN_SLEEP_STATE (0xA6)",
      0xA6,
      0x08, 
      0x08, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respdigpinsleepstate
      },
      //p. 45
      {
      "SET_DEBUG_MODE (0x27)",
      0x27,
      0x06, 
      0x06, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setdebugmode
      },
      //p. 45
      {
      "ACK_SET_DEBUG_MODE (0xA7)",
      0xA7,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetdebugmode
      },
      //p. 47
      {
      "SET_LED_FUNCTIONALITY (0x28)",
      0x28,
      0x06, 
      0x06, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setledfunctionality
      },
      //p. 47
      {
      "ACK_SET_LED_FUNCTIONALITY (0xA8)",
      0xA8,
      0x05, 
      0x05, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetledfunctionality
      },
      //p. 49
      {
      "RX_BYTES_ID_TO_ID (0xA9)",
      0xA9,
      14, 
      255, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_rxbytesidtoid
      },
      //p. 50
      {
      "SET_PROGRAMMABLE_SETTINGS (0x2A)",
      0x2A,
      0x15, 
      0x15, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_setprogrammablesettings
      },
      //p. 50
      {
      "ACK_SET_PROGRAMMABLE_SETTINGS (0xAA)",
      0xAA,
      0x07, 
      0x07, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_acksetprogrammablesettings
      },
      //p. 51
      {
      "QUERY_PROGRAMMABLE_SETTINGS (0x2B)",
      0x2B,
      0x05, 
      0x05, 
      TRUE,
      FALSE,
      LOG_PACKET_log_f_queryprogrammablesettings
      },
      //p. 51
      {
      "RESP_PROGRAMMABLE_SETTINGS (0xAB)",
      0xAB,
      0x15, 
      0x15, 
      FALSE,
      TRUE,
      LOG_PACKET_log_f_respprogrammablesettings
      },
   };

//Given a type and length byte, returns either:
//   a)The table index in the lookup table LOG_PACKET_pkt_type_lut_a[] corresponding to the 
//     information table entry.  This will be a non-negative number.
//   b)-1 to signal that the type byte is invalid.
//   c)-2 to signal that the type byte is valid but the length is invalid.
//
static int LOG_PACKET_type_length_lookup_a(int in_type, int in_length)
   {
   int i;

   for (i=0; i < (sizeof(LOG_PACKET_pkt_type_lut_a)/sizeof(LOG_PACKET_pkt_type_lut_a[0])); i++)
      {
      if (LOG_PACKET_pkt_type_lut_a[i].type_byte == in_type)
         {
         if (
               (in_length >= LOG_PACKET_pkt_type_lut_a[i].length_byte_min) 
               && 
               (in_length <= LOG_PACKET_pkt_type_lut_a[i].length_byte_max)
            )
            {
            //Type and length are consistent.  Return the index.
            return(i);
            }
         else
            {
            //Type is OK, but length is not.
            return(-2);
            }
         }
      }

   //If we're here, couldn't find a match on the type.
   return(-1);
   }


//Logs the bytes of a message.
static void LOG_PACKET_log_bytes(const struct __timeb64 *in_ts,
                                 QCHAR_TSE *in_pkts, 
                                 int in_npkts, 
                                 unsigned in_messagetype, 
				                     unsigned in_whichlogs)
   {
   int i, j, k;
   const int bytes_per_line = 14;
   int nlines;
   char buf[250];
   char buf_sub[250];

   nlines = (in_npkts + bytes_per_line - 1) / bytes_per_line;

   for (i=0; i<nlines; i++)
      {
      strcpy_s(buf, sizeof(buf), "     ");

      for (j=0; j<bytes_per_line; j++)
         {
         k = i * bytes_per_line + j;

         if (k >= in_npkts)
            break;

         sprintf_s(buf_sub, sizeof(buf_sub), "<%02X>", ((int)in_pkts[k].c) & 0xFF);
         strcat_s(buf, sizeof(buf), buf_sub);
         }

      LOG_write_ls(in_ts, 
                   in_messagetype, 
                   in_whichlogs, 
                   buf);
      }
   }


//This is the generic packet printer.  It is called when no more specific handler has been written.
//
static void LOG_PACKET_log_f_generic(int in_channel, 
                                     const struct __timeb64 *in_ts, 
                                     QCHAR_TSE *in_pkts, 
                                     int in_npkts, 
                                     int in_lutblentry, 
                                     int in_mirror_to_console,
                                     struct __timeb64 *t_last_msg,  //Static time of last message.
                                     int *first_time                //Static version of whether this is the first time.
                                     )
   {
   int cspan;
   int mdelta;
   char buf[250];

   if (*first_time)
      {
      memcpy(t_last_msg, &(in_pkts[0].ts), sizeof(*t_last_msg));
      *first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(t_last_msg, &(in_pkts[0].ts));
   memcpy(t_last_msg, &(in_pkts[0].ts), sizeof(*t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   }


static void LOG_PACKET_log_f_setpanid(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksetpanid(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_querypanid(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_resppanid(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_settransad(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int cspan;
   int mdelta;
   int translongad[8];
   int transshortad[2];
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));

   translongad[7]  = ((int)in_pkts[ 3].c) & 0xFF;
   translongad[6]  = ((int)in_pkts[ 4].c) & 0xFF;
   translongad[5]  = ((int)in_pkts[ 5].c) & 0xFF;
   translongad[4]  = ((int)in_pkts[ 6].c) & 0xFF;
   translongad[3]  = ((int)in_pkts[ 7].c) & 0xFF;
   translongad[2]  = ((int)in_pkts[ 8].c) & 0xFF;
   translongad[1]  = ((int)in_pkts[ 9].c) & 0xFF;
   translongad[0]  = ((int)in_pkts[10].c) & 0xFF;

   transshortad[1] = ((int)in_pkts[11].c) & 0xFF;
   transshortad[0] = ((int)in_pkts[12].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     TRANS_LONG_AD: 0x%02X%02X%02X%02X%02X%02X%02X%02X, TRANS_SHORT_AD: 0x%02X%02X.", 
             translongad[0],
             translongad[1],
             translongad[2],
             translongad[3],
             translongad[4],
             translongad[5],
             translongad[6],
             translongad[7],
             transshortad[0],
             transshortad[1]);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);
   }

   
static void LOG_PACKET_log_f_acksettransad(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_querytransad(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_resptransad(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_setrfchannel(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_acksetrfchannel(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_queryrfchannel(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_resprfchannel(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_endisallrfmsgs(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_ackendisallrfmsgs(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_queryrxallrfmsgsstatus(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_resprxallrfmsgsstatus(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_endisrfacksretries(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

static void LOG_PACKET_log_f_ackendisrfacksretries(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_queryrfacksretriesstatus(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_resprfacksretriesstatus(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setradiofeaturesoptions(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksetradiofeaturesoptions(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_queryradiofeaturesoptions(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_respradiofeaturesoptions(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_querystatistics(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_respstatistics(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_clearstatistics(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_ackclearstatistics(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_settxpowerlevel(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksettxpowerlevel(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_querytxpowerlevel(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_resptxpowerlevel(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_savecfgnvm(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksavecfgnvm(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_queryfirmwareversion(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_respfirmwareversion(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setlowpowermode(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksetlowpowermode(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }


static void LOG_PACKET_log_f_senddata(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int idx;
   int cspan;
   int mdelta;
   int packetid;
   int targetsender;
   int addressmode;
   int desttransad[8];
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));

   packetid     = ((int)in_pkts[3].c) & 0xFF;
   targetsender = ((int)in_pkts[4].c) & 0xFF;
   addressmode  = ((int)in_pkts[5].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     PACKET_ID: 0x%02X, TARGET_SENDER: 0x%02X, ADDRESS_MODE: 0x%02X.", 
             packetid,
             targetsender,
             addressmode
             );

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //Flag a bad address mode if it exists.
   if ((addressmode != 0x00) && (addressmode != 0x10))
      {
      sprintf_s(buf, sizeof(buf), "CH%02d:ADDRESS_MODE error in %s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);

      sprintf_s(buf, sizeof(buf), "     ADDRESS_MODE: 0x%02X.", addressmode);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);
      }

   //Form up the destination address.  It may be short or long.
   FillMemory(desttransad, sizeof(desttransad), 0);

   idx = 6;
   if (in_npkts > idx)
      {
      desttransad[7] = ((int)in_pkts[idx].c) & 0xFF;
      }
   idx++;
   if (in_npkts > idx)
      {
      desttransad[6] = ((int)in_pkts[idx].c) & 0xFF;
      }
   idx++;

   if (addressmode & 0xf0) //Long address.
      {
      if (in_npkts > idx)
         {
         desttransad[5] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[4] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[3] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[2] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[1] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[0] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      }

   //If we've overshot the data area (and the assumption is made that there is at least one
   //byte of data), this means that the address modes were inconsistent with the message length.
   //This is an error.
   if (idx > (in_npkts - 3))
      {
      sprintf_s(buf, sizeof(buf), "CH%02d:ADDRESS_MODE and message length error in %s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);
      }

   //Emit the destination transceiver address.  There is some variability due
   //to the address mode.
   if (addressmode & 0xf0) //Destination transceiver long address.
      {
      sprintf_s(buf, 
                sizeof(buf), 
                "     DST_TRANS_AD: 0x%02X%02X%02X%02X02X%02X%02X%02X.", 
                ((int)desttransad[0]) & 0xFF,
                ((int)desttransad[1]) & 0xFF,
                ((int)desttransad[2]) & 0xFF,
                ((int)desttransad[3]) & 0xFF,
                ((int)desttransad[4]) & 0xFF,
                ((int)desttransad[5]) & 0xFF,
                ((int)desttransad[6]) & 0xFF,
                ((int)desttransad[7]) & 0xFF);
      }
   else
      {
      sprintf_s(buf, 
                sizeof(buf), 
                "     DST_TRANS_AD: 0x%02X%02X.", 
                ((int)desttransad[6]) & 0xFF,
                ((int)desttransad[7]) & 0xFF);
      }

   //And write the line to the log.
   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //Write the data bytes.
   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                "     DATA:");

   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts + idx, 
                        in_npkts - idx - 2,
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   }

   
static void LOG_PACKET_log_f_acksenddata(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int cspan;
   int mdelta;
   int packetid;
   int acknack;
   int nretries;
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));

   packetid  = ((int)in_pkts[ 3].c) & 0xFF;
   acknack   = ((int)in_pkts[ 4].c) & 0xFF;
   nretries  = ((int)in_pkts[ 5].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     PACKET_ID: 0x%02X, ACK_NACK: 0x%02X, NUM_RETRIES: 0x%02X.", 
             packetid,
             acknack,
             nretries
             );

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   if (acknack != 0x01)
      {
      sprintf_s(buf, sizeof(buf), "CH%02d:ACK_NACK error in %s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);

      sprintf_s(buf, sizeof(buf), "     ACK_NACK: 0x%02X.", acknack);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);
      }
   }

   
static void LOG_PACKET_log_f_rxeddata(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int idx;
   int cspan;
   int mdelta;
   int packetid;
   int targetsender;
   int lqi;
   int addressmode;
   int desttransad[8];
   int srctransad[8];
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));

   packetid     = ((int)in_pkts[3].c) & 0xFF;
   targetsender = ((int)in_pkts[4].c) & 0xFF;
   lqi          = ((int)in_pkts[5].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     PACKET_ID: 0x%02X, TARGET_SENDER: 0x%02X, LQI: 0x%02X.", 
             packetid,
             targetsender,
             lqi
             );

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   addressmode = ((int)in_pkts[6].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     ADDRESS_MODE: 0x%02X.", 
             addressmode);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //Flag a bad address mode if it exists.
   if ((addressmode != 0x00) && (addressmode != 0x01) && (addressmode != 0x10) && (addressmode != 0x11))
      {
      sprintf_s(buf, sizeof(buf), "CH%02d:ADDRESS_MODE error in %s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);

      sprintf_s(buf, sizeof(buf), "     ADDRESS_MODE: 0x%02X.", addressmode);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);
      }

   //Form up the destination address.  It may be short or long.
   FillMemory(desttransad, sizeof(desttransad), 0);

   idx = 7;
   if (in_npkts > idx)
      {
      desttransad[7] = ((int)in_pkts[idx].c) & 0xFF;
      }
   idx++;
   if (in_npkts > idx)
      {
      desttransad[6] = ((int)in_pkts[idx].c) & 0xFF;
      }
   idx++;

   if (addressmode & 0xf0) //Long address.
      {
      if (in_npkts > idx)
         {
         desttransad[5] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[4] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[3] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[2] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[1] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         desttransad[0] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      }

   //Form up the source address.  It may be short or long.
   FillMemory(srctransad, sizeof(srctransad), 0);

   if (in_npkts > idx)
      {
      srctransad[7] = ((int)in_pkts[idx].c) & 0xFF;
      }
   idx++;
   if (in_npkts > idx)
      {
      srctransad[6] = ((int)in_pkts[idx].c) & 0xFF;
      }
   idx++;

   if (addressmode & 0x0f) //Long address.
      {
      if (in_npkts > idx)
         {
         srctransad[5] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         srctransad[4] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         srctransad[3] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         srctransad[2] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         srctransad[1] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      if (in_npkts > idx)
         {
         srctransad[0] = ((int)in_pkts[idx].c) & 0xFF;
         }
      idx++;
      }

   //If we've overshot the data area (and the assumption is made that there is at least one
   //byte of data), this means that the address modes were inconsistent with the message length.
   //This is an error.
   if (idx > (in_npkts - 3))
      {
      sprintf_s(buf, sizeof(buf), "CH%02d:ADDRESS_MODE and message length error in %s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);
      }

   //Emit the destination transceiver and source transceiver address.  There is some variability due
   //to the address mode.
      {
      char minibuf[250];

      strcpy_s(buf, sizeof(buf), "     ");

      if (addressmode & 0xf0) //Destination transceiver long address.
         {
         sprintf_s(minibuf, 
                   sizeof(minibuf), 
                   "DST_TRANS_AD: 0x%02X%02X%02X%02X02X%02X%02X%02X,", 
                   ((int)desttransad[0]) & 0xFF,
                   ((int)desttransad[1]) & 0xFF,
                   ((int)desttransad[2]) & 0xFF,
                   ((int)desttransad[3]) & 0xFF,
                   ((int)desttransad[4]) & 0xFF,
                   ((int)desttransad[5]) & 0xFF,
                   ((int)desttransad[6]) & 0xFF,
                   ((int)desttransad[7]) & 0xFF);
         }
      else
         {
         sprintf_s(minibuf, 
                   sizeof(minibuf), 
                   "DST_TRANS_AD: 0x%02X%02X,", 
                   ((int)desttransad[6]) & 0xFF,
                   ((int)desttransad[7]) & 0xFF);
         }

      //Add in the string and some space.
      strcat_s(buf, sizeof(buf), minibuf);
      strcat_s(buf, sizeof(buf), " ");

      if (addressmode & 0x0f) //Source transceiver long address.
         {
         sprintf_s(minibuf, 
                   sizeof(minibuf), 
                   "SRC_TRANS_AD: 0x%02X%02X%02X%02X02X%02X%02X%02X.", 
                   ((int)srctransad[0]) & 0xFF,
                   ((int)srctransad[1]) & 0xFF,
                   ((int)srctransad[2]) & 0xFF,
                   ((int)srctransad[3]) & 0xFF,
                   ((int)srctransad[4]) & 0xFF,
                   ((int)srctransad[5]) & 0xFF,
                   ((int)srctransad[6]) & 0xFF,
                   ((int)srctransad[7]) & 0xFF);
         }
      else
         {
         sprintf_s(minibuf, 
                   sizeof(minibuf), 
                   "SRC_TRANS_AD: 0x%02X%02X.", 
                   ((int)srctransad[6]) & 0xFF,
                   ((int)srctransad[7]) & 0xFF);
         }

      //Add in the string.
      strcat_s(buf, sizeof(buf), minibuf);

      //And write the line to the log.
      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ROUTINE, 
                   (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                   buf);
      }

   //Write the data bytes.
   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                "     DATA:");

   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts + idx, 
                        in_npkts - idx - 2,
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   }

   
static void LOG_PACKET_log_f_resetrequest(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_ackresetrequest(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_sendmsgapp(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksendmsgapp(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_rxedmsgapp(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_initfirmwaredownload(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_ackinitfirmwaredownload(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_transferfirmwareblock(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acktransferfirmwareblock(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_terminatedownload(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_ackterminatedownload(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setdigpincfg(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksetdigpincfg(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_querydigpincfg(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_respdigpincfg(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setdigpinstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksetdigpinstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_querydigpinstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_respdigpinstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_queryanalogpinvalues(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_respanalogpinvalues(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setanalogpinsleepstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksetanalogpinsleepstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_queryanalogpinsleepstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_respanalogpinsleepstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setdigpinsleepstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksetdigpinsleepstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_querydigpinsleepstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_respdigpinsleepstate(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setdebugmode(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_acksetdebugmode(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setledfunctionality(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int cspan;
   int mdelta;
   int ledmode;
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));

   ledmode  = ((int)in_pkts[3].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     LED_MODE: 0x%02X.", 
             ledmode);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);
   if (ledmode & 0xF8)  //Bits set in the mode that shouldn't be.
      {
      sprintf_s(buf, sizeof(buf), "CH%02d:LED_MODE error in %s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);

      sprintf_s(buf, sizeof(buf), "     LED_MODE: 0x%02X.", ledmode);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);
      }
   }

   
static void LOG_PACKET_log_f_acksetledfunctionality(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_rxbytesidtoid(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;

   LOG_PACKET_log_f_generic(in_channel, 
                            in_ts, 
                            in_pkts, 
                            in_npkts, 
                            in_lutblentry, 
                            in_mirror_to_console,
                            &t_last_msg,
                            &first_time);
   }

   
static void LOG_PACKET_log_f_setprogrammablesettings(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int cspan;
   int mdelta;
   int panidlsb, panidmsb, panid;
   int rfchannel;
   int receive_all;
   int rfacksretries;
   int rfpowerlevel;
   int txcvrlongad[8];
   int txcvrshortad[2];
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));

   panidlsb = ((int)in_pkts[3].c) & 0xFF;
   panidmsb = ((int)in_pkts[4].c) & 0xFF;
   panid = 256 * panidmsb + panidlsb;

   txcvrlongad[7] = ((int)in_pkts[ 5].c) & 0xFF;
   txcvrlongad[6] = ((int)in_pkts[ 6].c) & 0xFF;
   txcvrlongad[5] = ((int)in_pkts[ 7].c) & 0xFF;
   txcvrlongad[4] = ((int)in_pkts[ 8].c) & 0xFF;
   txcvrlongad[3] = ((int)in_pkts[ 9].c) & 0xFF;
   txcvrlongad[2] = ((int)in_pkts[10].c) & 0xFF;
   txcvrlongad[1] = ((int)in_pkts[11].c) & 0xFF;
   txcvrlongad[0] = ((int)in_pkts[12].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     PANID: 0x%04X, TXCVR_LONG_AD: 0x%02X%02X%02X%02X%02X%02X%02X%02X.", 
             panid,
             txcvrlongad[0],
             txcvrlongad[1],
             txcvrlongad[2],
             txcvrlongad[3],
             txcvrlongad[4],
             txcvrlongad[5],
             txcvrlongad[6],
             txcvrlongad[7]
             );

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   txcvrshortad[1] = ((int)in_pkts[13].c) & 0xFF;
   txcvrshortad[0] = ((int)in_pkts[14].c) & 0xFF;

   rfchannel       = ((int)in_pkts[15].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     TXCVR_SHORT_AD: 0x%02X%02X, RF_CHANNEL: 0x%02X.", 
             txcvrshortad[0],
             txcvrshortad[1],
             rfchannel
             );

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   receive_all    = ((int)in_pkts[16].c) & 0xFF;
   rfacksretries  = ((int)in_pkts[17].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     RECEIVE_ALL: 0x%02X, RF_ACKS_RETRIES: 0x%02X.", 
             receive_all,
             rfacksretries
             );

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   rfpowerlevel  = ((int)in_pkts[18].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     RF_POWER_LEVEL: 0x%02X.", 
             rfpowerlevel
             );

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);
   }

   
static void LOG_PACKET_log_f_acksetprogrammablesettings(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int cspan;
   int mdelta;
   int acknack;
   int status;
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));

   acknack   = ((int)in_pkts[ 3].c) & 0xFF;
   status    = ((int)in_pkts[ 4].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     ACK_NACK: 0x%02X, STATUS: 0x%02X.", 
             acknack,
             status
             );

   LOG_write_ls(&(in_pkts[0].ts), 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   if (acknack != 0x01)
      {
      sprintf_s(buf, sizeof(buf), "CH%02d:ACK_NACK error in %s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);

      sprintf_s(buf, sizeof(buf), "     ACK_NACK: 0x%02X, STATUS: 0x%02X.", acknack, status);

      LOG_write_ls(&(in_pkts[0].ts), 
                   LOG_MT_ALERT, 
                   LOG_LI_PKT | LOG_LI_ALERT | LOG_LI_COMP | LOG_LI_STDOUT, 
                   buf);
      }
   }

   
static void LOG_PACKET_log_f_queryprogrammablesettings(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int cspan;
   int mdelta;
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(in_ts, 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(in_ts, 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   }

   
static void LOG_PACKET_log_f_respprogrammablesettings(int in_channel, const struct __timeb64 *in_ts, QCHAR_TSE *in_pkts, int in_npkts, int in_lutblentry, int in_mirror_to_console)
   {
   int cspan;
   int mdelta;
   int panidlsb, panidmsb, panid;
   int rfchannel;
   int receive_all;
   int rfacksretries;
   int rfpowerlevel;
   int txcvrlongad[8];
   int txcvrshortad[2];
   static struct __timeb64 t_last_msg;
   static int first_time = TRUE;
   char buf[250];

   if (first_time)
      {
      memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));
      first_time = FALSE;
      }

   cspan = MISCFUNC_timb64_diff_bounded_ms(&(in_pkts[0].ts), &(in_pkts[in_npkts-1].ts));
   mdelta = MISCFUNC_timb64_diff_bounded_ms(&t_last_msg, &(in_pkts[0].ts));
   memcpy(&t_last_msg, &(in_pkts[0].ts), sizeof(t_last_msg));

   sprintf_s(buf, sizeof(buf), "CH%02d:%s.", in_channel, LOG_PACKET_pkt_type_lut_a[in_lutblentry].tag_terse);

   LOG_write_ls(in_ts, 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   sprintf_s(buf, sizeof(buf), "     cspan=%d, mdelta=%d.", cspan, mdelta);

   LOG_write_ls(in_ts, 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   //The header.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts, 
                        3, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The payload.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+3, 
                        in_npkts-5, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));
   //The trailer.
   LOG_PACKET_log_bytes(&(in_pkts[0].ts),
                        in_pkts+in_npkts-2, 
                        2, 
                        LOG_MT_ROUTINE, 
				            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP));

   panidlsb = ((int)in_pkts[3].c) & 0xFF;
   panidmsb = ((int)in_pkts[4].c) & 0xFF;
   panid = 256 * panidmsb + panidlsb;

   txcvrlongad[7] = ((int)in_pkts[ 5].c) & 0xFF;
   txcvrlongad[6] = ((int)in_pkts[ 6].c) & 0xFF;
   txcvrlongad[5] = ((int)in_pkts[ 7].c) & 0xFF;
   txcvrlongad[4] = ((int)in_pkts[ 8].c) & 0xFF;
   txcvrlongad[3] = ((int)in_pkts[ 9].c) & 0xFF;
   txcvrlongad[2] = ((int)in_pkts[10].c) & 0xFF;
   txcvrlongad[1] = ((int)in_pkts[11].c) & 0xFF;
   txcvrlongad[0] = ((int)in_pkts[12].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     PANID: 0x%04X, TXCVR_LONG_AD: 0x%02X%02X%02X%02X%02X%02X%02X%02X.", 
             panid,
             txcvrlongad[0],
             txcvrlongad[1],
             txcvrlongad[2],
             txcvrlongad[3],
             txcvrlongad[4],
             txcvrlongad[5],
             txcvrlongad[6],
             txcvrlongad[7]
             );

   LOG_write_ls(in_ts, 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   txcvrshortad[1] = ((int)in_pkts[13].c) & 0xFF;
   txcvrshortad[0] = ((int)in_pkts[14].c) & 0xFF;

   rfchannel       = ((int)in_pkts[15].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     TXCVR_SHORT_AD: 0x%02X%02X, RF_CHANNEL: 0x%02X.", 
             txcvrshortad[0],
             txcvrshortad[1],
             rfchannel
             );

   LOG_write_ls(in_ts, 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   receive_all    = ((int)in_pkts[16].c) & 0xFF;
   rfacksretries  = ((int)in_pkts[17].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     RECEIVE_ALL: 0x%02X, RF_ACKS_RETRIES: 0x%02X.", 
             receive_all,
             rfacksretries
             );

   LOG_write_ls(in_ts, 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);

   rfpowerlevel  = ((int)in_pkts[18].c) & 0xFF;

   sprintf_s(buf, sizeof(buf), "     RF_POWER_LEVEL: 0x%02X.", 
             rfpowerlevel
             );

   LOG_write_ls(in_ts, 
                LOG_MT_ROUTINE, 
                (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP), 
                buf);
   }


//Returns a pointer to a string describing an event.  The string is made for announcing events
//that can't be used for a particular intended purpose.
//
//This function is not thread-safe.
//
const char *LOG_PACKET_event_text_desc_a(const QCHAR_TSE *in_ev)
   {
   static char buf[250];

   switch (in_ev->ev)
      {
      case QCHAR_EV_CHAR:
         sprintf_s(buf, sizeof(buf), "Character: 0x%02X", ((int)in_ev->c) & 0xFF);
         break;
      case QCHAR_EV_BREAK:
         sprintf_s(buf, sizeof(buf), "Event: BREAK");
         break;
      case QCHAR_EV_FRAME:
         sprintf_s(buf, sizeof(buf), "Event: FRAMING_ERROR");
         break;
      case QCHAR_EV_OVERRUN:
         sprintf_s(buf, sizeof(buf), "Event: LOW_LEVEL_OVERRUN");
         break;
      case QCHAR_EV_RXOVER:
         sprintf_s(buf, sizeof(buf), "Event: RECEIVE_Q_OVERFLOW");
         break;
      case QCHAR_EV_RXPARITY:
         sprintf_s(buf, sizeof(buf), "Event: PARITY_ERROR");
         break;
      default:
         sprintf_s(buf, sizeof(buf), "Event: INTERNAL_SOFTWARE_ERROR");
         break;
      }

   return(buf);
   }


//Discards events that can't be the start of a packet.
//
static void LOG_PACKET_non_start_discard(int in_channel, QCHAR_CCEQ *in_q, const struct __timeb64 *in_ts, int in_mirror_to_console)
   {
   int done = FALSE;
   QCHAR_TSE item;

   while (!done)
      {
      //Can't proceed if no elements in queue.
      if (! QCHAR_cceq_nelem(in_q))
         {
         done = TRUE;
         }

      //Peek at the first element.
      if (!done)
         QCHAR_cceq_peek(in_q, &item);

      //If the first element is invalid, discard it, else we're done.
      if (!done)
         {
         if ((item.ev != QCHAR_EV_CHAR) || (item.c != 0x01))
            {
            char buf[250];

            sprintf_s(buf, sizeof(buf), "CH%02d:Non-packet start event discarded: %s.", in_channel, LOG_PACKET_event_text_desc_a(&item));

            LOG_write_ls(&(item.ts), 
                         LOG_MT_ALERT, 
                         (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                         buf);
            QCHAR_cceq_get(in_q, &item);
            }
         else
            {
            //First element is apparently a start element.  We're good.
            done = TRUE;
            }
         }
      }
   }


//Resynchronizes by discarding an apparent start element that can't be used and then looking for another
//start element.
//
static void LOG_PACKET_non_start_resync_discard(int in_channel, QCHAR_CCEQ *in_q, const struct __timeb64 *in_ts, int in_mirror_to_console)
   {
   QCHAR_TSE item;

   //Can't proceed if no elements in queue.
   if (! QCHAR_cceq_nelem(in_q))
      {
      return;
      }

   //Peek at the first element.
   QCHAR_cceq_peek(in_q, &item);

   //If the first element is a start element, discard it.
   if ((item.ev == QCHAR_EV_CHAR) && (item.c == 0x01))
      {
      char buf[250];

      sprintf_s(buf, sizeof(buf), "CH%02d:SOH start event discarded to resynchronize.", in_channel);

      LOG_write_ls(&(item.ts), 
                   LOG_MT_ALERT, 
                   (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                   buf);
      QCHAR_cceq_get(in_q, &item);
      }

   //Discard characters beyond the SOH that can't be the start.
   LOG_PACKET_non_start_discard(in_channel, in_q, in_ts, in_mirror_to_console);
   }


//Figures out whether a range is all characters and what the checksum is.  Note that end index is 1+.
//
static void LOG_PACKET_q_range_all_chars_cksum8(QCHAR_CCEQ *in_q, int in_sidx, int in_eidx, int *out_all_chars, int *out_cksum8)
   {
   int i;
   QCHAR_TSE item;
   int cksum8 = 0;
   int all_chars = TRUE;

   for (i=in_sidx; i<in_eidx; i++)
      {
      QCHAR_cceq_peek_n(in_q, i, &item);

      if (item.ev == QCHAR_EV_CHAR)
         {
         cksum8 += (((int)item.c) & 0xFF);
         cksum8 &= 0xFF;
         }
      else
         {
         all_chars = FALSE;
         }
      }

   *out_all_chars = all_chars;
   *out_cksum8 = cksum8;
   }


static void LOG_PACKET_emit(int in_channel, QCHAR_CCEQ *in_q, const struct __timeb64 *in_ts, int in_mirror_to_console)
   {
   int lut_index;
   int declared_length;
   int declared_checksum;
   int nqueue;
   int must_resync = FALSE;
   int done = FALSE;
   int packet_found;
   QCHAR_TSE item_soh;
   QCHAR_TSE item_length;
   QCHAR_TSE item_type;
   QCHAR_TSE item_checksum;
   QCHAR_TSE item_endbyte;
   QCHAR_TSE event_buf[256];
   char buf[250];

   while (! done)
      {
      packet_found = FALSE;
      must_resync = FALSE;

      //All packets have to start with a character 0x01.  Trash anything that is not a character and/or not
      //a 0x01.
      LOG_PACKET_non_start_discard(in_channel, in_q, in_ts, in_mirror_to_console);
   
      //If there is nothing left in the queue, we can't go further.
      nqueue = QCHAR_cceq_nelem(in_q);
      if (!nqueue)
         return;

      if (nqueue >= 3)
         //We can begin looking for anomalies as soon as 3 characters.
         {
         //Grab the presumed SOH.
         QCHAR_cceq_peek_n(in_q, 0, &item_soh);

         //Grab the presumed length.
         QCHAR_cceq_peek_n(in_q, 1, &item_length);

         //Grab the presumed type.
         QCHAR_cceq_peek_n(in_q, 2, &item_type);

         //If the SOH is not as expected, must resynchronize.
         if ((item_soh.ev != QCHAR_EV_CHAR) || (item_soh.c != 0x01))
            {
            sprintf_s(buf, sizeof(buf), "CH%02d:Expected: SOH.  Actual: %s.", in_channel, LOG_PACKET_event_text_desc_a(&item_soh));

            LOG_write_ls(in_ts, 
                         LOG_MT_ALERT, 
                         (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                         buf);

            must_resync = TRUE;
            }

         //If the length is not a received character, must resynchronize.
         if (item_length.ev != QCHAR_EV_CHAR)
            {
            sprintf_s(buf, sizeof(buf), "CH%02d:Expected: Length.  Actual: %s.", in_channel, LOG_PACKET_event_text_desc_a(&item_length));

            LOG_write_ls(in_ts, 
                         LOG_MT_ALERT, 
                         (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                         buf);

            must_resync = TRUE;
            }

         //If the type is not a received character, must resynchronize.
         if (item_type.ev != QCHAR_EV_CHAR)
            {
            sprintf_s(buf, sizeof(buf), "CH%02d:Expected: Type.  Actual: %s.", in_channel, LOG_PACKET_event_text_desc_a(&item_type));

            LOG_write_ls(in_ts, 
                         LOG_MT_ALERT, 
                         (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                         buf);

            must_resync = TRUE;
            }

         //Try to look up the length and type and get a table index.  This may result in an error.
         lut_index = LOG_PACKET_type_length_lookup_a(((int)item_type.c) & 0xFF, ((int)item_length.c) & 0xFF);

         if (lut_index < 0)
            {
            if (lut_index == -2)
               {
               //Type is invalid.  Must resync.
               sprintf_s(buf, sizeof(buf), "CH%02d:Type byte has invalid value (0x%02X).", in_channel, ((int)item_type.c) & 0xFF);

               LOG_write_ls(in_ts, 
                            LOG_MT_ALERT, 
                            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                            buf);

               must_resync = TRUE;
               }
            else if (lut_index == -1)
               {
               //Length is inconsistent with type.
               sprintf_s(buf, 
                         sizeof(buf), 
                         "CH%02d:Type is acceptable(0x%02X) but length is inconsistent (0x%02X).", 
                         in_channel, 
                         ((int)item_type.c) & 0xFF, 
                         ((int)item_length.c) & 0xFF);

               LOG_write_ls(in_ts, 
                            LOG_MT_ALERT, 
                            (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                            buf);

               must_resync = TRUE;
               }
            else
               {
               //Negative value but don't know why.  This is an impossible internal software error.
               CCMFATAL_fatal("Unexpected internal software error.", __FILE__, __LINE__);
               }
            }
         else
            {
            //Index >= 0, so it is a valid table index.
            //
            //Look to see if we have at least as many characters as the declared length.
            declared_length = ((int)item_length.c) & 0xFF;

            if (nqueue >= declared_length)
               {
               //We have enough characters.  Peek at the end byte.  If it is wrong, can't continue.
               QCHAR_cceq_peek_n(in_q, declared_length-1, &item_endbyte);
           
               if ((item_endbyte.ev != QCHAR_EV_CHAR) || (item_endbyte.c != 0x04))
                  {
                  sprintf_s(buf, sizeof(buf), "CH%02d:Expected: 0x04 endbyte.  Actual: %s.", in_channel, LOG_PACKET_event_text_desc_a(&item_endbyte));

                  LOG_write_ls(in_ts, 
                               LOG_MT_ALERT, 
                               (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                               buf);

                  must_resync = TRUE;
                  }
               else
                  {
                  //Gotta look at checksum.
                  QCHAR_cceq_peek_n(in_q, declared_length-2, &item_checksum);
           
                  if (item_checksum.ev != QCHAR_EV_CHAR)
                     {
                     sprintf_s(buf, sizeof(buf), "CH%02d:Expected: checksum is character.  Actual: %s.", in_channel, LOG_PACKET_event_text_desc_a(&item_checksum));

                     LOG_write_ls(in_ts, 
                                  LOG_MT_ALERT, 
                                  (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                                  buf);

                     must_resync = TRUE;
                     }
                  else
                     {
                     int calculated_checksum;
                     int all_chars;

                     declared_checksum = ((int)item_checksum.c) & 0xFF;

                     LOG_PACKET_q_range_all_chars_cksum8(in_q, 0, declared_length-2, &all_chars, &calculated_checksum);

                     if (! all_chars)
                        {
                        //Not everything was a character.  Must resync.
                        sprintf_s(buf, sizeof(buf), "CH%02d:Some packet items not characters.  Resynchronizing.", in_channel);

                        LOG_write_ls(in_ts, 
                                     LOG_MT_ALERT, 
                                     (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                                     buf);

                        must_resync = TRUE;
                        }
                     else
                        {
                        if (calculated_checksum != declared_checksum)
                           {
                           //Checksum error.  Must resync.
                           sprintf_s(buf, 
                                     sizeof(buf), 
                                     "CH%02d:Packet checksum mismatch.  Declared: 0x%02X.  Actual: 0x%02X.  Resynchronizing.", 
                                     in_channel, 
                                     declared_checksum, 
                                     calculated_checksum);

                           LOG_write_ls(in_ts, 
                                        LOG_MT_ALERT, 
                                        (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                                        buf);

                           must_resync = TRUE;
                           }
                        else
                           {
                           //Everything looks OK.  Issue a warning if the packet type is inconsistent with what is allowed.  By convention, channel 0 is the
                           //line from the host micro to the RF module, and channel 1 is the one back.
                           //
                           if ((in_channel == 0) && (!LOG_PACKET_pkt_type_lut_a[lut_index].valid_from_host))
                              {
                              //Packet not allowed from host.
                              sprintf_s(buf, 
                                        sizeof(buf), 
                                        "CH%02d:Packet type not allowed from host.", 
                                        in_channel);

                              LOG_write_ls(in_ts, 
                                           LOG_MT_ALERT, 
                                           (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                                           buf);
                              }
                           else if ((in_channel == 1) && (!LOG_PACKET_pkt_type_lut_a[lut_index].valid_from_rf_mod))
                              {
                              //Packet not allowed from RF module.
                              sprintf_s(buf, 
                                        sizeof(buf), 
                                        "CH%02d:Packet type not allowed from RF module.", 
                                        in_channel);

                              LOG_write_ls(in_ts, 
                                           LOG_MT_ALERT, 
                                           (in_mirror_to_console) ? (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT) : (LOG_LI_PKT | LOG_LI_COMP | LOG_LI_ALERT | LOG_LI_STDOUT), 
                                           buf);
                              }

                           //We are in the green to call the function to handle the packet.  At the same time we get the
                           //characters ready for this function, we pull them from the queue.
                           //
                              {
                              int i;

                              //Be sure we're consistent.  Everybody gets a clean copy.
                              FillMemory(event_buf, sizeof(event_buf), 0);
                              
                              //Do the copy and queue removal.
                              for (i=0; i<declared_length; i++)
                                 {
                                 QCHAR_cceq_get(in_q, &(event_buf[i]));
                                 }

                              //Call the function to handle it.
                              (*LOG_PACKET_pkt_type_lut_a[lut_index].logptr)(in_channel,
                                                                             in_ts,
                                                                             event_buf, 
                                                                             declared_length, 
                                                                             lut_index, 
                                                                             in_mirror_to_console);  

                              //We did find a packet.
                              packet_found = TRUE;
                              }
                           }
                        }

                     }
                  }
               }
            }
         } //End if nqueue >= 3.

      //If the terminal event in the queue has aged out, must resync.
      nqueue = QCHAR_cceq_nelem(in_q);
      if (!nqueue)
         return;

      QCHAR_cceq_peek_n(in_q, nqueue-1, &item_endbyte);
      if (MISCFUNC_timb64_diff_bounded_ms(&(item_endbyte.ts), in_ts) > LOG_PACKET_CHAR_STRAGGLER_TIME)
         {
         must_resync = TRUE;
         }

      //Resync if requested.
      if (must_resync)
         {
         LOG_PACKET_non_start_resync_discard(in_channel, in_q, in_ts, in_mirror_to_console);
         }

      //We are not done if we found a packet or had to resync.
      if (!packet_found && !must_resync)
         done = TRUE;
      } //End while(! done)
   }


void LOG_PACKET_advance(QCHAR_CCEQ *in_q0, QCHAR_CCEQ *in_q1, const struct __timeb64 *in_ts, int in_mirror_to_console)
   {
   //All we need to do is gather as many characters as we can and group them by timestamp.  We need to do this
   //once for each channel.
   LOG_PACKET_emit(0, in_q0, in_ts, in_mirror_to_console);
   LOG_PACKET_emit(1, in_q1, in_ts, in_mirror_to_console);
   }


const char *LOG_PACKET_cvcinfo(void)
   {
   return("$Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/winprojs/scirfmmon/source/log_packet.c,v 1.24 2009/01/17 22:12:37 dashley Exp $");
   }


const char *LOG_PACKET_hvcinfo(void)
   {
   return(LOG_PACKET_H_VERSION);
   }


//**************************************************************************
// $Log: log_packet.c,v $
// Revision 1.24  2009/01/17 22:12:37  dashley
// Issue where some errors not logged to console fixed.
//
// Revision 1.23  2009/01/16 17:56:16  dashley
// 0xAB data presentation completed.
//
// Revision 1.22  2009/01/16 17:46:45  dashley
// 0x03 data presentation completed.
//
// Revision 1.21  2009/01/16 17:33:39  dashley
// 0x28 data presentation completed.
//
// Revision 1.20  2009/01/16 17:06:42  dashley
// 0x94 data presentation completed.
//
// Revision 1.19  2009/01/16 05:19:25  dashley
// 0x14 data presentation completed.
//
// Revision 1.18  2009/01/16 04:49:50  dashley
// 0x95 data presentation completed.
//
// Revision 1.17  2009/01/15 21:43:11  dashley
// Edits.
//
// Revision 1.16  2009/01/15 20:11:58  dashley
// Edits.
//
// Revision 1.15  2009/01/15 19:14:38  dashley
// Edits.
//**************************************************************************
// End of $RCSfile: log_packet.c,v $.
