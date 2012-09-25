/* embly.y - EMBL sequence parser */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
#endif

#include "sequence.h"
#include "sequence/parse.h"
#include "sequence/embly.h"

int yylex(YYSTYPE *);
static void yyerror(sequence_t *, const char *);

int embly_check(FILE *);
sequence_t *embly_parse(FILE *);
%}

%pure-parser
%parse-param { sequence_t *seq }

%union { char *str; int num; }

%token EOL ERR INT MIN NUL NUM QUO SEP SPC TER TER2 TXT
%token CBR OBR

%token ID
%token <str> IDNAM
%token AC
%token <str> ACNUM
%token SV
%token <num> SVNUM
%token PR PRVAL PRNUM
%token DT
%token DE
%token <str> DETXT
%token KW
%token <str> KWORD KWOR2
%token OS
%token <str> OSTXT
%token OC
%token <str> OCNOD OCNO2
%token OG
%token RN
%token RC
%token RP
%token RX RXDB RXID
%token RG
%token RA RAAUT
%token RT
%token RL
%token DR
%token AH
%token AS
%token FH
%token FT
%token CC
%token CO
%token SQ
%token SEQ
%token <str> SEQBAS
%token END

%%

embl : annots sequence end           { return 0;  /*NOTREACHED*/ }
     | NUL                           { return -1; /*NOTREACHED*/ }
     ;

annots : locus access vers proj date desc kwords orgas refs dbref comm asmb feats ;

locus : idline ;
idline : ID IDNAM idtxt EOL                          { parse_namadd(seq, $2); }
       ;
idtxt : idtxt TXT | ;

access : access acline | ;
acline : AC aclist TER EOL ;
aclist : aclist SEP ACNUM                            { parse_accadd(seq, $3); }
       | ACNUM                                       { parse_accadd(seq, $1); }
       ;

vers : svline | ;
svline : SV ACNUM SEP SVNUM EOL                      { parse_veradd(seq, $4); }
       ;

proj : prline | ;
prline : PR PRVAL SEP PRNUM TER EOL ;

date : dtline dtline | ;
dtline : DT dttxt EOL ;
dttxt : dttxt TXT | TXT ;

desc : desc deline | ;
deline : DE detxt EOL ;
detxt : detxt DETXT                                 { parse_dscadd2(seq, $2); }
      | DETXT                                       { parse_dscadd1(seq, $1); }
      ;

kwords : kwlines kwline2 | ;
kwlines : kwlines kwline1 | kwlines kwline3 | ;
kwline1 : KW kwlist TER2 EOL ;
kwline2 : KW kwlist TER EOL ;
kwline3 : KW kwlist EOL ;
kwlist : kwlist SEP KWORD                            { parse_kwdadd(seq, $3); }
       | KWORD                                       { parse_kwdadd(seq, $1); }
       | KWOR2                                       { parse_kwdupd(seq, $1); }
       | /* Empty */
       ;

orgas : orgas orgent | ;
orgent : orgspe orgcla orggan ;

orgspe : osline ;
osline : OS ostxt EOL ;
ostxt : OSTXT ;

orgcla : oclines ocline2 | ;
oclines : oclines ocline1 | ;
ocline1 : OC oclist TER2 EOL | OC oclist EOL ;
ocline2 : OC oclist TER EOL ;
oclist : oclist SEP ocnode | ocnode | ;
ocnode : OCNOD | OCNO2 ;

orggan : orggan ogline | ;
ogline : OG ogtxt EOL ;
ogtxt : ogtxt TXT | TXT ;

refs : refs refent | ;
refent : refnum refcom refpos refxdb refgrp refaut reftit refloc ;

refnum : rnline ;
rnline : RN OBR INT CBR EOL ;

refcom : refcom rcline | ;
rcline : RC rctxt EOL ;
rctxt : rctxt TXT | TXT ;

refpos : rplines rpline2 | ;
rplines : rplines rpline1 | ;
rpline1 : RP rplist TER EOL ;
rpline2 : RP rplist EOL ;
rplist : rplist SEP rpval | rpval ;
rpval : INT MIN INT ;

refxdb : refxdb rxline | ;
rxline : RX RXDB SEP RXID TER EOL ;

refgrp : refgrp rgline | ;
rgline : RG rgtxt EOL ;
rgtxt : rgtxt TXT | TXT ;

refaut : ralines raline2 ;
ralines : ralines raline1 | ;
raline1 : RA ralist TER2 EOL ;
raline2 : RA ralist TER EOL ;
ralist : ralist SEP RAAUT | RAAUT | ;

reftit : rtline1 rtlines rtline3 | rtline | ;
rtlines : rtlines rtline2 | ;
rtline : RT QUO rttxt QUO TER EOL | RT TER EOL ;
rtline1 : RT QUO rttxt EOL ;
rtline2 : RT rttxt EOL ;
rtline3 : RT rttxt QUO TER EOL | RT QUO TER EOL ;
rttxt : rttxt TXT | TXT ;

refloc : refloc rlline | rlline ;
rlline : RL rltxt EOL ;
rltxt : rltxt TXT | TXT ;

dbref : dbref drline | ;
drline : DR drtxt EOL ;
drtxt : drtxt TXT | TXT ;

feats : feathead featdata | ;

asmb : ahline aslines | ;
ahline : AH ahtxt EOL ;
ahtxt : ahtxt TXT | TXT ;
aslines : aslines asline | asline ;
asline : AS astxt EOL ;
astxt : astxt TXT | TXT ;

feathead : fhline fhline ;
fhline : FH fhtxt EOL ;
fhtxt : fhtxt TXT | ;

featdata : featdata ftline | ftline ;
ftline : FT fttxt EOL ;
fttxt : fttxt TXT | TXT ;

comm : comm ccline | ;
ccline : CC cctxt EOL ;
cctxt : cctxt TXT | ;

sequence : seqcont seqhead seqdata | seqcont | seqhead seqdata ;

seqcont : seqcont coline | coline ;
coline : CO cotxt EOL ;
cotxt : cotxt TXT | TXT ;

seqhead : sqline ;
sqline : SQ sqtxt EOL ;
sqtxt : sqtxt TXT | TXT ;

seqdata : seqdata seqline | seqline ;
seqline : SEQ seqlist seqnum EOL ;
seqlist : seqlist SEP SEQBAS                         { parse_stradd(seq, $3); }
        | SEQBAS                                     { parse_stradd(seq, $1); }
        ;
seqnum : SPC INT | ;

end : END EOL ;

%%


/* Checks EMBL sequence */
int embly_check(FILE *f) {
  extern FILE *emblin;
  int i;

  emblin = f;
  i = yyparse(NULL);

  return i; }


/* Parse EMBL sequence */
sequence_t *embly_parse(FILE *f) {
  extern FILE *emblin;
  int i;
  sequence_t *seq;

  emblin = f;

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
