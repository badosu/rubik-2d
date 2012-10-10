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

void expand_frontier() {
  int i;
  int ***neighbours = get_neighbours(head->node->board);

  for(i=0; i<4; i++) {
    board_node *neighbour;

    if (neighbours[i] == NULL) {
      free(neighbours[i]);
      continue;
    }

    neighbour = init_node(neighbours[i]);
    frontier_push(neighbour);
  }
}

board_node *init_node(int **board) {
  board_node *node = malloc(sizeof(board_node*));
  node = malloc(sizeof(board_node));
  node->board = board;
  node->exhausted = 0;
  current_heuristic(node);
  return node;
}

void frontier_pop() {
}

void frontier_push(board_node *node) {
  list *new_item;

  while(frontier->next != NULL && frontier->next->node->cost < node->cost) {
    frontier = frontier->next;
  }

  new_item = malloc(sizeof(list));
  new_item->node = node;
  new_item->parent = frontier;
  new_item->next = frontier->next;

  if (frontier->next != NULL) {
    frontier->next->parent = new_item;
  }
  frontier->next = new_item;

  list_rewind(frontier);
}

void print_path() {
  list_rewind(head);
  print_node(head->node, "Initial State");
  while (head->next != NULL) {
    head = head->next;
    print_node(head->node, "Step");
  }
}

void list_rewind(list *list) {
  while(list->parent != NULL) {
    list = list->parent;
  }
}

void step() {
  expand_frontier();

  frontier_pop();

  print_path();
}

board_node* best_node_of(board_node **nodes) {
  int i;
  board_node *node = NULL;
  for(i=0; i<4; i++) {
    if (node == NULL || (nodes[i] != NULL && node->exhausted == 0
        && nodes[i]->cost < node->cost)) {
      node = nodes[i];
    }
  }
  node->exhausted = 1;
  return node;
}
