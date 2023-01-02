#include "json_lib.h"

//JSON(emptyObj) = OBJECT{}
////eimaste koukloi      

PROGRAM_BEGIN

//define emptyObj json with empty OBJECT
JSON(empObj1) = NUMBER(1022.0)
JSON(empObj2) = STRING("1022")
JSON(empObj3) = TRUE

//JSON(obj)=OBJECT{}
//define emptyArray json with empty array
//JSON(emptyArray) = ARRAY

JSON(week_temperatures2) = ARRAY[NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20), NUMBER(19), NUMBER(18.5), NUMBER(19)]


//#define ARRAY new Json_Type(std::vector<Json_Type*>Array)
//#define ARRAY new Json_Type(/*std::vector<Json_Type*>Array*/)



//JSON(week_temperatures) = ARRAY[NUMBER(20)]

							// vector1.push_back(new Json_Type(19.5))
//Json_Type week_temperatures = new Json_Type(std::vector<Json_Type> array)

PROGRAM_END
