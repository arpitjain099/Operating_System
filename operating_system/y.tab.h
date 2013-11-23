
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAIN = 258,
     CONTINUE = 259,
     ASTERISK = 260,
     BOOLEAN = 261,
     PRINTF = 262,
     DEFINE = 263,
     INCR = 264,
     DECR = 265,
     MOD = 266,
     PD = 267,
     PF = 268,
     PLUS = 269,
     MINUS = 270,
     DIV = 271,
     signed_int = 272,
     REL_OP = 273,
     INTEGER = 274,
     LOGICAL = 275,
     CHARACTER = 276,
     CHAR_DATA = 277,
     STRINGLITERAL = 278,
     FLOAT = 279,
     DOUBLE = 280,
     LONG = 281,
     SHORT = 282,
     VOLATILE = 283,
     SIGNED = 284,
     VOID = 285,
     CONST = 286,
     BINARYXOR = 287,
     EQUALTO = 288,
     BINARYONESCOMPLEMENT = 289,
     QUOTE = 290,
     COLON = 291,
     BINARYAND = 292,
     BINARYOR = 293,
     DOT = 294,
     SEMICOLON = 295,
     COMMA = 296,
     AND = 297,
     OR = 298,
     LSHIFT = 299,
     RSHIFT = 300,
     PLUSEQ = 301,
     MINUSEQ = 302,
     MULEQ = 303,
     DIVEQ = 304,
     BITANDEQ = 305,
     BITOREQ = 306,
     BITXOREQ = 307,
     MODEQ = 308,
     LSHIFTEQ = 309,
     RSHIFTEQ = 310,
     POINTERARROW = 311,
     NOT = 312,
     NOTEQ1 = 313,
     QUEST = 314,
     BACKSLASH = 315,
     PARENCLOSE = 316,
     PARENOPEN = 317,
     SQUAREOPENBRACKET = 318,
     SQUARECLOSEBRACKET = 319,
     BRACECLOSE = 320,
     BRACEOPEN = 321,
     HASH = 322,
     IF = 323,
     ELSE = 324,
     THEN = 325,
     WHILE = 326,
     FOR = 327,
     INCLUDE = 328,
     TYPEDEF = 329,
     BREAK = 330,
     SWITCH = 331,
     ENUM = 332,
     STRUCT = 333,
     DO = 334,
     DEFAULT = 335,
     none = 336,
     CASE = 337,
     IDENTIFIER = 338,
     IFEQUAL = 339,
     RETURN = 340,
     UNSIGNED = 341,
     SIGN_SHORT = 342,
     UNSIGN_SHORT = 343,
     SIGN_LONG = 344,
     UNSIGN_LONG = 345,
     SIGN_INT = 346,
     UNSIGN_INT = 347,
     FLOAT_DATA = 348,
     TABSPACE = 349,
     NOTEQ = 350,
     GEQ = 351,
     LEQ = 352,
     GREAT = 353,
     LESST = 354,
     UPLUS = 355,
     PDECR = 356,
     PINCR = 357,
     UMINUS = 358
   };
#endif
/* Tokens.  */
#define MAIN 258
#define CONTINUE 259
#define ASTERISK 260
#define BOOLEAN 261
#define PRINTF 262
#define DEFINE 263
#define INCR 264
#define DECR 265
#define MOD 266
#define PD 267
#define PF 268
#define PLUS 269
#define MINUS 270
#define DIV 271
#define signed_int 272
#define REL_OP 273
#define INTEGER 274
#define LOGICAL 275
#define CHARACTER 276
#define CHAR_DATA 277
#define STRINGLITERAL 278
#define FLOAT 279
#define DOUBLE 280
#define LONG 281
#define SHORT 282
#define VOLATILE 283
#define SIGNED 284
#define VOID 285
#define CONST 286
#define BINARYXOR 287
#define EQUALTO 288
#define BINARYONESCOMPLEMENT 289
#define QUOTE 290
#define COLON 291
#define BINARYAND 292
#define BINARYOR 293
#define DOT 294
#define SEMICOLON 295
#define COMMA 296
#define AND 297
#define OR 298
#define LSHIFT 299
#define RSHIFT 300
#define PLUSEQ 301
#define MINUSEQ 302
#define MULEQ 303
#define DIVEQ 304
#define BITANDEQ 305
#define BITOREQ 306
#define BITXOREQ 307
#define MODEQ 308
#define LSHIFTEQ 309
#define RSHIFTEQ 310
#define POINTERARROW 311
#define NOT 312
#define NOTEQ1 313
#define QUEST 314
#define BACKSLASH 315
#define PARENCLOSE 316
#define PARENOPEN 317
#define SQUAREOPENBRACKET 318
#define SQUARECLOSEBRACKET 319
#define BRACECLOSE 320
#define BRACEOPEN 321
#define HASH 322
#define IF 323
#define ELSE 324
#define THEN 325
#define WHILE 326
#define FOR 327
#define INCLUDE 328
#define TYPEDEF 329
#define BREAK 330
#define SWITCH 331
#define ENUM 332
#define STRUCT 333
#define DO 334
#define DEFAULT 335
#define none 336
#define CASE 337
#define IDENTIFIER 338
#define IFEQUAL 339
#define RETURN 340
#define UNSIGNED 341
#define SIGN_SHORT 342
#define UNSIGN_SHORT 343
#define SIGN_LONG 344
#define UNSIGN_LONG 345
#define SIGN_INT 346
#define UNSIGN_INT 347
#define FLOAT_DATA 348
#define TABSPACE 349
#define NOTEQ 350
#define GEQ 351
#define LEQ 352
#define GREAT 353
#define LESST 354
#define UPLUS 355
#define PDECR 356
#define PINCR 357
#define UMINUS 358




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 181 "yacc.y"

	int sign_short;
	int unsign_short;
	int sign_long;
	int unsign_long;
	int sign_int;
	int unsign_int;
	float float_data;
	char *symbol;
	struct nodeTypeTag* ptr;



/* Line 1676 of yacc.c  */
#line 272 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


