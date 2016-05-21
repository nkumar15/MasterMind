#include "../include/peg.h"

/* Peg constructor to initialize with color */
Peg :: Peg(PegType type,PegColor color){
    this->color = color;
    this->peg_type = type;
}

/* set color in a peg */
void Peg :: set_color(PegColor color){
    this->color = color;
}

/* get color of a peg */
PegColor Peg :: get_color(){
    return color;
}

/* create a pegs row */
PegRow :: PegRow(unsigned int num_pegs){

    this->num_pegs = num_pegs;
    pegs_row.reserve(this->num_pegs);

    for(unsigned int idx = 0; idx < num_pegs; idx++){
        pegs_row.push_back(Peg(PegType::CODE, PegColor::EMPTY));
    }
}

/* set code peg in a code peg row */
bool PegRow :: set_peg(unsigned int idx, Peg &peg){

    if ( idx >= pegs_row.size())
        return false;

    pegs_row[idx] = peg;
    return true;
}

Peg& PegRow :: get_peg(unsigned int idx){
    return pegs_row[idx];
}

vector<Peg> PegRow :: get_pegs_row(){
    return pegs_row;
}
