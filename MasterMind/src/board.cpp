#include "../include/board.h"

void GameBoard :: init(){

    game_state = GameState::READY;
    code_key_peg_rows.reserve(num_peg_rows);
    shield_peg_row.reserve(pegs_in_row);

    for(unsigned int idx = 0; idx < num_peg_rows; idx++){
        code_key_peg_rows.push_back(PegRow(pegs_in_row));
    }
    shield_peg_row.push_back(PegRow(pegs_in_row));
}

GameBoard :: GameBoard(unsigned int num_rows, unsigned int num_pegs){
    num_peg_rows = num_rows;
    pegs_in_row = num_pegs;
    init();
}

void GameBoard :: reset(){
    init();
}
