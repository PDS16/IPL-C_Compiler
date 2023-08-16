#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>

using namespace std;


struct Type{
    public:
        string type_name;
        int pointer_level;
        vector<int> sizes;
        bool lvalue = false;
        int arr_ptr;
        Type (string name, int level,vector<int> size_arr){
            this->type_name = name;
            this->pointer_level = level;
            this->sizes = size_arr;
            this->arr_ptr = 0;
        };  
        Type () {};

        bool operator==(const Type& rhs) const {
            return type_name == rhs.type_name && pointer_level == rhs.pointer_level && sizes == rhs.sizes;
        }

        // string StrType(){
        //     string temp1 = this->type_name;
        //     for(int i=0; i<this->pointer_level; i++){ temp1 += "*";}
        //     int start = 0;
        //     if  ( this->arr_ptr == 1){
        //         temp1 += "(*)";
        //         start = 0;
        //     }
        //     else if( this->arr_ptr == 0 && this->sizes.size()>=1){
        //         temp1+="(*)";
        //         start = 1;
        //     }
        //     for(int i=start; this->sizes.size(); i++){temp1+= "["+to_string(i)+"]";
        //     return temp1;
        // }

        // bool isCompatible(Type rhs){
        //     string temp1 = this->StrType();
        //     string temp2 = rhs.StrType();

        //     return(strcmp(temp1, temp2)==0);
        // }



};


#endif