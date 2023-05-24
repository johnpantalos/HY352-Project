#include "json_lib.h"

int Helper = 0;

Json_Type Json_Type::operator+(Json_Type obj) {
    std::string tmp;
    int tmpnum;
    double tmpdoub;
    std::vector<Json_Type> tmpVec;
    std::list<Json_Type> tmplist;
    if (this->GetFlag() == 1 && obj.GetFlag() == 1) {
        tmp = this->GetString() + obj.GetString();
        this->setString(tmp);
    }
    else if (this->GetFlag() == 2 && obj.GetFlag() == 2) {
        tmpnum = this->GetNumberInt() + obj.GetNumberInt();
        this->setInt(tmpnum);
    }
    else if (this->GetFlag() == 3 && obj.GetFlag() == 3) {
        tmpdoub = this->GetNumberDouble() + obj.GetNumberDouble();
        this->setInt(tmpdoub);
    }
    else if (this->GetFlag() == 4 && obj.GetFlag() == 4) {
        for (auto& it : this->GetDataobj().begin()->GetDataobj()) {
            tmplist.push_back(it);
        }
        for (auto& it : obj.GetDataobj().begin()->GetDataobj()) {
            tmplist.push_back(it);
        }
        this->setObject(tmplist);
    }
    else if (this->GetFlag() == 5 && obj.GetFlag() == 5) {
        for (auto& it : this->GetArray()) {
            tmpVec.push_back(it);
        }
        for (auto& iyi : obj.GetArray()) {
            tmpVec.push_back(iyi);
        }
        this->setArray(tmpVec);
    }
    return *this;
};

Json_Type Json_Type::operator-(Json_Type obj) {
    if(this->GetFlag()==2 && obj.GetFlag()==2){
        this->setInt((int)this->GetNumberInt()-(int)obj.GetNumberInt());
    }else if(this->GetFlag()==3 && obj.GetFlag()==3){
        this->setdouble((double)this->GetNumberDouble()-(double)obj.GetNumberDouble());
    }
    return *this;
};

Json_Type Json_Type::operator*(Json_Type obj) {
    if(this->GetFlag()==2 && obj.GetFlag()==2) {
        this->setInt((int)this->GetNumberInt()*((int)obj.GetNumberInt()));
    }
    else if(this->GetFlag()==3 && obj.GetFlag()==3) {
        this->setdouble((double)this->GetNumberDouble()*((double)obj.GetNumberDouble()));
    }
    return *this;
};

Json_Type Json_Type::operator/(Json_Type obj) {
    if(this->GetFlag()==2 && obj.GetFlag()==2){
        this->setInt((int)this->GetNumberInt()/((int)obj.GetNumberInt()));
    }
    else if(this->GetFlag()==3 && obj.GetFlag()==3){
        this->setdouble((double)this->GetNumberDouble()/((double)obj.GetNumberDouble()));
    }
    return *this;
};

Json_Type Json_Type::operator%(Json_Type obj) {
    if(this->GetFlag()==2 && obj.GetFlag()==2){
        this->setInt((int)this->GetNumberInt()%((int)obj.GetNumberInt()));
    }
    return *this;
};

// < > <= >=
Json_Type Json_Type::operator<(Json_Type obj) {
if(this->GetFlag()==2 && obj.GetFlag()==2){
        this->setInt((int)this->GetNumberInt()<((int)obj.GetNumberInt()));
    }else if(this->GetFlag()==3 && obj.GetFlag()==3){
        this->setdouble((double)this->GetNumberDouble()<((double)obj.GetNumberDouble()));
    }
    return *this;
};

Json_Type Json_Type::operator<=(Json_Type obj) {
    if(this->GetFlag()==2 && obj.GetFlag()==2){
        this->setInt((int)this->GetNumberInt()<=((int)obj.GetNumberInt()));
    }else if(this->GetFlag()==3 && obj.GetFlag()==3){
        this->setdouble((double)this->GetNumberDouble()<=((double)obj.GetNumberDouble()));
    }
    return *this;
};

Json_Type Json_Type::operator>(Json_Type obj) {
    if(this->GetFlag()==2 && obj.GetFlag()==2){
        this->setInt((int)this->GetNumberInt()>((int)obj.GetNumberInt()));
    }else if(this->GetFlag()==3 && obj.GetFlag()==3){
        this->setdouble((double)this->GetNumberDouble()>((double)obj.GetNumberDouble()));
    }
    return *this;
};

Json_Type Json_Type::operator>=(Json_Type obj) {
    if(this->GetFlag()==2 && obj.GetFlag()==2){
        this->setInt((int)this->GetNumberInt()>=((int)obj.GetNumberInt()));
    }else if(this->GetFlag()==3 && obj.GetFlag()==3){
        this->setdouble((double)this->GetNumberDouble()>=((double)obj.GetNumberDouble()));
    }
    return *this;
};

