/*****************************
** Program Name: Input Validation
** Description:  Functions for Input Validation
*****************************/

#include "inputValidation.hpp"

/*****************************
** Description: Validates string input and returns the value as an int.
*****************************/
char stringValidation(std::string message)
{
    bool isValid = false;
    std::string input;

    while(!(isValid))
    {
        std::cout << message;
        std::getline (std::cin,input);
        
        if (input.size() == 1) {
            if (tolower(input[0]) == 'r' || tolower(input[0]) == 'p' || tolower(input[0])  == 's' || tolower(input[0]) == 'e') {
                isValid = true;
            }
        }
              
        if (!isValid) {
            std::cout << "Invalid input: Please enter r for rock, p for paper, s for scissors, or e for exit." << std::endl;
        }
    }
    char output = input[0];
    return output;

}


/*****************************
** Description: Validates string input as either 'y' or 'n'.
*****************************/
char ynValidation(std::string message)
{
    bool isValid = false;
    std::string input;

    while(!(isValid))
    {
        std::cout << message;
        std::getline (std::cin,input); 
        
        if (input.size() == 1) {
            if (tolower(input[0]) == 'y' || tolower(input[0]) == 'n') {
                isValid = true;
            }
        }
        
        if (!isValid) {
            std::cout << "Invalid input: Please enter y for yes or n for no." << std::endl;
        }

    }
    char output = input[0];
    return output;

}


/*****************************
** Description: Validate a user's input is a positive integer
*****************************/
int validatePositive()
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
