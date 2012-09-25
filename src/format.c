/* format.c - Sequence/Alignment format functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <sys/types.h>
#ifdef STDC_HEADERS
# include <string.h>
#endif

#include "align.h"
#include "format.h"
#include "sequence.h"
#include "extern/error.h"


#if !defined(HAVE_FSEEKO) && (SIZEOF_LONG == 8)
# define fseeko fseek
# define ftello ftell
# define off_t long
#endif


/* Check alignment/sequence format */
void format_detect(allfmt_t *fmt, FILE *f, allfmt_t *ifmt, int s) {
  off_t off;
  align_t *ali;
  sequence_t *seq;

  fmt->ali = ALIFMT_NONE; fmt->seq = SEQFMT_NONE;
  fmt->num = 0; fmt->f = f;

  /* Process alignment formats */
  if (ifmt->ali != ALIFMT_NONE) {
    fmt->ali = align_format(f); }
  if (s && fmt->ali != ALIFMT_NONE) {
    if ((off = ftello(f)) == -1) {
      error_fatal("file position", NULL); }
    ali = align_parse(f, fmt->ali);
    fmt->num = 1;
    if (align_strict(ali) != 0) {
      fmt->num = 0; fmt->ali = ALIFMT_NONE; }
    align_free(ali);
    if (fseeko(f, off, SEEK_SET) == -1) {
      error_fatal("file position", NULL); }
  }

  /* Process sequence formats */
  if (ifmt->seq != SEQFMT_NONE) {
    fmt->seq = sequence_format(f); }
  if (s && fmt->seq != SEQFMT_NONE) {
    if ((off = ftello(f)) == -1) {
      error_fatal("file position", NULL); }
    while ((seq = sequence_parse(f, fmt->seq)) != NULL) {
      if (sequence_strict(seq) != 0) {
	fmt->num = 0; fmt->seq = SEQFMT_NONE; break; }
      fmt->num++;
      sequence_free(seq); }
    if (fseeko(f, off, SEEK_SET) == -1) {
      error_fatal("file position", NULL); }
  }

  return; }


/* Verify single format */
void format_verify(allfmt_t *fmt, FILE *f, allfmt_t *ifmt, int s) {
  int v;
  off_t off;
  align_t *ali;
  sequence_t *seq;

  fmt->ali = ifmt->ali; fmt->seq = ifmt->seq;
  fmt->num = ifmt->num = 0; fmt->f = ifmt->f = f;

  /* Verify aligment format */
  if (ifmt->ali != ALIFMT_NONE) {
    if ((off = ftello(f)) == -1) {
      error_fatal("file position", NULL); }
    if (align_check(f, ifmt->ali) != 0) {
      fmt->ali = ALIFMT_NONE; }
    if (fseeko(f, off, SEEK_SET) == -1) {
      error_fatal("file position", NULL); }
  }
  if (s && fmt->ali != ALIFMT_NONE) {
    fmt->num = 1;
    if ((off = ftello(f)) == -1) {
      error_fatal("file position", NULL); }
    ali = align_parse(f, fmt->ali);
    if (align_strict(ali) != 0) {
      fmt->num = 0; fmt->ali = ALIFMT_NONE; }
    align_free(ali);
    if (fseeko(f, off, SEEK_SET) == -1) {
      error_fatal("file position", NULL); }
  }

  /* Verify sequence format */
  if (ifmt->seq != SEQFMT_NONE) {
    if ((off = ftello(f)) == -1) {
      error_fatal("file position", NULL); }
    while ((v = sequence_check(f, ifmt->seq)) != -1) {
      if (v == 0) { continue; }
      fmt->seq = SEQFMT_NONE;
      break; }
    if (fseeko(f, off, SEEK_SET) == -1) {
      error_fatal("file position", NULL); }
  }
  if (s && fmt->seq != SEQFMT_NONE) {
    fmt->num = 0;
    if ((off = ftello(f)) == -1) {
      error_fatal("file position", NULL); }
    while ((seq = sequence_parse(f, fmt->seq)) != NULL) {
      if (sequence_strict(seq) != 0) {
	fmt->num = 0; fmt->seq = SEQFMT_NONE; break; }
      fmt->num++;
      sequence_free(seq); }
    if (fseeko(f, off, SEEK_SET) == -1) {
      error_fatal("file position", NULL); }
  }

  return; }


/* Get format name */
const char *format_name(allfmt_t *fmt) {
  const char *p = "UNKNOWN";

  if (fmt->ali != ALIFMT_NONE && fmt->ali != ALIFMT_UNKWN) {
    switch (fmt->ali) {
    case ALIFMT_CLUSTAL: p = "CLUSTAL"; break;
    case ALIFMT_FASTA:   p = "FASTA"; break;
    case ALIFMT_MEGA:    p = "MEGA"; break;
    case ALIFMT_MSF:     p = "MSF"; break;
    case ALIFMT_NEXUSI:  p = "NEXUS"; break;
    case ALIFMT_PHYLIPI: p = "PHYLIPI"; break;
    case ALIFMT_PHYLIPS: p = "PHYLIPS"; break;
    case ALIFMT_STOCK:   p = "STOCKHOLM"; break;
    default: break; }
    return p; }

  if (fmt->seq != SEQFMT_NONE && fmt->seq != SEQFMT_UNKWN) {
    switch (fmt->seq) {
    case SEQFMT_EMBL:    p = "EMBL"; break;
    case SEQFMT_FASTA:   p = "FASTA"; break;
    case SEQFMT_GCG:     p = "GCG"; break;
    case SEQFMT_GDE:     p = "GDE"; break;
    case SEQFMT_GENBANK: p = "GENBANK"; break;
    case SEQFMT_IG:      p = "IG"; break;
    case SEQFMT_NBRF:    p = "NBRF"; break;
    case SEQFMT_PIR:     p = "PIR"; break;
    case SEQFMT_RAW:     p = "RAW"; break;
    case SEQFMT_SPROT:   p = "SWISSPROT"; break;
    default: break; }
    return p; }

  return p; }


