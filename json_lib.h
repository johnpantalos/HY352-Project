#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#ifndef json_lib_h
#define json_lib_h

struct Json_Type{

   
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
    std::string str;

    String(std::string string) {
        this->str = string;
    }
};

class Number : Values
{
    public:
    std::int number;

    Number(std::int num) {
        this->number = num;
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
