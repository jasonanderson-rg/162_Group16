/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the implementation file for the RPSGame class.
** The RPSGame class is the class  used for playing the RPS game.
**********************************************************************************/

#include "RPSGame.hpp"


/******************************************************************************************
RPSGame::RPSGame()
Description: This constructor initializes the data members to a default value, with the
 exception of humanChoice and compChoice.
******************************************************************************************/
RPSGame::RPSGame()
{
	this->humanChoicesHistory = {};
	this->humanWins = 0;
	this->computerWins = 0;
	this->ties = 0;
	this->paperStrength = 1;
	this->scissorStrength = 1;
	this->rockStrength = 1;
	humanChoice = nullptr;
	compChoice = nullptr;
}


/******************************************************************************************
RPSGame::~RPSGame()
Description: This destructor frees up the memory allocated for the humanChoice and
 compChoice data members.
******************************************************************************************/
RPSGame::~RPSGame()
{
	
	if (compChoice != nullptr)
	{
		delete this->compChoice;
	}

	int size = humanChoicesHistory.size();
	for (int i = 0; i < size; i++)
	{	
		if (humanChoicesHistory[i] != nullptr)
		{
			delete humanChoicesHistory[i];
		}
	}
}


/******************************************************************************************
RPSGame::getHumanChoice()
Description: Accessor function for humanChoice.
******************************************************************************************/
Tool* RPSGame::getHumanChoice()
{
	return this->humanChoice;
}


/******************************************************************************************
RPSGame::setHumanChoice()
Description: Mutator function for humanChoice.
******************************************************************************************/
void RPSGame::setHumanChoice(Tool* tool)
{
	this->humanChoice = tool;
}


/******************************************************************************************
RPSGame::getComputerChoice()
Description: Accessor function for compChoice.
******************************************************************************************/
Tool* RPSGame::getComputerChoice()
{
	return this->compChoice;
}


/******************************************************************************************
RPSGame::setComputerChoice()
Description: Mutator function for compChoice.
******************************************************************************************/
void RPSGame::setComputerChoice(Tool* tool)
{
	if (compChoice != nullptr)
	{
		delete this->compChoice;
	}
	this->compChoice = tool;
}


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
	char choice = ynValidation("Welcome to Rock, Paper, Scissors! Do you want to choose different strengths for the tools? (y-yes, n-no): ");
	if (choice == 'y') {
		setToolStrengths();
	}
	
	while (userChoice())
	{
		compChoice = computerChoice(4); //recusive call to computer choice
		displayComputerTool();
		analyzeResults();
		displayResults();
		delete compChoice;
		compChoice = nullptr;
		humanChoicesHistory.push_back(humanChoice);
	}
}


/******************************************************************************************
RPSGame::userChoice()
Description: Gets input from the user for their RPS choice. Returns true if user chooses
 to continue playing and false otherwise.
******************************************************************************************/
bool RPSGame::userChoice()
{
	auto choice = stringValidation("Choose your tool (r-rock, p-paper, s-scissor, e-exit): ");
	switch (choice) {
		case 'r':
			setHumanChoice(new Rock(rockStrength));
			return true;
		case 'p':
			setHumanChoice(new Paper(paperStrength));
			return true;
		case 's':
			setHumanChoice(new Scissors(scissorStrength));
			return true;
		default: break;
	}
	return false;
}


/******************************************************************************************
 * std::vector<char> makeVect(int checkSize, int start)
 * Description: This function will return a vector of chars representing the type of tool 
 * 	the user chose. The checkSize parameter will determine how large of a vector will 
 * 	be returned, and the start parameter determines where in humanChoices the vector 
 * 	will start from. 
 * ***************************************************************************************/
std::vector<char> RPSGame::makeVect(int checkSize, int start)
{
	std::vector<char> choices;
	for (int i = 0; i < checkSize; i++)
	{
		choices.push_back(humanChoicesHistory[start - i]->getType());
	}
	return choices;
}


/******************************************************************************************
 * bool equalVects(std::vector<char> search, std::vector<char> compare, int checkSize)
 * Description: This functio will take two vectors as parameters as well as a size. The vectors
 * 	are compared and if they are equal this function returns true. 
 * ***************************************************************************************/
bool RPSGame::equalVects(std::vector<char> search, std::vector<char> compare, int checkSize)
{
	for (int i = 0; i < checkSize; i++)
	{
		if (search[i] != compare[i])
			return false;
	}
	return true;
}


/****************************************************************************************
 * Tool * randomChoice()
 * Description: returns random computer choice when there is not enough data to make a 
 * 	"Smart" Choice.
 * *************************************************************************************/
