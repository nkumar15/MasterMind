#ifndef PEG_H_INCLUDED
#define PEG_H_INCLUDED

#include "types.h"
#include <vector>

using namespace std;

class Peg{

private:
    PegColor color;
    PegType  peg_type;

public:
    Peg(PegType type, PegColor color);
    ~Peg(){}
    void set_color(PegColor color);
    PegColor get_color();
};

class PegRow{

private:
    unsigned int num_pegs;
    vector<Peg> code_pegs_row;
    vector<Peg> key_pegs_row;

public:
    PegRow(unsigned int num_pegs);
};

#endif // PEG_H_INCLUDED
