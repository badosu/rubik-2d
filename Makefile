LIBS = -lncurses
CFLAGS = -g        \
				 -ansi     \
				 -pedantic \
				 -Wall
SRC = rubik-2d.c  \
			board.c     \
			heuristic.c

all: clean compile

clean:
	rm -f *.o rubik-2d

compile: $(SRC)
	gcc -o rubik-2d $^ $(CFLAGS) $(LIBS)

%.o : $(SRC)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

check: clean compile
	./rubik-2d
