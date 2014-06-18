CC=mingw32-g++
CFLAGS=-Wall -O2 -DSFML_STATIC
INCLUDES=-IC:\SFML-2.1\include
LIBS=-LC:\SFML-2.1\lib
SFMLFLAGS=-lmingw32 -luser32 -lgdi32 -lwinmm -ldxguid -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -mwindows

all: game

game: main.o
	$(CC) $(LIBS) -o game.exe main.o $(SFMLFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp

clean:
	del *.o game.exe
