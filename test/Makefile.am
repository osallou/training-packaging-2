
TESTS = squizz.sh fmtseq.sh fmtali.sh convseq.sh convali.sh \
	$(TESTS_SEQS) align.sh $(TESTS_ALIS) count.sh

TESTS_ALIS = clustal.sh mega.sh msf.sh nexus.sh phylipi.sh phylips.sh \
	stockholm.sh
TESTS_SEQS = embl.sh genbank.sh ig.sh raw.sh sprot.sh

XFAIL_TESTS =

DATAS = $(ALIS) $(SEQS)

ALIS = align/clustal.seq align/fasta.seq align/mega.seq align/msf.seq \
	align/nexusi.seq align/phylipi.seq align/phylips.seq align/stock.seq

SEQS = sequence/embl.seq sequence/fasta.seq sequence/gde.seq \
	sequence/genbank.seq sequence/genpept.seq sequence/gcg.seq \
	sequence/ig.seq sequence/nbrf.seq sequence/pir.seq sequence/raw.seq \
	sequence/refseqn.seq sequence/refseqp.seq sequence/sprot.seq

EXTRA_DIST = $(TESTS) $(DATAS)
