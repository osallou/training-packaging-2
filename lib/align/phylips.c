/* phylips.c - PHYLIPS alignment functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "align.h"
#include "align/phylip.h"
#include "align/phylips.h"


/* Functions prototypes */
extern int phylipsy_check(FILE *);
extern align_t *phylipsy_parse(FILE *);


/* Check PHYLIPS alignment */
int phylips_check(FILE *f) {
  int i;

  i = phylipsy_check(f);

  return i; }


/* Parse PHYLIPS alignment */
align_t *phylips_parse(FILE *f) {
  align_t *ali;

  ali = phylipsy_parse(f);

  return ali; }


/* Print PHYLIPS alignment */
void phylips_print(FILE *f, align_t *ali) {
  const char *p;
  char *q, c;
  int i, j;
  size_t n, len;
  sequence_t **s;

  if (ali == NULL) { return; }

  s = ali->seq; len = (*s)->strlen; n = 0;
  while (s && *s) { n++; s++; }

  /* Print alignment header */
  (void)fprintf(f, " %5lu %5lu\n", n, len);

  /* Process all sequences */
  s = ali->seq;
  while (s && *s) {
    n = len / 60; if (len % 60) { n++; }
    i = 0;
    while (n--) {
      /* Name */
      q = (i == 0) ? phylip_fixnam((*s)->nam) : "";
      (void)fprintf(f, "%-10.10s", q);
      if (*q) { free(q); }
      /* Sequence */
      p = (*s)->str + i; j = 60;
      while (j && *p) {
	c = *p;
	if (c == '~' || c == '.') { c = '-'; }
	(void)fputc(c, f);
	j--; p++; }
      (void)fputc('\n', f);
      i += 60; }
    s++; }

  return; }
