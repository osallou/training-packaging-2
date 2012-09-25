#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
sequence=$srcdir/sequence/raw.seq

## Check default RAW file reference
(../src/squizz -S -f raw $sequence 2>&1 | grep -v RAW) && exit 1

## Check sequence with gaps
sed 's/gggg/----/' $sequence >_tmpseq.seq
(../src/squizz -S -f raw _tmpseq.seq 2>&1 | grep -v RAW) && exit 1

## Cleanup
rm -f _tmpseq*.seq

exit 0

