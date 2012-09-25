/* raw.c - RAW sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>

#include "sequence.h"
#include "sequence/raw.h"


/* Functions prototypes */
extern sequence_t *rawy_parse(FILE *);
extern int rawy_check(FILE *);


/* Parse RAW sequence */
sequence_t *raw_parse(FILE *f) {
  sequence_t *seq;

  seq = rawy_parse(f);

  return seq; }


/* Checks RAW sequence */
int raw_check(FILE *f) {
  int i;

  i = rawy_check(f);

  return i; }


/* Print RAW sequence */
void raw_print(FILE *f, sequence_t *seq) {
  char *p;

  if (seq == NULL) { return; }

  p = seq->str;
  while (*p) {
    (void)fputc(*p, f);
    p++; }
  (void)fputc('\n', f);

  return; }
