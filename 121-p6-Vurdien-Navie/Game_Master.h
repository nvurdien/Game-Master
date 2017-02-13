//Game_Master header class: contains all the methods used in the Game_Master Class.
//Navie Vurdien
//email: nvurdien@gmail.com
#include "Card.h"
#include "Number.h"
#include "Nim.h"
#include "Maze.h"
#ifndef GAME_MASTER_H
#define GAME_MASTER_H
class Game_Master
{
	//globals for game master
	int g_choice;//the players choice of game or to exit
	bool g_quit = false;//checks if player wants to quit
	Card g_card_game;//instantiates the card guessing game class
	Number g_number_game;//instantiates a number guessing game class
	Nim g_nim_game;//instantiates a nim game class
	Maze g_maze_game;//instantiates a maze game class
public:
	//methods for game master
	void prompt();//tells the player the choices
	void hello();//tells the player the choices
	void listen();//gets the user's choice
	void check_choice();//plays game the user chose
	void respond();//plays game the user chose
	void setup();//sets up the program
	bool endchk();//checks if game is done
	void cleanup();//resets variables
	void conversation();//opens the menu
};

#endif