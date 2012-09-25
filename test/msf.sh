#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
align=$srcdir/align/msf.seq

## Check default MSF file reference
(../src/squizz -A -f msf $align 2>&1 | grep -v MSF) && exit 1

## Cleanup
rm -f _tmpali.seq

exit 0

