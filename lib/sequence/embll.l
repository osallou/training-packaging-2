/* embll.l - EMBL sequence lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "sequence/embly.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x IDTAG ACTAG SVTAG PRTAG DTTAG DETAG KWTAG OSTAG OCTAG OGTAG RNTAG RCTAG
%x RPTAG RXTAG RGTAG RATAG RTTAG RLTAG DRTAG AHTAG ASTAG FHTAG FTTAG CCTAG
%x COTAG SQTAG
%x SEQTAG ENDTAG
%x IDTA2 RXTA2 RTTA2

alp            [[:alpha:]]
aln            [[:alnum:]]
cbr            "]"
col            ":"
com            ","
dig            [[:digit:]]
dot            "."
eol            "\n"
min            "-"
obr            "["
quo            "\""
sem            ";"
sla            "/"
spc            " "
sta            "*"
und            "_"

txt            .{1,80}

idnam          [^ ;\n]{1,13}
idcla          standard
idtyp          ((genomic|other|unassigned){spc}|pre{min}|sno?|sc|[mrt])
idmol          (circular{spc})?{idtyp}?([DR]NA|UKN)
iddiv          (CON|EST|FUN|GSS|HT[CG]|HUM|INV|MAM|MUS|ORG|PHG|PLN|PRO|ROD|STS|SYN|UNC|VR[LT]|XXX)

acnum          [^ ;\n]{1,75}

prval          Project

kwwrd          [^; \n][^;\n]{0,80}
kword          {kwwrd}({sem}{kwwrd})*

ocnod          [^;\n]{1,80}

rxdb           (AGRICOLA|DOI|MEDLINE|PUBMED)
rxid           .{1,80}

raaut          [^,;\n]{1,80}

gap            {min}
bas            ({alp}|{gap}){1,10}

%%

^{spc}*{eol}   ; /* Empty lines ignored */
^XX{eol}       ; /* Spacers ignored */

^ST{spc}{sta}{spc}.*{eol} ; /* Skip internal release status tag */
^AC{spc}{sta}{spc}.*{eol} ; /* Skip internal identifier tag */
^BQ{spc}{sta}{spc}.*{eol} ; /* Skip internal base quality tag */

^ID{spc}{3}    { BEGIN IDTAG; return ID; }
<IDTAG>{idnam} { BEGIN IDTA2; yylval->str = strdup(yytext); return IDNAM; }
<IDTAG>{eol}   { BEGIN INITIAL; return EOL; }
<IDTAG>.       { return ERR; }

<IDTA2>{txt}   { return TXT; }
<IDTA2>{eol}   { BEGIN INITIAL; return EOL; }

^AC{spc}{3}    { BEGIN ACTAG; return AC; }
<ACTAG>{acnum} { yylval->str = strdup(yytext); return ACNUM; }
<ACTAG>{sem}{spc} { return SEP; }
<ACTAG>{sem}{spc}?/{eol} { return TER; }
<ACTAG>{eol}   { BEGIN INITIAL; return EOL; }
<ACTAG>.       { return ERR; }

^SV{spc}{3}    { BEGIN SVTAG; return SV; }
<SVTAG>{acnum} { return ACNUM; }
<SVTAG>{dot}   { return SEP; }
<SVTAG>{dig}+  { yylval->num = atoi(yytext); return SVNUM; }
<SVTAG>{eol}   { BEGIN INITIAL; return EOL; }
<SVTAG>.       { return ERR; }

^PR{spc}{3}    { BEGIN PRTAG; return PR; }
<PRTAG>{prval} { return PRVAL; }
<PRTAG>{col}   { return SEP; }
<PRTAG>{sem}   { return TER; }
<PRTAG>{dig}+  { return PRNUM; }
<PRTAG>{eol}   { BEGIN INITIAL; return EOL; }
<PRTAG>.       { return ERR; }

^DT{spc}{3}    { BEGIN DTTAG; return DT; }
<DTTAG>{txt}   { return TXT; }
<DTTAG>{eol}   { BEGIN INITIAL; return EOL; }

