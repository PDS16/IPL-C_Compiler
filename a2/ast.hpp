#ifndef AST_H
#define AST_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdarg.h>
#include "type.hh"

using namespace std;

enum typeExp {
    abstract_astype,
    statement_astype,
    exp_astype,
    ref_astype,
    empty_astype,
    seq_astype,
    assgnS_astype,
    return_astype,
    proccall_astype,
    if_astype,
    while_astype,
    for_astype,
    op_binary_astype,
    op_unary_astype,
    assgnE_astype,
    funcall_astype,
    floatconst_astype,
    intconst_astype,
    string_astype,
    member_astype,
    arrow_astype,
    identifier_astype,
    index_astype,
    arrayref_astype,
};

extern void printAst(const char *astname, const char *fmt,...);

class abstract_astnode{
    public:
        virtual void print(int blanks) = 0;
        enum typeExp astnode_type;

        abstract_astnode(){
            this->astnode_type = abstract_astype;
        }

};



//---------------------------------------------

class statement_astnode : public abstract_astnode 
{
    public: 
        
        enum typeExp astnode_type;

        statement_astnode(){
            this->astnode_type = statement_astype;
        }

        void print(int blanks){

        }
};

class exp_astnode : public abstract_astnode 
{
    public: 
        
        enum typeExp astnode_type;
        Type type;
        int int_val;

        exp_astnode(){
            this->astnode_type = exp_astype;
        }

        void print(int blanks){

        }
};

class ref_astnode : public exp_astnode
{
    public:
        
        enum typeExp astnode_type;

        ref_astnode(){
            this->astnode_type = ref_astype;
        }

        void print(int blanks){

        }
};

class empty_astnode : public statement_astnode 
{
    public:
    empty_astnode(){
        this->astnode_type = empty_astype;
    }

    void print(int blanks){
        cout<<"\"empty\""<<endl;
    }
};

class nostatement : public statement_astnode
{
    public:
    nostatement(){
        this->astnode_type = empty_astype;
    }

    void print(int blanks){

    }
};

class identifier_astnode : public ref_astnode
{
    public:
        string id_astnode;

        identifier_astnode(string id_astnode){
            this->id_astnode = id_astnode;
            this->astnode_type = identifier_astype;
        }


        void print(int blanks){
            printAst(NULL, "s", "identifier", ("\"" + id_astnode + "\"").c_str());
        }
};

class seq_astnode : public statement_astnode
{

    public:
        vector<statement_astnode*> vec_nodes;

        seq_astnode(vector<statement_astnode*> vec){
            this->vec_nodes = vec;
            this->astnode_type = seq_astype;
        }

        void print(int blanks){
            printAst(NULL,"l","seq",&vec_nodes);
        }

};

class assgnS_astnode : public statement_astnode
{
    public:
        exp_astnode* lhs_node, *rhs_node;

        assgnS_astnode(exp_astnode* lhs, exp_astnode* rhs){
            this->lhs_node = lhs;
            this->rhs_node = rhs;
            this->astnode_type = assgnS_astype;
        }

        void print(int blanks){
            printAst("assignS", "aa", "left", lhs_node, "right", rhs_node);
        }
};

class return_astnode : public statement_astnode
{
    public:
        exp_astnode* node;
        enum typeExp astnode_type;  


        return_astnode(exp_astnode* node){
            this->node = node;
            this->astnode_type = return_astype;
        }

        void print(int blanks){
            printAst(NULL,"a","return",node);
        }


};

class proccall_astnode : public statement_astnode
{
    public:
        identifier_astnode* proc_name;
        vector<exp_astnode*> vec_nodes;

        proccall_astnode(identifier_astnode* proc_name, vector<exp_astnode*> vec_nodes){
            this->vec_nodes = vec_nodes;
            this->proc_name = proc_name;
            this->astnode_type = proccall_astype;
        }

        void print(int blanks){
            printAst("proccall","al","fname", proc_name,"params",&vec_nodes);
        }
};

class if_astnode : public statement_astnode
{
    public:
        exp_astnode* cond;
        statement_astnode* then_statement, *else_statement;

        if_astnode(exp_astnode* cond, statement_astnode* then_statement, statement_astnode* else_statement){
            this->cond = cond;
            this->then_statement = then_statement;
            this->else_statement = else_statement;
            this->astnode_type = if_astype;
        }

        void print(int blanks){
            printAst("if", "aaa", "cond", cond, "then", then_statement, "else", else_statement);
        }
};

class while_astnode : public statement_astnode
{
    public:
        exp_astnode* cond;
        statement_astnode* do_statement;

        while_astnode(exp_astnode* cond, statement_astnode* do_statement){
            this->cond = cond;
            this->do_statement = do_statement;
            this->astnode_type = while_astype;
        }

        void print(int blanks){
            printAst("while","aa","cond",cond,"stmt",do_statement);
        }
};

class for_astnode : public statement_astnode
{
    public:
        exp_astnode* assgn_astnode, *cond_astnode, *step_astnode;
        statement_astnode* do_statement;

