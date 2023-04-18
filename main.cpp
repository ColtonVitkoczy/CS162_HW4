#include "library.h"

// Colton Vitkoczy
// This is the main.cpp used to call the functions from CS_games.cpp

void input_games();

int main()
{
	node * head;
	head = NULL;

	library gameslib; // declares a class object of library called gameslib

	gameslib.input_games(); // calls the function to input
	gameslib.display_all(); // calls the function to display

	return 0;
}

