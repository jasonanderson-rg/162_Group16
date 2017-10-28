#Author: Joshua Nutt




CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g

SRCS = toolsMain.cpp
SRCS += Tool.hpp Tool.cpp 
SRCS += Rock.hpp Rock.cpp
SRCS += Paper.hpp Paper.cpp  
SRCS += Scissors.hpp Scissors.cpp



projGroup: ${SRCS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o projGroup

clean:
	rm projGroup

zip: 
	zip -D GroupProject_Group_16.zip ${SRCS} makefile
