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

  current_heuristic = heuristics[SIMPLE_HEURISTIC];

  calculate(initial_board);

  initialize_window();

  print_board(initial_board, "Current");
  print_neighbours(initial_board);

  while(1) {
    command = getch();
    clear();
    if (command == QUIT) {
      printw("\nPress any key to quit");
      break;
    }
    else if (command == NEXT) {
      print_board(initial_board, "Current");
      print_neighbours(initial_board);
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