^DE{spc}{3}    { BEGIN DETAG; return DE; }
<DETAG>{txt}   { yylval->str = strdup(yytext); return DETXT; }
<DETAG>{eol}   { BEGIN INITIAL; return EOL; }

^KW{spc}{3}    { BEGIN KWTAG; return KW; }
<KWTAG>{sem}{spc} { return SEP; }
<KWTAG>{sem}{spc}?/{eol} { return TER2; }
<KWTAG>{dot}{spc}?/{eol} { return TER; }
<KWTAG>{kword}/{eol}KW { yylval->str = strdup(yytext); return KWOR2; }
<KWTAG>{kword}/{sem}{spc} { yylval->str = strdup(yytext); return KWORD; }
<KWTAG>{kword}/{sem}{eol} { yylval->str = strdup(yytext); return KWORD; }
<KWTAG>{kword}/{dot}{eol} { yylval->str = strdup(yytext); return KWORD; }
<KWTAG>{kword}/{dot}{spc}{eol} { yylval->str = strdup(yytext); return KWORD; }
<KWTAG>{eol}   { BEGIN INITIAL; return EOL; }
<KWTAG>.       { return ERR; }

^OS{spc}{3}    { BEGIN OSTAG; return OS; }
<OSTAG>{txt}   { return OSTXT; }
<OSTAG>{eol}   { BEGIN INITIAL; return EOL; }

^OC{spc}{3}    { BEGIN OCTAG; return OC; }
<OCTAG>{sem}{spc} { return SEP; }
<OCTAG>{sem}{spc}?/{eol} { return TER2; }
<OCTAG>{dot}{spc}?/{eol} { return TER; }
<OCTAG>{ocnod}/{sem}{spc} { return OCNOD; }
<OCTAG>{ocnod}/{sem}{eol} { return OCNOD; }
<OCTAG>{ocnod}{dot}/{eol}OC { return OCNO2; }
<OCTAG>{ocnod}/{dot}{eol} { return OCNOD; }
<OCTAG>{ocnod}/{dot}{spc}{eol} { return OCNOD; }
<OCTAG>{eol}   { BEGIN INITIAL; return EOL; }
<OCTAG>.       { return ERR; }

^OG{spc}{3}    { BEGIN OGTAG; return OG; }
<OGTAG>{txt}   { return TXT; }
<OGTAG>{eol}   { BEGIN INITIAL; return EOL; }

^RN{spc}{3}    { BEGIN RNTAG; return RN; }
<RNTAG>{obr}   { return OBR; }
<RNTAG>{cbr}   { return CBR; }
<RNTAG>{dig}+  { return INT; }
<RNTAG>{eol}   { BEGIN INITIAL; return EOL; }
<RNTAG>.       { return ERR; }

^RC{spc}{3}    { BEGIN RCTAG; return RC; }
<RCTAG>{txt}   { return TXT; }
<RCTAG>{eol}   { BEGIN INITIAL; return EOL; }

^RP{spc}{3}    { BEGIN RPTAG; return RP; }
<RPTAG>{min}   { return MIN; }
<RPTAG>{com}{spc} { return SEP; }
<RPTAG>{com}/{eol} { return TER; }
<RPTAG>{dig}+  { return INT; }
<RPTAG>{eol}   { BEGIN INITIAL; return EOL; }
<RPTAG>.       { return ERR; }

^RX{spc}{3}    { BEGIN RXTAG; return RX; }
<RXTAG>{sem}{spc} { BEGIN RXTA2; return SEP; }
<RXTAG>{rxdb}/{sem}{spc} { return RXDB; }
<RXTAG>{eol}   { return ERR; }
<RXTAG>.       { return ERR; }

<RXTA2>{rxid}/{dot}{eol} { return RXID; }
<RXTA2>{dot}/{eol} { return TER; }
<RXTA2>{eol}   { BEGIN INITIAL; return EOL; }
<RXTA2>.       { return ERR; }

