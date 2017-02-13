//Number Guessing Game Prototype: contains all the methods used in the Number Class.
//Navie Vurdien
//email: nvurdien@hotmail.com
#ifndef NUMBER_H
#define NUMBER_H
class Number
{
	//globals for number game
	int g_more = 1;//conv. loop test;
	int g_secret = 0; //the secret number
	int g_prev_delta = 1000; //the previous guess number
	int g_guess = 0;//the guess number
	int g_wrong;//if the input is not in bounds
	int g_guess_cnt = 0;//number of guesses the user takes
	bool g_quit = false;//checks if user wants to quit early
public:
	void setup(); //generates number
	void prompt(); //guess prompt
	void hello();//gives the prompt (guess a number[1-100])
	void listen();//gets the players guess
	void check_num(int num);//checks if num is correct
	void respond();//checks if the guess is correct
	void cleanup();//resets variables to default
	int endchk();//checks if game is done
	void conversation();//plays the code
};
#endif