        for_astnode(exp_astnode* assgn_astnode, exp_astnode* cond_astnode, exp_astnode* step_astnode, statement_astnode* do_statement){
            this->assgn_astnode = assgn_astnode;
            this->cond_astnode = cond_astnode;
            this->step_astnode = step_astnode;
            this->do_statement = do_statement;
            this->astnode_type = for_astype;
        }

        void print(int blanks){
            printAst("for","aaaa","init",assgn_astnode,"guard",cond_astnode,"step",step_astnode,"body",do_statement);
        }
};

class op_binary_astnode : public exp_astnode 
{
    public:
        string operator_info;
        exp_astnode* astnode1, *astnode2;

        op_binary_astnode(string operator_info, exp_astnode* astnode1, exp_astnode* astnode2){
            this->operator_info = operator_info;
            this->astnode1 = astnode1;
            this->astnode2 = astnode2;
            this->astnode_type = op_binary_astype;
        }

        void print(int blanks){
            printAst("op_binary","saa","op",("\"" + operator_info + "\"").c_str(),"left",astnode1,"right",astnode2);
        }
        
};

class op_unary_astnode : public exp_astnode
{
    public:
        string operator_info;
        exp_astnode* astnode;

        op_unary_astnode(string operator_info, exp_astnode* astnode){
            this->operator_info = operator_info;
            this-> astnode = astnode;
            this->astnode_type = op_binary_astype;
        }

        void print(int blanks){
            printAst("op_unary","sa","op",("\"" + operator_info + "\"").c_str(),"child",astnode);
            // cout<<"\"op_unary\": {\n\"op\":";
            // cout<<this->operator_info<<"\n,\n\"child\":\n{ ";

        }
};

class assgnE_astnode : public exp_astnode
{
    public:
        exp_astnode* lhs_astnode, *rhs_astnode;

        assgnE_astnode(exp_astnode* lhs, exp_astnode* rhs){
            this->lhs_astnode = lhs;
            this->rhs_astnode = rhs;
            this->astnode_type = assgnE_astype;
        }

        
        void print(int blanks){
            printAst("assignE","aa","left",lhs_astnode,"right",rhs_astnode);
        }

};

class funcall_astnode : public exp_astnode
{
    public:
        identifier_astnode* fname;
        vector<exp_astnode*> vec_exps;

        funcall_astnode(identifier_astnode* fname, vector<exp_astnode*> vec){
            this->fname = fname;
            this->vec_exps = vec;
            this->astnode_type = funcall_astype;
        }

        void print(int blanks){
            printAst("funcall","al","fname",fname,"params",&vec_exps);
        }
};

class floatconst_astnode : public exp_astnode
{
    public:
        float float_val;

        floatconst_astnode(float val){
            this->float_val = val;
            this->astnode_type = floatconst_astype;
        }


        void print(int blanks){
            printAst(NULL,"f","floatconst",float_val);
        }
};

class intconst_astnode : public exp_astnode
{
    public:
        int int_val;

        intconst_astnode(int val){
            this->int_val = val;
            this->astnode_type = intconst_astype;
        }

        void print(int blanks){
            printAst(NULL,"i","intconst",int_val);
        }
};

class string_astnode : public exp_astnode
{
    public:
        string str_val;

        string_astnode(string str_val){
            this->str_val = str_val;
            this->astnode_type = string_astype;
        }


        void print(int blanks){
            printAst(NULL,"s","stringconst",str_val.c_str());
        }
};



class member_astnode : public exp_astnode
{
    public:
        exp_astnode *astnode;
        identifier_astnode *id_astnode;

        member_astnode(exp_astnode* astnode, identifier_astnode* id_astnode){
            this->astnode = astnode;
            this->id_astnode = id_astnode;
            this->astnode_type = member_astype;
        }


        void print(int blanks){
            printAst("member","aa","struct",astnode,"field",id_astnode);
        }
};

class arrow_astnode : public exp_astnode
{
    public:
        exp_astnode* astnode;
        identifier_astnode* id_astnode;

        arrow_astnode(exp_astnode* astnode, identifier_astnode* id_astnode){       
            this->astnode = astnode;
            this->id_astnode = id_astnode;
            this->astnode_type = arrow_astype;
        }

        void print(int blanks){
            printAst("arrow","aa","pointer",astnode,"field",id_astnode);
        }
};



class arrayref_astnode : public exp_astnode
{
    public:
        exp_astnode* arr_astnode, *index_astnode;
        enum typeExp astnode_type;

        arrayref_astnode(exp_astnode* arr_astnode, exp_astnode* index_astnode){
            this->arr_astnode = arr_astnode;
            this->index_astnode = index_astnode;
            this->astnode_type = arrayref_astype;
        }

        void print(int blanks){
            printAst("arrayref","aa","array",arr_astnode,"index",index_astnode);
        }
};

struct nType{
    abstract_astnode* ast;
    vector<exp_astnode*> vec_expr;
    string op;
};

#endif