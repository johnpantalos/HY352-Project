#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#ifndef json_lib_h
#define json_lib_h
#define JSON(var) Json_Type json
#define STRING(name) new String
#define NUMBER(name) new Number
#define OBJECT(name) new Object
#define ARRAY(name) new Array

struct Json_Type{
    public:
        std::string Name;

        public: Json_Type(std::string name) {
            this->Name = name;
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
    public:
        std::string string;

    String(std::string str) {
        this->string = str;
    }
};

class Number : Values
{
    public:
        int numberInt = 0;
        float numberFloat = 0.0;

    public: Number(int intNum) {
        this->numberInt = intNum;
    }

    public: Number(float floatNum) {
        this->numberFloat = floatNum;
    }
};

class Object : Values
{
     std::vector<Json_Type> dataobj;
     public: Object(std::vector<Json_Type> Object){
        this->dataobj=Object;
     }

}; 

class Array : Values
{
     std::vector<float> array;
     public: Array( std::vector<float> Array){
        this->array=Array;
     }
};


#endif
