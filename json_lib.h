#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#ifndef json_lib_h
#define json_lib_h

struct Json_Type{
    public:
        std::string Name;

        public Json_Type(std::string name) {
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

    public Number(int intNum) {
        this->numberInt = intNum;
    }

    public Number(float floatNum) {
        this->numberFloat = floatNum;
    }
};

class Object : Values
{
     std::vector<Json_Type> dataobj;

}; 

class Array : Values
{
     std::vector<float> array;
};




#endif
