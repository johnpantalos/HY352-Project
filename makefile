	
###################################################
#
# file: Makefile
#
# @Author:   Ioannis Pantalos
#			 Anestis Kivroglou
# @Version:  24-12-2022
# @email:    csd4348@csd.uoc.gr
#			 csd4538@csd.uoc.gr
#
# Makefile
#
#################################################### 

CC=g++ 
CFLAGS=-std=c++11 -Wall

all: json

json:	json_code.cpp
	$(CC) $(CFLAGS) json_code.cpp -o json

clean:
	rm -rf *o json

run:	json_code.cpp
	$(CC) $(CFLAGS) json_code.cpp -o json
	./json
	rm -rf *o json
