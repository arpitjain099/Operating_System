#include <stdlib.h>
#include "string.h"
#include "stdio.h"


struct SymbolTable{
	Node* symArray;			//enteries of symbol table stored in linked list.
	int scope;
	struct SymbolTable* parent;		//helps us to maintain scope information later
	struct SymbolTable* sub_parent;
	int count;			//number of enteries in symbol table
	int offset;
};

struct SymbolTable* globalScopeSymTable;
struct SymbolTable* currentSymTable;

/*-----------------------------------*/

struct str_arg {
	char* arg_name;
	int type_value;
	struct str_arg *next;
};

typedef struct strtype {
	char* name;
	struct SymbolTable* arglist;
	struct strtype* nextstr;
} strtype;

struct strtype *head_str;

int lookup_struct (char* declr) {
	struct strtype *p = head_str;	
	int count = 1;
	if(p==NULL)	return 0;
	while(p!=NULL){
		//printf("%s--\n",p->name);
		if (!strcmp(p->name,declr)) {
			return count+12;
		}
		else {
			p = p->nextstr; 
			count++;
		}
	}
	return 0;
}

int isvalid_strarg(int type, char* arg) {
	int count=type-12;
	struct strtype *p = head_str;
	int i;
	for(i=1; i<count; i++)
		p=p->nextstr;
	struct SymbolTable* q = p->arglist;
	Node *tm = malloc(sizeof(Node));
	tm=q->symArray;
	do{
		if (!strcmp(tm->name,arg)) {
			return tm->type;
		}
		else {
			tm=tm->next;
		}
	}while(tm != NULL);
	printf("error: reference to undefined object");	

}

int insert_str(char* strname){
	struct strtype *p = head_str;
	struct strtype *new = (struct strtype *)malloc(sizeof(struct strtype));
//	printf("\n----3----\n");
	int count = 1;
	if(p!=NULL)
	{
	while(p->nextstr != NULL) {
		p = p->nextstr;
		count++;
	}
	p->nextstr=new;
	}
	else head_str=new;
	new->name = (char*)malloc(sizeof(char));
	new->nextstr = (struct strtype*)malloc(sizeof(struct strtype));	
	new->arglist = (struct SymbolTable*) malloc(sizeof(struct SymbolTable));
	strcpy(new->name,strname);
	new->nextstr=NULL;
		//	printf("%s--\n",strname);	
	//printf("zdc%s--\n",head_str->name);
	return 12+count;
}

void insert_str_arg(int type, struct SymbolTable* symtab){
	int count=type-12;
	struct strtype *p;
//	printf("\n----1----\n");
	p = head_str;
//	printf("zdc%d %s--\n",type,p->name);
	int i;
	for(i=1; i<count-1; i++)
		p=p->nextstr;
	//p->nextstr = (struct strtype*)malloc(sizeof(struct strtype));	
	//p=p->nextstr;	
//	printf("%d %s--\n",type,p->name);	
	p->arglist=symtab;
}

/*-----------------------------------*/

Node* symSearch(char*);
Node* tableSearch(char*,struct SymbolTable*);
Node* getNewBasicSymbol(int,char*);

int getOffset(){
	if(currentSymTable)
		return currentSymTable->offset;
}	//returns offset of current symbol table.

void incOffset(int i){
	currentSymTable->offset+=i;
	//printf("Now offset is: %d\n",currentSymTable->offset);
}	//increases offset by i

void initializeSymTable(){
	//int i;
	globalScopeSymTable = (struct SymbolTable*) malloc(sizeof(struct SymbolTable));
	globalScopeSymTable->symArray = (Node*)malloc(sizeof(Node));	
	globalScopeSymTable->offset=0;
	globalScopeSymTable->parent=NULL;
	globalScopeSymTable->count=0;
	globalScopeSymTable->scope=0;
	currentSymTable = globalScopeSymTable;
	//printf("\n----1----\n");
	head_str = (struct strtype*) malloc(sizeof(struct strtype));
	//head_str->arglist = (nodeType*)malloc(sizeof(nodeType));   //$$ = (nodeType*)malloc(sizeof(nodeType));
	head_str=NULL;
}

void OpenScope(int mode){
	struct SymbolTable* oldSymTable=currentSymTable;
	int i;
	currentSymTable = (struct SymbolTable*) malloc(sizeof(struct SymbolTable));
	currentSymTable->symArray = (Node*)malloc(sizeof(Node));	
	if(mode==0){
		currentSymTable->scope=oldSymTable->scope+1;
		currentSymTable->parent=oldSymTable;		//mode=0 new symbol table child of previous symbol table
	}
	else if(mode==1){
		currentSymTable->scope=1;
		currentSymTable->parent=globalScopeSymTable;	//mode=1 new symbol table child of global symbol table
		currentSymTable->sub_parent=oldSymTable;
	}
	else{
		currentSymTable->parent=NULL;
		currentSymTable->sub_parent=oldSymTable;
	}
	currentSymTable->offset=oldSymTable->offset;	        
	currentSymTable->count=0;
}

void CloseScope(int mode){
	int i=currentSymTable->offset;
	if(mode){
	currentSymTable = currentSymTable->sub_parent;
	currentSymTable->offset=i;
	}
	else{
		if(currentSymTable->parent){
			currentSymTable = currentSymTable->parent;
			currentSymTable->offset=i;
		}
	}	
}

Node* symSearch(char* name){
	struct SymbolTable* currentTable = currentSymTable;
	Node* result = NULL;
	while(currentTable){
		result = tableSearch(name,currentTable);
		if(result) return result;
		currentTable=currentTable->parent;
	}
	return NULL;;
}	//searches for a token in symbol table.


Node* tableSearch(char* name, struct SymbolTable* currentTable){
	int i,count;
	Node *tmp=currentTable->symArray;
	while(tmp!=NULL){ 
		if(tmp->name!=NULL)
			if(!strcmp(tmp->name,name))
				return tmp;
			tmp=tmp->next;
	}
	return NULL;
}

Node* getNewBasicSymbol(int type,char* name){
	int count = currentSymTable->count;
	currentSymTable->count++;	
	if(count<99){

		Node *tmp=currentSymTable->symArray;
		if(currentSymTable->symArray==NULL)
		{
			globalScopeSymTable->symArray = (Node*)malloc(sizeof(Node));
			currentSymTable->symArray->name=(char*)malloc(sizeof(char));
			strcpy(currentSymTable->symArray->name,name);
			currentSymTable->symArray->type=type;
			currentSymTable->symArray->next=NULL;
			return tmp;
		}
		while(tmp->next!=NULL){tmp=tmp->next;}
		tmp->next=(Node*)malloc(sizeof(Node));	
		tmp->next->name=(char*)malloc(sizeof(char));
		strcpy(tmp->next->name,name);
		tmp->next->type=type;
		tmp->next->next=NULL;
		return (tmp->next);
	}
	else
		return NULL;
}

void printTable(){
       int i,count = currentSymTable->count;
       printf("\nPrinting the symbol list in the sym-table ! \n----------------------------------------------\n");
	   Node *tmp=currentSymTable->symArray;
       if(count){
       	while(tmp->next!=NULL)
       	{
       	printf("name->%s ; type->%d ; count='%d'\n", tmp->next->name,tmp->next->type,count--);
       	tmp=tmp->next;
       	}
        printf("The current symbol table isnt empty\n"); 
       }
       else printf("The current symbol table is empty\n");
       printf("\n");
}

/*--------------- Data Structures and functions for handling Structures-------------------*/

