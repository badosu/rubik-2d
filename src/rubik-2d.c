#include "rubik-2d.h"

int main(int argc, char *argv[]) {
  int command;
  char *initial_file = "initial_state";
  char *goal_file =    "goal_state";

  initialize_heuristics();

  initial_board = get_board(initial_file);

  if (initial_board == NULL) {
    printw("Could'nt read %s", initial_file);
    return 1;
  }

  goal_board = get_board(goal_file);

  if (goal_board == NULL) {
    printw("Could'nt read %s", goal_file);
    return 1;
  }

  current_heuristic = heuristics[SIMPLE_HEURISTIC];

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
