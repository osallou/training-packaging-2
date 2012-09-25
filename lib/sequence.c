/* sequence.c - Generic sequence functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <sys/types.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif
#include <ctype.h>

#ifndef HAVE_FSEEKO
# define fseeko fseek
# define ftello ftell
#endif

#include "extern/error.h"
#include "sequence.h"
#include "sequence/embl.h"
#include "sequence/fasta.h"
#include "sequence/gcg.h"
#include "sequence/gde.h"
#include "sequence/genbank.h"
#include "sequence/ig.h"
#include "sequence/nbrf.h"
#include "sequence/pir.h"
#include "sequence/raw.h"
#include "sequence/sprot.h"


/* Create a new sequence object */
sequence_t *sequence_new(void) {
  size_t len;
  sequence_t *seq;

  /* Allocate */
  len = sizeof(*seq);
  if ((seq = malloc(len)) == NULL) { return NULL; }

  /* Initialise */
  seq->nam = seq->dsc = seq->str = NULL;
  seq->acc = seq->kwd = NULL;
  seq->ver = seq->gi = 0;

  seq->keycnt = 0;
  seq->strlen = 0;

  return seq; }


/* Delete a sequence object */
void sequence_free(sequence_t *seq) {
  char **p;

  if (seq == NULL) { return; }

  if (seq->nam != NULL) { free(seq->nam); }
  if (seq->dsc != NULL) { free(seq->dsc); }
  if (seq->str != NULL) { free(seq->str); }
  if (seq->acc != NULL) {
    p = seq->acc; while (p && *p) { free(*p); p++; }
    free(seq->acc); }
  if (seq->kwd != NULL) {
    p = seq->kwd; while (p && *p) { free(*p); p++; }
    free(seq->kwd); }

  free(seq);

  return; }


/* Parse a formatted sequence from file */
sequence_t *sequence_parse(FILE *f, seqfmt_t fmt) {
  sequence_t *seq;

  seq = NULL;

  switch (fmt) {
  case SEQFMT_EMBL:
    seq = embl_parse(f); break;
  case SEQFMT_FASTA:
    seq = fasta_parse(f); break;
  case SEQFMT_GCG:
    seq = gcg_parse(f); break;
  case SEQFMT_GDE:
    seq = gde_parse(f); break;
  case SEQFMT_GENBANK:
    seq = genbank_parse(f); break;
  case SEQFMT_IG:
    seq = ig_parse(f); break;
  case SEQFMT_NBRF:
    seq = nbrf_parse(f); break;
  case SEQFMT_PIR:
    seq = pir_parse(f); break;
  case SEQFMT_RAW:
    seq = raw_parse(f); break;
  case SEQFMT_SPROT:
    seq = sprot_parse(f); break;
  default:
    break; }

  return seq; }


/* Check sequence single format */
int sequence_check(FILE *f, seqfmt_t fmt) {
  int i;

  i = 1;

  switch (fmt) {
  case SEQFMT_EMBL:
    i = embl_check(f); break;
  case SEQFMT_FASTA:
    i = fasta_check(f); break;
  case SEQFMT_GCG:
    i = gcg_check(f); break;
  case SEQFMT_GDE:
    i = gde_check(f); break;
  case SEQFMT_GENBANK:
    i = genbank_check(f); break;
  case SEQFMT_IG:
    i = ig_check(f); break;
  case SEQFMT_NBRF:
    i = nbrf_check(f); break;
  case SEQFMT_PIR:
    i = pir_check(f); break;
  case SEQFMT_RAW:
    i = raw_check(f); break;
  case SEQFMT_SPROT:
    i = sprot_check(f); break;
  default:
    break; }

  return i; }


/* Check for sequence strict conditions */
int sequence_strict(sequence_t *seq) {
  int d;

  if (seq == NULL) { return 1; }

  d = (getenv("SQUIZZ_DEBUG") != NULL) ? 1 : 0;

  /* Sequence must not be empty */
  if (d) { fprintf(stderr, "Found sequence with %lu residues\n", seq->strlen); }
  if (seq->strlen == 0 || seq->str == NULL) { return 1; }

  return 0; }


/* Print a formatted sequence */
void sequence_print(FILE *f, sequence_t *seq, seqfmt_t fmt) {

  switch (fmt) {
  case SEQFMT_EMBL:
    embl_print(f, seq); break;
  case SEQFMT_FASTA:
    fasta_print(f, seq); break;
  case SEQFMT_GCG:
    gcg_print(f, seq); break;
  case SEQFMT_GDE:
    gde_print(f, seq); break;
  case SEQFMT_GENBANK:
    genbank_print(f, seq); break;
  case SEQFMT_IG:
    ig_print(f, seq); break;
  case SEQFMT_NBRF:
    nbrf_print(f, seq); break;
  case SEQFMT_PIR:
    pir_print(f, seq); break;
  case SEQFMT_RAW:
    raw_print(f, seq); break;
  case SEQFMT_SPROT:
    sprot_print(f, seq); break;
  default:
    break; }

  return; }


/* Checks sequence file format */
seqfmt_t sequence_format(FILE *f) {
  int i, nb;
  off_t off;
  seqfmt_t fmt;

  if ((off = ftello(f)) == -1) {
    error_fatal("file position", NULL); }

  for (fmt = SEQFMT_UNKWN + 1; fmt != SEQFMT_NONE; fmt++) {

    nb = 0;
    while ((i = sequence_check(f, fmt)) == 0) { nb++; }

    if (fseeko(f, off, SEEK_SET) != 0) {
      error_fatal("file position", NULL); }

    if (i == -1 && nb != 0) { break; }

  }

  return fmt; }


/* Checks sequence type : nuc/pro */
seqtyp_t sequence_type(char *seq) {
  char c, *p;
  float n;
  int i, a[26];
  size_t len;

  /* NUC = ABCD..GH..K.MN...RSTUVW.Y. */
  /* ALP = ABCDEFGHIJKLMNOPQRSTUVWXYZ */
  /* PRO = ABCDEFGHIJKLMNOPQRSTUVWXYZ */

  if (seq == NULL) {
    return SEQTYP_UNKWN; }

  for (i = 0; i < 26; i++) { a[i] = 0; }
  len = strlen(seq);

  p = seq;
  while (*p) {

    c = toupper((unsigned char)*p);

    /* Protein */
    if (c == 'E' || c == 'F' || c == 'I' || c == 'J' || c == 'L' ||
	c == 'O' || c == 'P' || c == 'Q' || c == 'X' || c == 'Z' ||
	c == '*') {
      return SEQTYP_PRO; }

    /* Do not count non alpha characters */
    if (isalpha((unsigned char)c) == 0) {
      p++; continue; }

    i = c - 'A';
    a[i] += 1;

    p++; }

  /* Check composition (A/T/C/G/N percent) */
  i = a[0] + a[19] + a[2] + a[6] + a[13];
  n = (float)i / (float)len;

  if (n >= 0.90) {
    return SEQTYP_NUC; }
  if (n <= 0.10) {
    return SEQTYP_PRO; }

  return SEQTYP_UNKWN; }
