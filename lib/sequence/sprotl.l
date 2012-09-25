/* sprotl.l - SWISSPROT sequence lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "sequence/sproty.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x IDTAG ACTAG DTTAG DETAG GNTAG OSTAG OGTAG OCTAG OXTAG OHTAG RNTAG RPTAG
%x RCTAG RXTAG RGTAG RATAG RTTAG RLTAG CCTAG DRTAG PETAG KWTAG FTTAG SQTAG
%x SEQTAG ENDTAG
%x IDTA2

alp            [[:alpha:]]
aln            [[:alnum:]]
cbr            "]"
com            ","
dig            [[:digit:]]
dot            "."
eol            "\n"
equ            "="
obr            "["
quo            "\""
sem            ";"
sla            "/"
spc            " "
und            "_"

txt            .{1,80}

idnam          ({spnam}|{trnam}|{xxnam})
spnam          {aln}{1,5}_{aln}{1,5}
trnam          {aln}{6,8}
xxnam          [^ \n]{1,14}

acnum          ({aln}{6,8}|{alp}+{und}?{dig}+)

ostxt          [^,\n][^\n]{0,79}

ocnod          [^;\n]{1,80}

rxkey          (AGRICOLA|MEDLINE|PubMed|DOI)
rxval          [^=\n]{1,80}
rxval2         [^=;\n]{1,80}

raaut          [^,;\n]{1,80}

rttxt          [^"\n]{1,80}

drwrd          [^; \n][^;\n]{0,150}
drval          {drwrd}({sem}{drwrd})*

kword          [^;\n.]{1,80}

seqbas         {alp}{1,10}

%%

^{eol}         ; /* Empty lines ignored */

^ID{spc}{3}    { BEGIN IDTAG; return ID; }
<IDTAG>{idnam} { yylval->str = strdup(yytext); return IDNAM; }
<IDTAG>{spc}+  { BEGIN IDTA2; return SPC; }
<IDTAG>{eol}   { BEGIN INITIAL; return EOL; }

<IDTA2>{txt}   { return TXT; }
<IDTA2>{eol}   { BEGIN INITIAL; return EOL; }

^AC{spc}{3}    { BEGIN ACTAG; return AC; }
<ACTAG>{acnum} { yylval->str = strdup(yytext); return ACNUM; }
<ACTAG>{sem}{spc} { return SEP; }
<ACTAG>{sem}/{eol} { return TER; }
<ACTAG>{eol}   { BEGIN INITIAL; return EOL; }
<ACTAG>.       { return ERR; }

^DT{spc}{3}    { BEGIN DTTAG; return DT; }
<DTTAG>{txt}   { return TXT; }
<DTTAG>{eol}   { BEGIN INITIAL; return EOL; }

^DE{spc}{3}    { BEGIN DETAG; return DE; }
<DETAG>{dot}/{eol} { return TER; }
<DETAG>{txt}/{dot}{eol} { yylval->str = strdup(yytext); return DETXT; }
<DETAG>{txt}   { yylval->str = strdup(yytext); return DETXT; }
<DETAG>{eol}   { BEGIN INITIAL; return EOL; }

^GN{spc}{3}    { BEGIN GNTAG; return GN; }
<GNTAG>{txt}   { return TXT; }
<GNTAG>{eol}   { BEGIN INITIAL; return EOL; }

^OS{spc}{3}    { BEGIN OSTAG; return OS; }
<OSTAG>{com}/{eol} { return TER3; }
<OSTAG>{com}{spc}and/{eol} { return TER2; }
<OSTAG>{dot}/{eol} { return TER; }
<OSTAG>{ostxt}/{dot}{eol} { return OSTXT; }
<OSTAG>{ostxt}/{com}{spc}and{eol}OS { return OSTXT; }
<OSTAG>{ostxt}/{com}{eol}OS { return OSTXT; }
<OSTAG>{ostxt}/{eol}OS { return OSTX2; }
<OSTAG>{eol}   { BEGIN INITIAL; return EOL; }
<OSTAG>.       { return ERR; }

^OG{spc}{3}    { BEGIN OGTAG; return OG; }
<OGTAG>{txt}   { return TXT; }
<OGTAG>{eol}   { BEGIN INITIAL; return EOL; }

^OC{spc}{3}    { BEGIN OCTAG; return OC; }
<OCTAG>{sem}{spc} { return SEP; }
<OCTAG>{sem}/{eol} { return TER2; }
<OCTAG>{dot}/{eol} { return TER; }
<OCTAG>{ocnod}/{sem}{spc} { return OCNOD; }
<OCTAG>{ocnod}/{sem}{eol} { return OCNOD; }
<OCTAG>{ocnod}/{dot}{eol} { return OCNOD; }
<OCTAG>{eol}   { BEGIN INITIAL; return EOL; }
<OCTAG>.       { return ERR; }

^OX{spc}{3}    { BEGIN OXTAG; return OX; }
<OXTAG>{txt}   { return TXT; }
<OXTAG>{eol}   { BEGIN INITIAL; return EOL; }

^OH{spc}{3}    { BEGIN OHTAG; return OH; }
<OHTAG>{txt}   { return TXT; }
<OHTAG>{eol}   { BEGIN INITIAL; return EOL; }

^RN{spc}{3}    { BEGIN RNTAG; return RN; }
<RNTAG>{obr}   { return OBR; }
<RNTAG>{cbr}   { return CBR; }
<RNTAG>{dig}+  { return INT; }
<RNTAG>{eol}   { BEGIN INITIAL; return EOL; }
<RNTAG>.       { return ERR; }

