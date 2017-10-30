/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the implementation file for the RPSGame class.
** The RPSGame class is the class  used for playing the RPS game.
**********************************************************************************/

#include "RPSGame.hpp"


/******************************************************************************************
RPSGame::setToolStrengths()
Description: Default constructor that sets member variable type to 'r' and member
variable strength to 1
******************************************************************************************/

void RPSGame::setToolStrengths()
{
	rockStrength = oneOptionMenu("What will be rock's strength? ");
	paperStrength = oneOptionMenu("What will be paper's strength? ");
	scissorStrength = oneOptionMenu("What will be scissor's strength? ");
}


/******************************************************************************************
RPSGame::displayComputerTool()
Description: Displays the tool that the computer chose
******************************************************************************************/

void RPSGame::displayComputerTool()
{
	std::cout << "Computer chose ";
	if (compChoice->getType() == 'r')
	{
		std::cout << "rock.";
	} else if (compChoice->getType() == 'p')
	{
		std::cout << "paper.";
	} else
	{
		std::cout << "scissors.";
	}

	std::cout << std::endl;
}


/******************************************************************************************
RPSGame::analyzeResults()
Description: Determine and displays who won the round.
******************************************************************************************/

void RPSGame::analyzeResults()
{
	int winner = humanChoice->fight(compChoice);
	if ( winner == 1)
	{
		std::cout << "You win!!!";
		humanWins++;
	} else if (winner == 0)
	{
		std::cout << "Computer wins! :-(";
		computerWins++;
	} else
	{
		std::cout << "Tie Game!";
		ties++;
	}
	std::cout << std::endl;
}


/******************************************************************************************
RPSGame::displayResults()
Description: Display the current wins and ties totals
******************************************************************************************/

void RPSGame::displayResults()
{
	std::cout << "Human wins: " << humanWins << std::endl;
	std::cout << "Computer wins: " << computerWins << std::endl;
	std::cout << "Ties: " << ties << std::endl;
}

/******************************************************************************************
RPSGame::game()
Description: Plays the game until the user decides to quit
******************************************************************************************/

void RPSGame::game()
{
	while (userChoice())
	{
		computerChoice();
		displayComputerTool();
		analyzeResults();
		displayResults();
		delete compChoice;
		humanChoicesHistory.push_back(humanChoice);
	}
}



//One option menu with positive integer input validation
int RPSGame::oneOptionMenu(std::string a)
{
	std::cout << a << ": ";
	return validatePositive();
}

//Function to get a user's input and check if it is a positive integer. It will return the integer if valid.
int RPSGame::validatePositive()
{
	std::string input;
	bool again;

	//Loop endlessly until user provides a valid input
	do
	{
		getline(std::cin, input);
		again = false;
		//If first character is 0 or the string is null, print error and have user re-enter input
		if (input.length() == 0 || input[0] == '0')
		{
			again = true;
		}

		//If any character is non-numerical, print error and have user re-enter input
		if (!again)
		{
			for (int i = 0; i < static_cast<int>(input.length()); i++)
			{
				if (!isdigit(input[i]))
				{
					again = true;
				}
			}
		}

		//If input passes all of the tests, return the input as an integer
		if (!again)
		{
			return stoi(input);
		}

		//If input did not pass all the tests, have user try again
		std::cout << "Invalid format- Please enter a positive integer: ";
	} while (again);

	//function should never reach here, but if it does restart
	return validatePositive();
}