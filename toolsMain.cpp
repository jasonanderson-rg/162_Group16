#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"

#include <iostream>

/*********************************************************************************
void testFight(Tool* p, Tool* c);
Description: Displayd player's type and strength, opponent's type and strength,
and the return value of the fight function, then deletes the objects pointed to
Parameters: Pointers to Tool objects
**********************************************************************************/

void testFight(Tool* player, Tool* computer)
{
	std::cout << "Player " << player->getType() << " " << player->getStrength();
	std::cout << " vs Opponent " << computer->getType() << " " << computer->getStrength();
	std::cout << " Result: " << player->fight(computer) << std::endl;
	delete player;
	delete computer;
}


/*********************************************************************************
int main()
Description: Creates two pointers to Tool, and then calls the testFight function 
to test the Tool::fight() results;
**********************************************************************************/
int main()
{

	Tool* p = nullptr;
	Tool* c = nullptr;
	
	p = new Rock;
	c = new Rock;
	testFight(p, c);	
	p = new Rock(2);
	c = new Rock;
	testFight(p, c);
	p = new Rock;
	c = new Rock(2);
	testFight(p, c);	
	p = new Rock(2);
	c = new Rock(2);
	testFight(p, c);
	std::cout << std::endl;

	p = new Paper;
	c = new Paper;
	testFight(p, c);
	p = new Paper(2);
	c = new Paper;
	testFight(p, c);
	p = new Paper;
	c = new Paper(2);
	testFight(p, c);
	p = new Paper(2);
	c = new Paper(2);
	testFight(p, c);
	std::cout << std::endl;

	p = new Scissors;
	c = new Scissors;
	testFight(p, c);
	p = new Scissors(2);
	c = new Scissors;
	testFight(p, c);
	p = new Scissors;
	c = new Scissors(2);
	testFight(p, c);
	p = new Scissors(2);
	c = new Scissors(2);
	testFight(p, c);
	std::cout << std::endl;

	//Test Rock
	p = new Rock;
	c = new Paper;
	testFight(p, c);
	p = new Rock(2);
	c = new Paper;
	testFight(p, c);
	p = new Rock(3);
	c = new Paper;
	testFight(p, c);
	p = new Rock(4);
	c = new Paper;
	testFight(p, c);
	p = new Rock;
	c = new Paper(2);
	testFight(p, c);
	p = new Rock(2);
	c = new Paper(2);
	testFight(p, c);
	std::cout << std::endl;

	p = new Rock;
	c = new Scissors;
	testFight(p, c);
	p = new Rock(2);
	c = new Scissors;
	testFight(p, c);
	p = new Rock(2);
	c = new Scissors(2);
	testFight(p, c);
	p = new Rock;
	c = new Scissors(2);
	testFight(p, c);
	p = new Rock;
	c = new Scissors(3);
	testFight(p, c);
	p = new Rock();
	c = new Scissors(4);
	testFight(p, c);
	std::cout << std::endl;

	//Test Paper
	p = new Paper;
	c = new Scissors;
	testFight(p, c);
	p = new Paper(2);
	c = new Scissors;
	testFight(p, c);
	p = new Paper(3);
	c = new Scissors;
	testFight(p, c);
	p = new Paper(4);
	c = new Scissors;
	testFight(p, c);
	p = new Paper;
	c = new Scissors(2);
	testFight(p, c);
	p = new Paper(2);
	c = new Scissors(2);
	testFight(p, c);
	std::cout << std::endl;

	p = new Paper;
	c = new Rock;
	testFight(p, c);
	p = new Paper(2);
	c = new Rock;
	testFight(p, c);
	p = new Paper(2);
	c = new Rock(2);
	testFight(p, c);
	p = new Paper;
	c = new Rock(2);
	testFight(p, c);
	p = new Paper;
	c = new Rock(3);
	testFight(p, c);
	p = new Paper();
	c = new Rock(4);
	testFight(p, c);
	std::cout << std::endl;

	//Test Scissors
	p = new Scissors;
	c = new Rock;
	testFight(p, c);
	p = new Scissors(2);
	c = new Rock;
	testFight(p, c);
	p = new Scissors(3);
	c = new Rock;
	testFight(p, c);
	p = new Scissors(4);
	c = new Rock;
	testFight(p, c);
	p = new Scissors;
	c = new Rock(2);
	testFight(p, c);
	p = new Scissors(2);
	c = new Rock(2);
	testFight(p, c);
	std::cout << std::endl;

	p = new Scissors;
	c = new Paper;
	testFight(p, c);
	p = new Scissors(2);
	c = new Paper;
	testFight(p, c);
	p = new Scissors(2);
	c = new Paper(2);
	testFight(p, c);
	p = new Scissors;
	c = new Paper(2);
	testFight(p, c);
	p = new Scissors;
	c = new Paper(3);
	testFight(p, c);
	p = new Scissors();
	c = new Paper(4);
	testFight(p, c);
	std::cout << std::endl;

	std::cin.ignore();
	
	return 0;
}

