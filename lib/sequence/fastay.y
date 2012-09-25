/* fastay.y - FASTA sequence parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/fastay.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

int fastay_check(FILE *);
sequence_t *fastay_parse(FILE *);
%}

%pure-parser
%parse-param { sequence_t *seq }

%union { char *str; }

%token END EOL ERR NUL SPC SUP
%token <str> BAS NAM TXT

%%

fasta : header sequence end            { return 0;  /*NOTREACHED*/ }
      | NUL                            { return -1; /*NOTREACHED*/ }
      ;

header : SUP headtxt EOL ;

headtxt : headname SPC headdesc | headname ;

headname : headname NAM                              { parse_namadd(seq, $2); }
         | /* Empty */
         ;

headdesc : headdesc TXT                             { parse_dscadd2(seq, $2); }
         | /* Empty */
         ;

sequence : sequence BAS                              { parse_stradd(seq, $2); }
         | BAS                                       { parse_stradd(seq, $1); }
         ;

end : END ;

%%


/* Checks FASTA sequence */
int fastay_check(FILE *f) {
  extern FILE *fastain;
  int i;

  fastain = f;

  i = yyparse(NULL);

  return i; }


/* Parse FASTA sequence */
sequence_t *fastay_parse(FILE *f) {
  extern FILE *fastain;
  int i;
  sequence_t *seq;

  fastain = f;

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
