
AM_CPPFLAGS = -I$(srcdir)/../lib

bin_PROGRAMS = squizz
noinst_HEADERS = $(HDR)

squizz_SOURCES = squizz.c $(SRC)
squizz_LDADD = ../lib/libbioali.la ../lib/libbioseq.la

SRC = format.c
HDR = format.h
