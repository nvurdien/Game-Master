//Maze game header: contains all the methods used in Mystery House Maze game.
//Navie Vurdien
//email: nvurdien@hotmail.com
#include "house_parser.h"
#ifndef MAZE_H //if not defined in cpp, else ignore till matching #endif
#define MAZE_H //define it for cpp
class Maze
{
	//globals for Maze game
	House * g_house;//the house
	House_parser g_findhouse;//puts rooms in the house
	Room * g_help;//helps get from direction string to index or vice versa as well as for null rooms
	string g_szombie1="";//string direction of zombie
	string g_szombie2="";//string direction of zombie
	string g_szombie3="";//string direction of zombie
	string g_dir="";//direction user moved to
	int g_zombie1 = 1 + rand() % 49;//zombie1 room location
	int g_zombie2 = 1 + rand() % 49;//zombie2 room location
	int g_zombie3 = 1 + rand() % 49;//zombie3 room location
	int g_user_room = 1 + rand() % 49;//users room location
	int g_kitchen=29;//the kitchen
	int g_entry_num=0;//number of entries into rooms
	bool g_quit = false;//checks if user wants to quit early
public:
	string change_text(string text);//changes the underscores in the text to spaces
	void get_exits(int room_id);//gets the exit rooms for the room given
	void zombie_room();//puts zombies in 3 rooms
	void setup(); //generates random start & end room
	void move_zombie();//changes zombie's location
	void warn_zombie();//checks for zombies to warn user
	void prompt(); //checks for zombies. asks user where they want to go
	void hello();//gives the prompt & objective
	void listen();// gets the direction the user inputted
	void dice();//rolls dice when user encounters zombie
	void respond();//checks the value that was inputed
	void cleanup();//cleans up function
	bool endchk();//checks if game is done
	void conversation();//plays the code
};
#endif
