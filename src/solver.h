struct board_node {
  int cost;
  int distance;
  int **board;
  int exhausted;
};

struct board_list {
  board_node *node;
  struct board_list *parent;
  struct board_list *next;
};

board_node **get_neighbours(board_node *board);

void step();

void expand_frontier();

void frontier_pop();

void frontier_push(board_node *node);

board_node *init_node(int **board);

list *head;

list *frontier;

int list_rewind(list *list);
int list_fforward(list *list);

list *clone_list(list *list);
