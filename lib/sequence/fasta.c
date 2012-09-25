/* fasta.c - FASTA sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>

#include "sequence.h"
#include "sequence/fasta.h"


/* Functions prototypes */
extern sequence_t *fastay_parse(FILE *);
extern int fastay_check(FILE *);


/* Parse FASTA sequence */
sequence_t *fasta_parse(FILE *f) {
  sequence_t *seq;

  seq = fastay_parse(f);

  return seq; }


/* Check FASTA formatted sequence */
int fasta_check(FILE *f) {
  int i;

  i = fastay_check(f);

  return i; }


/* Print FASTA sequence */
void fasta_print(FILE *f, sequence_t *seq) {
  char *p, c;
  const char *q;
  int max;
  long l;

  if (seq == NULL) { return; }

  /* Header */
  q = (seq->nam != NULL) ? seq->nam : "unknown";
  (void)fprintf(f, ">%s", q);
  if (seq->dsc) { (void)fprintf(f, " %s", seq->dsc); }
  (void)fputc('\n', f);

  /* Sequence */
  p = seq->str; max = 80;
  while (*p) {
    l = p - seq->str;
    if (l % max == 0 && l > 0) { (void)fputc('\n', f); }
    c = *p;
    if (c == '~' || c == '.' || c == '?') { c = '-'; }
    (void)fputc(c, f);
    p++; }
  (void)fputc('\n', f);

  return; }
