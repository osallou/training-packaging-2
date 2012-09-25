/* rawy.y - RAW sequence parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/rawy.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *seq, const char *);

int rawy_check(FILE *);
sequence_t *rawy_parse(FILE *);
%}

%pure-parser
%parse-param { sequence_t *seq }

%union { char *str; }

%token ERR NUL
%token <str> BAS

%%

raw : sequence end                     { return 0;  /*NOTREACHED*/ }
    | NUL                              { return -1; /*NOTREACHED*/ }
    ;

sequence : sequence BAS                              { parse_stradd(seq, $2); }
         | BAS                                       { parse_stradd(seq, $1); }
         ;

end : NUL ;

%%


/* Checks RAW sequence */
int rawy_check(FILE *f) {
  extern FILE *rawin;
  int i;

  rawin = f;

  i = yyparse(NULL);

  return i; }


/* Parse RAW sequence */
sequence_t *rawy_parse(FILE *f) {
  extern FILE *rawin;
  int i;
  sequence_t *seq;

  rawin = f;

  if ((seq = sequence_new()) == NULL) {
    return NULL; }

  i = yyparse((void *)seq);
  if (i == 0) {
    return seq; }

  sequence_free(seq);

  return NULL; }


/* Helpers ... */

/*ARGSUSED*/
static void yyerror(sequence_t *seq, const char *s) { return; }
