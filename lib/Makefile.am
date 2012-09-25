
AUTOMAKE_OPTIONS = subdir-objects

AM_YFLAGS = -d -p `basename $* | sed 's,y$$,,'`
AM_LFLAGS = -s -P`basename $* | sed 's,l$$,,'` -olex.yy.c

lib_LTLIBRARIES = libbioseq.la libbioali.la

nobase_pkginclude_HEADERS = $(SEQ_HDR) $(ALI_HDR)
noinst_HEADERS = $(EXT_HDR) $(SE2_HDR) $(AL2_HDR)

libbioseq_la_SOURCES = $(SEQ_SRC) $(SE2_SRC) $(EXT_SRC)
libbioali_la_SOURCES = $(ALI_SRC) $(AL2_SRC)

SEQ_SRC = sequence.c $(SEQFMT_SRC)
SEQ_HDR = sequence.h $(SEQFMT_HDR)
SE2_SRC = sequence/parse.c sequence/protein.c sequence/utils.c
SE2_HDR = sequence/parse.h sequence/protein.h sequence/utils.h

ALI_SRC = align.c $(ALIFMT_SRC)
ALI_HDR = align.h $(ALIFMT_HDR)
AL2_SRC = align/parse.c align/phylip.c
AL2_HDR = align/parse.h align/phylip.h

SEQFMT_SRC = $(EMB_SRC) $(FAS_SRC) $(GBK_SRC) $(GCG_SRC) $(GDE_SRC) $(IG_SRC) \
	$(NBR_SRC) $(PIR_SRC) $(RAW_SRC) $(SPT_SRC)
SEQFMT_HDR = $(EMB_HDR) $(FAS_HDR) $(GBK_HDR) $(GCG_HDR) $(GDE_HDR) $(IG_HDR) \
	$(NBR_HDR) $(PIR_HDR) $(RAW_HDR) $(SPT_HDR)
ALIFMT_SRC = $(CLU_SRC) $(FA2_SRC) $(MEG_SRC) $(MSF_SRC) $(NXI_SRC) \
	$(PHI_SRC) $(PHS_SRC) $(STO_SRC)
ALIFMT_HDR = $(CLU_HDR) $(FA2_HDR) $(MEG_HDR) $(MSF_HDR) $(NXI_HDR) \
	$(PHI_HDR) $(PHS_HDR) $(STO_HDR)

CLU_SRC = align/clustal.c align/clustaly.y align/clustall.l
CLU_HDR = align/clustal.h
EMB_SRC = sequence/embl.c sequence/embly.y sequence/embll.l
EMB_HDR = sequence/embl.h
FAS_SRC = sequence/fasta.c sequence/fastay.y sequence/fastal.l
FAS_HDR = sequence/fasta.h
FA2_SRC = align/fasta2.c
FA2_HDR = align/fasta2.h
GBK_SRC = sequence/genbank.c sequence/genbanky.y sequence/genbankl.l
GBK_HDR = sequence/genbank.h
GCG_SRC = sequence/gcg.c sequence/gcgy.y sequence/gcgl.l
GCG_HDR = sequence/gcg.h
GDE_SRC = sequence/gde.c sequence/gdey.y sequence/gdel.l
GDE_HDR = sequence/gde.h
 IG_SRC = sequence/ig.c sequence/igy.y sequence/igl.l
 IG_HDR = sequence/ig.h
MEG_SRC = align/mega.c align/megay.y align/megal.l
MEG_HDR = align/mega.h
MSF_SRC = align/msf.c align/msfy.y align/msfl.l
MSF_HDR = align/msf.h
NBR_SRC = sequence/nbrf.c sequence/nbrfy.y sequence/nbrfl.l
NBR_HDR = sequence/nbrf.h
NXI_SRC = align/nexusi.c align/nexusiy.y align/nexusil.l
NXI_HDR = align/nexusi.h
PHI_SRC = align/phylipi.c align/phylipiy.y align/phylipil.l
PHI_HDR = align/phylipi.h
PHS_SRC = align/phylips.c align/phylipsy.y align/phylipsl.l
PHS_HDR = align/phylips.h
PIR_SRC = sequence/pir.c sequence/piry.y sequence/pirl.l
PIR_HDR = sequence/pir.h
RAW_SRC = sequence/raw.c sequence/rawy.y sequence/rawl.l
RAW_HDR = sequence/raw.h
SPT_SRC = sequence/sprot.c sequence/sproty.y sequence/sprotl.l
SPT_HDR = sequence/sprot.h
STO_SRC = align/stock.c align/stocky.y align/stockl.l
STO_HDR = align/stock.h

EXT_SRC = extern/error.c extern/text.c extern/file.c
EXT_HDR = extern/error.h extern/text.h extern/file.h


## Maintainer parano check

LINTDEFS = $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS)

parano:
	$(LINT) $(LINTFLAGS) $(LINTDEFS) `find . -name '*.c'`

