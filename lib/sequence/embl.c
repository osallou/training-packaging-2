/* embl.c - EMBL sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <string.h>
#endif

#include "extern/error.h"
#include "sequence.h"
#include "sequence/embl.h"


/* Functions prototypes */
extern sequence_t *embly_parse(FILE *);
extern int embly_check(FILE *);


/* Parse EMBL sequence */
sequence_t *embl_parse(FILE *f) {
  sequence_t *seq;

  seq = embly_parse(f);

  return seq; }


/* Check EMBL sequence */
int embl_check(FILE *f) {
  int i;

  i = embly_check(f);

  return i; }


/* Print EMBL sequence */
/* FIXME: Add `XX' spacers ... */
void embl_print(FILE *f, sequence_t *seq) {
  char *p, *q, *z, **x;
  const char *r, *s, *t;
  int v;
  long i, l, max;
  size_t len, sep, nba, nbt, nbc, nbg, nbo;

  if (seq == NULL) { return; }

  /* Inits */
  max = 80;

  /* Name */
  r = (seq->acc) ? *seq->acc : (seq->nam) ? seq->nam : "UNKNOWN";
  v = (seq->ver > 0) ? seq->ver : 1;
  t = "XXX"; len = seq->strlen;
  (void)fprintf(f, "ID   %s; SV %d; %s; %s; %s; %s; %lu BP.\n",
		r, v, t, t, t, t, len);

  /* Accession */
  if (seq->acc != NULL) {
    x = seq->acc; l = 0;
    while (x && *x) {
      switch (l) {
      case 0: s = "AC   "; break;
      case 5: s = ""; break;
      default: s = "; "; break; }
      len = strlen(*x); sep = strlen(s);
      if (l + len + 2 > max - 5) {
	l = 0; (void)fprintf(f, ";\n"); continue; }
      (void)fprintf(f, "%s%s", s, *x);
      l += sep + len;
      x++; }
    (void)fprintf(f, ";\n"); }

  /* Description */
  p = seq->dsc;
  while (p && *p) {
    while (*p && *p == ' ') { p++; }
    (void)fprintf(f, "DE   ");
    q = p; i = 0;
    while (*q && q - p < max - 5) { q++; }
    z = q;
    while (/*CONSTCOND*/1) {
      /* Do not split words */
      while (q - p > 0 && *q && *q != ' ' && i == 0) { q--; continue; }
      /* Split words longer than max-5 */
      while (q - p > 0 && *q && *q != '-' && i == 1) { q--; continue; }
      if (q == p) {
	q = z;
	if (i == 1) { break; }
	i = 1; continue; }
      /* Check for trailing '-' */
      if (*q == '-' && q - p + 1 > max - 5) { q--; continue; }
      if (*q == '-') { q++; }
      break; }
    while (*p && q - p > 0) {
      (void)fputc(*p, f); p++; }
    (void)fputc('\n', f);
    p = q; }

  /* Keywords */
  x = seq->kwd; l = 5;
  (void)fprintf(f, "KW   ");
  while (x && *x) {
    switch (l) {
    case 0: s = "KW   "; break;
    case 5: s = ""; break;
    default: s = "; "; break; }
    len = strlen(*x); sep = strlen(s);
    if (l > 5 && l + sep + len + 1 > max) {
      (void)fprintf(f , ";\n");
      l = 0; continue; }
    if (l + sep + len + 1 < max) {
      (void)fprintf(f, "%s%s", s, *x);
      l += sep + len; x++; continue; }
    (void)fprintf(f, "%s", s); l += sep;
    p = *x; i = 0;
    while (p && *p) {
      while (*p && *p == ' ') { p++; }
      q = p;
      while (*q && l + 1 + q - p < max) { q++; }
      while (/*CONSTCOND*/1) {
	/* Do not split words */
	while (q - p > 0 && *q && *q != ' ') { q--; continue; }
	break; }
      i = q - p;
      while (*p && q - p > 0) {
	(void)fputc(*p, f); p++; }
      if (*p) {
	(void)fprintf(f, "\nKW   "); }
      len = 5; p = q; }
    l += i;
    if (*(x+1) != NULL) {
      l = 0; (void)fprintf(f, ";\n"); }
    x++; }
  (void)fprintf(f, ".\n");

  /* Sequence header */
  p = seq->str; nba = nbt = nbc = nbg = nbo = 0;
  while (*p) {
    switch (*p) {
    case 'A':
    case 'a': nba++; break;
    case 'T':
    case 't': nbt++; break;
    case 'C':
    case 'c': nbc++; break;
    case 'G':
    case 'g': nbg++; break;
    default: nbo++; break; }
    p++; }
  (void)fprintf(f, "SQ   Sequence %lu BP", seq->strlen);
  (void)fprintf(f, "; %lu A; %lu C; %lu G; %lu T", nba, nbc, nbg, nbt);
  (void)fprintf(f, "; %lu other;\n", nbo);

  /* Sequence */
  p = seq->str; len = seq->strlen;
  while (*p) {
    l = p - seq->str;
    if (l % 60 == 0 && l > 0 ) {
      (void)fprintf(f, "%10li\n", l); }
    if (l % 60 == 0) {
      (void)fprintf(f, "     "); }
    if (l % 10 == 0 && l % 60 != 0) {
      (void)fputc(' ', f); }
    if (*p == '*') { p++; continue; }
    (void)fputc(*p, f); p++; }
  if ((p - seq->str) % 60 != 0) {
    l = 60 - len % 60; l += l / 10;
    while (l--) { (void)fputc(' ', f); }
  }
  (void)fprintf(f, "%10lu\n", len);

  /* End */
  (void)fprintf(f, "//\n");

  return; }
