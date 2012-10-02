#define COLS 3

int parse_char(char block);
int parse_block(int number);
void print_offset(int offset);

int **get_board(char *filename);
int **init_board();
int **copy_board(int **board);
void free_board(int **board);
void print_board(int **board);
