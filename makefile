#Author: Joshua Nutt




CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = play_game.cpp
SRCS += Tool.hpp Tool.cpp 
SRCS += Rock.hpp Rock.cpp
SRCS += Paper.hpp Paper.cpp  
SRCS += Scissors.hpp Scissors.cpp
SRCS += RPSGame.cpp RPSGame.hpp
SRCS += inputValidation.cpp inputValidation.hpp

projGroup: ${SRCS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o projGroup

clean:
	rm projGroup

zip: 
	zip -D GroupProject_Group_16.zip ${SRCS} makefile

