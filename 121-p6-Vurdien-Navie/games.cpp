//Games Class: The computer allows the user to pick either a number or card guessing game.
//Navie Vurdien
//email: nvurdien@hotmail.com
#include "stdafx.h"
#include "Game_Master.h"
#include "Maze.h"
#include "dout.h"

//main function; plays the game
//line count = 3
int main()
{
	Game_Master ga;//instantiates the game master object
	ga.conversation();//runs the game master function
	//Maze ma;
	//ma.conversation();
	return 0;//ends function
}