#include "player_move.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "game_init.h"

void player_turn (player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z,square spare[0][0]) {
//these 4 ints are used to select the row and column for the chosen piece/stack and the row and column to place it.
    int a, b;
    int c, d;
    bool check = false;
//boolean algebra used here to make sure players input correct values
    while (check == false) {
        printf("Player %d turn, Select which piece you would like to move (r,c),\n or enter 10,10 to select a spare piece(you have %d spare pieces): ", z,players[z-1].own_pieces);
        scanf("%d,%d", &a, &b);

//case for if player wants to place a spare piece
        if(a==10&&b==10){//if condition used to check if the player has a spare piece available to use
            if(players[z-1].own_pieces==0){
                printf("You have no spare pieces to use.\n");
            }
            else{
                printf("Player %d, where would you like to place the piece?(r,c):", z);
                scanf("%d,%d", &c, &d);
                if(board[c][d].type==VALID){
                    printf("valid piece");
                    spare_piece(players,board,z,c,d,spare);//parameters passed onto another function below on line 114
                    check=true;
                        }
                    }
                }
//if user does not want to use a spare piece then the values are passed onto this condition ot ensure that a valid piece is chosen and patches the players color
        else if ((board[a][b].type == VALID) && (board[a][b].stack->p_color == players[z - 1].player_color)&&(board[a][b].stack!=NULL)&&(a>=0&&a<=8)&&(b>=0&&b<=8)) {
            printf("Valid Piece\n");
            check = true;
        } else {
            printf("invalid Piece, Select a piece of your color!\n");
        }

    }

    check = false;

    //while loop used also with boolean algebra to choose a valid square on the board to place the chosen piece/stack
    while (check == false) {


        printf("Player %d, where would you like to move the piece?(r,c):", z);
        scanf("%d,%d", &c, &d);

//if condition here used to make sure chosen square is valid
        if ((((a - c) + (b - d)) == board[a][b].num_pieces || ((c - a) + (d - b)) == board[a][b].num_pieces)&&(board[a][b].type==VALID)&&(c>=0&&c<=8)&&(d>=0&&d<=8)) {
            printf("Valid Move\n");
            check = true;
        } else {
            printf("Invalid move, move a piece the same number as stacks on the square or to a valid square.\n");
        }
    }

//this below is responsible for adding pieces onto each other using linked lists

    if (board[c][d].stack==NULL){
        //if the chosen square has no pieces on it then the following code is executed
        piece *top = board[a][b].stack;
        board[c][d].stack = (piece *) malloc(sizeof(piece));//allowing a stack to be placed onto the square by making it not equal to null
        piece *curr = top;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = board[c][d].stack;
        board[c][d].stack->p_color=players[z-1].player_color;
        board[a][b].stack = NULL;
    }
    //if there is already at least one piece then this is loop is executed
    else {

        piece *top = board[a][b].stack;

        piece *curr = top;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = board[c][d].stack;

        board[c][d].stack = top;
        board[a][b].stack = NULL;
        int count = 1;
        piece *last = NULL;
//checking if the stack is above 5 pieces
        while (curr != NULL) {
            if (count < 5) {
                curr = curr->next;
                count++;
            } else {
                last = curr;
            }
                if (last != NULL) {
                    curr = curr->next;
//if over 5 then pieces are removed and stored as spare pieces or opponents trapped pieces
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

//function to add a spare piece onto the board
void spare_piece(player players[PLAYERS_NUM],square board[BOARD_SIZE][BOARD_SIZE],int z,int c,int d,square spare[0][0]){
//if placing a spare piece onto an empty board then this happens
    if(board[c][d].stack==NULL){
        //same as set_red function in game_init
        if(players[z-1].player_color==RED) {
            board[c][d].type = VALID;
            board[c][d].stack = (piece *) malloc(sizeof(piece));
            board[c][d].stack->p_color = RED;
            board[c][d].stack->next = NULL;
        }
        else{
            board[c][d].type = VALID;
            board[c][d].stack = (piece *) malloc (sizeof(piece));
            board[c][d].stack->p_color = GREEN;
            board[c][d].stack->next = NULL;
        }

    }
    //if the stack already has a piece or stack on it then this code is executed
    else{
        //dont know if this is the best way to do it but couldnt think of another way, i imagined creating an imaginary piece on another board then putting that piece onto the selected square
        spare[0][0].type = VALID;
        spare[0][0].stack = (piece *) malloc(sizeof(piece));
        spare[0][0].stack->p_color = players[z-1].player_color;
        spare[0][0].stack->next = NULL;

        piece *top = spare[0][0].stack;
        piece *curr = top;

        spare[0][0].stack=NULL;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = board[c][d].stack;

        board[c][d].stack = top;


        int count = 1;
        piece *last = NULL;
//same code as in function above to check if stack is over 5 pieces
        while (curr != NULL) {
            if (count < 5) {
                curr = curr->next;
                count++;
            } else {
                last = curr;
            }
            if (last != NULL) {
                curr = curr->next;

                while (curr != NULL) {
                    piece *toRemove = curr;
                    //pieces removed and stored based on which pieces they are
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



