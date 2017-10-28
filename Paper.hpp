/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the specification file for the Paper class.
** The Paper is subclass of Tool. It gets half strength against Scissors and double
** strength against Rock
**********************************************************************************/
#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"

class Paper : public Tool
{
public:
	Paper(); //default constructor sets type to r and strength to 1
	Paper(int setStrength); //constructor sets strength to parameter
	virtual int fight(Tool *opponent); //compares opponent Tool strength to this Tool's strength to determine a winner
};
#endif
