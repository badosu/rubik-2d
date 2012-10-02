#define COLS 3

#define UP    "01"
#define DOWN  "21"
#define LEFT  "10"
#define RIGHT "12"

int parse_char(char block);

int **get_board(char *filename);
int **init_board();
int **copy_board(int **board);
int **tap(int **board, char* direction);

int *blank_position_of(int **board);

void free_board(int **board);
