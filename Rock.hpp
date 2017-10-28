/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the specification file for the Rock class.
** The Rock is subclass of Tool. It gets half strength against Paper and double
** strength against Scissors
**********************************************************************************/
#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"

class Rock : public Tool
{
	public:
		Rock(); //default constructor sets type to r and strength to 1
		Rock(int setStrength); //constructor sets strength to parameter
		virtual int fight(Tool *opponent); //compares opponent Tool strength to this Tool's strength to determine a winner
};
#endif

