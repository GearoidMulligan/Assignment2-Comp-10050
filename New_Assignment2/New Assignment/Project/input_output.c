#include <stdio.h>
#include "input_output.h"


/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE]) {
    printf("****** The Board ******\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == VALID) {
                if (board[i][j].stack == NULL)
                    printf("|   ");
                else {
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| G ");

                    else
                        printf("| R ");
                }
            } else
                printf("| - ");

        }
        printf("|\n");
    }


    printf("************Pieces*************\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == VALID) {
                if (board[i][j].stack == NULL)
                    printf("| 0 ");
                else {
                    printf("| %d ", count_stack(board[i][j].stack));
                    board[i][j].num_pieces=count_stack(board[i][j].stack);
                }
            } else
                printf("| - ");

        }
        printf("|\n");
    }
}


    void ending(player players[PLAYERS_NUM], int x) {

        if (x == 1) {
            printf("Player 1 wins!!!\n");
            printf("Name:%s\nColor:%u\nCaptured Tokens:%d", players[0].name, players[0].player_color,
                   players[0].opp_pieces);
        } else {
            printf("Player 2 wins!!!\n");
            printf("Name:%s\nColor:%u\nCaptured Tokens:%d", players[1].name, players[1].player_color,
                   players[1].opp_pieces);
        }


    }

    int count_stack(piece *s) {
        int count = 1;

        while (s->next != NULL) {
            s = s->next;
            count++;
        }

        return count;


    }