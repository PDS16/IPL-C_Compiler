%skeleton "lalr1.cc"
%require  "3.0.1"

%defines 
%define api.namespace {IPL}
%define api.parser.class {Parser}


%define parse.trace

%code requires{
	#include "location.hh"
	#include <vector>
	#include <string>
	#include "ast.hpp"
	
	

   	namespace IPL {
      class Scanner;
   	}
	   

  // # ifndef YY_NULLPTR
  // #  if defined __cplusplus && 201103L <= __cplusplus
  // #   define YY_NULLPTR nullptr
  // #  else
  // #   define YY_NULLPTR 0
  // #  endif
  // # endif

}

%printer { std::cerr << $$; } STRING_LITERAL
%printer { std::cerr << $$; } WHILE
%printer { std::cerr << $$; } FOR
%printer { std::cerr << $$; } STRUCT
%printer { std::cerr << $$; } INT
%printer { std::cerr << $$; } FLOAT
%printer { std::cerr << $$; } VOID
%printer { std::cerr << $$; } IF
%printer { std::cerr << $$; } ELSE
%printer { std::cerr << $$; } RETURN
%printer { std::cerr << $$; } INC_OP
%printer { std::cerr << $$; } OR_OP
%printer { std::cerr << $$; } AND_OP
%printer { std::cerr << $$; } PTR_OP
%printer { std::cerr << $$; } EQ_OP
%printer { std::cerr << $$; } NE_OP
%printer { std::cerr << $$; } LE_OP
%printer { std::cerr << $$; } GE_OP
%printer { std::cerr << $$; } INT_CONSTANT
%printer { std::cerr << $$; } FLOAT_CONSTANT
%printer { std::cerr << $$; } IDENTIFIER


