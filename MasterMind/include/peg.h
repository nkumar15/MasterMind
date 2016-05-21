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
    void set_type(PegType type);
    PegType get_type();
};

class PegRow{

private:
    unsigned int num_pegs;
    vector<Peg> code_pegs_row;
    vector<Peg> key_pegs_row;

public:
    PegRow(unsigned int num_pegs);
    bool set_code_peg(unsigned int idx, Peg &peg);
    bool set_key_peg(unsigned int idx, Peg &peg);

};

#endif // PEG_H_INCLUDED
