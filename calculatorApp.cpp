/*
Name: DERRICK DEMERS
Date: 9/10/2024
Purpose: The purpose of this program is to run as a simple calculator, calculating two numbers with basic arithmetic
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string operation;  //define the variables
    double num1, num2;

    cout << "Enter the first number: "; //getting user input
    cin >> num1;

    cout << "Enter the Operation (+, -, *, /): "; //getting the operation needed for solving
    cin >> operation;

    cout << "Enter the second number: "; //getting last number of the problem
    cin >> num2;

    //checking the entered operation
    if(operation == "+")
    {
        cout << num1 + num2;
    }
    else if (operation == "-")
    {
        cout << num1 - num2;
    }
    else if (operation == "*")
    {
        cout << num1 * num2;
    }
    else if (operation == "/")
    {
        cout << num1 / num2;
    }
    else
    {
        cout << "Error! " << endl
             <<  "Not a recognized operation" << endl;
    }
    return 0;
}