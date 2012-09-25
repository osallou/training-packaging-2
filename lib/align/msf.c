/* msf.c - MSF alignment functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif
#include <ctype.h>
#include <time.h>

#include "align.h"
#include "align/msf.h"
#include "sequence.h"
#include "sequence/utils.h"


#define crc_t unsigned long


/* Functions prototypes */
extern int msfy_check(FILE *);
extern align_t *msfy_parse(FILE *);
extern crc_t gcg_crc(char *);
crc_t msf_crc(align_t *);


/* Checks MSF alignment */
int msf_check(FILE *f) {
  int i;

  i = msfy_check(f);

  return i; }


/* Parse MSF alignment */
align_t *msf_parse(FILE *f) {
  align_t *ali;

  ali = msfy_parse(f);

  return ali; }


/* Print MSF alignment */
void msf_print(FILE *f, align_t *ali) {
  char *p, *b, *e, *nam, c, d[255];
  const char *q;
  float v;
  size_t l, i, j, n, len, nlen;
  time_t tt;
  struct tm ts;
  crc_t crc;
  sequence_t **s;
  seqtyp_t t;

  if (ali == NULL) { return; }

  s = ali->seq; t = sequence_type((*s)->str);
  len = (*s)->strlen;
  crc = msf_crc(ali);
  d[0] = '\0'; tt = time(NULL);
  (void)localtime_r(&tt, &ts);
  (void)strftime(d, 100, "%B %e, %Y %H:%M", &ts);

  /* Header */
  v = 1.0; c = (t == SEQTYP_PRO) ? 'A' : 'N';
  (void)fprintf(f, "!!%cA_MULTIPLE_ALIGNMENT %.1f\n", c, v);
  c = (t == SEQTYP_PRO) ? 'P' : 'N'; q = "unknown";
  (void)fprintf(f, " %s  MSF: %lu", q, len);
  (void)fprintf(f, "  Type: %c  %s  Check: %04lu", c, d, crc);
  (void)fprintf(f, " ..\n");

  /* Names */
  (void)fputc('\n', f);
  s = ali->seq; nlen = 0;
  while (s && *s) {
    l = strlen((*s)->nam);
    if (l > nlen) { nlen = l; }
    s++; }
  if (nlen > 39) { nlen = 39; }
  l = (nlen < 15) ? 15 : nlen;
  s = ali->seq;
  while (s && *s) {
    crc = gcg_crc((*s)->str); nam = sequence_fixnam((*s)->nam);
    (void)fprintf(f, " Name: %-*.*s", (int)l, (int)l, nam);
    (void)fprintf(f, "  Len: %5lu", len);
    (void)fprintf(f, "  Check: %4lu", crc);
    (void)fprintf(f, "  Weight:  %2.2f\n", 1.0);
    free(nam); s++; }
  (void)fputc('\n', f);
  (void)fprintf(f, "//\n");

  /* Sequences */
  i = 0; n = len / 50; if (len % 50) { n++; }
  while (n--) {
    (void)fputc('\n', f);
    s = ali->seq;
    p = (*s)->str + i; j = 50;
    while (j && *p) { j--; p++; }
    (void)fprintf(f, "%*s  ", (int)nlen, "");
    if (j != 0) {
      (void)fprintf(f, "%lu\n", i+1); }
    else {
      (void)fprintf(f, "%-27lu%27lu\n", i+1, i+50);
    }
    while (s && *s) {

      /* Name */
      p = sequence_fixnam((*s)->nam); l = strlen(p); j = nlen;
      (void)fprintf(f, "%*s%s  ", (int)(j - l), "", p);
      free(p);

      /* Sequence */
      b = (*s)->str; while (*b && (*b == '-' || *b == '?')) b++;
      e = p = (*s)->str; while (*e) e++; e--;
      while (e > p && (*e == '-' || *e == '?')) e--;
      p = (*s)->str + i; j = 0;
      while (*p && j < 50) {
	if (j && j % 10 == 0) { (void)fputc(' ', f); }
	c = *p;
	if (c == '-' || c == '?') {
	  c = '.'; if (p < b || p > e) c = '~'; }
	(void)fputc(c, f);
	p++; j++; }
      (void)fputc(' ', f);
      (void)fputc('\n', f);
      s++; }
    i += 50; }
  (void)fputc('\n', f);

  return; }


/* MSF sequence CRC */
crc_t msf_crc(align_t *ali) {
  crc_t crc;
  sequence_t **s;

  crc = 0;

  if (ali == NULL) { return crc; }

  s = ali->seq;
  while (s && *s) {
    crc += gcg_crc((*s)->str);
    s++; }
  crc %= 10000;

  return crc; }
