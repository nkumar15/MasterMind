#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "peg.h"
#include <vector>
#include <iostream>

using namespace std;

class GameBoard{

private:
unsigned int num_peg_rows;
unsigned int pegs_in_row;
GameState game_state;

vector<PegRow> code_key_peg_rows;
PegRow shield_pegs_row;

void init();
PegColor get_random_color();

public:
    GameBoard(unsigned int num_rows, unsigned int num_pegs);
    ~GameBoard();

    void reset();

    void create_shield_code();
    bool set_code_peg(unsigned int row_idx, unsigned int peg_idx, Peg &peg);

};

#endif //
