#include <ncurses.h>
#include <stdlib.h>

#define QUIT 'q'
#define NEXT 'n'

void initialize_window();

typedef int (*command)(void);
command commands[1];

int **goal_board;

typedef struct board_node board_node;
typedef struct board_list list;

#include "solver.h"
#include "heuristic.h"
#include "board.h"
#include "printing.h"
