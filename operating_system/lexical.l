%{
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"

int linenum=1;
int pos=0;
int scope_g = 0;

/*
char *text=NULL;
struct token *current_tkn;
void makeTkn(int tag)
{
	current_tkn=malloc(sizeof(struct token));
	tokenize(current_tkn,strdup(yytext),tag,linenum, pos);
	printf("Token created: %s %d %d %d \n", yytext,tag,linenum,pos);
	insert(current_tkn);
	text=NULL;
	char *ch=yytext;
	while(*ch!='\0')
	{
		if(*ch=='\n')
		{
			linenum++;
			pos=0;
		}
		else if(*ch=='\t') pos+=TAB_SPACE-(pos%TAB_SPACE);
		else pos++;
		ch++;
	}
}
*/
void yyerror(char *);
void count();
void printerror();

%}


digit					[0-9]
number				({digit})+
alphabet			[a-zA-Z]
logical				"true"|"false"
float0				[+-]?{number}("."{number})?"E"[+-]?{number}
float1				[+-]?{number}"."{number}
float2				[+-]?"."{number}("E"[+-]?{number})?
float3				[+-]?{number}".E"[+-]?{number}
int						[+-]?{digit}+ 
floating			({float0}|{float1}|{float2}|{float3})
line 					\n
extraspace			[ \t]+
valididentifier			[_A-Za-z]+[A-Za-z0-9]*
stringliteral			"\""([^\"]*)"\""
char				"'"[A-Za-z0-9]"'"
		/*Single line comment*/
singlelinecomment 		("//")(.)*("\n")

	/*defining state for multiline comment*/
%x		 		CMNT

%%
{singlelinecomment}		{++linenum;}

<INITIAL>"/*"   		{BEGIN(CMNT);}
<CMNT>"*/"			BEGIN(INITIAL);
<CMNT>.				; 
<CMNT>{line}			{++linenum;}

{extraspace}			;
{line} 				{++linenum;pos=0;}
		/*datatypes*/

"int"				{count(); return INTEGER;}
"bool"				{count(); return BOOLEAN;}
"char"				{count(); return CHARACTER;}
"float"				{count(); return FLOAT ;}
"double"			{count(); return DOUBLE ;}
"long"				{count(); return LONG;}
"short"				{count(); return SHORT;}
"volatile"			{count(); return VOLATILE;}
"signed"			{count(); return SIGNED;}
"unsigned"			{count(); return UNSIGNED;}
"void"				{count(); return VOID;}
"const"				{count(); return CONST;}
"printf"			{count(); return PRINTF;}
"return"			{count(); return RETURN;}
				/*************Unary**********/
"++" 				{count(); return INCR;}
"--" 				{count(); return DECR;}

				/********Binary*******/
"%"				{count(); return MOD;}
"+"				{count(); return PLUS;}
"-"				{count(); return MINUS;}
"*"				{count(); return ASTERISK;}
"/"				{count(); return DIV;}
"<"				{count(); return LESST;}
">"				{count(); return GREAT;}
"==" 				{count(); return IFEQUAL;} 
"<=" 				{count(); return LEQ;}
">=" 				{count(); return GEQ;}
"!=" 				{count(); return NOTEQ;}
"^"				{count(); return BINARYXOR;}
"=" 				{count(); return EQUALTO;}
"~" 				{count(); return BINARYONESCOMPLEMENT;}	
":" 				{count(); return COLON;}
"&" 				{count(); return BINARYAND;}
"|" 				{count(); return BINARYOR;}
"." 				{count(); return DOT;}
";" 				{count(); return SEMICOLON;}
"," 				{count(); return COMMA;}
"&&" 				{count(); return AND;}
"||" 				{count(); return OR;}
"<<" 				{count(); return LSHIFT;}
">>" 				{count(); return RSHIFT;}
"+=" 				{count(); return PLUSEQ;}
"-=" 				{count(); return MINUSEQ;}
"*=" 				{count(); return MULEQ;}
"/=" 				{count(); return DIVEQ;}
"&=" 				{count(); return BITANDEQ;}
"|=" 				{count(); return BITOREQ;}
"^=" 				{count(); return BITXOREQ;}
"%=" 				{count(); return DIVEQ;}
"<<="				{count(); return LSHIFTEQ;}
">>="				{count(); return RSHIFTEQ;}
"->"				{count(); return POINTERARROW;}
"!"				{count(); return NOT;}
"<>"				{count(); return NOTEQ1;}
"?"				{count(); return QUEST;}

				/**********Symbols***********/
"\\"				{count(); return BACKSLASH;}
"("				{count(); return PARENOPEN;}
")"				{count(); return PARENCLOSE;}				
"[" 				{count(); return SQUAREOPENBRACKET;}
"]" 				{count(); return SQUARECLOSEBRACKET;}
"{" 				{count(); return BRACEOPEN;}
"}" 				{count(); return BRACECLOSE;}
"\""				{count(); return QUOTE;}
"#"				{count(); return HASH;}

					/*Keywords*/
"main"				{count(); yylval.symbol=strdup(yytext); return MAIN;}
"if"				{count(); return IF;}
"else"				{count(); return ELSE;}
"while"				{count(); return WHILE;}
"for"				{count(); return FOR;}
"include"			{count(); return INCLUDE;}
"typedef"			{count(); return TYPEDEF;}
"break"				{count(); return BREAK;}
"switch"			{count(); return SWITCH;}
"enum"				{count(); return ENUM;}
"struct"			{count(); return STRUCT;}
"do"				{count(); return DO;}
"default"			{count(); return DEFAULT;}
"\"%d\""				{count(); return PD;}
"\"%f\""				{count(); return PF;}
					/*valid datatypes*/
{stringliteral}			{count();  /*printf("literal %s\n",yytext);*/ yylval.symbol=strdup(yytext);return STRINGLITERAL;}
{valididentifier}       	{count(); yylval.symbol=strdup(yytext);return IDENTIFIER;}
{floating}			{count();  yylval.float_data = atof(yytext);return FLOAT_DATA;}
{int}				{ 
					long int i;
					unsigned long int j;
					i = strtol(yytext, NULL, 10);
					j=strtoul(yytext,NULL, 10);
				  if( i >= 0 ) {
					if (j < 32768) {
						count(); yylval.sign_short = atoi(yytext);return SIGN_SHORT;
					}
					else if(j < 65535) {
						count(); yylval.unsign_short = atoi(yytext);return UNSIGN_SHORT;
					}
					else if (j < 2000000000) {	
						count(); yylval.sign_int = atoi(yytext);return SIGN_INT;
					}
					else if(j < 4000000000) {
						count(); yylval.unsign_int = atoi(yytext);return UNSIGN_INT;
					}
					else if (j < 90000000000000) {
						count(); yylval.sign_long = atoi(yytext);return SIGN_LONG;
					}
					else if(j < 180000000000000) {
						count(); yylval.unsign_long = atoi(yytext);return UNSIGN_LONG;
					}
				  }
				  else {
					if(i > -32768) {
						count(); yylval.sign_short = atoi(yytext);return SIGN_SHORT;
					}
					else if(i > -2000000000) {
						count(); yylval.sign_int = atoi(yytext);return SIGN_INT;
					}
					else if(i > -900000000000000) {
						count(); yylval.sign_long = atoi(yytext);return SIGN_LONG;
					}
				  }
				}
{char}				{count(); return CHAR_DATA;}
.				{ printerror(); }

%%
void count()
{
	int i;
	for (i = 0; yytext[i] != '\0'; i++) {
		if (yytext[i] == '\n') {
			pos = 0; linenum++;
		}
		else if (yytext[i] == '\t')
			pos += 8 - (pos % 8);
		else
			pos++;
	}
}



void printerror() {
	printf("ERROR: Lexical Error.\n ERROR: Undefined Token \"%s\" at Line %d:%d\n", yytext, linenum, pos);
}



