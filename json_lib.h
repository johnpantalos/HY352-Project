#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#ifndef json_lib_h
#define json_lib_h

#define JSON(var) ;Json_Type var; var.setName(#var); var
#define STRING(name) Json_Type(name)
#define NUMBER(num) Json_Type(num)
#define ARRAY Json_Type(TMParray)
#define OBJECT *new Json_Type
#define TRUE Json_Type(true)
#define FALSE Json_Type(false)
#define NULL __null
#define PRINT ;std::cout << "\n" <<
#define HAS_KEY(variable, key) variable.HasKey(variable, key)

#define SIZE_OF(value) ;std::cout << "\n" << value.SIZEOF(value)
#define TYPE_OF(value) ;std::cout << "\n" << "The type of " << \
value.GetName() << " is : " << value.TYPEOF(value) << "\n"
#define IS_EMPTY(value) ;std::cout << "\n" << value.ISEMPTY(value)
#define KEY(name) Json_Type(#name,#name) = (1>2) ? Json_Type() 
// #define KEY(name) Json_Type(tmp = #name) = 0 ? 0

#define PROGRAM_BEGIN                            \
    int main()                                   \
    {                                            \
        std::string tmp;                         \
        std::initializer_list<Json_Type>TMPobj;  \
        std::vector<Json_Type> TMParray; 

#define PROGRAM_END         \
    ;return 0;              \
    }

//#define KEY(name) Json_Type(tmp = #name)
//#define KEY(name) TMPobj.insert(std::pair<<std::string, Json_Type>(#name, mytmp) :               // sto telos tou object    (to diko mou map) = TMPobj; TMPobj = clear()

//JSON(book) = OBJECT{
//
//    KEY(title) : STRING("Gone Girl"),
//    KEY(published) : NUMBER(2012),
//    KEY(type) : STRING("Thriller"),
//    }
//}

struct Json_Type
{

private:
    int flag = 10;
    std::string Name = "";
    std::string key = "";
    bool boolean = false; // True, False
    int* ptr = nullptr;   // null
    std::string string = "";
    int numberInt = 77777;
    double numberDouble = 77777.0;
    std::list<Json_Type> dataobj;
    std::vector<Json_Type> array;

public:
    Json_Type() { this->flag = 0; };

    Json_Type(std::string str) : string(str) { this->flag = 1; };

    Json_Type(std::string key, std::string str) : key(key), string(str) { this->flag = 1; };

    Json_Type(int intNum) : numberInt(intNum) { this->flag = 2; };

    Json_Type(double DoubleNum) : numberDouble(DoubleNum) { this->flag = 3; };

    Json_Type(std::initializer_list <Json_Type> Object)
    {
        //this->key=Key;
        std::list<Json_Type>::iterator it;
        it = this->dataobj.begin();
        it = this->dataobj.insert(it, Object);
        this->flag = 4;
    };
    Json_Type(std::vector<Json_Type> Array) { this->flag = 5; };

    void setName(std::string name) {
        this->Name = name;
    }

    void setKey(std::string Key) {
        this->key = Key;
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
    std::string GetKey(){
        return this->key;
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

    //void AddToVector(std::string(NameVar), Json_Type variable);

    Json_Type operator=(Json_Type obj)
    {
        //std::cout << this->GetName()<<"\n";                             //TYPWNEI TO ONOMAA!!
        // this->setFlag(obj.GetFlag());
        switch (obj.GetFlag()) {
        case 1:
            this->setString(obj.string);
            this->setFlag(1);
            break;
        case 2:
            this->setInt(obj.numberInt);
            if (obj.numberInt == 1) this->setBool(true);
            else if (obj.numberInt == 0) this->setBool(false);
            this->setFlag(2);
            break;
        case 3:
            this->setdouble(obj.numberDouble);
            this->setFlag(3);
            break;
        case 4:     // OBJECT
            this->dataobj.push_back(obj); 
            this->setFlag(4);
            break;
        case 5:     // ARRAY
             for(int i = 0; i < obj.GetArray().size() ; i++){
                this->array.push_back(obj.GetArray()[i]);
             }
            this->setFlag(5);
            break;
        default:
            break;
        }
        return *this;
    }
    Json_Type operator[](Json_Type obj);
    Json_Type operator[](const char* expression);
    Json_Type operator,(Json_Type obj1);

    friend std::ostream &operator<<(std::ostream &os, Json_Type &probj);
    std::string SIZEOF(Json_Type& probj);
    std::string ISEMPTY(Json_Type& probj);
    std::string TYPEOF(Json_Type& probj);
    std::string HasKey(Json_Type& variable, std::string key);
};

#endif
