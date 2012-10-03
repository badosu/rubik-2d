#include "rubik-2d.h"

void print_board(int **board, char *head) {

  int i, j;
  int offset = 3;

  board[0][0] = current_heuristic(board);

  printw("\n==========\n %s\n", head);
  print_offset(offset);
  printw("---");

  for (i=1; i < COLS+1; i++) {
    printw("%c", '\n');
    print_offset(offset);
    for (j=1; j < COLS+1; j++) {
      printw("%c", parse_block(board[i][j]));
    }
  }
  printw("%c", '\n');
  print_offset(offset);
  printw("---\n");
  printw(" Cost: %i\n", cost_of(board));
  printw("----------\n");
}

void print_offset(int offset) {
  int i;
  for(i=0; i < offset; i++) {
    printw("%c", ' ');
  }
}

void print_neighbours(int **board) {
  int ***neighbours = get_neighbours(board);
  int i;

  for (i=0; i<4; i++) {
    if (neighbours[i] != NULL) {
      print_board(neighbours[i], "Neighbour");
      free_board(neighbours[i]);
    }
  }

  free(neighbours);
}

int parse_block(int number) {
  return number == 0 ? ' ' : number+'0';
}
