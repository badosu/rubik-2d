#define SIMPLE_HEURISTIC 0

typedef int (*heuristic)(int **board);
void initialize_heuristics();
int simple_heuristic(int **board);
heuristic heuristics[1];
