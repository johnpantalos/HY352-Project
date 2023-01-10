	
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

all:
	$(CC) $(CFLAGS) json_file.cpp main.cpp -o json
	./json

clean:
	rm -rf *o json
