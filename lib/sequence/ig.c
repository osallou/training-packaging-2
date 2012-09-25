/* ig.c - IG sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>

#include "sequence.h"
#include "sequence/ig.h"


/* Functions prototypes */
extern sequence_t *igy_parse(FILE *);
extern int igy_check(FILE *);


/* Parse IG sequence */
sequence_t *ig_parse(FILE *f) {
  sequence_t *seq;

  seq = igy_parse(f);

  return seq; }


/* Checks IG sequence */
int ig_check(FILE *f) {
  int i;

  i = igy_check(f);

  return i; }


/* Print IG sequence */
void ig_print(FILE *f, sequence_t *seq) {
  const char *p, *q, *z;
  int max;
  long i, l;

  if (seq == NULL) { return; }

  /* Inits */
  max = 80;

  /* Comment */
  p = (seq->dsc != NULL) ? seq->dsc : "comment";
  while (p && *p) {
    while (*p && *p == ' ') { p++; }
    (void)fprintf(f, "; ");
    q = p; i = 0;
    while (*q && q - p < max - 2) { q++; }
    z = q;
    while (/*CONSTCOND*/1) {
      /* Do not split words */
      while (q - p > 0 && *q && *q != ' ' && i == 0) { q--; continue; }
      /* Split words longer than max-2 */
      while (q - p > 0 && *q && *q != '-' && i == 1) { q--; continue; }
      if (q == p) {
	q = z;
	if (i == 1) { break; }
	i = 1; continue; }
      /* Check for trailing '-' */
      if (*q == '-' && q - p + 1 > max - 2) { q--; continue; }
      if (*q == '-') { q++; }
      break; }
    while (*p && q - p > 0) {
      (void)fputc(*p, f); p++; }
    if (*p == '\0') {
      (void)fputc('.', f); }
    (void)fputc('\n', f);
    p = q; }

  /* Name */
  p = (seq->nam != NULL) ? seq->nam : "unknown";
  (void)fprintf(f, "%s\n", p);

  /* Sequence */
  p = seq->str;
  while (*p) {
    l = p - seq->str;
    if (l && l % max == 0) {
      (void)fputc('\n', f); }
    if (*p == '*') { p++; continue; }
    (void)fputc(*p, f);
    p++; }
  /* FIXME: Sequence type is forced to linear */
  (void)fputc('1', f);
  (void)fputc('\n', f);

  return; }
