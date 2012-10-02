#include "rubik-2d.h"

void initialize_heuristics() {
  heuristics[0] = simple_heuristic;
}

int simple_heuristic(int **board) {
  int i,j;
  int sum = 0;
  for (i=0; i < COLS; i++) {
    for (j=0; j < COLS; j++) {
      sum += abs(board[i+1][j+1]-(i*COLS+j));
    }
  }
  return sum;
}
