#define SIMPLE_HEURISTIC 0

typedef int (*heuristic)(board_node *node);
int simple_heuristic(board_node *node);
void initialize_heuristics();
heuristic heuristics[1];
board_node *initial_node;

heuristic current_heuristic;
