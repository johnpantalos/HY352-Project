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
    if (Helper == 0) {
        this->array.push_back(this->GetNumberInt());
		obj1.setName(this->GetName());
        Helper++;
        std::cout << obj1.Name;
	    // AddToVector(obj1.GetName(),*this);
    }
	this->array.push_back(obj1.GetNumberInt());
	obj1.setName(this->GetName());
    // CollectionVariables.begin()->second.array.push_back(obj1);
    return *this;
}

std::ostream &operator<<(std::ostream &os, Json_Type &probj){
        std::list<Json_Type> list;
        list=probj.GetDataobj();
    //     for (auto &i:list) {
    //         os << &i << std::endl;
    //     }
    //     for(int i=0;i<probj.GetDataobj().size(); i++) {
    //      if(probj.GetDataobj()[i].GetFlag() == 1){
    //         std::cout << probj.GetDataobj()[i].GetString();
    //    }else if(probj.GetDataobj()[i].GetFlag() == 2){
    //         std::cout << probj.GetDataobj()[i].GetNumberInt();
    //    }else if(probj.GetDataobj()[i].GetFlag() == 3){
    //         std::cout << probj.GetDataobj()[i].GetNumberDouble();
    //     }else if(probj.GetDataobj()[i].GetFlag() == 5){
    //             for(int k = 0; i < probj.GetDataobj()[i].array.size(); j++){
    //                  std:: cout << k << ") " << probj.GetDataobj()[i].array[k];
    //               }
    //          }
    //     }
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
