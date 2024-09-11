/*
Name: Derrick Demers
Date: 92/24
The purpose of this program is to simulate the game of Tic Tac Toe
*/

#include<iostream>
#include<ctime> //used to generate random numbers

using namespace std;

//creating different routines that will give us our board and allow us to make our moves
void drawBoard(char *spaces);
void playerMoves(char *spaces, char player);
void compMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; //array of 9 empty spaces for 9 spots on the board

    char player = 'X'; //player is always the X, sorry but that's the way it is
    char computer = 'O'; //computer player is always O
    bool running = true; //what keeps the game running after every turn

    drawBoard(spaces); //the routine that will draw and redraw the board after every turn

    while(running) //this continues while the game is still on/true
    {
        playerMoves(spaces, player); //going into the playerMoves function
        drawBoard(spaces); //draws the board 
        if(checkWinner(spaces, player, computer)) //checks to see if there is a winner after each turn
        {
            running = false; 
            break; //if the game is not running then the loop breaks
        }
        else if (checkTie(spaces)) //checks to see if there is a tie
        {
            running = false;
            break;
        }
        
        compMove(spaces, computer); //this is the computer players turn
        drawBoard(spaces); //draws the board after computer player's turn
        if(checkWinner(spaces, player, computer)) //checks for a winner after the computer player takes their turn
        {
            running = false;
            break;
        }
        else if (checkTie(spaces)) //checks for a tied game
        {
            running = false;
            break;
        }
    }

    cout << "Thanks for playing!!" << endl; //if the game running = false then the game ends
    
    return 0;
}

void drawBoard(char *spaces) //function used to draw the board after every turn
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  | "  << spaces[1] << "   |  "  << spaces[2] << "   " << endl; //spaces for where the players put their marks
    cout << "_____|_____|_____" << endl;                                                          //using the spaces from the space array
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  | "  << spaces[4] << "   |  "  << spaces[5] << "   " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  | "  << spaces[7] << "   |  "  << spaces[8] << "   " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

void playerMoves(char *spaces, char player) //function for the players turn
{
    int num;
    do
    {
        cout << "Enter a spot to place your marker (1-9)";
        cin >> num;
        num--; //number must be subtracted since array goes from 0-8 rather than 1-9
        if (spaces[num] == ' ')
        {
            spaces[num] = player; //player enters a spot on the board so long as it is between 1-9 and it is empty
            break;
        }
        
    }while (!num > 0 || !num < 8); //it will continuously loop if they enter a nuumber not within the array
    
}

void compMove(char *spaces, char computer) //function for the computer players turn
{
    int num;
    srand(time(0)); //creats and stores a random number

    while(true)
    {
        num = rand() % 9; //number is divided by 9
        if(spaces[num] == ' ') //checks if the number has been previously taken
        {
            spaces[num] = computer; //places number in the array and thus on the board
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) //function used to check if anyone has won
{
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) //checks for horizontal win ---
    {
        spaces[0] == player ? cout << "You win!!" : cout << "You lose!!"; //checks if computer or player has won
    }

    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) //checks for horizontal win ---
    {
        spaces[3] == player ? cout << "You win!!" : cout << "You lose!!"; 
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) //checks for horizontal win ---
    {
        spaces[6] == player ? cout << "You win!!" : cout << "You lose!!"; 
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) //checks for vertical win |
    {
        spaces[0] == player ? cout << "You win!!" : cout << "You lose!!"; 
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) //checks for vertical win |
    {
        spaces[1] == player ? cout << "You win!!" : cout << "You lose!!"; 
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) //checks for vertical win |
    {
        spaces[2] == player ? cout << "You win!!" : cout << "You lose!!"; 
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) //checks for diagonal win / 
    {
        spaces[0] == player ? cout << "You win!!" : cout << "You lose!!"; 
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) //checks for diagonal win /
    {
        spaces[2] == player ? cout << "You win!!" : cout << "You lose!!"; 
    }
    else
    {
        return false; //returns that no one has won yet
    }
    return true;
}

bool checkTie(char *spaces) //checks if there is a tied game
{
    for(int i = 0; i < 9; i++) //counter used to check how many spaces are occupied by players
    {
        if(spaces[i] == ' ') 
        {
            return false; //if any of the spaces are still empty then the game will continue
        }
    }

    cout << "It's a tie!!" << endl;

    return true; //if all spaces are filled without a winner then the game ends at a tie
}