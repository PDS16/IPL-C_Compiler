
#include "scanner.hh"
#include "parser.tab.hh"
#include "symbtab.hh"
#include "ast.hpp"
#include <string>
#include <fstream>
#include <map>
using namespace std;

SymbTab gst, gstfun, gststruct; 
map<string,statement_astnode*> ast;
extern std::string code;
vector<std::string> codegen;
extern vector<std::string> readonly;
string filename;

int main(int argc, char **argv)
{
	using namespace std;
	fstream in_file, out_file;


	in_file.open(argv[1], ios::in);

	IPL::Scanner scanner(in_file);

	IPL::Parser parser(scanner);

#ifdef YYDEBUG
	parser.set_debug_level(1);
#endif
parser.parse();




for (const auto &entry : gst.Entries)
{
	if (entry.second.type == "fun")
	gstfun.Entries.insert({entry.first, entry.second});
}

for (const auto &entry : gst.Entries)
{
	if (entry.second.type == "struct")
	gststruct.Entries.insert({entry.first, entry.second});
}

//ast["main"]->print(0);


// start the JSON printing

// cout << "{\"globalST\": " << endl;
// gst.printgst();
// cout << "," << endl;

// cout << "  \"structs\": [" << endl;
// for (auto it = gststruct.Entries.begin(); it != gststruct.Entries.end(); ++it)

// {   cout << "{" << endl;
// 	cout << "\"name\": " << "\"" << it->first << "\"," << endl;
// 	cout << "\"localST\": " << endl;
// 	it->second.symbtab->print();
// 	cout << "}" << endl;
// 	if (next(it,1) != gststruct.Entries.end()) 
// 	cout << "," << endl;
// }
// cout << "]," << endl;
// cout << "  \"functions\": [" << endl;

// for (auto it = gstfun.Entries.begin(); it != gstfun.Entries.end(); ++it)

// {
// 	cout << "{" << endl;
// 	cout << "\"name\": " << "\"" << it->first << "\"," << endl;
// 	cout << "\"localST\": " << endl;
// 	it->second.symbtab->print();


// 	//cout << "," << endl;
// 	//cout << "\"ast\": " << endl;
// 	//ast[it->first]->print(0);
// 	cout << "}" << endl;
// 	if (next(it,1) != gstfun.Entries.end()) cout << "," << endl;
	
// }

// 	cout << "]" << endl;
// 	cout << "}" << endl;


cout<<"\t.file\t\""<<argv[1]<<"\"\n";

if(readonly.size()!=0){
	cout << "\t.text\n";
	cout << "\t.section\t.rodata\n";
}



for (auto i: readonly)
{
	cout<<i<<endl;
}

	cout << code ;
	cout << "	.ident	\"GCC: (Ubuntu 8.1.0-9ubuntu1~16.04.york1) 8.1.0\"\n";
	cout << "	.section	.note.GNU-stack,\"\",@progbits\n";
	//cout << "BC";

	fclose(stdout);
}