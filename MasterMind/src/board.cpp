#include "../include/board.h"
#include <stdlib.h>
#include <time.h>

/* Helper function to initialize the board */
void GameBoard :: init(){

    game_state = GameState::READY;
    code_key_peg_rows.reserve(num_peg_rows);

    for(unsigned int idx = 0; idx < num_peg_rows; idx++){
        code_key_peg_rows.push_back(PegRow(pegs_in_row));
    }

}

/* Constructor */
GameBoard :: GameBoard(unsigned int num_rows, unsigned int num_pegs):num_peg_rows(num_rows),
                        shield_pegs_row(num_pegs),pegs_in_row(num_pegs){
    init();
}

/* Reset the game board */
void GameBoard :: reset(){
    init();
}

/* Get random color from range of colors */
PegColor GameBoard :: get_random_color(){
    srand(time(nullptr));
    int code = rand() % pegs_in_row;

    PegColor color = PegColor::EMPTY;

    switch(code){
        case 0:
            color = PegColor::RED;
            break;
        case 1:
            color = PegColor::YELLOW;
            break;
        case 2:
            color = PegColor::GREEN;
            break;
        case 3:
            color = PegColor::ORANGE;
            break;
        case 4:
            color = PegColor::VOILET;
            break;
        case 5:
            color = PegColor::BLUE;
            break;
        default:
            cout<<"Invalid random color";
            exit(0);
    }

    return color;
}

/* Create code peg for shield */
/* To be used by code maker */
void GameBoard :: create_shield_code(){

    game_state = GameState::PLAYING;

    for(unsigned int idx=0; idx < pegs_in_row; idx++){
        PegColor clr = get_random_color();
        Peg peg(PegType::CODE,clr);
        shield_pegs_row.set_code_peg(idx,peg );
    }
}

/* set code peg in a row of code pegs */
/* To be used by code breaker */
bool GameBoard :: set_code_peg(unsigned int row_idx, unsigned int peg_idx, Peg &peg){

    if( row_idx >= code_key_peg_rows.size())
        return false;

    return code_key_peg_rows[row_idx].set_code_peg(peg_idx,peg);

}
