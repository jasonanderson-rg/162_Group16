/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the specification file for the Scissors class.
** The Scissors is subclass of Tool. It gets half strength against Rock and double
** strength against Paper
**********************************************************************************/
#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "Tool.hpp"

class Scissors : public Tool
{
public:
	Scissors(); //default constructor sets type to r and strength to 1
	Scissors(int setStrength); //constructor sets strength to parameter
	virtual int fight(Tool *opponent); //compares opponent Tool strength to this Tool's strength to determine a winner
};
#endif

