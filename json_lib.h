#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#ifndef json_lib_h
#define json_lib_h

struct Json_Type{

    private:
    std::vector<float> array;
    std::vector<Json_Type> dataobj; // or map?
    int number;
    bool expression;
    std::string name_expr;
    public:
    Json_Type(std::string stringExpr){

    }
    Json_Type(bool expression){

    }
    Json_Type(int number){

    }
    Json_Type(std::vector<Json_Type> Object){

    }
    Json_Type(std::vector<float> array){

    }
    void setName(std::string Name){
        this->name_expr=Name;
    }
    void setArray(std::vector<float> Table){
        this->array=Table;
    }
    void setDataObject(std::vector<Json_Type> Data){
        this->dataobj=Data;
    }
    std::string getName(){
        return this->name_expr;
    }
    std::vector<float> getArray(){
        return this->array;
    }
    std::vector<Json_Type> getDataObj(){
        return this->dataobj;
    }

    bool is_Empty(){
        if(this->getArray().size()==0 && this->getDataObj().size()==0
            && this->getName()==""){
                return true;
        }else{
            return false;
        }
    }

};

class Values
{
    public:
        bool boolean; // True, False
        int* ptr; // null
};

class String : Values
{

};

class Number : Values
{

};

class Object : Values
{

}; 

class Array : Values
{

};




#endif