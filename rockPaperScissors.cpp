/*
Name: Derrick Demers
Date: 2/19/24
The purpose of this program is to simulate the game Rock Paper Scissors
*/

#include <iostream>
#include <cstdlib> //this library allows us to use a function for random number generation rand and srand
#include <ctime> //library will allow use of current time and seed time for rng

#define ROCK 1
#define PAPER 2
#define SCISSORS 3 //usine the #define, the seeded random number based on time will define the outcome

using namespace std;

int main ()
{
    //paper beats rock
    //rock beats scissors
    //scissors beats paper
    //if a draw were to occur, the user and program would need to continue
    //  until a victor is made

    srand(time((unsigned int) NULL)); //creates a random number from the unsigned int depending on the time the program is ran

    int playerThrow = 0;
    int aiThrow = 0;
    bool draw = false; //checks for a draw game

    do
    {
        cout << "Select your throw." << endl
             << "1: Rock " << endl
             << "2. Paper " << endl
             << "3. Scissors " << endl
             << "Selection: ";

        cin >> playerThrow;

        cout << endl;

        //the rand() will throw and integer between 0...999999; we will apply % 3, we get an integer 0-2
        //example 10/3 -> remainder = 1
        //        11/3 -> 2
        //        12/3 -> 3

        aiThrow = (rand() % 3) + 1;

        if (aiThrow == ROCK)
        {
            cout << "AI throws ROCK" << endl;
        }
        else if (aiThrow == PAPER)
        {
            cout << "AI throws PAPER" << endl;
        }
        else if (aiThrow == SCISSORS)
        {
            cout << "AI throws SCISSORS" << endl;
        }

        draw = false; //setting the draw to false beforehand

        if (playerThrow == aiThrow)
        {
            draw = true; //turning the draw into true so the game continues
            cout << "Draw! Play Again!" << endl;
        }
        else if (playerThrow > 3 || playerThrow < 1)
        {
            draw = true;
            cout << "INVALID RESPONSE. Try again..." << endl;
        }
        
        else if (playerThrow == ROCK && aiThrow == SCISSORS)
        {
            cout << "ROCK beats SCISSORS. YOU WIN!!" << endl;
        }
        else if (playerThrow == ROCK && aiThrow == PAPER)
        {
            cout << "PAPER beats ROCK. YOU LOSE!!" << endl;
        }
        else if (playerThrow == PAPER && aiThrow == ROCK)
        {
            cout << "PAPER beats ROCK. YOU WIN!!" << endl;
        }
        else if (playerThrow == PAPER && aiThrow == SCISSORS)
        {
            cout << "SCISSORS beats PAPER. YOU LOSE!!" << endl;
        }
        else if (playerThrow == SCISSORS && aiThrow == PAPER)
        {
            cout << "SCISSORS beats PAPER. YOU WIN!!" << endl;
        }
        else if (playerThrow == SCISSORS && aiThrow == ROCK)
        {
            cout << "ROCK beats SCISSORS. YOU LOSE!!" << endl;
        }

        cout << endl;
        
    } while (draw); //continues to play if draw = true

    return 0;
}