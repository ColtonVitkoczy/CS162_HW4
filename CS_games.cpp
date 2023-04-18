#include "library.h"


// Colton Vitkoczy
//
// The purpose of this file is to contain the functions for constructors and destructors for 
// the games struct and library class. It then goes on to build the functions to input games
// in a LLL, and then display the games inputed traversing through the LLL.

// Constructor for games struct. This function sets the value of each pointer for adynamic array
// of characters to NULL or 0 for player_count. 
games::games()
{
	name = NULL;
	type = NULL;
	description = NULL;
	player_count = 0;
}

// Destructor empty since memory is deleted in the library deconstructor.
games::~games(){}

// Constructor setting head to nullptr
library::library()
{
	head = nullptr;
}

// This function is the destructor for the library class. this function deallocates the memory for the LLL
// and deletes the nodes. First, it declares a pointer variable current to struct node. Next it enters into a 
// while loop traversing through the list and deleting the dynamic lists in each node, then the node itself
// until it gets to the end of the loop. 
library::~library()
{
	node * current;
	while (head)
	{
		current = head->next;
		delete [] head->data.name;
		delete [] head->data.type;
		delete [] head->data.description;
		delete head;
		head = current;
	}
}

// This function is to input the games. First, asking the user if they'd like to inpt a game
// it then creates a pointer to the same place in memory as head, grabs input from the user
// and stores it in the new node, doing this for each dynamically allocated array then connects
// the new node to the front of the list.
void library::input_games()
{
	char response = 'N';
	
	cout << "Would you like to read in a game?: ";
	cin >> response;
	cin.ignore(100, '\n');

	while('Y' == toupper(response))
	{
		node * current = head;
		head = new node;
		
		cout << "Please enter the name of the game: " << endl;

		char temp_name[NAME];
		cin.get(temp_name, NAME, '\n');
		cin.ignore(100, '\n');

		head->data.name = new char [strlen(temp_name)+1];
		strcpy(head->data.name, temp_name);
	
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
		cout << "Please enter the type of the game: " << endl;

		char temp_type[TYPE];
		cin.get(temp_type, TYPE, '\n');
		cin.ignore(100, '\n');

		head->data.type = new char [strlen(temp_type)+1];
		strcpy(head->data.type, temp_type);

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		cout << "Please enter a description of the game: " << endl;

		char temp_desc[DESCRIPTION];
		cin.get(temp_desc, DESCRIPTION, '\n');
		cin.ignore(100, '\n');

		head->data.description = new char [strlen(temp_desc)+1];
		strcpy(head->data.description, temp_desc);

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		cout << "Please enter the number of players: " << endl;

		cin >> head->data.player_count;
		cin.ignore(100, '\n');

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		head->next = current;
		
		cout << "Another?: ";
		cin >> response;
		cin.ignore(100, '\n');
	}
}

// THis function displays all traversing through the list and outputting the contents
// in each node until at the end of the list.
void library::display_all()
{
	node * current = head;
	while(NULL != current)
	{
		cout << current->data.name << endl;
		cout << current->data.type << endl;
		cout << current->data.description << endl;
		cout << current->data.player_count << endl;
		
		current = current->next;
	}
}

