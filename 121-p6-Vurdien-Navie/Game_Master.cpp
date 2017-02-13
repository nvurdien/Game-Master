//Game_master class: the main menu for the games
//Navie Vurdien
//email: nvurdien@hotmail.com
#include "stdafx.h"
#include "Game_Master.h"
#include "Card.h"
#include "Number.h"
#include "dout.h"
#include "Nim.h"
#include <iostream>
#include <cstdlib>//srand
#include <ctime>//time
#include <cmath>
#include <string>
using namespace std;

//----------
//| Prompt |
//----------
//tells the player the choices
//Touches: n/a
//line count = 5;
void Game_Master::prompt()
{
	cout << "Input a number:\n" //choose an option
		<< " 1 for the Card Guessing game.\n"//1-card guess
		<< " 2 for the Number Guessing game.\n"//2-number guess
		<< " 3 for the Nim Game.\n"//3-nim
		<< " 4 for the Mystery House Game.\n"//4-maze
		<< " 0 to quit.\n";//0-quit
}

//=========
//| Hello |
//=========
//greets the player
//Touches:n/a
//line coount = 3
void Game_Master::hello()
{
	cout << "\nHi. This is the Games Master program.\n";//hello
	cout << "I've several games you can play. Please pick one.\n";//greeting
	prompt();//choices
}

//==========
//| Set Up |
//==========
//sets up the program
//Touches: n/a
//line count = 0
void Game_Master::setup()
{
	//DOUT "SETUP" ENDLDOUT
}

//==========
//| Listen |
//==========
//gets the user's choice
//Touches: g_choice, g_quit
//line count = 3
void Game_Master::listen()
{
	cin >> g_choice;//user inputs their choice of game
	cin.ignore();
	if (g_choice == 0)//if choice is 0 the program quits
		g_quit = true;//variable to quit is set to true
}

//----------------
//| Check_Choice |
//----------------
//plays game the user chose
//Touches: g_choice, g_card_game, g_number_game, g_nim_game
//line count = 6
void Game_Master::check_choice()
{
	switch (g_choice)//checks which choice is chosen
	{
	case 0:
		cout << "Game will terminate. " << endl; g_quit = true; exit(0);//exits the game
		break;
	case 1://when choice one is entered the card game is played
		g_card_game.conversation();	cout << "\nBack to the Games Master program.\n"; break;
	case 2://when choice two is entered the number game is played
		g_number_game.conversation(); cout << "\nBack to the Games Master program.\n"; break;
	case 3://when choice three is entered the nim game is played
		g_nim_game.conversation(); cout << "\nBack to the Games Master program.\n"; break;
	case 4://when choice four is entered the maze game is played
		g_maze_game.conversation(); cout << "\nBack to the Games Master program.\n"; break;
	default://when anything else is entered the game terminates.
		cout << "Invalid choice = " << g_choice << endl;
		break;
	}
}

//===========
//| Cleanup |
//===========
//resets variables
//Touches: g_number_game, g_card_game, g_choice
//line count = 5
void Game_Master::cleanup() 
{
	Number sh;//new number game
	g_number_game = sh;//resets number game
	Card op;//new card game
	g_card_game = op;//resets card game
	g_choice = 0;//resets choice to 0
}

//==========
//| EndChk |
//==========
//checks if game is done
//Touches:g_quit
//line count = 4
bool Game_Master::endchk()
{ 
	if (g_quit)//if the user chose to quit
	{
		cout << "Game will terminate. " << endl;//text to quit
		exit(0);//menu closes
	}
	
	return !g_quit;//otherwise outputs true
}

//===========
//| Respond |
//===========
//plays game the user chose
//Touches: n/a
//line count = 2
void Game_Master::respond()
{
	check_choice();//checks which choice was chosen
	if (endchk())prompt();//if choice isn't 0 the choices are shown again
}

//================
//| Conversation |
//================
//opens menu
//Touches: n/a
//line count = 7
void Game_Master::conversation()
{
	hello();//greets user
	setup();//sets up program
	do
	{
		listen();//gets user's choice
		respond();//plays game the user chose
	} while (endchk());//checks if done
	cleanup();//resets variables
}