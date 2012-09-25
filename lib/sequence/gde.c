/* gde.c - GDE sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>

#include "sequence.h"
#include "sequence/gde.h"


/* Functions prototypes */
extern sequence_t *gdey_parse(FILE *);
extern int gdey_check(FILE *);


/* Parse GDE sequence */
sequence_t *gde_parse(FILE *f) {
  sequence_t *seq;

  seq = gdey_parse(f);

  return seq; }


/* Checks GDE sequence */
int gde_check(FILE *f) {
  int i;

  i = gdey_check(f);

  return i; }


/* Print GDE sequence */
void gde_print(FILE *f, sequence_t *seq) {
  char *p, c;
  const char *q;
  int max;
  long l;
  seqtyp_t typ;

  if (seq == NULL) { return; }

  typ = sequence_type(seq->str);
  c = (typ == SEQTYP_PRO) ? '%' : '#';

  /* Header */
  q = (seq->nam != NULL) ? seq->nam : "unknown";
  (void)fprintf(f, "%c%s\n", c, q);

  /* Sequence */
  p = seq->str; max = 80;
  while (*p) {
    l = p - seq->str;
    if (l % max == 0 && l > 0) { (void)fputc('\n', f); }
    if (*p == '*') { p++; continue; }
    (void)fputc(*p, f);
    p++; }
  l = p - seq->str;
  if (l % max != 0) { (void)fputc('\n', f); }

  return; }
