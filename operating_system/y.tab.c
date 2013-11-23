
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"

#include <stdio.h>
#include <string.h>
#include "parser.c"
#include "symbol_table.c"
int iscompatible(int a, int b);
int isoperable(int a,int b);
extern int linenum;

	//PROTOTYPEs -----
nodeType *id_handler(char*,int);
nodeType *id(char*); 
nodeType *typeset(int);
List* appendLists(List* ,List* );
	//Constant Nodes
nodeType *con(int value);
nodeType *fcon(float value);
nodeType *scon(short value);
nodeType *lcon(long value);
nodeType *u_con(unsigned int value);
nodeType *u_scon(unsigned short value);
nodeType *u_lcon(unsigned long value);

	//GenCodes..
void topGenCODEstring(enum OPCODE opcode,char *str, Code *Code_list);
void GenCODEstringprint(enum OPCODE opcode,int t3, Code *Code_list);
void Update(Code *Code_list,entry *tmpt1);
void GenCODEnode_float(enum OPCODE opcode, Node *target, float val, Code *Code_list);
void GenCODEnode(enum OPCODE opcode,Node *target, Code *Code_list);
void GenCODEnode_int(enum OPCODE opcode, Node *target, int val, Code *Code_list);
void print_Code(Code *list);
void GenCODEnode_node(enum OPCODE opcode,Node *target, Node* source, Code *Code_list);
void GenCODEnode(enum OPCODE opcode,Node *target, Code *Code_list);
void GenCODEstring_node_node(enum OPCODE opcode, char *target, Node *source1, Node *source2,Code *Code_list);
void GenCODEstring(enum OPCODE opcode, char *target, Code *Code_list);
void GenCODEstring_node(enum OPCODE opcode, char *target, Node *source1,Code *Code_list);
void GenCODEnode_int(enum OPCODE opcode, Node *target, int val, Code *Code_list);
void GenCODEnode_node_node(enum OPCODE opcode, Node *target, Node *source1,Node *source2,Code *Code_list);
void GenCODEstring_int(enum OPCODE opcode, char *target, int val, Code *Code_list);
void GenCODEnode_int_int(enum OPCODE opcode, Node *target, int val1,int val2, Code *Code_list);
void GenCODEnode_node_int(enum OPCODE opcode, Node *t1, Node *t2, int t3, Code *Code_list);
	// Handle flows..
nodeType *handle_if(int oper,nodeType *arg1,nodeType *arg2,nodeType *arg3) ;
nodeType *handle_for(int oper,nodeType *arg1,nodeType *arg2,nodeType *arg3,nodeType *arg4);
nodeType *handle_while(int oper,nodeType *arg1,nodeType *arg2);

void printing(int oper,nodeType* arg1,Code* Code_LIst);
Code* append(Code *l1,Code *l2);

	// Performs ..
nodeType *perform_arithmetic(int oper,nodeType *arg1,nodeType *arg2,int bit); 
nodeType *perform_boolean(int oper,nodeType *arg1,nodeType *arg2); 
nodeType *perform_logical(int oper,nodeType *arg1,nodeType *arg2); 
nodeType *perform_assignment(int oper,nodeType *arg1,nodeType *arg2); 
nodeType *perform_binary(int oper, nodeType *arg1, nodeType *arg2, int bit);
void iscomp(int, int);

	// Fina code generation..
void code_printer(struct _code *intermediate_list);

	//Constants used..
int check=0;
int typeID=11;
int labelno=0;
char func_name[20];
int nextloopnno=0;
int nextlabelno=0;
int loopno=0;
int strno=0;
int enum_number=0;

void yyerror(const char *str)
{
	printf("Error: %s at line %d\n",str,linenum);
}
int yylex();
int yywrap()
{
        return 1;
}
int main()
{
	initializeSymTable();
	yyparse();
	//printTable();
}


