CC=mingw32-g++
CFLAGS=-c -O2 -DSFML_STATIC -static-libstdc++ -static-libgcc
INCLUDES=-IC:\SFML-2.1\include
LIBS=-LC:\SFML-2.1\lib
SOURCES=graphictile.cpp gametile.cpp map.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=game.exe
SFMLFLAGS=-lmingw32 -luser32 -lgdi32 -lwinmm -ldxguid -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -mwindows

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(LIBS) $(OBJECTS) -o $@ $(SFMLFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	del *.o game.exe
