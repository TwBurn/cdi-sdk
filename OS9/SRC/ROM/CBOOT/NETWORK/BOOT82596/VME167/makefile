#############################################################################
#                                                                           #
#            Copyright 1993-2000 by Microware Systems Corporation           #
#                            All Rights Reserved                            #
#                          Reproduced Under License                         #
#                                                                           #
#  This software is confidential property of Microware Systems Corporation, #
#  and is provided under license for internal development purposes only.    #
#  Reproduction, publication, distribution, or creation of derivative works #
#  in any form to any party other than the licensee is strictly prohibited, #
#  unless expressly authorized in writing by Microware Systems Corporation. #
#                                                                           #
#############################################################################
#                                                                           #
# Edition History:                                                          #
# #   Date    Comments                                                 By   #
# -- -------- -------------------------------------------------------  ---  #
#                                                                           #
#n+01 930728  MWOS'ed and filenames made DOSable                       gkm  #
# 02  930729, 930810	some defs moved in MWOS, changes accordingly   gkm  #
# 02  930810  -dCBOOT is used to distinguish between booter and driver gkm  #
#             in the newly merged i82596.h.  merged i82596.h in mwos/       #
#             os9/src/defs/inet.  dependency changed accordingly.           #
#             dittoe for ie.h.                                              #
# 03  961018  Made the defs find OS9/SRC/DEFS before SRC/DEFS because  pjw  #
#             of support for ISP v.2.0.                                     #
# 04  990106  Changed to use makeosk.tpl, added mkdir,clean, codo etc. mgh  #
# 05  011112  Fixed location of INET defs							   rry  #
#             $$                    <RELEASE_INFO>                     $$   #
#############################################################################
# makefile for INETboot:
# Boot Driver for i82596 ethernet (bootp)
#############################################################################

-bo
-mode=compat

MWOS		= ../../../../../../..
SDIR		=	..
RDIR		=	RELS

LIB			=	../../../../LIB
SCSIDEF		=	$(MWOS)/SRC/DEFS/IO/SCSI
SYSDEFS 	=	$(MWOS)/SRC/DEFS
SYSDEFSINET =   $(MWOS)/SRC/DEFS/ISP
OSDEFS		=	$(MWOS)/OS9/SRC/DEFS
INETDEFS	=	$(OSDEFS)/INET
CBDEFS		=	../../../DEFS
INBDEFS		=	../../../INETBOOT/DEFS
DASHVDEFS	=	-v=$(INBDEFS) -v=$(SCSIDEF) -v=$(CBDEFS) \
				-v=$(OSDEFS) -v=$(INETDEFS) -v=$(SYSDEFS) -v=$(SYSDEFSINET)

BLIB		=	bp_167_82596.l

FILES		=	boot82596.r init.r term.r xmit.r recv.r machdep.r misc.r \
				i82596.r addr.r
COMDEFS		=	$(SCSIDEF)/scsidmod.h $(SCSIDEF)/cmdblk.h 
DEFS		=	$(INETDEFS)/ie.h $(INETDEFS)/i82596.h $(INETDEFS)/if162167.h \
				$(INBDEFS)/inetboot_p.h $(COMDEFS)

include $(MWOS)/MAKETMPL/makeosk.tpl

CFLAGS		=	-qst=$(TEMP) $(DASHVDEFS) -dCBOOT -dif167 -die167 -o=0
RFLAGS		=	-q -o=0

$(BLIB) : makdir $(LIB)/$(BLIB)
	$(COMMENT)

$(LIB)/$(BLIB) : $(FILES)
	-$(CODO) $@
	-$(DEL)  $@
	$(CHD) $(RDIR); $(MERGE) $(FILES) $(REDIR_OUT)../$@

$(FILES) : $(DEFS)
machdep.r: ./machdep.c
addr.r: ./addr.c


makdir: $(RDIR)

$(RDIR):
	-$(MAKDIR) $@
 
clean: .
	-$(DEL) $(RDIR)/boot82596.r
	-$(DEL) $(RDIR)/init.r
	-$(DEL) $(RDIR)/term.r
	-$(DEL) $(RDIR)/xmit.r
	-$(DEL) $(RDIR)/recv.r 
	-$(DEL) $(RDIR)/machdep.r
	-$(DEL) $(RDIR)/misc.r 
	-$(DEL) $(RDIR)/i82596.r
	-$(DEL) $(RDIR)/addr.r

purge: .
	-$(CODO) $(LIB)/$(BLIB)
	-$(DEL)  $(LIB)/$(BLIB)