/* Line 189 of yacc.c  */
#line 162 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 418 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 430 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNRULES -- Number of states.  */
#define YYNSTATES  299

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   358

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    11,    20,    25,    27,
      28,    31,    34,    37,    38,    39,    48,    49,    50,    61,
      65,    67,    68,    72,    75,    77,    79,    81,    83,    85,
      88,    91,    94,    97,   100,   103,   105,   107,   109,   112,
     115,   118,   120,   123,   126,   128,   130,   132,   134,   136,
     138,   140,   144,   147,   150,   153,   156,   158,   159,   160,
     164,   168,   170,   172,   177,   182,   187,   192,   197,   202,
     205,   208,   211,   214,   218,   222,   226,   230,   234,   238,
     242,   245,   248,   252,   256,   260,   264,   268,   272,   276,
     280,   284,   288,   292,   296,   300,   304,   308,   312,   316,
     320,   324,   328,   331,   334,   336,   337,   341,   343,   348,
     355,   363,   376,   381,   384,   386,   390,   396,   401,   402,
     403,   410,   411,   417,   418,   419,   427,   430,   432,   436,
     438,   442,   448,   457,   459,   461,   463,   465,   467,   469,
     471,   474,   477,   481,   482,   487,   490,   491,   492,   501,
     503,   505,   508
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     105,     0,    -1,   106,    -1,   107,   109,    -1,   107,    -1,
      -1,    67,    73,    99,    83,    39,    83,    98,   108,    -1,
      67,    73,    23,   108,    -1,   107,    -1,    -1,   110,   109,
      -1,   110,   106,    -1,   119,   109,    -1,    -1,    -1,   117,
       3,    62,   111,   115,   112,    61,   146,    -1,    -1,    -1,
     117,    83,    62,   113,   115,   114,    61,    66,   148,    65,
      -1,   115,    41,   116,    -1,   116,    -1,    -1,   115,     1,
     116,    -1,   117,    83,    -1,    19,    -1,    24,    -1,    21,
      -1,    25,    -1,    28,    -1,    29,    19,    -1,    86,    19,
      -1,    29,    27,    -1,    29,    26,    -1,    86,    27,    -1,
      86,    26,    -1,    26,    -1,    27,    -1,     6,    -1,    31,
      19,    -1,    31,    24,    -1,    31,    21,    -1,    30,    -1,
      78,    83,    -1,    77,    83,    -1,    87,    -1,    88,    -1,
      89,    -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,
     117,   123,    40,    -1,   123,    40,    -1,   126,    40,    -1,
     135,    40,    -1,   137,    40,    -1,    83,    -1,    -1,    -1,
     123,    33,   123,    -1,   123,    33,   126,    -1,   118,    -1,
     120,    -1,   123,    41,   122,   123,    -1,   123,    14,   121,
     123,    -1,   123,    15,   121,   123,    -1,   123,     5,   121,
     123,    -1,   123,    16,   121,   123,    -1,   123,    11,   121,
     123,    -1,   123,     9,    -1,   123,    10,    -1,     9,   123,
      -1,    10,   123,    -1,   123,    34,   123,    -1,   123,    37,
     123,    -1,   123,    38,   123,    -1,   123,    32,   123,    -1,
     123,    44,   123,    -1,   123,    45,   123,    -1,    62,   123,
      61,    -1,    15,   123,    -1,    14,   123,    -1,    62,   124,
      61,    -1,   124,    97,   124,    -1,   124,    96,   124,    -1,
     124,    98,   124,    -1,   124,    99,   124,    -1,   124,    95,
     124,    -1,   124,    84,   124,    -1,   124,    58,   124,    -1,
     124,    43,   124,    -1,   124,    42,   124,    -1,   124,    46,
     124,    -1,   124,    47,   124,    -1,   124,    49,   124,    -1,
     124,    48,   124,    -1,   124,    54,   124,    -1,   124,    55,
     124,    -1,   124,    50,   124,    -1,   124,    51,   124,    -1,
     124,    52,   124,    -1,   124,    53,   124,    -1,    57,   124,
      -1,    34,   124,    -1,   123,    -1,    -1,   125,    41,   124,
      -1,   124,    -1,    83,    62,   125,    61,    -1,    71,    62,
     121,   124,    61,   146,    -1,    79,   146,    71,    62,   121,
     124,    61,    -1,    72,    62,   121,   124,    40,   121,   125,
      40,   121,   125,    61,   146,    -1,    82,    31,    36,   148,
      -1,   131,   130,    -1,   130,    -1,    66,   131,    65,    -1,
      76,    62,   124,    61,   132,    -1,   134,   117,   120,    40,
      -1,    -1,    -1,    78,    83,    66,   136,   134,    65,    -1,
      -1,    77,    66,   138,   141,    65,    -1,    -1,    -1,    77,
      83,   139,    66,   140,   141,    65,    -1,    77,    83,    -1,
     142,    -1,   141,    41,   142,    -1,    83,    -1,    83,    33,
     118,    -1,     7,    62,    23,    61,    40,    -1,     7,    62,
     144,    41,   121,   120,    61,    40,    -1,    12,    -1,    13,
      -1,   127,    -1,   119,    -1,   129,    -1,   133,    -1,   143,
      -1,   128,    40,    -1,     4,    40,    -1,    85,   124,    40,
      -1,    -1,    66,   147,   148,    65,    -1,   148,   149,    -1,
      -1,    -1,    68,    62,   121,   124,    61,   150,   146,   151,
      -1,   145,    -1,   146,    -1,    69,   149,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   217,   217,   227,   230,   231,   239,   240,   243,   244,
     250,   255,   260,   267,   276,   267,   306,   317,   306,   356,
     360,   361,   365,   372,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   411,   417,   418,   419,   420,   421,   422,
     423,   426,   438,   440,   441,   445,   451,   469,   476,   493,
     530,   556,   557,   558,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   609,   614,   615,   616,   617,   618,   619,   620,   621,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   656,   657,   658,   662,   675,   691,   823,
     828,   832,   836,   838,   839,   841,   845,   852,   853,   858,
     858,   886,   886,   887,   887,   887,   888,   896,   897,   905,
     911,   928,   935,   962,   963,   965,   969,   973,   977,   982,
     986,   990,   995,  1001,  1001,  1006,  1012,  1017,  1017,  1023,
    1028,  1042,  1045
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "CONTINUE", "ASTERISK",
  "BOOLEAN", "PRINTF", "DEFINE", "INCR", "DECR", "MOD", "PD", "PF", "PLUS",
  "MINUS", "DIV", "signed_int", "REL_OP", "INTEGER", "LOGICAL",
  "CHARACTER", "CHAR_DATA", "STRINGLITERAL", "FLOAT", "DOUBLE", "LONG",
  "SHORT", "VOLATILE", "SIGNED", "VOID", "CONST", "BINARYXOR", "EQUALTO",
  "BINARYONESCOMPLEMENT", "QUOTE", "COLON", "BINARYAND", "BINARYOR", "DOT",
  "SEMICOLON", "COMMA", "AND", "OR", "LSHIFT", "RSHIFT", "PLUSEQ",
  "MINUSEQ", "MULEQ", "DIVEQ", "BITANDEQ", "BITOREQ", "BITXOREQ", "MODEQ",
  "LSHIFTEQ", "RSHIFTEQ", "POINTERARROW", "NOT", "NOTEQ1", "QUEST",
  "BACKSLASH", "PARENCLOSE", "PARENOPEN", "SQUAREOPENBRACKET",
  "SQUARECLOSEBRACKET", "BRACECLOSE", "BRACEOPEN", "HASH", "IF", "ELSE",
  "THEN", "WHILE", "FOR", "INCLUDE", "TYPEDEF", "BREAK", "SWITCH", "ENUM",
  "STRUCT", "DO", "DEFAULT", "none", "CASE", "IDENTIFIER", "IFEQUAL",
  "RETURN", "UNSIGNED", "SIGN_SHORT", "UNSIGN_SHORT", "SIGN_LONG",
  "UNSIGN_LONG", "SIGN_INT", "UNSIGN_INT", "FLOAT_DATA", "TABSPACE",
  "NOTEQ", "GEQ", "LEQ", "GREAT", "LESST", "UPLUS", "PDECR", "PINCR",
  "UMINUS", "$accept", "start_main", "start_1", "Macros", "Macros1",
  "start_2", "Function", "@1", "$@2", "@3", "$@4", "Arg_List", "Arg",
  "TYPE", "NUM", "Declaration1", "id_declarator", "marker", "type_marker",
  "Assignment", "Expr", "Expr_Loop", "Function_Call", "While_State",
  "Do_While_State", "For_State", "Case_State", "Case_List", "Case_Compd",
  "Switch_State", "Assign_List", "Struct_State", "$@5", "Enum_State",
  "$@6", "@7", "$@8", "enumerator_list", "enumerator", "Print_Funct",
  "argt", "State", "Compound_State", "$@9", "State_List", "Stmt", "$@10",
  "ELSE_OPTIONAL", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   106,   106,   106,   107,   107,   108,   108,
     109,   109,   109,   111,   112,   110,   113,   114,   110,   115,
     115,   115,   115,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   119,   120,   121,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   126,   127,
     128,   129,   130,   131,   131,   132,   133,   134,   134,   136,
     135,   138,   137,   139,   140,   137,   137,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   145,   145,   145,   145,
     145,   145,   145,   147,   146,   148,   148,   150,   149,   149,
     149,   151,   151
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     8,     4,     1,     0,
       2,     2,     2,     0,     0,     8,     0,     0,    10,     3,
       1,     0,     3,     2,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     2,     2,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     2,     2,     1,     0,     0,     3,
       3,     1,     1,     4,     4,     4,     4,     4,     4,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     0,     3,     1,     4,     6,
       7,    12,     4,     2,     1,     3,     5,     4,     0,     0,
       6,     0,     5,     0,     0,     7,     2,     1,     3,     1,
       3,     5,     8,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     0,     4,     2,     0,     0,     8,     1,
       1,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     2,     4,     0,     1,    37,     0,     0,
       0,     0,    24,    26,    25,    27,    35,    36,    28,     0,
      41,     0,     0,     0,     0,    56,     0,    44,    45,    46,
      47,    48,    49,    50,     3,     5,     0,    61,     0,    62,
       0,     0,     0,     0,     9,     0,    56,    71,    72,    81,
      80,    29,    32,    31,    38,    40,    39,     0,   121,    43,
      42,   105,    30,    34,    33,    11,    10,     0,    56,     0,
      12,    57,    69,    70,    57,    57,    57,    57,     0,     0,
       0,     0,     0,    52,    58,     0,     0,    53,    54,    55,
       8,     7,     0,    79,     0,     0,   119,   105,   105,   105,
     104,   107,     0,    13,    16,    51,     0,     0,     0,     0,
       0,    76,    59,    60,    73,    74,    75,     0,    77,    78,
       0,   129,     0,   127,   124,   118,   103,   102,   104,     0,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     108,    21,    21,    66,    68,    64,    65,    67,    63,     0,
       0,     0,   122,     0,     0,    82,    91,    90,    92,    93,
      95,    94,    98,    99,   100,   101,    96,    97,    89,    88,
      87,    84,    83,    85,    86,   106,     0,     0,     0,    20,
       0,     0,     9,   130,   128,     0,   120,     0,    43,    42,
       0,     0,     0,    23,     0,     6,   125,     0,    22,    19,
       0,     0,   117,   143,    15,   146,   146,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,   105,     0,   136,
     135,     0,   137,   138,   139,   149,   150,   145,   144,   141,
       0,    57,    57,    57,   105,     0,     0,   140,   133,   134,
       0,     0,   105,   105,   105,     0,     0,   142,     0,    57,
       0,     0,     0,     0,    57,   131,     0,   147,     0,    57,
       0,   116,   105,     0,     0,   109,   105,     0,   114,     0,
       0,     0,   152,     0,     0,   115,   113,   110,   132,     0,
     148,    57,   146,   151,   105,   112,     0,     0,   111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    91,    34,    35,   151,   202,   152,
     204,   188,   189,   190,    37,   229,    39,   106,   117,   100,
     101,   102,    41,   230,   231,   232,   278,   279,   271,   233,
     164,    42,   125,    43,    94,    95,   163,   122,   123,   234,
     251,   235,   236,   216,   217,   237,   274,   290
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -206
static const yytype_int16 yypact[] =
{
     -37,   -35,    84,  -206,   536,    -8,  -206,  -206,   174,   174,
     174,   174,  -206,  -206,  -206,  -206,  -206,  -206,  -206,    71,
    -206,    91,   174,    17,    11,    37,    90,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,   492,   117,  -206,   536,  -206,
     960,    61,    67,   101,   -37,    64,  -206,    10,    10,    10,
      10,  -206,  -206,  -206,  -206,  -206,  -206,   923,  -206,   -23,
      45,   265,  -206,  -206,  -206,  -206,  -206,    88,    94,   997,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,   174,   353,
     174,   174,   174,  -206,  -206,   174,   174,  -206,  -206,  -206,
    -206,  -206,   118,  -206,    75,    95,  -206,   265,   265,   265,
    1011,   845,   -19,  -206,  -206,  -206,   174,   174,   174,   174,
     174,  1099,  1048,  -206,    10,  1107,  1062,   174,   114,   114,
      77,   130,     0,  -206,  -206,  -206,  -206,  -206,   923,   678,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
    -206,   611,   611,    10,    10,   185,   185,    10,  1048,    66,
     282,    75,  -206,    75,   509,  -206,    56,    38,   845,   845,
     845,   845,   845,   845,   845,   845,   845,   845,    47,    47,
      47,  -206,  -206,  -206,  -206,   845,    82,    87,    25,  -206,
      89,    26,   -37,  -206,  -206,    28,  -206,    97,  -206,  -206,
     611,   611,   105,  -206,   110,  -206,  -206,   133,  -206,  -206,
     108,   112,  -206,  -206,  -206,  -206,  -206,   224,   314,   141,
     120,  -206,   123,   124,   129,   135,   108,   265,   174,  -206,
    -206,   152,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
      12,  -206,  -206,  -206,   265,   128,   603,  -206,  -206,  -206,
     150,   161,   265,   265,   265,   695,   155,  -206,   172,  -206,
     753,   770,   620,   154,  -206,  -206,    97,  -206,   108,  -206,
     136,  -206,   265,   160,   108,  -206,   265,   191,  -206,   -42,
     828,   183,   157,   -12,   193,  -206,  -206,  -206,  -206,   404,
    -206,  -206,  -206,  -206,   265,   404,    27,   108,  -206
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,   192,   -43,    40,    83,  -206,  -206,  -206,  -206,
    -206,    85,   -62,    -2,    80,    35,  -194,   -66,  -206,    -4,
     -85,  -205,   156,  -206,  -206,  -206,   -38,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,    79,    86,  -206,
    -206,  -206,  -189,  -206,  -200,   -45,  -206,  -206
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -127
static const yytype_int16 yytable[] =
{
      40,    90,    36,   207,    47,    48,    49,    50,   107,   108,
     109,   110,   126,   127,   129,    44,   218,  -126,    57,    72,
      73,   214,   149,   285,   248,   249,   200,   200,   291,   149,
       1,    40,    69,    36,    40,   250,    36,   245,     5,    38,
     277,   161,   150,  -123,    80,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   162,   201,   201,   149,   161,
      38,   283,   273,    38,   111,   112,   114,   115,   116,   275,
     130,   118,   119,    58,     6,   282,   -14,   -17,   297,   296,
      51,    45,   295,   206,    60,   128,   142,    52,    53,    61,
      59,    87,   153,   154,   155,   156,   157,    88,   298,    62,
      54,    96,    55,   158,   142,    56,    63,    64,    66,    71,
      67,    70,   143,    72,    73,    74,     8,     9,    75,    76,
      77,    10,    11,   144,   145,   146,   147,   148,   208,   209,
     143,    89,   246,   145,   146,   147,   148,    92,    80,    90,
     103,   144,   145,   146,   147,   148,   104,   120,   121,   255,
     159,   124,   197,   160,   192,   198,   210,   260,   261,   262,
     199,   211,   203,   212,   213,   252,   253,   254,   215,    22,
      46,   239,   240,     8,     9,   241,   242,   280,    10,    11,
      71,   243,   247,   266,    72,    73,    74,   244,   272,   256,
      68,    77,   259,   276,    27,    28,    29,    30,    31,    32,
      33,   258,   265,    40,    40,   228,   228,   264,   277,    80,
     270,   281,   284,   288,    69,   294,   289,    65,   219,   292,
       7,   220,   205,     8,     9,   113,    22,   191,    10,    11,
     193,   286,   195,    12,   293,    13,     0,   194,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    46,     0,     0,
       0,    27,    28,    29,    30,    31,    32,    33,     0,     0,
       0,     0,     0,     0,     8,     9,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    40,    22,   228,     0,   221,
     213,    40,   222,   228,     0,   223,   224,     0,     0,    97,
     225,    23,    24,   226,     0,     0,     0,    25,     0,   227,
      26,    27,    28,    29,    30,    31,    32,    33,   219,     0,
       7,   220,    98,     8,     9,     0,     0,    99,    10,    11,
       0,     0,     0,    12,     0,    13,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,    46,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,     8,     9,     0,     0,     0,    10,    11,    27,
      28,    29,    30,    31,    32,    33,    22,     0,     0,   238,
     213,     0,   222,     0,     0,   223,   224,     0,     0,     0,
     225,    23,    24,   226,     0,     0,     0,    25,     0,   227,
      26,    27,    28,    29,    30,    31,    32,    33,   219,     0,
       7,   220,     0,     8,     9,    22,     0,     0,    10,    11,
       0,     0,     0,    12,     0,    13,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    25,     0,     0,     0,
      27,    28,    29,    30,    31,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
     213,     0,   222,     0,     0,   223,   224,     0,     0,     0,
     225,    23,    24,   226,     0,     0,     0,    25,     0,   227,
      26,    27,    28,    29,    30,    31,    32,    33,     7,     0,
       0,     8,     9,     0,     0,     0,    10,    11,     0,     0,
       0,    12,     0,    13,     0,     7,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,    12,     0,
      13,     0,     0,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     7,     0,     0,     8,     9,     0,     0,     0,
      10,    11,     0,     0,    22,    12,     0,    13,     0,     1,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    23,
      24,     0,     0,     0,   196,    25,     0,     0,    26,    27,
      28,    29,    30,    31,    32,    33,   186,   187,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,     0,     0,     7,     0,    25,
       0,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      12,     0,    13,     0,     0,    14,    15,    16,    17,    18,
      19,    20,    21,   257,     0,   130,   131,     0,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
     269,   142,   130,   131,     0,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   186,   187,
       0,     0,     0,     0,     0,     0,     0,    26,   144,   145,
     146,   147,   148,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148,
     130,   131,     0,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   130,   131,   165,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,     0,     0,   263,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,   146,   147,   148,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,   148,   130,   131,     0,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   130,   131,   267,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,     0,
       0,   268,     0,     0,     0,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,   148,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148,
     130,   131,     0,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   130,   131,   287,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,   146,   147,   148,    71,   143,
       0,     0,    72,    73,    74,     0,     0,    75,    76,    77,
     144,   145,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,     0,     0,
      81,    82,     0,     0,    84,    71,     0,    85,    86,    72,
      73,    74,     0,     0,    75,    76,    77,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,    78,    79,    80,     0,     0,    81,    82,     0,
      83,    84,    71,     0,    85,    86,    72,    73,    74,     0,
       0,    75,    76,    77,     0,     0,    71,     0,     0,     0,
      72,    73,    74,     0,     0,    75,    76,    77,     0,    78,
      79,    80,     0,     0,    81,    82,     0,   105,    84,     0,
       0,    85,    86,    78,    79,    80,     0,     0,    81,    82,
       0,     0,    84,    71,     0,    85,    86,    72,    73,    74,
       0,     0,    75,    76,    77,     0,     0,    71,     0,     0,
       0,    72,    73,    74,     0,     0,    75,    76,    77,     0,
      78,    79,    80,     0,     0,    81,    82,     0,     0,     0,
       0,     0,    85,    86,    78,     0,    80,     0,     0,    81,
       0,     0,     0,     0,    71,     0,    85,    86,    72,    73,
      74,     0,    71,    75,    76,    77,    72,    73,    74,     0,
       0,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,    81,     0,     0,     0,
       0,    80,     0,    85,    86,     0,     0,     0,     0,     0,
       0,    85,    86
};

static const yytype_int16 yycheck[] =
{
       4,    44,     4,   197,     8,     9,    10,    11,    74,    75,
      76,    77,    97,    98,    99,    23,   216,    40,    22,     9,
      10,   210,    41,    65,    12,    13,     1,     1,    40,    41,
      67,    35,    36,    35,    38,    23,    38,   226,    73,     4,
      82,    41,    61,    66,    34,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    65,    41,    41,    41,    41,
      35,   276,   266,    38,    78,    79,    80,    81,    82,   268,
      42,    85,    86,    66,     0,   274,    61,    61,    61,   294,
      19,    99,   292,    65,    83,    99,    58,    26,    27,    62,
      83,    40,   106,   107,   108,   109,   110,    40,   297,    19,
      19,    66,    21,   117,    58,    24,    26,    27,    35,     5,
       3,    38,    84,     9,    10,    11,     9,    10,    14,    15,
      16,    14,    15,    95,    96,    97,    98,    99,   200,   201,
      84,    40,   227,    96,    97,    98,    99,    83,    34,   192,
      62,    95,    96,    97,    98,    99,    62,    39,    83,   244,
      83,    66,   164,    33,    98,    83,    61,   252,   253,   254,
      83,    61,    83,    40,    66,   241,   242,   243,    66,    62,
      83,    40,    62,     9,    10,    62,    62,   272,    14,    15,
       5,    62,    40,   259,     9,    10,    11,    62,   264,    71,
      83,    16,    41,   269,    87,    88,    89,    90,    91,    92,
      93,    61,    40,   217,   218,   217,   218,    62,    82,    34,
      66,    61,    31,    40,   228,   291,    69,    35,     4,    36,
       6,     7,   192,     9,    10,    79,    62,   152,    14,    15,
     160,   279,   163,    19,   289,    21,    -1,   161,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    83,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,   289,    62,   289,    -1,    65,
      66,   295,    68,   295,    -1,    71,    72,    -1,    -1,    34,
      76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     4,    -1,
       6,     7,    57,     9,    10,    -1,    -1,    62,    14,    15,
      -1,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    83,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,     9,    10,    -1,    -1,    -1,    14,    15,    87,
      88,    89,    90,    91,    92,    93,    62,    -1,    -1,    65,
      66,    -1,    68,    -1,    -1,    71,    72,    -1,    -1,    -1,
      76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     4,    -1,
       6,     7,    -1,     9,    10,    62,    -1,    -1,    14,    15,
      -1,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    83,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      66,    -1,    68,    -1,    -1,    71,    72,    -1,    -1,    -1,
      76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     6,    -1,
      -1,     9,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    19,    -1,    21,    -1,     6,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    19,    -1,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,
      14,    15,    -1,    -1,    62,    19,    -1,    21,    -1,    67,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    77,
      78,    -1,    -1,    -1,    65,    83,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    -1,     6,    -1,    83,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    40,    -1,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      40,    58,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    95,    96,
      97,    98,    99,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    42,    43,    61,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    42,    43,    61,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    42,    43,    61,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,     5,    84,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,    -1,
      37,    38,    -1,    -1,    41,     5,    -1,    44,    45,     9,
      10,    11,    -1,    -1,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    -1,    37,    38,    -1,
      40,    41,     5,    -1,    44,    45,     9,    10,    11,    -1,
      -1,    14,    15,    16,    -1,    -1,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    -1,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    40,    41,    -1,
      -1,    44,    45,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    41,     5,    -1,    44,    45,     9,    10,    11,
      -1,    -1,    14,    15,    16,    -1,    -1,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    -1,
      32,    33,    34,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    32,    -1,    34,    -1,    -1,    37,
      -1,    -1,    -1,    -1,     5,    -1,    44,    45,     9,    10,
      11,    -1,     5,    14,    15,    16,     9,    10,    11,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    34,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,   105,   106,   107,    73,     0,     6,     9,    10,
      14,    15,    19,    21,    24,    25,    26,    27,    28,    29,
      30,    31,    62,    77,    78,    83,    86,    87,    88,    89,
      90,    91,    92,    93,   109,   110,   117,   118,   119,   120,
     123,   126,   135,   137,    23,    99,    83,   123,   123,   123,
     123,    19,    26,    27,    19,    21,    24,   123,    66,    83,
      83,    62,    19,    26,    27,   106,   109,     3,    83,   123,
     109,     5,     9,    10,    11,    14,    15,    16,    32,    33,
      34,    37,    38,    40,    41,    44,    45,    40,    40,    40,
     107,   108,    83,    61,   138,   139,    66,    34,    57,    62,
     123,   124,   125,    62,    62,    40,   121,   121,   121,   121,
     121,   123,   123,   126,   123,   123,   123,   122,   123,   123,
      39,    83,   141,   142,    66,   136,   124,   124,   123,   124,
      42,    43,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    58,    84,    95,    96,    97,    98,    99,    41,
      61,   111,   113,   123,   123,   123,   123,   123,   123,    83,
      33,    41,    65,   140,   134,    61,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,    77,    78,   115,   116,
     117,   115,    98,   118,   142,   141,    65,   117,    83,    83,
       1,    41,   112,    83,   114,   108,    65,   120,   116,   116,
      61,    61,    40,    66,   146,    66,   147,   148,   148,     4,
       7,    65,    68,    71,    72,    76,    79,    85,   117,   119,
     127,   128,   129,   133,   143,   145,   146,   149,    65,    40,
      62,    62,    62,    62,    62,   146,   124,    40,    12,    13,
      23,   144,   121,   121,   121,   124,    71,    40,    61,    41,
     124,   124,   124,    61,    62,    40,   121,    61,    61,    40,
      66,   132,   121,   120,   150,   146,   121,    82,   130,   131,
     124,    61,   146,   125,    31,    65,   130,    61,    40,    69,
     151,    40,    36,   149,   121,   148,   125,    61,   146
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 217 "yacc.y"
    {
						//print_Code($$->code);
						if(check==1)printf("Oops! Code not generated. Please Try again.\n"); 
						else{
						(yyval.ptr)=(yyvsp[(1) - (1)].ptr);
						code_printer((yyvsp[(1) - (1)].ptr)->code);
						}
						}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 227 "yacc.y"
    {
						(yyval.ptr)=(yyvsp[(2) - (2)].ptr);
						}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 230 "yacc.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr);}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 231 "yacc.y"
    {
						(yyval.ptr) = (nodeType*)malloc(sizeof(nodeType)); 
						(yyval.ptr)->code = (Code*)malloc(sizeof(Code));//$$=NULL;
						}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 239 "yacc.y"
    {(yyval.ptr)=(yyvsp[(8) - (8)].ptr);}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 240 "yacc.y"
    {(yyval.ptr)=(yyvsp[(4) - (4)].ptr);}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 243 "yacc.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr);}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 244 "yacc.y"
    {
					(yyval.ptr) = (nodeType*)malloc(sizeof(nodeType)); 
					(yyval.ptr)->code = (Code*)malloc(sizeof(Code));
				}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 250 "yacc.y"
    { (yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType)); 	//printf("F_start2\n");
							  (yyval.ptr)->code = (Code*) malloc(sizeof(Code));
							  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(1) - (2)].ptr)->code);  		/* printf("reading a line complete\n");*/	
							  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(2) - (2)].ptr)->code); 
							}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 255 "yacc.y"
    { (yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType));	//printf("F_start1\n");
							  (yyval.ptr)->code = (Code*) malloc(sizeof(Code));
							  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(1) - (2)].ptr)->code);  		/* printf("reading a line complete\n");*/	
							  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(2) - (2)].ptr)->code); 
							}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 260 "yacc.y"
    { (yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType));	 //printf("Decl_start2\n");
							  (yyval.ptr)->code = (Code*) malloc(sizeof(Code));
							  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(1) - (2)].ptr)->code);  		 /* printf("reading a line complete\n");*/	
							  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(2) - (2)].ptr)->code); 
							}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 267 "yacc.y"
    {											 //OpenScope(1);  //	printf("$2 = %s \n",$2);
								 	(yyval.ptr)= id_handler((yyvsp[(2) - (3)].symbol),10);
									(yyval.ptr)->ret=(yyvsp[(1) - (3)].ptr)->type;
									symSearch((yyvsp[(2) - (3)].symbol))->ret=(yyvsp[(1) - (3)].ptr)->type;
									symSearch((yyvsp[(2) - (3)].symbol))->local_var=(struct SymbolTable*)malloc(sizeof(struct SymbolTable));
	 								symSearch((yyvsp[(2) - (3)].symbol))->local_var=currentSymTable; 
	 																		 //OpenScope(0);
	 							}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 276 "yacc.y"
    {
	 								ListNodes* t=(ListNodes*)malloc(sizeof(ListNodes));
									List* tmp = (List*)malloc(sizeof(List));
												 							//printf("after $2 = %s \n",$2);	
		 							if((yyvsp[(5) - (5)].ptr)!=NULL)
		 							{	
		 							tmp=(yyvsp[(5) - (5)].ptr)->parameters;
		 							symSearch((yyvsp[(2) - (5)].symbol))->parameters=t;	
									while(tmp)
									{
										t->first=tmp->first;
										if(tmp->next!=NULL)
										{
										t->next=(ListNodes*)malloc(sizeof(ListNodes));
										t=t->next;
										}
										tmp=tmp->next;
									}
									}
									else {symSearch((yyvsp[(2) - (5)].symbol))->parameters=NULL;}
								}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 297 "yacc.y"
    {									//printf("after $2 = %s \n",$2);
																			//printTable();
																			//CloseScope(0);
											(yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType)); 
											(yyval.ptr)->code = (Code*) malloc(sizeof(Code));  
											GenCODEstring(label,"main",(yyval.ptr)->code);	
											(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(5) - (8)].ptr)->code);		//=> may give segmentation fault
											(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(8) - (8)].ptr)->code);
										}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 306 "yacc.y"
    {											//OpenScope(1); 					
								 											//printf("$2 = %s \n",$2);
									(yyval.ptr)= id_handler((yyvsp[(2) - (3)].symbol),10);
																			//printf("offset is: %d\n",symSearch($2)->stackOffset);
								 	sprintf(func_name,(yyvsp[(2) - (3)].symbol)); 
									(yyval.ptr)->ret=(yyvsp[(1) - (3)].ptr)->type;
									symSearch((yyvsp[(2) - (3)].symbol))->ret=(yyvsp[(1) - (3)].ptr)->type;
									symSearch((yyvsp[(2) - (3)].symbol))->local_var=(struct SymbolTable*)malloc(sizeof(struct SymbolTable));
	 								symSearch((yyvsp[(2) - (3)].symbol))->local_var=currentSymTable; 
	 								OpenScope(1);
							    }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 317 "yacc.y"
    {

									ListNodes* t=(ListNodes*)malloc(sizeof(ListNodes));
									List* tmp = (List*)malloc(sizeof(List));
		 																	//printf("after $2 = %s \n",$2);	
		 							if((yyvsp[(5) - (5)].ptr)!=NULL)
		 							{	
		 							tmp=(yyvsp[(5) - (5)].ptr)->parameters;
		 							symSearch((yyvsp[(2) - (5)].symbol))->parameters=t;	

									while(tmp)
									{
										t->first=tmp->first;
										if(tmp->next!=NULL){t->next=(ListNodes*)malloc(sizeof(ListNodes));
										t=t->next;}
										tmp=tmp->next;
									}
									}
									else {symSearch((yyvsp[(2) - (5)].symbol))->parameters=NULL;}
									}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 337 "yacc.y"
    {
	  									 										//   printTable();
					  			 			CloseScope(1);
					  			 			(yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType));					// Code generation..  
											(yyval.ptr)->code = (Code*) malloc(sizeof(Code));
											if((yyvsp[(5) - (10)].ptr)!=NULL)
											{
											(yyval.ptr)->parameters=(yyvsp[(5) - (10)].ptr)->parameters;
											}
											else (yyval.ptr)->parameters=NULL;
									 		GenCODEstring(label,(yyvsp[(2) - (10)].symbol),(yyval.ptr)->code); 
											(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(5) - (10)].ptr)->code);						//=> may give segmentation fault
											(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(9) - (10)].ptr)->code);
											GenCODEstring(ret_only,func_name,(yyval.ptr)->code); 
																				//print_Code($$->code);
					  			 												//	printf("TYPE IDENTIFIER PARENOPEN Arg_List\n");
					  			}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 356 "yacc.y"
    {	(yyval.ptr)->parameters=appendLists((yyvsp[(1) - (3)].ptr)->parameters,(yyvsp[(3) - (3)].ptr)->parameters);
								(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(1) - (3)].ptr)->code);
								(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(3) - (3)].ptr)->code);
							 }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 360 "yacc.y"
    {	(yyval.ptr)=(yyvsp[(1) - (1)].ptr);		  }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 361 "yacc.y"
    {
								(yyval.ptr) = (nodeType*)malloc(sizeof(nodeType)); 
								(yyval.ptr)->code = (Code*)malloc(sizeof(Code));			//$$=NULL;
							 }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 365 "yacc.y"
    {  
	  /* now we cannot parse further */
  	  printf("Syntax Error Arg_List Arg_List COMMA Arg	....at Line %d: \n", linenum);
	  yyclearin;
	  yyerrok;
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 372 "yacc.y"
    {														//	printf("bet of Arg = %s \n",$2);	
							(yyval.ptr)= id_handler((yyvsp[(2) - (2)].symbol),(yyvsp[(1) - (2)].ptr)->type);
																				//$$ = (nodeType*)malloc(sizeof(nodeType)); 
							List* var = (List*)malloc(sizeof(List));
							var->first=(yyvsp[(1) - (2)].ptr)->type;
							var->head=(yyval.ptr)->place;
							var->next=NULL;
							(yyval.ptr)->parameters=var;
																				//$$->parameters = $2->parameters; 
 																				//	printf("out of Arg = %s \n",$2);								 
						}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 385 "yacc.y"
    { (yyval.ptr) = typeset(1) ; }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 386 "yacc.y"
    { (yyval.ptr) = typeset(2) ; }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 387 "yacc.y"
    { (yyval.ptr) = typeset(3) ;	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 388 "yacc.y"
    { (yyval.ptr) = typeset(2) ; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 389 "yacc.y"
    { (yyval.ptr) = typeset(1) ; }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 390 "yacc.y"
    { (yyval.ptr) = typeset(1) ; }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 391 "yacc.y"
    { (yyval.ptr) = typeset(4) ; }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 392 "yacc.y"
    { (yyval.ptr) = typeset(5) ; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 393 "yacc.y"
    { (yyval.ptr) = typeset(6) ; }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 394 "yacc.y"
    { (yyval.ptr) = typeset(7) ; }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 395 "yacc.y"
    { (yyval.ptr) = typeset(8) ; }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 396 "yacc.y"
    { (yyval.ptr) = typeset(6) ; }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 397 "yacc.y"
    { (yyval.ptr) = typeset(5) ; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 398 "yacc.y"
    { (yyval.ptr) = typeset(1) ; }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 399 "yacc.y"
    { (yyval.ptr) = typeset(1) ; }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 400 "yacc.y"
    { (yyval.ptr) = typeset(2) ; }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 401 "yacc.y"
    { (yyval.ptr) = typeset(3) ; }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 402 "yacc.y"
    { (yyval.ptr) = typeset(0) ; }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 403 "yacc.y"
    {
						int a=lookup_struct((yyvsp[(2) - (2)].symbol)); 
						if(!a)
							printf("error\n");
							else {
								(yyval.ptr) = typeset(a);
							 	 }
						}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 411 "yacc.y"
    {
						(yyval.ptr)=id((yyvsp[(2) - (2)].symbol));
						if((yyval.ptr)->type!=12) printf("undefined enum reference to %s at line %d\n",(yyvsp[(2) - (2)].symbol),linenum);
					  }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 417 "yacc.y"
    {(yyval.ptr)=scon((yyvsp[(1) - (1)].sign_short));	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 418 "yacc.y"
    {(yyval.ptr)=u_scon((yyvsp[(1) - (1)].unsign_short)); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 419 "yacc.y"
    {(yyval.ptr)=lcon((yyvsp[(1) - (1)].sign_long));   }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 420 "yacc.y"
    {(yyval.ptr)=u_lcon((yyvsp[(1) - (1)].unsign_long)); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 421 "yacc.y"
    {(yyval.ptr)=con((yyvsp[(1) - (1)].sign_int));    }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 422 "yacc.y"
    {(yyval.ptr)=u_con((yyvsp[(1) - (1)].unsign_int));  }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 423 "yacc.y"
    {(yyval.ptr)=fcon((yyvsp[(1) - (1)].float_data));   }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 426 "yacc.y"
    {
																				//printf("id_declarator dtype=%d %s\n",$2->datatype,$2->name);
										if((yyvsp[(2) - (3)].ptr)->datatype!=9)
										{
										yyerror("Illegal identifier used at line");check=1;
										}
										(yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType));
										(yyval.ptr)->code = (Code*)malloc(sizeof(Code));
		  								(yyval.ptr)->type=(yyvsp[(1) - (3)].ptr)->type;
										(yyval.ptr)->place=(yyvsp[(2) - (3)].ptr)->place;										
										(yyval.ptr)->code = append((yyval.ptr)->code, (yyvsp[(2) - (3)].ptr)->code);
										}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 438 "yacc.y"
    {(yyval.ptr)=(yyvsp[(1) - (2)].ptr);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 440 "yacc.y"
    {(yyval.ptr)=(yyvsp[(1) - (2)].ptr);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 441 "yacc.y"
    { (yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType)); //printf("F_start2\n");
							 			  (yyval.ptr)->code = (Code*) malloc(sizeof(Code));
							 			  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(1) - (2)].ptr)->code);  /* printf("reading a line complete\n");*/	
										}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 445 "yacc.y"
    { (yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType)); //printf("F_start2\n");
							 			  (yyval.ptr)->code = (Code*) malloc(sizeof(Code));
							 			  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(1) - (2)].ptr)->code);  /* printf("reading a line complete\n");*/	
										}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 451 "yacc.y"
    {												 //printf("after $1 = %s \n",$1);	
									
								if((yyvsp[(0) - (1)].ptr) !=NULL)
								 {	
								 												 // printf("inside $1 = %s \n",$1);	
								 												 // printf("%d in %s\n", $<ptr>0->type,$1);
								 												 // printf("after $1 = %s \n",$1);	
								 	 if((yyvsp[(0) - (1)].ptr)->datatype==1)
									 {  
									 (yyval.ptr)= id_handler((yyvsp[(1) - (1)].symbol),(yyvsp[(0) - (1)].ptr)->type);
									 } 
									 else 
								 	 {
								 	 (yyval.ptr)= id((yyvsp[(1) - (1)].symbol));
								 	 }
								}
								}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 469 "yacc.y"
    {																	 //printf("Hello marker\n");
			(yyval.ptr)=(nodeType*)malloc(sizeof(nodeType));
			(yyval.ptr)->datatype=0;
			(yyval.ptr)->type=11;
			}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 476 "yacc.y"
    {	
										if((yyvsp[(-2) - (0)].ptr)==NULL)
										{
										(yyval.ptr)=(nodeType*)malloc(sizeof(nodeType));
										(yyval.ptr)->datatype=0;
																				 //printf("NULL creating %d\n", $$->datatype);
										}
										else if((yyvsp[(-2) - (0)].ptr)->datatype==1)
										{
																				 //	printf("inside the loop\n");
										 	(yyval.ptr) = typeset((yyvsp[(-2) - (0)].ptr)->type);
										}
																				 // printf("yo i'm done in marker!\n");
										}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 494 "yacc.y"
    {												//printf("t1=%d .. t2=%d\n",$1->type,$3->type);		//	iscomp(1,2);
																				//	if($1!=NULL && iscompatible($1->type,$3->type))
								(yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType));  
								(yyval.ptr)->code = (Code*)malloc(sizeof(Code));
		  						(yyval.ptr)->code = append((yyval.ptr)->code, (yyvsp[(3) - (3)].ptr)->code);
		  						(yyval.ptr)->datatype=(yyvsp[(1) - (3)].ptr)->datatype;
		  																		//	printf("Assignment1:t1=%d .. t2=%d\n",$1->type,$3->type);
		  						if ((yyvsp[(1) - (3)].ptr)!=NULL && !iscompatible((yyvsp[(1) - (3)].ptr)->type,(yyvsp[(3) - (3)].ptr)->type))
								{
																				//printf("Assignment:t1=%d .. t2=%d\n",$1->type,$3->type);
								yyerror("Incompatible datatypes");check=1;
								}
		  						else if(((yyvsp[(1) - (3)].ptr)->type==1 ||((yyvsp[(1) - (3)].ptr)->type>=4 && (yyvsp[(1) - (3)].ptr)->type<=8)) && ((yyvsp[(3) - (3)].ptr)->type==1 ||((yyvsp[(3) - (3)].ptr)->type>=4 && (yyvsp[(3) - (3)].ptr)->type<=8))) 
										{
										GenCODEnode_node(assigni, symSearch((yyvsp[(1) - (3)].ptr)->name), (yyvsp[(3) - (3)].ptr)->place, (yyval.ptr)->code);
																				//	printf("a1\n");
										}	
										else if (((yyvsp[(1) - (3)].ptr)->type==2) && ((yyvsp[(3) - (3)].ptr)->type==2))
										{ 
										GenCODEnode_node(assignf, symSearch((yyvsp[(1) - (3)].ptr)->name), (yyvsp[(3) - (3)].ptr)->place, (yyval.ptr)->code);
																				//printf("a2\n");
										}	
										else if(((yyvsp[(1) - (3)].ptr)->type==2) && ((yyvsp[(3) - (3)].ptr)->type==1 ||((yyvsp[(3) - (3)].ptr)->type>=4 && (yyvsp[(3) - (3)].ptr)->type<=8)))
										{ 
										Node *temp_node;
										temp_node = malloc(sizeof(Node ));
										temp_node->type = 2;
										GenCODEnode_node(int_to_float, temp_node, (yyvsp[(3) - (3)].ptr)->place, (yyval.ptr)->code);
										GenCODEnode_node(assignf, symSearch((yyvsp[(1) - (3)].ptr)->name), temp_node, (yyval.ptr)->code);
																				//printf("a3\n");
										}		
										else if(((yyvsp[(1) - (3)].ptr)->type==1 ||((yyvsp[(1) - (3)].ptr)->type>=4 && (yyvsp[(1) - (3)].ptr)->type<=8)) && (yyvsp[(3) - (3)].ptr)->type==2)
										{
											yyerror("Incompatible datatypes");check=1;					
										}
								}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 530 "yacc.y"
    {												//printf("t1=%d .. t2=%d\n",$1->type,$3->type); iscomp(1,2);
								(yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType));  
								(yyval.ptr)->code = (Code*)malloc(sizeof(Code));
		  						(yyval.ptr)->code = append((yyval.ptr)->code, (yyvsp[(3) - (3)].ptr)->code);
		  						if(((yyvsp[(1) - (3)].ptr)->type==1 ||((yyvsp[(1) - (3)].ptr)->type>=4 && (yyvsp[(1) - (3)].ptr)->type<=8)) && ((yyvsp[(3) - (3)].ptr)->type==1 ||((yyvsp[(3) - (3)].ptr)->type>=4 && (yyvsp[(3) - (3)].ptr)->type<=8))) 
										{
										GenCODEnode_node(assigni, symSearch((yyvsp[(1) - (3)].ptr)->name), (yyvsp[(3) - (3)].ptr)->place, (yyval.ptr)->code);
										}	
										else if (((yyvsp[(1) - (3)].ptr)->type==2) && ((yyvsp[(3) - (3)].ptr)->type==2))
										{ 
										GenCODEnode_node(assignf, symSearch((yyvsp[(1) - (3)].ptr)->name), (yyvsp[(3) - (3)].ptr)->place, (yyval.ptr)->code);
										}	
										else if(((yyvsp[(1) - (3)].ptr)->type==2) && ((yyvsp[(3) - (3)].ptr)->type==1 ||((yyvsp[(3) - (3)].ptr)->type>=4 && (yyvsp[(3) - (3)].ptr)->type<=8)))
										{ 
										Node *temp_node;
										temp_node = malloc(sizeof(Node ));
										temp_node->type = 2;
										GenCODEnode_node(int_to_float, temp_node, (yyvsp[(3) - (3)].ptr)->place, (yyval.ptr)->code);
										GenCODEnode_node(assignf, symSearch((yyvsp[(1) - (3)].ptr)->name), temp_node, (yyval.ptr)->code);
										}
								else if ((yyvsp[(1) - (3)].ptr)!=NULL && (!iscompatible((yyvsp[(1) - (3)].ptr)->type,(yyvsp[(3) - (3)].ptr)->type)))
								{													 //		printf("t1=%d .. t2=%d\n",$1->type,$3->ret);
								yyerror("Incompatible datatypes");check=1;
								}
								}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 556 "yacc.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr);	 	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 557 "yacc.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr); 	 printf("id_declarator dtype1=%d dtype2=%d name!:%s name2:%s\n",(yyval.ptr)->datatype,(yyvsp[(1) - (1)].ptr)->datatype,(yyval.ptr)->name,(yyvsp[(1) - (1)].ptr)->name);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 558 "yacc.y"
    { (yyval.ptr)  = (nodeType*)malloc(sizeof(nodeType));  
												(yyval.ptr)->code = (Code*)malloc(sizeof(Code));
												(yyval.ptr)->type=(yyvsp[(4) - (4)].ptr)->type;
												(yyval.ptr)->place=(yyvsp[(4) - (4)].ptr)->place;
												(yyval.ptr)->code = append((yyval.ptr)->code, (yyvsp[(1) - (4)].ptr)->code);
												(yyval.ptr)->code = append((yyval.ptr)->code, (yyvsp[(4) - (4)].ptr)->code);
												if((yyvsp[(1) - (4)].ptr)->datatype==(yyvsp[(4) - (4)].ptr)->datatype)
												{
												(yyval.ptr)->datatype=(yyvsp[(1) - (4)].ptr)->datatype;
												}
												else (yyval.ptr)->datatype=0;
																					//printf("Assignment COMMA type_marker Assignment\n");
												}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 571 "yacc.y"
    {	(yyval.ptr) = perform_arithmetic(plus,(yyvsp[(1) - (4)].ptr),(yyvsp[(4) - (4)].ptr),0);		       }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 572 "yacc.y"
    { (yyval.ptr) = perform_arithmetic(minus,(yyvsp[(1) - (4)].ptr),(yyvsp[(4) - (4)].ptr),0);		       }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 573 "yacc.y"
    { (yyval.ptr) = perform_arithmetic(asterisk,(yyvsp[(1) - (4)].ptr),(yyvsp[(4) - (4)].ptr),0);		   }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 574 "yacc.y"
    { (yyval.ptr) = perform_arithmetic(divi,(yyvsp[(1) - (4)].ptr),(yyvsp[(4) - (4)].ptr),0);		   	   }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 575 "yacc.y"
    { (yyval.ptr) = perform_arithmetic(mod,(yyvsp[(1) - (4)].ptr),(yyvsp[(4) - (4)].ptr),0);		  	   }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 576 "yacc.y"
    {	perform_unary(incr,(yyvsp[(1) - (2)].ptr)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 577 "yacc.y"
    {	perform_unary(decr,(yyvsp[(1) - (2)].ptr)); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 578 "yacc.y"
    { perform_unary(incr,(yyvsp[(2) - (2)].ptr)); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 579 "yacc.y"
    { perform_unary(decr,(yyvsp[(2) - (2)].ptr)); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 580 "yacc.y"
    { (yyval.ptr)=perform_binary(binaryonescomplement,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),0);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 581 "yacc.y"
    { (yyval.ptr)=perform_binary(binaryand,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),0);}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 582 "yacc.y"
    { (yyval.ptr)=perform_binary(binaryor,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),0);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 583 "yacc.y"
    { (yyval.ptr)=perform_binary(binaryxor,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),0);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 584 "yacc.y"
    { (yyval.ptr)=perform_binary(lshift,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),0);}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 585 "yacc.y"
    { (yyval.ptr)=perform_binary(rshift,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),0);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 586 "yacc.y"
    {(yyval.ptr)=(yyvsp[(2) - (3)].ptr);}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 587 "yacc.y"
    { 	(yyval.ptr) = (nodeType*)malloc(sizeof(nodeType)); 
												(yyval.ptr)->place = (yyvsp[(2) - (2)].ptr)->place;									  ///?????
												if((yyval.ptr)->code==NULL){
									    				(yyval.ptr)->code = (Code*)malloc(sizeof(Code));
																  }															   	
												if((yyvsp[(2) - (2)].ptr)->type==1||((yyvsp[(2) - (2)].ptr)->type>=4 && (yyvsp[(2) - (2)].ptr)->type<=8))
												{
												(yyval.ptr)->type = 1;
												GenCODEnode(uminus,(yyvsp[(2) - (2)].ptr)->place, (yyvsp[(2) - (2)].ptr)->code);
												(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(2) - (2)].ptr)->code);
												}
												else if((yyvsp[(2) - (2)].ptr)->type==2)
												{
												(yyval.ptr)->type = 2;
												GenCODEnode(uminus,(yyvsp[(2) - (2)].ptr)->place, (yyvsp[(2) - (2)].ptr)->code);
												(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(2) - (2)].ptr)->code);
												}
												else
																									//printf("type error at %d\n",line_no);
													yyerror("type error");
													check=1;
													}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 609 "yacc.y"
    {(yyval.ptr)=(yyvsp[(2) - (2)].ptr);}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 615 "yacc.y"
    { (yyval.ptr) = perform_boolean(leq,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));		}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 616 "yacc.y"
    { (yyval.ptr) = perform_boolean(geq,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 617 "yacc.y"
    { (yyval.ptr) = perform_boolean(great,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 618 "yacc.y"
    { (yyval.ptr) = perform_boolean(lesst,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 619 "yacc.y"
    { (yyval.ptr) = perform_boolean(noteq,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));		}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 620 "yacc.y"
    { (yyval.ptr) = perform_boolean(ifequal,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 621 "yacc.y"
    { (yyval.ptr) = perform_boolean(noteq,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));		}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 624 "yacc.y"
    { (yyval.ptr) = perform_logical(or,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));		}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 625 "yacc.y"
    { (yyval.ptr) = perform_logical(and,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr));		}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 626 "yacc.y"
    { (yyval.ptr) = perform_arithmetic(plus,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),1);}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 627 "yacc.y"
    { (yyval.ptr) = perform_arithmetic(minus,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),1);}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 628 "yacc.y"
    { (yyval.ptr) = perform_arithmetic(divi,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),1);}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 629 "yacc.y"
    { (yyval.ptr) = perform_arithmetic(asterisk,(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),1);}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 636 "yacc.y"
    { 
									(yyval.ptr) = (nodeType*)malloc(sizeof(nodeType));
									(yyval.ptr)->code = (Code*)malloc(sizeof(Code)); 
									(yyval.ptr)->place = (yyvsp[(2) - (2)].ptr)->place;				
									Node * tmp=(Node*)malloc(sizeof(Node));
									tmp->stackOffset=getOffset();
									incOffset(4);
									
									if((yyvsp[(2) - (2)].ptr)->type==1){
									(yyval.ptr)->type = (yyvsp[(2) - (2)].ptr)->type;
									
									(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(2) - (2)].ptr)->code);
									GenCODEnode_node(not,tmp,(yyvsp[(2) - (2)].ptr)->place, (yyval.ptr)->code);(yyval.ptr)->place=tmp;
									}
									else{
																							//printf("type error at %d\n",linenum);
									yyerror("type error");
									check=1;
									}		
							}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 656 "yacc.y"
    {(yyval.ptr)=(yyvsp[(2) - (2)].ptr);}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 657 "yacc.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr); }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 658 "yacc.y"
    {(yyval.ptr) = (nodeType*)malloc(sizeof(nodeType));
								 (yyval.ptr)->code = (Code*)malloc(sizeof(Code));}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 662 "yacc.y"
    { 										//printf("expr_loop\n");
										(yyval.ptr) = (nodeType*)malloc(sizeof(nodeType));(yyval.ptr)->code = (Code*)malloc(sizeof(Code));
										List* var = (List*)malloc(sizeof(List));
										var->first=(yyvsp[(3) - (3)].ptr)->type;
										var->head=(yyvsp[(3) - (3)].ptr)->place;
										var->next=NULL;
										(yyvsp[(3) - (3)].ptr)->parameters=var;
																						//	print_List($1->parameters);
										(yyval.ptr)->parameters=appendLists((yyvsp[(1) - (3)].ptr)->parameters,(yyvsp[(3) - (3)].ptr)->parameters);
										(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(1) - (3)].ptr)->code);
										(yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(3) - (3)].ptr)->code);
																						//	printf("Expr_loop comma expr\n");
												}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 675 "yacc.y"
    { (yyval.ptr) = (nodeType*)malloc(sizeof(nodeType)); printf("Hii, Expr\n");
									    		  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
												  List* var = (List*)malloc(sizeof(List));
												  if((yyvsp[(1) - (1)].ptr)!=NULL)
												  {
												  var->first=(yyvsp[(1) - (1)].ptr)->type;
																						//  printf("expr type = %d\n",$1->type);
												  var->head=(yyvsp[(1) - (1)].ptr)->place;
												  var->next=NULL;
												  (yyvsp[(1) - (1)].ptr)->parameters=var;
												  (yyval.ptr)->parameters = (yyvsp[(1) - (1)].ptr)->parameters;
												  (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(1) - (1)].ptr)->code); 
												  }
												}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 691 "yacc.y"
    {  							//printf("hello function '%s'\n", $1);
														(yyval.ptr)=id((yyvsp[(1) - (4)].symbol)); 						//printf("hello function '%s'\n", $1);
																						//printf("off=%d",symSearch($3->parameters->head)->stackOffset);
														if(symSearch((yyvsp[(1) - (4)].symbol))!=NULL)
														{
																						//$$->ret=symSearch($1)->ret;
														(yyval.ptr)->type =symSearch((yyvsp[(1) - (4)].symbol))->ret;
														if (symSearch((yyvsp[(1) - (4)].symbol))->parameters!=NULL && ((yyvsp[(3) - (4)].ptr)==NULL || (yyvsp[(3) - (4)].ptr)->parameters==NULL))
														{
																						//printf("function0: '%s' unmatched arguments at %d\n",$1,linenum);
														yyerror("unmatched arguments");
														check=1;
														}
														if(symSearch((yyvsp[(1) - (4)].symbol))->parameters==NULL && (yyvsp[(3) - (4)].ptr)!=NULL)
														{
																						//errorbit=1;
																						//printf("function1: '%s' unmatched arguments at %d\n",$1,linenum);
														yyerror("unmatched arguments");
														check=1;
														}
														else if (symSearch((yyvsp[(1) - (4)].symbol))->type!=10) 
														{
																						//printf("error:'%s' is not a fuction at %d\n",$1,linenum);
														yyerror("Undefined function name");
														check=1;
														}
														else (yyval.ptr)->type=symSearch((yyvsp[(1) - (4)].symbol))->ret;				//printf("hello function1 '%s'\n", $1);

														int sum=0;
														ListNodes *t1 = malloc(sizeof(ListNodes));
														List *t2 = malloc(sizeof(List));
														Node *tm = malloc(sizeof(Node));
														t1=symSearch((yyvsp[(1) - (4)].symbol))->parameters;
														t2=(yyvsp[(3) - (4)].ptr)->parameters;
														
														while(t1!=NULL && t2!=NULL)
														{									//printf("hello function1 '%s'\n", $1);
														sum=sum+t1->first;
																							//	printf("t1=%d \t t2=%d\n",t1->first,t2->first);
															if(!iscompatible(t1->first,t2->first))
																{
																yyerror("type error");
																							//printf("type error at: %d\n",linenum);
																check=1;
																}
															t1=t1->next;		
															t2=t2->next;
																if(t1==NULL && t2!=NULL)														
																{	
																							//printf("function2: '%s' unmatched arguments at %d\n",$1,linenum);
																	yyerror("unmatched arguments");																	
																	check=1;
																}
																if(t1!=NULL && t2==NULL)
																	{
																							//printf("function3: '%s' unmatched arguments at %d\n",$1,linenum);
																	yyerror("unmatched arguments");															
																	check=1;
																	}
														}
											if(check!=1){
											if ((yyval.ptr)->type ==1){
											
											tm->stackOffset = getOffset();
											incOffset(4);
											tm->type = 1;
											}
											else if ((yyval.ptr)->type ==2){
											
											tm->stackOffset = getOffset();
											incOffset(8);
											tm->type = 2;}
											else if ((yyval.ptr)->type ==3){
								
											tm->stackOffset = getOffset();
											incOffset(4);
											tm->type = 3;}
											else if ((yyval.ptr)->type ==0){
								
											tm->stackOffset = getOffset();
											incOffset(4);
											tm->type = 0;}
											else {
											tm->stackOffset = getOffset();
											incOffset(4);
											tm->type = 11;
											}
										    (yyval.ptr)->code = append((yyval.ptr)->code,(yyvsp[(3) - (4)].ptr)->code);
									        t2=(yyvsp[(3) - (4)].ptr)->parameters;
											sum=0;int m;
										if(symSearch((yyvsp[(1) - (4)].symbol))->ret==1)m=4;	
										else if(symSearch((yyvsp[(1) - (4)].symbol))->ret==2)m=8;
										else if(symSearch((yyvsp[(1) - (4)].symbol))->ret==3)m=1;
										else if(symSearch((yyvsp[(1) - (4)].symbol))->ret==0)m=0;
										else m=4; 
										GenCODEstring_int(func1, (yyvsp[(1) - (4)].symbol), 500, (yyval.ptr)->code);						
						      		   	int num = 1;
						      		  	sprintf(func_name,(yyvsp[(1) - (4)].symbol));
										    while(t2 != NULL){
							                 		if(t2->first == 1 || t2->first >=4 && t2->first <=8)
							                		 {
																	 //printf("offset------------->%d\nname------------->%s\n",t2->head->stackOffset, $1);
							                		 GenCODEnode_int_int(int_param, t2->head, symSearch((yyvsp[(1) - (4)].symbol))->stackOffset+m , sum, (yyval.ptr)->code);
							                		 printf("offset=%d\n",symSearch((yyvsp[(1) - (4)].symbol))->stackOffset+m);
							                		 sum=sum+4;
							                		 }
											 else if(t2->first == 2)
											 		{
											 		GenCODEnode_int_int(float_param, t2->head, symSearch((yyvsp[(1) - (4)].symbol))->stackOffset+m, sum, (yyval.ptr)->code);
											 		sum=sum+8;
											 		}
											 else if(t2->first == 3)
											 		{
											 		GenCODEnode_int_int(char_param, t2->head, symSearch((yyvsp[(1) - (4)].symbol))->stackOffset+m, sum, (yyval.ptr)->code);
											 		sum=sum+1;
											 		}
											 else {
											 		GenCODEnode_int_int(int_param, t2->head, symSearch((yyvsp[(1) - (4)].symbol))->stackOffset+m, sum, (yyval.ptr)->code);
											 		sum=sum+4;
											 		}				//500 is redundant....create GenCODEstring
											 num++;
											 t2 = t2->next;}									 
										   GenCODEstring_int(func2, (yyvsp[(1) - (4)].symbol), 500, (yyval.ptr)->code);			//500 is redundant....create GenCODEstring
										   GenCODEnode_int(ret_val, tm, 500, (yyval.ptr)->code); 		//500 is redundant....create GenCODEstring
										   (yyval.ptr)->place = tm;
																
											}
														}
													 }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 823 "yacc.y"
    { 							//printf("while\n");
																	(yyval.ptr) = handle_while(whilesym,(yyvsp[(4) - (6)].ptr),(yyvsp[(6) - (6)].ptr));	
																  }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 828 "yacc.y"
    { (yyval.ptr) = handle_while(whilesym,(yyvsp[(6) - (7)].ptr),(yyvsp[(2) - (7)].ptr));	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 832 "yacc.y"
    {(yyval.ptr) = handle_for(forloop,(yyvsp[(4) - (12)].ptr),(yyvsp[(7) - (12)].ptr),(yyvsp[(10) - (12)].ptr),(yyvsp[(12) - (12)].ptr)); }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 858 "yacc.y"
    {										//printf("struct %d\n",lookup_struct($2));
											if(lookup_struct((yyvsp[(2) - (3)].symbol))) 
												printf("error: struct declaration already exists at line %d\n",linenum); 
											else {

												int sequence = insert_str((yyvsp[(2) - (3)].symbol));
												OpenScope(0);
																					//	printf("s2 %d--\n",sequence);	
												insert_str_arg(sequence, currentSymTable);
											}
											 }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 869 "yacc.y"
    {CloseScope(0);}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 886 "yacc.y"
    {enum_number=0;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 886 "yacc.y"
    {(yyval.ptr)=(yyvsp[(4) - (5)].ptr);}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 887 "yacc.y"
    {(yyval.ptr)=id_handler((yyvsp[(2) - (2)].symbol),12);}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 887 "yacc.y"
    {enum_number=0;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 887 "yacc.y"
    {(yyval.ptr)=(yyvsp[(6) - (7)].ptr);}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 888 "yacc.y"
    {
						(yyval.ptr)=id_handler((yyvsp[(2) - (2)].symbol),13);
						symSearch((yyvsp[(2) - (2)].symbol))->is_enum=1;
						symSearch((yyvsp[(2) - (2)].symbol))->enum_val=0;
			   		  }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 896 "yacc.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr);}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 897 "yacc.y"
    { (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (3)].ptr)->code);			//=> Check why? it is giving segmentation fault???
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(3) - (3)].ptr)->code);
					    }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 905 "yacc.y"
    {
						(yyval.ptr)=id_handler((yyvsp[(1) - (1)].symbol),1);
						symSearch((yyvsp[(1) - (1)].symbol))->enum_val=enum_number;
						symSearch((yyvsp[(1) - (1)].symbol))->is_enum=1;
						enum_number++;
			    }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 911 "yacc.y"
    {
						(yyval.ptr)=id_handler((yyvsp[(1) - (3)].symbol),1);
						if((yyvsp[(3) - (3)].ptr)->type=1 || ((yyvsp[(3) - (3)].ptr)->type>=4 && (yyvsp[(3) - (3)].ptr)->type<=8))
						{
						symSearch((yyvsp[(1) - (3)].symbol))->enum_val=enum_number;
						symSearch((yyvsp[(1) - (3)].symbol))->is_enum=1;
						//enum_number+=$3;
			   			}
			   			else
			   			{
			   			printf("Line %d: Enumeration requires constant expression\n",linenum);
						printf("Line %d: cannot convert from %s type to const int type\n",linenum,(yyvsp[(3) - (3)].ptr)->type);
						}
						}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 928 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								 											  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								 											 // printf("passing string: %s\n",$3);
								 											  topGenCODEstring(printshdr,(yyvsp[(3) - (5)].symbol), (yyval.ptr)->code);
								 											  GenCODEstringprint(prints,strno,(yyval.ptr)->code);
								 											//  $$->code=append($$->code,$1->code);	//=> Check why? it is giving segmentation fault???
					    }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 936 "yacc.y"
    {	
					//printf("%s\t%d\n",$6->name,$6->type);
					(yyval.ptr) = (nodeType*)malloc(sizeof(nodeType));	
					if((yyval.ptr)->code==NULL){
					(yyval.ptr)->code = (Code*)malloc(sizeof(Code));
					}	
					if((yyvsp[(3) - (8)].ptr)->type==1 && (((yyvsp[(6) - (8)].ptr)->type==1) || ((yyvsp[(6) - (8)].ptr)->type>=4 && (yyvsp[(6) - (8)].ptr)->type<=8)))
					{
					//$$->type = 1;
					GenCODEnode(printi,(yyvsp[(6) - (8)].ptr)->place, (yyval.ptr)->code);
					//$$->code = append($$->code,$2->code);
					}
					else if((yyvsp[(3) - (8)].ptr)->type==2 && (yyvsp[(6) - (8)].ptr)->type==2)
					{
					//$$->type = 2;
					GenCODEnode(printff,(yyvsp[(6) - (8)].ptr)->place, (yyval.ptr)->code);
					//$$->code = append($$->code,$$->code);
					}
					else
					{
					//printf("type error at %d\n",line_no);
					yyerror("type error");
					check=1;
					}
					}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 962 "yacc.y"
    { (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType)); (yyval.ptr)->type=1;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 963 "yacc.y"
    { (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType)); (yyval.ptr)->type=2;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 965 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (1)].ptr)->code);			//=> Check why? it is giving segmentation fault???
					    }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 969 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (1)].ptr)->code);			//=> Check why? it is giving segmentation fault???
					    }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 973 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (1)].ptr)->code);			//=> Check why? it is giving segmentation fault???
					    }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 977 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
																				//  $$->code=append($$->code,$1->code);			
																				//=> Check why? it is giving segmentation fault???
					    }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 982 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (1)].ptr)->code);			//=> Check why? it is giving segmentation fault???
					    }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 986 "yacc.y"
    { (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (2)].ptr)->code);			//=> Check why? it is giving segmentation fault???
					   					}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 990 "yacc.y"
    { (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
																				//  $$->code=append($$->code,$1->code);			
																				//=> Check why? it is giving segmentation fault???
					   					}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 995 "yacc.y"
    { (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(2) - (3)].ptr)->code);			//=> Check why? it is giving segmentation fault???
					   					}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1001 "yacc.y"
    {
							OpenScope(0);										//printf("hello3 compound\n");
						  }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1003 "yacc.y"
    { CloseScope(0); (yyval.ptr)=(yyvsp[(3) - (4)].ptr);	}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1006 "yacc.y"
    { (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (2)].ptr)->code);
  								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(2) - (2)].ptr)->code);  			//=> Check why? it is giving segmentation fault???
																				//  printf("State_List Stmt  \n");
								 }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1012 "yacc.y"
    { (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));	// printf("blank reduce\n");
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));	
								}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1017 "yacc.y"
    {OpenScope(0);}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1017 "yacc.y"
    {						//printf("hello1 compound\n");
																							CloseScope(0);
																 							 if((yyvsp[(7) - (8)].ptr)==NULL){(yyval.ptr) = handle_if(ifsym,(yyvsp[(4) - (8)].ptr),(yyvsp[(7) - (8)].ptr),NULL);	}
															     							 else {(yyval.ptr) = handle_if(ifsym,(yyvsp[(4) - (8)].ptr),(yyvsp[(7) - (8)].ptr),(yyvsp[(8) - (8)].ptr));	}
															   						
																  						 }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1023 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (1)].ptr)->code);											//{ printf("State\n");}
								  																				//=> Check why? it is giving segmentation fault???
						}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1028 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								  (yyval.ptr)->code=append((yyval.ptr)->code,(yyvsp[(1) - (1)].ptr)->code);
																												//  { printf("Compound_State	 \n");}			
																												//=> Check why? it is giving segmentation fault???
					    }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1042 "yacc.y"
    {
									(yyval.ptr)=(yyvsp[(2) - (2)].ptr);																		//{ printf("Inside else \n");}
								   }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1045 "yacc.y"
    { 		  (yyval.ptr) =  (nodeType*)malloc(sizeof(nodeType));
								  			  (yyval.ptr)->code = (Code*)malloc(sizeof(Code));
								    }
    break;



