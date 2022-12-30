#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#ifndef json_lib_h
#define json_lib_h
#define JSON(var) Json_Type *var
#define STRING(name) new Json_Type("name") 

// #define NUMBER new Json_Type
#define NUMBER(num) new Json_Type(num)

/*std::vector<Json_Type> */
#define OBJECT{Object} *new Json_Type(Object)

/*std::vector<Json_Type> */
#define ARRAY new Json_Type(array)[]

#define TRUE true
#define FALSE false
#define NULL std::nullptr_t nullptr
#define PROGRAM_BEGIN int main(){ std::string member = "MEMBERS"; std::string tmp; Json_Type mytmp("Variable")
#define PROGRAM_END ;return 0;}

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
    int* ptr= nullptr; // null
    std::string string = "";
    int numberInt = 77777;
    double numberDouble = 77777.0;
    std::map<std::string, Json_Type> dataobj;
    std::vector<Json_Type> array;

public:
    Json_Type(){}
    Json_Type(std::string str) {
        this->string = str;
    }

    Json_Type(int intNum) {
        this->numberInt = intNum;
    }

    Json_Type(double DoubleNum) {
        this->numberDouble = DoubleNum;
    }

    Json_Type(std::map<std::string,Json_Type> Object) {
        this->dataobj = Object;
    }

    Json_Type(std::vector<Json_Type> Array) {
        this->array = Array;
    }

    void setName(std::string name) {
        this->Name = name;
    }

    void setString(std::string String) {
        this->string = String;
    }

    void setInt(int Number) {
        this->numberInt = Number;
    }

    void setdouble(float DoubleNum) {
        this->numberDouble = DoubleNum;
    }

    void setObject(std::map<std::string, Json_Type> Dataobj) {
        this->dataobj = Dataobj;
    }

    void setArray(std::vector<Json_Type> Array) {
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

    std::vector<Json_Type> GetArray() {
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


    //ARRAY --> Json_Type(std::vector<double> array);
    // 
    //JSON(week_temperatures) = ARRAY[ NUMBER(20) ]
    Json_Type& operator[](Json_Type obj)
    {
        this->array.push_back(obj);
        return *this;
    }
    
    int i = 0;
    //JSON(week_temperatures) = ARRAY[ NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20), NUMBER(19), NUMBER(18.5), NUMBER(19) ]
    Json_Type& operator,(Json_Type obj1/*, Json_Type* obj2*/)
    {
        if (i == 0) {
            this->array.push_back(*this);
            i++;
        }
        this->array.push_back(obj1);
        
        return *this;
    }

};

//class Values
//{
//public:
//
//};
//
//class String : Values
//{
//public:
//
//};
//
//class Number : Values
//{
//public:
//};
//
//class Object : Values
//{
//public:
//}; 
//
//class Array : Values
//{
//public:
//};


#endif
