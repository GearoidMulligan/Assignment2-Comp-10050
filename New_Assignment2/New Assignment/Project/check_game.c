
#include "check_game.h"

int end_con(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]){

    int p1=0;
    int p2=0;

    for (int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j].type==VALID && (board[i][j].stack!=0)){
                if(board[i][j].stack->p_color == players[0].player_color){
                    p1++;
                } else if (board[i][j].stack->p_color == players[1].player_color){
                    p2++;

                }
            }
        }
    }
    if(p1 ==0){
        return 1;
    }
    else if(p2==0){
        return 2;
    }
    else{
        return 0;
    }

}