/* Line 1455 of yacc.c  */
#line 3618 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1050 "yacc.y"


nodeType *id_handler(char* name, int type)                           
{
	Node* ptr=(Node*)malloc(sizeof(Node)); 	
	ptr = tableSearch(name,currentSymTable);	   		// table search or symSearch???
														//ptr = symSearch(name);
														//printf("mai aa gaya124312!\n");
	if(!ptr)
	{
		ptr = getNewBasicSymbol(type,name);
		ptr->type = type;
														//		printf("output:%s input:%s type:%d\n",ptr->name,name,ptr->type);  
														//Add for other types as well if any left!	
		if(type==1 || type==4){							//Integer,volatile
		ptr->stackOffset=getOffset();
		
		incOffset(4);}
		else if(type==3){								//char
		ptr->stackOffset=getOffset();
		incOffset(4);
		}
		else if(type==5 || type==7){					//short
		ptr->stackOffset=getOffset();
		incOffset(4);
		}
		else if(type==2 || type==6 || type==8){			//double,float,long
		ptr->stackOffset=getOffset();
		incOffset(8);}									//SET WIDTH N OFFSET IN TABLE	
	}
	else
	{
		if(ptr->type==11)
		{
		printf("Error: redeclaration of function:'%s' at line %d\n",name, linenum);
		check=1;
		}
		else{
		printf("Error: redeclaration of variable:'%s' at line %d\n",name, linenum);
		check=1;
		}
	}

	return id(name);
}

