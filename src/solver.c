#include "rubik-2d.h"

board_node **get_neighbours(board_node *board) {
  int i;
  char *DIRECTIONS[4] = {UP, DOWN, LEFT, RIGHT};
  board_node **neighbours = malloc(4*sizeof(board_node*));

  for(i=0; i<4; i++) {
    neighbours[i] = tap(board, DIRECTIONS[i]);
  }

  return neighbours;
}

void expand_frontier() {
  int i;
  board_node **neighbours;

  list_rewind(frontier);

  neighbours = get_neighbours(frontier->node);

  for(i=0; i<4; i++) {
    board_node *neighbour = neighbours[i];

    if (neighbour == NULL) {
      free(neighbour);
      continue;
    }

    frontier_push(neighbour);
  }
}

board_node *init_node(int **board) {
  board_node *node = malloc(sizeof(board_node*));
  node = malloc(sizeof(board_node));
  node->board = copy_board(board);
  node->exhausted = 0;
  current_heuristic(node);
  return node;
}

void frontier_pop() {
  list_rewind(frontier);
  head = clone_list(frontier);
  frontier->parent = NULL;
  frontier = frontier->next;
}

list *clone_list(list *o_list) {
  list *cloned_list = malloc(sizeof(list*));
  cloned_list->node = o_list->node;
  cloned_list->parent = o_list->parent;
  cloned_list->next = o_list->next;
  return cloned_list;
}

void frontier_push(board_node *node) {
  list *new_item;

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

  print_node(frontier->node, "Current State");
}

int list_fforward(list *list) {
  int i = 0;
  while(list->next != NULL) {
    list = list->next;
    i++;
  }
  return i;
}

int list_rewind(list *list) {
  int i = 0;
  while(list->parent != NULL) {
    list = list->parent;
    i++;
  }
  return i;
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
