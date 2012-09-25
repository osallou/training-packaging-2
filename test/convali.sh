#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

tmpseq=_convert.seq

## Alignment files location
alidir=$srcdir/align
seqlist='clustal.seq fasta.seq msf.seq nexusi.seq phylipi.seq phylips.seq stock.seq'

## Checks CLUSTAL-like sequence
for f in $seqlist; do
  ../src/squizz -c clustal $alidir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v CLUSTAL) && exit 1
done

## Checks FASTA-like sequence
for f in $seqlist; do
  ../src/squizz -c fasta $alidir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v FASTA) && exit 1
done

## Checks MEGA-like sequence
for f in $seqlist; do
  ../src/squizz -c mega $alidir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v MEGA) && exit 1
done

## Checks MSF-like sequence
for f in $seqlist; do
  ../src/squizz -c msf $alidir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v MSF) && exit 1
done

## Checks NEXUS-like sequence
for f in $seqlist; do
  ../src/squizz -c nexus $alidir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v NEXUS) && exit 1
done

## Checks PHYLIP-like sequence
for f in $seqlist; do
  ../src/squizz -c phylipi $alidir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v PHYLIPI) && exit 1
  ../src/squizz -c phylips $alidir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v PHYLIPS) && exit 1
done

## Checks STOCKHOLM-like sequence
for f in $seqlist; do
  ../src/squizz -c stockholm $alidir/$f >$tmpseq 2>/dev/null
  (../src/squizz $tmpseq 2>&1 | grep -v STOCKHOLM) && exit 1
done

## Clean temp files
rm -f $tmpseq

exit 0

