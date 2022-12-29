#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Json_Type{

    private:
    std::vector<float> array;
    std::vector<Json_Type> data; // or map?

    std::string name;
    std::string str;

    public:
    
};
