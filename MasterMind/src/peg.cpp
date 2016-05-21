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
    code_pegs_row.reserve(this->num_pegs);
    key_pegs_row.reserve(this->num_pegs);

    for(unsigned int idx = 0; idx < num_pegs; idx++){
        code_pegs_row.push_back(Peg(PegType::CODE, PegColor::EMPTY));
        key_pegs_row.push_back(Peg(PegType::KEY, PegColor::BLACK));
    }

}

/* set code peg in a code peg row */
bool PegRow :: set_code_peg(unsigned int idx, Peg &peg){

    if ( idx >= code_pegs_row.size())
        return false;

    code_pegs_row[idx] = peg;
    return true;
}

/* set key in a key peg row */
bool PegRow :: set_key_peg(unsigned int idx, Peg &peg){

    if ( idx >= key_pegs_row.size())
        return false;

    key_pegs_row[idx] = peg;
    return true;
}

