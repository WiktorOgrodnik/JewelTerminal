CXX = g++
CXXFLAGS = -O2 -H -std=c++17 -Wall
OBJ = main.o game.o object.o jewel.o board.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

PCH_SRC = pch.hpp
#PCH_HEADERS = 
PCH_OUT = pch.hpp.gch

all: clean $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o jewel $(SFML) 
	@rm -f $(OBJ)
main.o: 
	@g++ -c main.cpp
game.o:
	@g++ -c game.cpp
object.o:
	@g++ -c object.cpp
jewel.o:
	@g++ -c jewel.cpp
board.o:
	@g++ -c board.cpp
clean:
	@rm -f jewel
pre:
	@$(CXX) $(CXXFLAGS) $(PCH_SRC);
	@make
	
	

