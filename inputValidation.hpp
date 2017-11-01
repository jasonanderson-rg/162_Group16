/******************************************
** Project Name: Input Validation
** Author: Jason Anderson
** Date: 10/1/17
** Description: This is the interface file for the Input Validation functions.
*******************************************/
#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
#include <string>
char stringValidation(std::string); //Declaration for inputValidation function that takes a string parameter for a message and returns a valid char
char ynValidation(std::string); //Declaration for ynValidation function that takes a string parameter for a message and returns a valid 'y' or 'n'
#endif
