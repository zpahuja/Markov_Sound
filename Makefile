OFILES= sin_wave.o

all: main

main: main.cpp $(OFILES)
	g++ main.cpp $(OFILES) -o main -Wall -lSDL2

sin_wave: sin_wave.cpp sin_wave.h
	g++ -c sin_wave.cpp -o sin_wave.o -Wall

clean:
	rm -rf *o *gch main