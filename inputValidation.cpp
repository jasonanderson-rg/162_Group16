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
        
        if (input.size() == 1) {
            if (tolower(input[0]) == 'r' || tolower(input[0]) == 'p' || tolower(input[0])  == 's' || tolower(input[0]) == 'e') {
                isValid = true;
            }
        }
              
        if (!isValid) {
            std::cout << "Invalid input: Please enter r for rock, p for paper, s for scissors, or e for exit." << std::endl;
        }
        
        /*int total = 0;
        for(int i = 0; i < input.size(); i++)
        {   
            total += input[i];
            if ((tolower(input[i]) == 114) || (tolower(input[i]) == 112) || (tolower(input[i]) == 115) || (tolower(input[i]) == 101)) 
            {
                isValid = true;
            } 
            else if (total > 115)
            {
                isValid = false;
                std::cout << "Invalid input: Please enter r for rock, p for paper, s for scissors, or e for exit." << std::endl;
            }  
            else
            {
                isValid = false;
                std::cout << "Invalid input: Please enter r for rock, p for paper, s for scissors, or e for exit." << std::endl;
            }  
        }*/
    }
    char output = input[0];
    return output;

}


/*****************************
** Description: Validates string input as either 'y' or 'n'.
*****************************/
char ynValidation(std::string message)
{
    bool isValid = false;
    std::string input;

    while(!(isValid))
    {
        std::cout << message << std::endl;
        std::getline (std::cin,input); 
        
        if (input.size() == 1) {
            if (tolower(input[0]) == 'y' || tolower(input[0]) == 'n') {
                isValid = true;
            }
        }
        
        if (!isValid) {
            std::cout << "Invalid input: Please enter y for yes or n for no." << std::endl;
        }
        
        
        /*int total = 0;
        for(int i = 0; i < input.size(); i++)
        {   
            total += input[i];
            if ((tolower(input[i]) == 121) || (tolower(input[i]) == 110)) 
            {
                isValid = true;
            } 
            else if (total > 121)
            {
                isValid = false;
                std::cout << "Invalid input: Please enter y for yes or n for no." << std::endl;
            }  
            else
            {
                isValid = false;
                std::cout << "Invalid input: Please enter y for yes or n for no." << std::endl;
            }  
        }*/
    }
    char output = input[0];
    return output;

}



/*int main()
{
    char choice = stringValidation("Please choose your class.\nPress \"r\" for Rock\nPress \"p\" for Paper\nPress \"s\" for Scissors\n");
    std::cout << choice << std::endl;
}*/
