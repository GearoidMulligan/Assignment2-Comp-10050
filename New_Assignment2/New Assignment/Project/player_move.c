# include "player_move.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void player_turn (player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z) {

    int a, b;
    int c, d;
    bool check = false;

    while (check == false) {
        printf("Player %d turn, Select which piece you would like to move (x,y): ", z);
        scanf("%d,%d", &a, &b);


        if (board[a][b].type == VALID && board[a][b].stack->p_color == players[z - 1].player_color) {
            printf("Valid Piece\n");
            check = true;
        } else {
            printf("invalid Piece, Select a piece of your color!\n");
        }
    }

    check = false;

    while (check == false) {

        printf("Player %d, where would you like to move the piece?(x,y)", z);
        scanf("%d,%d", &c, &d);


        if (((a - c) + (b - d)) == board[a][b].num_pieces || ((c - a) + (d - b)) == board[a][b].num_pieces) {
            printf("Valid Move\n");
            check = true;
        } else {
            printf("Invalid move, move a piece the same number as stacks on the square:");
        }
    }


    if (board[c][d].stack==NULL){
        piece *top = board[a][b].stack;
        piece *curr = top;
        board[a][b].stack = NULL;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = board[c][d].stack;
        board[c][d].num_pieces=board[a][b].num_pieces;
        board[a][b].num_pieces=0;
    }
    else {

        piece *top = board[a][b].stack;

        piece *curr = top;
        board[a][b].stack = NULL;
        board[a][b].num_pieces = 0;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = board[c][d].stack;

        board[c][d].stack = top;


        int count = 1;
        board[c][d].num_pieces = 0;
        piece *last = NULL;

        while (curr != NULL) {
            if (count < 5) {
                curr = curr->next;
                count++;
                board[c][d].num_pieces++;
            } else {
                last = curr;
            }
        }


        if (last != NULL) {
            curr = curr->next;
        }
        while (curr != NULL) {
            piece *toRemove = curr;
            curr = curr->next;
            free(toRemove);
        }
        last->next = NULL;
    }

}




