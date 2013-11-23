%{
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
%}

%token <symbol> MAIN
%token CONTINUE
%token ASTERISK
%token BOOLEAN
%token PRINTF
%token DEFINE
%token INCR 
%token DECR
%token MOD
%token PD
%token PF
%token PLUS 
%token MINUS
%token DIV
%token signed_int
%token REL_OP
%token INTEGER
%token LOGICAL
%token CHARACTER
%token CHAR_DATA
%token <symbol> STRINGLITERAL
%token FLOAT
%token DOUBLE
%token LONG
%token SHORT
%token VOLATILE
%token SIGNED
%token VOID
%token CONST
%token BINARYXOR 
%token EQUALTO
%token BINARYONESCOMPLEMENT 
%token QUOTE
%token COLON
%token BINARYAND
%token BINARYOR 
%token DOT
%token SEMICOLON
%token COMMA
%token AND
%token OR
%token LSHIFT
%token RSHIFT
%token PLUSEQ
%token MINUSEQ
%token MULEQ
%token DIVEQ
%token BITANDEQ
%token BITOREQ
%token BITXOREQ
%token MODEQ
%token LSHIFTEQ
%token RSHIFTEQ
%token POINTERARROW
%token NOT
%token NOTEQ1
%token QUEST
%token BACKSLASH
%token PARENCLOSE
%token PARENOPEN
%token SQUAREOPENBRACKET
%token SQUARECLOSEBRACKET
%token BRACECLOSE
%token BRACEOPEN
%token HASH 
%token IF
%token ELSE
%token THEN
%token WHILE
%token FOR
%token INCLUDE
%token TYPEDEF
%token BREAK
%token SWITCH
%token ENUM
%token STRUCT
%token DO
%token DEFAULT
%token none
%token CASE
%token <symbol> IDENTIFIER
%token IFEQUAL
%token RETURN
%token UNSIGNED
%token <sign_short> SIGN_SHORT
%token <unsign_short> UNSIGN_SHORT
%token <sign_long> SIGN_LONG
%token <unsign_long> UNSIGN_LONG
%token <sign_int> SIGN_INT
%token <unsign_int> UNSIGN_INT
%token <float_data> FLOAT_DATA
%token TABSPACE
%union{
	int sign_short;
	int unsign_short;
	int sign_long;
	int unsign_long;
	int sign_int;
	int unsign_int;
	float float_data;
	char *symbol;
	struct nodeTypeTag* ptr;
} ;

%type <ptr> TYPE type_marker marker Assignment NUM Function PARENOPEN State_List Arg Arg_List Function_Call Expr Expr_Loop id_declarator Macros Macros1 start_1 start_main start_2 Declaration1 Compound_State ELSE_OPTIONAL Stmt State While_State For_State Switch_State Print_Funct Do_While_State Struct_State Enum_State enumerator enumerator_list argt
%left COMMA
%right EQUALTO PLUSEQ MINUSEQ MULEQ DIVEQ MODEQ BITANDEQ BITOREQ BITXOREQ RSHIFTEQ LSHIFTEQ 

/*%right tern*/

%left OR
%left AND
%left BINARYOR
%left BINARYXOR
%left BINARYAND
%left IFEQUAL NOTEQ NOTEQ1
%left LESST GREAT LEQ GEQ
%left RSHIFT LSHIFT
%left PLUS MINUS
%left ASTERISK DIV MOD
%right BINARYONESCOMPLEMENT NOT UMINUS PINCR PDECR UPLUS
%left INCR DECR POINTERARROW PARENOPEN PARENCLOSE

%start start_main

%%


start_main:start_1		{
						//print_Code($$->code);
						if(check==1)printf("Oops! Code not generated. Please Try again.\n"); 
						else{
						$$=$1;
						code_printer($1->code);
						}
						}
		;

start_1: Macros start_2 {
						$$=$2;
						}
	|Macros				{$$=$1;}
	|					{
						$$ = (nodeType*)malloc(sizeof(nodeType)); 
						$$->code = (Code*)malloc(sizeof(Code));//$$=NULL;
						}
	;
	
/* Declaration block */

Macros:  HASH INCLUDE LESST IDENTIFIER DOT IDENTIFIER GREAT Macros1 {$$=$8;}
		|HASH INCLUDE STRINGLITERAL Macros1							{$$=$4;}
		;

Macros1: Macros	{$$=$1;}
		|		{
					$$ = (nodeType*)malloc(sizeof(nodeType)); 
					$$->code = (Code*)malloc(sizeof(Code));
				}
		;
	
