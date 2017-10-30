/*****************************
** Program Name: Input Validation
** Author: Jason Anderson
** Date: 10/8/17
** Description:  Functions for Input Validation
*****************************/
#include "inputValidation.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
/*****************************
** Description: Validates string input and returns the value as an int.
*****************************/
char stringValidation(std::string message)
{
    bool isValid = false;
    std::string input;

    while(!(isValid))
    {
        std::cout << message << std::endl;
        std::getline (std::cin,input); 
        int total;
        for(int i = 0; i < input.size(); i++)
        {   
            total += input[i];
            if ((tolower(input[i]) == 114) || (tolower(input[i]) == 112) || (tolower(input[i]) == 115)) 
            {
                isValid = true;
            } 
            else if (total > 115)
            {
                isValid = false;
                std::cout << "Invalid input: Please enter r for rock, p for paper, or s for scissors." << std::endl;
            }  
            else
            {
                isValid = false;
                std::cout << "Invalid input: Please enter r for rock, p for paper, or s for scissors." << std::endl;
            }  
        }
    }
    char output = input[0];
    return output;

}   


int main()
{
    char choice = stringValidation("Please choose your class.\nPress \"r\" for Rock\nPress \"p\" for Paper\nPress \"s\" for Scissors\n");
    std::cout << choice << std::endl;
}
