all: clean main.o game.o
	@g++ main.o game.o -o jewel -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@rm -f main.o
	@rm -f game.o
main.o: 
	@g++ -c main.cpp
game.o:
	@g++ -c game.cpp
clean:
	@rm -f jewel
	
	

