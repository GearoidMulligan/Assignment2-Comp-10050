
#ifndef PROJECT_PLAYER_MOVE_H
#define PROJECT_PLAYER_MOVE_H



#include "game_init.h"

//Function to control player moves
void player_turn (player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z,square spare[0][0]);

void spare_piece(player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z,int c,int d,square spare[0][0]);

#endif //PROJECT_PLAYER_MOVE_H