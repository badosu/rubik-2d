#include "rubik-2d.h"

int **init_board() {
  int i;
  int **board;

  board = malloc((COLS+2) * sizeof(int*));

  for(i=0; i<COLS+2; i++) {
    board[i] = malloc((COLS+2) * sizeof(int));
  }

  for (i=0; i<COLS+2; i++) {
    board[0][i] = -1;
    board[COLS+1][i] = -1;
    board[i][0] = -1;
    board[i][COLS+1] = -1;
  }

  return board;
}

int parse_block(int number) {
  return number == 0 ? ' ' : number+'0';
}

int parse_char(char block) {
  return block == ' ' ? 0 : block-'0';
}

void free_board(int **board) {
  int i;
  for(i=0; i<COLS+2; i++) {
    free(board[i]);
  }
  free(board);
}

int **copy_board(int **board) {
  int **new_board = init_board();
  int i,j;
  for (i=1; i<COLS+1; i++) {
    for (j=1; j<COLS+1; j++) {
      new_board[i][j] = board[i][j];
    }
  }

  return new_board;
}

int **get_board(char *filename) {
  char line [5];
  int i;
  int index = 1;
  int **board;

  FILE *stream = fopen(filename, "r");

  if (stream == NULL) {
    return NULL;
  }

  board = init_board();

  while (fgets(line, sizeof line, stream) != NULL) {
    for (i=0; i < COLS; i++) {
      board[index][i+1] = parse_char(line[i]);
    }
    index++;
  }

  fclose(stream);

  return board;
}

int *blank_position(int **board) {
  int i,j;
  int *position = malloc(2*sizeof(int));
  for (i=1; i<COLS+1; i++) {
    for (j=1; j<COLS+1; j++) {
      if (board[i][j]==0) {
        position[0] = i;
        position[1] = j;
        break;
      }
    }
  }

  return position;
}

void tap(int **board, int i, int j) {
  int *blank;
  blank = blank_position(board);
  board_swap(board, blank[0], blank[1], i, j);
  free(blank);
}

void board_swap(int **board, int i, int j, int new_i, int new_j) {
  int old_block = board[i][j];
  int new_block = board[new_i][new_j];
  board[i][j] = new_block;
  board[new_i][new_j] = old_block;
}

void print_board(int **board, char *head) {
  int i, j;
  int offset = 3;

  printw("\n==========\n %s\n", head);
  print_offset(offset);
  printw("---");

  for (i=1; i < COLS+1; i++) {
    printw("%c", '\n');
    print_offset(offset);
    for (j=1; j < COLS+1; j++) {
      printw("%c", parse_block(board[i][j]));
    }
  }
  printw("%c", '\n');
  print_offset(offset);
  printw("---\n");
  printw(" Cost: %i\n", cost_of(board));
  printw("----------\n");
}

void print_offset(int offset) {
  int i;
  for(i=0; i < offset; i++) {
    printw("%c", ' ');
  }
}