nodeType *id(char* i) 
{
	nodeType *p;
       
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{	yyerror("insufficient space on disk"); check=1;}
	
	if(p->code==NULL){
	p->code = (Code*)malloc(sizeof(Code));
			}
		int idtype;
        if(symSearch(i)==NULL)
        {
        printf("Error: undefined reference to:'%s' at line %d\n", i,linenum);
        check=1;
        p->type=0;
        }
	else{	
		idtype = symSearch(i)->type;  
		p->type = idtype;	
		p->datatype=9;			
		p->place = symSearch(i); 
			}
			p->name = i;
													//printf("returned from id\n");
													//p->treeNode = malloc(sizeof(node));	
													//p->treeNode->id.name = (char*) malloc(sizeof(char)*strlen(i));
													//strcpy(p->treeNode->id.name,i);
	return p;
}

List* appendLists(List* l1,List* l2){
	List *t;
	t = malloc(sizeof(List));
	t=l1;
	if(l1==NULL)return l2;
	while(t->next!=NULL)
	{t = t->next;}

													//t->next = malloc(sizeof(List *));
	t->next = l2;
													//l1 = t;
	return l1;
	}
	
nodeType *typeset(int datatype)
{
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
													//	yyerror("out of memory");
	{yyerror("insufficient space on disk"); check=1;}
	/* copy information */
	p->type = datatype;
	p->datatype = 1;
													//	typeID=datatype;
	return p;	
}

