#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
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
#define OBJECT *new Json_Type
#define TRUE Json_Type(true)
#define FALSE Json_Type(false)
#define NULL __null
// #define KEY(name) Json_Type name; AddToVector(#name, name); name = (1>2) ? Json_Type()
#define KEY(name) Json_Type(tmp = #name) = 0 ? 0
#define PRINT ;std::cout <<
#define PROGRAM_BEGIN                            \
    int main()                                   \
    {                                            \
        std::string tmp;                         \
        std::initializer_list<Json_Type>TMPobj; \
        std::vector<Json_Type> TMParray; \
        
#define SIZEOF(var) switch (var.GetFlag()) {                                        \
case 4:                                                                             \
    std::cout << "The size of object is : " << var.GetArray().size() << "\n";       \
case 5:                                                                             \
    std::cout << "The size of array is : " << var.GetDataObj().size() << "\n";      \
    break;                                                                          \
default:                                                                            \
    std::cout << " The size of variable is : 1\n";                                  \
    break;                                                                          \
}                                                                                       

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


// std::string CurrName;
// Json_Type CurrJson;

struct Json_Type
{
public:
 std::string CurrName = "None";
 Json_Type *CurrJson = nullptr;

private:
    int flag = 10;
    std::string Name = "";
    bool boolean = false; // True, False
    int *ptr = nullptr;   // null
    std::string string = "";
    int numberInt = 77777;
    double numberDouble = 77777.0;
    std::list<Json_Type> dataobj;
    std::vector<Json_Type> array;

public:
    Json_Type() { CurrJson = this; this->flag = 0; std::cout << "called 0\n"; };

    Json_Type( std::string str) : string(str) { CurrJson = this;/*std::cout << "called 1\n";*/ this->flag = 1; };

    Json_Type( int intNum) : numberInt(intNum) { CurrJson = this;/*std::cout << "called 2\n";*/ this->flag = 2; };

    Json_Type( double DoubleNum) : numberDouble(DoubleNum) { CurrJson = this;/*std::cout << "called 3\n";*/ this->flag = 3; };

    Json_Type(std::initializer_list <Json_Type> Object)
    {
    std::list<Json_Type>::iterator it;
    it=this->dataobj.begin();
    it=this->dataobj.insert(it,Object);
    /*std::cout << "called 4\n";*/ this->flag = 4; };
    Json_Type(std::vector<Json_Type> Array) {std::cout << "called 5\n"; this->flag = 5; };

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

    void setObject(std::list<Json_Type> Dataobj) {
        this->dataobj = Dataobj;
    }

    void setArray(std::vector<Json_Type> Array) {
        this->array=Array;
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

    std::list<Json_Type> GetDataobj() {
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
       //obj.setName(this->GetName());

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
               break;
           case 5:     // ARRAY
               //this->setArray(obj.array);
            //    for (int j = 0; j < CollectionVariables.begin()->second.GetArray().size(); j++)
            //    {
            //        std::cout << CollectionVariables.begin()->second.GetArray().at(j).GetNumberInt() << "\n";
            //    }
               std::cout << obj.GetName();
               //AddToVector(this->GetName(), *this);                                    //                      'H obj          ????????????????
               std::cout << "5 added to vector\n";
               break;
           default:
               AddToVector(this->GetName(), *this);                                    //                      'H obj          ????????????????
               break;
       }
       return obj;
    }
    Json_Type operator[](Json_Type obj);

    Json_Type operator,(Json_Type obj1);
    bool IS_EMPTY();
    std::string TYPE_OF();
};

#endif


