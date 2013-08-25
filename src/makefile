PROG = keen5.exe
OBJS = Player.o helpers.o main.o Timer.o
FLAGS = -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf

# This is a Windows makefile.
# ...sorry. It hurts you just as much as it hurts me.

$(PROG): $(OBJS)
	g++ -Wall -o $(PROG) $(OBJS) $(FLAGS)

clean:
	del *.o keen5.exe

# Dependencies
Player.o: Player.h
helpers.o: helpers.h
Timer.o: Timer.h