%parse-param { Scanner  &scanner  }
%locations
%code{
	#include <string>
	#include <map>
   	#include "symbtab.cpp"
   	#include "scanner.hh"
	#include "ast.hpp"
	#include "print.hh" 

	int line_num = 1;
	extern SymbTab gst;
	extern map<std::string, statement_astnode*> ast;
	LocalSymbTab* curr_st = new LocalSymbTab();
	std::string curr;

	Type global_type("-",0,vector<int>());
	struct SymbolTableRow2 curr_strow("none","var","local",0,0,global_type);
	map<string,vector<SymbolTableRow2>> func_map;
	string curr_trunit;


	string dec_type;
	int dec_size = 0;

	bool isCompatible(Type t1, Type t2){

		string temp1 = t1.type_name;
		for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
		int start = 0;
		if  ( t1.arr_ptr == 1){
			if(t1.sizes.size()==0){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 0;
		}
		else if( t1.arr_ptr == 0 && t1.sizes.size()>=1){
			if(t1.sizes.size()==1){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t1.sizes.size(); i++){
			temp1+= "["+to_string(t1.sizes[i])+"]";
		}

		string temp2 = t2.type_name;
		for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
		start = 0;
		if  ( t2.arr_ptr == 1){
			if(t2.sizes.size()==0){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 0;
		}
		else if( t2.arr_ptr == 0 && t2.sizes.size()>=1){
			if(t2.sizes.size()==1){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t2.sizes.size(); i++){temp2+= "["+to_string(t2.sizes[i])+"]";}

		if(t2.pointer_level == 0 && t2.sizes.size()==0 && t2.arr_ptr==0 && t1.pointer_level == 0 && t1.sizes.size()==0 && t1.arr_ptr==0 ){}
		else{
			if(temp1 == temp2){
				return true;
			}
			else if((t1.type_name == "void" && t1.pointer_level == 1 && t1.sizes.size() == 0) || (t2.type_name == "void" && t2.pointer_level == 1 && t2.sizes.size() == 0))
			{
				return true;
			}
			else{
				return false;
			}
		}
		return false;
	}
	
#undef yylex
#define yylex IPL::Parser::scanner.yylex

}



%define api.value.type variant
%define parse.assert

%start translation_unit



%token <std::string> STRING_LITERAL
%token <std::string> WHILE
%token <std::string> FOR
%token <std::string> STRUCT
%token <std::string> INT
%token <std::string> FLOAT
%token <std::string> VOID
%token <std::string> IF
%token <std::string> ELSE
%token <std::string> RETURN
%token <std::string> INC_OP
%token <std::string> OR_OP
%token <std::string> AND_OP
%token <std::string> PTR_OP
%token <std::string> EQ_OP
%token <std::string> NE_OP
%token <std::string> LE_OP
%token <std::string> GE_OP
%token <std::string> INT_CONSTANT
%token <std::string> FLOAT_CONSTANT
%token <std::string> IDENTIFIER
%token ';' '+' ',' '(' ')' '{' '}' '[' ']' ':' '*' '<' '>' '-' '/' '!' '&' '='

%nterm <int> translation_unit 
%nterm <int> struct_specifier
%nterm <int> function_definition 
%nterm <std::string> type_specifier 
%nterm <std::string> fun_declarator 
%nterm <int> parameter_list 
%nterm <int> parameter_declaration 
%nterm <int> declarator_arr 
%nterm <int> declarator 
%nterm <statement_astnode*> compound_statement 
%nterm <seq_astnode*> statement_list 
%nterm <statement_astnode*> statement 
%nterm <assgnE_astnode*> assignment_expression 
%nterm <statement_astnode*> assignment_statement 
%nterm <proccall_astnode*> procedure_call 
%nterm <exp_astnode*> expression 
%nterm <exp_astnode*> logical_and_expression
%nterm <exp_astnode*> equality_expression 
%nterm <exp_astnode*> relational_expression 
%nterm <exp_astnode*> additive_expression 
%nterm <exp_astnode*> unary_expression 
%nterm <exp_astnode*> multiplicative_expression 
%nterm <exp_astnode*> postfix_expression 
%nterm <exp_astnode*> primary_expression 
%nterm <vector <exp_astnode*> > expression_list 
%nterm <std::string> unary_operator 
%nterm <statement_astnode*> selection_statement
%nterm <statement_astnode*> iteration_statement 
%nterm <int> declaration_list 
%nterm <int> declaration 
%nterm <int> declarator_list 

%%

translation_unit:
	struct_specifier 
	{
		
	}
	;

	| function_definition 
	{
		
	}
	;

	| translation_unit struct_specifier 
	{
		
	}
	;

	| translation_unit function_definition 
	{
		
	}
	;

struct_specifier:
	STRUCT IDENTIFIER '{'
	{
		class LocalSymbTab* local_st = new class LocalSymbTab();
		gst.Entries[$1+" "+$2] = SymbolTableRow($1+" "+$2,"struct","global",0,-1,Type("-",0,vector<int>()),local_st);
		curr_st = local_st;
		curr_trunit = "struct";
		curr = $1+" "+$2;
	}
	declaration_list '}' ';' 
	{
		int total_size =0;
		for (auto i:curr_st->table)
		{
			total_size+= i.size;
		}
		gst.Entries[$1+" "+$2].size = total_size;
	}

	;

function_definition:
	type_specifier fun_declarator compound_statement 
	{
		ast[curr] = $3;
		// std::cout<<curr;
	}
	;

type_specifier:
	VOID 
	{
		dec_type = "void";
		dec_size = 4;	
	}
	;

	| INT 
	{
		dec_type = "int";
		dec_size = 4;	
	}
	;

	| FLOAT 
	{
		dec_type = "float";
		dec_size = 4;	
	}
	;

	| STRUCT IDENTIFIER 
	{
		bool exists = false;
		dec_type = $1 + " " + $2;
		for (const auto &entry : gst.Entries)
		{
			if (entry.second.symname == $1 + " " +$2){
				dec_size = entry.second.size;
				exists = true;
				break;
			}
		}
		if(!exists)
		{
			std::cout<<"Error at line "<<@$.begin.line<<": \""<<$1 + " " + $2<<"\" is not defined";
			exit(1);
		}
	}
	;

fun_declarator:
	IDENTIFIER '(' 
	{
		class LocalSymbTab* local_st = new class LocalSymbTab();
		gst.Entries[$1] = SymbolTableRow($1,"fun","global",0,0,Type(dec_type,0,vector<int>()),local_st);
		curr_st = local_st;
		curr_trunit = "fun";
		curr = $1;
	}
	parameter_list ')' 
	{
		int init_offset = 12;
		deque<SymbolTableRow2> temp;
		while(curr_st->table.size()  != 0)
		{
			SymbolTableRow2 temp_row = curr_st->table.back();
			curr_st->table.pop_back();
			temp_row.offset = init_offset;
			init_offset += temp_row.size;			
			temp.push_back(temp_row);
		}
		curr_st->table = temp;
	}
	
	;

	| IDENTIFIER '('
	{
		class LocalSymbTab* local_st = new class LocalSymbTab();
		gst.Entries[$1] = SymbolTableRow($1,"fun","global",0,0,Type(dec_type,0,vector<int>()),local_st);
		curr_st = local_st;
		curr_trunit = "fun";
		curr = $1;
		func_map[$1] = vector<SymbolTableRow2>();
	}
	')' 
	{}
	
	;

parameter_list:
	parameter_declaration 
	{
		
	}
	;

	| parameter_list ',' parameter_declaration 
	{
		
	}
	;

parameter_declaration:
	type_specifier declarator 
	{
		global_type.type_name = dec_type;
		int multi = 1;
		if ( global_type.pointer_level > 0){
			dec_size = 4;
		}
		for(auto i : global_type.sizes){ multi = multi*i;}
		if (curr_st->table.size() == 0)
		{
			curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","param",dec_size*multi,12,global_type)); //to-be-changed
			func_map[curr].push_back(SymbolTableRow2(curr_strow.symname,"var","param",dec_size*multi,12,global_type));
		}
		else{
			int size_temp = curr_st->table.back().size;
			int offset_temp = curr_st->table.back().offset;

			curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","param",dec_size*multi,offset_temp+size_temp,global_type)); //to-be-changed
			func_map[curr].push_back(SymbolTableRow2(curr_strow.symname,"var","param",dec_size*multi,offset_temp+size_temp,global_type));
		}
		global_type = Type("-",0,vector<int>());
	}
	;

declarator_arr:
	IDENTIFIER 
	{
		curr_strow.symname = $1;
	}
	;

	| declarator_arr '[' INT_CONSTANT ']' 
	{
		global_type.sizes.push_back(atoi($3.c_str()));
	}
	;

declarator:
	declarator_arr 
	{
		
	}
	;

	| '*' declarator 
	{
		global_type.pointer_level++;
	}
	;

compound_statement:
	'{' '}' 
	{
		vector<statement_astnode*> vec;
		$$ = new seq_astnode(vec);
	}
	;

	| '{' statement_list '}' 
	{
		$$ = $2;
	}
	;

	| '{' declaration_list '}'
	{
		vector<statement_astnode*> vec;
		$$ = new seq_astnode(vec);
	}
	;

	| '{' declaration_list statement_list '}' 
	{
		$$ = $3;
	}
	;

statement_list:
	statement 
	{
		vector<statement_astnode*> vec;
		vec.push_back($1);
		$$ = new seq_astnode(vec);
	}
	;

	| statement_list statement 
	{
		$1->vec_nodes.push_back($2);
		$$ = new seq_astnode($1->vec_nodes);
	}
	;

statement:
	';' 
	{
		$$ = new empty_astnode();
	}
	;

	| '{' statement_list '}' 
	{
		$$ = $2;
	}
	;

	| selection_statement 
	{
		$$ = $1;
	}
	;

	| iteration_statement 
	{
		$$ = $1;
	}
	;

	| assignment_statement 
	{
		$$ = $1;
	}
	;

	| procedure_call 
	{
		$$ = $1;
	}
	;

	| RETURN expression ';' 
	{
		
		if(gst.Entries[curr].ret_type.type_name == "float" && $2->type.type_name == "int"){
			op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $2);
			$$ = new return_astnode(unode);
		}
		else if(gst.Entries[curr].ret_type.type_name == "int" && $2->type.type_name == "float"){
			op_unary_astnode* unode = new op_unary_astnode("TO_INT", $2);
			$$ = new return_astnode(unode);
		}
		else if(gst.Entries[curr].ret_type.type_name == $2->type.type_name){

			$$ = new return_astnode($2);
		}
		else {
			std::cout<<"Error at line "<<@$.begin.line<<": Incompatible type \""<<$2->type.type_name<<"\" returned, expected \""<<gst.Entries[curr].ret_type.type_name<<"\"";
			exit(1);
		}
	}
	;

assignment_expression:
	unary_expression '=' expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		bool compatible = true;
		if($1->type.lvalue==false){
			std::cout<<"Error at line "<<@$.begin.line<<": Left operand of assignment should have an lvalue";
			exit(1);
		}
		
		string temp1 = t1.type_name;
		for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
		int start = 0;
		if  ( t1.arr_ptr == 1){
			if(t1.sizes.size()==0){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 0;
		}
		else if( t1.arr_ptr == 0 && t1.sizes.size()>=1){
			if(t1.sizes.size()==1){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t1.sizes.size(); i++){
			temp1+= "["+to_string(t1.sizes[i])+"]";
		}

		string temp2 = t2.type_name;
		for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
		start = 0;
		if  ( t2.arr_ptr == 1){
			if(t2.sizes.size()==0){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 0;
		}
		else if( t2.arr_ptr == 0 && t2.sizes.size()>=1){
			if(t2.sizes.size()==1){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t2.sizes.size(); i++){temp2+= "["+to_string(t2.sizes[i])+"]";}

		if($3->type.pointer_level == 0 && $3->type.sizes.size()==0 && $3->type.arr_ptr==0 && $1->type.pointer_level == 0 && $1->type.sizes.size()==0 && $1->type.arr_ptr==0 )
		{
			if($3->type.type_name == "float" && $1->type.type_name=="int"){
				op_unary_astnode* unode = new op_unary_astnode("TO_INT", $3);
				$$ = new assgnE_astnode($1, unode);
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="int"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3);
				$$ = new assgnE_astnode($1, unode);
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == $3->type.type_name){
				$$ = new assgnE_astnode($1, $3);
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here";
				compatible = false;
			}
		}
		else{
			if(temp1 == temp2){
				if($1->type.pointer_level==0 && $3->type.pointer_level==0 && $1->type.arr_ptr==0 && $3->type.arr_ptr==0)
				{
					compatible = false;
				}
				else{
					$$ = new assgnE_astnode($1, $3);
					$$->type.lvalue = false;
				}
				
			}
			else if(!($3->type.pointer_level == 0 && $3->type.arr_ptr==0)&& $1->type.type_name == "void" && $1->type.pointer_level == 1 && $1->type.sizes.size()==0){
				$$ = new assgnE_astnode($1, $3);
				$$->type.lvalue = false;
			}
			else if(!($1->type.pointer_level == 0 && $1->type.arr_ptr==0) && $3->type.type_name == "void" && $3->type.pointer_level == 1 && $3->type.sizes.size()==0){
				$$ = new assgnE_astnode($1, $3);
				$$->type.lvalue = false;
			}
			else if(!($1->type.pointer_level == 0 && $1->type.arr_ptr==0) && $3->astnode_type==typeExp::intconst_astype && $3->int_val == 0){
				$$ = new assgnE_astnode($1, $3);
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here2";
				compatible = false;
			}

		}
		if(!compatible){
			string temp1 = t1.type_name;
			for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
			for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
			for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
			for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout << "Error at line "<<@$.begin.line<<": Incompatible assignment when assigning to type \""<<temp1<<"\" from type \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

assignment_statement:
	assignment_expression ';' 
	{
		$$ = new assgnS_astnode($1->lhs_astnode, $1->rhs_astnode);
	}
	;

procedure_call:
	IDENTIFIER '(' ')' ';' 
	{
		vector<exp_astnode*> vec = {};
		identifier_astnode* idnode = new identifier_astnode($1);
		// inode->type.lvalue = true;
		$$ = new proccall_astnode(idnode, vec);
		bool exists = false;
		for (const auto &entry : gst.Entries)
		{
			if (entry.second.symname == $1){
				exists = true;
				break;
			}
		}
		string printf = "printf";
		string scanf = "scanf";
		if(!exists)
		{
			
			if(!($1==printf || $1==scanf )){
				std::cout<<"Error at line "<<@$.begin.line<<": \""<<$1<<"\" is not defined";
				exit(1);
			}
		}
		if(!($1==printf || $1==scanf ))
		{
			if(func_map[$1].size() > 0)
			{
				std::cout<<"Error at line: "<<@$.begin.line<<": Procedure \""<<$1<<"\"  called with too many arguments";
				exit(1);
			}
		}
	}
	;

	| IDENTIFIER '(' expression_list ')' ';' 
	{
		identifier_astnode* idnode = new identifier_astnode($1);
		// idnode->type.lvalue=true;
		$$ = new proccall_astnode(idnode, $3);
		bool exists = false;
		for (const auto &entry : gst.Entries)
		{
			if (entry.second.symname == $1){
				exists = true;
				break;
			}
		}
		string printf = "printf";
		string scanf = "scanf";
		if(!exists)
		{
			if(!($1==printf || $1==scanf )){
				std::cout<<"Error at line "<<@$.begin.line<<": \""<<$1<<"\" is not defined";
				exit(1);
			}
		}
		if(!($1==printf || $1==scanf )){

			unsigned int n = $3.size();
			if(func_map[$1].size() < n)
			{
				std::cout<<"Error at line: "<<@$.begin.line<<": Procedure \""<<$1<<"\"  called with too many arguments";
				exit(1);
			}
			if(func_map[$1].size() > n)
			{
				std::cout<<"Error at line "<<@$.begin.line<<": Procedure \""<<$1<<"\"  called with too few arguments";
				exit(1);
			}
			
			for( unsigned int i=0 ;i<n ;i++)
			{
				Type t1 = $3[i]->type;
				Type t2 = func_map[$1][i].ret_type;
				if(t2.pointer_level == 0 && t2.arr_ptr == 0 && t2.sizes.size() == 0 && t1.pointer_level == 0 && t1.arr_ptr == 0 && t1.sizes.size() == 0)
				{
					if ( t1.type_name == t2.type_name)
					{
						
					}
					else if (t1.type_name == "int" && t2.type_name == "float")
					{
						op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3[i]);
						$3[i] = unode;
					}
					else if (t1.type_name == "float" && t2.type_name == "int") 
					{
						op_unary_astnode* unode = new op_unary_astnode("TO_INT", $3[i]);
						$3[i] = unode;
					}
					else
					{
						std::cout<<"Error at line "<<@$.begin.line<<": Expected \""<<t2.type_name<<"\" but argument is of type \""<<t1.type_name<<"\"";
						exit(1);
					}
				}
				else
				{
					if(!isCompatible(t1,t2))
					{
						string temp1 = t1.type_name;
						for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
						if  ( t1.arr_ptr == 1){temp1 += "(*)";}
						for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
						string temp2 = t2.type_name;
						for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
						if  ( t2.arr_ptr == 1){temp2 += "(*)";}
						for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
						std::cout<<"Error at line "<<@$.begin.line<<": Expected \""<<temp2<<"\" but argument is of type \""<<temp1<<"\"";
						exit(1);
					}
					
				}

			}
		}
		$$ = new proccall_astnode(idnode, $3);
	}
	;

expression:
	logical_and_expression 
	{
		$$ = $1;
		$$->type = $1->type;
	}
	;

	| expression OR_OP logical_and_expression 
	{
		if( !($1->type.type_name == "int" || $1->type.type_name == "float" || $1->type.pointer_level > 0 || $1->type.arr_ptr > 0 || $1->type.sizes.size()> 0))
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand of ||,  not scalar or pointer";
			exit(1);
		}
		if( !($3->type.type_name == "int" || $3->type.type_name == "float" || $3->type.pointer_level > 0 || $3->type.arr_ptr > 0 || $3->type.sizes.size()> 0))
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand of ||,  not scalar or pointer";
			exit(1);
		}
		$$ = new op_binary_astnode("OR_OP", $1, $3);
		$$->type = Type("int",0,vector<int>());
		$$->type.lvalue = false;
	}
	;

logical_and_expression:
	equality_expression 
	{
		$$ = $1;
		$$->type = $1->type;
	}
	;

	| logical_and_expression AND_OP equality_expression 
	{
		if( !($1->type.type_name == "int" || $1->type.type_name == "float" || $1->type.pointer_level > 0 || $1->type.arr_ptr > 0 || $1->type.sizes.size()> 0))
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand of &&,  not scalar or pointer";
			exit(1);
		}
		if( !($3->type.type_name == "int" || $3->type.type_name == "float" || $3->type.pointer_level > 0 || $3->type.arr_ptr > 0 || $3->type.sizes.size()> 0))
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand of &&,  not scalar or pointer";
			exit(1);
		}
		$$ = new op_binary_astnode("AND_OP", $1, $3);
		$$->type = Type("int",0,vector<int>());
		$$->type.lvalue = false;
	}
	;


equality_expression:
	relational_expression 
	{
		$$ = $1;
		$$->type = $1->type;
	}
	;

	| equality_expression EQ_OP relational_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		bool compatible = true;

		string temp1 = t1.type_name;
		for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
		int start = 0;
		if  ( t1.arr_ptr == 1){
			if(t1.sizes.size()==0){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 0;
		}
		else if( t1.arr_ptr == 0 && t1.sizes.size()>=1){
			if(t1.sizes.size()==1){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t1.sizes.size(); i++){
			temp1+= "["+to_string(t1.sizes[i])+"]";
		}

		string temp2 = t2.type_name;
		for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
		start = 0;
		if  ( t2.arr_ptr == 1){
			if(t2.sizes.size()==0){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 0;
		}
		else if( t2.arr_ptr == 0 && t2.sizes.size()>=1){
			if(t2.sizes.size()==1){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t2.sizes.size(); i++){temp2+= "["+to_string(t2.sizes[i])+"]";}

		if($3->type.pointer_level == 0 && $3->type.sizes.size()==0 && $3->type.arr_ptr==0 && $1->type.pointer_level == 0 && $1->type.sizes.size()==0 && $1->type.arr_ptr==0 )
		{
			if($1->type.type_name == "int" && $3->type.type_name == "int"){
				$$ = new op_binary_astnode("EQ_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="int"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3);
				$$ = new op_binary_astnode("EQ_OP_FLOAT",$1, unode);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "int" && $3->type.type_name=="float"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
				$$ = new op_binary_astnode("EQ_OP_FLOAT",unode, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="float"){
				$$ = new op_binary_astnode("EQ_OP_FLOAT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here";
				compatible = false;
			}
		}
		else{
			if(temp1 == temp2){
				$$ = new op_binary_astnode("EQ_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if(!($3->type.pointer_level == 0 && $3->type.arr_ptr==0)&& $1->type.type_name == "void" && $1->type.pointer_level == 1 && $1->type.sizes.size()==0){
				$$ = new op_binary_astnode("EQ_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if(!($1->type.pointer_level == 0 && $1->type.arr_ptr==0) && $3->type.type_name == "void" && $3->type.pointer_level == 1 && $3->type.sizes.size()==0){
				$$ = new op_binary_astnode("EQ_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if(!($1->type.pointer_level == 0 && $1->type.arr_ptr==0) && $3->astnode_type==typeExp::intconst_astype && $3->int_val == 0){
				$$ = new op_binary_astnode("EQ_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if(!($3->type.pointer_level == 0 && $3->type.arr_ptr==0) && $1->astnode_type==typeExp::intconst_astype && $1->int_val == 0){
				$$ = new op_binary_astnode("EQ_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here2";
				compatible = false;
			}

		}
		if(!compatible){
			string temp1 = t1.type_name;
			for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
			for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
			for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
			for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout << "Error at line "<<@$.begin.line<<": Invalid operands types for binary ==, \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

	| equality_expression NE_OP relational_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		bool compatible = true;

		string temp1 = t1.type_name;
		for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
		int start = 0;
		if  ( t1.arr_ptr == 1){
			if(t1.sizes.size()==0){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 0;
		}
		else if( t1.arr_ptr == 0 && t1.sizes.size()>=1){
			if(t1.sizes.size()==1){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t1.sizes.size(); i++){
			temp1+= "["+to_string(t1.sizes[i])+"]";
		}

		string temp2 = t2.type_name;
		for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
		start = 0;
		if  ( t2.arr_ptr == 1){
			if(t2.sizes.size()==0){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 0;
		}
		else if( t2.arr_ptr == 0 && t2.sizes.size()>=1){
			if(t2.sizes.size()==1){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t2.sizes.size(); i++){temp2+= "["+to_string(t2.sizes[i])+"]";}

		if($3->type.pointer_level == 0 && $3->type.sizes.size()==0 && $3->type.arr_ptr==0 && $1->type.pointer_level == 0 && $1->type.sizes.size()==0 && $1->type.arr_ptr==0 )
		{
			if($1->type.type_name == "int" && $3->type.type_name == "int"){
				$$ = new op_binary_astnode("NE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="int"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3);
				$$ = new op_binary_astnode("NE_OP_FLOAT",$1, unode);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "int" && $3->type.type_name=="float"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
				$$ = new op_binary_astnode("NE_OP_FLOAT",unode, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="float"){
				$$ = new op_binary_astnode("NE_OP_FLOAT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here";
				compatible = false;
			}
		}
		else{
			if(temp1 == temp2){
				$$ = new op_binary_astnode("NE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if(!($3->type.pointer_level == 0 && $3->type.arr_ptr==0)&& $1->type.type_name == "void" && $1->type.pointer_level == 1 && $1->type.sizes.size()==0){
				$$ = new op_binary_astnode("NE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if(!($1->type.pointer_level == 0 && $1->type.arr_ptr==0) && $3->type.type_name == "void" && $3->type.pointer_level == 1 && $3->type.sizes.size()==0){
				$$ = new op_binary_astnode("NE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if(!($1->type.pointer_level == 0 && $1->type.arr_ptr==0) && $3->astnode_type==typeExp::intconst_astype && $3->int_val == 0){
				$$ = new op_binary_astnode("NE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if(!($3->type.pointer_level == 0 && $3->type.arr_ptr==0) && $1->astnode_type==typeExp::intconst_astype && $1->int_val == 0){
				$$ = new op_binary_astnode("NE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here2";
				compatible = false;
			}

		}
		if(!compatible){
			string temp1 = t1.type_name;
			for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
			for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
			for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
			for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout << "Error at line "<<@$.begin.line<<": Invalid operands types for binary !=, \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

relational_expression:
	additive_expression 
	{
		$$ = $1;
		$$->type = $1->type;
	}
	;

	| relational_expression '<' additive_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;

		bool compatible = true;

		string temp1 = t1.type_name;
		for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
		int start = 0;
		if  ( t1.arr_ptr == 1){
			if(t1.sizes.size()==0){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 0;
		}
		else if( t1.arr_ptr == 0 && t1.sizes.size()>=1){
			if(t1.sizes.size()==1){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t1.sizes.size(); i++){
			temp1+= "["+to_string(t1.sizes[i])+"]";
		}

		string temp2 = t2.type_name;
		for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
		start = 0;
		if  ( t2.arr_ptr == 1){
			if(t2.sizes.size()==0){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 0;
		}
		else if( t2.arr_ptr == 0 && t2.sizes.size()>=1){
			if(t2.sizes.size()==1){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t2.sizes.size(); i++){temp2+= "["+to_string(t2.sizes[i])+"]";}

		if($3->type.pointer_level == 0 && $3->type.sizes.size()==0 && $3->type.arr_ptr==0 && $1->type.pointer_level == 0 && $1->type.sizes.size()==0 && $1->type.arr_ptr==0 )
		{
			if($1->type.type_name == "int" && $3->type.type_name == "int"){
				$$ = new op_binary_astnode("LT_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="int"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3);
				$$ = new op_binary_astnode("LT_OP_FLOAT",$1, unode);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "int" && $3->type.type_name=="float"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
				$$ = new op_binary_astnode("LT_OP_FLOAT",unode, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="float"){
				$$ = new op_binary_astnode("LT_OP_FLOAT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here";
				compatible = false;
			}
		}
		else{
			if(temp1 == temp2){
				$$ = new op_binary_astnode("LT_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here2";
				compatible = false;
			}

		}
		if(!compatible){
			string temp1 = t1.type_name;
			for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
			for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
			for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
			for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout << "Error at line "<<@$.begin.line<<": Invalid operands types for binary < , \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}	
	}
	;

	| relational_expression '>' additive_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		bool compatible = true;

		string temp1 = t1.type_name;
		for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
		int start = 0;
		if  ( t1.arr_ptr == 1){
			if(t1.sizes.size()==0){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 0;
		}
		else if( t1.arr_ptr == 0 && t1.sizes.size()>=1){
			if(t1.sizes.size()==1){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t1.sizes.size(); i++){
			temp1+= "["+to_string(t1.sizes[i])+"]";
		}

		string temp2 = t2.type_name;
		for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
		start = 0;
		if  ( t2.arr_ptr == 1){
			if(t2.sizes.size()==0){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 0;
		}
		else if( t2.arr_ptr == 0 && t2.sizes.size()>=1){
			if(t2.sizes.size()==1){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t2.sizes.size(); i++){temp2+= "["+to_string(t2.sizes[i])+"]";}

		if($3->type.pointer_level == 0 && $3->type.sizes.size()==0 && $3->type.arr_ptr==0 && $1->type.pointer_level == 0 && $1->type.sizes.size()==0 && $1->type.arr_ptr==0 )
		{
			if($1->type.type_name == "int" && $3->type.type_name == "int"){
				$$ = new op_binary_astnode("GT_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="int"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3);
				$$ = new op_binary_astnode("GT_OP_FLOAT",$1, unode);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "int" && $3->type.type_name=="float"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
				$$ = new op_binary_astnode("GT_OP_FLOAT",unode, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="float"){
				$$ = new op_binary_astnode("GT_OP_FLOAT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here";
				compatible = false;
			}
		}
		else{
			if(temp1 == temp2){
				$$ = new op_binary_astnode("GT_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here2";
				compatible = false;
			}

		}
		if(!compatible){
			string temp1 = t1.type_name;
			for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
			for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
			for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
			for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout << "Error at line "<<@$.begin.line<<": Invalid operands types for binary > , \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

	| relational_expression LE_OP additive_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		bool compatible = true;

		string temp1 = t1.type_name;
		for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
		int start = 0;
		if  ( t1.arr_ptr == 1){
			if(t1.sizes.size()==0){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 0;
		}
		else if( t1.arr_ptr == 0 && t1.sizes.size()>=1){
			if(t1.sizes.size()==1){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t1.sizes.size(); i++){
			temp1+= "["+to_string(t1.sizes[i])+"]";
		}

		string temp2 = t2.type_name;
		for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
		start = 0;
		if  ( t2.arr_ptr == 1){
			if(t2.sizes.size()==0){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 0;
		}
		else if( t2.arr_ptr == 0 && t2.sizes.size()>=1){
			if(t2.sizes.size()==1){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t2.sizes.size(); i++){temp2+= "["+to_string(t2.sizes[i])+"]";}

		if($3->type.pointer_level == 0 && $3->type.sizes.size()==0 && $3->type.arr_ptr==0 && $1->type.pointer_level == 0 && $1->type.sizes.size()==0 && $1->type.arr_ptr==0 )
		{
			if($1->type.type_name == "int" && $3->type.type_name == "int"){
				$$ = new op_binary_astnode("LE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="int"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3);
				$$ = new op_binary_astnode("LE_OP_FLOAT",$1, unode);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "int" && $3->type.type_name=="float"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
				$$ = new op_binary_astnode("LE_OP_FLOAT",unode, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="float"){
				$$ = new op_binary_astnode("LE_OP_FLOAT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here";
				compatible = false;
			}
		}
		else{
			if(temp1 == temp2){
				$$ = new op_binary_astnode("LE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here2";
				compatible = false;
			}

		}
		if(!compatible){
			string temp1 = t1.type_name;
			for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
			for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
			for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
			for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout << "Error at line "<<@$.begin.line<<": Invalid operands types for binary >= , \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

	| relational_expression GE_OP additive_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		bool compatible = true;

		string temp1 = t1.type_name;
		for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
		int start = 0;
		if  ( t1.arr_ptr == 1){
			if(t1.sizes.size()==0){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 0;
		}
		else if( t1.arr_ptr == 0 && t1.sizes.size()>=1){
			if(t1.sizes.size()==1){
				temp1+="*";
			}
			else{
				temp1+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t1.sizes.size(); i++){
			temp1+= "["+to_string(t1.sizes[i])+"]";
		}

		string temp2 = t2.type_name;
		for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
		start = 0;
		if  ( t2.arr_ptr == 1){
			if(t2.sizes.size()==0){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 0;
		}
		else if( t2.arr_ptr == 0 && t2.sizes.size()>=1){
			if(t2.sizes.size()==1){
				temp2+="*";
			}
			else{
				temp2+="(*)";
			}
			start = 1;
		}
		for(unsigned int i=start; i<t2.sizes.size(); i++){temp2+= "["+to_string(t2.sizes[i])+"]";}

		if($3->type.pointer_level == 0 && $3->type.sizes.size()==0 && $3->type.arr_ptr==0 && $1->type.pointer_level == 0 && $1->type.sizes.size()==0 && $1->type.arr_ptr==0 )
		{
			if($1->type.type_name == "int" && $3->type.type_name == "int"){
				$$ = new op_binary_astnode("GE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="int"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3);
				$$ = new op_binary_astnode("GE_OP_FLOAT",$1, unode);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "int" && $3->type.type_name=="float"){
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
				$$ = new op_binary_astnode("GE_OP_FLOAT",unode, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else if($1->type.type_name == "float" && $3->type.type_name=="float"){
				$$ = new op_binary_astnode("GE_OP_FLOAT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here";
				compatible = false;
			}
		}
		else{
			if(temp1 == temp2){
				$$ = new op_binary_astnode("GE_OP_INT",$1, $3);
				$$->type = Type("int", 0 , vector<int>());
				$$->type.lvalue = false;
			}
			else{
				//std::cout<<"here2";
				compatible = false;
			}

		}
		if(!compatible){
			string temp1 = t1.type_name;
			for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
			for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
			for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
			for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout << "Error at line "<<@$.begin.line<<": Invalid operands types for binary >= , \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

additive_expression:
	multiplicative_expression 
	{
		$$ = $1;
		$$->type = $1->type;
	}
	;

	| additive_expression '+' multiplicative_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		if((t1.pointer_level > 0 || t1.arr_ptr >0 || t1.sizes.size() > 0) && t2.type_name == "int" && t2.pointer_level == 0 && t2.arr_ptr == 0 && t2.sizes.size() == 0){
			$$ = new op_binary_astnode("PLUS_INT",$1, $3);
			$$->type = $1->type;
			$$->type.lvalue = false;
		}
		else if ((t2.pointer_level > 0 || t2.arr_ptr >0 || t2.sizes.size() > 0) && t1.type_name == "int" && t1.pointer_level == 0 && t1.arr_ptr == 0 && t1.sizes.size() == 0){
			$$ = new op_binary_astnode("PLUS_INT",$1, $3);
			$$->type = $3->type;
			$$->type.lvalue = false;
		}
		else if(t2.pointer_level == 0 && t2.arr_ptr == 0 && t2.sizes.size() == 0 && t1.pointer_level == 0 && t1.arr_ptr == 0 && t1.sizes.size() == 0)
		{
			if ( t1.type_name == "int" && t2.type_name == "int")
			{
				$$ = new op_binary_astnode("PLUS_INT",$1, $3);
				$$->type = $1->type;
				$$->type.lvalue = false;
			}
			else if (t1.type_name == "int" && t2.type_name == "float")
			{
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
				$$ = new op_binary_astnode("PLUS_FLOAT",unode, $3);
				$$->type = $3->type;
				$$->type.lvalue = false;
			}
			else if (t1.type_name == "float" && t2.type_name == "int") 
			{
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT",$3);
				$$ = new op_binary_astnode("PLUS_FLOAT",$1, unode);
				$$->type = $1->type;
				$$->type.lvalue = false;
			}
			else if (t1.type_name == "float" && t2.type_name == "float")
			{
				$$ = new op_binary_astnode("PLUS_FLOAT",$1, $3);
				$$->type = $3->type;
				$$->type.lvalue = false;
			}
			else
			{
				std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary + , \""<<t1.type_name<<"\" and \""<<t2.type_name<<"\"";
				exit(1);
			}
		}
		else
		{
			string temp1 = t1.type_name;
            for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
            for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
            for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
            for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary + , \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

	| additive_expression '-' multiplicative_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;

		if((t1.pointer_level > 0 || t1.arr_ptr >0 || t1.sizes.size() > 0) && t2.type_name == "int" && t2.pointer_level == 0 && t2.arr_ptr == 0 && t2.sizes.size() == 0){
			$$ = new op_binary_astnode("MINUS_INT",$1, $3);
			$$->type = $1->type;
			$$->type.lvalue = false;
		}
		else if ((t2.pointer_level > 0 || t2.arr_ptr >0 || t2.sizes.size() > 0) && (t1.pointer_level > 0 || t1.arr_ptr >0 || t1.sizes.size() > 0)){
			if(isCompatible(t1, t2)){
				$$ = new op_binary_astnode("MINUS_INT",$1, $3);
				$$->type = Type("int", 0 ,vector<int> ());
				$$->type.lvalue = false;
			}
			else{
				string temp1 = t1.type_name;
				for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
				if  ( t1.arr_ptr == 1){temp1 += "(*)";}
				for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
				string temp2 = t2.type_name;
				for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
				if  ( t2.arr_ptr == 1){temp2 += "(*)";}
				for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
				std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary - , \""<<temp1<<"\" and \""<<temp2<<"\"";
				exit(1);
			}
			
		}
		else if(t2.pointer_level == 0 && t2.arr_ptr == 0 && t2.sizes.size() == 0 && t1.pointer_level == 0 && t1.arr_ptr == 0 && t1.sizes.size() == 0)
		{

			if ( t1.type_name == "int" && t2.type_name == "int")
			{
				$$ = new op_binary_astnode("MINUS_INT",$1, $3);
				$$->type = $1->type;
				$$->type.lvalue = false;
			}
			else if (t1.type_name == "int" && t2.type_name == "float")
			{
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
				$$ = new op_binary_astnode("MINUS_FLOAT",unode, $3);
				$$->type = $3->type;
				$$->type.lvalue = false;
			}
			else if (t1.type_name == "float" && t2.type_name == "int") 
			{
				op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT",$3);
				$$ = new op_binary_astnode("MINUS_FLOAT",$1, unode);
				$$->type = $1->type;
				$$->type.lvalue = false;
			}
			else if (t1.type_name == "float" && t2.type_name == "float")
			{
				$$ = new op_binary_astnode("MINUS_FLOAT",$1, $3);
				$$->type = $1->type;
				$$->type.lvalue = false;
			}
			else
			{
				std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary - , \""<<t1.type_name<<"\" and \""<<t2.type_name<<"\"";
				exit(1);
			}
		}
		else
		{
			string temp1 = t1.type_name;
            for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
            for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
            for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
            for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary - , \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}

	}
	;

unary_expression:
	postfix_expression 
	{
		$$ = $1;
		$$->type = $1->type;
	}
	;

	| unary_operator unary_expression 
	{
		$$ = new op_unary_astnode($1, $2);
		if($1=="NOT"){
			$$->type = Type("int", 0, vector<int>());
			if($2->type.type_name == "int" || $2->type.type_name == "float" || $2->type.pointer_level > 0 || $2->type.arr_ptr >0 || $2->type.sizes.size() > 0)
			{			}
			else{
				std::cout<<"Error at line "<<@$.begin.line<<":  Operand of  NOT should be an int or float or pointer";
				exit(1);
				}
			$$->type.lvalue = false;
		}
		else if($1 == "DEREF"){
			Type t = $2->type;
			Type t1 = t;
			if ( t.arr_ptr > 0)
			{
				t1.arr_ptr--;
				$$->type = t1;
			}
			else
			{
				$$->type = Type(t.type_name, t.pointer_level-1, t.sizes);
			}
			if(t.pointer_level > 0 || t.arr_ptr >0 || t.sizes.size() > 0){}
			else{
				std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand type \""<<t.type_name<<"\" of unary *";
				exit(1);
			}
			if ( t.type_name == "void")
			{
				string temp2 = t.type_name;
				for(int i=0; i<t.pointer_level; i++){ temp2 += "*";}
				if  ( t.arr_ptr == 1){temp2 += "(*)";}
				for(auto i:t.sizes){temp2+= "["+to_string(i)+"]";}
				std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand type \""<<temp2<<"\" of unary *";
				exit(1);
			}
			$$->type.lvalue = true;
		}
		else if($1 == "ADDRESS")
		{
			Type t = $2->type;
			Type t2(t.type_name, t.pointer_level, t.sizes);
			t2.arr_ptr += 1;
			$$->type = t2;
			if($2->type.lvalue == false){
				std::cout<<"Error at line "<<@$.begin.line<<":  Operand of unary & should have an lvalue";
				exit(1);
			}
			$$->type.lvalue = false;
			
		}
		else{
			$$->type = $2->type;
			if($2->type.type_name == "int" || $2->type.type_name == "float"){}
			else{
				std::cout<<"Error at line "<<@$.begin.line<<":  Operand of unary - should be an int or float";
				exit(1);
			}
			if($2->type.pointer_level > 0 || $2->type.arr_ptr >0 || $2->type.sizes.size() > 0)
			{
				std::cout<<"Error at line "<<@$.begin.line<<":  Operand of unary - should be an int or float";
				exit(1);
			}
			$$->type.lvalue=true;
		}
		
	}
	;

multiplicative_expression:
	unary_expression 
	{
		$$ = $1;
		$$->type = $1->type;
	}
	;

	| multiplicative_expression '*' unary_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		if ( t1.type_name == "int" && t2.type_name == "int")
		{
			$$ = new op_binary_astnode("MULT_INT",$1, $3);
			$$->type = $1->type;
			$$->type.lvalue = false;
		}
		else if (t1.type_name == "int" && t2.type_name == "float")
		{
			op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
			$$ = new op_binary_astnode("MULT_FLOAT",unode, $3);
			$$->type = $3->type;
			$$->type.lvalue = false;
		}
		else if (t1.type_name == "float" && t2.type_name == "int") 
		{
			op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT",$3);
			$$ = new op_binary_astnode("MULT_FLOAT",$1, unode);
			$$->type = $1->type;
			$$->type.lvalue = false;
		}
		else if (t1.type_name == "float" && t2.type_name == "float")
		{
			$$ = new op_binary_astnode("MULT_FLOAT",$1, $3);
			$$->type = $1->type;
			$$->type.lvalue = false;
		}
		else
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary * , \""<<t1.type_name<<"\" and \""<<t2.type_name<<"\"";
			exit(1);
		}
		if((t2.pointer_level > 0 || t2.arr_ptr >0 || t2.sizes.size() > 0) || (t1.pointer_level > 0 || t1.arr_ptr >0 || t1.sizes.size() > 0))
		{
			string temp1 = t1.type_name;
            for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
            for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
            for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
            for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary * , \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

	| multiplicative_expression '/' unary_expression 
	{
		Type t1 = $1->type;
		Type t2 = $3->type;
		if ( t1.type_name == "int" && t2.type_name == "int")
		{
			$$ = new op_binary_astnode("DIV_INT",$1, $3);
			$$->type = $1->type;
			$$->type.lvalue = false;
		}
		else if (t1.type_name == "int" && t2.type_name == "float")
		{
			op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $1);
			$$ = new op_binary_astnode("DIV_FLOAT",unode, $3);
			$$->type = $3->type;
			$$->type.lvalue = false;
		}
		else if (t1.type_name == "float" && t2.type_name == "int") 
		{
			op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT",$3);
			$$ = new op_binary_astnode("DIV_FLOAT",$1, unode);
			$$->type = $1->type;
			$$->type.lvalue = false;
		}
		else if (t1.type_name == "float" && t2.type_name == "float")
		{
			$$ = new op_binary_astnode("DIV_FLOAT",$1, $3);
			$$->type = $1->type;
			$$->type.lvalue = false;
		}
		else
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary / , \""<<t1.type_name<<"\" and \""<<t2.type_name<<"\"";
			exit(1);
		}
		if((t2.pointer_level > 0 || t2.arr_ptr >0 || t2.sizes.size() > 0) || (t1.pointer_level > 0 || t1.arr_ptr >0 || t1.sizes.size() > 0))
		{
			string temp1 = t1.type_name;
            for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
			if  ( t1.arr_ptr == 1){temp1 += "(*)";}
            for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
			string temp2 = t2.type_name;
            for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
			if  ( t2.arr_ptr == 1){temp2 += "(*)";}
            for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
			std::cout<<"Error at line "<<@$.begin.line<<": Invalid operand types for binary / , \""<<temp1<<"\" and \""<<temp2<<"\"";
			exit(1);
		}
	}
	;

postfix_expression:
	primary_expression 
	{
		$$ = $1;
		$$->type = $1->type;
	}
	;

	| postfix_expression '[' expression ']' 
	{
		$$ = new arrayref_astnode($1, $3);
		Type t1 = $1->type;
		t1.sizes.pop_back();
		$$->type = t1;
		if ( $3->type.type_name != "int" || $3->type.pointer_level > 0 || $3->type.sizes.size() > 0)
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Array subscript is not an integer";
			exit(1);
		}
		if( ($1->type.pointer_level == 0 && $1->type.sizes.size()==0) || $1->type.type_name == "void")
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Subscripted value is neither array nor pointer";
			exit(1);
		}
		$$->type.lvalue = true;
	}
	;

	| IDENTIFIER '(' ')' 
	{
		vector<exp_astnode*> vec = { };
		identifier_astnode* idnode = new identifier_astnode($1);
		$$ = new funcall_astnode(idnode, vec);
		bool exists = false;
		for (const auto &entry : gst.Entries)
		{
			if (entry.second.symname == $1){
				exists = true;
				break;
			}
		}
				string printf = "printf";
		string scanf = "scanf";
		if(!exists)
		{
			
			if(!($1==printf || $1==scanf )){
				std::cout<<"Error at line "<<@$.begin.line<<": \""<<$1<<"\" is not defined";
				exit(1);
			}
		}
		if(!($1==printf || $1==scanf ))
		{
			if(func_map[$1].size() > 0)
			{
				std::cout<<"Error at line "<<@$.begin.line<<": Procedure \""<<$1<<"\"  called with too many arguments";
				exit(1);
			}
			$$->type = gst.Entries[$1].ret_type;
			$$->type.lvalue = false;
		}
		else if($1==printf || $1==scanf)
		{
			$$->type = Type("void",0,vector<int>());
			$$->type.lvalue = false;
		}

	}
	;

	| IDENTIFIER '(' expression_list ')' 
	{
		identifier_astnode* idnode = new identifier_astnode($1);
		// idnode->type.lvalue = true;
		
		bool exists = false;
		for (const auto &entry : gst.Entries)
		{
			if (entry.second.symname == $1){
				exists = true;
				break;
			}
		}
		string printf = "printf";
		string scanf = "scanf";
		if(!exists)
		{
			if(!($1==printf || $1==scanf )){
				std::cout<<"Error at line "<<@$.begin.line<<": \""<<$1<<"\" is not defined";
				exit(1);
			}
		}
		if(!($1==printf || $1==scanf )){

			unsigned int n = $3.size();
			if(func_map[$1].size() < n)
			{
				std::cout<<"Error at line "<<@$.begin.line<<": Procedure \""<<$1<<"\"  called with too many arguments";
				exit(1);
			}
			if(func_map[$1].size() > n)
			{
				std::cout<<"Error at line "<<@$.begin.line<<": Procedure \""<<$1<<"\"  called with too few arguments";
				exit(1);
			}
			
			for( unsigned int i=0 ;i<n ;i++)
			{
				Type t1 = $3[i]->type;
				Type t2 = func_map[$1][i].ret_type;
				if(t2.pointer_level == 0 && t2.arr_ptr == 0 && t2.sizes.size() == 0 && t1.pointer_level == 0 && t1.arr_ptr == 0 && t1.sizes.size() == 0)
				{
					if ( t1.type_name == t2.type_name)
					{
						
					}
					else if (t1.type_name == "int" && t2.type_name == "float")
					{
						op_unary_astnode* unode = new op_unary_astnode("TO_FLOAT", $3[i]);
						$3[i] = unode;
					}
					else if (t1.type_name == "float" && t2.type_name == "int") 
					{
						op_unary_astnode* unode = new op_unary_astnode("TO_INT", $3[i]);
						$3[i] = unode;
					}
					else
					{
						std::cout<<"Error at line "<<@$.begin.line<<": Expected \""<<t2.type_name<<"\" but argument is of type \""<<t1.type_name<<"\"";
						exit(1);
					}
				}
				else
				{
					if(!isCompatible(t1,t2))
					{
						string temp1 = t1.type_name;
						for(int i=0; i<t1.pointer_level; i++){ temp1 += "*";}
						if  ( t1.arr_ptr == 1){temp1 += "(*)";}
						for(auto i:t1.sizes){temp1+= "["+to_string(i)+"]";}
						string temp2 = t2.type_name;
						for(int i=0; i<t2.pointer_level; i++){ temp2 += "*";}
						if  ( t2.arr_ptr == 1){temp2 += "(*)";}
						for(auto i:t2.sizes){temp2+= "["+to_string(i)+"]";}
						std::cout<<"Error at line "<<@$.begin.line<<": Expected \""<<temp2<<"\" but argument is of type \""<<temp1<<"\"";
						exit(1);
					}
					
				}

			}
			$$ = new funcall_astnode(idnode, $3);
			$$->type = gst.Entries[$1].ret_type;
			$$->type.lvalue = false;
		}
		else
		{
			$$ = new funcall_astnode(idnode, $3);
			$$->type = Type("void",0,vector<int>());
			$$->type.lvalue = false;
		}
		
		
	}
	;

	| postfix_expression '.' IDENTIFIER 
	{
		identifier_astnode* idnode = new identifier_astnode($3);
		$$ = new member_astnode($1, idnode);
		if ( ($1->type.type_name.compare(0,6,"struct") != 0) && ($1->type.pointer_level == 0 && $1->type.sizes.size() == 0))
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Left operand of \".\"  is not a  structure";
			exit(1);
		}
		if ( gst.Entries[$1->type.type_name].symbtab->vartype($3).type_name == "-")
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Struct \""<<$1->type.type_name<<"\" has no member named \""<<$3<<"\"";
			exit(1);
		}
		$$->type = gst.Entries[$1->type.type_name].symbtab->vartype($3);
		$$->type.lvalue = true;
		
	}
	;

	| postfix_expression PTR_OP IDENTIFIER 
	{
		identifier_astnode* idnode = new identifier_astnode($3);
		$$ = new arrow_astnode($1, idnode);
		if (!(($1->type.pointer_level == 1 && $1->type.sizes.size() == 0) || ($1->type.pointer_level == 0 && $1->type.sizes.size() == 1)))
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Left operand of \"->\" is not a pointer to structure";
			exit(1);
		}
		if ( ($1->type.type_name.compare(0,6,"struct") != 0))
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Left operand of \"->\" is not a pointer to structure";
			exit(1);
		}
		if ( gst.Entries[$1->type.type_name].symbtab->vartype($3).type_name == "-")
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Struct \""<<$1->type.type_name<<"\" has no member named \""<<$3<<"\"";
			exit(1);
		} 
		$$->type = gst.Entries[$1->type.type_name].symbtab->vartype($3);
		$$->type.lvalue = true;
	}
	;

	| postfix_expression INC_OP 
	{
		$$ = new op_unary_astnode("PP", $1);
		if($1->type.lvalue == false){
			std::cout<<"Error at line "<<@$.begin.line<<": Operand of \"++\" should have lvalue";
			exit(1);
		}
		$$->type = $1->type;
		$$->type.lvalue = false;
	}
	;

primary_expression:
	IDENTIFIER 
	{
		$$ = new identifier_astnode($1);
		$$->type = curr_st->vartype($1);
		if ( $$->type.type_name == "-")
		{
			std::cout<<"Error at line "<<@$.begin.line<<": Variable \""<<$1<<"\" not declared";
			exit(1);
		}
		$$->type.lvalue = true;
	}
	;

	| INT_CONSTANT 
	{
		$$ = new intconst_astnode(stoi($1));
		$$->type = Type("int",0,vector<int>());
		$$->type.lvalue = false;
	}
	;

	| FLOAT_CONSTANT 
	{
		$$ = new floatconst_astnode(stof($1));
		$$->type = Type("float",0,vector<int>());
		$$->type.lvalue = false;
	}
	;

	| STRING_LITERAL 
	{
		$$ = new string_astnode($1);
		$$->type = Type("string",0,vector<int>());
		$$->type.lvalue = false;
	}
	;

	| '(' expression ')' 
	{
		$$ = $2;
		$$->type = $2->type;
	}
	;

expression_list:
	expression 
	{
		vector<exp_astnode*> vec;
		vec.push_back($1);
		$$ = vec;
	}
	;

	| expression_list ',' expression 
	{
		$1.push_back($3);
		$$ = $1; 
	}
	;

unary_operator:
	'-' 
	{
		$$ = "UMINUS";
	}
	;

	| '!' 
	{
		$$ = "NOT";
	}
	;

	| '&' 
	{
		$$ = "ADDRESS";
	}
	;

	| '*' 
	{
		$$ = "DEREF";
	}
	;

selection_statement:
	IF '(' expression ')' statement ELSE statement 
	{
		$$ = new if_astnode($3, $5, $7);
	}
	;

iteration_statement:
	WHILE '(' expression ')' statement 
	{
		$$ = new while_astnode($3, $5);
	}
	;

	| FOR '(' assignment_expression ';' expression ';' assignment_expression ')' statement 
	{
		$$ = new for_astnode($3, $5, $7, $9);
	}
	;

declaration_list:
	declaration 
	{
		
	}
	;

	| declaration_list declaration 
	{
		
	}
	;

declaration:
	type_specifier declarator_list ';' 
	{
		
	}
	;

declarator_list:
	declarator 
	{
		global_type.type_name = dec_type;
		if(dec_type == "void" && global_type.pointer_level == 0)
		{
			string temp1 = global_type.type_name;
            for(auto i:global_type.sizes){temp1+= "["+to_string(i)+"]";}
			std::cout<<"Error at line "<<@$.begin.line<<": Cannot declare variable of type \""<<temp1<<"\"";
			exit(1);
		}
		if ( curr == dec_type && global_type.pointer_level == 0)
		{
			std::cout<<"Error at line "<<@$.begin.line<<": \""<<dec_type<<"\" is not defined";
			exit(1);
		}
		if ( curr_st->vartype(curr_strow.symname).type_name != "-")
		{
			std::cout<<"Error at line "<<@$.begin.line<<": \""<<curr_strow.symname<<"\" has a previous declaration";
			exit(1);
		}
		int multi = 1;
		for(auto i : global_type.sizes){ multi = multi*i;}
		if ( global_type.pointer_level > 0){
			dec_size = 4;
		}
		if (curr_st->table.size() == 0)
		{
			if (curr_trunit == "fun"){
				curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,-dec_size*multi,global_type)); //to-be-changed
				}
			else{
				curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,0,global_type)); 
			}
		}
		else{
			int size_temp = curr_st->table.back().size;
			int offset_temp = curr_st->table.back().offset;

			if (curr_trunit == "fun"){
				if ( offset_temp < 0){curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,offset_temp-dec_size*multi,global_type)); //to-be-changed
					}
				else {curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,-dec_size*multi,global_type)); 
					}
			}
			else{
				curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,offset_temp+size_temp,global_type)); 
			}
		}
		global_type = Type("-",0,vector<int>());
	}
	;

	| declarator_list ',' declarator 
	{
		
		global_type.type_name = dec_type;
		int multi = 1;
		if ( global_type.pointer_level > 0){
			dec_size = 4;
		}
		for(auto i : global_type.sizes){ multi = multi*i;}
		if (curr_st->table.size() == 0)
		{
			if (curr_trunit == "fun"){
				curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,-dec_size*multi,global_type)); //to-be-changed
				}
			else{
				curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,0,global_type)); 
			}
		}
		else{
			int size_temp = curr_st->table.back().size;
			int offset_temp = curr_st->table.back().offset;

			if (curr_trunit == "fun"){
				if ( offset_temp < 0){curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,offset_temp-dec_size*multi,global_type)); //to-be-changed
					}
				else {curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,-dec_size*multi,global_type)); 
					}
			}
			else{
				curr_st->table.push_back(SymbolTableRow2(curr_strow.symname,"var","local",dec_size*multi,offset_temp+size_temp,global_type)); 
			}
		}
		
		global_type = Type("-",0,vector<int>());
	
	}
	;



%%
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cout << "Error at line " << line_num << ": " << err_message << "\n";
	exit(1);
}


