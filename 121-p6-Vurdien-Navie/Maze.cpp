//Maze game: Mystery House maze game. The player needs to find the kitchen in a house to not starve.
//Navie Vurdien
//email: nvurdien@hotmail.com
#include "stdafx.h"
#include "Maze.h"
#include <iostream>
#include <cstdlib>//srand
#include <ctime>//time
#include <cmath>
using namespace std;

//---------------
//| Change Text |
//---------------
//changes the underscores in the text to spaces
//Touches: n/a
//line count = 6
string Maze::change_text(string text)
{
	string new_text;//text to return
	for (char ax : text)//loops through every char in the string
	{
		if ('_'==ax)//if there is an underscore
			new_text = new_text + " ";//it is changed to a space
		else
			new_text = new_text + ax;//otherwise, the char is input
	}
	return new_text;//returns the string
}


//-------------
//| Get Exits |
//-------------
//gets the exit rooms for the room given
//Touches: g_house
//line count = 8
void Maze::get_exits(int room_id)
{
	//DOUT "get_exit start";
		int rand_room = 1 + rand() % 49; while (rand_room == room_id){ rand_room = 1+ rand() % 49; }//gets random room id
		int dir = rand() % 10;//gets random direction
		int kit = rand() % 8;//sees if value should be kitchen
		if (kit <=6)//if not then gets a random room
		while (g_house->find_room(room_id)->m_aexits[dir] != g_help)dir = rand() % 10;//if the direction already has a room in it try again
		//sets exits to the room
		if (kit >7)//if it can then sets exit to kitchen
			g_house->find_room(room_id)->set_exit(g_help->cvt_exit_index_to_dir(dir), g_house->find_room(29));
		else//else sets to the random room value
			g_house->find_room(room_id)->set_exit(g_help->cvt_exit_index_to_dir(dir), g_house->find_room(rand_room));
	//DOUT "get_exit end" ENDLDOUT;
}

//---------------
//| Zombie Room |
//---------------
//puts zombies in 3 rooms
//Touches: g_zombie1,g_zombie2,g_zombie3,g_kitchen, g_user_room
//line count = 6
void Maze::zombie_room()
{
	//DOUT "zombie room start";
	//gets a room for the zombies
	//if the zombie is in the kitchen or same room as user get another number
	while (g_zombie1 == g_kitchen || g_zombie1==g_user_room)
	{//keeps randomizing until all are in different rooms
		g_zombie1 = 1 + rand() % 49; 
	}//if the zombie is in the kitchen or same room as user get another number
	while (g_zombie2 == g_kitchen || g_zombie2 ==g_user_room)
	{//keeps randomizing until all are in different rooms
		g_zombie2 = 1 + rand() % 49;
	}//if the zombie is in the kitchen or same room as user get another number
	while (g_zombie3 == g_kitchen || g_zombie3==g_user_room)
	{//keeps randomizing until all are in different rooms
		g_zombie3 = 1 + rand() % 49;
	}
	//DOUT "zombie room end" ENDLDOUT;
}



