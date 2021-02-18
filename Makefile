CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall

OBJ = button.o clickable.o drawable.o game.o jewel.o label.o layer.o logfile.o logic.o main.o rectangle.o resources.o selectable.o settings.o sprite.o
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



