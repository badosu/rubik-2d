#define COLS 3

int parse_char(char block);
int parse_block(int number);

void print_offset(int offset);
void print_board(int **board);

int **get_board(char *filename);
int **init_board();
int **copy_board(int **board);
void board_swap(int **board, int i, int j, int new_i, int new_j);
int *blank_position(int **board);
void tap(int **board, int i, int j);

void free_board(int **board);
