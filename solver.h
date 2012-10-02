struct board_node {
  int **board;
  struct board_node *next;
};

typedef struct board_node node;

heuristic current_heuristic;

int cost_of(int **board);
void calculate(int **board);

int ***get_neighbours(int **board);
