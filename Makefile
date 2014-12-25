LUADIR=/usr/include/
CC=g++
CFLAGS=-I$(IDIR) -I$(LUADIR) -L$(LUADIR) -O2
CPPFLAGS+=-g -O2
TARGET  = ExclusionEngine

LIBS=-lSDL2 -lGL -lGLEW -llua

OBJ := $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))

all: $(TARGET)

$(TARGET): bin $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o bin/$@ 

bin:
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) bin/$(TARGET)