start_2: Function start_2	{ $$  = (nodeType*)malloc(sizeof(nodeType)); 	//printf("F_start2\n");
							  $$->code = (Code*) malloc(sizeof(Code));
							  $$->code = append($$->code,$1->code);  		/* printf("reading a line complete\n");*/	
							  $$->code = append($$->code,$2->code); 
							}	
	|Function start_1		{ $$  = (nodeType*)malloc(sizeof(nodeType));	//printf("F_start1\n");
							  $$->code = (Code*) malloc(sizeof(Code));
							  $$->code = append($$->code,$1->code);  		/* printf("reading a line complete\n");*/	
							  $$->code = append($$->code,$2->code); 
							}
	|Declaration1 start_2	{ $$  = (nodeType*)malloc(sizeof(nodeType));	 //printf("Decl_start2\n");
							  $$->code = (Code*) malloc(sizeof(Code));
							  $$->code = append($$->code,$1->code);  		 /* printf("reading a line complete\n");*/	
							  $$->code = append($$->code,$2->code); 
							}
	;

Function : TYPE MAIN PARENOPEN {											 //OpenScope(1);  //	printf("$2 = %s \n",$2);
								 	$<ptr>$= id_handler($2,10);
									$<ptr>$->ret=$1->type;
									symSearch($2)->ret=$1->type;
									symSearch($2)->local_var=(struct SymbolTable*)malloc(sizeof(struct SymbolTable));
	 								symSearch($2)->local_var=currentSymTable; 
	 																		 //OpenScope(0);
	 							}
	 							Arg_List
	 							{
	 								ListNodes* t=(ListNodes*)malloc(sizeof(ListNodes));
									List* tmp = (List*)malloc(sizeof(List));
												 							//printf("after $2 = %s \n",$2);	
		 							if($5!=NULL)
		 							{	
		 							tmp=$5->parameters;
		 							symSearch($2)->parameters=t;	
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
									else {symSearch($2)->parameters=NULL;}
								}
			PARENCLOSE Compound_State 	{									//printf("after $2 = %s \n",$2);
																			//printTable();
																			//CloseScope(0);
											$$  = (nodeType*)malloc(sizeof(nodeType)); 
											$$->code = (Code*) malloc(sizeof(Code));  
											GenCODEstring(label,"main",$$->code);	
											$$->code = append($$->code,$5->code);		//=> may give segmentation fault
											$$->code = append($$->code,$8->code);
										}									//{printf("TYPE MAIN PARENOPEN Arg_List PARENCLOSE Compound_State\n");}
	| TYPE IDENTIFIER PARENOPEN {											//OpenScope(1); 					
								 											//printf("$2 = %s \n",$2);
									$<ptr>$= id_handler($2,10);
																			//printf("offset is: %d\n",symSearch($2)->stackOffset);
								 	sprintf(func_name,$2); 
									$<ptr>$->ret=$1->type;
									symSearch($2)->ret=$1->type;
									symSearch($2)->local_var=(struct SymbolTable*)malloc(sizeof(struct SymbolTable));
	 								symSearch($2)->local_var=currentSymTable; 
	 								OpenScope(1);
							    }	
	Arg_List					{

									ListNodes* t=(ListNodes*)malloc(sizeof(ListNodes));
									List* tmp = (List*)malloc(sizeof(List));
		 																	//printf("after $2 = %s \n",$2);	
		 							if($5!=NULL)
		 							{	
		 							tmp=$5->parameters;
		 							symSearch($2)->parameters=t;	

									while(tmp)
									{
										t->first=tmp->first;
										if(tmp->next!=NULL){t->next=(ListNodes*)malloc(sizeof(ListNodes));
										t=t->next;}
										tmp=tmp->next;
									}
									}
									else {symSearch($2)->parameters=NULL;}
									}	
	  PARENCLOSE BRACEOPEN State_List BRACECLOSE {
	  									 										//   printTable();
					  			 			CloseScope(1);
					  			 			$$  = (nodeType*)malloc(sizeof(nodeType));					// Code generation..  
											$$->code = (Code*) malloc(sizeof(Code));
											if($5!=NULL)
											{
											$$->parameters=$5->parameters;
											}
											else $$->parameters=NULL;
									 		GenCODEstring(label,$2,$$->code); 
											$$->code = append($$->code,$5->code);						//=> may give segmentation fault
											$$->code = append($$->code,$9->code);
											GenCODEstring(ret_only,func_name,$$->code); 
																				//print_Code($$->code);
					  			 												//	printf("TYPE IDENTIFIER PARENOPEN Arg_List\n");
					  			}
	;
	
Arg_List: Arg_List COMMA Arg {	$$->parameters=appendLists($1->parameters,$3->parameters);
								$$->code = append($$->code,$1->code);
								$$->code = append($$->code,$3->code);
							 }
	| Arg 					 {	$$=$1;		  }
	|						 {
								$$ = (nodeType*)malloc(sizeof(nodeType)); 
								$$->code = (Code*)malloc(sizeof(Code));			//$$=NULL;
							 }
	| Arg_List error Arg{  
	  /* now we cannot parse further */
  	  printf("Syntax Error Arg_List Arg_List COMMA Arg	....at Line %d: \n", linenum);
	  yyclearin;
	  yyerrok;
	}
	;
Arg:	TYPE IDENTIFIER {														//	printf("bet of Arg = %s \n",$2);	
							$$= id_handler($2,$1->type);
																				//$$ = (nodeType*)malloc(sizeof(nodeType)); 
							List* var = (List*)malloc(sizeof(List));
							var->first=$1->type;
							var->head=$$->place;
							var->next=NULL;
							$$->parameters=var;
																				//$$->parameters = $2->parameters; 
 																				//	printf("out of Arg = %s \n",$2);								 
						}
	;

TYPE: INTEGER 			{ $$ = typeset(1) ; }
	| FLOAT				{ $$ = typeset(2) ; }
	| CHARACTER			{ $$ = typeset(3) ;	}										 //printf("hello char type='%d'\n", $$->type);
	| DOUBLE			{ $$ = typeset(2) ; }	
	| VOLATILE			{ $$ = typeset(1) ; }
	| SIGNED INTEGER	{ $$ = typeset(1) ; }
	| UNSIGNED INTEGER	{ $$ = typeset(4) ; }
	| SIGNED SHORT		{ $$ = typeset(5) ; }
	| SIGNED LONG		{ $$ = typeset(6) ; }
	| UNSIGNED SHORT	{ $$ = typeset(7) ; }
	| UNSIGNED LONG		{ $$ = typeset(8) ; }
	| LONG				{ $$ = typeset(6) ; }
	| SHORT				{ $$ = typeset(5) ; }
	| BOOLEAN			{ $$ = typeset(1) ; }
	| CONST INTEGER		{ $$ = typeset(1) ; }
	| CONST FLOAT		{ $$ = typeset(2) ; }
	| CONST CHARACTER	{ $$ = typeset(3) ; }
	| VOID				{ $$ = typeset(0) ; }
	| STRUCT IDENTIFIER	{
						int a=lookup_struct($2); 
						if(!a)
							printf("error\n");
							else {
								$$ = typeset(a);
							 	 }
						}
	|ENUM IDENTIFIER  {
						$$=id($2);
						if($$->type!=12) printf("undefined enum reference to %s at line %d\n",$2,linenum);
					  }
	;

NUM:	SIGN_SHORT		{$$=scon($1);	}										//printf("val=%d\n",$1);  }
	|UNSIGN_SHORT		{$$=u_scon($1); }
      |SIGN_LONG		{$$=lcon($1);   }
	|UNSIGN_LONG		{$$=u_lcon($1); }
      |SIGN_INT			{$$=con($1);    }
	|UNSIGN_INT			{$$=u_con($1);  }
	|FLOAT_DATA			{$$=fcon($1);   }
	;

Declaration1: TYPE Assignment SEMICOLON {
																				//printf("id_declarator dtype=%d %s\n",$2->datatype,$2->name);
										if($2->datatype!=9)
										{
										yyerror("Illegal identifier used at line");check=1;
										}
										$$  = (nodeType*)malloc(sizeof(nodeType));
										$$->code = (Code*)malloc(sizeof(Code));
		  								$$->type=$1->type;
										$$->place=$2->place;										
										$$->code = append($$->code, $2->code);
										}										//printf("declaration '%d' \n", linenum);		
	| Assignment SEMICOLON				{$$=$1;}
	//| Expr SEMICOLON				{$$=$1;}
	| Function_Call SEMICOLON 			{$$=$1;}
	| Struct_State SEMICOLON			{ $$  = (nodeType*)malloc(sizeof(nodeType)); //printf("F_start2\n");
							 			  $$->code = (Code*) malloc(sizeof(Code));
							 			  $$->code = append($$->code,$1->code);  /* printf("reading a line complete\n");*/	
										}
 	| Enum_State SEMICOLON				{ $$  = (nodeType*)malloc(sizeof(nodeType)); //printf("F_start2\n");
							 			  $$->code = (Code*) malloc(sizeof(Code));
							 			  $$->code = append($$->code,$1->code);  /* printf("reading a line complete\n");*/	
										}
	;
	
id_declarator: IDENTIFIER		{												 //printf("after $1 = %s \n",$1);	
									
								if($<ptr>0 !=NULL)
								 {	
								 												 // printf("inside $1 = %s \n",$1);	
								 												 // printf("%d in %s\n", $<ptr>0->type,$1);
								 												 // printf("after $1 = %s \n",$1);	
								 	 if($<ptr>0->datatype==1)
									 {  
									 $$= id_handler($1,$<ptr>0->type);
									 } 
									 else 
								 	 {
								 	 $$= id($1);
								 	 }
								}
								}
								;
marker:		{																	 //printf("Hello marker\n");
			$$=(nodeType*)malloc(sizeof(nodeType));
			$$->datatype=0;
			$$->type=11;
			}
			;						
type_marker
	:									{	
										if($<ptr>-2==NULL)
										{
										$$=(nodeType*)malloc(sizeof(nodeType));
										$$->datatype=0;
																				 //printf("NULL creating %d\n", $$->datatype);
										}
										else if($<ptr>-2->datatype==1)
										{
																				 //	printf("inside the loop\n");
										 	$$ = typeset($<ptr>-2->type);
										}
																				 // printf("yo i'm done in marker!\n");
										}										 //{ $$->datatype = $-1->datatype ;}
	;
	
/* Assignment block */
Assignment:	Assignment EQUALTO Assignment 
								{												//printf("t1=%d .. t2=%d\n",$1->type,$3->type);		//	iscomp(1,2);
																				//	if($1!=NULL && iscompatible($1->type,$3->type))
								$$  = (nodeType*)malloc(sizeof(nodeType));  
								$$->code = (Code*)malloc(sizeof(Code));
		  						$$->code = append($$->code, $3->code);
		  						$$->datatype=$1->datatype;
		  																		//	printf("Assignment1:t1=%d .. t2=%d\n",$1->type,$3->type);
		  						if ($1!=NULL && !iscompatible($1->type,$3->type))
								{
																				//printf("Assignment:t1=%d .. t2=%d\n",$1->type,$3->type);
								yyerror("Incompatible datatypes");check=1;
								}
		  						else if(($1->type==1 ||($1->type>=4 && $1->type<=8)) && ($3->type==1 ||($3->type>=4 && $3->type<=8))) 
										{
										GenCODEnode_node(assigni, symSearch($1->name), $3->place, $$->code);
																				//	printf("a1\n");
										}	
										else if (($1->type==2) && ($3->type==2))
										{ 
										GenCODEnode_node(assignf, symSearch($1->name), $3->place, $$->code);
																				//printf("a2\n");
										}	
										else if(($1->type==2) && ($3->type==1 ||($3->type>=4 && $3->type<=8)))
										{ 
										Node *temp_node;
										temp_node = malloc(sizeof(Node ));
										temp_node->type = 2;
										GenCODEnode_node(int_to_float, temp_node, $3->place, $$->code);
										GenCODEnode_node(assignf, symSearch($1->name), temp_node, $$->code);
																				//printf("a3\n");
										}		
										else if(($1->type==1 ||($1->type>=4 && $1->type<=8)) && $3->type==2)
										{
											yyerror("Incompatible datatypes");check=1;					
										}
								}
	| Assignment EQUALTO Function_Call{												//printf("t1=%d .. t2=%d\n",$1->type,$3->type); iscomp(1,2);
								$$  = (nodeType*)malloc(sizeof(nodeType));  
								$$->code = (Code*)malloc(sizeof(Code));
		  						$$->code = append($$->code, $3->code);
		  						if(($1->type==1 ||($1->type>=4 && $1->type<=8)) && ($3->type==1 ||($3->type>=4 && $3->type<=8))) 
										{
										GenCODEnode_node(assigni, symSearch($1->name), $3->place, $$->code);
										}	
										else if (($1->type==2) && ($3->type==2))
										{ 
										GenCODEnode_node(assignf, symSearch($1->name), $3->place, $$->code);
										}	
										else if(($1->type==2) && ($3->type==1 ||($3->type>=4 && $3->type<=8)))
										{ 
										Node *temp_node;
										temp_node = malloc(sizeof(Node ));
										temp_node->type = 2;
										GenCODEnode_node(int_to_float, temp_node, $3->place, $$->code);
										GenCODEnode_node(assignf, symSearch($1->name), temp_node, $$->code);
										}
								else if ($1!=NULL && (!iscompatible($1->type,$3->type)))
								{													 //		printf("t1=%d .. t2=%d\n",$1->type,$3->ret);
								yyerror("Incompatible datatypes");check=1;
								}
								}
								
	| NUM						{$$=$1;	 	}										//printf("num type= %d\n",$1->type);}
	| id_declarator 			{$$=$1; 	 printf("id_declarator dtype1=%d dtype2=%d name!:%s name2:%s\n",$$->datatype,$1->datatype,$$->name,$1->name);}
	| Assignment COMMA type_marker Assignment { $$  = (nodeType*)malloc(sizeof(nodeType));  
												$$->code = (Code*)malloc(sizeof(Code));
												$$->type=$4->type;
												$$->place=$4->place;
												$$->code = append($$->code, $1->code);
												$$->code = append($$->code, $4->code);
												if($1->datatype==$4->datatype)
												{
												$$->datatype=$1->datatype;
												}
												else $$->datatype=0;
																					//printf("Assignment COMMA type_marker Assignment\n");
												}
	| Assignment PLUS marker Assignment		  {	$$ = perform_arithmetic(plus,$1,$4,0);		       }	//printf("t1=%d\t plus t2=%d\n",$1->type,$4->type);}
	| Assignment MINUS marker Assignment	  { $$ = perform_arithmetic(minus,$1,$4,0);		       }	//printf("MINUS\n");
	| Assignment ASTERISK marker Assignment	  { $$ = perform_arithmetic(asterisk,$1,$4,0);		   }
	| Assignment DIV marker Assignment		  { $$ = perform_arithmetic(divi,$1,$4,0);		   	   }
	| Assignment MOD marker Assignment		  { $$ = perform_arithmetic(mod,$1,$4,0);		  	   }
	| Assignment INCR						  {	perform_unary(incr,$1); }								 //printf("Incr,type='%s'\n",$1->type);}	
	| Assignment DECR						  {	perform_unary(decr,$1); }								 //printf("Decr,type='%s'\n",$1->type);}					
	| INCR Assignment %prec PINCR			  { perform_unary(incr,$2); } 								 //Error recovery unknown as of now
	| DECR Assignment %prec PDECR			  { perform_unary(decr,$2); }								 //Error recovery unknown as of now
	| Assignment BINARYONESCOMPLEMENT Assignment { $$=perform_binary(binaryonescomplement,$1,$3,0);}
	| Assignment BINARYAND Assignment			{ $$=perform_binary(binaryand,$1,$3,0);}
	| Assignment BINARYOR Assignment			{ $$=perform_binary(binaryor,$1,$3,0);}
	| Assignment BINARYXOR Assignment			{ $$=perform_binary(binaryxor,$1,$3,0);}
	| Assignment LSHIFT Assignment				{ $$=perform_binary(lshift,$1,$3,0);}
	| Assignment RSHIFT Assignment				{ $$=perform_binary(rshift,$1,$3,0);}
	| PARENOPEN Assignment PARENCLOSE   	 {$$=$2;}  													  //=>Error recovery(giving segmentation fault) 	
	| MINUS Assignment %prec UMINUS			 { 	$$ = (nodeType*)malloc(sizeof(nodeType)); 
												$$->place = $2->place;									  ///?????
												if($$->code==NULL){
									    				$$->code = (Code*)malloc(sizeof(Code));
																  }															   	
												if($2->type==1||($2->type>=4 && $2->type<=8))
												{
												$$->type = 1;
												GenCODEnode(uminus,$2->place, $2->code);
												$$->code = append($$->code,$2->code);
												}
												else if($2->type==2)
												{
												$$->type = 2;
												GenCODEnode(uminus,$2->place, $2->code);
												$$->code = append($$->code,$2->code);
												}
												else
																									//printf("type error at %d\n",line_no);
													yyerror("type error");
													check=1;
													}											
	| PLUS Assignment %prec UPLUS			{$$=$2;}	
	//|Expr	
	;
	
/*Expression Block*/
Expr:	PARENOPEN Expr PARENCLOSE
	| Expr LEQ Expr			{ $$ = perform_boolean(leq,$1,$3);		}
	| Expr GEQ Expr			{ $$ = perform_boolean(geq,$1,$3);		}
	| Expr GREAT Expr		{ $$ = perform_boolean(great,$1,$3);		}
	| Expr LESST Expr		{ $$ = perform_boolean(lesst,$1,$3);	}						//{ printf(" %d lesst %d \n",$1->type,$3->type);}	}
	| Expr NOTEQ Expr		{ $$ = perform_boolean(noteq,$1,$3);		}
	| Expr IFEQUAL Expr		{ $$ = perform_boolean(ifequal,$1,$3);	}						// printf(" if equal \n");	}
	| Expr NOTEQ1 Expr		{ $$ = perform_boolean(noteq,$1,$3);		}
//	| Expr EQUALTO Expr																		//Check
//	| Expr COMMA Expr
	| Expr OR Expr			{ $$ = perform_logical(or,$1,$3);		}
	| Expr AND Expr			{ $$ = perform_logical(and,$1,$3);		}
	| Expr PLUSEQ Expr		{ $$ = perform_arithmetic(plus,$1,$3,1);}
	| Expr MINUSEQ Expr		{ $$ = perform_arithmetic(minus,$1,$3,1);}
	| Expr DIVEQ Expr		{ $$ = perform_arithmetic(divi,$1,$3,1);}
	| Expr MULEQ Expr		{ $$ = perform_arithmetic(asterisk,$1,$3,1);}
	| Expr LSHIFTEQ Expr
	| Expr RSHIFTEQ Expr
	| Expr BITANDEQ Expr
	| Expr BITOREQ Expr
	| Expr BITXOREQ Expr
	| Expr MODEQ Expr
	| NOT Expr %prec UMINUS { 
									$$ = (nodeType*)malloc(sizeof(nodeType));
									$$->code = (Code*)malloc(sizeof(Code)); 
									$$->place = $2->place;				
									Node * tmp=(Node*)malloc(sizeof(Node));
									tmp->stackOffset=getOffset();
									incOffset(4);
									
									if($2->type==1){
									$$->type = $2->type;
									
									$$->code = append($$->code,$2->code);
									GenCODEnode_node(not,tmp,$2->place, $$->code);$$->place=tmp;
									}
									else{
																							//printf("type error at %d\n",linenum);
									yyerror("type error");
									check=1;
									}		
							}
	| BINARYONESCOMPLEMENT Expr {$$=$2;}
	| Assignment				{$$=$1; }												//printf("reducing Ass. to expr line='%d',type=%d \n",linenum,$1->type);	} 
	|							{$$ = (nodeType*)malloc(sizeof(nodeType));
								 $$->code = (Code*)malloc(sizeof(Code));}
	;

Expr_Loop:Expr_Loop COMMA Expr					{ 										//printf("expr_loop\n");
										$$ = (nodeType*)malloc(sizeof(nodeType));$$->code = (Code*)malloc(sizeof(Code));
										List* var = (List*)malloc(sizeof(List));
										var->first=$3->type;
										var->head=$3->place;
										var->next=NULL;
										$3->parameters=var;
																						//	print_List($1->parameters);
										$$->parameters=appendLists($1->parameters,$3->parameters);
										$$->code = append($$->code,$1->code);
										$$->code = append($$->code,$3->code);
																						//	printf("Expr_loop comma expr\n");
												}
		|Expr									{ $$ = (nodeType*)malloc(sizeof(nodeType)); printf("Hii, Expr\n");
									    		  $$->code = (Code*)malloc(sizeof(Code));
												  List* var = (List*)malloc(sizeof(List));
												  if($1!=NULL)
												  {
												  var->first=$1->type;
																						//  printf("expr type = %d\n",$1->type);
												  var->head=$1->place;
												  var->next=NULL;
												  $1->parameters=var;
												  $$->parameters = $1->parameters;
												  $$->code = append($$->code,$1->code); 
												  }
												}
	;

Function_Call :  IDENTIFIER PARENOPEN Expr_Loop PARENCLOSE{  							//printf("hello function '%s'\n", $1);
														$$=id($1); 						//printf("hello function '%s'\n", $1);
																						//printf("off=%d",symSearch($3->parameters->head)->stackOffset);
														if(symSearch($1)!=NULL)
														{
																						//$$->ret=symSearch($1)->ret;
														$$->type =symSearch($1)->ret;
														if (symSearch($1)->parameters!=NULL && ($3==NULL || $3->parameters==NULL))
														{
																						//printf("function0: '%s' unmatched arguments at %d\n",$1,linenum);
														yyerror("unmatched arguments");
														check=1;
														}
														if(symSearch($1)->parameters==NULL && $3!=NULL)
														{
																						//errorbit=1;
																						//printf("function1: '%s' unmatched arguments at %d\n",$1,linenum);
														yyerror("unmatched arguments");
														check=1;
														}
														else if (symSearch($1)->type!=10) 
														{
																						//printf("error:'%s' is not a fuction at %d\n",$1,linenum);
														yyerror("Undefined function name");
														check=1;
														}
														else $$->type=symSearch($1)->ret;				//printf("hello function1 '%s'\n", $1);

														int sum=0;
														ListNodes *t1 = malloc(sizeof(ListNodes));
														List *t2 = malloc(sizeof(List));
														Node *tm = malloc(sizeof(Node));
														t1=symSearch($1)->parameters;
														t2=$3->parameters;
														
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
											if ($$->type ==1){
											
											tm->stackOffset = getOffset();
											incOffset(4);
											tm->type = 1;
											}
											else if ($$->type ==2){
											
											tm->stackOffset = getOffset();
											incOffset(8);
											tm->type = 2;}
											else if ($$->type ==3){
								
											tm->stackOffset = getOffset();
											incOffset(4);
											tm->type = 3;}
											else if ($$->type ==0){
								
											tm->stackOffset = getOffset();
											incOffset(4);
											tm->type = 0;}
											else {
											tm->stackOffset = getOffset();
											incOffset(4);
											tm->type = 11;
											}
										    $$->code = append($$->code,$3->code);
									        t2=$3->parameters;
											sum=0;int m;
										if(symSearch($1)->ret==1)m=4;	
										else if(symSearch($1)->ret==2)m=8;
										else if(symSearch($1)->ret==3)m=1;
										else if(symSearch($1)->ret==0)m=0;
										else m=4; 
										GenCODEstring_int(func1, $1, 500, $$->code);						
						      		   	int num = 1;
						      		  	sprintf(func_name,$1);
										    while(t2 != NULL){
							                 		if(t2->first == 1 || t2->first >=4 && t2->first <=8)
							                		 {
																	 //printf("offset------------->%d\nname------------->%s\n",t2->head->stackOffset, $1);
							                		 GenCODEnode_int_int(int_param, t2->head, symSearch($1)->stackOffset+m , sum, $$->code);
							                		 printf("offset=%d\n",symSearch($1)->stackOffset+m);
							                		 sum=sum+4;
							                		 }
											 else if(t2->first == 2)
											 		{
											 		GenCODEnode_int_int(float_param, t2->head, symSearch($1)->stackOffset+m, sum, $$->code);
											 		sum=sum+8;
											 		}
											 else if(t2->first == 3)
											 		{
											 		GenCODEnode_int_int(char_param, t2->head, symSearch($1)->stackOffset+m, sum, $$->code);
											 		sum=sum+1;
											 		}
											 else {
											 		GenCODEnode_int_int(int_param, t2->head, symSearch($1)->stackOffset+m, sum, $$->code);
											 		sum=sum+4;
											 		}				//500 is redundant....create GenCODEstring
											 num++;
											 t2 = t2->next;}									 
										   GenCODEstring_int(func2, $1, 500, $$->code);			//500 is redundant....create GenCODEstring
										   GenCODEnode_int(ret_val, tm, 500, $$->code); 		//500 is redundant....create GenCODEstring
										   $$->place = tm;
																
											}
														}
													 }
	;

