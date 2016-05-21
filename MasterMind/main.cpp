#include <iostream>
#include "include/board.h"

using namespace std;

#define NUM_ROWS 12
#define NUM_PEGS 6

void print_banner(){
    cout<<"--------Color Menu--------"<<endl;
    cout<<"0. Red"<<endl;
    cout<<"1. Yellow"<<endl;
    cout<<"2. Green"<<endl;
    cout<<"3. Orange"<<endl;
    cout<<"4. Voilet"<<endl;
    cout<<"5. Blue"<<endl;

}

int main()
{
    print_banner();
    GameBoard board(NUM_ROWS,NUM_PEGS);

    board.create_shield_code();
    board.display_shield_code();

    int peg_count = 0;
    int input_color = 0;
    PegColor color = PegColor::EMPTY;
    int attempts = 0;
peg_count = 0;
    while ( attempts < NUM_ROWS )
    {
        peg_count = 0;
        while(peg_count < NUM_PEGS)
        {
            do{
                cout<<"Enter peg color in digit: ";
                cin>>input_color;
                if( input_color >= 6)
                    cout<<"Invalid color. Please reenter "<<endl;
                else
                    break;
             }while(true);

            PegColor color = board.get_color(input_color);
            Peg peg(PegType::CODE,color);
            board.set_code_peg(attempts,peg_count,peg);
            peg_count++;
        }

        board.display_code_pegs(attempts);

        bool win = board.verify_guess(attempts);

        board.display_feeback_code(attempts);

        if( win == true){
            cout<<"You won"<<endl;
            break;
        }
        else
            cout<<"sorry "<<endl;
        attempts++;
    }

    cout<<"Bye...";
    return 0;
}
