#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "peg.h"
#include <vector>

using namespace std;

class GameBoard{

private:
unsigned int num_peg_rows;
unsigned int pegs_in_row;
GameState game_state;

vector<PegRow> code_key_peg_rows;
vector<PegRow> shield_peg_row;

void init();

public:
    GameBoard(unsigned int num_rows, unsigned int num_pegs);
    void reset();
};

#endif //
