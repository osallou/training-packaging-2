/* stock.c - STOCKHOLM alignment functions */

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
#include "align/stock.h"
#include "sequence.h"


/* Functions prototypes */
extern int stocky_check(FILE *);
extern align_t *stocky_parse(FILE *);
char *stock_conserv(align_t *);


/* Checks STOCK alignment */
int stock_check(FILE *f) {
  int i;

  i = stocky_check(f);

  return i; }


/* Parse STOCK alignment */
align_t *stock_parse(FILE *f) {
  align_t *ali;

  ali = stocky_parse(f);

  return ali; }


/* Print STOCK alignment */
void stock_print(FILE *f, align_t *ali) {
  char *p, c;
  float v;
  size_t i, j, n, len, nam, seq;
  sequence_t **s;

  if (ali == NULL) { return; }

  nam = 0; seq = 50;
  s = ali->seq;
  while (s && *s) {
    len = strlen((*s)->nam);
    if (len > nam) { nam = len; }
    s++; }

  /* Header */
  v = 1.0;
  (void)fprintf(f, "# STOCKHOLM %1.1f\n", v);

  /* Sequence blocks */
  s = ali->seq; len = (*s)->strlen;
  n = len / seq; if (len % seq) { n++; }
  i = 0;
  while (n--) {

    (void)fputc('\n', f);
    s = ali->seq;

    while (s && *s) {

      /* Name (no spaces) */
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
      (void)fputc(' ', f);

      /* Sequence */
      p = (*s)->str + i; j = seq;
      while (j && *p) {
        c = *p;
	if (c == '~') { c = '.'; }
        (void)fputc(c, f);
        j--; p++; }

      (void)fputc('\n', f);
      s++; }

    i += seq; }

  /* End */
  (void)fprintf(f, "//\n");

  return; }
