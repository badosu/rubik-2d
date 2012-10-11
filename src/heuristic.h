#define SIMPLE_HEURISTIC 0

typedef int (*heuristic)(list *item);
int simple_heuristic(list *item);
void initialize_heuristics();
heuristic heuristics[1];

heuristic current_heuristic;
