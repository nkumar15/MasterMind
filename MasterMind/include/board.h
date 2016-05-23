#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "peg.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>

using namespace std;

class GameBoard
{

private:
    unsigned int num_rows;
    unsigned int pegs_in_row;
    vector<PegRow> code_rows;
    vector<PegRow> feedback_rows;
    PegRow shield_pegs_row;
    unordered_map<int, string> colornames;


    void init();
    PegColor get_random_color();
    vector<Peg>& get_code_peg_row(unsigned int row_idx);
    vector<Peg>& get_feedback_peg_row(unsigned int row_idx);

    bool set_shield_peg(unsigned int peg_idx, Peg &peg);
    Peg& get_shield_peg(unsigned int peg_idx);

    bool check_color_exist_in_shield(PegColor color);

public:
    GameBoard(unsigned int _num_rows, unsigned int _num_pegs);
    ~GameBoard() {}

    void reset();

    string get_color_name(PegColor clr);
    PegColor get_color_code(int code);

    bool set_code_peg(unsigned int row_idx, unsigned int peg_idx, Peg &peg);
    Peg& get_code_peg(unsigned int row_idx, unsigned int peg_idx);


    bool set_feedback_peg(unsigned int row_idx, unsigned int peg_idx, Peg &peg);
    Peg& get_feedback_peg(unsigned int row_idx, unsigned int peg_idx);


    void create_shield_code();
    void display_shield_code();
    void display_code_pegs(unsigned int idx);
    void display_feeback_code(unsigned int idx);
    bool verify_guess(int attempt);

};



#endif //