//==========
//| Set Up |
//==========
//generates random start & end room
//Touches: g_findhouse, g_house, g_user_room
//line count = 7
void Maze::setup()
{
	//DOUT "setup start";
	g_findhouse.conversation(); g_house = g_findhouse.get_house();//gets a house
	srand(static_cast<unsigned int>(time(0))); int rand_exit_num = 1 + rand() % 4;//sees whether the room will be big or small
	while (g_user_room==29) g_user_room = 1 + rand() % 49;//gets random starting room
	for (int ix = 1; ix < 50; ix++)//loops through all the rooms
	{//gets exits for rooms
		for(int ax=0;ax <rand_exit_num;ax++) get_exits(ix);
		rand_exit_num = 1 + rand() % 4;//sees whether the room will be big or small again
	}
	zombie_room();//puts zombies in rooms
	//DOUT "setup end" ENDLDOUT;
	//g_house->show();
}
//---------------
//| Move Zombie |
//---------------
//changes zombie's location
//Touches: g_house, g_help, g_zombie1, g_zombie2, g_zombie3, g_kitchen
//line count = 7
void Maze::move_zombie()
{
	//gets random direction
	int m_zombie_dir = rand() % 10;
	//loops until finds a room the zombie can go to
	while (g_house->find_room(g_zombie1)->m_aexits[m_zombie_dir] == g_help)
	m_zombie_dir = rand() % 10;	g_zombie1 = g_house->find_room(g_zombie1)->m_aexits[m_zombie_dir]->m_id; m_zombie_dir = rand() % 10;//changes zombies room id
	//loops until finds a room the zombie can go to
	while (g_house->find_room(g_zombie2)->m_aexits[m_zombie_dir] == g_help) 
	m_zombie_dir = rand() % 10; g_zombie2 = g_house->find_room(g_zombie2)->m_aexits[m_zombie_dir]->m_id; m_zombie_dir = rand() % 10;//changes zombies room id
	//loops until finds a room the zombie can go to
	while (g_house->find_room(g_zombie3)->m_aexits[m_zombie_dir] == g_help) 
	m_zombie_dir = rand() % 10; g_zombie3 = g_house->find_room(g_zombie3)->m_aexits[m_zombie_dir]->m_id;//changes zombies room id
}


//---------------
//| Warn Zombie |
//---------------
//checks for zombies to warn user
//Touches: g_house, g_user_room, g_help, g_zombie1, g_zombie2, g_zombie3, g_szombie1, g_szombie2, g_szombie3
//line count = 8
void Maze::warn_zombie()
{
	for (int zx = 0; zx < 8; zx++)//loops through every direction
	{
		if (g_house->find_room(g_user_room)->m_aexits[zx] != g_help)//if the room is not empty
		{
			//checks if there are zombies in surrounding rooms
		if (g_house->find_room(g_user_room)->m_aexits[zx]->m_id == g_zombie1){ g_szombie1 = g_help->cvt_exit_index_to_dir(zx);//stores the first zombie direction
				cout << "You hear sounds coming from the " << g_help->cvt_exit_index_to_dir(zx) << " room.\n";//warns user
		}
			//checks if there are zombies in surrounding rooms
		if (g_house->find_room(g_user_room)->m_aexits[zx]->m_id == g_zombie2){ g_szombie2 = g_help->cvt_exit_index_to_dir(zx);//stores the second zombie direction
				cout << "You hear sounds coming from the " << g_help->cvt_exit_index_to_dir(zx) << " room.\n";//warns user
		}
			//checks if there are zombies in surrounding rooms
		if (g_house->find_room(g_user_room)->m_aexits[zx]->m_id == g_zombie3){ g_szombie3 = g_help->cvt_exit_index_to_dir(zx);//stores the third zombie direction
				cout << "You hear sounds coming from the " << g_help->cvt_exit_index_to_dir(zx) << " room.\n";//warns user
		}
		}
	}
}


//----------
//| Prompt |
//----------
//checks for zombies. asks user where they want to go
//Touches: g_house, g_user_room, g_help
//line count = 5
void Maze::prompt()
{
	warn_zombie();//warns user of zombies
	cout << "\nYou are in the " << change_text(g_house->find_room(g_user_room)->m_name) << ". It is "//tells user where they are
		<< change_text(g_house->find_room(g_user_room)->m_desc) << ". There are exits at the following locations:\n";//gives a description
	//tells user where they can go
	for (int ix = 0; ix < 10; ix++){ if (g_house->find_room(g_user_room)->m_aexits[ix] != g_help) cout << g_help->cvt_exit_index_to_dir(ix) << "\n"; }
	cout << "\nWhere would you like to go?";//asks user
}

//=========
//| Hello |
//=========
//gives the prompt & objective
//Touches: n/a
//line count = 2
void Maze::hello()
{
	cout << "Welcome to the mystery house you must find the kitchen.\n\n";//tells which room user needs to find
	prompt();//asks user where they want to go
}

