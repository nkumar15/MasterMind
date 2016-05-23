#include <iostream>
#include "include/board.h"
#include <stdlib.h>

using namespace std;

#define NUM_ROWS 12
#define NUM_PEGS 4

void print_color_banner()
{
    cout<<"--------Color Menu---------------------------------"<<endl;
    cout<<"0. RED"<<endl;
    cout<<"1. BLUE"<<endl;
    cout<<"2. YELLOW"<<endl;
    cout<<"3. GREEN"<<endl;
    cout<<endl;
}

void print_info_banner()
{
    cout<<"--------Game Instructions--------------------------"<<endl;
    cout<<endl;
    cout<<"Shield has been generated with "<< NUM_PEGS <<" colors."<<endl;
    cout<<"Please guess correct colors in correct order."<<endl;
    cout<<"You will receive feedback code in WHITE BLACK and EMPTY colors."<<endl;
    cout<<"WHITE color means you have guessed correct color at correct place in shield colors."<<endl;
    cout<<"BLACK color means you have guessed correct color but it is present at different position in shield colors code."<<endl;
    cout<<"EMPTY color means you have guessed in correct color in shield code."<<endl;
    cout<<"You have maximum "<< NUM_ROWS <<" attempts to guess shield code."<<endl;
    cout<<endl;

}

int main()
{

    GameBoard board(NUM_ROWS,NUM_PEGS);
    int peg_count = 0;
    int input_color = 0;
    int attempts = 0;
    int temp;
    peg_count = 0;

    board.create_shield_code();

    while ( attempts < NUM_ROWS )
    {
        system("cls");
        print_color_banner();
        print_info_banner();
        //board.display_shield_code();
        peg_count = 0;

        cout<<"-------Play area-------------------------------"<<endl;
        cout<<endl<<"Attempt: "<< attempts + 1<<endl;


        while(peg_count < NUM_PEGS)
        {
            do
            {
                cout<<"Enter peg color in digit: ";
                cin>>input_color;
                if( input_color >= 6)
                    cout<<"Invalid color. Please reenter "<<endl;
                else
                    break;
            }
            while(true);

            PegColor color = board.get_color_code(input_color);
            Peg peg(PegType::CODE,color);
            board.set_code_peg(attempts,peg_count,peg);
            peg_count++;
        }

        board.display_code_pegs(attempts);

        bool win = board.verify_guess(attempts);

        board.display_feeback_code(attempts);

        if( win == true)
        {
            cout<<"You won"<<endl;
            break;
        }
        else
        {
            cout<<endl<<"Sorry your code didn't match."<<endl;
            cout<<endl<<"Please press enter for next attempt."<<endl;
        }

        attempts++;
        cin.get();
        cin.get();
    }

    if(attempts == NUM_ROWS)
        cout<<endl<<"You have exhausted all attempts:"<<endl;

    cout<<endl<<"Game exiting now. Bye...";
    return 0;
}
