#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Sequence files location
srcdir=$srcdir/sequence

## Checks EMBL-like sequence
seqlist='embl.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v EMBL) && exit 1
done

## Checks FASTA-like sequence
seqlist='fasta.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v FASTA) && exit 1
done

## Checks GDE-like sequence
seqlist='gde.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v GDE) && exit 1
done

## Checks GENBANK-like sequence
seqlist='genbank.seq genpept.seq refseqn.seq refseqp.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v GENBANK) && exit 1
done

## Checks GCG-like sequence
seqlist='gcg.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v GCG) && exit 1
done

## Checks IG-like sequence
seqlist='ig.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v IG) && exit 1
done

## Checks NBRF-like sequence
seqlist='nbrf.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v NBRF) && exit 1
done

## Checks PIR-like (CODATA) sequence
seqlist='pir.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v PIR) && exit 1
done

## Checks RAW-like sequence
seqlist='raw.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v RAW) && exit 1
done

## Checks SWISSPROT-like sequence
seqlist='sprot.seq'
for f in $seqlist; do
  (../src/squizz $srcdir/$f 2>&1 | grep -v SWISSPROT) && exit 1
done

exit 0

