/* pir.c - PIR sequence functions */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <string.h>
#endif

#include "sequence.h"
#include "sequence/pir.h"
#include "sequence/protein.h"


/* Functions prototypes */
extern sequence_t *piry_parse(FILE *);
extern int piry_check(FILE *);
unsigned int pir_checksum(char *);


/* Parse PIR sequence */
sequence_t *pir_parse(FILE *f) {
  sequence_t *seq;

  seq = piry_parse(f);

  return seq; }


/* Checks PIR sequence */
int pir_check(FILE *f) {
  int i;

  i = piry_check(f);

  return i; }


/* Print PIR sequence */
void pir_print(FILE *f, sequence_t *seq) {
  char *p, *q, **x;
  const char *r, *s;
  float w;
  int i, max;
  long l;
  size_t len, sep;
  unsigned int c;

  if (seq == NULL) { return; }

  /* Inits */
  max = 80;

  /* Name */
  r = (seq->nam != NULL) ? seq->nam : "UNKNWN" ; s = "complete";
  (void)fprintf(f, "ENTRY           %.6s  #type %s\n", r, s);

  /* Description */
  p = seq->dsc; i = 1;
  while (p && *p) {
    while (*p && *p == ' ') { p++; }
    if (i == 1) {
      (void)fprintf(f, "TITLE           "); i = 0; }
    else {
      (void)fprintf(f, "                "); }
    q = p;
    while (*q && q - p < max - 16) { q++; }
    while (*q && *q != ' ') { q--; }
    while (*p && q - p > 0) {
      (void)fputc(*p, f); p++; }
    (void)fputc('\n', f);
    p = q; }

  /* Accession */
  x = seq->acc; l = 0;
  while (x && *x) {
    switch (l) {
    case 0: s = "ACCESSIONS      "; break;
    case 16: s = ""; break;
    default: s = "; "; break; }
    len = strlen(*x); sep = strlen(s);
    if (l + sep + len + 2 > max - 5) {
      l = 0; (void)fprintf(f, ";\n"); continue; }
    (void)fprintf(f, "%s%s", s, *x);
    l += sep + len; x++; }
  if (l != 0) { (void)fputc('\n', f); }

  /* Sequence Header */
  w = protein_weight(seq->str); c = pir_checksum(seq->str);
  (void)fprintf(f, "SUMMARY         #length %lu", seq->strlen);
  (void)fprintf(f, "  #molecular-weight %u ", (unsigned int)w);
  (void)fprintf(f, " #checksum %u", c);
  (void)fputc('\n', f);

  /* Sequence */
  (void)fprintf(f, "SEQUENCE\n");
  (void)fprintf(f, "        ");
  for (i = 5; i <= 30; i += 5) {
    (void)fprintf(f, "%10i", i); }
  (void)fputc('\n', f);
  p = seq->str;
  while (*p) {
    l = p - seq->str;
    if (l % 30 == 0 && l > 0) {
      (void)fputc('\n', f); }
    if (l % 30 == 0) {
      (void)fprintf(f, "%8li", l+1); }
    if (*p == '*') { p++; continue; }
    (void)fputc(' ', f);
    (void)fputc(*p, f);
    p++; }
  (void)fputc('\n', f);

  /* End */
  (void)fprintf(f, "///\n");

  return; }


/* Pir sequence checksum */
unsigned int pir_checksum(char *seq) {
  char *p;
  unsigned int nb, lsum, cksum;

  p = seq; cksum = nb = 0;
  while (*p) {
    nb++;
    cksum += nb * (*p);
    if (nb == 57) { nb = 0; }
    p++; }
  lsum = cksum / 10000;
  cksum -= lsum * 10000;

  return cksum; }
