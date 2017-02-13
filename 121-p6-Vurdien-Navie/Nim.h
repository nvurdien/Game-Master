//Nim Game header: contains all the methods used in the Nim Class.
//Navie Vurdien
//email: nvurdien@hotmail.com
#include <vector>
#ifndef NIM_H //if not defined in cpp, else ignore till matching #endif
#define NIM_H //define it for cpp

class Nim
{
	//globals used in Nim game
	int g_arraysize;//the array size
	int g_playrow;//the players row input
	int g_playpin;//the players pin input
	std::vector<int> a_game;//the game array
public:
	void setup(); //generates number of rows & pins
	void prompt(); //response prompt
	void hello();//gives the prompt (what the game looks like so far)
	void listen();//gets the how many pins from a row that the user wants to take
	void change_pins();//changes the number of pins after the player's turn
	bool is_empty();//checks if the vector is empty
	void comp_change_pins();//changes the number of pins after the computer's turn
	void respond();//changes the number of pins in rows
	void cleanup();//cleans up function
	bool endchk();//checks if game is done
	void conversation();//plays the code
};

#endif //NIM.H
//avoid redef errors
