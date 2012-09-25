#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Sequence files location
srcdir=$srcdir/align

## Checks CLUSTAL-like sequence
seqlist='clustal.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v CLUSTAL) && exit 1
  (../src/squizz -s $srcdir/$f 2>&1 | grep -v CLUSTAL) && exit 1
done

## Checks FASTA-like sequence
seqlist='fasta.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v FASTA) && exit 1
  (../src/squizz -s $srcdir/$f 2>&1 | grep -v FASTA) && exit 1
done

## Checks MEGA-like sequence
seqlist='mega.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v MEGA) && exit 1
  (../src/squizz -s $srcdir/$f 2>&1 | grep -v MEGA) && exit 1
done

## Checks MSF-like sequence
seqlist='msf.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v MSF) && exit 1
  (../src/squizz -s $srcdir/$f 2>&1 | grep -v MSF) && exit 1
done

## Checks NEXUS-like sequence
seqlist='nexusi.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v NEXUS) && exit 1
  (../src/squizz -s $srcdir/$f 2>&1 | grep -v NEXUS) && exit 1
done

## Checks PHYLIP-like sequence
seqlist='phylipi.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v PHYLIPI) && exit 1
  (../src/squizz -s $srcdir/$f 2>&1 | grep -v PHYLIPI) && exit 1
done
seqlist='phylips.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v PHYLIPS) && exit 1
  (../src/squizz -s $srcdir/$f 2>&1 | grep -v PHYLIPS) && exit 1
done

## Checks STOCKHOLM-like sequence
seqlist='stock.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v STOCKHOLM) && exit 1
  (../src/squizz -s $srcdir/$f 2>&1 | grep -v STOCKHOLM) && exit 1
done

exit 0

