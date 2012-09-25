/* nbrf.c - NBRF sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>

#include "sequence.h"
#include "sequence/nbrf.h"


/* Functions prototypes */
extern sequence_t *nbrfy_parse(FILE *);
extern int nbrfy_check(FILE *);


/* Parse NBRF sequence */
sequence_t *nbrf_parse(FILE *f) {
  sequence_t *seq;

  seq = nbrfy_parse(f);

  return seq; }


/* Check NBRF sequence */
int nbrf_check(FILE *f) {
  int i;

  i = nbrfy_check(f);

  return i; }


/* Print NBRF sequence */
void nbrf_print(FILE *f, sequence_t *seq) {
  char *p;
  const char *q, *r;
  int max;
  long l;
  seqtyp_t t;

  if (seq == NULL) { return; }

  t = sequence_type(seq->str);

  /* Header */
  q = (t == SEQTYP_PRO) ? "P1" : "DL";
  r = (seq->nam != NULL) ? seq->nam : "unknown";
  (void)fprintf(f, ">%s;%s\n", q, r);
  if (seq->dsc) { (void)fprintf(f, "%s", seq->dsc); }
  (void)fputc('\n', f);

  /* Sequence */
  p = seq->str; max = 80;
  while (*p) {
    l = p - seq->str;
    if (l % max == 0 && l > 0) { (void)fputc('\n', f); }
    if (*p == '*' && *(p+1) == '\0') { break; }
    (void)fputc(*p, f);
    p++; }
  l = p - seq->str;
  (void)fputc('*', f);
  (void)fputc('\n', f);

  return; }
