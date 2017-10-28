/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the implementation file for the Tool class.
** The Tool is an abstract class that is used for a game of Rock, Paper, Scissors
** that is used as the base for Rock, Paper,
** Derivatives: Rock class, Paper class, Scissors class
**********************************************************************************/
#include "Tool.hpp"

/***************************************************************************************
void Tool::setStrength()
Description: Sets member variable strengh
Parameter: The number to set the strength to as an int
****************************************************************************************/
void Tool::setStrength(int setStrength)
{
	this->strength = setStrength;
}
/****************************************************************************************
int Tool::getStrength()
Description: Returns member variable strengh
Returns: The strength as int
*****************************************************************************************/
int Tool::getStrength()
{
	return strength;
}
/****************************************************************************************
void Tool::setType()
Description: Sets member variable type
Parameter: The type as a char (r = Rock, p = Paper, s = Scissors)
*****************************************************************************************/
void Tool::setType(char setType)
{
	this->type = setType;
}
/****************************************************************************************
char Tool::getType()
Description: Returns member variable type
Returns: The type as a char (r = Rock, p = Paper, s = Scissors)
*****************************************************************************************/
char Tool::getType()
{
	return type;
}
/******************************************************************************************
int Tool::doubleStrength()
Description: Returns a value that is double the tool's strength to compare when fighting.
Returns: Double the member variable strength as an int
******************************************************************************************/
int Tool::doubleStrength()
{
	return strength * 2;
}
/******************************************************************************************
Tool::Tool()
Description: Default constructor that sets member variable strength to 1
******************************************************************************************/
Tool::Tool()
{
	this->setStrength(1);
}
/******************************************************************************************
Tool::Tool()
Description: Overloaded constructor that sets member variable strength equal to the
parameter
Parameter: The strength as an int
******************************************************************************************/
Tool::Tool(int setStrength)
{
	this->setStrength(setStrength);
}
/******************************************************************************************
Tool::Tool()
Description: Virtual destructor 
******************************************************************************************/
Tool::~Tool()
{

}
