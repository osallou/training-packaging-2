#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
sequence=$srcdir/sequence/genbank.seq

## Check default GENBANK file reference
(../src/squizz -S -f genbank $sequence 2>&1 | grep -v GENBANK) && exit 1

## Check supported accessions
sed 's,^ACCESSION   .*$,ACCESSION   UNKNOWN,' $sequence >_tmpseq.seq
(../src/squizz -S -f genbank _tmpseq.seq 2>&1 | grep -v GENBANK) && exit 1
sed 's,^ACCESSION   .*$,ACCESSION   XXX-YYY,' $sequence >_tmpseq.seq
(../src/squizz -S -f genbank _tmpseq.seq 2>&1 | grep -v GENBANK) && exit 1

## Cleanup
rm -f _tmpseq.seq

exit 0