/* Loop Blocks */ 
While_State:WHILE PARENOPEN marker Expr PARENCLOSE Compound_State { 							//printf("while\n");
																	$$ = handle_while(whilesym,$4,$6);	
																  }
	;

Do_While_State: DO Compound_State WHILE PARENOPEN marker Expr PARENCLOSE { $$ = handle_while(whilesym,$6,$2);	}
		;

/* For Block */
For_State:FOR PARENOPEN marker Expr SEMICOLON marker Expr_Loop SEMICOLON marker Expr_Loop PARENCLOSE Compound_State {$$ = handle_for(forloop,$4,$7,$10,$12); }
	;

/* Case State*/
Case_State: CASE CONST COLON State_List
	   ;
Case_List:  Case_List Case_State
	    |Case_State
	     ;			
Case_Compd: BRACEOPEN Case_List BRACECLOSE
	;
/* Switch Statement*/

Switch_State: SWITCH PARENOPEN Expr PARENCLOSE Case_Compd /*{ $$ =  (nodeType*)malloc(sizeof(nodeType));
								 							$$->code = (Code*)malloc(sizeof(Code));
								 						  }*/
	;

/*Assignment List*/

Assign_List: Assign_List TYPE id_declarator SEMICOLON
	     |
	;
	
/* Struct Statement */

