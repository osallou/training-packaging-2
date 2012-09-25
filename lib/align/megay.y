/* megay.y - MEGA alignment parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "align.h"
#include "align/parse.h"
#include "align/megay.h"

int yylex(YYSTYPE *);
static void yyerror(align_t *, const char *);

int megay_check(FILE *);
align_t *megay_parse(FILE *);
%}

%pure-parser
%parse-param { align_t *ali }

%union { char *str; }

%token EXC DIE END EOL ERR SEM TXT
%token TAG KEY
%token <str> NAM BAS

%%

mega : header seqents end                          { return 0; /*NOTREACHED*/ }
     ;

header : tagline deflines ;

tagline : DIE TAG EOL ;

deflines : deflines defline | defline ;
defline : EXC KEY deftxt SEM EOL | KEY deftxt EOL ;
deftxt : deftxt TXT | ;

seqents : seqents seqent | seqent ;
seqent : namline seqlines                        { CHKERR(parse_seqnxt(ali)); }
       ;

namline : DIE namval EOL                         { CHKERR(parse_seqnew(ali)); }
        ;
namval : namval NAM                          { CHKERR(parse_tmpupd(ali, $2)); }
       | NAM                                 { CHKERR(parse_tmpupd(ali, $1)); }
       ;

seqlines : seqlines seqline | seqline ;
seqline : seqlist EOL ;
seqlist : seqlist BAS                        { CHKERR(parse_sequpd(ali, $2)); }
        | BAS                                { CHKERR(parse_sequpd(ali, $1)); }
        ;

end : END ;

%%


/* Checks MEGA sequence */
int megay_check(FILE *f) {
  extern FILE *megain;
  int i;

  megain = f;
  i = yyparse(NULL);

  return i; }


/* Parse MEGA alignment */
align_t *megay_parse(FILE *f) {
  extern FILE *megain;
  int i;
  align_t *ali;

  if ((ali = align_new()) == NULL) {
    return NULL; }

  megain = f;
  i = yyparse((void *)ali);
  if (i == 0 && ali->seq != NULL) {
    return ali; }

  return NULL; }


/* Helpers ... */

/*ARGSUSED*/
static void yyerror(align_t *ali, const char *s) { return; }
