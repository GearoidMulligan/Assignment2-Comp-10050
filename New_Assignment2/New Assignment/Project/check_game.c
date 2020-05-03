
#include "check_game.h"
//function declaration here
int end_con(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]){

    //p1 and p2 represent player 1 and player 2 variables for the top color on each stack
    int p1=0;
    int p2=0;

    //nested for loop used to go through each square in the board and check which piece is on top, p1 or p2 is incremented accordingly
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
    //if statements here used to check if p1 or p2 has won, the opposite player number is returned as they are the winner
    if(p1 ==0 && players[0].own_pieces==0){
        return 2;
    }
    else if(p2==0 && players[0].own_pieces==0){
        return 1;
    }
    //if neither of these if statements are true then 0 is returned which loops everything again in main0
    else{
        return 0;
    }

}