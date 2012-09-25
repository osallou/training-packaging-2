/* align.c - Generic alignment functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <sys/types.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#ifndef HAVE_FSEEKO
# define fseeko fseek
# define ftello ftell
#endif

#include "align.h"
#include "align/clustal.h"
#include "align/fasta2.h"
#include "align/mega.h"
#include "align/msf.h"
#include "align/nexusi.h"
#include "align/phylipi.h"
#include "align/phylips.h"
#include "align/stock.h"
#include "extern/error.h"


static int namcmp(const void *a, const void *b) {
  const char * const *p = a, * const *q = b;
  return strcmp(*p, *q); }


/* Create a new alignment object */
align_t *align_new(void) {
  size_t len;
  align_t *ali;

  /* Allocate */
  len = sizeof(*ali);
  if ((ali = malloc(len)) == NULL) { return NULL; }

  /* Initialise */
  ali->seq = NULL;
  ali->cur = ali->seq;
  ali->_tmp = NULL;

  return ali; }


/* Delete an alignment object */
void align_free(align_t *ali) {
  sequence_t **p;

  if (ali == NULL) { return; }

  p = ali->seq;
  while (p && *p) {
    sequence_free(*p);
    p++; }
  free(ali->seq);
  free(ali->_tmp);
  free(ali);

  return; }


/* Parse a formatted alignment from file */
align_t *align_parse(FILE *f, alifmt_t fmt) {
  align_t *ali;

  ali = NULL;

  switch (fmt) {
  case ALIFMT_CLUSTAL:
    ali = clustal_parse(f); break;
  case ALIFMT_FASTA:
    ali = fasta2_parse(f); break;
  case ALIFMT_MEGA:
    ali = mega_parse(f); break;
  case ALIFMT_MSF:
    ali = msf_parse(f); break;
  case ALIFMT_NEXUSI:
    ali = nexusi_parse(f); break;
  case ALIFMT_PHYLIPI:
    ali = phylipi_parse(f); break;
  case ALIFMT_PHYLIPS:
    ali = phylips_parse(f); break;
  case ALIFMT_STOCK:
    ali = stock_parse(f); break;
  default: break; }

  return ali; }


/* Check alignment format */
int align_check(FILE *f, alifmt_t fmt) {
  int i;

  switch (fmt) {
  case ALIFMT_CLUSTAL:
    i = clustal_check(f); break;
  case ALIFMT_FASTA:
    i = fasta2_check(f); break;
  case ALIFMT_MEGA:
    i = mega_check(f); break;
  case ALIFMT_MSF:
    i = msf_check(f); break;
  case ALIFMT_NEXUSI:
    i = nexusi_check(f); break;
  case ALIFMT_PHYLIPI:
    i = phylipi_check(f); break;
  case ALIFMT_PHYLIPS:
    i = phylips_check(f); break;
  case ALIFMT_STOCK:
    i = stock_check(f); break;
  default:
    i = 1; break; }

  return i; }


/* Check aligment file format */
alifmt_t align_format(FILE *f) {
  int i;
  off_t off;
  alifmt_t fmt;

  if ((off = ftello(f)) == -1) {
    error_fatal("file position", NULL); }

  for (fmt = ALIFMT_UNKWN + 1; fmt != ALIFMT_NONE; fmt++) {

    i = align_check(f, fmt);

    if (fseeko(f, off, SEEK_SET) != 0) {
      error_fatal("file position", NULL); }

    if (i == 0) { break; }

  }

  return fmt; }


/* Check for alignment strict conditions */
int align_strict(align_t *ali) {
  int i, d, n, num;
  size_t len;
  char **x, **buf;
  sequence_t **p;

  if (ali == NULL || ali->seq == NULL) { return 1; }

  d = (getenv("SQUIZZ_DEBUG") != NULL) ? 1 : 0;

  /* Need more than 1 sequence */
  p = ali->seq; n = 0;
  while (p && *p) { n++; p++; }
  if (d) { fprintf(stderr, "Found %d sequence(s)\n", n); }
  if (n < 2) { return 1; }
  num = n;

  /* All sequences must have the same length */
  p = ali->seq; n = 0; len = (*p)->strlen;
  while (p && *p) {
    if ((*p)->strlen != len) { n++; }
    p++; }
  if (d) { fprintf(stderr, "Found %d sequence(s) with bad lengths\n", n); }
  if (n > 0) { return 1; }

  /* Sequence names must exists */
  p = ali->seq; n = 0;
  while (p && *p) {
    if ((*p)->nam == NULL) { n++; }
    p++; }
  if (d) { fprintf(stderr, "Found %d unnamed sequence(s)\n", n); }
  if (n > 0) { return 1; }

  /* Sequence names must be unique */
  len = num * sizeof(*buf);
  if ((buf = malloc(len)) == NULL) { return 1; }
  p = ali->seq; x = buf; n = 0;
  while (p && *p) {
    *x = (*p)->nam; x++; p++; }
  qsort(buf, num, sizeof(*buf), namcmp);
  for (i = 0, x = buf; i < num - 1; i++, x++) {
    if (strcmp(*x, *(x+1)) != 0) { continue; }
    n++; }
  free(buf);
  if (d) { fprintf(stderr, "Found %d identical sequence name pair(s)\n", n); }
  if (n > 0) { return 1; }

  return 0; }


/* Print alignment */
void align_print(FILE *f, align_t *ali, alifmt_t fmt) {

  switch (fmt) {
  case ALIFMT_CLUSTAL:
    clustal_print(f, ali); break;
  case ALIFMT_FASTA:
    fasta2_print(f, ali); break;
  case ALIFMT_MEGA:
    mega_print(f, ali); break;
  case ALIFMT_MSF:
    msf_print(f, ali); break;
  case ALIFMT_NEXUSI:
    nexusi_print(f, ali); break;
  case ALIFMT_PHYLIPI:
    phylipi_print(f, ali); break;
  case ALIFMT_PHYLIPS:
    phylips_print(f, ali); break;
  case ALIFMT_STOCK:
    stock_print(f, ali); break;
  default:
    break; }

  return; }
