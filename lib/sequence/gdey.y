/* gdey.y - GDE sequence parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/gdey.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

int gdey_check(FILE *);
sequence_t *gdey_parse(FILE *);
%}

%pure-parser
%parse-param { sequence_t *seq }

%union { char *str; }

%token END EOL ERR NUL
%token TAG
%token <str> NAM BAS

%%

gde : header sequence end              { return 0;  /*NOTREACHED*/ }
    | NUL                              { return -1; /*NOTREACHED*/ }
;

header : TAG headnam EOL ;

headnam : NAM                                        { parse_namadd(seq, $1); }
        ;

sequence : sequence BAS                              { parse_stradd(seq, $2); }
         | BAS                                       { parse_stradd(seq, $1); }
         ;

end : END ;

%%


/* Checks GDE sequence */
int gdey_check(FILE *f) {
  extern FILE *gdein;
  int i;

  gdein = f;

  i = yyparse(NULL);

  return i; }


/* Parse GDE sequence */
sequence_t *gdey_parse(FILE *f) {
  extern FILE *gdein;
  int i;
  sequence_t *seq;

  gdein = f;

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
