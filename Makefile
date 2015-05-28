INCLUDE=/usr/include/
BULLET_INC=/usr/include/bullet
LIB=/usr/lib/
CC=g++
CFLAGS=-I$(IDIR) -I$(LUADIR) -L$(LUADIR) -O2
CPPFLAGS+=-g -O2 -I$(INCLUDE) -I$(LIB) -I$(BULLET_INC)
#CPPFLAGS+=-g -O2 -I$(DIR) -I$(LUA_INC) -L$(LUA_LIB)
TARGET = ExclusionEngine

#LIBS=-lSDL2 -lGL -lGLEW -llua
#MAC_LIBS= -framework OpenGL -framework SDL2 -framework BulletDynamics -framework BulletCollision -framework LinearMath -llua

OBJ := $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))

all: $(TARGET)

$(TARGET): bin $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o bin/$@

linux:
	LIBS = -lSDL2 -lGL -lGLEW -llua
	make all

macosx:
	LIBS = -framework OpenGL -framework SDL2 -framework BulletDynamics -framework BulletCollision -framework LinearMath -llua
	make all

bin:
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) bin/$(TARGET)
