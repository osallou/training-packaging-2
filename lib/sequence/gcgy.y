/* gcgy.y - GCG sequence parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/gcgy.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

int gcgy_check(FILE *);
sequence_t *gcgy_parse(FILE *);
%}

%pure-parser
%parse-param { sequence_t *seq }

%union { char *str; }

%token END EOL ERR INT NUL SPC TER
%token <str> TXT BAS

%%

gcg : header sequence end              { return 0;  /*NOTREACHED*/ }
    | NUL                              { return -1; /*NOTREACHED*/ }
    ;

header : headlines headline2 ;
headlines : headlines headline1 | ;
headline1 : headtxt EOL ;
headline2 : headtxt TER EOL ;
headtxt : headtxt TXT
        | /* Empty */
        ;

sequence : sequence seqline | seqline ;
seqline : INT SPC seqlist EOL ;
seqlist : seqlist SPC BAS                            { parse_stradd(seq, $3); }
        | BAS                                        { parse_stradd(seq, $1); }
        ;

end : END ;

%%


/* Checks GCG sequence */
int gcgy_check(FILE *f) {
  extern FILE *gcgin;
  int i;

  gcgin = f;

  i = yyparse(NULL);

  return i; }


/* Parse GCG sequence */
sequence_t *gcgy_parse(FILE *f) {
  extern FILE *gcgin;
  int i;
  sequence_t *seq;

  gcgin = f;

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
