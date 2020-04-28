#include "player_move.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "game_init.h"

void player_turn (player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z,square spare[0][0]) {


    int a, b;
    int c, d;
    bool check = false;

    while (check == false) {
        printf("Player %d turn, Select which piece you would like to move (r,c),\n or enter 10,10 to select a spare piece(you have %d spare pieces): ", z,players[z-1].own_pieces);
        scanf("%d,%d", &a, &b);


        if(a==10&&b==10){
            if(players[z-1].own_pieces==0){
                printf("You have no spare pieces to use");
            }
            else{
                printf("Player %d, where would you like to place the piece?(r,c):", z);
                scanf("%d,%d", &c, &d);
                if(board[c][d].type==VALID){
                    printf("valid piece");
                    spare_piece(players,board,z,c,d,spare);
                    check=true;
                        }
                    }
                }

        else if ((board[a][b].type == VALID) && (board[a][b].stack->p_color == players[z - 1].player_color)) {
            printf("Valid Piece\n");
            check = true;
        } else {
            printf("invalid Piece, Select a piece of your color!\n");
        }
    }

    check = false;

    while (check == false) {

        printf("Player %d, where would you like to move the piece?(r,c):", z);
        scanf("%d,%d", &c, &d);


        if ((((a - c) + (b - d)) == board[a][b].num_pieces || ((c - a) + (d - b)) == board[a][b].num_pieces)&&(board[a][b].type==VALID)) {
            printf("Valid Move\n");
            check = true;
        } else {
            printf("Invalid move, move a piece the same number as stacks on the square or to a valid square:");
        }
    }


    if (board[c][d].stack==NULL){
        piece *top = board[a][b].stack;
        piece *curr = top;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = board[c][d].stack;
        board[c][d].num_pieces=board[a][b].num_pieces;
        board[a][b].num_pieces=0;
        board[a][b].stack = NULL;
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
                if (last != NULL) {
                    curr = curr->next;

                    while (curr != NULL) {
                        piece *toRemove = curr;
                        if (toRemove->p_color == players[z - 1].player_color) {
                            players[z - 1].own_pieces++;
                        } else {
                            players[z - 1].opp_pieces++;
                        }
                        curr = curr->next;
                        free(toRemove);
                    }
                    last->next = NULL;
                }

        }

    }

}

void spare_piece(player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z,int c,int d,square spare[0][0]){

    if(board[c][d].stack==NULL){
        if(players[z-1].player_color==RED) {
            board[c][d].type = VALID;
            board[c][d].stack = (piece *) malloc(sizeof(piece));
            board[c][d].stack->p_color = RED;
            board[c][d].stack->next = NULL;
            board[c][d].num_pieces = 1;
        }
        else{
            board[c][d].type = VALID;
            board[c][d].stack = (piece *) malloc (sizeof(piece));
            board[c][d].stack->p_color = GREEN;
            board[c][d].stack->next = NULL;
            board[c][d].num_pieces = 1;
        }

    }
    else{
        spare[0][0].type = VALID;
        spare[0][0].stack = (piece *) malloc(sizeof(piece));
        spare[0][0].stack->p_color = players[z-1].player_color;
        spare[0][0].stack->next = NULL;
        spare[0][0].num_pieces = 1;

        piece *top = spare[0][0].stack;
        piece *curr = top;
        
        spare[0][0].stack=NULL;
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
            if (last != NULL) {
                curr = curr->next;

                while (curr != NULL) {
                    piece *toRemove = curr;
                    if (toRemove->p_color == players[z - 1].player_color) {
                        players[z - 1].own_pieces++;
                    } else {
                        players[z - 1].opp_pieces++;
                    }
                    curr = curr->next;
                    free(toRemove);
                }
                last->next = NULL;
            }

        }


    }
}



