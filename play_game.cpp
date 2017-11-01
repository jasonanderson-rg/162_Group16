/************************************************************************************************************
 * Author: Group 16
 * Description: Main for the RPS Game.
 * *********************************************************************************************************/

#include "RPSGame.hpp"

int main()
{
	int seed = time(0);
	srand(seed);

	RPSGame RPS;
	RPS.game();
	return 0;
}
