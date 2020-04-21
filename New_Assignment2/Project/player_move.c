# include "player_move.h"
#include <stdio.h>
void player_turn (player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z){

        int a,b;

        printf("Player %d turn, Select which piece you would like to move (x,y): ",z);
        scanf("%d,%d",&a,&b);

        if(board[a][b].type==VALID && board[a][b].stack->p_color == players[z-1].player_color){
            printf("Valid Piece\n");
        }
        else{
            printf("invalid Piece!\n");
        }

}



