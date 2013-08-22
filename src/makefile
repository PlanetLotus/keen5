PROG = keen5.exe
OBJS = helpers.o main.o Player.o
FLAGS = -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf

# This is a Windows makefile.
# ...sorry. It hurts you just as much as it hurts me.

$(PROG): $(OBJS)
	g++ -Wall -o $(PROG) $(OBJS) $(FLAGS)

clean:
	rm -Force *.o keen5.exe

# Dependencies

helpers.o: helpers.cpp
main.o: main.cpp
Player.o: Player.cpp Unit.h
