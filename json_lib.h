#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#ifndef json_lib_h
#define json_lib_h
#define JSON(var) ;Json_Type *var;AddToVector(#var, &var); var
#define STRING(name) new Json_Type(name)
#define NUMBER(num) new Json_Type(num)
#define ARRAY new Json_Type()

//#define ARRAY new Json_Type(std::vector<Json_Type*>Array); week_temperatures2.Array.push_back()           CollectionVariables.find(week_temperatures2)                 

#define OBJECT new Json_Type()

#define TRUE new Json_Type(true);
#define FALSE new Json_Type(false);
#define NULL new Json_Type(nullptr);
#define PROGRAM_BEGIN int main(){ std::string member = "MEMBERS"; std::string tmp; Json_Type mytmp("Variable")
#define PROGRAM_END ;return 0;}


// STO SET THA MPOREI NA KANEI FIND MESA SE ENA VECTOR OLA TA ONOMATA TWN METAVLHTVN


//#define add_and_print(keyword) alpha_token_t *temp_token = static_cast<alpha_token_t*>(ylval);\
//                temp_token = new alpha_token_t(yylineno, alpha_token_list.size() + 1, (std::string)yytext, (std::string)#keyword);\
//                alpha_token_list.push_front(temp_token);\
//            temp_token->print_token();
//#define add_and_print_nested(keyword) temp_token2 = new alpha_token_t(yylineno, alpha_token_list.size() + 1, (std::string)yytext, (std::string)#keyword);\
//                alpha_token_list.push_front(temp_token2);\
//            temp_token2->print_token();
//#undef add_and_print
//#define add_and_print(x) return x;
//#undef add_and_print_nested
//#define add_and_print_nested(x)
//#define print_rule(left, right) std::cout << "\033[1;32m LINE " << yylineno << ": " << #right  << " --> " << #left << "\033[0m" << std::endl

//template<class T> class Json_Type {
//public:
//    std::string Name;
//    friend class Values;
//
//    Json_Type(std::string name) {
//        this->Name = name;
//    }
//    T& operator= (const T& obj)
//    {
//    }
//};

struct Json_Type {

private:
    std::string Name = "";
    bool boolean = false; // True, False
    int* ptr = nullptr; // null
    std::string string = "";
    int numberInt = 77777;
    double numberDouble = 77777.0;
    std::map<std::string, Json_Type> dataobj;
    std::vector<Json_Type*> array;

public:
    Json_Type(){}

    Json_Type(std::string name, std::string str) : string(str), Name(name){}

    Json_Type(int intNum) : numberInt(intNum){}

    Json_Type(double DoubleNum) : numberDouble(DoubleNum){}
    
    Json_Type(std::map<std::string,Json_Type> Object) : dataobj(Object){}

    //JSON(v) = new Json_Type(std::vector<Json_Type*>Array)[NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20), NUMBER(19), NUMBER(18.5), NUMBER(19) ]
    Json_Type(std::vector<Json_Type*>Array){
         array=Array;
    }
    Json_Type(bool Boolean) : boolean(Boolean) {}

    void setName(std::string name) {
        this->Name = name;
    }

    void setString(std::string String) {
        this->string = String;
    }
    
    void setInt(int NumberInt) {
        this->numberInt = NumberInt;
    }

    void setdouble(double DoubleNum) {
        this->numberDouble = DoubleNum;
    }

    void setObject(std::map<std::string, Json_Type> Dataobj) {
        this->dataobj = Dataobj;
    }

    void setArray(std::vector<Json_Type*> Array) {
        this->array = Array;
    }

    std::string GetName() {
        return this->Name;
    }

    std::string GetString() {
        return this->string;
    }

    int GetNumberInt() {
        return this->numberInt;
    }

    double GetNumberDouble() {
        return this->numberDouble;
    }

    std::map<std::string, Json_Type> GetDataobj() {
        return this->dataobj;
    }

    std::vector<Json_Type*> GetArray() {
        return this->array;
    }
    
    Json_Type& operator=(Json_Type *obj){

        if (obj->GetString() != "")
        {
            this->setString(obj->string);
        }
        else if (obj->GetNumberInt() != 77777)
        {
            this->setInt(obj->numberInt);
        }
        else if (obj->GetNumberDouble() != 77777.0)
        {
            this->setdouble(obj->numberDouble);
        }
        else if (obj->dataobj.empty())
        {
            this->setObject(obj->dataobj);
        }
        else if (obj->array.empty())
        {
            this->setArray(obj->array);
        }
        return *this;
    }

    //std::string& operator[](Json_Type *obj);
    Json_Type& operator[](Json_Type *obj);
    Json_Type operator,(Json_Type *obj1);


};
    //Json_Type operator,(Json_Type obj1, Json_Type obj2);

Json_Type Json_Type::operator,(Json_Type *obj1)
{
    Json_Type *temp;
    temp->setName(obj1->GetName());
    temp->setString(obj1->GetString());
    temp->setInt(obj1->GetNumberInt());
    temp->setdouble(obj1->GetNumberDouble());
    temp->setArray(obj1->GetArray());
    std::cout << temp->Name << "\n";
    std::cout << temp->string << "\n";
    std::cout << temp->Name << "\n";
    // temp.setBoolean = obj1.boolean;
    // temp.dataobj=obj1.dataobj;

    //if (i == 0) {
    //    this->array.push_back(*this);
    //    i++;
    //}
    //this->array.push_back(obj1);
    return temp;
}

Json_Type& Json_Type::operator[](Json_Type* obj)
{
    std::cout << obj->GetNumberInt();
    return *this;
}


std::map<std::string, Json_Type> CollectionVariables;

void AddToVector(std::string(NameVar), Json_Type variable) {

    CollectionVariables.insert(std::pair<std::string, Json_Type>(NameVar, variable));

    for (const auto& elem : CollectionVariables)
    {
        std::cout << elem.first << "\n";
    }

}

//template<typename T> T& Json_Type::operator[](T elem)
//{
//    std::string elements = elem;
//    std::cout << elem;
//
//
//    return elements;
//    /*this->array.push_back(obj);
//    for (size_t i = 0; i < array.size(); ++i)
//    {
//        std::cout << array[i] << ' ';
//    }
//    return *this;*/
//    // or  return *obj;
//}

#endif
