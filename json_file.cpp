#include "json_lib.h"

//JSON(emptyObj) = OBJECT{}
////eimaste koukloi      

PROGRAM_BEGIN

//define emptyObj json with empty OBJECT
JSON(emptyObj) = NUMBER(1022.0)
JSON(emptyObj) = STRING("1022")
JSON(emptyObj) = TRUE

//define emptyArray json with empty array
JSON(emptyArray) = ARRAY[]


JSON(week_temperatures) = ARRAY[NUMBER(20)]
JSON(week_temperatures) = ARRAY[ NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20), NUMBER(19), NUMBER(18.5), NUMBER(19) ]
Json_Type week_temperatures = new Json_Type(std::vector<Json_Type> array)

PROGRAM_END
