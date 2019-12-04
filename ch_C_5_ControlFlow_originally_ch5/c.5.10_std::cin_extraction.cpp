/**
 * @file c.5.10_std::cin_extraction.cpp
 * @author ds9058.lee@gmail.com
 * @brief 
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 * @note
 * 1. A program that handles error cases well is said to be robust.
 * 2. When we use operator>> to get user input and put it into a variable, this is called an “extraction”. The >> operator is accordingly called the extraction operator when used in this context.
 */

#include <iostream>

double getDouble()
{
    while(true)
    {
        std::cout << "Enter a double value: ";
        double x;
        std::cin >> x;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Opps, that input is invalid. Please try again. \n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return x;
        }
    }
}

char getOperator()
{
    while(true)
    {
        std::cout << "Enter one of the following: +, -, *, / : ";
        char op;
        std::cin >> op;

        if(op == '+' || op == '-' || op == '*' || op == '/')
        {
            return op;
        }
        else
        {
            std::cout << "Oops, that input is invalid. Please try again. \n";
        }        
    }
}

void printResult(double x, char op, double y)
{
    if(op == '+')
    {
        std::cout << x << " + " << y << " is " << x+y << '\n';
    }
    else if(op == '-')
    {
        std::cout << x << " - " << y << " is " << x-y << '\n';
    }
    else if(op == '*')
    {
        std::cout << x << " * " << y << " is " << x*y << '\n';
    }
    else if(op == '/')
    {
        std::cout << x << " / " << y << " is " << x/y << '\n';
    }
    else
    {
        std::cout << "Something went wrong : printResult() got an invalid operator. \n";
    }
    
}

int main()
{
    double x = getDouble();
    char op = getOperator();
    char y = getDouble();

    printResult(x, op, y);

    return 0;
}