#include <ncurses.h>
#include <stdlib.h>
#include "board.h"
#include "heuristic.h"

#define QUIT 'q'
#define NEXT 'n'

struct list_el {
  int val;
  int cost;
  struct list_el * next;
};

typedef struct list_el item;

/* void get_neighbours(item **board, int *neighbours [4]); */
/* item *step(int *initial_board, heuristic heuristic); */

void initialize_window();
typedef int (*command)(void);
command commands[1];
