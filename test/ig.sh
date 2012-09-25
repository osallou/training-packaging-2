#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
sequence=$srcdir/sequence/ig.seq

## Check default IG file reference
(../src/squizz -S -f ig $sequence 2>&1 | grep -v IG) && exit 1

## Check without newline at EOF
sed -e '$d' $sequence >_tmpseq.seq
tail -n 1 $sequence | tr -d '\n' >>_tmpseq.seq
(../src/squizz -S -f ig _tmpseq.seq 2>&1 | grep -v IG) && exit 1

## Cleanup
rm -f _tmpseq.seq

exit 0

