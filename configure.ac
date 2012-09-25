# Process this file with autoconf to produce a configure script.
AC_INIT([squizz],[0.99a])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([lib/config.h])
AC_CONFIG_MACRO_DIR([m4])

# Disable unneeded CXX/F77 checks for libtool 1.5.x
m4_defun([_LT_AC_LANG_CXX_CONFIG], [:])
m4_defun([_LT_AC_LANG_F77_CONFIG], [:])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_LIBTOOL
AC_PROG_YACC
AM_PROG_LEX
AC_CHECK_PROG(POD2MAN, pod2man, pod2man, :)
AC_CHECK_PROG(POD2HTM, pod2html, pod2html, :)

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdlib.h string.h strings.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_CHECK_SIZEOF([uint64_t])
AC_STRUCT_TM
AC_TYPE_OFF_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_FSEEKO
#AC_FUNC_MALLOC
#AC_FUNC_REALLOC
AC_FUNC_STRFTIME
AC_CHECK_FUNCS([localtime_r strcasecmp strchr strdup strerror])

# Add 64-bits file support on some hosts
AC_DEFINE([_FILE_OFFSET_BITS], [64],
          [Define to 64 for large file support on some hosts])

AC_CONFIG_FILES([Makefile lib/Makefile src/Makefile data/Makefile
                 doc/Makefile test/Makefile])
AC_OUTPUT