Json_Type Json_Type::operator&&(Json_Type obj) {
    if (this->GetNumberInt() == 1 && obj.GetNumberInt() == 1) {
        this->setInt(1);
    }
    else if (this->GetNumberInt() == 1 && obj.GetNumberInt() == 0) {
        this->setInt(0);
    }
    else if (this->GetNumberInt() == 0 && obj.GetNumberInt() == 1) {
        this->setInt(0);
    }
    else if (this->GetNumberInt() == 0 && obj.GetNumberInt() == 0) {
        this->setInt(0);
    }
    return *this;
};

Json_Type Json_Type::operator||(Json_Type obj) {
    if (this->GetNumberInt() == 1 && obj.GetNumberInt() == 1) {
        this->setInt(1);
    }
    else if (this->GetNumberInt() == 1 && obj.GetNumberInt() == 0) {
        this->setInt(1);
    }
    else if (this->GetNumberInt() == 0 && obj.GetNumberInt() == 1) {
        this->setInt(1);
    }
    else if (this->GetNumberInt() == 0 && obj.GetNumberInt() == 0) {
        this->setInt(0);
    }
    return *this;
};

Json_Type Json_Type::operator!() {
    if (this->GetNumberInt() == 1) {
        this->setInt(0);
    }
    else if (this->GetNumberInt() == 0) {
        this->setInt(1);
    }
    return *this;
};

Json_Type Json_Type::operator==(Json_Type obj) {
    if (Json_Type::TYPEOF(*this) == Json_Type::TYPEOF(obj)) {
        this->setInt(1);
    }
    else
    {
        this->setInt(0);
    }
    return *this;
};

Json_Type Json_Type::operator!=(Json_Type obj) {
    if (this->GetNumberInt() == 1) {
        this->setInt(0);
    }
    else if (this->GetNumberInt() == 0) {
        this->setInt(1);
    }
    return *this;
};

std::string Json_Type::operator[](std::string expression) {      //STRING
   std::list<Json_Type> list;
   std::string str="";
   list=this->GetDataobj().begin()->GetDataobj();
   for (auto& it : list) {
       if (it.GetFlag() == 1 && it.GetKey() == expression) {
           str = it.GetKey() + " : " + it.GetString() + "\n";
           std::cout << it.GetKey() << " : " << it.GetString() << "\n";
       }
       if (it.GetFlag() == 2 && it.GetKey() == expression) {
           str = it.GetKey() + " : " + std::to_string(it.GetNumberInt()) + "\n";
           std::cout<< it.GetKey() << " : " << std::to_string(it.GetNumberInt()) << "\n";
       }
       if (it.GetFlag() == 3 && it.GetKey() == expression) {
           str = it.GetKey() + " : " + std::to_string(it.GetNumberDouble()) + "\n";
           std::cout << it.GetKey() << " : " << std::to_string(it.GetNumberDouble()) << "\n";
       }
       if (it.GetFlag() == 5 && it.GetKey() == expression) {
           std::cout << "Array of " << it.GetKey() << " has :\n";
           for (int i = 0; i < it.GetArray().size(); i++) {
               if (it.GetArray().at(i).GetFlag() == 1) {
                   str = it.GetArray().at(i).GetString();
                   std::cout << "Index " << i << " : " << str << "\n";
               }
               else if (it.GetArray().at(i).GetFlag() == 2) {
                   str = std::to_string(it.GetArray().at(i).GetNumberInt());
                   std::cout << "Index " << i << " : " << str << "\n";
               }
               else if (it.GetArray().at(i).GetFlag() == 3) {
                   str = std::to_string(it.GetArray().at(i).GetNumberDouble());
                   std::cout << "Index " << i << " : " << str << "\n";
               }
           }     
       }
   }
   return "";
};

//Json_Type& Json_Type::operator[](int number) {        //ARRAY
//    if(this->GetArray().size() < number || this->GetArray().empty()) {
//        std::cout << "Index out of bounds" << std::endl;
//        return *this;
//    }
//    this->GetArray().at(number);
//    return this->GetArray().at(1);
//};
//
//Json_Type Json_Type::operator*=(Json_Type obj) {    //ASSIGN
//    
//    
//    //if (this->GetFlag() == 5) {
//
//        switch (obj.GetFlag())
//        {
//            case 1:
//                this->setString(obj.GetString());
//                break;
//            case 2:
//                if(!this->GetArray().empty() && this->GetArray().size()<GLo){
//                      this->GetArray().at(GLo).setInt(obj.GetNumberInt());
//                }
//                break;
//            case 3:
//                this->setdouble(obj.GetNumberDouble());
//                break;
//            case 4:
//                this->setObject(obj.GetDataobj());
//                break;
//            case 5:
//                this->setArray(obj.GetArray());
//                break;
//            default:
//                break;
//            }
//    //}
//    return *this;
//};

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
    }
    else {
        if (Helper == 0)
        {
            this->array.push_back(this->GetNumberInt());
            obj1.setName(this->GetName());
            Helper++;
            std::cout << obj1.Name;
        }
        this->array.push_back(obj1.GetNumberInt());
    }
    obj1.setName(this->GetName());
    return *this;
};

