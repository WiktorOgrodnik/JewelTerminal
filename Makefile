CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall

OBJ = main.o game.o selectable.o jewel.o layer.o settings.o logic.o logfile.o resources.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

INC_DIR=.
SRC_DIR=./src

PCH_SRC = src/pch.hpp
#PCH_HEADERS = 
PCH_OUT = src/pch.hpp.gch

NAME = jewel

all: $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) $(SFML)
%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c -I$(INC_DIR) $< -o $@
clean:
	@rm -f $(NAME) $(OBJ)



