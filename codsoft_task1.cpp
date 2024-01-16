//// codsoft_task1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

class NumberGuess
{
private:
    int number;
    HANDLE hConsole;

public:
    NumberGuess()
    {
        number = 0;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    NumberGuess(int n)
    {
        number = n;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    void printBox()
    {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "--------------------------" << endl;
        cout << "|  Number Guessing Game  |" << endl;
        cout << "--------------------------" << endl;
        SetConsoleTextAttribute(hConsole, 15);
    }

    void guess()
    {
        int userguess = 909090;

        printBox();
        SetConsoleTextAttribute(hConsole, 3);
        cout << "I have selected a number between 1 and 10. Can you guess it?" << endl;
        SetConsoleTextAttribute(hConsole, 15);

        while (number != userguess)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Enter your guess: ";
            cin >> userguess;

            // add a while loop to check for non integer inputs
            while (userguess < 0 || userguess >= 11)
            {
                cout << "In-Valid input" << endl;
                cout << "Re-enter number = ";
                cin >> userguess;
            }
            cout << endl;

            if (number - userguess == 2 || number - userguess == 1)
            {
                cout << "Your guess is close. Aim slightly higher." << endl;
            }
            else if (number - userguess == -2 || number - userguess == -1)
            {
                cout << "Your guess is close. Aim slightly lower." << endl;
            }
            else if (number < userguess)
            {
                cout << "Your guess is too high. Try a lower number." << endl;
            }
            else if (number > userguess)
            {
                cout << "Your guess is too low. Try a higher number." << endl;
            }
            else if (number == userguess)
            {
                cout << "Congratulations! You guessed the correct number: " << number << endl;
                cout << "Thank you for playing this game. Goodbye!" << endl;
            }

            this_thread::sleep_for(chrono::seconds(2));
            system("cls"); // This clears the screen; may not work on all systems
            printBox();
        }
    }
};

int main()
{
    srand(time(0));
    int randomnumber = (rand() % 10) + 1; // I am generating a random number here which the user will guess

    NumberGuess n1(randomnumber);

    n1.guess();

    return 0;
}