nodeType *con(int value) 
{
	nodeType *p;
	
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{yyerror("insufficient space on disk"); check=1;}
	if(p->code==NULL){
	p->code = (Code*) malloc(sizeof(Code));
					}
	p->type = 1;
	p->treeNode = malloc(sizeof(Node));
	p->treeNode->int_con.value = value;
													 //	printf("treenode=%d\n",p->treeNode->int_con.value);
	
	Node *temporary = malloc(sizeof(Node));
	temporary->type = 1;
	temporary->stackOffset = getOffset();
	incOffset(4);

	GenCODEnode_int(int_to_const, temporary, value, p->code);
	p->place = temporary;
	return p;
}

nodeType *u_con(unsigned int value)
{
	nodeType *p;	
	if ((p = malloc(sizeof(nodeType))) == NULL)
		{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*) malloc(sizeof(Code));
					}
	p->type = 4;
	p->treeNode = malloc(sizeof(Node));
	p->treeNode->ui_con.value = value;
													//	printf("treenode=%d\n",p->treeNode->s_con.value);
	Node *temporary = malloc(sizeof(Node));
	temporary->type = 4;
	temporary->stackOffset = getOffset();
	incOffset(4);

	GenCODEnode_int(int_to_const, temporary, value, p->code);
	p->place = temporary;
	return p;
}

