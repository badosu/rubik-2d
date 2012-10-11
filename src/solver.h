struct board_node {
  int cost;
  int distance;
  int heuristic;
  int **board;
};

struct board_list {
  board_node *node;
  struct board_list *parent;
  struct board_list *next;
  struct board_list *prev;
};

board_node **get_neighbours(board_node *board);

/* Performs a step of the solver */
void step();

void expand_frontier();

void frontier_pop();

/* Initializes an item using provided node */
/* Pushes the item in the frontier */
/* Ordered by the node cost */
void frontier_push(board_node *node);

/* Prints all the steps taken since the initial_state, and their cost */
/* Also prints the current best node */
void print_path();

board_node *init_node(int **board);

list *frontier;

/* Rewinds the list to it's first element */
/* Returns the number of items between */
int list_rewind(list *list);

/* Rewinds the list to it's last element */
/* Returns the number of items between */
int list_fforward(list *list);

/* Initializes an item with provided node */
/* Calculate it's heuristic */
list *init_item(board_node *node);

list *get_head();
