PROG = keen5.exe
OBJS = helpers.o main.o
FLAGS = -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf

# This is a Windows makefile.
# ...sorry. It hurts you just as much as it hurts me.

$(PROG): $(OBJS)
	g++ -o $(PROG) $(OBJS) $(FLAGS)

clean:
	rm -Force *.o keen5.exe
