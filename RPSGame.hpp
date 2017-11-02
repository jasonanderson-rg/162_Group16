/*********************************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Group 16
** Date: 10/27/2017
** Description: This is the specification file for the RPSGame class.
** The RPSGame class is the class  used for playing the RPS game.
**********************************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "inputValidation.hpp"
#include "Tool.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdlib.h>

class RPSGame
{
private:
	Tool * humanChoice;
	Tool * compChoice;
	std::vector<Tool*> humanChoicesHistory;
	int humanWins;
	int computerWins;
	int ties;
	int paperStrength;
	int scissorStrength;
	int rockStrength;
public:
	RPSGame();
	~RPSGame();
	Tool* getHumanChoice();
	void setHumanChoice(Tool* tool);
	Tool* getComputerChoice();
	void setComputerChoice(Tool* tool);
	void setToolStrengths(); // Have the user set the strengths for each tool
	void displayComputerTool(); // Display the computer's choice
	void analyzeResults(); //Determine whether the player or computer won and display the winner of the round
	void displayResults(); // Display the win totals
	void game(); // Play the game
	bool userChoice(); // Lets the user choose which tool to play or whether to quit
	void computerChoice();
	int oneOptionMenu(std::string a); //One option menu with positive integer input validation
	std::vector<char> makeVect(int checkSize, int start); //returns vectors to compare human choice patterns
	bool equalVects(std::vector<char> search, std::vector<char> compare, int checkSize);//true if vectors equal
	Tool * computerChoice(int checkSize); //returns the choice that the computer wants to make
	Tool * randomChoice(); //returns a random tool pointer when there is not enough data
	Tool * analyzeMatches(std::vector<char> matches); //finds most frequent match and returns pointer
	bool greaterThan(int a, int b); //true if a is greater than b
	bool equalTo(int a, int b); //true if a is equal to b
};




#endif

