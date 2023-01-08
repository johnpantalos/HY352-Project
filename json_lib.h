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
    Json_Type var;                         \
    var.setName(#var);                     \
    var

#define STRING(name) Json_Type(name)
#define NUMBER(num) Json_Type(num)
#define ARRAY Json_Type(TMParray)
#define OBJECT Json_Type(TMPobj)
#define TRUE Json_Type(true)
#define FALSE Json_Type(false)
#define NULL Json_Type(nullptr)
#define KEY(name) Json_Type name; AddToVector(#name, name); name = (1>2) ? Json_Type()
#define PRINT ;std::cout <<
#define PROGRAM_BEGIN                            \
    int main()                                   \
    {                                            \
        std::string tmp;                         \
        std::map<std::string, Json_Type> TMPobj; \
        std::vector<Json_Type> TMParray;

#define PROGRAM_END         \
    ;return 0;              \
    }

//#define KEY(name) Json_Type(tmp = #name)
//#define KEY(name) TMPobj.insert(std::pair<<std::string, Json_Type>(#name, mytmp) :               // sto telos tou object    (to diko mou map) = TMPobj; TMPobj = clear()
//#define KEY(name) Json_Type *name = new Json_Type:               // sto telos tou object    (to diko mou map) = TMPobj; TMPobj = clear()
//x = (y < 10) ? 30 : 40;

//JSON(book) = OBJECT{
//
//    KEY(title) : STRING("Gone Girl"),
//    KEY(published) : NUMBER(2012),
//    KEY(type) : STRING("Thriller"),
//    }
//}

int Helper = 0;

struct Json_Type
{
public:
    /*static std::string CurrName;
    static Json_Type CurrJson;*/

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
    Json_Type() { 
        /*CurrJson = *this;
        CurrName = this->GetName();*/
        this->flag = 0; 
    }

    Json_Type(std::string str) : string(str) { /*std::cout << "called 1\n";*/ this->flag = 1; }

    Json_Type(int intNum) : numberInt(intNum) { /*std::cout << "called 2\n";*/ this->flag = 2; }

    Json_Type(double DoubleNum) : numberDouble(DoubleNum) { /*std::cout << "called 3\n";*/ this->flag = 3; }

    Json_Type(std::map<std::string, Json_Type> Object) : dataobj(Object) { /*std::cout << "called 4\n";*/ this->flag = 4; }

    Json_Type(std::vector<Json_Type> Array) { /*std::cout << "called 5\n";*/ this->flag = 5; }

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
    
    void setBool(bool Boolean) {
        this->boolean = Boolean;
    }

    void setObject(std::map<std::string, Json_Type> Dataobj) {
        this->dataobj = Dataobj;
    }

    void setArray(std::vector<Json_Type> Array) {
        this->array = Array;
    }

    void setFlag(int Flag) {
        this->flag = Flag;
    }

    int GetFlag() {
        return this->flag;
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
    
    double GetBool() {
        return this->boolean;
    }

    std::map<std::string, Json_Type> GetDataobj() {
        return this->dataobj;
    }

    std::vector<Json_Type> GetArray() {
        return this->array;
    }

    void AddToVector(std::string(NameVar), Json_Type variable);

    //JSON(LALA) = STRING("P")
    //JSON(LALA1) = NUMBER(10)
    //JSON(LALA2) = ARRAY[NUMBER(9), NUMBER(8)]
    Json_Type operator=(Json_Type obj)
    {
        //std::cout << this->GetName();                             TYPWNEI TO ONOMAA!!
        obj.setName(this->GetName());

        //CurrName = this->GetName();
        switch (obj.GetFlag()) {
            case 1:
                this->setString(obj.string);
                AddToVector(this->GetName(), *this);                                    //                      'H obj          ????????????????
                //std::cout << "1 added to vector\n";
                break;
            case 2:
                this->setInt(obj.numberInt);
                if (obj.numberInt == 1) this->setBool(true);
                else if (obj.numberInt == 0) this->setBool(false);
                AddToVector(this->GetName(), *this);                                    //                      'H obj          ????????????????
                //std::cout << "2 added to vector\n";
                break;
            case 3:
                this->setdouble(obj.numberDouble);
                AddToVector(this->GetName(), *this);                                    //                      'H obj          ????????????????
                //std::cout << "3 added to vector\n";
                break;
            case 4:     // OBJECT
                this->setObject(obj.dataobj);
                AddToVector(this->GetName(), *this);                                    //                      'H obj          ????????????????
                //std::cout << "4 added to vector\n";
                //CurrJson = *this;
                break;
            case 5:     // ARRAY
                this->setArray(obj.array);
                //std::cout << this->GetName();
                AddToVector(this->GetName(), *this);                                    //                      'H obj          ????????????????
                //std::cout << "5 added to vector\n";
                //CurrJson = *this;
                break;
            default:
                AddToVector(this->GetName(), *this);                                    //                      'H obj          ????????????????
                break;
        }
        return obj;

        //if (obj.GetFlag() == 1)
        //{
        //}
        //else if (obj.GetFlag() == 2)
        //{
        //}
        //else if (obj.GetFlag() == 3)
        //{
        //}
        //else if (obj.GetFlag() == 4)        // OBJECT
        //{
        //}
        //else if (obj.GetFlag() == 5)        // ARRAY
        //{
        //    
        //}
    }
    Json_Type operator[](Json_Type obj);

    Json_Type& operator,(Json_Type obj1);
};

std::map<std::string, Json_Type> CollectionVariables;

Json_Type Json_Type::operator[](Json_Type obj)
{
    Helper = 0;
    //this->setName(CurrName);
    //obj.setName(CurrName);
    std::cout << this->GetName();
    
    //                                                              AddToVector(CurrName, it->second);
    return *this;
};

Json_Type& Json_Type::operator,(Json_Type obj1)
{
    Json_Type temp = Json_Type();
    temp.setArray(obj1.GetArray());
    temp.setName(obj1.GetName());
    temp.setString(obj1.GetString());
    temp.setInt(obj1.GetNumberInt());
    temp.setdouble(obj1.GetNumberDouble());
    temp.setArray(obj1.GetArray());
    temp.setBool(obj1.GetBool());
    temp.setObject(obj1.GetDataobj());

    auto it = CollectionVariables.begin();

    std::cout << it->first;

    if (Helper == 0) {
        it->second.array.push_back(*this);
        //std::cout << this->GetNumberInt() << " ";
        Helper++;
    }
    it->second.array.push_back(obj1);
    //                                                                          it->second.array.push_back(temp);
    //std::cout << obj1.GetNumberInt() << " ";
    
    //for (int j = 0; j < it->second.array.size(); j++)
    //{
    //    std::cout << it->second.array.at(j).GetNumberInt() << "\n";
    //}
    //std::cout << it->first << "\n
    //std::cout<<obj1.GetName()<<"okok";
    
    return *this;
}

inline void Json_Type::AddToVector(std::string(NameVar), Json_Type variable)
{
    CollectionVariables.insert(std::pair<std::string, Json_Type>(NameVar, variable));

    for (auto& elem : CollectionVariables)
    {
        //std::cout << elem.first << "\n";
        //std::cout << elem.second.GetString() << std::endl;

        //if (elem.first == "emp2") {
            for (int j = 0; j < elem.second.array.size(); j++)
            {
                std::cout << "\n" << elem.second.array.at(j).GetNumberInt();
            }
        //}
    }
}
;
//std::string Json_Type::CurrName = "None";
//Json_Type Json_Type::CurrJson;


//void AddToVector(std::string(NameVar), Json_Type variable)
//{
//    CollectionVariables.insert(std::pair<std::string, Json_Type>(NameVar, variable));
//
//    for (auto& elem : CollectionVariables)
//    {
//        std::cout << elem.first << "\n";
//        std::cout << elem.second.GetString()<<std::endl;
//        if (elem.first == "empObj2") {
//            std::cout << elem.second.GetString() << std::endl;
//        }
//    }
//}
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