//==========
//| Listen |
//==========
//gets the direction the user inputted
//Touches:g_dir, g_quit, g_entry_num, g_house, g_user_room,g_help
//line count = 8
void Maze::listen()
{ 
	getline(cin, g_dir); //gets user's direction
	for (size_t ix = 0; ix < g_dir.size();ix++)//loops through each char
	{ 
		g_dir[ix] = toupper(g_dir[ix]); //changes to uppercase
	}
	if (g_dir == "Q"){ cout << "Sorry you want to quit early."; g_quit = true; return; }//sees if user wants to quit
	//if user inputs a direction not listed
	if (g_house->find_room(g_user_room)->m_aexits[g_help->cvt_exit_dir_to_index(g_dir)] == g_help)
	{
		cout << "Sorry you can't go there\n"; g_dir = ""; prompt(); listen(); return;//redoes function if invalid direction is input
	}

	g_entry_num++;//increases the number of rooms the user entered

	//changes the user room to the room direction the user wanted to go to
	g_user_room = g_house->find_room(g_user_room)->m_aexits[g_help->cvt_exit_dir_to_index(g_dir)]->m_id;
	//DOUT "listen" ENDLDOUT;
}

//--------
//| Dice |
//--------
//rolls dice when user encounters zombie
//Touches: g_user_room,g_zombie1,g_zombie2,g_zombie3
//line count = 4
void Maze::dice()
{
	int dice_num = 1 + rand() % 6;//gets a random number from a dice roll
		cout << "Oh no! You see a zombie!\nYou roll a dice to see what you should do.\nYou get " << dice_num << "! Which means ";//starting of sentence
		switch (dice_num){//switches through each case
		case 1: cout << "the zombie kills you! GAME OVER!\n"; g_quit = true; break;//if user gets 1 they kill zombie
		case 2: cout << "you run to a random room!\n"; //if user gets 2 they run to a random room
			while (g_user_room == g_zombie1 || g_user_room == g_zombie2 || g_user_room == g_zombie2) g_user_room = 1 + rand() % 49; break;//gets random room
		case 3: cout << "you find a hiding spot!\n"; move_zombie();  break;//if user gets 3 user finds hiding spot
		case 4: cout << "you run away and find the kitchen!\n"; g_user_room = 29; break;//if user gets 4 they find the kitchen
		default: cout << "the zombie runs away!\n"; move_zombie();  break;//if user gets any other number the zombie runs away
		}

}


//===========
//| Respond |
//===========
//checks the value that was inputed
//Touches: g_szombie1, g_szombie2,g_szombie3, g_quit, g_user_room, g_kitchen, g_entry_num
//line count = 7
void Maze::respond()
{
	//DOUT "respond" ENDLDOUT;
	if (g_szombie1 == g_dir || g_szombie2 == g_dir || g_szombie3 == g_dir){ dice(); } //if the user enters a room with a zombie
	//DOUT "ZOMBIE" ENDLDOUT;
	if (g_user_room == g_kitchen)//if user found room
	{//congragulates user
		cout << "\n\nCongragulations you found the kitchen after going through "<< g_entry_num <<" rooms! You may now eat your sandwich!\n\n";
		g_quit = true;//ends game
	}
	//DOUT "KITCHEN" ENDLDOUT;
	g_szombie1 = ""; g_szombie2 = ""; g_szombie3 = ""; //resets variables
	if (!g_quit){ move_zombie(); prompt(); }//asks user where they want to go next
	//DOUT "RESPOND" ENDLDOUT;
}

//===========
//| Cleanup |
//===========
//cleans up function
//Touches: g_entry_num, g_quit
//line count = 3;
void Maze::cleanup()
{
	g_entry_num = 0;//resets the entry number
	g_quit = false;//changes the variable back to false
	cout << "Thank you for playing mystery house! \n\n";//thanks user
}

//==========
//| EndChk |
//==========
//checks if game is done
//Touches: g_quit
//line count = 1;
bool Maze::endchk()
{ 
	return !g_quit;//checks if game is done
}

//================
//| Conversation |
//================
//plays the code
//Touches: n/a
//line count = 6
void Maze::conversation()
{

	setup();//generates random start & end room
	hello();//gives the prompt & objective
	do
	{
		listen();// gets the direction the user inputted
		respond();//checks the value that was inputed
	} while (endchk());//checks if game is done
	cleanup();//cleans up function
}
