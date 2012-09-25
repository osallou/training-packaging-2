#! /bin/sh

## Verbose mode
test "x$VERBOSE" = xx && set -x

## Check options/formats list
../src/squizz -h 2>/dev/null || exit 1
../src/squizz -l >/dev/null || exit 1

## Check unsupported formats
../src/squizz -c FOOBAR /dev/null 2>/dev/null && exit 1
../src/squizz -f FOOBAR /dev/null 2>/dev/null && exit 1

## Check options conflicts
../src/squizz -A -S /dev/null 2>/dev/null && exit 1
../src/squizz -s -c raw /dev/null 2>/dev/null && exit 1
../src/squizz -n /dev/null 2>/dev/null && exit 1
../src/squizz -S -n -s /dev/null 2>/dev/null && exit 1

## Check for non-regular input file
test -c /dev/null && ../src/squizz /dev/null 2>/dev/null && exit 1
test -d /tmp && ../src/squizz /tmp 2>/dev/null && exit 1

exit 0

