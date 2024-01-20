// codsoft_task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;

class Calculator
{
private:
    float num1;
    float num2;
    char symbol;
public:
    Calculator()
    {
        num1 = 0;
        num2 = 0;
    }

    Calculator(float n1, float n2, char op)
    {
        num1 = n1;
        num2 = n2;
        symbol = op;
    }

    float performoperation()
    {
        if (symbol == '+')
            return num1 + num2;

        else if (symbol == '-')
            return num1 - num2;

        else if (symbol == '/')
            return num1 / num2;

        else if (symbol == '*')
            return num1 * num2;

        else if (symbol == '^')
            return pow(num1, num2);

        cout << "Error: Invalid operation." << endl;

        return 0;
    }
};

int main()
{
    float num1, num2;
    char symbol;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 673);

    cout << "------------------------" << endl;
    cout << "|  Arham's Calculator  |" << endl;
    cout << "------------------------" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    cout << "Enter first number: ";
    //cin >> num1;
    while (!(cin >> num1))
    {
        cin.clear();
        while (cin.get() != '\n'); 
        cout << "Invalid input. Enter a valid number: ";
    }

   /* cout << "Enter operation (+, -, *, /, ^): ";*/
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
    cout << "Enter operation (";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Red color
    cout << "+";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
    cout << ", ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Green color
    cout << "-";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
    cout << ", ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Light cyan color
    cout << "*";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
    cout << ", ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // Purple color
    cout << "/";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
    cout << ", ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Cyan color
    cout << "^";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
    cout << "): ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset to default color

   // cin >> symbol;
    while (!(cin >> symbol) || (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/' && symbol != '^'))
    {
        cin.clear();
        while (cin.get() != '\n'); 
        //cout << "Invalid input. Enter a valid operation (+, -, *, /, ^): ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
        cout << "Invalid input. Enter a valid operation (";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Red color
        cout << "+";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
        cout << ", ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Green color
        cout << "-";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
        cout << ", ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Light cyan color
        cout << "*";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
        cout << ", ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // Purple color
        cout << "/";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
        cout << ", ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Cyan color
        cout << "^";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Yellow color
        cout << "): ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset to default color
    }

    cout << "Enter second number: ";
    //cin >> num2;

    while (!(cin >> num2))
    {
        cin.clear();
        while (cin.get() != '\n'); 
        cout << "Invalid input. Enter a valid number: ";
    }

    Calculator calc(num1, num2, symbol);
    float result = calc.performoperation();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 673);
    cout << fixed << setprecision(2); 
    cout << "------------------------------" << endl;
    cout << "Result: " << num1 << " " << symbol << " " << num2 << " = " << result << endl;
    cout << "------------------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    return 0;
}


