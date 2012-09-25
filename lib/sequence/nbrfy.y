/* nbrfy.y - NBRF sequence parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/nbrfy.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

sequence_t *nbrfy_parse(FILE *);
int nbrfy_check(FILE *);
%}

%pure-parser
%parse-param { sequence_t *seq }

%union { char *str; }

%token END EOL ERR NUL SEM SPC SUP
%token <str> TXT
%token TAG
%token <str> BAS NAM

%%

nbrf : header sequence end            { return 0;  /*NOTREACHED*/ }
     | NUL                            { return -1; /*NOTREACHED*/ }
     ;

header : headname headdesc ;

headname : SUP TAG SEM hnam EOL ;

hnam : NAM                                           { parse_namadd(seq, $1); }
     ;

headdesc : headtxt EOL ;

headtxt : headtxt TXT                               { parse_dscadd2(seq, $2); }
        | /* Empty */
        ;

sequence : sequence BAS                              { parse_stradd(seq, $2); }
         | BAS                                       { parse_stradd(seq, $1); }
         ;

end : END ;

%%


/* Check NBRF sequence */
int nbrfy_check(FILE *f) {
  extern FILE *nbrfin;
  int i;

  nbrfin = f;

  i = yyparse(NULL);

  return i; }


/* Parse NBRF sequence */
sequence_t *nbrfy_parse(FILE *f) {
  extern FILE *nbrfin;
  int i;
  sequence_t *seq;

  nbrfin = f;

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
