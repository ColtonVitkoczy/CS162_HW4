#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// Colton Vitkoczy
// This file contains the prprocessor directives and contains the constamts,
// structs, and class.

// Constants
 const int NAME = 50; // For sizing the dynamic array of name
 const int TYPE = 40; // For sizing the dynamic array of type
 const int DESCRIPTION = 200; // For sizing the dynamic array of description

// struct of games containing the data type srequired
struct games
{
	games(); //constructor
	~games();//deconstructor
	int player_count; // Declares object for amount of players 
	char * name;      // pointer for name
	char * type;      // pointer for type
	char * description; // pointer for description
};

// Struct for the nodes
struct node
{
	games data;  // Nested node of the struct games called data
	node * next; // recursive pointer for next in node

};

//
class library
{
	public:
		library(); //constructor
		~library();//deconstructor
		void display_all(); // prototype for display all
		void input_games(); // prototype for inputing games
	private:
		node * head; // pointer of type node called head.
};

