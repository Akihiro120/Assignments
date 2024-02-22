/*
Description:
Write a C++ program that implements a simple calculator.The program should be able to perform 
basic arithmetic operations such as addition, subtraction, multiplication, 
and division on two numbers entered by the user.Additionally, 
the program should provide a menu - driven interface for the user to choose the operation 
they want to perform.After each operation, the program should display the result to the user.

Requirements :

    The program should display a menu to the user with options for addition, subtraction, multiplication, and division.
    The user should be prompted to enter two numbers and choose an operation from the menu.
    Depending on the user's choice, the program should perform the selected operation and display the result.
    The program should handle division by zero gracefully and display an appropriate error message if encountered.
    Use appropriate functions to modularize your code.
    The program should keep running until the user chooses to exit.
    */

#include <iostream>
bool quit = false;

void display_arithmetic_operations()
{
    std::cout << "Simple Calculator" << "\n";
    std::cout << "\t1) Addition" << "\n";
    std::cout << "\t2) Subtraction" << "\n";
    std::cout << "\t3) Division" << "\n";
    std::cout << "\t4) Multiplication" << "\n";
    std::cout << "\t5) Quit" << "\n";
}

// perform addition operation
double addition(double x, double y)
{
    return x + y;
}

// perform subtraction operation
double subtraction(double x, double y)
{
    return x - y;
}

// perform multiplication operation
double multiplication(double x, double y)
{
    return x * y;
}

// perform division operation
double division(double x, double y)
{
    // check for division by zero
    if (y == 0)
    {
        std::cout << "Error: Division By Zero is Invalid" << std::endl;
    }

    return x / y;
}

double operation_prompt(double x, double y)
{
    int operation = 0;
    std::cout << "\nChoose An Operation: ";
    std::cin >> operation;

    // based on the operation choosen perform
    switch (operation)
    {
        case 1:
        {
            return addition(x, y);
            break;
        }

        case 2:
        {
            return subtraction(x, y);
            break;
        }

        case 3:
        {
            return division(x, y);
            break;
        }

        case 4:
        {
            return multiplication(x, y);
            break;
        }

        case 5:
        {
            quit = true;
            break;
        }
    }
}

void calculator()
{
    std::cout << "\n";
    display_arithmetic_operations();

    double x = 0.0, y = 0.0;
    std::cout << "\n" << "Input Two Values" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        // input two values or x, y, determined by the "i" index
        std::cout << ((i == 0) ? "x: " : "y: ");
        std::cin >> ((i == 0) ? x : y);
    }

    // allow user to choose the operator
    double answer = operation_prompt(x, y);

    std::cout << "The Answer is: " << answer << std::endl;
}

int main()
{
    // determine if the user is quitting the program
    while (!quit)
    {
        // if the program is still running recusively continue this function
        calculator();
    }

	return 0;
}