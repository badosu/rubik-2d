struct board_node {
  int **board;
  struct board_node * next;
};

typedef struct board_node node;

/* int ***void get_neighbours(int **board); */
/* item *step(int *initial_board, heuristic heuristic); */

int cost_of(int **board);
void calculate(int **board);
