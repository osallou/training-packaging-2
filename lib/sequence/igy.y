/* igy.y - IG sequence parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/igy.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

int igy_check(FILE *);
sequence_t *igy_parse(FILE *);
%}

%pure-parser
%parse-param { sequence_t *seq }

%union { char *str; }

%token EOL ERR NUL SEM
%token <str> TXT
%token <str> NAM
%token <str> BAS
%token TYP
%token END

%%

ig : header sequence end               { return 0;  /*NOTREACHED*/ }
   | NUL                               { return -1; /*NOTREACHED*/ }
   ;

header : headcom headnam ;

headcom : headcom comline | comline ;
comline : SEM comtxt EOL ;
comtxt : comtxt TXT                                 { parse_dscadd2(seq, $2); }
       | /* Empty */
       ;

headnam : namtxt EOL ;
namtxt : NAM                                         { parse_namadd(seq, $1); }
       | /* Empty */
       ;

sequence : seqlist seqtype ;
seqlist : seqlist BAS                                { parse_stradd(seq, $2); }
        | BAS                                        { parse_stradd(seq, $1); }
        ;
seqtype : TYP | ;

end : END ;

%%


/* Checks IG sequence */
int igy_check(FILE *f) {
  extern FILE *igin;
  int i;

  igin = f;

  i = yyparse(NULL);

  return i; }


/* Parse IG sequence */
sequence_t *igy_parse(FILE *f) {
  extern FILE *igin;
  int i;
  sequence_t *seq;

  igin = f;

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
