#include "rubik-2d.h"

int ***get_neighbours(int **board) {
  int i;
  char *DIRECTIONS[4] = {UP, DOWN, LEFT, RIGHT};
  int ***neighbours = malloc(4*sizeof(int**));

  for(i=0; i<4; i++) {
    neighbours[i] = tap(board, DIRECTIONS[i]);
  }

  return neighbours;
}

int cost_of(int **board) {
  return board[0][0];
}

void calculate(int **board) {
  board[0][0] = current_heuristic(board);
}
