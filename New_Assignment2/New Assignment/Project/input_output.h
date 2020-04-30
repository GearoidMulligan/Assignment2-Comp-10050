
#ifndef PROJECT_INPUT_OUTPUT_H
#define PROJECT_INPUT_OUTPUT_H



#include "game_init.h"

//Function to print the board
void print_board(square board[BOARD_SIZE][BOARD_SIZE]);

void ending(player players[PLAYERS_NUM],int x);

int count_stack( piece*s);

#endif //PROJECT_INPUT_OUTPUT_H
