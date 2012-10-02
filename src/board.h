#define COLS 3

#define UP    "01"
#define DOWN  "21"
#define LEFT  "10"
#define RIGHT "12"

int parse_char(char block);
int parse_block(int number);

void print_offset(int offset);
void print_board(int **board, char *head);
void print_neighbours(int **board);

int **get_board(char *filename);
int **init_board();
int **copy_board(int **board);
void board_swap(int **board, int i, int j, int new_i, int new_j);
int *blank_position(int **board);
int **tap(int **board, char* position);

void free_board(int **board);
