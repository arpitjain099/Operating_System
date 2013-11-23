flex lexical.l
yacc -d -v  yacc.y
gcc lex.yy.c y.tab.c -o parser

