

#include <stdio.h>

#include "input_output.h"
#include "player_move.h"



int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    player_turn(players,board,1);
    print_board(board);
    player_turn(players,board,2);
    print_board(board);


    return 0;
}



