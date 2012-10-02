#include <ncurses.h>
#include <stdlib.h>
#include "board.h"
#include "heuristic.h"
#include "solver.h"
#include "printing.h"

#define QUIT 'q'
#define NEXT 'n'

void initialize_window();

typedef int (*command)(void);
command commands[1];