int washere=0;
std::ostream& operator<<(std::ostream& os, Json_Type& probj) {
    std::list<Json_Type> list;
    list = probj.GetDataobj();
    if (!list.empty() && probj.GetFlag() == 4) {
        if (washere == 0) {
            os << "Object " << probj.GetName() << " has :" << "\n";
            washere = 1;
        }
        for (auto& it : list) {
            os << it << std::endl;
            if (it.GetFlag() == 1) {
                os << "    String of " << it.GetKey() << " is : " << it.GetString() << "\n";
            }
            if (it.GetFlag() == 2) {
                os << "    Number of " << it.GetString() << " is : " << it.GetNumberInt() << "\n";
            }
            if (it.GetFlag() == 3) {
                os << "    Number of " << it.GetString() << " is : " << it.GetNumberDouble() << "\n";
            }
            if (it.GetFlag() == 5) {
                os << "    Array of " << it.GetKey() << " has :\n";
                for (int i = 0; i < it.GetArray().size(); i++) {
                    os << "    Index " << i << it.GetArray()[i];
                }
            }
        }
    }
    else
    {
        washere = 0;
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
            //                                                      ARRAY APO OBJECTS : FIXME!
            /*for (auto& it : probj.GetArray()) {
                if (it.GetArray().begin()->GetFlag() == 4) {
                    for (auto& iyi : it.GetArray()) {

                        for (auto& iyi1 : iyi.GetDataobj().begin()->GetDataobj()) {
                            if (iyi1.GetFlag() == 1) {
                                os << "    String of " << iyi1.GetKey() << " is : " << iyi1.GetString() << "\n";
                            }if (iyi1.GetFlag() == 2) {
                                os << "    Number of " << iyi1.GetString() << " is : " << iyi1.GetNumberInt() << "\n";
                            }
                            if (iyi1.GetFlag() == 3) {
                                os << "    Number of " << iyi1.GetString() << " is : " << iyi1.GetNumberDouble() << "\n";
                            }
                        }
                    }
                }
            }*/
        }
    }
    return os;
};

 
std::string Json_Type::ISEMPTY(Json_Type& probj) {
    std::string ret;
    if (probj.GetFlag() == 5) {
        if (probj.array.size() == 0) {
            ret = "Has variable " + probj.GetName() + " empty array? = TRUE\n";
            return ret;
        }
        else {
            return ret = "Has variable " + probj.GetName() + " empty array? = FALSE\n";
            return ret;
        }
    }
    else if (probj.GetFlag() == 4) {
        if (probj.dataobj.size() == 0) {
            return ret = "Has variable " + probj.GetName() + " empty object? = TRUE\n";
            return ret;
        }
        else {
            return ret = "Has variable " + probj.GetName() + " empty object? = FALSE\n";
            return ret;
        }
    }
    else {
        ret = "Variable " + probj.GetName() + " isn't an array or an object!\n";
        return ret;
    }
};

std::string Json_Type::TYPEOF(Json_Type& probj) {
    if (probj.GetFlag() == 1) {
        return "string";
    }
    else if (probj.GetFlag() == 2 || probj.GetFlag() == 3) {
        return "number";
    }
    else if (probj.GetFlag() == 4) {
        return "object";
    }
    else if (probj.GetFlag() == 5) {
        return "array";
    }
    else {
        return "NULL";
    }
};

std::string Json_Type::SIZEOF(Json_Type& probj) {
    std::string ret;
    switch (probj.GetFlag()) {
    case 4:
        ret = "Variable " + probj.GetName() + " has an object with size : " + std::to_string(probj.GetDataobj().begin()->GetDataobj().size()) + "\n";
        return ret;
    case 5:
        ret = "Variable " + probj.GetName() + " has an array with size : " + std::to_string(probj.GetArray().size()) + "\n";
        return ret;
    default:
        ret = "The size of variable " + probj.GetName() + " is : 1\n";
        return ret;
    }
};

std::string Json_Type::HasKey(Json_Type& variable, std::string key) {
    std::string ret;
    std::list<Json_Type> list;

    list = variable.GetDataobj().begin()->GetDataobj();

    //for (auto& it1 : list) std::cout << it1.GetKey();
    if (variable.GetFlag() == 4) {
        for (auto& it : list) {
            if (it.GetKey() == key)
            {
                ret = "Object " + variable.GetName() + " has key '" + key + "'? TRUE\n";
                return ret;
            }
            else
            {
                ret = "Object " + variable.GetName() + " has key '" + key + "'? FALSE\n";
            }
        }
    }
    else
    {
        ret = "The Variable " + variable.GetName() + " is not an object to has a key!";
    }
    return ret;
};
