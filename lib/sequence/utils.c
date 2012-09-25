/* utils.c - Sequence generic utilities functions */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif


/* Generic sequence name fixing */
char *sequence_fixnam(const char *nam) {
  const char *tmp;
  char *p, *new;

  tmp = (nam == NULL) ? "unknown" : nam;
  if ((new = strdup(tmp)) == NULL) {
    return NULL; }

  /* Relplace all spaces characters */
  p = new;
  while (*p) {
    if (*p == ' ') { *p = '_'; }
    p++; }

  return new; }