Struct_State : STRUCT IDENTIFIER BRACEOPEN {										//printf("struct %d\n",lookup_struct($2));
											if(lookup_struct($2)) 
												printf("error: struct declaration already exists at line %d\n",linenum); 
											else {

												int sequence = insert_str($2);
												OpenScope(0);
																					//	printf("s2 %d--\n",sequence);	
												insert_str_arg(sequence, currentSymTable);
											}
											 }
				Assign_List BRACECLOSE {CloseScope(0);}
			; 
			/*
Extra:IDENTIFIER	{		printf("struct %d\n",lookup_struct($2));
							if(lookup_struct($2)) 
								printf("error: struct declaration already exists at line %d\n",linenum); 
							else {
									//int sequence = insert_str($2);
									int seq=lookup_struct($<ptr>-6);
								//	printf("s2 %d--\n",sequence);	
									insert_str_arg(sequence, currentSymTable);
								}
				   }
	|
	;
*/
/* Enum Statement*/
Enum_State: ENUM BRACEOPEN {enum_number=0;} enumerator_list BRACECLOSE {$$=$4;}
	| ENUM IDENTIFIER {$<ptr>$=id_handler($2,12);}BRACEOPEN {enum_number=0;} enumerator_list BRACECLOSE	{$$=$6;}		
	| ENUM IDENTIFIER {
						$$=id_handler($2,13);
						symSearch($2)->is_enum=1;
						symSearch($2)->enum_val=0;
			   		  }
	;

