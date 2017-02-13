//Card Guessing Game Prototype: contains all the methods used in the Card Class.
//Navie Vurdien
//email: nvurdien@hotmail.com
#include <string>
#ifndef CARD_H //if not defined in cpp, else ignore till matching #endif
#define CARD_H //define it for cpp
class Card
{
	//globals for card game
	int g_more = 1;//conv. loop test;
	std::string g_secret_card;//secret card in string form
	int g_secret = 0; //the secret number
	int g_prev_delta = 1000; //the previous guess number
	int g_guess = 0;//the guess number
	int g_wrong;//if the input is not in bounds
	int g_guess_cnt = 0;//number of guesses the user takes
	bool g_quit = false;//checks if user wants to quit early
	std::string g_the_card; //guess string
public:
	void get_rand_suit();//generates a random suit number
	void get_rand_rank();//generates a random rank number
	void setup(); //generates number
	void prompt(); //guess prompt
	void hello();//gives the prompt (guess a card)
	bool check_rank(std::string rrank);//changes the rank into number form to add it to the guess value
	void check_suit(std::string rsuit);//changes the suit into number form to add it to the guess value
	void guide();//give's user help
	void listen();//gets the players guess
	void check_card(int card_value);//checks how far the the guess is from the actual
	void respond();//checks if the guess is correct
	void cleanup();//resets variables to default
	int endchk();//checks if game is done
	void conversation();//plays the code
};
#endif
