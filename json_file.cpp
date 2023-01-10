#include "json_lib.h"

int Helper = 0;
std::unordered_map<std::string, Json_Type> CollectionVariables;

Json_Type Json_Type::operator[](Json_Type obj)
{
    std::cout << "\n[]\n";
    Helper = 0;
    this->setArray(obj.array);
    
    //this->setName(CurrName);
    //obj.setName(CurrName);
    //AddToVector(this->GetName(), *this);
    //std::cout << this->GetName();
    // auto it = CollectionVariables.begin();
    // for (int j = 0; j < it->second.array.size(); j++)
    // {
    //     std::cout << it->second.array.at(j).GetNumberInt() << "\n";
    // }
    for(int i=0;i<obj.GetArray().size();i++){
        std::cout<<obj.GetNumberInt()<<"\n";
    }
     std::cout<<this->GetNumberInt()<< ";a;a\n";
    std::cout<<obj.GetNumberInt()<< ";a;a\n";
    AddToVector(this->GetName(),*this);
                                                           //  AddToVector(CurrName, it->second);
    // it->second = *this;
    return *this;
};


//JSON(week_temperatures2) = ARRAY[NUMBER(20), NUMBER(19), NUMBER(18), NUMBER(17), NUMBER(16), NUMBER(15), NUMBER(14)]

Json_Type Json_Type::operator,(Json_Type obj1)
{
    std::cout << "\n,,,\n";
    //std::cout << it->first;
    Json_Type temp;
    temp.array=obj1.GetArray();
    temp.numberDouble=obj1.GetNumberDouble();
    temp.numberInt=obj1.GetNumberInt();
    temp.string=obj1.GetString();
    temp.boolean=obj1.GetBool();
    temp.dataobj=obj1.GetDataobj();
    temp.flag=obj1.GetFlag();
    temp.Name=obj1.GetName();
    if (Helper == 0) {
        this->array.push_back(*this);
        //std::cout << this->GetNumberInt() << " ";
        Helper++;
    }

    this->array.push_back(obj1);
    //std::cout << this->GetNumberInt() << " ";
    //for (int j = 0; j < this->array.size(); j++)
    //{
    //    std::cout << this->array.at(j).GetNumberInt() << "\n";
    //}
    
    //                                                                          it->second.array.push_back(temp);
    //std::cout << obj1.GetNumberInt() << " ";
//    for (int j = 0; j < it->second.array.size(); j++)
//     {
//        std::cout << it->second.array.at(j).GetNumberInt() << "\n";
//     }
    // std::cout << it->first << "\n";
    // std::cout<<obj1.GetName()<<"okok"; 
    
    return obj1;
}

inline void Json_Type::AddToVector(std::string(NameVar), Json_Type variable)
{
    CollectionVariables.insert(std::pair<std::string, Json_Type>(NameVar, variable));

    for (auto& elem : CollectionVariables)
    {
        //std::cout << elem.first << "\n";
        //std::cout << elem.second.GetString() << std::endl;

        if (elem.first == "empObj3") {
            for (int j = 0; j < elem.second.array.size(); j++)
            {

                //std::cout << elem.first << "\n";
                //std::cout << "\n" << elem.second.array.at(j).GetNumberInt();
            }
        }
    }
};
bool Json_Type::IS_EMPTY(){
        if(this->flag == 5){
            if(this->array.size() == 0){
                return true;
            }else{
                return false;
            }
        }else if(this->flag==4){
            if(this->dataobj.size() == 0){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
}

 std::string Json_Type::TYPE_OF(){

        if(this->flag == 1){
            return "string";
        }else if(this->flag == 2 || this->flag == 3){
            return "number";
        }else if(this->flag == 4){
            return "object";
        }else if(this->flag == 5){
            return "array";
        }else{
            return "NULL";
        }

    }


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
