

#include <stdio.h>

#include "input_output.h"
#include "player_move.h"
#include "move_stacks.h"



int main() {

    // declaration of the players and the board
    int x=0;
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    square spare[0][0];


    initialize_players(players);
    initialize_board(board);
    print_board(board);
    initialize_spare(spare);


while(x!=2){
   player_turn(players, board, 1,spare);
   print_board(board);
   player_turn(players, board, 2,spare);
   print_board(board);
   x++;
}


    return 0;
}



