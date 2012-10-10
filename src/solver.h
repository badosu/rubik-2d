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

int ***get_neighbours(int **board);

void step();

void expand_frontier();

void frontier_pop();

void frontier_push(board_node *node);

board_node *init_node(int **board);

list *head;

list *frontier;
