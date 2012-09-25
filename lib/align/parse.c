/* parse.c - Alignment parsing helper functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif
#include <ctype.h>

#include "align.h"
#include "align/parse.h"
#include "sequence.h"
#include "sequence/parse.h"
#include "extern/error.h"
#include "extern/text.h"


/* Update sequence name in temporary buffer */
int parse_tmpupd(align_t *ali, char *nam) {

  if (nam == NULL) { return 0; }
  if (ali == NULL) { free(nam); return 0; }

  ali->_tmp = text_strupd(ali->_tmp, nam);
  free(nam);

  return (ali->_tmp == NULL); }


/* Add new sequence ... */
int parse_seqnew(align_t *ali) {
  char *q, *r;
  int i, d;
  size_t len;
  sequence_t **p;

  if (ali == NULL || ali->_tmp == NULL) { return 0; }

  d = (getenv("SQUIZZ_DEBUG") != NULL) ? 1 : 0;

  /* Cleanup leading spaces */
  q = ali->_tmp; while (*q && isspace((unsigned char)*q)) { q++; }
  if (q != ali->_tmp) { r = strdup(q); free(ali->_tmp); ali->_tmp = r; }

  /* Search if sequence already exist */
  p = ali->cur;
  if (p && *p) {
    i = strcmp((*p)->nam, ali->_tmp);
    if (d && i) {
      fprintf(stderr, "%s: unexpected sequence name\n", ali->_tmp); }
    free(ali->_tmp);
    ali->_tmp = NULL;
    return i; }

  /* Check for reallocation */
  p = ali->seq; i = 0; while (p && *p) { i++; p++; }
  len = sizeof(*p) * (i + 1 + 1);
  if ((ali->seq = realloc(ali->seq, len)) == NULL) {
    error_fatal("memory", NULL); }

  /* Add new sequence & NULL byte */
  p = ali->seq + i;
  *p = sequence_new();
  *(p+1) = NULL;
  (*p)->nam = ali->_tmp;
  ali->_tmp = NULL;

  /* Set current sequence */
  ali->cur = p;

  return 0; }


/* Update sequence string */
int parse_sequpd(align_t *ali, char *str) {
  sequence_t **p;

  if (str == NULL) { return 0; }
  if (ali == NULL) { free(str); return 0; }

  p = ali->cur;
  if (*p == NULL) { return -1; }
  parse_stradd(*p, str);

  return 0; }


/* Set current sequence pointer at the begginning */
int parse_seqrst(align_t *ali) {

  if (ali == NULL || ali->seq == NULL) { return 0; }

  if (*ali->cur != NULL && ali->cur != ali->seq) { return -1; }
  ali->cur = ali->seq;

  return 0; }


/* Update current sequence pointer to the next one */
int parse_seqnxt(align_t *ali) {

  if (ali == NULL || ali->seq == NULL) { return 0; }

  if (*ali->cur == NULL) { return -1; }
  ali->cur += 1;

  return 0; }
