LUADIR=/usr/include/
CC=g++
CFLAGS=-I$(IDIR) -I$(LUADIR) -L$(LUADIR) -O2
CPPFLAGS+=-g -O2

LIBS=-lSDL2 -lGL -lGLEW -llua

DEPS = shader.h GameState.h Scene.h window.h InputManager.h PhysicsEngine.h game.h renderingengine.h ExclusionEngine.h CoreEngine.h Entity.h ScriptingEngine.h

OBJ = main.o window.o ScriptingEngine.o

all: ExclusionEngine

.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

ExclusionEngine: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o ExclusionEngine