Tool * RPSGame::randomChoice()
{
	int randChoice = rand() % 3 + 1;
	if (randChoice == 1)
	{
		return new Rock(rockStrength);
	}
	else if (randChoice == 2)
	{
		return new Paper(paperStrength);
	}
	else 
	{
		return new Scissors(scissorStrength);
	}
}


/****************************************************************************************
 * Tool * analyzeMatches(std::vector<char> matches)
 * Description: This function will look through a vector and determine the most frequent 
 * 	choice, then return a tool pointer to the tool that will beat that choice. 
 * **************************************************************************************/
Tool * RPSGame::analyzeMatches(std::vector<char> matches)
{
	int r = 0;
	int p = 0;
	int s = 0;
	int size = matches.size();
	//tally the frequencies
	for (int i = 0; i < size; i++)
	{
		if (matches[i] == 'r')
			r++;	
		else if (matches[i] == 'p')
			p++;
		else
			s++;
	}
	int tieBreak = rand() % 2; //random tie breaker for if frequencies are the same.

	//determine return value
	if (greaterThan(r, p) && greaterThan(r, s)) // rock is most frequent computer thinks human will choose rock
	{
		return new Paper(paperStrength); //return paper since that beats rock
	}
	else if (greaterThan(p, r) && greaterThan(p, s)) //paper is most frequent computer thinks human will choose paper
	{
		return new Scissors(scissorStrength); // return scissors since that beats paper
	}
	else if (greaterThan(s, r) && greaterThan(s, p)) //Scissors is most frequent computer thinks human will choose scissors
	{
		return new Rock(rockStrength); //return rock since that beats scissors
	}
	else if (equalTo(r, p) && greaterThan(r, s)) //r and p are same but greater than s computer thinks human will choose r or p
	{
		if (tieBreak == 0)
		{
			return new Paper(paperStrength);
		}
		else
		{
			return new Scissors(scissorStrength);
		}
	}
	else if (equalTo(p, s) && greaterThan(p, r)) //p and s are same but greater than r computer thinks human will choose p or s
	{
		if (tieBreak == 0)
		{
			return new Scissors(scissorStrength);
		}
		else
		{
			return new Rock(rockStrength);
		}
	}
	else if (equalTo(s, r) && greaterThan(s, p)) // s and r are same but greater than p computer thinks human will choose s or r
	{
		if (tieBreak == 0)
		{
			return new Rock(rockStrength);
		}
		else
		{
			return new Paper(paperStrength);
		}
	}
	else // all tools have same frequency
	{
		return randomChoice();
	}
}


/************************************************************************************************************
 * bool greaterThan(int a, int b)
 * Description: helper function for analyze mataches. Returns true if a is greater than b.
 * *********************************************************************************************************/
bool RPSGame::greaterThan(int a, int b)
{
	if (a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/************************************************************************************************************
 * bool equalTo(int a, int b)
 * Description: Helper function for analyzeMatches. Returns true if a and b are equal.
 * *********************************************************************************************************/
bool RPSGame::equalTo(int a, int b)
{
	if (a == b)
	{
		return true;
	}
	else 
	{
		return false;
	}
}


/*****************************************************************************************
 * computerChoice(int checkSize) 
 * Description: This function will return a pointer to a tool that is the computers 
 * 	choice. This is based on the history of the human choices, or is pseudorandom, if 
 * 	there is not enough data. 
 * **************************************************************************************/
Tool * RPSGame::computerChoice(int checkSize)
{
	
	int checkStart = humanChoicesHistory.size() - 1; // need to start at the last position of the vector. 
	int checkEnd = checkStart - checkSize;
	
	if (checkSize < 2 || checkSize >= checkStart) // if checksize is 1 or if the checkSize is >= Vector do a random choice
		return randomChoice();
	std::vector<char> search = makeVect(checkSize, checkStart);

	std::vector<char> results;	//vector to hold matches
	while (checkEnd >= 0)
	{
		checkStart--;	//each iteration move start and end back to check the next piece of humanChoicesHistory
		checkEnd--;
		std::vector<char> compare = makeVect(checkSize, checkStart); //get compare vectory from HCH
		if (equalVects(search, compare, checkSize))
		{
			results.push_back(humanChoicesHistory[checkStart + 1]->getType());//if match add the type directly befor match.
		}
	}
	if (!results.empty()) //if results is not empty
	{
		return analyzeMatches(results);// function to search results and pass a pointer to tool that is most frequent
	}
	else
	{
		return computerChoice(checkSize - 1);
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
