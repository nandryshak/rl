# Windows
ifeq ($(OS),Windows_NT)
	CC=mingw32-g++
	INCLUDES=-IC:\SFML-2.1\include
	LIBS=-LC:\SFML-2.1\lib
	EXE=game.exe
	SFMLFLAGS=-lmingw32 -luser32 -lgdi32 -lwinmm -ldxguid -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -mwindows
else
# Everything else
	CC=g++
	EXE=game
	SFMLFLAGS=-lsfml-graphics-s -lsfml-window-s -lsfml-system-s
endif

# cross-platform
CFLAGS=-c -g -DSFML_STATIC -static-libstdc++ -static-libgcc
SOURCES=graphictile.cpp gametile.cpp map.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CC) -g $(LIBS) $(OBJECTS) -o $@ $(SFMLFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	del *.o game.exe
