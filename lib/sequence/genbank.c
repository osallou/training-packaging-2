/* genbank.c - GENBANK sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <string.h>
#endif
#include <time.h>

#include "extern/error.h"
#include "sequence.h"
#include "sequence/genbank.h"


/* Functions prototypes */
extern sequence_t *genbanky_parse(FILE *);
extern int genbanky_check(FILE *);


/* Parse GENBANK sequence */
sequence_t *genbank_parse(FILE *f) {
  sequence_t *seq;

  seq = genbanky_parse(f);

  return seq; }


/* Check GENBANK sequence */
int genbank_check(FILE *f) {
  int i;

  i = genbanky_check(f);

  return i; }


/* Print GENBANK sequence */
void genbank_print(FILE *f, sequence_t *seq) {
  char *p, *q, *z, **x;
  const char *r, *s, *u;
  int i, j, max;
  long l;
  size_t len, sep;
  time_t tt;
  struct tm ts;

  static const char *mon[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL",
			       "AUG", "SEP", "OCT", "NOV", "DEC" };

  if (seq == NULL) { return; }

  /* Inits */
  max = 80;

  /* Name */
  r = "XXX"; u = (seq->nam != NULL) ? seq->nam : "UNKNOWN";
  tt = time(NULL); (void)localtime_r(&tt, &ts); s = mon[ts.tm_mon];
  (void)fprintf(f, "LOCUS       %-16.16s %11lu bp", u, seq->strlen);
  (void)fprintf(f, " %3s%-6s  %-8s %3s", r, r, r, r);
  (void)fprintf(f, " %02i-%3s-%4i\n", ts.tm_mday, s, ts.tm_year+1900);

  /* Description */
  p = seq->dsc; i = 1;
  while (p && *p) {
    while (*p && *p == ' ') { p++; }
    if (!*p) { continue; }
    if (i == 1) {
      (void)fprintf(f, "DEFINITION  "); i = 0; }
    else {
      (void)fprintf(f, "            "); }
    q = p; j = 0;
    while (*q && q - p < max - 13) { q++; }
    z = q;
    while (/*CONSTCOND*/1) {
      /* Do not split words */
      if (q - p > 0 && *q && *q != ' ' && j == 0) { q--; continue; }
      /* Split words longer than max */
      if (q - p > 0 && *q && *q != '-' && j == 1) { q--; continue; }
      if (q == p) {
	q = z;
	if (j == 1) { break; }
	j = 1; continue; }
      /* Check for trailing '-', '.' */
      if (*q == '-' && q - p + 1 > max - 13) { q--; continue; }
      if (*q == '\0' && q - p + 1 > max - 13) { q--; continue; }
      if (*q == '-') { q++; }
      break; }
    while (*p && q - p > 0) {
      (void)fputc(*p, f); p++; }
    if (*p == '\0') { (void)fputc('.', f); }
    (void)fputc('\n', f);
    p = q; }

  /* Accession */
  if (seq->acc != NULL) {
    x = seq->acc; l = 0;
    (void)fprintf(f, "ACCESSION   ");
    while (x && *x) {
      len = strlen(*x);
      if (l + len + 1 > max - 12) {
        l = 0; (void)fprintf(f, "\n"); }
      r = (l == 0) ? "            " : " ";
      if (x == seq->acc) { r = ""; }
      (void)fprintf(f, "%s%s", r, *x);
      l += strlen(p) + len;
      x++; }
    (void)fputc('\n', f); }

  /* Version + GI */
  if (seq->ver != 0 && seq->acc && *seq->acc) {
    (void)fprintf(f, "VERSION     %s.%d", *seq->acc, seq->ver);
    if (seq->gi != 0) {
      (void)fprintf(f, "  GI:%d", seq->gi); }
    (void)fputc('\n', f); }

  /* Keywords */
  x = seq->kwd; l = 12;
  (void)fprintf(f, "KEYWORDS    ");
  while (x && *x) {
    p = *x; i = 0;
    while (p && *p) {
      switch (l) {
      case 0: s = "            "; break;
      case 12: s = ""; break;
      default: s = "; "; break; }
      sep = strlen(s);
      while (*p && *p == ' ') { p++; }
      q = p;
      while (*q && l + sep + q - p < max - 1) { q++; }
      if (*q == '\0' && l + sep + q - p + 1 > max - 1) { q--; }
      while (/*CONSTCOND*/1) {
	/* Do not split words */
	while (q - p > 0 && *q && *q != ' ' && i == 0) { q--; continue; }
	/* Split words longer than max-1 */
	while (q - p > 0 && *q && *q != '-' && i == 1) { q--; continue; }
	/* Check for trailing '-' */
	if (*q == '-' && l + sep + q - p + 1 >= max - 1) { q--; continue; }
	if (*q == '-') { q++; }
	break; }
      if (q - p == 0) {
	if (l != 0) { (void)fprintf(f, ";\n"); }
	else { i = 1; }
	l = 0; continue; }
      (void)fprintf(f, "%s", s); l += sep;
      l += q - p;
      while (*p && q - p > 0) {
	(void)fputc(*p, f); p++; }
      if (*p) {
	(void)fputc('\n', f); l = 0; }
      i = 0; p = q; }
    x++; }
  (void)fprintf(f, ".\n");

  /* FIXME: Sequence header */
  (void)fprintf(f, "ORIGIN      \n");

  /* Sequence */
  p = seq->str;
  while (*p) {
    l = p - seq->str;
    if (l % 60 == 0 && l > 0) {
      (void)fputc('\n', f); }
    if (l % 60 == 0) {
      (void)fprintf(f, " %8li ", l + 1); }
    if (l % 10 == 0 && l % 60 != 0) {
      (void)fputc(' ', f); }
    if (*p == '*') { p++; continue; }
    (void)fputc(*p, f);
    p++; }
  (void)fputc('\n', f);

  /* End */
  (void)fprintf(f, "//\n");

  return; }
