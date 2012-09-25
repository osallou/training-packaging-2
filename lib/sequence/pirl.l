/* pirl.l - PIR sequence lexer */

%{
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif

#include "sequence/piry.h"

#undef  YY_DECL
#define YY_DECL int yylex(YYSTYPE *yylval)
%}

%option never-interactive
%option nounput noyywrap

%x FHEAD
%x ENTAG TITAG ALTAG CTTAG ORTAG DATAG ACTAG RETAG COTAG GETAG FUTAG CXTAG
%x CLTAG KETAG FETAG SUTAG SETAG SNTAG SEQTAG ENDTAG
%x ENTAG2

aln      [[:alnum:]]
alp      [[:alpha:]]
asl      "\\"
com      ","
cpa      ")"
dig      [[:digit:]]
dot      "."
eol      "\n"
equ      "="
min      "-"
opa      "("
sem      ";"
sla      "/"
spc      " "
und      "_"

txt      .{1,80}

ennam    [^# \n]{1,80}
entyp    #type
enval    (complete|fragments?)

acnum    {alp}+{und}?{dig}+

gap      {min}
bas      ({alp}|{gap})
sep      ({com}|{cpa}|{dot}|{equ}|{opa}|{sla}|{spc})

%%

^[A-Z]{1,10}{spc}+{min}{eol} /* Ignore empty fields made by sreformat tool */

^{spc}{eol}{spc}+P{spc}R{spc}O{spc}T{spc}E{spc}I{spc}N { BEGIN FHEAD; }
<FHEAD>{txt}   ; /* Ignore file header */
<FHEAD>{eol}/{asl}{3} { BEGIN INITIAL; }
<FHEAD>{eol}   ;

^{asl}{3}{eol} ; /* Ignore file trailer */

^ENTRY{spc}{10,11} { BEGIN ENTAG; return EN; }
<ENTAG>{ennam} { BEGIN ENTAG2; yylval->str = strdup(yytext); return ENNAM; }
<ENTAG>{spc}+/{eol} ; /* Trailing spaces ignored */
<ENTAG>{eol}   { BEGIN INITIAL; return EOL; }
<ENTAG>.       { return ERR; }

<ENTAG2>{txt}  { return ENTXT; }
<ENTAG2>{eol}  { BEGIN INITIAL; return EOL; }

^TITLE{spc}{10,11} { BEGIN TITAG; return TI; }
<TITAG>^{spc}{16}/{txt} { return NXT; }
<TITAG>{txt}   { yylval->str = strdup(yytext); return TITXT; }
<TITAG>{eol}/{spc}{16} { return EOL; }
<TITAG>{eol}   { BEGIN INITIAL; return EOL; }

^ALTERNATE_NAMES{spc} { BEGIN ALTAG; return AL; }
<ALTAG>^{spc}{16}/{txt} { return NXT; }
<ALTAG>{txt}   { return TXT; }
<ALTAG>{eol}/{spc}{16} { return EOL; }
<ALTAG>{eol}   { BEGIN INITIAL; return EOL; }

^CONTAINS{spc}{8} { BEGIN CTTAG; return CT; }
<CTTAG>^{spc}{16}/{txt} { return NXT; }
<CTTAG>{txt}   { return TXT; }
<CTTAG>{eol}/{spc}{16} { return EOL; }
<CTTAG>{eol}   { BEGIN INITIAL; return EOL; }

^ORGANISM{spc}{8} { BEGIN ORTAG; return OR; }
<ORTAG>^{spc}{3}/{txt} { return NXT; }
<ORTAG>{txt}   { return TXT; }
<ORTAG>{eol}/{spc}{3} { return EOL; }
<ORTAG>{eol}   { BEGIN INITIAL; return EOL; }

^DATE{spc}{12} { BEGIN DATAG; return DA; }
<DATAG>^{spc}{16}/{txt} { return NXT; }
<DATAG>{txt}   { return TXT; }
<DATAG>{eol}/{spc}{16} { return EOL; }
<DATAG>{eol}   { BEGIN INITIAL; return EOL; }

^ACCESSIONS{spc}{6} { BEGIN ACTAG; return AC; }
<ACTAG>^{spc}{16}/{acnum} { return NXT; }
<ACTAG>{acnum} { yylval->str = strdup(yytext); return ACNUM; }
<ACTAG>{sem}{spc} { return SEP; }
<ACTAG>{sem}/{eol} { return CNT; }
<ACTAG>{eol}/{spc}{16} { return EOL; }
<ACTAG>{eol}   { BEGIN INITIAL; return EOL; }
<ACTAG>.       { return ERR; }

^REFERENCE{spc}{7} { BEGIN RETAG; return RE; }
<RETAG>^{spc}{3}/{txt} { return NXT; }
<RETAG>{txt}   { return TXT; }
<RETAG>{eol}/{spc}{3} { return EOL; }
<RETAG>{eol}   { BEGIN INITIAL; return EOL; }

^COMMENT{spc}{9} { BEGIN COTAG; return CO; }
<COTAG>^{spc}{16}/{txt} { return NXT; }
<COTAG>{txt}   { return TXT; }
<COTAG>{eol}/{spc}{16} { return EOL; }
<COTAG>{eol}   { BEGIN INITIAL; return EOL; }

^GENETICS({spc}{8})? { BEGIN GETAG; return GE; }
<GETAG>^{spc}{3}/{txt} { return NXT; }
<GETAG>{txt}   { return TXT; }
<GETAG>{eol}/{spc}{3} { return EOL; }
<GETAG>{eol}   { BEGIN INITIAL; return EOL; }

^FUNCTION({spc}{8})? { BEGIN FUTAG; return FU; }
<FUTAG>^{spc}{3}/{txt} { return NXT; }
<FUTAG>{txt}   { return TXT; }
<FUTAG>{eol}/{spc}{3} { return EOL; }
<FUTAG>{eol}   { BEGIN INITIAL; return EOL; }

^COMPLEX{spc}{9} { BEGIN CXTAG; return CX; }
<CXTAG>^{spc}{3}/{txt} { return NXT; }
<CXTAG>{txt}   { return TXT; }
<CXTAG>{eol}/{spc}{3} { return EOL; }
<CXTAG>{eol}   { BEGIN INITIAL; return EOL; }

^CLASSIFICATION{spc}{2} { BEGIN CLTAG; return CL; }
<CLTAG>^{spc}{16}/{txt} { return NXT; }
<CLTAG>{txt}   { return TXT; }
<CLTAG>{eol}/{spc}{16} { return EOL; }
<CLTAG>{eol}   { BEGIN INITIAL; return EOL; }

^KEYWORDS{spc}{8} { BEGIN KETAG; return KE; }
<KETAG>^{spc}{16}/{txt} { return NXT; }
<KETAG>{txt}   { return TXT; }
<KETAG>{eol}/{spc}{16} { return EOL; }
<KETAG>{eol}   { BEGIN INITIAL; return EOL; }

^FEATURE/{eol} { BEGIN FETAG; return FE; }
<FETAG>^{spc}{3}/{txt} { return NXT; }
<FETAG>{txt}   { return TXT; }
<FETAG>{eol}/{spc}{3} { return EOL; }
<FETAG>{eol}   { BEGIN INITIAL; return EOL; }

^SUMMARY{spc}{9} { BEGIN SUTAG; return SU; }
<SUTAG>{txt}   { return TXT; }
<SUTAG>{eol}   { BEGIN INITIAL; return EOL; }

^SEQUENCE{spc}*/{eol} { BEGIN SETAG; return SE; }
<SETAG>{eol}   { BEGIN SNTAG; return EOL; }
<SETAG>.       { return ERR; }

<SNTAG>^{spc}{16,18} { return SN; }
<SNTAG>{dig}+  { return INT; }
<SNTAG>{spc}+  { return SPC; }
<SNTAG>{eol}   { BEGIN SEQTAG; return EOL; }
<SNTAG>.       { return ERR; }

<SEQTAG>^{spc}+ { return SEQ; }
<SEQTAG>{dig}+ { return INT; }
<SEQTAG>{bas}  { yylval->str = strdup(yytext); return BAS; }
<SEQTAG>{sep}+ { return SEP; }
<SEQTAG>{eol}/{spc} { return EOL; }
<SEQTAG>{eol}  { BEGIN INITIAL; return EOL; }
<SEQTAG>.      { return ERR; }

^{sla}{3}      { BEGIN ENDTAG; return END; }
<ENDTAG>{eol}  { BEGIN INITIAL; return EOL; }
<ENDTAG>.      { return ERR; }

<<EOF>>        { return NUL; }
{eol}          { return ERR; }
.              { return ERR; }

%%
