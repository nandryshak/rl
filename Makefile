CC=mingw32-g++
CFLAGS=-c -Wall -O2
INCLUDES=-IC:\SFML-2.1\include
LIBS=-LC:\SFML-2.1\lib
SFMLFLAGS=-lmingw32 -luser32 -lgdi32 -lwinmm -ldxguid -lsfml-graphics -lsfml-window -lsfml-system -mwindows

all: game

game: main.o
	$(CC) $(LIBS) -o game.exe main.o -s $(SFMLFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp

clean:
	del *.o game.exe
