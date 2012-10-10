#define COLS 3

#define UP    "01"
#define DOWN  "21"
#define LEFT  "10"
#define RIGHT "12"

int parse_char(char block);

int **get_board(char *filename);
int **init_board();
int **copy_board(int **board);
board_node *tap(board_node *node, char* direction);

int *get_position_of(int **board, int value);

void free_board(int **board);

int frontier_contains(board_node *node);

int board_equals(int **board, int **other_board);
