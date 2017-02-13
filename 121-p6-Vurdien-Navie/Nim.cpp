//Nim game: contains the nim game which generates an array with a random number of rows that contain a random number of pins. responses must be formatted like shown in the read me file.
//Navie Vurdien
//email: nvurdien@hotmail.com
#include "stdafx.h"
#include "Nim.h"
#include "dout.h"
#include <iostream>
#include <cstdlib>//srand
#include <ctime>//time
#include <cmath>
#include <vector>
using namespace std;

//==========
//| Set Up |
//==========
//generates random number of rows & pins
//Touches: g_arraysize, a_game
//line count = 8
void Nim::setup()
{
	srand(static_cast<unsigned int>(time(0)));//generate random-like number
	g_arraysize = rand(); //generates a random number for the array size
	g_arraysize = 3 + (g_arraysize % 3); //gets a number from 3-5
	a_game.resize(g_arraysize);//changes the size of the array to the number generated
	for (int ix = 0; ix < g_arraysize; ix++)//loops through the rows
	{
		int px = rand();//generates a random number for the number of pins in the row
		px = 3 + (px % 6);//gets a number from 3-8
		a_game[ix] = px;//puts that number into that cell in the vector.
	}
}

//----------
//| Prompt |
//----------
//response prompt
//Touches: g_arraysize, a_game
//line count = 6
void Nim::prompt()
{
	for (int ix = 0; ix < g_arraysize; ix++)//loops through the array
	{
		cout <<"\t"<< ix << ": ";//outputs the row number
		for (int bx = 0; bx < a_game[ix]; bx++)//takes the number in that row
			cout << "| ";//outputs the same number contained in that cell as |
		cout << endl; //creates a new line
	}
	cout << "How many pins would you like to take?(row) (pin) ";//asks the user how many pins they would like to take from the row they chose.
}

//=========
//| Hello |
//=========
//gives the prompt (what the it looks like so far)
//Touches: n/a
//line count = 3
void Nim::hello()
{//tells the user a basic summary of how to play
	cout << "In this game you will be take any number of pins that any of the following rows has." << endl
		<< "To win you need to take all the pins before the computer" << endl; //summary
	prompt();//response prompt
}

//==========
//| Listen |
//==========
//gets the how many pins from a row that the user wants to take
//Touches:g_playrow, g_playpin, g_arraysize, a_game
//line count = 7
void Nim::listen()
{
	cin >> g_playrow >> g_playpin;//gets the user's row & pin input
	if (g_playrow > g_arraysize - 1 || 0 > g_playrow)//if the row player picks a row bigger or smaller than the array bounds
	{
		cout << "\nError: Row does not exist! \n" << endl;//outputs if the number picked is smaller or bigger than array size
		prompt(); listen();//recalls method(recursive)
	}
	if (0 == a_game[g_playrow])//if row contains no pins
	{
		cout << "\nAt least one pin must be taken! \n"<< endl;//outputs that the player must take at least one pin
		prompt(); listen();//recalls method.(recursive)
	}
}

//---------------
//| Change_Pins |
//---------------
//changes the number of pins after the player's turn
//Touches: g_playpin, a_game, g_playrow
//line count = 8
void Nim::change_pins()
{
	if (g_playpin > a_game[g_playrow])//greater than the number of pins in that row
	{//the player takes all the pins in that row
		cout << "You take " << a_game[g_playrow] << " pins from row " << g_playrow << endl;
		a_game[g_playrow] = 0;//the row contains no pins

	}
	else if (2 > g_playpin)//less than 2
	{//only takes one pin
		a_game[g_playrow] = a_game[g_playrow] - 1;
		//tells user how many pins they took
		cout << "You take 1 pin from row " << g_playrow << endl;
	}
	else
	{//changes number of pins in that row
		a_game[g_playrow] = a_game[g_playrow] - g_playpin;
		//tells user how many pins they took
		cout << "You take " << g_playpin << " pins from row " << g_playrow << endl;
	}
}

//------------
//| Is_Empty |
//------------
//checks if the vector is empty
//Touches: g_arraysize, a_game
//line count = 4
bool Nim::is_empty()
{
	for (int ax = 0; ax < g_arraysize; ax++)//loops through all items in array
	{
		if (0 != a_game[ax])//contains a number that not 0
		return false;//array not empty
	}
	return true;//else return true
}

//--------------------
//| Comp_Change_Pins |
//--------------------
//changes the number of pins after the computer's turn
//Touches: g_arraysize, a_game
//line count = 8
void Nim::comp_change_pins()
{
	int compr = rand()%g_arraysize;//generates random number
	while (0 == a_game[compr])//if row doesn't have any pins
	{
		compr = rand();//generates random number
		compr = compr%g_arraysize;//gets random row number again from 0-array size
	}
	int compp = rand();//generates random number of pins
	compp = 1 + compp%a_game[compr];//gets a random pin number from (1-# of pins in row)
	a_game[compr] = a_game[compr] - compp;//removes the number of pins in that row by the number the computer takes
	cout << "I take " << compp << " pins from row " << compr << endl;//tells user how many pins computer took
}

//===========
//| Respond |
//===========
//changes the number of pins in rows
//Touches: n/a
//line count = 5
void Nim::respond()
{	
	change_pins();//changes the pin number based on what the user chose
	if (is_empty()) cout << "\n \nYou win!"<< endl;//if array is empty
	else
	{
		comp_change_pins();//changes the pins with the computer's input
		if (is_empty())	cout << "\n \nThe Brain wins!" << endl;//if it is empty
		else
			prompt();//the prompt is returned
	}
}

//===========
//| Cleanup |
//===========
//cleans up function
//Touches: n/a
//line count = 1;
void Nim::cleanup()
{
	cout << "\nThank you for playing the Nim Game!\n \n";//thanks user
}

//==========
//| EndChk |
//==========
//checks if game is done
//Touches: n/a
//line count = 1;
bool Nim::endchk(){ return !is_empty(); }//returns the opposite of function is_empty

//================
//| Conversation |
//================
//plays the code
//Touches: n/a
//line count = 6
void Nim::conversation()
{

	setup();//generates number of rows & pins
	hello();//gives the prompt (what the game looks like so far)
	do
	{
		listen();//gets the how many pins from a row that the user wants to take
		respond();//changes the number of pins in rows
	} while (endchk());//while the array is not empty
	cleanup();//resets the variables to default
}
