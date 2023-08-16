#include "symbtab.hh"

SymbolTableRow::SymbolTableRow(string sym_name, string type, string scope, int size, int offset, Type ret_type, LocalSymbTab *symbtab){
    this->symname = sym_name;
    this->type = type;
    this->scope = scope;
    this->size = size;
    this->offset = offset;
    this->ret_type = ret_type;
    this->symbtab = symbtab;
};

SymbolTableRow2::SymbolTableRow2(string sym_name, string type, string scope, int size, int offset, Type ret_type){
    this->symname = sym_name;
    this->type = type;
    this->scope = scope;
    this->size = size;
    this->offset = offset;
    this->ret_type = ret_type;
};

SymbTab::SymbTab(){};

LocalSymbTab::LocalSymbTab(){};

