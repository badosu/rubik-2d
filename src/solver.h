struct board_node {
  int cost;
  int distance;
  int **board;
  int exhausted;
};

struct board_list {
  board_node node;
  struct board_list *next;
};

int cost_of(int **board);

int ***get_neighbours(int **board);

board_node* best_node_of(board_node **nodes);

void step_into(board_node *current_node);

board_node *initial_node;
list current_list;
