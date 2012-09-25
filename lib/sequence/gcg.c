/* gcg.c - GCG sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <string.h>
#endif
#include <time.h>
#include <ctype.h>

#include "sequence.h"
#include "sequence/gcg.h"


#define crc_t unsigned long


/* Functions prototypes */
extern sequence_t *gcgy_parse(FILE *);
extern int gcgy_check(FILE *);
crc_t gcg_crc(char *);


/* Parse GCG sequence */
sequence_t *gcg_parse(FILE *f) {
  sequence_t *seq;

  seq = gcgy_parse(f);

  return seq; }


/* Checks GCG sequence */
int gcg_check(FILE *f) {
  int i;

  i = gcgy_check(f);

  return i; }


/* Print GCG sequence */
void gcg_print(FILE *f, sequence_t *seq) {
  char *p, c, d[255];
  const char *q;
  float v;
  long l;
  time_t tt;
  struct tm ts;
  crc_t crc;
  seqtyp_t t;

  if (seq == NULL) { return; }

  t = sequence_type(seq->str);
  d[0] = '\0'; tt = time(NULL);
  (void)localtime_r(&tt, &ts);
  (void)strftime(d, 100, "%B %e, %Y %H:%M", &ts);

  /* FIXME: Header (comment, annots, ...) */
  c = (t == SEQTYP_PRO) ? 'A' : 'N'; v = 1.0;
  (void)fprintf(f, "!!%cA_SEQUENCE %.1f\n", c, v);
  c = (t == SEQTYP_PRO) ? 'P' : 'N';
  q = "unknown"; crc = gcg_crc(seq->str);
  (void)fprintf(f, "%s  Length: %lu  %s", q, seq->strlen, d);
  (void)fprintf(f, "  Type: %c  Check: %04lu", c, crc);
  (void)fprintf(f, " ..\n");

  /* Sequence */
  p = seq->str;
  while (*p) {
    l = p - seq->str;
    if (l % 50 == 0 && l > 0) {
      (void)fputc('\n', f); }
    if (l % 50 == 0) {
      (void)fprintf(f, "\n%8li  ", l+1); }
    if (l % 10 == 0 && l % 50 != 0) {
      (void)fputc(' ', f); }
    if (*p == '*') { p++; continue; }
    (void)fputc(*p, f);
    p++; }
  (void)fputc('\n', f);
  (void)fputc('\n', f);

  return; }


/* Calculate GCG sequence CRC */
crc_t gcg_crc(char *str) {
  char *p;
  int i;
  crc_t crc;

  crc = 0; i = 0; p = str;
  while (p && *p) {
    crc += ((i % 57) + 1) * toupper((unsigned char)*p);
    i++; p++; }
  crc %= 10000;

  return crc; }
