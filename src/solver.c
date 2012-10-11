#include "rubik-2d.h"

void step() {
  expand_frontier();

  frontier_pop();

  print_path();
}

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

  neighbours = get_neighbours(get_head()->node);

  for(i=0; i<4; i++) {
    board_node *neighbour = neighbours[i];

    if (neighbour == NULL) {
      free(neighbour);
      continue;
    }

    frontier_push(neighbour);
  }
}

void frontier_pop() {
  get_head();
  frontier->prev = NULL;
  frontier = frontier->next;
}

void frontier_push(board_node *node) {
  list *item = init_item(node);

  get_head();

  while(frontier->next != NULL) {
    board_node *l_node = frontier->node;
    if (l_node->cost < node->cost) {
      break;
    }
    frontier = frontier->next;
  }

  item->next = frontier;
  item->prev = frontier->prev;

  if (frontier->prev != NULL) {
    frontier->prev->next = item;
  }
  frontier->prev = item;

  frontier = item;

  list_rewind(frontier);
}

void print_path() {
  get_head();
  print_node(frontier->node, "Initial State");
  while (frontier->prev != NULL) {
    frontier = frontier->prev;
    print_node(frontier->node, "Step");
  }
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

  if (list == NULL) {
    return i;
  }

  while(list->prev != NULL) {
    list = list->prev;
    i++;
  }
  return i;
}

list *get_head() {
  list_rewind(frontier);
  return frontier;
}

list *init_item(board_node *node) {
  list *item = malloc(sizeof(list));
  item->node = node;
  item->parent = get_head();
  current_heuristic(item);

  return item;
}

board_node *init_node(int **board) {
  board_node *node = malloc(sizeof(board_node));
  node = malloc(sizeof(board_node));
  node->board = copy_board(board);
  return node;
}
