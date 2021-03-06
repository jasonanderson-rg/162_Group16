/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the implementation file for the Paper class.
** The Paper is subclass of Tool. It gets half strength against Scissors and double
** strength against Rock
**********************************************************************************/
#include "Paper.hpp"


/******************************************************************************************
Paper::Paper()
Description: Default constructor that sets member variable type to 'r' and member
variable strength to 1
******************************************************************************************/
Paper::Paper()
{
	this->setType('p');
	this->setStrength(1);
}
/******************************************************************************************
Paper::Paper()
Description: Overloaded constructor that sets that sets member variable type to 'r' and
member variable strength equal to the parameter
Parameter: The strength as an int
******************************************************************************************/
Paper::Paper(int setStrength) //constructor sets strength to parameter
{
	this->setType('p');
	this->setStrength(setStrength);
}
/******************************************************************************************
int Paper::fight()
Description: Compares opponent Tool strength to this Tool's strength to determine a winner
Parameter: A pointer to the opponent Tool
Returns: an int: 0 for a loss, 1 for a win, 2 for a tie
******************************************************************************************/
int Paper::fight(Tool *opponent)
{
	//If opponent is Scissors
	if (opponent->getType() == 's')
	{
        //Compare tool strengths and return result
		if (this->getStrength() > opponent->doubleStrength())
		{
			return 1;
		}
		else if (this->getStrength() < opponent->doubleStrength())
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	//If opponent is Rock
	else if (opponent->getType() == 'r')
	{
        //Compare tool strengths and return result
		if (this->doubleStrength() > opponent->getStrength())
		{
			return 1;
		}
		else if (this->doubleStrength() < opponent->getStrength())
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	//If opponent is also Paper
	else if (opponent->getType() == 'p')
	{
        //Compare tool strengths and return result
		if (this->getStrength() > opponent->getStrength())
		{
			return 1;
		}
		else if (this->getStrength() < opponent->getStrength())
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
}
