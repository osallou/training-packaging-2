/* file.c - Data file functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

#include "extern/error.h"
#include "extern/file.h"


#ifndef BIODATADIR
#define BIODATADIR "/usr/local/share/"PACKAGE
#endif


/* Locate data file */
char *file_locate(char *name) {
  char *p, *q;
  size_t l, len;

  /* Check current directory */
  if (access(name, F_OK) != -1) {
    return name; }

  p = NULL; l = strlen(name);

  /* Check env directory */
  if ((q = getenv("BIODATADIR")) != NULL) {
    len = strlen(q) + 1 + l;
    if ((p = realloc(p, len+1)) == NULL) {
      return NULL; }
    (void)sprintf(p, "%s/%s",  q, name);
    if (access(p, F_OK) != -1) {
      return p; }
  }

  /* Check system directory */
  len = strlen(BIODATADIR) + 1 + l;
  if ((p = realloc(p, len+1)) == NULL) {
    return NULL; }
  (void)sprintf(p, "%s/%s", BIODATADIR, name);
  if (access(p, F_OK) != -1) {
    return p; }

  return NULL; }
