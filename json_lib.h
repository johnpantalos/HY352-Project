#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Json_Type{

    private:
    std::vector<float> array;
    std::vector<Json_Type> dataobj; // or map?

    std::string name;
    std::string str;

    public:
    
    void setName(std::string Name){
        this->name=Name;
    }
    void setString(std::string String){
        this->str=String;
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
    std::string getString(){
        return this->str;
    }
    std::vector<float> getArray(){
        return this->array;
    }
    std::vector<Json_Type> getDataObj(){
        return this->dataobj;
    }

    bool is_Empty(){
        if(this->getArray().size()==0 && this->getDataObj().size()==0
            && this->getName()=="" && this->getString()==""){
                return true;
        }else{
            return false;
        }
    }
    
};
