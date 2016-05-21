#include <iostream>
#include "include/board.h"

using namespace std;

#define NUM_ROWS 12
#define NUM_PEGS 6

int main()
{
    cout<<"--------Color Menu--------"<<endl;
    cout<<"1. Red"<<endl;
    cout<<"2. Yellow"<<endl;
    cout<<"3. Green"<<endl;
    cout<<"4. Orange"<<endl;
    cout<<"5. Voilet"<<endl;
    cout<<"6. Blue"<<endl;

    GameBoard board(NUM_ROWS,NUM_PEGS);

    board.create_shield_code();
    board.display_shield_code();







    return 0;
}
