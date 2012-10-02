LIBS = -lncurses
CFLAGS =	-g        \
			-ansi     \
			-pedantic \
			-Wall
SRC = $(wildcard src/*.c)
all: clean compile

clean:
	rm -f *.o rubik-2d

compile: $(SRC)
	gcc -o rubik-2d $^ $(CFLAGS) $(LIBS)

check: clean compile
	./rubik-2d
