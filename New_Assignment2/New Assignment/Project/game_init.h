
#ifndef PROJECT_GAME_INIT_H
#define PROJECT_GAME_INIT_H



#define BOARD_SIZE 8
#define PLAYERS_NUM 2
#define PLAYER_NAME 20

//colors that a piece can have
typedef enum color {
    RED,
    GREEN
}color;

// Square types
//INVALID: squares that are on the sides and where no piece can be placed
//VALID: squares where it is possible to place a piece or a stack
typedef enum square_type {
    VALID,
    INVALID
}square_type;

//Player
typedef struct player{
    //the color associated with the player
    color player_color;
    //player name
    char name [PLAYER_NAME];
    //used to keep track of spare pieces and opponents captured pieces
    int opp_pieces;
    int own_pieces;
}player;

// A piece
typedef struct piece {
    //the color associated with a piece
    color p_color;

    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.
    struct piece * next;

}piece;

// A Square of the board
typedef struct square {
    // type of the square (VALID/INVALID)
    square_type type;

    //the piece or the top piece on the stack
    piece * stack;

    //number of pieces on the square
    int num_pieces;

}square;

//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);

//function to create spare piece to add to a stack
void initialize_spare(square spare[0][0]);




#endif //PROJECT_GAME_INIT_H
