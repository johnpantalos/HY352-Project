#include "json_lib.h"
PROGRAM_BEGIN

//define emptyObj json with empty OBJECT

JSON(empObj3) = TRUE
JSON(week_temperatures2) = ARRAY[NUMBER(20), NUMBER(19), NUMBER(18), NUMBER(17), NUMBER(16), NUMBER(15), NUMBER(14)]
JSON(empObj1) = NUMBER(1022)
JSON(papa) = STRING("lala")
JSON(emp2) = STRING("lala111")
//JSON(object) = OBJECT;

JSON(book) = OBJECT{
	KEY(title) : STRING("Gone Girl"),
	KEY(published) : NUMBER(2012),
	KEY(published1) : NUMBER(2012.2),
	KEY(type) : STRING("Thriller"),
	KEY(grades) : ARRAY[NUMBER(10), NUMBER(7), NUMBER(5), NUMBER(6), NUMBER(8), NUMBER(9), NUMBER(7)]
}

PRINT empObj1
SIZE_OF(week_temperatures2)
PRINT papa
PRINT week_temperatures2
SIZE_OF(papa)

PRINT book

//PRINT book["title"]
PRINT HAS_KEY(book, "published1")
PRINT HAS_KEY(book, "published")
PRINT HAS_KEY(book, "type")
PRINT HAS_KEY(book, "type1")
PRINT HAS_KEY(book, "title")
PRINT HAS_KEY(book, "grades")
PRINT HAS_KEY(book, "grades1")

//JSON(week_temperatures) = ARRAY[NUMBER(20)]

							// vector1.push_back(new Json_Type(19.5))
//Json_Type week_temperatures = new Json_Type(std::vector<Json_Type> array)

PROGRAM_END
