#include "json_lib.h"

int Helper = 0;
std::unordered_map<std::string, Json_Type> CollectionVariables;

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
std::ostream &operator<<(std::ostream &os, Json_Type &probj){
    std::list<Json_Type> list;
    Json_Type it_prev;
    list = probj.GetDataobj();
    //if(probj.GetFlag()==4)
    if(!list.empty()){
        for(auto &it:list){
            
             os<<it<<std::endl;
            if(it.GetFlag()==1){
                os<< "String of " << it.GetKey() << " is : " << it.GetString() << "\n";
            }if(it.GetFlag()==2){
                os << "Number of " << it.GetString() << " is : " << it.GetNumberInt();
            }
            if(it.GetFlag()==3){
                os << "Number of " << it.GetString() << " is : " << it.GetNumberDouble();
            }
            if(it.GetFlag()==5){
                // os << "Array of " << it.GetName() << " has :\n";
                // for (int i = 0; i < it.GetArray().size(); i++) {
                // os << "Index " << i << it.GetArray()[i];
                // }
            }
            it_prev = it;
        }
    }else{
        if(probj.GetFlag()==1) {
             os<< "String of " << probj.GetName() << " is : " << probj.GetString() << "\n";
        }
        else if(probj.GetFlag()==2) {
             os << probj.GetName() << " : " << probj.GetNumberInt() << "\n";
        }
        else if(probj.GetFlag()==3){
             os << probj.GetNumberDouble() << " ";
        }
        else if(probj.GetFlag()==5){
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