^RP{spc}{3}    { BEGIN RPTAG; return RP; }
<RPTAG>{dot}/{eol} { return TER; }
<RPTAG>{txt}/{dot}{eol} { return TXT; }
<RPTAG>{txt}/{eol}RP { return TXT; }
<RPTAG>{eol}   { BEGIN INITIAL; return EOL; }
<RPTAG>.       { return ERR; }

^RC{spc}{3}    { BEGIN RCTAG; return RC; }
<RCTAG>{txt}   { return TXT; }
<RCTAG>{eol}   { BEGIN INITIAL; return EOL; }

^RX{spc}{3}    { BEGIN RXTAG; return RX; }
<RXTAG>{equ}   { return EQU; }
<RXTAG>{sem}{spc} { return SEP; }
<RXTAG>{sem}/{eol} { return TER; }
<RXTAG>{dot}/{eol} { return TER2; }
<RXTAG>{rxkey}/{equ} { return RXKEY; }
<RXTAG>{rxkey}/{sem}{spc} { return RXKEY; }
<RXTAG>{rxval}/{sem} { return RXVAL; }
<RXTAG>{rxval2}/{dot}{eol} { return RXVAL; }
<RXTAG>{eol}   { BEGIN INITIAL; return EOL; }
<RXTAG>.       { return ERR; }

^RG{spc}{3}    { BEGIN RGTAG; return RG; }
<RGTAG>{sem}/{eol} { return TER; }
<RGTAG>{txt}/{sem}{eol} { return TXT; }
<RGTAG>{txt}/{eol}RG { return TXT; }
<RGTAG>{eol}   { BEGIN INITIAL; return EOL; }
<RGTAG>.       { return ERR; }

^RA{spc}{3}    { BEGIN RATAG; return RA; }
<RATAG>{com}{spc} { return SEP; }
<RATAG>{com}/{eol} { return TER2; }
<RATAG>{sem}/{eol} { return TER; }
<RATAG>{raaut}/{com} { return RAAUT; }
<RATAG>{raaut}/{sem} { return RAAUT; }
<RATAG>{eol}   { BEGIN INITIAL; return EOL; }
<RATAG>.       { return ERR; }

^RT{spc}{3}    { BEGIN RTTAG; return RT; }
<RTTAG>{sem}/{eol} { return TER; }
<RTTAG>{quo}   { return QUO; }
<RTTAG>{rttxt} { return TXT; }
<RTTAG>{eol}   { BEGIN INITIAL; return EOL; }

^RL{spc}{3}    { BEGIN RLTAG; return RL; }
<RLTAG>{dot}/{eol} { return TER; }
<RLTAG>{txt}/{dot}{eol} { return TXT; }
<RLTAG>{txt}/{eol}RL { return TXT; }
<RLTAG>{eol}   { BEGIN INITIAL; return EOL; }
<RLTAG>.       { return ERR; }

^CC{spc}{3}    { BEGIN CCTAG; return CC; }
<CCTAG>{txt}   { return TXT; }
<CCTAG>{eol}   { BEGIN INITIAL; return EOL; }

^DR{spc}{3}    { BEGIN DRTAG; return DR; }
<DRTAG>{sem}{spc} { return SEP; }
<DRTAG>{dot}/{eol} { return TER; }
<DRTAG>{drval}/{sem}{spc} { return DRVAL; }
<DRTAG>{drval}/{dot}{eol} { return DRVAL; }
<DRTAG>{eol}   { BEGIN INITIAL; return EOL; }
<DRTAG>.       { return ERR; }

^PE{spc}{3}    { BEGIN PETAG; return PE; }
<PETAG>{sem}/{eol} { return TER; }
<PETAG>{txt}/{sem}{eol} { return TXT; }
<PETAG>{eol}   { BEGIN INITIAL; return EOL; }
<PETAG>.       { return ERR; }

^KW{spc}{3}    { BEGIN KWTAG; return KW; }
<KWTAG>{sem}{spc} { return SEP; }
<KWTAG>{dot}/{eol} { return TER; }
<KWTAG>{sem}/{eol} { return TER2; }
<KWTAG>{kword}/{sem}{spc} { yylval->str = strdup(yytext); return KWORD; }
<KWTAG>{kword}/{sem}{eol} { yylval->str = strdup(yytext); return KWORD; }
<KWTAG>{kword}/{dot}{eol} { yylval->str = strdup(yytext); return KWORD; }
<KWTAG>{eol}   { BEGIN INITIAL; return EOL; }
<KWTAG>.       { return ERR; }

^FT{spc}{3}    { BEGIN FTTAG; return FT; }
<FTTAG>{txt}   { return TXT; }
<FTTAG>{eol}   { BEGIN INITIAL; return EOL; }

^SQ{spc}{3}    { BEGIN SQTAG; return SQ; }
<SQTAG>{txt}   { return TXT; }
<SQTAG>{eol}   { BEGIN INITIAL; return EOL; }

^{spc}{5}      { BEGIN SEQTAG; return SEQ; }
<SEQTAG>{seqbas} { yylval->str = strdup(yytext); return SEQBAS; }
<SEQTAG>{spc}  { return SPC; }
<SEQTAG>{eol}  { BEGIN INITIAL; return EOL; }
<SEQTAG>.      { return ERR; }

^{sla}{2}      { BEGIN ENDTAG; return END; }
<ENDTAG>{spc}+/{eol} ; /* Trailing spaces ignored */
<ENDTAG><<EOF>> { BEGIN INITIAL; return EOL; }
<ENDTAG>{eol}  { BEGIN INITIAL; return EOL; }
<ENDTAG>.      { return ERR; }

<<EOF>>        { return NUL; }
{eol}          { return ERR; }
.              { return ERR; }

%%
