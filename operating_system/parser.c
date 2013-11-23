typedef enum { 
	typefCon,
	typeCon,
	typesCon,
	typelCon,
	typeuCon,
	typeusCon,
	typeulCon,
	typeStr,
	typeId,
	typeOpr,
} nodeEnum;

/*nodes for constants*/
typedef struct {
	int value;
}intNodeType;

typedef struct {
	float value;
}floatNodeType;

typedef struct {
	char value;
}charNodeType;

typedef struct {
	long value;
}longNodeType;

typedef struct {
	short value;
}shortNodeType;

typedef struct {
	unsigned int value;
}u_intNodeType;

typedef struct {
	unsigned long value;
}u_longNodeType;

typedef struct {
	unsigned short value;
}u_shortNodeType;

typedef struct
{	
	char value; 		/* value of string */
} strNodeType;

/* identifiers */
typedef struct 
{
	char* name; 		/* subscript to ident array */
} idNodeType;

struct nodeTypeTag;

typedef struct 
{
	int oper; 		/* operator */
	int nops; 		/* number of operands */
	struct nodeTypeTag** op; /* operands (expandable) */
} oprNodeType;


typedef union
{
	intNodeType int_con; 	/* constants */
	floatNodeType f_con;
	longNodeType l_con;
	shortNodeType s_con;
	u_intNodeType ui_con;
	u_longNodeType ul_con;
	u_shortNodeType us_con;
	idNodeType id; 		/* identifiers */
	oprNodeType opr; 	/* operators */
	strNodeType string;	/* strings */
}NEWnode;


typedef struct _ListNodes{
	int first;
	struct _ListNodes *next;
}ListNodes;

typedef struct _Node
{
	char *name;
	int type;
	int enum_val;
	int is_enum;
	int is_declared;
	int width;
	int stackOffset;
	struct SymbolTable* local_var;
	int ret;
	int acc_type;
	struct _Node * next;
	ListNodes * parameters;
}Node;

enum OPCODE 			//OPcodes we are going to use for intermediate code generation
{
uminus,
incr,
decr,
forloop,
whilesym,
character,
mod,
diveq,
pluseq,
minuseq,
muleq,
equalto,
ifequal,
binaryand,
binaryor,
binaryxor,
lshift,
rshift,
and,
or,
not,
equal,
ifsym,
comma,
binaryonescomplement,
func1,
func2,
jump,
label,
reference_int,
assign_to_ref,
assigni,
printi,
assignf,
printff,
prints,
printshdr,
int_to_float,
int_to_const,
float_to_const,
lesst,
float_lesst,
great,
float_great,
noteq,
float_noteq,
leq,
float_leq,
geq,
float_geq,
compare,
float_compare,
plus,
float_plus,
asterisk,
float_asterisk,
divi,
float_divi,
minus,
float_minus,
ret,
ret_only,
ret_val,
int_param,
float_param,
char_param,
};

union Arg {
	Node *nodeType_arg;
	int ival;
	short sval;
	long lval;
	unsigned int uival;
	unsigned short usval;
	unsigned long ulval;
	float fval;
	char *str;
};

union Target
{
	Node *nodeType_target;
	char *char_target; 				//	LABELS FOR JUMPS	
};

typedef struct _entry
{
  	enum OPCODE opcode;
	union Target target;
	union Arg argumt1;
	union Arg argumt2; 
}entry;

typedef struct _code{
	entry *head;
	struct _code *next;
}Code;

typedef struct List1
{
	int first;
	Node *head;
	struct List1 *next;
}List;

typedef struct nodeTypeTag 
{
	//nodeEnum type; 		/* type of node */
	int datatype;			//now used as type of the node ex:id,function
 	char* name;
	int type;
	int temp;
	int ret;
	
	int position;
	Code *code;
	Node *place;
	
	List *parameters;
	NEWnode *treeNode; 		//Use to store the values of the variables in the symbol table.
} nodeType;

