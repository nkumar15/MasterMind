#ifndef PEG_H_INCLUDED
#define PEG_H_INCLUDED

#include "types.h"
#include <vector>
#include <iostream>

using namespace std;

/* Peg class to denote a single peg */
class Peg
{

private:
    PegColor color;
    PegType  peg_type;

public:
    Peg(PegType type, PegColor color);
    ~Peg() {}
    void set_color(PegColor color);
    PegColor get_color();
    void set_type(PegType type);
    PegType get_type();

};

/* Peg row */
class PegRow
{

private:
    unsigned int num_pegs;
    vector<Peg> pegs_row;

public:
    PegRow() {}
    PegRow(unsigned int num_pegs);
    bool set_peg(unsigned int idx, Peg &peg);
    Peg& get_peg(unsigned int idx);
    vector<Peg>& get_pegs_row();
};

#endif // PEG_H_INCLUDED
