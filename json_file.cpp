#include "json_lib.h"

int Helper = 0;
std::unordered_map<std::string, Json_Type> CollectionVariables;
// Json_Type Json_Type::operator[](const char* expression){
//     std::string exp=expression;
//     std::list<Json_Type> list;
//     list = probj.GetDataobj();
//     for(auto &it:list){
//         if()
//     }

//  }
Json_Type Json_Type::operator[](Json_Type obj)
{
    Helper = 0;
    this->setArray(obj.array);
    
    return *this;
};

Json_Type Json_Type::operator,(Json_Type obj1)
{
    if (this->GetFlag() == 4)
    {
        if (obj1.GetFlag() == 1)
        {
            obj1.setKey(obj1.GetString());
            this->dataobj.push_back(obj1.GetString());
        }
        else if (obj1.GetFlag() == 2)
        {
            this->dataobj.push_back(obj1.GetNumberInt());
        }
        else if (obj1.GetFlag() == 3)
        {
            this->dataobj.push_back(obj1.GetNumberDouble());
        }
        else if (obj1.GetArray().size() != 0 || obj1.GetFlag() == 5)
        {
            for (int i = 0; i < obj1.GetArray().size(); i++)
            {
                this->dataobj.push_back(obj1.GetArray()[i]);
            }
        }
    }else{
        if (Helper == 0)
        {
            this->array.push_back(this->GetNumberInt());
            obj1.setName(this->GetName());
            Helper++;
            std::cout << obj1.Name;
            // AddToVector(obj1.GetName(),*this);
            
        }
        this->array.push_back(obj1.GetNumberInt());
        // obj1.setName(this->GetName());
    }
    obj1.setName(this->GetName());
    // CollectionVariables.begin()->second.array.push_back(obj1);
    return *this;
}

int washere=0;
std::ostream &operator<<(std::ostream &os, Json_Type &probj){
    std::list<Json_Type> list;
    list = probj.GetDataobj();
    if(!list.empty() && probj.GetFlag()==4) {
        if (washere==0) {
            os << "Object " << probj.GetName() << " has :" << "\n";
            washere=1;
        }
        for(auto &it:list){
            os<<it<<std::endl;
            if(it.GetFlag()==1) {
                os<< "    String of " << it.GetKey() << " is : " << it.GetString() << "\n";
            }if(it.GetFlag()==2) {
                os << "    Number of " << it.GetString() << " is : " << it.GetNumberInt() << "\n";
            }
            if(it.GetFlag()==3) {
                os << "    Number of " << it.GetString() << " is : " << it.GetNumberDouble() << "\n";
            }
            if(it.GetFlag()==5) {
                os << "    Array of " << it.GetKey() << " has :\n";
                for (int i = 0; i < it.GetArray().size(); i++) {
                os << "    Index " << i << it.GetArray()[i];
                }
            }
        }
    }
    else
    {
        washere=0;
        if (probj.GetFlag() == 1 && probj.GetKey() == "")
        {
            os << "String of " << probj.GetName() << " is : " << probj.GetString() << "\n";
        }
        else if (probj.GetFlag() == 2 && probj.GetKey() == "")
        {
            os << probj.GetName() << " : " << probj.GetNumberInt() << "\n";
        }
        else if (probj.GetFlag() == 3 && probj.GetKey() == "")
        {
            os << probj.GetNumberDouble() << " ";
        }
        else if (probj.GetFlag() == 5 && probj.GetKey() == "")
        {
            os << "Array of " << probj.GetName() << " has :\n";
            for (int i = 0; i < probj.GetArray().size(); i++) {
                os << "Index " << i << probj.GetArray()[i];
            }
        }
    }
    return os;
}

//inline void Json_Type::AddToVector(std::string(NameVar), Json_Type variable)
//{
//    CollectionVariables.insert(std::pair<std::string, Json_Type>(NameVar, variable));
//
//    //for (auto& elem : CollectionVariables)
//    //{
//    //    //std::cout << elem.first << "\n";
//    //    for (int j = 0; j < elem.second.array.size(); j++)
//    //    {
//    //        std::cout << elem.second.GetArray()[j].GetNumberInt() << "\n";
//    //    }
//    //}
//};
 
std::string Json_Type::ISEMPTY(Json_Type& probj){
    std::string ret;
    if(probj.GetFlag() == 5){
        if(probj.array.size() == 0){
            ret = "Has variable " + probj.GetName() + "empty array? = TRUE\n";
            return ret;
        }else{
            return ret = "Has variable " + probj.GetName() + "empty array? = FALSE\n";
            return ret;
        }
    }else if(probj.GetFlag()==4){
        if(probj.dataobj.size() == 0){
            return ret = "Has variable " + probj.GetName() + " empty object? = TRUE\n";
            return ret;
        }else{
            return ret = "Has variable " + probj.GetName() + " empty object? = FALSE\n";
            return ret;
        }
    }else{
        ret = "Variable " + probj.GetName() + " isn't an array or an object!\n";
        return ret;
    }
}

std::string Json_Type::TYPEOF(Json_Type& probj){
    if(probj.GetFlag() == 1){
        return "string";
    }else if(probj.GetFlag() == 2 || probj.GetFlag() == 3){
        return "number";
    }else if(probj.GetFlag() == 4){
        return "object";
    }else if(probj.GetFlag() == 5){
        return "array";
    }else{
        return "NULL";
    }
}

std::string Json_Type::SIZEOF(Json_Type& probj) {
    std::string ret;
    switch (probj.GetFlag()) {
        case 4:                                                                             
            ret = "Variable " + probj.GetName() + " has an object with size : " + std::to_string(probj.GetDataobj().size()) + "\n";
            return ret;
        case 5:                                                                             
            ret = "Variable " + probj.GetName() + " has an array with size : " + std::to_string(probj.GetArray().size()) + "\n";
            return ret;
        default:                                                                            
            ret = "The size of variable " + probj.GetName() + " is : 1\n";                                  
            return ret;
    }
}

std::string Json_Type::HasKey(Json_Type &variable, std::string key) {
    std::string ret;
    std::list<Json_Type> list;

    list = variable.GetDataobj().begin()->GetDataobj();
    
    //for (auto& it1 : list) std::cout << it1.GetKey();
    if (variable.GetFlag() == 4) {
        for (auto& it : list) {
            if (it.GetKey() == key) 
            {
                //ret = "Key '" + key + "' found at object " + variable.GetName() + "\n";
                ret = "Object " + variable.GetName() + " has key '" + key + "'? TRUE\n";
                return ret;
            }
            else 
            {
                ret = "Key '" + key + "' don't found at object " + variable.GetName() + "\n";
            }
        }
    }
    else
    {
        ret = "The Variable " + variable.GetName() + " is not an object to has a key!";
    }
    return ret;
}
