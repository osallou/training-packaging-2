/* parse.c - Sequence parsing helper functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "extern/error.h"
#include "extern/text.h"
#include "sequence.h"
#include "sequence/parse.h"


/* Null update ... */
/*ARGSUSED*/
void parse_nuladd(sequence_t *seq, char *str) {

  if (str == NULL) { return; }
  free(str);

  return; }


/* Name update ... */
void parse_namadd(sequence_t *seq, char *str) {

  if (str == NULL) { return; }
  if (seq != NULL) {
    seq->nam = text_strupd(seq->nam, str); }
  free(str);

  return; }


/* Accession number update */
void parse_accadd(sequence_t *seq, char *str) {

  if (str == NULL) { return; }
  if (seq != NULL) {
    seq->acc = text_keyadd(seq->acc, str); }
  free(str);

  return; }


/* Version number update */
void parse_veradd(sequence_t *seq, int num) {

  if (seq != NULL) {
    seq->ver = num; }

  return; }


/* NCBI GI number update */
void parse_giadd(sequence_t *seq, int num) {

  if (seq != NULL) {
    seq->gi = num; }

  return; }


/* Description update ... */
void parse_dscadd1(sequence_t *seq, char *str) {

  if (str == NULL) { return; }
  if (seq != NULL) {
    seq->dsc = text_strupds(seq->dsc, str); }
  free(str);

  return; }

void parse_dscadd2(sequence_t *seq, char *str) {

  if (str == NULL) { return; }
  if (seq != NULL) {
    seq->dsc = text_strupd(seq->dsc, str); }
  free(str);

  return; }


/* Keywords update ... */
void parse_kwdadd(sequence_t *seq, char *str) {

  if (str == NULL) { return; }
  if (seq != NULL) {
    if (seq->keycnt == 1) {
      seq->kwd = text_keyupd(seq->kwd, str); }
    else {
      seq->kwd = text_keyadd(seq->kwd, str); }
    seq->keycnt = 0; }
  free(str);

  return; }

void parse_kwdupd(sequence_t *seq, char *str) {

  if (str == NULL) { return; }
  if (seq != NULL) {
    if (seq->keycnt == 1) {
      seq->kwd = text_keyupd(seq->kwd, str); }
    else {
      seq->kwd = text_keyadd(seq->kwd, str); }
    seq->keycnt = 1; }
  free(str);

  return; }


/* Sequence string update ... */
void parse_stradd(sequence_t *seq, char *str) {
  char *p, *q;

  if (str == NULL) { return; }
  if (seq != NULL) {
    size_t len = seq->strlen + strlen(str);
    if ((seq->str = (char *)realloc(seq->str, len+1)) == NULL) {
      error_fatal("memory", NULL); }
    p = str; q = seq->str + seq->strlen;
    while (*p) { *q++ = *p++; }
    *q = '\0';
    seq->strlen = len; }

  free(str);

  return; }
