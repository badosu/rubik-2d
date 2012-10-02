#include "rubik-2d.h"

int ***get_neighbours(int **board) {
  int *blank = blank_position(board);
  int ***neighbours = malloc(4*sizeof(int**));
  int i=0;

  if (board[blank[0]+1][blank[1]] >= 0) {
    neighbours[i] = tap(board, blank[0]+1, blank[1]);
    calculate(neighbours[i]);
    i++;
  }

  if (board[blank[0]-1][blank[1]] >= 0) {
    neighbours[i] = tap(board, blank[0]-1, blank[1]);
    calculate(neighbours[i]);
    i++;
  }

  if (board[blank[0]][blank[1]+1] >= 0) {
    neighbours[i] = tap(board, blank[0], blank[1]+1);
    calculate(neighbours[i]);
    i++;
  }

  if (board[blank[0]][blank[1]-1] >= 0) {
    neighbours[i] = tap(board, blank[0], blank[1]-1);
    calculate(neighbours[i]);
  }

  free(blank);

  return neighbours;
}

int cost_of(int **board) {
  return board[0][0];
}

void calculate(int **board) {
  board[0][0] = current_heuristic(board);
}