enumerator_list
	: enumerator {$$=$1;}
	| enumerator_list COMMA enumerator { $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);			//=> Check why? it is giving segmentation fault???
								  $$->code=append($$->code,$3->code);
					    }
	;

enumerator
	: IDENTIFIER{
						$$=id_handler($1,1);
						symSearch($1)->enum_val=enum_number;
						symSearch($1)->is_enum=1;
						enum_number++;
			    }
	| IDENTIFIER EQUALTO NUM{
						$$=id_handler($1,1);
						if($3->type=1 || ($3->type>=4 && $3->type<=8))
						{
						symSearch($1)->enum_val=enum_number;
						symSearch($1)->is_enum=1;
						//enum_number+=$3;
			   			}
			   			else
			   			{
			   			printf("Line %d: Enumeration requires constant expression\n",linenum);
						printf("Line %d: cannot convert from %s type to const int type\n",linenum,$3->type);
						}
						}
	;

/* Print Function */
Print_Funct : PRINTF PARENOPEN STRINGLITERAL PARENCLOSE SEMICOLON { 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								 											  $$->code = (Code*)malloc(sizeof(Code));
								 											 // printf("passing string: %s\n",$3);
								 											  topGenCODEstring(printshdr,$3, $$->code);
								 											  GenCODEstringprint(prints,strno,$$->code);
								 											//  $$->code=append($$->code,$1->code);	//=> Check why? it is giving segmentation fault???
					    }	
			|PRINTF PARENOPEN argt COMMA marker id_declarator PARENCLOSE SEMICOLON
			{	
					//printf("%s\t%d\n",$6->name,$6->type);
					$$ = (nodeType*)malloc(sizeof(nodeType));	
					if($$->code==NULL){
					$$->code = (Code*)malloc(sizeof(Code));
					}	
					if($3->type==1 && (($6->type==1) || ($6->type>=4 && $6->type<=8)))
					{
					//$$->type = 1;
					GenCODEnode(printi,$6->place, $$->code);
					//$$->code = append($$->code,$2->code);
					}
					else if($3->type==2 && $6->type==2)
					{
					//$$->type = 2;
					GenCODEnode(printff,$6->place, $$->code);
					//$$->code = append($$->code,$$->code);
					}
					else
					{
					//printf("type error at %d\n",line_no);
					yyerror("type error");
					check=1;
					}
					}
	;
