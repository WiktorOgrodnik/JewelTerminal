CXX = g++
CXXFLAGS = -O2 -H -std=c++17 -Wall
OBJ = main.o engine.o game.o object.o jewel.o board.o layer.o settings.o score.o logika.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

PCH_SRC = source/pch.hpp
#PCH_HEADERS = 
PCH_OUT = source/pch.hpp.gch

all: clean $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o jewel $(SFML)
main.o: 
	@g++ -c source/main.cpp
game.o:
	@g++ -c source/game.cpp
object.o:
	@g++ -c source/object.cpp
jewel.o:
	@g++ -c source/jewel.cpp
board.o:
	@g++ -c source/board.cpp
layer.o:
	@g++ -c source/layer.cpp
engine.o:
	@g++ -c source/engine.cpp
settings.o:
	@g++ -c source/settings.cpp
score.o:
	@g++ -c source/score.cpp
logika.o:
	@g++ -c source/logika.cpp
clean:
	@rm -f $(OBJ) 
	@rm -f jewel
pre:
	@$(CXX) $(CXXFLAGS) $(PCH_SRC);
	@make
	
	

