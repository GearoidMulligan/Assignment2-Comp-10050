

#include <stdio.h>

#include "input_output.h"
#include "player_move.h"
#include "check_game.h"


int main() {

    // declaration of the players and the board and spare piece
    int x=0;
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    square spare[0][0];

//initializing the players and boards, aswell as the spare piece
    initialize_players(players);
    initialize_board(board);
    print_board(board);
    initialize_spare(spare);

//this while loop is responsible for controlling the player moves and checking if any player has won at the end
while(x== 0){
   player_turn(players, board, 1,spare);
   print_board(board);
   player_turn(players, board, 2,spare);
   print_board(board);
   x = end_con(board,players);
}
//when the loop above is broken the ending stats are declared below
 ending(players,x);

    return 0;
}



