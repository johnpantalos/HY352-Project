#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#ifndef json_lib_h
#define json_lib_h
#define JSON(var)            \
    ;                        \
    Json_Type var;           \
    var.setName(#var);       \
    AddToVector(#var, &var); \
    var
#define STRING(name) Json_Type(tmp = name)
#define NUMBER(num) Json_Type(num)
#define ARRAY Json_Type(TMParray)
#define OBJECT Json_Type(TMPobj)

#define TRUE Json_Type(true)
#define FALSE Json_Type(false)
#define NULL Json_Type(nullptr)
#define PROGRAM_BEGIN                            \
    int main()                                   \
    {                                            \
        std::string tmp;                         \
        Json_Type mytmp("Variable");             \
        std::map<std::string, Json_Type> TMPobj; \
        std::vector<Json_Type> TMParray;

#define PROGRAM_END \
    ;               \
    return 0;       \
    }

// template <typename T>
// ostream& operator<<(ostream& os, const vector<T>& v)
// {
//     os << "[";
//     for (int i = 0; i < v.size(); ++i) {
//         os << v[i];
//         if (i != v.size() - 1)
//             os << ", ";
//     }
//     os << "]\n";
//     return os;
// }
// STO SET THA MPOREI NA KANEI FIND MESA SE ENA VECTOR OLA TA ONOMATA TWN METAVLHTVN

//#define add_and_print(keyword) alpha_token_t *temp_token = static_cast<alpha_token_t*>(ylval);\
//                temp_token = new alpha_token_t(yylineno, alpha_token_list.size() + 1, (std::string)yytext, (std::string)#keyword);\
//                alpha_token_list.push_front(temp_token);\
//            temp_token->print_token();
//#define add_and_print_nested(keyword) temp_token2 = new alpha_token_t(yylineno, alpha_token_list.size() + 1, (std::string)yytext, (std::string)#keyword);\
//                alpha_token_list.push_front(temp_token2);\
//            temp_token2->print_token();
// #undef add_and_print
// #define add_and_print(x) return x;
// #undef add_and_print_nested
// #define add_and_print_nested(x)
// #define print_rule(left, right) std::cout << "\033[1;32m LINE " << yylineno << ": " << #right  << " --> " << #left << "\033[0m" << std::endl

int i = 0;

struct Json_Type
{

private:
    int flag = 10;
    std::string Name = "";
    bool boolean = false; // True, False
    int *ptr = nullptr;   // null
    std::string string = "";
    int numberInt = 77777;
    double numberDouble = 77777.0;
    std::map<std::string, Json_Type> dataobj;
    std::vector<Json_Type> array;

public:
    Json_Type() { this->flag = 0; }

    Json_Type(const std::string &str) : string(str) { this->flag = 1; }

    Json_Type(const int intNum) : numberInt(intNum) { this->flag = 2; }

    Json_Type(const double DoubleNum) : numberDouble(DoubleNum) { this->flag = 3; }

    Json_Type(std::map<std::string, Json_Type> Object) : dataobj(Object)
    {
        this->dataobj.insert(std::pair<std::string, Json_Type>("Main Object", this));
        this->flag = 4;
    }

    Json_Type(std::vector<Json_Type> Array)
    {
        this->flag = 5;
        this->array.push_back(this);
    }

    Json_Type(bool Boolean) : boolean(Boolean) { this->flag = 6; }

    void setName(std::string name)
    {
        this->Name = name;
    }

    void setString(std::string String)
    {
        this->string = String;
    }

    void setInt(int NumberInt)
    {
        this->numberInt = NumberInt;
    }

    void setdouble(double DoubleNum)
    {
        this->numberDouble = DoubleNum;
    }

    void setBool(bool Boolean)
    {
        this->boolean = Boolean;
    }

    void setObject(std::map<std::string, Json_Type> Dataobj)
    {
        this->dataobj = Dataobj;
    }

    void setArray(std::vector<Json_Type> Array)
    {
        this->array = Array;
    }

    void setFlag(int Flag)
    {
        this->flag = Flag;
    }

    int GetFlag()
    {
        return this->flag;
    }

    std::string GetName()
    {
        return this->Name;
    }

    std::string GetString()
    {
        return this->string;
    }

    int GetNumberInt()
    {
        return this->numberInt;
    }

    double GetNumberDouble()
    {
        return this->numberDouble;
    }

    double GetBool()
    {
        return this->boolean;
    }

    std::map<std::string, Json_Type> GetDataobj()
    {
        return this->dataobj;
    }

    std::vector<Json_Type> GetArray()
    {
        return this->array;
    }

    // JSON(MONTHS) = ARRAY[JUNE, JULE,AUGUST]

    // std::string& operator[](Json_Type *obj);
    Json_Type &operator=(Json_Type *obj)
    {
        // std::cout << this->GetName() << "\n";
        obj->setName(this->GetName());
        if (obj->GetFlag() == 1)
        {
            string = obj->string;
            this->setString(string);
        }
        else if (obj->GetFlag() == 2)
        {
            numberInt = obj->numberInt;
            this->setInt(numberInt);
        }
        else if (obj->GetFlag() == 3)
        {
            numberDouble = obj->numberDouble;
            this->setdouble(numberDouble);
        }
        else if (obj->GetFlag() == 4)
        {
            dataobj = obj->dataobj;
            this->setObject(dataobj);
        }
        else if (obj->GetFlag() == 5)
        {
            array = obj->array;
            this->setArray(array);
        }
        else if (obj->GetFlag() == 6)
        {
            boolean = obj->boolean;
        }
        // std::cout << obj.GetName() << "\n";

        return *obj;
    }

    Json_Type operator[](Json_Type obj);
    Json_Type operator[](Json_Type *obj);
    Json_Type &operator,(Json_Type obj1);
};

std::map<std::string, Json_Type> CollectionVariables;
Json_Type Json_Type::operator[](Json_Type obj)
{
    i = 0;
    // std::cout << obj.GetNumberInt();
    std::cout << obj.GetName();
    return obj;
};
Json_Type Json_Type::operator[](Json_Type *obj)
{
    i = 0;
    //  std::cout << obj.GetNumberInt();
    std::cout << obj->GetName();
    return obj;
};
Json_Type &Json_Type::operator,(Json_Type obj1)
{
    Json_Type temp = new Json_Type();
    temp.setArray(obj1.GetArray());
    temp.setName(obj1.GetName());
    temp.setString(obj1.GetString());
    temp.setInt(obj1.GetNumberInt());
    temp.setdouble(obj1.GetNumberDouble());
    temp.setArray(obj1.GetArray());
    temp.setBool(obj1.GetBool());
    temp.setObject(obj1.GetDataobj());

    auto it = CollectionVariables.end();
    it--;

    if (i == 0)
    {
        it->second.array.push_back(*this);
        i++;
    }

    it->second.array.push_back(obj1);
    obj1.Name=it->first;
    for (int j = 0; j < it->second.array.size(); j++)
    {
        if (it->second.array.at(j).GetNumberInt() != 77777)
        {
            std::cout << it->second.array.at(j).GetNumberInt() << "\n";
        }
        if (it->second.array.at(j).GetString() != "")
        {
            std::cout << it->second.array.at(j).GetString() << "\n";
        }
    }
    //  std::cout << it->first << "\n";
    

    return *this;
};

// 1->string
// 2->numbInt
// 3->numbDouble
// 4->bool
// 5->array
// 6,7->object

void AddToVector(std::string(NameVar), Json_Type variable)
{

    CollectionVariables.insert(std::pair<std::string, Json_Type>(NameVar, variable));

    for (auto &elem : CollectionVariables)
    {
        // std::cout << elem.first << "\n";
    }
}

// template<typename T> T& Json_Type::operator[](T elem)
//{
//     std::string elements = elem;
//     std::cout << elem;
//
//
//     return elements;
//     /*this->array.push_back(obj);
//     for (size_t i = 0; i < array.size(); ++i)
//     {
//         std::cout << array[i] << ' ';
//     }
//     return *this;*/
//     // or  return *obj;
// }

#endif