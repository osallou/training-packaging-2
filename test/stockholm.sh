#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Inits
align=$srcdir/align/stock.seq

## Check default STOCKHOLM file reference
(../src/squizz -A -f stockholm $align 2>&1 | grep -v STOCKHOLM) && exit 1

## Check without empty line after header
echo "# STOCKHOLM 1.0" >_tmpali.seq
tail -n +3 $align >>_tmpali.seq
(../src/squizz -A -f stockholm _tmpali.seq 2>&1 | grep -v STOCKHOLM) && exit 1

## Be robust against invalid sequence lines
sed 's/  //' $align >_tmpali.seq
(../src/squizz -A -f stockholm _tmpali.seq 2>&1 | grep STOCKHOLM) && exit 1

## Allow sequence names with a single char
sed 's/^MALK_ECOLI/M         /' $align >_tmpali.seq
(../src/squizz -A -f stockholm _tmpali.seq 2>&1 | grep -v STOCKHOLM) && exit 1

## Cleanup
rm -f _tmpali.seq

exit 0