nodeType *scon(short value)
{
	nodeType *p;	
	if ((p = malloc(sizeof(nodeType))) == NULL)
		{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*) malloc(sizeof(Code));
					}
	p->type = 5;
	p->treeNode = malloc(sizeof(Node));
	p->treeNode->s_con.value = value;
													//	printf("treenode=%d\n",p->treeNode->s_con.value);

	Node *temporary = malloc(sizeof(Node));
	temporary->type = 5;
	temporary->stackOffset = getOffset();
	incOffset(4);

	GenCODEnode_int(int_to_const, temporary, value, p->code);
	p->place = temporary;
	return p;
}


nodeType *u_scon(unsigned short value)
{
	nodeType *p;	
	if ((p = malloc(sizeof(nodeType))) == NULL)
		{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*) malloc(sizeof(Code));
					}
	p->type = 7;
	p->treeNode = malloc(sizeof(Node));
	p->treeNode->us_con.value = value;
													//	printf("treenode=%d\n",p->treeNode->s_con.value);
	Node *temporary = malloc(sizeof(Node));
	temporary->type = 7;
	temporary->stackOffset = getOffset();
	incOffset(4);

	GenCODEnode_int(int_to_const, temporary, value, p->code);
	p->place = temporary;
	return p;
}

nodeType *lcon(long value)
{
	nodeType *p;	
	if ((p = malloc(sizeof(nodeType))) == NULL)
		{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*) malloc(sizeof(Code));
					}
	p->type = 6;
	p->treeNode = malloc(sizeof(Node));
	p->treeNode->l_con.value = value;
													//	printf("treenode=%d\n",p->treeNode->s_con.value);
	Node *temporary = malloc(sizeof(Node));
	temporary->type = 6;
	temporary->stackOffset = getOffset();
	incOffset(8);

	GenCODEnode_int(int_to_const, temporary, value, p->code);
	p->place = temporary;
	return p;
}

nodeType *u_lcon(unsigned long value)
{
	nodeType *p;	
	if ((p = malloc(sizeof(nodeType))) == NULL)
		{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*) malloc(sizeof(Code));
					}
	p->type = 8;
	p->treeNode = malloc(sizeof(Node));
	p->treeNode->ul_con.value = value;
													//	printf("treenode=%d\n",p->treeNode->s_con.value);
	Node *temporary = malloc(sizeof(Node));
	temporary->type = 8;
	temporary->stackOffset = getOffset();
	incOffset(8);

	GenCODEnode_int(int_to_const, temporary, value, p->code);
	p->place = temporary;
	return p;
}

nodeType *fcon(float value) 
{
	nodeType *p;
	if ((p = malloc(sizeof(nodeType))) == NULL)
		{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*) malloc(sizeof(Code));
					}
	p->type = 2;
	p->treeNode = malloc(sizeof(Node));
	p->treeNode->f_con.value = value;
													//	printf("treenode=%d\n",p->treeNode->s_con.value);
	Node *temporary = malloc(sizeof(Node));
	temporary->type = 2;
	temporary->stackOffset = getOffset();
	incOffset(8);

	GenCODEnode_float(float_to_const, temporary, value, p->code);
	p->place = temporary;
	return p;
}

/*Some Functions that we will be using for intermediate code generation starts here*/

Code* append(Code *l1,Code *l2)
{
	if(l2==NULL){
		if(l1==NULL){
		return NULL;
	        }
		else return l1;
	}
	if(l1==NULL){
        l1 = malloc(sizeof(Code));
		l1 = l2;
		return l1;
	}
	
	Code *newcode; 
	newcode = malloc(sizeof(Code));
	newcode = l1;
	while (newcode->next!=NULL){
		newcode=newcode->next;
	}
	if (newcode->next==NULL){
		newcode->next= l2;
	}
	return l1;
}
void Update(Code *Code_list,entry *tmpt1)
{  
	Code *temp_code = (Code*)malloc(sizeof(Code));
	temp_code = Code_list;
	while(temp_code->next != NULL){
		temp_code = temp_code->next;
	} 
	temp_code->next = malloc(sizeof(Code));
	temp_code->next->head = tmpt1;
	temp_code->next->next = NULL;	
}

void topGenCODEstring(enum OPCODE opcode,char *str, Code *Code_list)
{
	entry *tmpt1 = (entry*)malloc(sizeof(entry));
	tmpt1->opcode = opcode;
 														   //tmpt1->target.nodeType_target = target;
	tmpt1->argumt1.str = str;
	tmpt1->argumt2.ival = strno;
	Update(Code_list,tmpt1);
}

void GenCODEstringprint(enum OPCODE opcode,int t3,Code *Code_list)
{
	entry *tmpt1 = (entry*)malloc(sizeof(entry));
	tmpt1->opcode = opcode;
	tmpt1->argumt1.ival = t3;
	strno++;
	Update(Code_list,tmpt1);
}
void GenCODEnode_node(enum OPCODE opcode,Node *target, Node* source, Code *Code_list )
{
	entry *tmpt1 = (entry*)malloc(sizeof(entry));
	tmpt1->opcode = opcode;
        tmpt1->target.nodeType_target = target;
	tmpt1->argumt1.nodeType_arg = source;
	Update(Code_list,tmpt1);
}

void GenCODEnode_node_node(enum OPCODE opcode, Node *target, Node *source1,Node *source2,Code *Code_list)
{
	entry *tmp1= (entry*)malloc(sizeof(entry));
    tmp1->opcode = opcode;
	tmp1->target.nodeType_target = target;
        tmp1->argumt1.nodeType_arg = source1;
        tmp1->argumt2.nodeType_arg = source2;
        Update(Code_list,tmp1);
}

void GenCODEnode_node_int(enum OPCODE opcode, Node *t1, Node *t2, int t3, Code *Code_list)
{
	entry *tmp1= (entry*)malloc(sizeof(entry));
	tmp1->opcode = opcode;
        tmp1->target.nodeType_target = t1;
        tmp1->argumt1.nodeType_arg = t2;
        tmp1->argumt2.ival = t3;
	Update(Code_list,tmp1);
}

void GenCODEnode_int(enum OPCODE opcode, Node *target, int val, Code *Code_list)
{	
	entry *tmpt= (entry*)malloc(sizeof(entry));
	tmpt->opcode = opcode;
        tmpt->target.nodeType_target = target;
	tmpt->argumt1.ival = val;
        Update(Code_list,tmpt);	
}

void GenCODEnode_int_int(enum OPCODE opcode, Node *target, int val1, int val2, Code *Code_list){	
	entry *tmp1= (entry*)malloc(sizeof(entry));
	tmp1->opcode = opcode;
        tmp1->target.nodeType_target = target;
	tmp1->argumt1.ival = val1;
	tmp1->argumt2.ival = val2;
	Update(Code_list,tmp1);
}

void GenCODEnode_float(enum OPCODE opcode, Node *target, float val, Code *Code_list)
{
	entry *tmpt1= (entry*)malloc(sizeof(entry));
	tmpt1->opcode = opcode;
	tmpt1->target.nodeType_target = target;
	tmpt1->argumt1.fval = val;
	Update(Code_list,tmpt1);	
}

void GenCODEnode(enum OPCODE opcode,Node *target, Code *Code_list)
{
	entry *tmpt1= (entry*)malloc(sizeof(entry));
	tmpt1->opcode = opcode;
	tmpt1->target.nodeType_target = target;      
    Update(Code_list,tmpt1);
}

void print_Code(Code *list){	
	if(list == NULL){		
		return;
	}
	Code *temp_code = malloc(sizeof(Code));
	temp_code = list;
	int i=0;
	while(temp_code->next != NULL){
		if(temp_code->head != NULL)
		{
			printf("COde:%d->\t%d \n",i,temp_code->head->opcode);
			i++;
		}
		temp_code = temp_code->next;		
								  }
		if(temp_code->head != NULL){
		printf("COde:%d->\t%d \n",i,temp_code->head->opcode);
		i++;
	}
}

void GenCODEstring_node_node(enum OPCODE opcode, char *target, Node *source1, Node *source2,Code *Code_list)
{
    entry *tmpt= (entry*)malloc(sizeof(entry));
    tmpt->opcode = opcode;	
    tmpt->target.char_target = target; 						//Labels
    tmpt->argumt1.nodeType_arg = source1;
    tmpt->argumt2.nodeType_arg = source2;
    Update(Code_list,tmpt);
}

void GenCODEstring_node(enum OPCODE opcode, char *target, Node *source1,Code *Code_list)
{
    entry *tmpt= (entry*)malloc(sizeof(entry));
    tmpt->opcode = opcode;	
    tmpt->target.char_target = target;
    tmpt->argumt1.nodeType_arg = source1;
    Update(Code_list,tmpt);
}

void GenCODEstring_int(enum OPCODE opcode, char *target, int val, Code *Code_list){
	entry *tmpt1= (entry*)malloc(sizeof(entry));
	tmpt1->opcode = opcode;
	tmpt1->target.char_target = target;
	tmpt1->argumt1.ival= val;
        Update(Code_list,tmpt1);											//print_Code(Code_list);
	
}

void GenCODEstring(enum OPCODE opcode, char *target, Code *Code_list)
{	
	entry *tmpt2= (entry*)malloc(sizeof(entry));
	tmpt2->opcode = opcode;
	tmpt2->target.char_target = target;
	Update(Code_list,tmpt2);
}

			//Performs Operations ...
/*
nodeType *perform_assignment(int oper,nodeType *arg1,nodeType *arg2) 
{
nodeType *p;
      
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror();
	if(p->code==NULL){
	p->code = (Code*)malloc(sizeof(Code));
			}	
	if(arg1->place->type==5 && arg2->type==5 ){                
	arg1->place->stackOffset=getOffset();
	struct SymbolTable* tmp=symSearch(arg2->place->name)->local_var;
	Node * ivar=tmp->symArray->next;
	
       	struct SymbolTable* obj_local_vars=malloc(sizeof(struct SymbolTable));
	obj_local_vars->offset=getOffset();
	
	Node * obj=(Node*)malloc(sizeof(Node));;
	Node * tmpe=obj; 
	
	
	while(ivar!=NULL)
	{
	obj->type=ivar->type;
	obj->name=(char*)malloc(sizeof(char));
	
	strcpy(obj->name,ivar->name);
	
	obj->stackOffset=getOffset();
	
	obj->acc_type=ivar->acc_type;
	if(obj->type==1)incOffset(4);
	else if (obj->type==2)incOffset(8);
	else if(obj->type==3)incOffset(4);
	else {printf("");}
	obj->next=(Node*)malloc(sizeof(Node));
	obj=obj->next;
	
	ivar=ivar->next;
	
	}obj=NULL;obj_local_vars->symArray=tmpe;
	arg1->place->local_var=obj_local_vars;
	
	  }
	else if(arg1->type == 1 && (arg2->type==1||arg2->type==3)){
		p->code = append(p->code, arg1->code);
		p->code = append(p->code, arg2->code);
		p->type = 1; 
		GenCODEnode_node(assigni+oper,  arg1->place, arg2->place, p->code);
		}
        else if(arg1->type == 1 && !(arg2->type==1||arg2->type==3)){
		printf("type error at %d\n",line_no);check=1;
		p->type = 11;
		}
	else if(arg1->type == 3 && !(arg2->type==1||arg2->type==3)){
		printf("type error at %d\n",line_no);check=1;
		p->type = 11;
		}
	else if(arg1->type == 3 && (arg2->type==1||arg2->type==3)){
		p->code = append(p->code, arg1->code);
		p->code = append(p->code, arg2->code);
		p->type = 3;
		GenCODEnode_node(assignf,  arg1->place, arg2->place, p->code);
		}
	else if(arg1->type == 2 && arg2->type==2){
		p->code = append(p->code, arg1->code);
		p->code = append(p->code, arg2->code);
		p->type=2;
		GenCODEnode_node(assignf,  arg1->place, arg2->place, p->code);}
	else if(arg1->type == 2 && (arg2->type==1||arg2->type==3)){	
		Node *temp_node = malloc(sizeof(Node));
		temp_node->type = 2;

		temp_node->stackOffset = getOffset();
		incOffset(8);p->type=2;
		p->code = append(p->code, arg1->code);
		p->code = append(p->code, arg2->code);
		GenCODEnode_node(int_to_float, temp_node, arg2->place, p->code);//???????????  /
		GenCODEnode_node(assignf,  arg1->place, temp_node, p->code);
		}
	else{	printf("type error at %d\n",line_no);check=1;
		p->type = 11;	
		}
//printf("p assigneed type%d",p->type);
return p;
}*/
			//Perform unary expressions .. Decr,Incr
perform_unary(int oper,nodeType *arg)
{
	nodeType *p;
    if ((p = malloc(sizeof(nodeType))) == NULL)
    {
	yyerror("insufficient space on disk");check=1;
	}
	if(p->code==NULL)
	{
	p->code = (Code*)malloc(sizeof(Code));
	}
	p->place = arg->place;
	if(arg->type==1||arg->type==2|| (arg->type>=4 && arg->type<=8))
		{
		if((arg->type>=4 && arg->type<=8) ||arg->type==1 )
			{
			p->type = 1;
			}
		else p->type = 2;
		GenCODEnode(incr,arg->place, arg->code);
		p->code = append(p->code,arg->code);
		}
		else {
			//printf("type error at %d\n",line_no);check=1;
			}
}
			//Performs operations boolean . ..

nodeType *perform_boolean(int oper,nodeType *arg1,nodeType *arg2) 
{
	nodeType *p;
    if ((p = malloc(sizeof(nodeType))) == NULL)
    {
	yyerror("insufficient space on disk");check=1;
	}
	if(p->code==NULL)
	{
	p->code = (Code*)malloc(sizeof(Code));
	}	
			if((arg1->type==1 ||(arg1->type>=4 && arg1->type<=8)) && (arg2->type==1 ||(arg2->type>=4 && arg2->type<=8))){
				p->type = 1;
				Node* temp = malloc(sizeof(Node));
				char * label1 =(char*)malloc(sizeof(char));
				sprintf(label1, "label%d", labelno);
				temp->type = 1;
		
				temp->stackOffset = getOffset();
				incOffset(4);
				labelno++;
				char * label2 =(char*)malloc(sizeof(char));
				sprintf(label2, "label%d", labelno);
				labelno++;
				p->code = append(p->code, arg1->code);
				p->code = append(p->code, arg2->code);
				
				GenCODEstring_node_node(oper, label1, arg1->place, arg2->place, p->code);
				GenCODEnode_int(int_to_const, temp, 0, p->code);
				GenCODEstring(jump, label2, p->code);
				GenCODEstring(label, label1, p->code);
				GenCODEnode_int(int_to_const, temp, 1, p->code);
				GenCODEstring(label, label2, p->code);
				p->place = temp;
			}
			else if(arg1->type==2&&(arg2->type==2)){
				p->type = 2;
				Node* temp = malloc(sizeof(Node));
				char * label1 =(char*)malloc(sizeof(char));
				sprintf(label1, "label%d", labelno);
				temp->type = 1;
		
				temp->stackOffset = getOffset();
				incOffset(8);
				labelno++;
				char * label2 =(char*)malloc(sizeof(char));
				sprintf(label2, "label%d", labelno);
				labelno++;
				p->code = append(p->code, arg1->code);
				p->code = append(p->code, arg2->code);
				
				GenCODEstring_node_node(oper+1, label1, arg1->place, arg2->place, p->code);
				GenCODEnode_int(int_to_const, temp, 0, p->code);
				GenCODEstring(jump, label2, p->code);
				GenCODEstring(label, label1, p->code);
				GenCODEnode_int(int_to_const, temp, 1, p->code);
				GenCODEstring(label, label2, p->code);
				p->place = temp;
			}
			else{
				p->type = 11;
				//printf("type error at %d\n",linenum);
				yyerror("type error");
				check=1;
			}
return p;
}
					//Performs logical
