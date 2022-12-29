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

    std::string name;
    std::string value;

    public:
    
    void setName(std::string Name){
        this->name=Name;
    }
    void setValue(std::string Value){
        this->value=Value;
    }
    void setArray(std::vector<float> Table){
        this->array=Table;
    }
    void setDataObject(std::vector<Json_Type> Data){
        this->dataobj=Data;
    }
    std::string getName(){
        return this->name;
    }
    std::string getValue(){
        return this->value;
    }
    std::vector<float> getArray(){
        return this->array;
    }
    std::vector<Json_Type> getDataObj(){
        return this->dataobj;
    }

    bool is_Empty(){
        if(this->getArray().size()==0 && this->getDataObj().size()==0
            && this->getName()=="" && this->getValue()==""){
                return true;
        }else{
            return false;
        }
    }

};
#endif