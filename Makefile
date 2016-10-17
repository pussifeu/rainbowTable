TABLE_SRC=contexte.cpp cracker.cpp arcEnCiel.cpp 
CRACK_SRC=contexte.cpp cracker.cpp arcEnCiel.cpp
HEADERS=contexte.hpp
PROGS=createTable executeCrack
CC=g++
CFLAGS= -O3 -g -Wall -std=c++11 -lssl -lcrypto 

all: ${PROGS}

createTable:	utils.o ${TABLE_SRC:.cpp=.o} createTable.cpp
	${CC} $^ -o $@ ${CFLAGS}

executeCrack:	utils.o ${CRACK_SRC:.cpp=.o} executeCrack.cpp
	${CC} $^ -o $@ ${CFLAGS}

%.o: %.cpp %.hpp
	g++  -c $^ ${CFLAGS}

clean:
	rm -f ${PROGS} *.o
