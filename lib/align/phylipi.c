/* phylipi.c - PHYLIPI (interleaved) alignment functions */

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
#include "align/phylipi.h"


/* Functions prototypes */
extern int phylipiy_check(FILE *);
extern align_t *phylipiy_parse(FILE *);


/* Check PHYLIPI alignment */
int phylipi_check(FILE *f) {
  int i;

  i = phylipiy_check(f);

  return i; }


/* Parse PHYLIPI alignment */
align_t *phylipi_parse(FILE *f) {
  align_t *ali;

  ali = phylipiy_parse(f);

  return ali; }


/* Print PHYLIPI alignment */
void phylipi_print(FILE *f, align_t *ali) {
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

  /* Process sequences */
  i = 0;
  n = len / 60; if (len % 60) { n++; }
  while (n--) {
    if (i != 0) { (void)fputc('\n', f); }
    s = ali->seq;
    while (s && *s) {
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
      s++; }
    i += 60; }

  return; }
