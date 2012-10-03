#include "rubik-2d.h"

int **init_board() {
  int i;
  int **board;

  board = malloc((COLS+2) * sizeof(int*));

  board[0] = malloc((COLS+2) * (COLS+2) * sizeof(int));

  for(i=1; i<COLS+2; i++) {
    board[i] = board[0]+i*(COLS+2);
  }

  for (i=0; i<COLS+2; i++) {
    board[0][i] = -1;
    board[COLS+1][i] = -1;
    board[i][0] = -1;
    board[i][COLS+1] = -1;
  }

  return board;
}

int parse_char(char block) {
  return block == ' ' ? 0 : block-'0';
}

void free_board(int **board) {
  free(board[0]);
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

int *get_position_of(int **board, int value) {
  int i,j;
  int *position = malloc(2*sizeof(int));
  for (i=1; i<COLS+1; i++) {
    for (j=1; j<COLS+1; j++) {
      if (board[i][j] == value) {
        position[0] = i;
        position[1] = j;
        return position;
      }
    }
  }
  return position;
}

int **tap(int **board, char* direction) {
  int **tapped_board;
  int old_block, new_block;

  int *blank = get_position_of(board, 0);

  int i = blank[0]+(direction[0]-'0'-1);
  int j = blank[1]+(direction[1]-'0'-1);

  if (board[i][j] < 0) {
    return NULL;
  }

  tapped_board = copy_board(board);

  old_block = tapped_board[i][j];
  new_block = tapped_board[blank[0]][blank[1]];

  tapped_board[i][j] = new_block;
  tapped_board[blank[0]][blank[1]] = old_block;

  free(blank);

  return tapped_board;
}
