

#include <stdio.h>
#include "input_output.h"


/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|   ");
                else {
                    if (board[i][j].stack->p_color == GREEN)
                    printf("| G ");

                    else
                    printf("| R ");
                }
            }
            else
                printf("| - ");


        }
        printf("|\n");
    }

    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                printf("Square[%d][%d]: %d\n", i, j, board[i][j].num_pieces);
            }
        }

        }
}

void player_move(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]){

}