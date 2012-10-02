#include "rubik-2d.h"

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

*/

/* int ***get_neighbours(item *board) {
} */

int cost_of(int **board) {
  return board[0][0];
}

void calculate(int **board) {
  board[0][0] = current_heuristic(board);
}
