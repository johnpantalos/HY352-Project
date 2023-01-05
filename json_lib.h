#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#ifndef json_lib_h
#define json_lib_h
#define JSON(var)                          \
    ;                                      \
    Json_Type var; var.setName(#var);     \
    AddToVector(#var, &var);               \
    var
#define STRING(name) Json_Type(tmp = name)
#define NUMBER(num) Json_Type(num)
#define ARRAY Json_Type(TMParray)
#define OBJECT Json_Type(TMPobj)
#define KEY(name) Json_Type(tmp = #name)
#define KEY(name) TMPobj.insert(std::pair<<std::string, Json_Type>(#name,                // sto telos tou object    (to diko mou map) = TMPobj; TMPobj = clear()
//#define :
#define TRUE Json_Type(true)
#define FALSE Json_Type(false)
#define NULL Json_Type(nullptr)

#define PRINT ;std::cout <<

#define PROGRAM_BEGIN                \
    int main()                       \
    {                                \
        std::string tmp;             \
        Json_Type mytmp("Variable"); \
        std::map<std::string, Json_Type> TMPobj; \
        std::vector<Json_Type> TMParray;

//JSON(book) = OBJECT{
//
//    KEY(title) : STRING("Gone Girl"),           // isws operator overload to : ??
//    KEY(published) : NUMBER(2012),
//    KEY(type) : STRING("Thriller"),
//    }
//}

#define PROGRAM_END \
    ;               \
    return 0;       \
    }

int Helper = 0;

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
    Json_Type(){ this->flag = 0; }

    Json_Type(const std::string &str) : string(str) { this->flag = 1; }

    Json_Type(const int intNum) : numberInt(intNum) { this->flag = 2; }

    Json_Type(const double DoubleNum) : numberDouble(DoubleNum) { this->flag = 3; }

    Json_Type(std::map<std::string, Json_Type> Object) : dataobj(Object) { 
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
    Json_Type& operator=(Json_Type *obj)
    {
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
        return *obj;
    }

    Json_Type& operator[](Json_Type obj);

    Json_Type& operator,(Json_Type obj1);
};

std::map<std::string, Json_Type> CollectionVariables;

Json_Type& Json_Type::operator[](Json_Type obj)
{
    Helper = 0;
    std::cout << obj.GetName();
    return *this;
};

Json_Type& Json_Type::operator,(Json_Type obj1)
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

    auto it= CollectionVariables.end();
    it--;

    if (Helper == 0) {
        it->second.array.push_back(*this);
        Helper++;
    }

    it->second.array.push_back(obj1);
    
    //for (int j = 0; j < it->second.array.size(); j++)
    //{
    //    std::cout << it->second.array.at(j).GetNumberInt() << "\n";
    //}
    //std::cout << it->first << "\n
    return *this;
};

void AddToVector(std::string(NameVar), Json_Type variable)
{

    CollectionVariables.insert(std::pair<std::string, Json_Type>(NameVar, variable));

    for (auto& elem : CollectionVariables)
    {
        //std::cout << elem.first << "\n";
    }
}

// 1->string
// 2->numbInt
// 3->numbDouble
// 4->bool
// 5->array
// 6,7->object

//OBJECT{
//KEY(title) : STRING("title"),
//KEY(year) : NUMBER(2011)
//}
// 
//
//myType& operator,(myType value) {
//    printerino(value, this);
//
//        if ((value.which == 2 || value.which == 3) && value.name == "") {
//            //it is an array of intigers so goes to array
//            // this->GetArray().size() == 0
//            if (this->isARRAYempty()) {
//                this->array.push_back(this->getINTEGER());
//                this->edited = true;
//            }
//
//            this->array.push_back(value.getINTEGER());
//            this->setWHICH(5);
//        }
//        else if (this->getNAME() != "") {
//            //overloads this with itselfs and value and returns
//
//            myType joker = *this;
//
//            this->clear();
//            this->setWHICH(6);
//            this->setMEMBER(true);
//
//            this->headOFdata.push_back(joker);
//            this->headOFdata.push_back(value);
//
//        }
//        else if (this->getNAME() == "" && value.getNAME() == "") {
//            //overloads this with itsels and value and returns
//
//            myType joker = *this;
//
//            this->clear();
//            this->setWHICH(6);
//            this->setMEMBER(true);
//
//            this->headOFdata.push_back(joker);
//            this->headOFdata.push_back(value);
//        }
//        else {
//            //it is an array of intigers so goes to array
//
//            array.push_back(value.getINTEGER());
//            this->setWHICH(5);
//
//        }
//
//    return *this;
//
//};
// 
// 
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