nodeType *perform_logical(int oper,nodeType *arg1,nodeType *arg2) 
	{
	nodeType *p;
      	if ((p = malloc(sizeof(nodeType))) == NULL)
		{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
		p->code = (Code*)malloc(sizeof(Code));
	}	
	if((arg1->type==1 ||(arg1->type>=4 && arg1->type<=8)) && (arg2->type==1 ||(arg2->type>=4 && arg2->type<=8))){
		p->type = 1;
		Node* temp = malloc(sizeof(Node));
		temp->type = 1;		
		temp->stackOffset = getOffset();
		incOffset(4);
		p->code = append(p->code, arg1->code);
		p->code = append(p->code, arg2->code);
		GenCODEnode_node_node(oper, temp, arg1->place, arg2->place, p->code);	
		p->place = temp;
	}
	else{
		p->type = 11;
		//printf("type error at %d\n",linenum);
		yyerror("type error");
		check=1;
	}
	return p;
	}
					//Performs arithmetic..			
nodeType *perform_arithmetic(int oper, nodeType *arg1, nodeType *arg2, int bit) 
{
nodeType *p;     
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*)malloc(sizeof(Code));
			}	
	 Node* tempnode1 = malloc(sizeof(Node));
	 Node* tempnode2 = malloc(sizeof(Node));
			if((arg1->type==1 ||(arg1->type>=4 && arg1->type<=8)) && (arg2->type==1)) {				
				tempnode1->stackOffset = getOffset();
				incOffset(4);
				tempnode1->type=1;
				p->code = append(p->code, arg1->code);
				p->code = append(p->code, arg2->code);
				p->type = 1;
				GenCODEnode_node_node(oper, tempnode1, arg1->place, arg2->place, p->code);
				if(bit==1)GenCODEnode_node(assigni,  arg1->place, tempnode1, p->code);
				p->place = tempnode1;
			}
			else if((arg1->type==2) && (arg2->type==1 ||(arg2->type>=4 && arg2->type<=8))) {
				tempnode1->type =  2;
				tempnode1->stackOffset = getOffset();
				incOffset(8);
				tempnode2->type =  2;
				tempnode2->stackOffset = getOffset();
				incOffset(8);
				p->code = append(p->code, arg1->code);
				p->code = append(p->code, arg2->code);
				GenCODEnode_node(int_to_float, tempnode1, arg2->place, p->code);
				p->type = 2;
				GenCODEnode_node_node(oper+1, tempnode2, arg1->place, tempnode1, p->code);
				if(bit==1)GenCODEnode_node(assignf,  arg1->place, tempnode2, p->code);				
				p->place = tempnode2;
			}
			else if((arg1->type==1 ||(arg1->type>=4 && arg1->type<=8)) && (arg2->type==2)) {				
				tempnode1->type =  2;
				tempnode1->stackOffset = getOffset();
				incOffset(8);				
				tempnode2->type =  2;
				tempnode2->stackOffset = getOffset();
				incOffset(8);p->code = append(p->code, arg1->code);
				p->code = append(p->code, arg2->code);	
				GenCODEnode_node(int_to_float, tempnode2, arg1->place, p->code); 
				p->type = 2;
				GenCODEnode_node_node(oper+1, tempnode1, arg2->place, tempnode2, p->code);
				if(bit==1)GenCODEnode_node(assignf,  arg2->place, tempnode1, p->code);	
				p->place = tempnode1;
			}
			else if((arg1->type==2) && (arg2->type==2)) {
				
				
				tempnode2->stackOffset = getOffset();
				incOffset(8);		
				tempnode2->type=2;
				p->code = append(p->code, arg1->code);
				p->code = append(p->code, arg2->code);
				p->type = 2;				
				GenCODEnode_node_node(oper+1, tempnode2, arg1->place, arg2->place, p->code); ////////////////CHK IF IT IS OPER+1
                if(bit==1)GenCODEnode_node(assignf, arg1->place, tempnode2, p->code);
				p->place = tempnode2;
			}
			else
			{
				//printf("type error at %d\n",linenum);
				yyerror("type error");
				check=1;
				p->type = 11;				
			}
return p;
}

nodeType *perform_binary(int oper, nodeType *arg1, nodeType *arg2, int bit) 
{
nodeType *p;     
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*)malloc(sizeof(Code));
			}	
	 Node* tempnode1 = malloc(sizeof(Node));
	 Node* tempnode2 = malloc(sizeof(Node));
			if((arg1->type==1 ||(arg1->type>=4 && arg1->type<=8)) && (arg2->type==1 ||(arg2->type>=4 && arg2->type<=8))) {				
				tempnode1->stackOffset = getOffset();
				incOffset(4);
				tempnode1->type=1;
				p->code = append(p->code, arg1->code);
				p->code = append(p->code, arg2->code);
				p->type = 1;
				GenCODEnode_node_node(oper, tempnode1, arg1->place, arg2->place, p->code);
				if(bit==1)GenCODEnode_node(assigni,  arg1->place, tempnode1, p->code);
				p->place = tempnode1;
			}
			else
			{
				//printf("type error at %d\n",linenum);
				yyerror("type error");
				check=1;
				p->type = 11;				
			}
return p;
}
						//Performs code generation for IF and ELSE.		
nodeType *handle_if(int oper,nodeType *arg1,nodeType *arg2,nodeType *arg3) 
{
	char *next = (char*)malloc(sizeof(char)); 
	nodeType *p;
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*)malloc(sizeof(Code));
			}	
	if(arg1->type==1||arg1->type==2||arg1->type==3)
	{
	p->type= arg2->type;
	Node* temporary = malloc(sizeof(Node *));

	char * label1 =(char*)malloc(sizeof(char)); // C.true.next
	sprintf(label1, "label%d", labelno);
	labelno++;
	

	  //S.next
	sprintf(next, "next%d", nextlabelno);
	nextlabelno++;

	temporary->type = 1;
	temporary->stackOffset=getOffset();
	incOffset(4);

	
	p->code = append(p->code, arg1->code);	//Scode=Bcode

	GenCODEstring_node(ifsym, label1, arg1->place, p->code);
	p->code = append(p->code, arg2->code);
	GenCODEstring(jump,next,p->code);
	GenCODEstring(label,label1,p->code);
	
//	GenCODEnode_int(int_to_const, temporary, 0, p->code); //label(btrue)				//////NOT REQUIRED??????????????????????
//	GenCODEstring_node_node(ifsym, label1, arg1->place, temporary, p->code);
//	p->code = append(p->code, arg2->code); //scode=S1.code
//	GenCODEstring(jump, next, p->code);  //goto label/
//	GenCODEstring(label, label1, p->code); // label Bfalse


	if (arg3!=NULL){
		//if (arg2->type!=arg3->type){
		//p->type =11;
		//printf("type error");}
		/*else*/ 
		p->code = append(p->code, arg3->code);
		}
	GenCODEstring(label, next, p->code); 
	}
	else	{p->type =11;
	//printf("type error at %d\n",linenum);
	yyerror("type error");
	check=1;
	}
	//GenCODEstring(label,next,p->code);
		
return p;

}
						//Performs code generation for While..	
nodeType *handle_while(int oper,nodeType *arg1,nodeType *arg2) 
{
nodeType *p;
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*)malloc(sizeof(Code));
			}	
	if(arg1->type==1||arg1->type==2||arg1->type==3){
	p->type= 12;
	Node* temporary = malloc(sizeof(Node *));

	char * label1 =(char*)malloc(sizeof(char)); // C.true.next
	sprintf(label1, "iter%d", loopno);
	loopno++;
	//char * label2 =(char*)malloc(sizeof(char)); // C.true.next
	//sprintf(label2, "iter%d", loopno);
	//loopno++;
	char *next = (char*)malloc(sizeof(char));   //S.next
	sprintf(next, "nextl%d", nextloopnno);
	nextloopnno++;
	temporary->type = 1;
	temporary->stackOffset = getOffset();
	incOffset(4);

	GenCODEstring(label, label1, p->code);
	p->code = append(p->code, arg1->code);	

	GenCODEstring_node(whilesym, next, arg1->place, p->code);
	p->code =append(p->code, arg2->code);
	GenCODEstring(jump, label1, p->code);
	GenCODEstring(label, next, p->code);
		


//GenCODEnode_int(int_to_const, temporary, 0, p->code);
	
	}
	else	{p->type =11;
	//printf("type error at %d\n",linenum);
	yyerror("type error");
	check=1;}
return p;

}
			//Performs code generation for FOR..
nodeType *handle_for(int oper,nodeType *arg1,nodeType *arg2,nodeType *arg3,nodeType *arg4) 
{
nodeType *p;
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{yyerror("insufficient space on disk");check=1;}
	if(p->code==NULL){
	p->code = (Code*)malloc(sizeof(Code));
			}	
	if(arg2->type==1||arg2->type==2||arg2->type==3){
	p->type= 12;
	p->code = append(p->code, arg1->code);	
	p->place = NULL;
	Node* temporary = malloc(sizeof(Node *));

	char * label1 =(char*)malloc(sizeof(char)); // C.true.next
	sprintf(label1, "iter%d", loopno);
	loopno++;
	char * label2 =(char*)malloc(sizeof(char)); // C.true.next
	
	char *next = (char*)malloc(sizeof(char));   //S.next
	sprintf(next, "nextl%d", nextloopnno);
	nextloopnno++;
	temporary->type = 1;
	temporary->stackOffset = getOffset();
	incOffset(4);


	GenCODEstring(label, label1, p->code);
	p->code = append(p->code, arg2->code);	
	
	GenCODEstring_node(forloop, next, arg2->place, p->code);
	
	p->code =append(p->code, arg4->code);

	if(arg3!=NULL){p->code = append(p->code, arg3->code);
	}
	GenCODEstring(jump, label1, p->code);
	GenCODEstring(label, next, p->code);
	
	}
	else	{p->type =11;
	//printf("type error at %d\n",linenum);
	yyerror("type error");
	check=1;}
return p;

}


int iscompatible(int a, int b){
	//printf("a=%d ;b=%d\n",a,b);
	if(a==b)
	{
	return 1;
	}
	else if(a<=2 || (a>=4 && a<=8))
	{
	if(b<=2 || (b>=4 && b<=8))
	{
	return 1;
	}
	else return 0;
	}
	/*
	if(a==5) {
		if(b==5)
			return 1;
		else return 0;
	}
	else if(a==7) {
		if((b==5||b==7)&&b>0)
			return 1;
		else return 0;
	}
	else if(a==1){//printf("a=1,b=%d\n",b);
		if(b==1||b==5||b==7)
			return 1;
		else return 0;
	}
	else if(a==4){
		if((b==1||b==4||b==5||b==7)&&b>0)
			return 1;
		else return 0;
	}
	else if(a==6){
		if(b==1||b==4||b==5||b==6||b==7)
			return 1;
		else return 0;
	}
	else if(a==8){
		if((b==1||b==4||b==5||b==6||b==7|b==8)&&b>0)
			return 1;
		else return 0;
	}
	else if(a==2){
		//printf("yo-yo\n");
		//printf("a=1,b=%d\n",b);
		if(b<=2||(b>3 && b<=8))
			return 1;
		else return 0;
	}*/
	else if(a==3){
		if(b==3)
			return 1;
		else return 0;
	}
	else{
		return 0;
	}
	
}

void iscomp(int type1, int type2)
{
if (!iscompatible(type1,type2))
								{
								yyerror("Incompatible datatypes");check=1;
								}
}
int isoperable(int a,int b){
	switch(b){
		case 1:
		{
			if(a<=2||(a>=4&&a<=8))
				return 1;
			else 
				return 0;
		}
		case 2:
		{
			if(a<=1||(a>=4&&a<=8))
				return 1;
			else 
				return 0;
		}
	}
}


void code_printer(struct _code *intermediate_list)
{	
	if(intermediate_list == NULL)
	{
		printf("code is empty\n");
		return;
	}
	FILE *fid = fopen("asm", "w");
	
	entry *p = (entry*)malloc(sizeof(entry));
	int off1;
	int off2;
	int target;
	if(fid == NULL)
	{
		printf("cannot open file for output\n");
		return;
	}
	Code *temp_code = malloc(sizeof(Code));
	Code *temp_code1 = malloc(sizeof(Code));
	temp_code = intermediate_list;
	temp_code1 = intermediate_list;
	fprintf(fid, "\t.data\n");
													//	fprintf(fid, "str:\n");
													//	fprintf(fid, ".asciiz \" : is answer \\n\"\n");
	while(temp_code1 != NULL)
	{
		if(temp_code1->head == NULL)
		{
		temp_code1=temp_code1->next;
		continue;
		}
		p=temp_code1->head;
		if(p->opcode == printshdr)
		{
		fprintf(fid,"str%d: \t.asciiz %s\n", p->argumt2.ival,p->argumt1.str);
		}
	temp_code1=temp_code1->next;
	}
												//fprintf(fid,"newline: \t.asciiz "\n"\n");
												//newline: .asciiz	"\n"
	fprintf(fid, "\t.text\n");	
	while(temp_code != NULL){
	if(temp_code->head == NULL)
	{
	temp_code=temp_code->next;
	continue;
	}
	p=temp_code->head;
												//printf("printing\n%d,",p->opcode);
												//print_Code(temp_code);
		temp_code = temp_code->next;
		
/*************************************[uminus,incr,decr,int_to_const,float_to_const,assigni,assignf,forloop,whilesym]***********************************/

		if(p->opcode == uminus)
		{
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw $t1,%d($sp)\n", -target );
			fprintf(fid,"\tli $t3, -1\n");
			fprintf(fid,"\tmul $t2,$t1,$t3\n");
			fprintf(fid,"\tsw $t2,%d($sp)\n", -target );
		}
		else if(p->opcode == incr)
		{
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw $t1,%d($sp)\n", -target );
			fprintf(fid,"\tli $t3, 1\n");
			fprintf(fid,"\tadd $t1,$t1,$t3\n");
			fprintf(fid,"\tsw $t1,%d($sp)\n", -target );
		}
		else if(p->opcode == decr)
		{
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw $t1,%d($sp)\n", -target );
			fprintf(fid,"\tli $t3, 1\n");
			fprintf(fid,"\tsub $t1,$t1,$t3\n");
			fprintf(fid,"\tsw $t1,%d($sp)\n", -target );
		}
		else if(p->opcode == int_to_const)
		{
			int val = p->argumt1.ival;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tli $t5,%d\n", val);
			fprintf(fid,"\tsw $t5, %d($sp)\n", -target);
		}
		else if(p->opcode == float_to_const)
		{
			float val = p->argumt1.fval;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tli.s $f2,%f\n", val);
			fprintf(fid,"\tswc1 $f2, %d($sp)\n", -target);		
		}
		else if(p->opcode == assigni)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tsw  $t1,%d($sp) \n", -target);	
		}
		else if(p->opcode == assignf)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlwc1  $f1,%d($sp) \n", -off1);
			fprintf(fid,"\tswc1  $f1,%d($sp) \n", -target);
		}
		else if(p->opcode == forloop)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
        	fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
        	fprintf(fid,"\tli $t2,1\n");
        	fprintf(fid,"\tbne $t1,$t2,%s\n", p->target.char_target);
		}
		else if(p->opcode == whilesym)
		{
		 	off1 = p->argumt1.nodeType_arg->stackOffset;
            fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
            fprintf(fid,"\tli $t2,1\n");
            fprintf(fid,"\tbne $t1,$t2,%s\n", p->target.char_target);		
		}

