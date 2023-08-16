#ifndef SYMTAB_H
#define SYMTAB_H


#include <string>
#include <deque>
#include <map>
#include <algorithm>
#include "type.hh"

using namespace std;



class SymbolTableRow2{
    public:
        string symname;
        string type; //"fun", "struct", "var"
        string scope; // "global", "local", "param"
        int size;
        int offset; //"-" for struct
        Type ret_type; //"-" for struct
        SymbolTableRow2(string sym_name, string type, string scope, int size, int offset, Type ret_type);
};


class LocalSymbTab{
    public:
        deque<SymbolTableRow2> table;

    LocalSymbTab();

    Type vartype(string symname)
    {
        for (const auto entry : table)
        {
            if(entry.symname == symname)
            {
                return entry.ret_type;
            }
       }
       return Type("-",0,vector<int>());
    }
    void print(){
        sort(table.begin(),table.end(),[](SymbolTableRow2 r1, SymbolTableRow2 r2){return r1.symname < r2.symname ;});
        cout<<"[\n";
        for (const auto entry : table)
        {
            string temp = entry.ret_type.type_name;
            for(int i=0; i<entry.ret_type.pointer_level; i++){ temp += "*";}
            for(auto i:entry.ret_type.sizes){temp+= "["+to_string(i)+"]";}
            cout<<"[\""<<entry.symname<<"\",         \""<<entry.type<<"\",         \""<<entry.scope<<"\",       "<<entry.size<<",       "<<entry.offset<<",\""<<temp<<"\"\n]";
            if(entry.symname == table.back().symname)
            {
                cout<<"\n";
            }
            else{
                cout<<"\n,\n";
            }
       }
        cout<<"]\n";
    }

}; 



class SymbolTableRow{
    public:
        string symname;
        string type; //"fun", "struct", "var"
        string scope; // "global", "local", "param"
        int size;
        int offset; //"-" for struct
        Type ret_type; //"-" for struct
        LocalSymbTab *symbtab;
        SymbolTableRow(string sym_name, string type, string scope, int size, int offset, Type ret_type, LocalSymbTab* symbtab);
        SymbolTableRow(){};
};

class SymbTab{
    public:
        map<string, SymbolTableRow> Entries;

    SymbTab();

    void printgst(){
        cout<<"[";
        for (const auto &e : Entries)
        {
            SymbolTableRow entry = e.second;
            string temp = entry.ret_type.type_name;
            if(entry.offset == -1){
                cout<<"[         \""<<entry.symname<<"\",         \""<<entry.type<<"\",         \""<<entry.scope<<"\",       "<<entry.size<<",       \""<<"-"<<"\",\""<<temp<<"\"\n]";
            }
            else{cout<<"[         \""<<entry.symname<<"\",         \""<<entry.type<<"\",         \""<<entry.scope<<"\",       "<<entry.size<<",       "<<"0"<<",\""<<temp<<"\"\n]";
            }
            if(e.first == (--Entries.end())->first)
            {
                cout<<"\n";
            }
            else{cout<<",\n";}
        }
        cout<<"]\n";
    }

}; 



#endif