#include "json_lib.h"
//JSON(emptyObj) = OBJECT{}

PROGRAM_BEGIN

//define emptyObj json with empty OBJECT

//JSON(empObj1) = NUMBER(1022)
//JSON(papa) = STRING("lala")
// JSON(emp2) = STRING("lala111")



//JSON(obj) = OBJECT{}
//define emptyArray json with empty array
//JSON(emptyArray) = ARRAY

// JSON(empObj3) = TRUE
JSON(week_temperatures2) = ARRAY[NUMBER(20), STRING("lala111"), NUMBER(18), NUMBER(17), NUMBER(16), NUMBER(15), NUMBER(14)]

//JSON(object) = OBJECT;

//KEY(title) : STRING("Gone Girl");

//KEY(papapa) : STRING("frapaa")

JSON(book) = OBJECT{
	KEY(published) : NUMBER(2012),
	KEY(type): STRING("Thriller")
}

//JSON(week_temperatures) = ARRAY[NUMBER(20)]

							// vector1.push_back(new Json_Type(19.5))
//Json_Type week_temperatures = new Json_Type(std::vector<Json_Type> array)

PROGRAM_END
