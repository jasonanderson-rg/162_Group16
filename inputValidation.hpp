/******************************************
** Project Name: Input Validation
** Description: This is the interface file for the Input Validation functions.
*******************************************/
#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
#include <string>
#include <iostream>

char stringValidation(std::string); //Declaration for inputValidation function that takes a string parameter for a message and returns a valid char
char ynValidation(std::string); //Declaration for ynValidation function that takes a string parameter for a message and returns a valid 'y' or 'n'
int validatePositive(); //Validate a user's input is a positive integer
#endif
