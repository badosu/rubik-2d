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

void step_into(board_node *current_node) {
  int i;
  board_node *best_node;

  int ***neighbours = get_neighbours(current_node->board);
  board_node **nodes = malloc(4*sizeof(board_node*));

  print_node(current_node);

  for(i=0; i<4; i++) {
    int **neighbour = neighbours[i];
    if (neighbour == NULL) {
      continue;
    }
    nodes[i] = malloc(sizeof(board_node));
    nodes[i]->board = neighbour;
    nodes[i]->exhausted = 0;
    current_heuristic(nodes[i]);
  }

  best_node = best_node_of(nodes);

  while (best_node != NULL) {
    best_node = best_node_of(nodes);
    step_into(best_node);
    if (best_node->distance == 0) {
      best_node->exhausted = 0;
      break;
    }
  }

  for(i=0; i<4; i++) {
    free(neighbours[i]);
    if (nodes[i]->exhausted) {
      free(nodes[i]);
    }
  }
}

board_node* best_node_of(board_node **nodes) {
  int i;
  board_node *node = NULL;
  for(i=0; i<4; i++) {
    if (node == NULL || (nodes[i] != NULL
        && nodes[i]->cost < node->cost)) {
      node = nodes[i];
    }
  }
  return node;
}
