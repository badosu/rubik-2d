#include <ncurses.h>
#include <stdlib.h>

#define QUIT 'q'
#define NEXT 'n'

void initialize_window();

int **goal_board;

int command;

typedef struct board_node board_node;
typedef struct board_list list;

#include "solver.h"
#include "heuristic.h"
#include "board.h"
#include "printing.h"
