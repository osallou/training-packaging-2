/* sproty.y - SWISSPROT sequence parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/sproty.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *seq, const char *);

int sproty_check(FILE *);
sequence_t *sproty_parse(FILE *);
%}

%pure-parser
%parse-param { sequence_t *seq }

%union { char *str; }

%token EOL EQU ERR INT NUL QUO SEP SPC TER TER2 TER3 TXT
%token CBR OBR

%token ID
%token <str> IDNAM
%token AC
%token <str> ACNUM
%token DT
%token DE
%token <str> DETXT
%token GN
%token OS
%token <str> OSTXT OSTX2
%token OG
%token OC
%token <str> OCNOD
%token OX
%token OH
%token RN
%token RP
%token RC
%token RX RXKEY RXVAL
%token RG
%token RA RAAUT
%token RT
%token RL
%token CC
%token DR DRVAL DRVAL2
%token PE
%token KW
%token <str> KWORD
%token FT
%token SQ
%token SEQ
%token <str> SEQBAS
%token END

%%

sprot : annots sequence end           { return 0;  /*NOTREACHED*/ }
      | NUL                           { return -1; /*NOTREACHED*/ }
      ;

annots : locus access date desc gene orga refs comm dbref exist kwrds feats ;

locus : idline ;
idline : ID IDNAM idtxt EOL                          { parse_namadd(seq, $2); }
       ;
idtxt : idtxt TXT | SPC ;

access : access acline | ;
acline : AC aclist TER EOL ;
aclist : aclist SEP ACNUM                            { parse_accadd(seq, $3); }
       | ACNUM                                       { parse_accadd(seq, $1); }
       ;

date : dtline dtline dtline | ;
dtline : DT dttxt EOL ;
dttxt : dttxt TXT | TXT ;

desc : delines deline2 | delines deline1 | ;
delines : delines deline1 | ;
deline1 : DE detxt EOL ;
deline2 : DE detxt TER EOL | DE TER EOL ;
detxt : detxt DETXT                                 { parse_dscadd2(seq, $2); }
      | DETXT                                       { parse_dscadd1(seq, $1); }
      ;

gene : gene gnline | ;
gnline : GN gntxt EOL ;
gntxt : gntxt TXT | TXT ;

orga : orgspe orggan orgcla orgtax orghos ;

orgspe : osents osent3 | osent3 | ;
osents : osentt osent2 | osent2 ;
osentt : osentt osent1 | osent1 ;
osent1 : oslines osline1 ;
osent2 : oslines osline2 ;
osent3 : oslines osline3 ;
oslines : oslines osline | ;
osline : OS ostxt EOL ;
osline1 : OS ostxt TER3 EOL ;
osline2 : OS ostxt TER2 EOL ;
osline3 : OS ostxt TER EOL ;
ostxt : OSTXT | OSTX2 ;

orggan : orggan ogline | ;
ogline : OG ogtxt EOL ;
ogtxt : ogtxt TXT | TXT ;

orgcla : oclines ocline2 | ;
oclines : oclines ocline1 | ;
ocline1 : OC oclist TER2 EOL ;
ocline2 : OC oclist TER EOL ;
oclist : oclist SEP OCNOD | OCNOD ;

orgtax : orgtax oxline | ;
oxline : OX oxtxt EOL ;
oxtxt : oxtxt TXT | TXT ;

orghos : orghos ohline | ;
ohline : OH ohtxt EOL ;
ohtxt : ohtxt TXT | TXT ;

refs : refs refent | ;
refent : refnum refpos refcom refxdb refper reftit refloc ;
refper : refgrp refaut | refgrp | refaut ;

refnum : rnline ;
rnline : RN OBR INT CBR EOL ;

refpos : rplines rpline2 ;
rplines : rplines rpline1 | ;
rpline1 : RP rptxt EOL ;
rpline2 : RP rptxt TER EOL ;
rptxt : rptxt TXT | TXT ;

refcom : refcom rcline | ;
rcline : RC rctxt EOL ;
rctxt : rctxt TXT | TXT ;

refxdb : rxlines | rxline1 | ;
rxlines : rxlines rxline | rxline ;
rxline : RX rxlist TER EOL ;
rxline1 : RX rxent1 TER2 EOL ;
rxlist : rxlist SEP rxent | rxent ;
rxent : RXKEY EQU RXVAL ;
rxent1 : RXKEY SEP RXVAL ;

refgrp : rglines rgline2 ;
rglines : rglines rgline1 | ;
rgline1 : RG rgtxt EOL ;
rgline2 : RG rgtxt TER EOL ;
rgtxt : rgtxt TXT | TXT ;

refaut : ralines raline2 ;
ralines : ralines raline1 | ;
raline1 : RA ralist TER2 EOL ;
raline2 : RA ralist TER EOL ;
ralist : ralist SEP RAAUT | RAAUT ;

reftit : rtline1 rtlines rtline3 | rtline | ;
rtlines : rtlines rtline2 | ;
rtline : RT QUO rttxt QUO TER EOL ;
rtline1 : RT QUO rttxt EOL ;
rtline2 : RT rttxt EOL ;
rtline3 : RT rttxt QUO TER EOL ;
rttxt : rttxt TXT | TXT ;

refloc : rllines rlline2 | ;
rllines : rllines rlline1 | ;
rlline1 : RL rltxt EOL ;
rlline2 : RL rltxt TER EOL ;
rltxt : rltxt TXT | TXT ;

comm : comm ccline | ;
ccline : CC cctxt EOL ;
cctxt : cctxt TXT | TXT ;

dbref : dbref drline | ;
drline : DR drlist TER EOL ;
drlist : DRVAL SEP DRVAL SEP DRVAL dropt ;
dropt : SEP DRVAL SEP DRVAL | SEP DRVAL | ;

exist: peline | ;
peline : PE petxt TER EOL ;
petxt : petxt TXT | TXT ;

kwrds : kwlines kwline2 | ;
kwlines : kwlines kwline1 | ;
kwline1 : KW kwlist TER2 EOL ;
kwline2 : KW kwlist TER EOL ;
kwlist : kwlist SEP KWORD                            { parse_kwdadd(seq, $3); }
       | KWORD                                       { parse_kwdadd(seq, $1); }
       | /* Empty */
       ;

feats : feats ftline | ;
ftline : FT fttxt EOL ;
fttxt : fttxt TXT | TXT ;

sequence : seqhead seqdata ;

seqhead : sqline ;
sqline : SQ sqtxt EOL ;
sqtxt : sqtxt TXT | TXT ;

seqdata : seqdata seqline | seqline ;
seqline : SEQ seqlist EOL ;
seqlist : seqlist SPC SEQBAS                         { parse_stradd(seq, $3); }
        | SEQBAS                                     { parse_stradd(seq, $1); }
        ;

end : END EOL ;

%%


/* Check SPROT sequence */
int sproty_check(FILE *f) {
  extern FILE *sprotin;
  int i;

  sprotin = f;

  i = yyparse(NULL);

  return i; }


/* Parse SPROT sequence */
sequence_t *sproty_parse(FILE *f) {
  extern FILE *sprotin;
  int i;
  sequence_t *seq;

  sprotin = f;

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
