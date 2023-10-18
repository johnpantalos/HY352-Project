# Project352
Project HY352

Team members:

John Pantalos
Anestis Kivroglou
C++ VERSION 11

We test and work on this project using Ubuntu terminal 18.04. We build the program using makefile, that compiles the main.cpp and json_file.cpp files with the inclusion of the json_lib.h.

Our project consists of:
-Declaring JSON variables and objects, including arrays, except for nested arrays with objects.
-The following functions:
    SIZE_OF(json_value_or_variable)
    IS_EMPTY(json_value_or_variable)
    HAS_KEY(json_value_or_variable, key)
    TYPE_OF(json_value_or_variable)

Additionally, we have implemented the "print" function, except in the case of "PRINT book["title"]["name"]". We have implemented numerical operators for all variables and objects, as well as comparison operators (<= and >=).
Boolean operators are implemented, except for checking arrays and objects. The "set" and "erase" functions have not been implemented.
