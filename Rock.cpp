/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the implementation file for the Rock class.
** The Rock is subclass of Tool. It gets half strength against Paper and double
** strength against Scissors
**********************************************************************************/
#include "Rock.hpp"


/******************************************************************************************
Rock::Rock()
Description: Default constructor that sets member variable type to 'r' and member 
variable strength to 1
******************************************************************************************/
Rock::Rock()
{
	this->setType('r');
	this->setStrength(1);
}
/******************************************************************************************
Rock::Rock()
Description: Overloaded constructor that sets that sets member variable type to 'r' and
member variable strength equal to the parameter
Parameter: The strength as an int
******************************************************************************************/
Rock::Rock(int setStrength) //constructor sets strength to parameter
{
	this->setType('r');
	this->setStrength(setStrength);
}
/******************************************************************************************
int Rock::fight()
Description: Compares opponent Tool strength to this Tool's strength to determine a winner
Parameter: A pointer to the opponent Tool
Returns: an int: 0 for a loss, 1 for a win, 2 for a tie
******************************************************************************************/
int Rock::fight(Tool *opponent)
{
	//If opponent is Paper
	if (opponent->getType() == 'p')
	{
		//If half of this tool's strength is more than the opponents strength
		//then this tool wins. Else if half this tool's strength is less than
		//then the opponent's strength, the opponents wins.  If both of those
		//are not true, then the strengths are equal and it is a tie
		if (this->halfStrength() > opponent->getStrength())
		{
			return 1;
		}
		else if (this->halfStrength() < opponent->getStrength())
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	//If opponent is Scissors
	else if (opponent->getType() == 's')
	{
	//If double this tool's strength is more than the opponents strength
	//then this tool wins. Else if double this tool's strength is less than
	//then the opponent's strength, the opponents wins.  If both of those
	//are not true, then the strengths are equal and it is a tie
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
	//If opponent is also Rock
	else if (opponent->getType() == 'r')
	{
	//If this tool's strength is more than the opponents strength
	//then this tool wins. Else if this tool's strength is less than
	//then the opponent's strength, the opponents wins.  If both of those
	//are not true, then the strengths are equal and it is a tie
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