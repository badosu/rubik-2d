#include "rubik-2d.h"

int main(int argc, char *argv[]) {
  int **initial_board;
  char *filename = "initial_state";
  int command;

  initialize_heuristics();

  initial_board = get_board(filename);

  if (initial_board == NULL) {
    printw("Could'nt read initial_status");
    return 1;
  }

  initialize_window();

  print_board(initial_board);
  while(1) {
    command = getch();
    clear();
    if (command == QUIT) {
      printw("\nPress any key to quit");
      break;
    }
    else if (command == NEXT) {
      print_board(initial_board);
    }
    else {
      printw("   Press n to iterate, q to quit\n");
    }
  }

  free_board(initial_board);

  refresh();
  getch();
  endwin();

  return 0;
}

void initialize_window() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  printw("WELCOME TO BADOSU's rubik-2d solver!\n");
  printw("   Press n to iterate, q to quit\n");
  getch();
  clear();
}

/* void getpositions(char chars[]) {
  item * curr, * head;
  head = NULL;
  for(i=0;i<strlen(chars);i++) {
    curr = malloc(sizeof(item));
    curr->val = chars[i];
    curr->next  = head;
    head = curr; */


/*item *step(int *initial_board, heuristic heuristic) {
  int *neighbours[4];
  int i = 0;

  get_neighbours(board, neighbours);

  while(neighbours[i] != NULL) {
    print_board(neighbours[i]);
    i++;
  }
  item *board;

  board = malloc(sizeof(item));
  board->val = initial_board;
  board->cost = heuristic(initial_board);

  return board->val;
}

void get_neighbours(item *board, int *neighbours[4]) {
  neighbours[0] = board->val;
}

*/