/* Get format from name */
void format_fmt(allfmt_t *fmt, char *str) {

  fmt->ali = ALIFMT_NONE; fmt->seq = SEQFMT_NONE;
  fmt->f = stdout;

  if (strcasecmp(str, "CLUSTAL") == 0) {
    fmt->ali = ALIFMT_CLUSTAL; }
  if (strcasecmp(str, "EMBL") == 0) {
    fmt->seq = SEQFMT_EMBL; }
  if (strcasecmp(str, "FASTA") == 0) {
    fmt->ali = ALIFMT_FASTA;
    fmt->seq = SEQFMT_FASTA; }
  if (strcasecmp(str, "GCG") == 0) {
    fmt->seq = SEQFMT_GCG; }
  if (strcasecmp(str, "GDE") == 0) {
    fmt->seq = SEQFMT_GDE; }
  if (strcasecmp(str, "GENBANK") == 0) {
    fmt->seq = SEQFMT_GENBANK; }
  if (strcasecmp(str, "IG") == 0) {
    fmt->seq = SEQFMT_IG; }
  if (strcasecmp(str, "MEGA") == 0) {
    fmt->ali = ALIFMT_MEGA; }
  if (strcasecmp(str, "MSF") == 0) {
    fmt->ali = ALIFMT_MSF; }
  if (strcasecmp(str, "NBRF") == 0) {
    fmt->seq = SEQFMT_NBRF; }
  if (strcasecmp(str, "NEXUSI") == 0 ||
      strcasecmp(str, "NEXUS") == 0) {
    fmt->ali = ALIFMT_NEXUSI; }
  if (strcasecmp(str, "PHYLIPI") == 0 ||
      strcasecmp(str, "PHYLIP") == 0) {
    fmt->ali = ALIFMT_PHYLIPI; }
  if (strcasecmp(str, "PHYLIPS") == 0) {
    fmt->ali = ALIFMT_PHYLIPS; }
  if (strcasecmp(str, "PIR") == 0) {
    fmt->seq = SEQFMT_PIR; }
  if (strcasecmp(str, "RAW") == 0) {
    fmt->seq = SEQFMT_RAW; }
  if (strcasecmp(str, "SWISSPROT") == 0) {
    fmt->seq = SEQFMT_SPROT; }
  if (strcasecmp(str, "STOCKHOLM") == 0) {
    fmt->ali = ALIFMT_STOCK; }

  return; }


/* Convert format */
void format_convert(allfmt_t *ifmt, allfmt_t *ofmt) {
  const char *nam;
  int n;
  align_t *ali;
  sequence_t **s, *seq;

  /* Ignore unknown formats */
  if (ifmt->ali == ALIFMT_NONE && ifmt->seq == SEQFMT_NONE) {
    return; }

  /* From align to align */
  if (ifmt->ali != ALIFMT_NONE && ofmt->ali != ALIFMT_NONE) {
    ali = align_parse(ifmt->f, ifmt->ali);
    align_print(ofmt->f, ali, ofmt->ali);
    align_free(ali);
    return; }

  /* From sequence to sequence */
  if (ifmt->seq != SEQFMT_NONE && ofmt->seq != SEQFMT_NONE) {
    n = 0;
    while ((seq = sequence_parse(ifmt->f, ifmt->seq)) != NULL) {
      if (n && (ofmt->seq == SEQFMT_RAW || ofmt->seq == SEQFMT_GCG)) {
	nam = format_name(ofmt);
	error_fatal(nam, "this format cannot handle more than one sequence"); }
      sequence_print(ofmt->f, seq, ofmt->seq);
      sequence_free(seq); n++; }
    return; }

  /* From align to sequence */
  if (ifmt->ali != ALIFMT_NONE && ofmt->seq != SEQFMT_NONE) {
    ali = align_parse(ifmt->f, ifmt->ali);
    n = 0; s = ali->seq;
    while (s && *s) {
      if (n && (ofmt->seq == SEQFMT_RAW || ofmt->seq == SEQFMT_GCG)) {
	nam = format_name(ofmt);
	error_fatal(nam, "this format cannot handle more than one sequence"); }
      sequence_print(ofmt->f, *s, ofmt->seq);
      n++; s++; }
    align_free(ali);
    return; }

 /* From sequence to align */
  if (ifmt->seq != SEQFMT_NONE && ofmt->ali != ALIFMT_NONE) {
    error_fatal("sequence", "cannot convert to alignment format");
    return; }

  return; }


/* List all supported formats */
void format_list(allfmt_t *lfmt) {
  FILE *f;
  allfmt_t fmt;

  f = stdout;

  /* Alignments */
  if (lfmt->ali != ALIFMT_NONE) {
    fmt.seq = SEQFMT_NONE;
    for (fmt.ali = ALIFMT_UNKWN+1; fmt.ali != ALIFMT_NONE; fmt.ali++) {
      /* Skip formats already in sequence list */
      if (lfmt->seq != SEQFMT_NONE && fmt.ali == ALIFMT_FASTA) continue;
      (void)fprintf(f, "%s\n", format_name(&fmt)); }
  }

  /* Sequences */
  if (lfmt->seq != SEQFMT_NONE) {
    fmt.ali = ALIFMT_NONE;
    for (fmt.seq = SEQFMT_UNKWN+1; fmt.seq != SEQFMT_NONE; fmt.seq++) {
      (void)fprintf(f, "%s\n", format_name(&fmt)); }
  }

  return; }