^RG{spc}{3}    { BEGIN RGTAG; return RG; }
<RGTAG>{txt}   { return TXT; }
<RGTAG>{eol}   { BEGIN INITIAL; return EOL; }

^RA{spc}{3}    { BEGIN RATAG; return RA; }
<RATAG>{com}{spc} { return SEP; }
<RATAG>{com}/{eol} { return TER2; }
<RATAG>{sem}/{eol} { return TER; }
<RATAG>{raaut} { return RAAUT; }
<RATAG>{eol}   { BEGIN INITIAL; return EOL; }
<RATAG>.       { return ERR; }

^RT{spc}{3}    { BEGIN RTTAG; return RT; }
<RTTAG>{quo}   { BEGIN RTTA2; return QUO; }
<RTTAG>{sem}/{eol} { return TER; }
<RTTAG>{eol}   { BEGIN INITIAL; return EOL; }

<RTTA2>^RT{spc}{3}/{txt}{eol} { return RT; }
<RTTA2>{quo}/{sem}{eol} { BEGIN RTTAG; return QUO; }
<RTTA2>{txt}/{quo}{sem}{eol} { return TXT; }
<RTTA2>{txt}   { return TXT; }
<RTTA2>{eol}   { return EOL; }

^RL{spc}{3}    { BEGIN RLTAG; return RL; }
<RLTAG>{txt}   { return TXT; }
<RLTAG>{eol}   { BEGIN INITIAL; return EOL; }

^DR{spc}{3}    { BEGIN DRTAG; return DR; }
<DRTAG>{txt}   { return TXT; }
<DRTAG>{eol}   { BEGIN INITIAL; return EOL; }

^AH{spc}{3}    { BEGIN AHTAG; return AH; }
<AHTAG>{txt}   { return TXT; }
<AHTAG>{eol}   { BEGIN INITIAL; return EOL; }

^AS{spc}{3}    { BEGIN ASTAG; return AS; }
<ASTAG>{txt}   { return TXT; }
<ASTAG>{eol}   { BEGIN INITIAL; return EOL; }

^FH({spc}{3})? { BEGIN FHTAG; return FH; }
<FHTAG>{txt}   { return TXT; }
<FHTAG>{eol}   { BEGIN INITIAL; return EOL; }

^FT{spc}{3}    { BEGIN FTTAG; return FT; }
<FTTAG>{txt}   { return TXT; }
<FTTAG>{eol}   { BEGIN INITIAL; return EOL; }

^CC{spc}{3}    { BEGIN CCTAG; return CC; }
<CCTAG>{txt}   { return TXT; }
<CCTAG>{eol}   { BEGIN INITIAL; return EOL; }

^CO{spc}{3}    { BEGIN COTAG; return CO; }
<COTAG>{txt}   { return TXT; }
<COTAG>{eol}   { BEGIN INITIAL; return EOL; }

^SQ{spc}{3}    { BEGIN SQTAG; return SQ; }
<SQTAG>{txt}   { return TXT; }
<SQTAG>{eol}   { BEGIN INITIAL; return EOL; }

^{spc}{5}      { BEGIN SEQTAG; return SEQ; }
<SEQTAG>{bas}  { yylval->str = strdup(yytext); return SEQBAS; }
<SEQTAG>{dig}+ { return INT; }
<SEQTAG>{spc}+/{dig} { return SPC; }
<SEQTAG>{spc}  { return SEP; }
<SEQTAG>{eol}  { BEGIN INITIAL; return EOL; }
<SEQTAG>.      { return ERR; }

^{sla}{2}      { BEGIN ENDTAG; return END; }
<ENDTAG>{eol}  { BEGIN INITIAL; return EOL; }
<ENDTAG><<EOF>> { BEGIN INITIAL; return EOL; }
<ENDTAG>.      { return ERR; }

<<EOF>>        { return NUL; }
{eol}          { return ERR; }
.              { return ERR; }

%%