argt: PD			{ $$ =  (nodeType*)malloc(sizeof(nodeType)); $$->type=1;}
	| PF			{ $$ =  (nodeType*)malloc(sizeof(nodeType)); $$->type=2;}
	;
State:	While_State 	{ 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);			//=> Check why? it is giving segmentation fault???
					    }														//{ printf("While_State  \n");}
	| Declaration1		{ 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);			//=> Check why? it is giving segmentation fault???
					    }														//{ printf("Declaration1  \n");}
	| For_State 		{ 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);			//=> Check why? it is giving segmentation fault???
					    }
	| Switch_State 		{ 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
																				//  $$->code=append($$->code,$1->code);			
																				//=> Check why? it is giving segmentation fault???
					    }
	| Print_Funct 		{ 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);			//=> Check why? it is giving segmentation fault???
					    }														//{ printf("printf  \n");}
	| Do_While_State SEMICOLON  		{ $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);			//=> Check why? it is giving segmentation fault???
					   					} 
	| CONTINUE SEMICOLON			{ $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
																				//  $$->code=append($$->code,$1->code);			
																				//=> Check why? it is giving segmentation fault???
					   					} 
	| RETURN Expr SEMICOLON			{ $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$2->code);			//=> Check why? it is giving segmentation fault???
					   					} 
	;

