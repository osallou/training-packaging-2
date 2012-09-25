/* nexusi.c - NEXUSI alignment functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <string.h>
#endif
#include <ctype.h>

#include "align.h"
#include "align/nexusi.h"
#include "sequence.h"
#include "sequence/utils.h"


/* Functions prototypes */
extern int nexusiy_check(FILE *);
extern align_t *nexusiy_parse(FILE *);


/* Checks NEXUSI alignment */
int nexusi_check(FILE *f) {
  int i;

  i = nexusiy_check(f);

  return i; }


/* Parse NEXUSI alignment */
align_t *nexusi_parse(FILE *f) {
  align_t *ali;

  ali = nexusiy_parse(f);

  return ali; }


/* Print NEXUSI alignment */
void nexusi_print(FILE *f, align_t *ali) {
  char *p, c;
  const char *q;
  size_t i, j, m, n;
  size_t l, len, nam, seq, blk;
  sequence_t **s;
  seqtyp_t t;

  if (ali == NULL) { return; }

  s = ali->seq; len = (*s)->strlen;

  t = sequence_type((*s)->str);
  nam = 0; seq = 60;
  n = 0; while (s && *s) {
    p = (*s)->nam; l = 0; blk = 0;
    while (*p) {
      blk |= (isspace((unsigned char)*p)) ? 1 : 0;
      l++; p++; }
    l += 2 * blk;
    if (nam < l) { nam = l; }
    n++; s++; }

  /* Header */
  (void)fprintf(f, "#NEXUS\n");

  /* FIXME: Sequences (gap, missing) */
  i = 0; m = n; n = len / seq; if (len % seq) { n++; }
  (void)fprintf(f, "begin data;\n");
  (void)fprintf(f, "  dimensions ntax=%lu nchar=%lu;\n", m, len);
  q = (t == SEQTYP_PRO) ? "protein" : "nucleic";
  (void)fprintf(f, "  format datatype=%s interleave;\n", q);
  (void)fprintf(f, "  matrix\n");
  while (n--) {
    s = ali->seq;
    if (i != 0) {
      (void)fputc('\n', f); }
    while (s && *s) {
      /* Name */
      p = (*s)->nam; l = 0; blk = 0;
      while (*p) {
	blk |= (isspace((unsigned char)*p)) ? 1 : 0; l++; p++; }
      l += 2 * blk; p = (blk) ? "'" : "";
      (void)fprintf(f, "%s%s%s%*s  ", p, (*s)->nam, p, (int)(nam - l), "");
      /* Sequence */
      p = (*s)->str + i; j = seq;
      while (j && *p) {
	c = *p;
	if (c == '*') { c = 'X'; }
	if (c == '~') { c = '.'; }
	(void)fputc(c, f);
	j--; p++; }
      (void)fputc('\n', f);
      s++; }
    i += seq; }
  (void)fprintf(f, "  ;\n");
  (void)fprintf(f, "endblock;\n");

  return; }

