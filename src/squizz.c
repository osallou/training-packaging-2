/* squizz.c - Sequence/Alignment format detection */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <sys/stat.h>

#include <stdio.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
#endif
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#include <libgen.h>

#include "extern/error.h"
#include "align.h"
#include "format.h"
#include "sequence.h"


/* Functions prottypes */
static void usage(char *p);


/* Main function */
ERRORint main(int argc, char **argv) {
  FILE *f;
  char *file, *prg;
  const char *nam;
  int i, strict, convert, verify, count, list;
  struct stat st;
  allfmt_t fmt, ifmt, ofmt;

  /* Misc inits */
  prg = *argv;
  ifmt.ali = ALIFMT_UNKWN;
  ifmt.seq = SEQFMT_UNKWN;

  /* Check command line */
  strict = 1; convert = 0; verify = 0; count = 0; list = 0;
  while ((i = getopt(argc, argv, "ASc:f:hlns")) != -1) {
    switch (i) {
    case 'A':
      ifmt.seq = SEQFMT_NONE;
      break;
    case 'S':
      ifmt.ali = ALIFMT_NONE;
      break;
    case 'c':
      convert = 1;
      format_fmt(&ofmt, optarg);
      if (ofmt.ali == ALIFMT_NONE && ofmt.seq == SEQFMT_NONE) {
	error_fatal(optarg, "unsupported format"); }
      break;
    case 'f':
      verify = 1;
      format_fmt(&fmt, optarg);
      if (fmt.ali == ALIFMT_NONE && fmt.seq == SEQFMT_NONE) {
	error_fatal(optarg, "unsupported format"); }
      if (ifmt.ali != ALIFMT_NONE) { ifmt.ali = fmt.ali; }
      if (ifmt.seq != SEQFMT_NONE) { ifmt.seq = fmt.seq; }
      break;
    case 'h':
      usage(prg); return EXIT_SUCCESS;
    case 'l':
      list = 1; break;
    case 'n':
      count = 1; break;
    case 's':
      strict = 0; break;
    default:
      usage(prg); return EXIT_FAILURE; }
  }
  if (convert == 1 && strict != 1) {
    error_fatal("options", "-c and -s options cannot be set together"); }
  if (ifmt.ali == ALIFMT_NONE && ifmt.seq == SEQFMT_NONE) {
    error_fatal("options", "-A and -S options cannot be set together"); }
  if (count && ifmt.ali == ALIFMT_UNKWN && ifmt.seq == SEQFMT_UNKWN) {
    error_fatal("options", "-n cannot be set without -A or -S"); }
  if (count && strict == 0) {
    error_fatal("options", "-n and -s options cannot be set together"); }

  /* Print supported format list */
  if (list == 1) {
    format_list(&ifmt); return EXIT_SUCCESS; }

  if (argc - optind != 1) {
    usage(prg); return EXIT_FAILURE; }

  /* Process file */
  file = *(argv+optind);

  /* Check for regular input file */
  if (stat(file, &st) == -1) {
    error_fatal(file, NULL); }
  if ((st.st_mode & S_IFREG) == 0) {
    error_fatal(file, "not a regular file"); }

  if ((f = fopen(file, "r")) == NULL) {
    error_fatal(file, NULL); }

  /* Check/Detect format */
  if (verify == 0) {
    format_detect(&fmt, f, &ifmt, strict); }
  else {
    format_verify(&fmt, f, &ifmt, strict); }
  nam = format_name(&fmt);
  (void)fprintf(stderr, "%s: %s format", file, nam);
  if (count) {
    (void)fprintf(stderr, ", %d entries", fmt.num); }
  (void)fprintf(stderr, ".\n");

  /* Convert if needed */
  if (convert == 1) {
    format_convert(&fmt, &ofmt); }

  if (fclose(f) == EOF) {
    error_fatal(file, NULL); }

  return EXIT_SUCCESS; }


/* Usage display */
static void usage(char *p) {
  FILE *f = stderr;

  (void)fprintf(f, "usage: %s [options] <file>\n", basename(p));
  (void)fprintf(f, "\noptions:\n");
  (void)fprintf(f, "  -A       ... Detect alignment formats only.\n");
  (void)fprintf(f, "  -S       ... Detect sequence formats only.\n");
  (void)fprintf(f, "  -c <fmt> ... Convert into format <fmt>.\n");
  (void)fprintf(f, "  -f <fmt> ... Assume input format <fmt>.\n");
  (void)fprintf(f, "  -h       ... Print this message and exit.\n");
  (void)fprintf(f, "  -l       ... List all supported formats.\n");
  (void)fprintf(f, "  -n       ... Count and report entries number.\n");
  (void)fprintf(f, "  -s       ... Disable strict format checks.\n");

  return; }
