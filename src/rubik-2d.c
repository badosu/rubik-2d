#include "rubik-2d.h"

int main(int argc, char *argv[]) {
  char *initial_file = "initial_state";
  char *goal_file =    "goal_state";
  int **initial_board = get_board(initial_file);

  if (initial_board == NULL) {
    printw("Could'nt read %s", initial_file);
    return 1;
  }

  goal_board = get_board(goal_file);

  if (goal_board == NULL) {
    printw("Could'nt read %s", goal_file);
    return 1;
  }

  initialize_window();

  initialize_heuristics();
  current_heuristic = heuristics[SIMPLE_HEURISTIC];

  initial_node = malloc(sizeof(board_node));
  initial_node->exhausted = 0;
  initial_node->board = initial_board;
  current_heuristic(initial_node);

  step_into(initial_node);

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
