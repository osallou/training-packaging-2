#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

tmpseq=_convert.seq

## Sequence files location
seqdir=$srcdir/sequence
seqlist='embl.seq fasta.seq gcg.seq gde.seq genbank.seq genpept.seq ig.seq nbrf.seq pir.seq raw.seq refseqn.seq refseqp.seq sprot.seq'

## Checks EMBL-like sequence
for f in $seqlist; do
  ../src/squizz -c embl $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v EMBL) && exit 1
done

## Checks FASTA-like sequence/alignment
for f in $seqlist; do
  ../src/squizz -c fasta $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v FASTA) && exit 1
done

## Checks GCG-like sequence
for f in $seqlist; do
  ../src/squizz -c gcg $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v GCG) && exit 1
done

## Checks GDE-like sequence
for f in $seqlist; do
  ../src/squizz -c gde $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v GDE) && exit 1
done

## Checks GENBANK-like sequence
for f in $seqlist; do
  ../src/squizz -c genbank $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v GENBANK) && exit 1
done

## Checks IG-like sequence
for f in $seqlist; do
  ../src/squizz -c ig $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v IG) && exit 1
done

## Checks NBRF-like sequence
for f in $seqlist; do
  ../src/squizz -c nbrf $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v NBRF) && exit 1
done

## Checks PIR-like sequence
for f in $seqlist; do
  ../src/squizz -c pir $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v PIR) && exit 1
done

## Checks RAW-like sequence
for f in $seqlist; do
  ../src/squizz -c raw $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v RAW) && exit 1
done

## Checks SWISSPROT-like sequence
for f in $seqlist; do
  ../src/squizz -c swissprot $seqdir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v SWISSPROT) && exit 1
done

## Clean temp files
rm -f $tmpseq

exit 0

