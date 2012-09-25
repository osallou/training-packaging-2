/* clustal.c - CLUSTAL alignment functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif
#include <ctype.h>

#include "align.h"
#include "align/clustal.h"
#include "sequence.h"


/* Functions prototypes */
extern int clustaly_check(FILE *);
extern align_t *clustaly_parse(FILE *);
char *clustal_conserv(align_t *);


/* Checks CLUSTAL alignment */
int clustal_check(FILE *f) {
  int i;

  i = clustaly_check(f);

  return i; }


/* Parse CLUSTAL alignment */
align_t *clustal_parse(FILE *f) {
  align_t *ali;

  ali = clustaly_parse(f);

  return ali; }


/* Print CLUSTAL alignment */
void clustal_print(FILE *f, align_t *ali) {
  char *p, *cons, c;
  size_t i, j, n, len, nam, seq;
  sequence_t **s;

  if (ali == NULL) { return; }

  s = ali->seq; len = (*s)->strlen;
  if ((cons = clustal_conserv(ali)) == NULL) {
    return; }

  nam = 15; seq = 60;
  s = ali->seq;
  while (s && *s) {
    if (strlen((*s)->nam) > 15) {
      nam = 30; seq = 50; break; }
    s++; }

  /* Header */
  (void)fprintf(f, "CLUSTAL multiple sequence alignment\n\n");

  /* Sequences */
  i = 0; n = len / seq; if (len % seq) { n++; }
  while (n--) {
    (void)fputc('\n', f);
    s = ali->seq;
    while (s && *s) {

      /* Name (no spaces, max 30 chars) */
      p = (*s)->nam; j = nam;
      while (j && *p) {
	c = *p;
	if (isspace((unsigned char)c)) { c = '_'; }
	(void)fputc(c, f);
	j--; p++; }
      while (j) {
	(void)fputc(' ', f);
	j--; }

      (void)fputc(' ', f);

      /* Sequence */
      p = (*s)->str + i; j = seq;
      while (j && *p) {
	c = *p;
	if (c == '*') { c = 'X'; }
	if (c == '.' || c == '~' || c == '?') { c = '-'; }
	(void)fputc(c, f);
	j--; p++; }
      (void)fputc('\n', f);
      s++; }
    /* Conservation line */
    (void)fprintf(f, "%*s %.*s\n", (int)nam, "", (int)seq, cons+i);
    i += seq; }

  free(cons);

  return; }


/* Get conservation string from alignment */
char *clustal_conserv(align_t *ali) {
  char *p, *q, *cons, c;
  const char *z, **x;
  int j, alph, mask;
  size_t l, len;
  sequence_t **s;
  seqtyp_t t;

  static const char *strong[] = { "STA", "NEQK", "NHQK", "NDEQ", "QHRK",
				  "MILV", "MILF", "HY", "FYW", NULL };
  static const char *weaker[] = { "CSA", "ATV", "SAG", "STNK", "STPA", "SGND",
				  "SNDEQK", "NDEQHK", "NEQHRK", "FVLIM", "HFY",
				  NULL };

  s = ali->seq; len = (*s)->strlen;
  t = sequence_type((*s)->str);

  /* Allocate buffer */
  if ((cons = (char *)malloc(len+1)) == NULL) {
    return NULL; }

  /* Proceed all columns */
  l = 0; q = cons;
  while (l < len) {
    s = ali->seq; alph = 0; c = '\0';
    /* Make alphabet value */
    while (s && *s) {
      p = (*s)->str + l;
      if (! isalpha((unsigned char)*p)) { c = ' '; break; }
      alph |= (1 << (toupper((unsigned char)*p) - 'A'));
      s++; }
    /* Check unique residue */
    j = 0;
    while (c == '\0' && j < 26) {
      if ((alph & ~(1 << j)) != 0) { j++; continue; }
      c = '*'; break; }
    /* Check strong groups */
    x = strong;
    while (c == '\0' && t == SEQTYP_PRO && *x) {
      z = (const char *)*x; mask = 0;
      while (*z) { mask |= (1 << (toupper((unsigned char)*z) - 'A')); z++; }
      if ((alph & ~mask) != 0) { x++; continue; }
      c = ':'; break; }
    /* Check weaker groups */
    x = weaker;
    while (c == '\0' && t == SEQTYP_PRO && *x) {
      z = (const char *)*x; mask = 0;
      while (*z) { mask |= (1 << (toupper((unsigned char)*z) - 'A')); z++; }
      if ((alph & ~mask) != 0) { x++; continue; }
      c = '.'; break; }
    /* All remaining cases */
    if (c == '\0') { c = ' '; }
    *q = c; q++; l++; }
  *q = '\0';

  return cons; }
