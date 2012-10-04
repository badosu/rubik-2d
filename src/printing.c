#include "rubik-2d.h"

void print_node(board_node *node, char *head) {
  int i, j;
  int offset = 3;

  printw("\n==========\n %s\n", head);
  print_offset(offset);
  printw("---");

  for (i=1; i < COLS+1; i++) {
    printw("%c", '\n');
    print_offset(offset);
    for (j=1; j < COLS+1; j++) {
      printw("%c", parse_block(node->board[i][j]));
    }
  }
  printw("%c", '\n');
  print_offset(offset);
  printw("---\n");
  printw(" Cost: %i\n", node->cost);
  printw("----------\n");
}

void print_offset(int offset) {
  int i;
  for(i=0; i < offset; i++) {
    printw("%c", ' ');
  }
}

int parse_block(int number) {
  return number == 0 ? ' ' : number+'0';
}
