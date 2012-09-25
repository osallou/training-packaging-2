/* mega.c - MEGA alignment functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif
#include <ctype.h>
#include <time.h>

#include "align.h"
#include "align/mega.h"
#include "sequence.h"
#include "sequence/utils.h"


/* Functions prototypes */
extern int megay_check(FILE *);
extern align_t *megay_parse(FILE *);


/* Checks MEGA alignment */
int mega_check(FILE *f) {
  int i;

  i = megay_check(f);

  return i; }


/* Parse MEGA alignment */
align_t *mega_parse(FILE *f) {
  char *p, *q, *ref;
  align_t *ali;
  sequence_t **s;

  ali = megay_parse(f);
  if (ali == NULL) {
    return ali; }

  /* FIXME: Do not allow identical character in 1st sequence */
  /* Replace all "identical" characters in sequences */
  s = ali->seq; ref = (*s)->str; s++;
  while (s && *s) {
    p = (*s)->str; q = ref;
    while (p && *p) {
      if (*p == '.') { *p = *q; }
      p++; q++; }
    s++; }

  return ali; }


/* Print MEGA alignment */
void mega_print(FILE *f, align_t *ali) {
  char *p;
  char c;
  int j;
  sequence_t **s;

  if (ali == NULL) { return; }

  /* Header */
  (void)fprintf(f, "#mega\n");
  (void)fprintf(f, "!Title Multiple Sequence Alignment;\n");
  (void)fputc('\n', f);

  /* Sequences */
  s = ali->seq;
  while (s && *s) {

    /* Name (max 40 chars) */
    p = sequence_fixnam((*s)->nam); j = 40;
    (void)fprintf(f, "#%-.*s\n", j, p);
    free(p);

    /* Sequence */
    p = (*s)->str; j = 60;
    while (*p) {
      c = *p;
      if (c == '~') { c = '-'; }
      if (j == 0) {
	(void)fputc('\n', f);
	j = 60; }
      (void)fputc(c, f);
      j--; p++; }
    (void)fputc('\n', f);

    s++; }

  return; }
