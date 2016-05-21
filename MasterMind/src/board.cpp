#include "../include/board.h"
#include <stdlib.h>
#include <time.h>

/* Helper function to initialize the board */
void GameBoard :: init(){
    code_rows.reserve(num_rows);
    feedback_rows.reserve(num_rows);

    for(unsigned int idx = 0; idx < pegs_in_row; idx++){
        code_rows.push_back(PegRow(pegs_in_row));
        feedback_rows.push_back(PegRow(pegs_in_row));
    }
}

/* Constructor */
GameBoard :: GameBoard(unsigned int _num_rows, unsigned int _num_pegs):
                num_rows(_num_rows),pegs_in_row(_num_pegs),shield_pegs_row(pegs_in_row){

    init();

    colornames.push_back("red");
    colornames.push_back("yellow");
    colornames.push_back("green");
    colornames.push_back("orange");
    colornames.push_back("voilet");
    colornames.push_back("blue");
    colornames.push_back("white");
    colornames.push_back("black");
    colornames.push_back("empty");

    color_codes.push_back(PegColor::RED);
    color_codes.push_back(PegColor::YELLOW);
    color_codes.push_back(PegColor::GREEN);
    color_codes.push_back(PegColor::ORANGE);
    color_codes.push_back(PegColor::VOILET);
    color_codes.push_back(PegColor::BLUE);
    color_codes.push_back(PegColor::WHITE);
    color_codes.push_back(PegColor::BLACK);
    color_codes.push_back(PegColor::EMPTY);
}

/* Reset the game board */
void GameBoard :: reset(){
    init();
}
PegColor GameBoard :: get_color(unsigned int code){
    return color_codes[code];
}

/* Get random color from range of colors */
PegColor GameBoard :: get_random_color(){

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

vector<Peg>& GameBoard :: get_code_peg_row(unsigned int row_idx){
    return code_rows[row_idx].get_pegs_row();
 }

vector<Peg>& GameBoard :: get_feedback_peg_row(unsigned int row_idx){
    return feedback_rows[row_idx].get_pegs_row();
 }

bool GameBoard :: set_shield_peg(unsigned int peg_idx, Peg &peg){
    shield_pegs_row.set_peg(peg_idx,peg);
    return true;
}

Peg& GameBoard :: get_shield_peg(unsigned int peg_idx){
    return shield_pegs_row.get_peg(peg_idx);
}

/* Create code peg for shield */
/* To be used by code maker */
void GameBoard :: create_shield_code(){
    srand(time(nullptr));
    for(unsigned int idx=0; idx < pegs_in_row; idx++){
        PegColor clr = get_random_color();
        Peg peg(PegType::CODE,clr);
        shield_pegs_row.set_peg(idx,peg);
    }
}

void GameBoard :: display_shield_code(){
    vector<Peg> pegs = shield_pegs_row.get_pegs_row();
    cout<<"Shield Colors: ";
    for(unsigned int idx = 0; idx < pegs.size(); idx++){
        Peg peg = pegs[idx];
        PegColor clr = peg.get_color();
        cout<<colornames[static_cast<int>(clr)]<<" ";
    }
    cout<<endl;
}

void GameBoard :: display_code_pegs(unsigned int idx){
    vector<Peg>  row = get_code_peg_row(idx);
    cout<<"Code pegs at index:" <<idx<<" "<<row.size()<<endl;
    for(Peg &peg : row)
    {
        PegColor clr = peg.get_color();
        cout<<colornames[static_cast<int>(clr)]<<" ";
    }
    cout<<endl;
}

void GameBoard :: display_feeback_code(unsigned int idx){
    vector<Peg>  row = get_feedback_peg_row(idx);
    for(Peg &peg : row)
    {
        PegColor clr = peg.get_color();
        cout<<colornames[static_cast<int>(clr)]<<" ";
    }
    cout<<endl;
}
/* set code peg in a row of code pegs */
/* To be used by code breaker */
bool GameBoard :: set_code_peg(unsigned int row_idx, unsigned int peg_idx, Peg &peg){

    if( row_idx >= code_rows.size())
        return false;

    code_rows[row_idx].set_peg(peg_idx,peg);
    return true;
}

Peg& GameBoard :: get_code_peg(unsigned int row_idx, unsigned int peg_idx){

    return code_rows[row_idx].get_peg(peg_idx);
}

bool GameBoard :: set_feedback_peg(unsigned int row_idx, unsigned int peg_idx, Peg &peg){

    if( row_idx >= code_rows.size())
        return false;

    feedback_rows[row_idx].set_peg(peg_idx,peg);
    return true;
}

Peg& GameBoard :: get_feedback_peg(unsigned int row_idx, unsigned int peg_idx){

    return feedback_rows[row_idx].get_peg(peg_idx);
}

bool GameBoard :: check_color_exist_in_shield(PegColor color){
    vector<Peg> pegs = shield_pegs_row.get_pegs_row();
    for(unsigned int idx=0; idx < pegs.size(); idx++){
        Peg peg = pegs[idx];

        if(peg.get_color() == color)
            return true;
    }

    return false;
}

bool GameBoard :: verify_guess(int attempt_number){

    vector<Peg> code_row = get_code_peg_row(attempt_number);
    vector<Peg> shield_row = shield_pegs_row.get_pegs_row();

    for(unsigned int idx = 0; idx < code_row.size(); idx++){

        Peg code_peg = code_row[idx];
        Peg shield_peg = shield_row[idx];

        if( code_peg.get_color() == shield_peg.get_color()){
            Peg peg(PegType::FEEDBACK,PegColor::WHITE);
            set_feedback_peg(attempt_number,idx,peg);

        }
        else if (check_color_exist_in_shield(code_peg.get_color())){
            Peg peg(PegType::FEEDBACK,PegColor::BLACK);
            set_feedback_peg(attempt_number,idx,peg);
        }
        else{
            Peg peg(PegType::FEEDBACK,PegColor::EMPTY);
            set_feedback_peg(attempt_number,idx,peg);
        }
   }

   unsigned int idx = 0;
   vector<Peg> feedback_row = get_feedback_peg_row(attempt_number);
   for(idx = 0; idx < feedback_row.size(); idx++){
        if (feedback_row[idx].get_color() != PegColor :: WHITE)
            break;
   }

   return idx == shield_row.size();
}
