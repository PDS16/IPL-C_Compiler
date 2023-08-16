#ifndef AST_H
#define AST_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdarg.h>
#include "type.hh"
#include "symbtab.hh"

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
static int label=0;
static int params = 0;


class abstract_astnode{
    public:
        virtual void print(int blanks) = 0;
        virtual void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size)=0;
        virtual void addr(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size)=0;
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            
        }

        void addr(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            
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
        
        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            // cout <<" Hello E";
        }

        void addr(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){

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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            // cout <<"Empty_astnode";
        }
};

class empty_astnode : public statement_astnode 
{
    public:
    empty_astnode(){
        this->astnode_type = empty_astype;
    }

    void print(int blanks){
        // cout<<"\"empty\""<<endl;
    }

    void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
         
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

    void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
         
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            int offset = 0;
            Type type = this->type;

            if(type.type_name == "int" || type.pointer_level!=0 || type.arr_ptr!=0 || type.sizes.size()!=0){
                for (auto e : curr_st->table)
                {
                    if ( e.symname == id_astnode)
                    {
                        offset = e.offset;
                        code += "\tmovl\t"+to_string(offset)+"(%ebp),\t%eax\n";

                        break;
                    }
                }
            }
            else{
                for (auto e : curr_st->table)
                {
                    
                    if (e.symname == id_astnode && e.type == "struct")
                    {
                        
                        offset = e.offset;
                        int size = e.size;
                        int iter = size/4;

                        cout<< iter;
                        code += "\tleal\t"+to_string(offset + size - 4) + "(%ebp),\t%eax\n";
                        //push the struct into stack
                        for (int i=0; i<iter; i++){
                            code += "\tmovl\t(%eax),\t%ebx\n";
                            code += "\tpushl\t%ebx\n";
                            code += "\taddl\t$4,\t%eax\n";
                        }
                    }
                }
            }
            
            
        } //offset nikalna hai abhi

        void addr(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            int offset = 0;
            for (auto e : curr_st->table)
            {
                if ( e.symname == id_astnode)
                {
                    offset = e.offset;
                    break;
                }
            }
            //cout << "Here\n";
            code += "\tleal\t"+to_string(offset)+"(%ebp),\t%eax\n";
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            for(class statement_astnode* s : this->vec_nodes){
                // cout<<"Seq_Astnode\n";
                s->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            }
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            
            if(lhs_node->type.type_name.compare(0,6,"struct")==0 && lhs_node->type.pointer_level==0 && lhs_node->type.arr_ptr && lhs_node->type.sizes.size()==0){
                rhs_node->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                lhs_node->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);

                int size = gst.Entries[lhs_node->type.type_name].size;
                int iter = size/4;

                for (int i=0; i<iter; i++){
                    code += "\tpopl\t%ebx\n";
                    code += "\tmovl\t%ebx,\t(%eax)\n";
                    code += "\tsubl\t$4,\t%eax\n";
                }
            }
            else{
                rhs_node->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tpushl\t%eax\n";
            
                lhs_node->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tpopl\t%ebx\n";
                code += "\tmovl\t%ebx,\t(%eax)\n";
            }
            
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            node->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            

            Type type = gst.Entries[curr].ret_type;
        
            
            if(type.type_name.compare(0,6,"struct")==0){
                int size = gst.Entries[type.type_name].size;
                int iter = size/4;
                code += "\tmovl\t%ebp,\t%eax\n";
                for(int i=0; i<iter ; i++){
                    code += "\tpopl\t%ebx\n";
                    code += "\tmovl\t%ebx,\t"+to_string(param_size)+"(%eax)\n";
                    code += "\tsubl\t$4,\t%eax\n";
                }
            }
            
            
            code += "\tleave\n";
		    code += "\tret\n";
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            if(proc_name->id_astnode == "printf"){
                // cout<<"Printf\n";
                for (int i=vec_nodes.size()-1; i>0; i--){
                    vec_nodes[i]->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                    code += "\tpushl\t%eax\n";
    
                }
                vec_nodes[0]->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tcall\t"+proc_name->id_astnode+"\n"; 
                code += "\taddl\t$"+to_string(4*vec_nodes.size())+",\t%esp\n";
            }
            else{
                Type type = gst.Entries[proc_name->id_astnode].ret_type; 
                int size = gst.Entries[type.type_name].size;
                params = 0;

                if(type.type_name.compare(0,6,"struct")==0){
                    code += "\tsubl\t$"+to_string(4*size)+",\t%esp\n"; //allocate space for 
                }
               
                for(unsigned int i=0 ; i<vec_nodes.size(); i++){
                    vec_nodes[i]->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                    code += "\tpushl\t%eax\n";
                    string type = vec_nodes[i]->type.type_name;

                    if(type.compare(0,6,"struct")==0){
                        params += gst.Entries[type].size;
                    }
                    else{
                        params += 4;
                    }
                }
               
                code += "\tcall\t" + proc_name->id_astnode+"\n";
                // code += "\taddl\t$"+to_string(4*vec_nodes.size())+",\t%esp\n";
                code += "\taddl\t$"+to_string(params)+",\t%esp\n";
                
                if(type.type_name.compare(0,6,"struct")==0){
                    code += "\taddl\t$"+to_string(4*size)+",\t%esp"; //remove space for 
                }

            }
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            cond->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            code += "\tcmpl\t$1,\t%eax\n";
            int instr = label;
            label++;
            code += "\tjne\t.L"+to_string(instr)+"\n";
            then_statement->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            int next = label;
            label++;
            code += "\tjmp\t.L"+to_string(next)+"\n";
            code += ".L"+to_string(instr)+":\n";
            else_statement->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            code += ".L"+to_string(next)+":\n";
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            int instr = label;
            label++;
            code += ".L" + to_string(instr)+":\n";
            cond->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            code += "\tcmpl\t$1,\t%eax\n";
            int next = label;
            label++;
            code += "\tjne\t.L" + to_string(next) + "\n";
            do_statement->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            code += "\tjmp\t.L" + to_string(instr) + "\n";
            code += ".L" + to_string(next) + ":\n";
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            assgn_astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            int instr_cond = label;
            label++;
            code += ".L" + to_string(instr_cond)+":\n";
            cond_astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            code += "\tcmpl\t$1,\t%eax\n";
            int next_instr = label;
            label++;
            code += "\tjne\t.L" + to_string(next_instr) + "\n";
            do_statement->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            step_astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            code += "\tjmp\t.L"+to_string(instr_cond)+"\n";
            code += ".L"+to_string(next_instr)+":\n";
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
        

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            if(operator_info == "AND_OP"){
                astnode1->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                
                code +="\tcmpl\t$0,\t%eax\n";
                int instr_label = label;
                label++;
                code +="\tje\t.L"+ to_string(instr_label)+"\n";
                
                astnode2->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code +="\tcmpl\t$0,\t%eax\n";
                code +="\tje\t.L"+ to_string(instr_label)+"\n";
                
                
                int nextinstr = label;
                label++;
                
                code +="\tmovl\t$1,\t%eax\n";
                code +="\tjmp\t.L"+ to_string(nextinstr)+"\n";
                
                code +=".L"+ to_string(instr_label)+":\n";
                code +="\tmovl\t$0,\t%eax\n";

                code +=".L"+ to_string(nextinstr)+":\n";

            }

            else if(operator_info == "OR_OP"){
                
                astnode1->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                
                code +="\tcmpl\t$0,\t%eax\n";
                int instr_label = label;
                label++;
                code +="\tjne\t.L"+ to_string(instr_label)+"\n";
    
                astnode2->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code +="\tcmpl\t$0,\t%eax\n";
                code +="\tjne\t.L"+ to_string(instr_label)+"\n";

                int nextinstr = label;
                label++;
                
                code +="\tmovl\t$0,\t%eax\n";
                code +="\tje\t.L"+ to_string(nextinstr)+"\n";

                code +=".L"+ to_string(instr_label)+":\n";
                code +="\tmovl\t$1,\t%eax\n";

                code +=".L"+ to_string(nextinstr)+":\n";
            }

            else{
                astnode2-> gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tpushl\t%eax\n";

                Type type1 = astnode1->type;
                Type type2 = astnode2->type;

                astnode1->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tpopl\t%ebx\n";

                if(operator_info == "PLUS_INT"){
                    if(type1.pointer_level!=0 || type1.arr_ptr!=0 || type1.sizes.size()!=0){
                        code += "\timull\t$4,\t%ebx\n";
                        code += "\taddl\t%ebx,\t%eax\n";
                    }
                    else if(type2.pointer_level!=0 || type2.arr_ptr!=0 || type2.sizes.size()!=0){
                        code += "\timull\t$4,\t%eax\n";
                        code += "\taddl\t%eax,\t%ebx\n";
                    }
                    else{
                        code += "\taddl\t%ebx,\t%eax\n";
                    }
                }
                else if(operator_info == "MINUS_INT"){
                    if((type1.pointer_level!=0 || type1.arr_ptr!=0 || type1.sizes.size()!=0) && (type2.pointer_level!=0 || type2.arr_ptr!=0 || type2.sizes.size()!=0)){
                        code += "\tsubl\t%ebx,\t%eax\n";
                        if(type1.type_name.compare(0,6,"struct")==0){
                            int size = gst.Entries[type1.type_name].size;
                            code += "\tmovl\t$"+to_string(size)+",\t%ebx\n";
                            code += "\tcltd\n";
                            code += "\tidivl\t%ebx\n";
                        }
                        else{
                            code += "\tmovl\t$4,\t%ebx\n";
                            code += "\tcltd\n";
                            code += "\tidivl\t%ebx\n"; 
                        }
                    }
                    else if(type1.pointer_level!=0 || type1.arr_ptr!=0 || type1.sizes.size()!=0){
                        code += "\timull\t$4,\t%ebx\n";
                        code += "\tsubl\t%ebx,\t%eax\n";
                    }
                    else{
                        code += "\tsubl\t%ebx,\t%eax\n";
                    }
                }
                else if(operator_info == "MULT_INT"){
                    code += "\timull\t%ebx,\t%eax\n";
                }
                else if(operator_info == "DIV_INT"){
                    code += "\tcltd\n";
                    code += "\tidivl\t%ebx\n";
                }
                else if(operator_info == "GT_OP_INT"){
                    code += "\tcmpl\t%ebx,\t%eax\n";
                    code += "\tsetg\t%al\n";
                    code += "\tmovzbl\t%al,\t%eax\n";
                }
                else if(operator_info == "LT_OP_INT"){
                    code += "\tcmpl\t%ebx,\t%eax\n";
                    code += "\tsetl\t%al\n";
                    code += "\tmovzbl\t%al,\t%eax\n";
                }
                else if(operator_info == "GE_OP_INT"){
                    code += "\tcmpl\t%ebx,\t%eax\n";
                    code += "\tsetge\t%al\n";
                    code += "\tmovzbl\t%al,\t%eax\n";
                }
                else if(operator_info == "LE_OP_INT"){
                    code += "\tcmpl\t%ebx,\t%eax\n";
                    code += "\tsetle\t%al\n";
                    code += "\tmovzbl\t%al,\t%eax\n";
                }
                else if(operator_info == "EQ_OP_INT"){
                    code += "\tcmpl\t%eax,\t%ebx\n";
                    code += "\tsete\t%al\n";
                    code += "\tmovzbl\t%al,\t%eax\n";
                }
                else if(operator_info == "NE_OP_INT"){
                    code += "\tcmpl\t%eax,\t%ebx\n";
                    code += "\tsetne\t%al\n";
                    code += "\tmovzbl\t%al,\t%eax\n";
                }
            }
            

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
        }

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            if(operator_info == "UMINUS"){
                astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tnegl\t%eax\n";
            }
            else if(operator_info == "NOT"){
                astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tcmpl\t$0,\t%eax\n";
                code += "\tsete\t%al\n";
                code += "\tmovzbl\t%al,\t%eax\n";
            }
            else if(operator_info == "PP"){
                Type type = astnode->type;

                if(type.pointer_level != 0 || type.arr_ptr !=0 || type.sizes.size() != 0){
                    astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                    code += "\tpushl\t%eax\n";
                    astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);
                    if(type.type_name.compare(0,6,"Struct")==0){
                        int size = gst.Entries[type.type_name].size;
                        code += "\taddl\t$" + to_string(size) + ",\t(%eax)\n";
                    }
                    else{
                        code += "\taddl\t$4,\t(%eax)\n";
                    }
                    code += "\tpopl\t%eax\n";
                }
                else{
                    astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                    code += "\tpushl\t%eax\n";
                    astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);
                    code += "\taddl\t$1,\t(%eax)\n";
                    code += "\tpopl\t%eax\n";
                }
                

            }
            else if(operator_info == "ADDRESS"){
                astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);
            }
            else if(operator_info == "DEREF"){
                string type = astnode->type.type_name;

                if(type.compare(0,6,"struct")==0){
                    astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);
                    
                    int size = gst.Entries[astnode->type.type_name].size;
                    int iter = size/4;

                    for (int i=0; i<iter; i++){
                        code += "\tmovl\t(%eax),\t%ebx\n";
                        code += "\tpushl\t%ebx\n";
                        code += "\taddl\t$4,\t%eax\n";
                    }
                }
                else{
                    astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                    code += "\tmovl\t(%eax),\t%eax\n";
                }
            }
        }

        void addr(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            if(lhs_astnode->type.type_name.compare(0,6,"struct")==0){
                rhs_astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                lhs_astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);

                int size = gst.Entries[lhs_astnode->type.type_name].size;
                int iter = size/4;

                for (int i=0; i<iter; i++){
                    code += "\tpopl\t%ebx\n";
                    code += "\tmovl\t%ebx,\t(%eax)\n";
                    code += "\taddl\t$4,\t%eax\n";
                }
            }
            else{
                rhs_astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tpushl\t%eax\n";
            
                lhs_astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tpopl\t%ebx\n";
                code += "\tmovl\t%ebx,\t(%eax)\n";
            }
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            string type = gst.Entries[fname->id_astnode].ret_type.type_name; 
            int size = gst.Entries[type].size;
            //params_size = 4*vec_exps.size();
            //cout << type;
            params = 0;

            if(type.compare(0,6,"struct")==0){
                code += "\tsubl\t$"+to_string(size)+",\t%esp\n"; //allocate space for 
            }
        
            for(unsigned int i=0 ; i<vec_exps.size(); i++){
                vec_exps[i]->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
                code += "\tpushl\t%eax\n";
                if(type.compare(0,6,"struct")==0){
                    params += gst.Entries[type].size; //allocate space for 
                }
                else{
                    params += 4;
                }
            }
            code += "\tcall\t" + fname->id_astnode+"\n";
            //code += "\taddl\t$"+to_string(4*vec_exps.size())+",\t%esp\n";
            code += "\taddl\t$"+to_string(params)+",\t%esp\n";
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
             
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            //cout <<"Intconst";
            code += "\tmovl\t$"+to_string(int_val)+",\t%eax\n";
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
		    //cout<<"Stringastnode\n";
            readonly.push_back(".LC"+to_string(ro_label)+":");
		    readonly.push_back("\t.string	"+str_val);
            code += "\tpushl\t$.LC"+to_string(ro_label)+"\n";
            ro_label ++;
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            // cout << astnode->astnode_type == identifier_astype;
            // cout << id_astnode->astnode_type;
            astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);
            string type = astnode->type.type_name;
            LocalSymbTab* struct_st = gst.Entries[type].symbtab;
            
            int offset = 0;
            for (auto e : struct_st->table){
                if(e.symname == id_astnode->id_astnode){
                    offset = e.offset; 
                    // if(e.type.compare(0,6,"struct")==0){
                        
                    // }
                    code += "\tmovl\t"+to_string(offset)+"(%eax), %eax\n";
                }
            }
        }

        void addr(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size)
        {
            astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);
            string type = astnode->type.type_name;
            LocalSymbTab* struct_st = gst.Entries[type].symbtab;
            
            int offset = 0;
            for (auto e : struct_st->table){
                if(e.symname == id_astnode->id_astnode){
                    offset = e.offset;
                    code += "\taddl\t$" + to_string(offset) + ",\t%eax\n";
                }
            }
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size);

            code += "\tmovl\t(%eax),\t%eax\n";

            string type = astnode->type.type_name;
            LocalSymbTab* struct_st = gst.Entries[type].symbtab;
            
            int offset = 0;
            for (auto e : struct_st->table){
                if(e.symname == id_astnode->id_astnode){
                    offset = e.offset;
                    code += "\tmovl\t" + to_string(offset) + "(%eax),\t%eax\n";
                }
            }
        }

        void addr(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size)
        {
            astnode->gencode(code, gst, curr_st, curr, readonly, ro_label, param_size);
            string type = astnode->type.type_name;
            LocalSymbTab* struct_st = gst.Entries[type].symbtab;
            
            int offset = 0;
            for (auto e : struct_st->table){
                if(e.symname == id_astnode->id_astnode){
                    offset = e.offset;
                    code += "\taddl\t$" + to_string(offset) + ",\t%eax\n";
                }
            }
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

        void gencode(string& code, SymbTab gst, LocalSymbTab* curr_st, string curr, vector<string> &readonly, int& ro_label, int param_size){
            // arr_astnode->addr(code, gst, curr_st, curr, readonly, ro_label, param_size); 
            // for (auto e: curr_st->table){
            //     if(e.symname == )
            // }
        }
};

struct nType{
    abstract_astnode* ast;
    vector<exp_astnode*> vec_expr;
    string op;
};

#endif