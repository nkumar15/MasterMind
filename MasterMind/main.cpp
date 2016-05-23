#include <iostream>
#include "include/board.h"
#include "include/types.h"
#include <stdlib.h>
#include <memory>

using namespace std;

#define NUM_ROWS 10
#define NUM_PEGS 4

void print_color_banner(shared_ptr<GameBoard> ptr)
{
    cout<<"--------Color Menu---------------------------------"<<endl;
    cout<<(int) PegColor::RED << " : " << ptr->get_color_name(PegColor::RED)<<endl;
    cout<<(int) PegColor::BLUE << " : " << ptr->get_color_name(PegColor::BLUE)<<endl;
    cout<<(int) PegColor::YELLOW << " : " << ptr->get_color_name(PegColor::YELLOW)<<endl;
    cout<<(int) PegColor::GREEN << " : " << ptr->get_color_name(PegColor::GREEN)<<endl;
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

    shared_ptr<GameBoard> board_ptr(new GameBoard(NUM_ROWS,NUM_PEGS));
    int peg_count = 0;
    int input_color = 0;
    int attempts = 0;

    /* Generate the shield code */
    board_ptr->create_shield_code();

    /* Run loop player exhaust its number of attempts */
    do
    {
        system("cls");
        print_color_banner(board_ptr);
        print_info_banner();
        //board_ptr->display_shield_code();
        peg_count = 0;

        cout<<"-------Play area-------------------------------"<<endl;
        cout<<endl<<"Attempt: "<< attempts + 1<<endl;

        while(peg_count < NUM_PEGS)
        {
            /* If user enters wrong color code. Ask him to re-enter */
            do
            {
                cout<<"Enter peg color in digit: ";
                cin>>input_color;
                if( input_color >= NUM_PEGS )
                    cout<<"Invalid color. Please reenter "<<endl;
                else
                    break;
            }
            while(true);

            /* Create a colored code peg and set it into row of code pegs in board */
            PegColor color = board_ptr->get_color_code(input_color);
            Peg peg(PegType::CODE,color);
            board_ptr->set_code_peg(attempts,peg_count,peg);
            peg_count++;
        }

        /* Display the color representation of code pegs entered by user. */
        board_ptr->display_code_pegs(attempts);

        /* Verify the code pegs entered by player */
        bool win = board_ptr->verify_guess(attempts);

        /* Display the feedback code to the user */
        board_ptr->display_feeback_code(attempts);

        /* If users win greet him and exit */
        if( win == true)
        {
            cout<<"Congratulations! You won."<<endl;
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
    } while ( attempts < NUM_ROWS );

    /* Display message to user if he has exhausted his attempts */
    if(attempts == NUM_ROWS)
        cout<<endl<<"You have exhausted your all attempts."<<endl;

    cout<<endl<<"Game exiting now. Bye...";
    return 0;
}