Compound_State:	BRACEOPEN {
							OpenScope(0);										//printf("hello3 compound\n");
						  } State_List BRACECLOSE	{ CloseScope(0); $$=$3;	}	// printf("BRACEOPEN State_List BRACECLOSE \n");}
	;

State_List: State_List Stmt 	{ $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);
  								  $$->code=append($$->code,$2->code);  			//=> Check why? it is giving segmentation fault???
																				//  printf("State_List Stmt  \n");
								 }
	|							{ $$ =  (nodeType*)malloc(sizeof(nodeType));	// printf("blank reduce\n");
								  $$->code = (Code*)malloc(sizeof(Code));	
								}
	;
		;
Stmt:	IF PARENOPEN marker Expr PARENCLOSE {OpenScope(0);} Compound_State ELSE_OPTIONAL {						//printf("hello1 compound\n");
																							CloseScope(0);
																 							 if($7==NULL){$$ = handle_if(ifsym,$4,$7,NULL);	}
															     							 else {$$ = handle_if(ifsym,$4,$7,$8);	}
															   						
																  						 }	
	|State				{ 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);											//{ printf("State\n");}
								  																				//=> Check why? it is giving segmentation fault???
						}
	|Compound_State		{ 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								  $$->code = (Code*)malloc(sizeof(Code));
								  $$->code=append($$->code,$1->code);
																												//  { printf("Compound_State	 \n");}			
																												//=> Check why? it is giving segmentation fault???
					    }
	/*|IF PARENOPEN marker Expr PARENCLOSE error{
	/* now we cannot parse further *
	 // printf("Extra * symbol inserted....at Line %d: \n", linenum);
	  yyerror("{ statements; } missing ");
	  yyclearin;
	  yyerrok;
	}*/
	;
ELSE_OPTIONAL:ELSE Stmt  {
									$$=$2;																		//{ printf("Inside else \n");}
								   }
	| 								{ 		  $$ =  (nodeType*)malloc(sizeof(nodeType));
								  			  $$->code = (Code*)malloc(sizeof(Code));
								    }
	;

%%

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




