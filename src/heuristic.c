#include "rubik-2d.h"

void initialize_heuristics() {
  heuristics[0] = simple_heuristic;
}

int simple_distance(int **board, int **other_board);

int simple_heuristic(list *item) {
  list *parent = item->parent;
  board_node *node = item->node;
  node->distance = parent == NULL ? 0 : parent->node->distance + 1;
  node->heuristic = simple_distance(node->board, goal_board);
  node->cost = node->distance + node->heuristic;
  return node->cost;
}

int simple_distance(int **board, int **other_board) {
  int i, j;
  int sum = 0;
  for (i=1; i < COLS+1; i++) {
    for (j=1; j < COLS+1; j++) {
      int* other_position = get_position_of(other_board, board[i][j]);
      sum += abs(i-other_position[0]) + abs(j-other_position[1]);
      free(other_position);
    }
  }
  return sum;
}
