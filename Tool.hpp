/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the specification file for the Tool class.
** The Tool is an abstract class that is used for a game of Rock, Paper, Scissors
** Derivatives: Rock class, Paper class, Scissors class
**********************************************************************************/
#ifndef TOOL_HPP
#define TOOL_HPP
class Tool
{
	private:
		int strength; //holds the strength of the tool
		char type; //holds a character to identify the type of the tool(r, p or s)

	protected:		
		void setStrength(int setStrength); //used to set the strength member variable
		void setType(char setType); //used to set the type member variable


	public:
		int getStrength(); //returns the strength member variable
		char getType(); //returns the type member variable
		int halfStrength(); //returns a value that is half the tool's strength to compare when fighting.
		int doubleStrength(); //returns value that is double the tool's strength to compare when fighting
		Tool(); //default constructor that sets strength to 1
		Tool(int setStrength); // overloaded constructor sets strength member equal to the parameter strength
		virtual ~Tool(); //destructor
		virtual int fight(Tool *opponent) = 0; //compares opponent tool strength to current tool strength to determine a winner
};
#endif