/*************************************END[uminus,incr,decr,int_to_const,float_to_const,assigni,assignf,forloop,whilesym]***********************************/

/*****************************************************INT OPERATIONS[plus,minus,asterisk,divi]***********************************************/
		else if(p->opcode == plus){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tadd $t3,$t1,$t2 \n");
			fprintf(fid,"\tsw  $t3,%d($sp) \n", -target);
		}
		else if(p->opcode == minus){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tsub $t3,$t1,$t2 \n");
			fprintf(fid,"\tsw  $t3,%d($sp) \n", -target);
		}
		else if(p->opcode == asterisk){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tmul $t3,$t1,$t2 \n");
			fprintf(fid,"\tsw  $t3,%d($sp) \n", -target);
		}
		else if(p->opcode == divi){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tdiv $t3,$t1,$t2 \n");
			fprintf(fid,"\tsw  $t3,%d($sp) \n", -target);
		}
/*****************************************************INT OPERATIONS Ends Here***********************************************/

/*****************************************************FLOAT OPERATIONS[(float_)plus,minus,asterisk,divi]***********************************************/
		else if(p->opcode == float_plus)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
            fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tadd.s $f6,$f2,$f4 \n");
			fprintf(fid,"\tswc1  $f6,%d($sp) \n", -target);
		}
		else if(p->opcode == float_minus)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
            fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tsub.s $f6,$f2,$4\n");
			fprintf(fid,"\tswc1  $f6,%d($sp) \n", -target);
		}
		else if(p->opcode == float_asterisk)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tmul.s $f5,$f2,$f4 \n");
			fprintf(fid,"\tswc1  $f5,%d($sp) \n", -target);
		}
		else if(p->opcode == float_divi)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tdiv.s $f6,$f2,$f4 \n");
			fprintf(fid,"\tswc1  $f6,%d($sp) \n", -target);	
		}
/*****************************************************FLOAT OPERATIONS Ends Here***********************************************/

/*****************************************************EQUAL OPERATOR OPERATIONS[pluseq,minuseq,diveq,muleq]***********************************************/
		else if(p->opcode == pluseq)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -target);
			fprintf(fid,"\tadd $t3,$t1,$t2 \n");
			fprintf(fid,"\tsw $t3,%d($sp)\n", -target );
		}
		else if(p->opcode == minuseq)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -target);
			fprintf(fid,"\tsub $t3,$t1,$t2 \n");
			fprintf(fid,"\tsw $t3,%d($sp)\n", -target );
		}
		else if(p->opcode == diveq)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -target);
			fprintf(fid,"\tdiv $t3,$t1,$t2 \n");
			fprintf(fid,"\tsw $t3,%d($sp)\n", -target );
		}
		else if(p->opcode == muleq)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -target);
			fprintf(fid,"\tmul $t3,$t1,$t2 \n");
			fprintf(fid,"\tsw $t3,%d($sp)\n", -target );
		}
		
/*****************************************************OPERATOR OPERATIONS Ends Here***********************************************/

		else if(p->opcode == mod)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tdiv $t3,$t1,$t2 \n");
			fprintf(fid,"\tmul $t4,$t2,$t3 \n");
			fprintf(fid,"\tsub $t5,$t1,$t4 \n");
			fprintf(fid,"\tsw  $t5,%d($sp) \n", -target);
		}
		else if(p->opcode == int_to_float)
		{
		off1 = p->argumt1.nodeType_arg->stackOffset;
		target = p->target.nodeType_target->stackOffset;
		fprintf(fid,"\tlw $t1,%d($sp) \n", -off1);
		fprintf(fid,"\tmtc1 $t1, $f2 \n");
		fprintf(fid,"\tcvt.s.w $f2, $f2\n");
		fprintf(fid,"\tswc1 $f2,%d($sp) \n", -target);
		}

/*****************************************************PRINT OPCODES***********************************************/

		else if(p->opcode == printi)
		{
		target = p->target.nodeType_target->stackOffset;
		fprintf(fid,"\tlw $a0 %d($sp)\n",-target);
		fprintf(fid, "\tli $v0,1 \n\tsyscall\n");				//print int
		fprintf(fid, "\tli $a0,10\n\tli $v0,11 \n\tsyscall\n");
		}
		else if(p->opcode == printff)
		{
		target = p->target.nodeType_target->stackOffset;
		fprintf(fid,"\tlwc1 $f12 %d($sp)\n",-target);
		fprintf(fid, "\tli $v0,2 \n\tsyscall\n"); 				//print float
		fprintf(fid, "\tli $a0,10\n\tli $v0,11 \n\tsyscall\n");	//print character
		}
		else if(p->opcode == printshdr)
		{
																//fprintf(fid,"str%d: \t.asciiz %s\n", p->argumt2.ival,p->argumt1.str);
		}
		else if(p->opcode == prints)
		{
																//target = p->target.nodeType_target->stackOffset;
		fprintf(fid,"\tli $v0 4\n");
		fprintf(fid, "\tla $a0,\tstr%d \n\tsyscall\n",p->argumt1.ival);				//print int
																//fprintf(fid, "\tli $a0,10\n\tli $v0,11 \n\tsyscall\n");
		}
/*****************************************************PRINT OPCODES Ends here***********************************************/
/*li $v0, 4
la $a0, str
syscall
*/
//*****************************************************COMPARISONS***********************************************/
		else if(p->opcode == lesst)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tsub $t3,$t1,$t2 \n");		
			fprintf(fid,"\tbltz $t3,%s\n", p->target.char_target);
		}
		else if(p->opcode == great)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tsub $t3,$t1,$t2 \n");		
			fprintf(fid,"\tbgtz $t3,%s\n", p->target.char_target);
		}
		else if(p->opcode == ifequal)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tsub $t3,$t1,$t2 \n");		
			fprintf(fid,"\tbeqz $t3,%s\n", p->target.char_target);
		}
		else if(p->opcode == noteq)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tbne $t1,$t2,%s\n", p->target.char_target);
		}
		else if(p->opcode == leq)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tsub $t3,$t1,$t2 \n");		
			fprintf(fid,"\tblez $t3,%s\n", p->target.char_target);
		}
		else if(p->opcode == geq)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);
			fprintf(fid,"\tsub $t3,$t1,$t2 \n");		
			fprintf(fid,"\tbgez $t3,%s\n", p->target.char_target);
		}
		else if(p->opcode == compare)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tbeq $t1,$t2,%s\n", p->target.char_target);
		}
		
/*****************************************************COMPARE Ends Here***********************************************/

		else if(p->opcode == label)
		{
			fprintf(fid,"%s:\n", p->target.char_target);
		}
		
		else if(p->opcode == and)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tmul $t3,$t1,$t2\n");
			fprintf(fid,"\tsw  $t3,%d($sp)\n", -target);
		}
		else if(p->opcode == or)
		{
		off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tadd $t3,$t1,$t2\n");
			fprintf(fid,"\tsw  $t3,%d($sp)\n", -target);
		}

		else if(p->opcode == not)
		{
                       off1 = p->argumt1.nodeType_arg->stackOffset;
                       target = p->target.nodeType_target->stackOffset;
                       fprintf(fid,"\tlw $a0,%d($sp) \n", -off1);
                       fprintf(fid,"\tjal notfunc \n");
                       fprintf(fid,"\tsw $v1, %d($sp) \n", -target);
		
               }
		else if(p->opcode == binaryxor)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\txor $t3,$t1,$t2\n");
			fprintf(fid,"\tsw  $t3,%d($sp)\n", -target);
		}
		else if(p->opcode == binaryor)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tor $t3,$t1,$t2\n");
			fprintf(fid,"\tsw  $t3,%d($sp)\n", -target);
		}
		else if(p->opcode == binaryand)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tand $t3,$t1,$t2\n");
			fprintf(fid,"\tsw  $t3,%d($sp)\n", -target);
		}
		else if(p->opcode == rshift)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tsrl $t3,$t1,$t2\n");
			fprintf(fid,"\tsw  $t3,%d($sp)\n", -target);
		}
		else if(p->opcode == lshift)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tsll $t3,$t1,$t2\n");
			fprintf(fid,"\tsw  $t3,%d($sp)\n", -target);
		}
		else if(p->opcode == equal)
		{
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
			fprintf(fid,"\tlw  $t2,%d($sp) \n", -off2);			
			fprintf(fid,"\tbeq $t3,$t1,$t2\n");
			fprintf(fid,"\tsw  $t3,%d($sp)\n", -target);
		}
		else if(p->opcode == ifsym)
		{
             off1 = p->argumt1.nodeType_arg->stackOffset;
             fprintf(fid,"\tlw  $t1,%d($sp) \n", -off1);
             fprintf(fid,"\tli $t2,0\n");
             fprintf(fid,"\tble $t1,$t2,%s\n", p->target.char_target);
         }
        else if(p->opcode == jump)
        {
             fprintf(fid,"\tj %s\n", p->target.char_target);
        }
		else if(p->opcode == character)
		{                                			//initializaion by a character
                       int val = p->argumt1.ival;
                       target = p->target.nodeType_target->stackOffset;
                       fprintf(fid,"\tli $t1,%d\n", val);
                       fprintf(fid,"\tsw $t1, %d($sp)\n", -target);
        }	
		else if(p->opcode==ret){target=p->target.nodeType_target->stackOffset;
		fprintf(fid,"\tlw $v0,%d($sp)\n",-target);
		fprintf(fid,"\tadd $sp,$sp,500\n");		// restoring stack pointer	
		fprintf(fid,"\tjr $ra\n");
		}
		else if(p->opcode==func1){
		fprintf(fid,"\tsw $ra,($sp)\n");
		fprintf(fid,"\tsub $sp,$sp,500\n");		// changing stack pointer
		}
		


		else if(p->opcode==func2){
		
		//fprintf(fid,"\tsw $ra,($sp)\n");
		//fprintf(fid,"\tsub $sp,$sp,500\n");
		fprintf(fid,"\tjal %s\n",p->target.char_target);
		fprintf(fid,"\tlw $ra,($sp)\n");
		}
		else if (p->opcode==ret_only){
		fprintf(fid,"\tadd $sp,$sp,500\n");		// restoring stack pointer
		//fprintf(fid,"\tlw $ra,($sp)\n");
		fprintf(fid,"\tjr $ra\n");}


		else if(p->opcode==ret_val){
		target=p->target.nodeType_target->stackOffset;
		fprintf(fid,"\tsw  $v0,%d($sp) \n", -target);										
		}

		  else if(p->opcode == int_param){
               	target = p->target.nodeType_target->stackOffset-500;
		int val1 = p->argumt1.ival;
		int val2 = p->argumt2.ival;
		int off = val1+val2;
		fprintf(fid,"\tlw $t1,%d($sp) \n", -target);
		fprintf(fid,"\tsw $t1,%d($sp) \n", -off);
               }
               else if(p->opcode == float_param){
               target = p->target.nodeType_target->stackOffset;
		int val1 = p->argumt1.fval;
		int val2 = p->argumt2.fval;
		int off = val1+val2;
		fprintf(fid,"\tlwc1 $f1,%d($sp) \n", -target);                  	
		fprintf(fid,"\tswc1 $f1,%d($sp) \n", -off);
               }
               else if(p->opcode == char_param){
               target = p->target.nodeType_target->stackOffset;
		int val1 = p->argumt1.ival;
		int val2 = p->argumt2.ival;
		int off = val1+val2;
		fprintf(fid,"\tlw $t1,%d($sp) \n", -target);
		fprintf(fid,"\tsw $t1,%d($sp) \n", -off);
               }

		else if(p->opcode == float_lesst){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tc.lt.s $f2,$f4\n");
			fprintf(fid,"\tbc1f %s\n", p->target.char_target);
		}
		else if(p->opcode == float_great){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tc.le.s $f2,$f4\n");
			fprintf(fid,"\tbc1t %s\n", p->target.char_target);
		}
		else if(p->opcode == float_noteq){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tc.eq.s $f2,$f4\n");
			fprintf(fid,"\tbc1t %s\n", p->target.char_target);
		}
		else if(p->opcode == float_leq){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tc.le.s $f2,$f4\n");
			fprintf(fid,"\tbc1f %s\n",p->target.char_target);
		}
		else if(p->opcode == float_geq){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tc.lt.s $f2,$f4\n");
			fprintf(fid,"\tbc1t %s\n",p->target.char_target);
		}
		else if(p->opcode == float_compare){
			off1 = p->argumt1.nodeType_arg->stackOffset;
			off2 = p->argumt2.nodeType_arg->stackOffset;
			fprintf(fid,"\tlwc1  $f2,%d($sp) \n", -off1);
			fprintf(fid,"\tlwc1  $f4,%d($sp) \n", -off2);
			fprintf(fid,"\tc.eq.s $f2,$f4\n");
			fprintf(fid,"\tbc1f %s\n", p->target.char_target);
		}

		else if(p->opcode == reference_int){
			int off1 = p->argumt1.nodeType_arg->stackOffset;
			int target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw $t2,%d($sp)\n", -off1 );
			fprintf(fid,"\tsub $a0,$sp,$t2\n"); 
			fprintf(fid,"\tlw $t1,($a0)\n");
            		fprintf(fid,"\tsw $t1,%d($sp)\n", -target);
		}



			else if(p->opcode == assign_to_ref)
			{int off1 = p->argumt1.nodeType_arg->stackOffset;
			int target = p->target.nodeType_target->stackOffset;
			fprintf(fid,"\tlw $t2,%d($sp)\n", -off1 );
			fprintf(fid,"\tlw $t3,%d($sp)\n", -target );
			fprintf(fid,"\tsub $a0,$sp,$t3\n"); 
			fprintf(fid,"\tsw $t2,($a0)\n");


			}

		else{
			printf("The opcode is not valid\n");
		}
	   
	}	fprintf(fid,"\tli $v0,10\n\tsyscall\n");			//exit system call
}





