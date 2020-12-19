all: clean main.o
	@g++ main.o -o jewel -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	@rm -f main.o
main.o: 
	@g++ -c main.cpp
clean:
	@rm -f jewel
	
	

