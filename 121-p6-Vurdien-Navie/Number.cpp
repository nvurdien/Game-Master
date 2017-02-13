//Number Guessing Game Class: The computer generates a number that the player has to guess.
//Navie Vurdien
//email: nvurdien@hotmail.com
#include "stdafx.h"
#include "dout.h"
#include "Number.h"
#include <iostream>
#include <cstdlib>//srand
#include <ctime>//time
#include <cmath>
#include <string>
using namespace std;

//==========
//| Set Up |
//==========
//generates number
//Touches: g_secret
//line count = 3
void Number::setup()
{
	srand(static_cast<unsigned int>(time(0)));//generate random-like number
	int rx = rand(); //generates a random number
	g_secret = 1 + (rx % 100); //secret number from 1-100 
}

//----------
//| Prompt |
//----------
//prompt guess
//Touches: n/a
//line count = 1
void Number::prompt(){ cout<< "Guess A Number: "; }//guess prompt

//=========
//| Hello |
//=========
//gives the prompt (guess a number[1-100])
//Touches: n/a
//line count = 3
void Number::hello()
{
	cout << "I've chosen a secret number that you have to guess.(1-100)"//the greeting
		<< endl<<"If you would like to quit early enter 0"<<endl; //tells user how to quit
	prompt();//prompt guess
}

//==========
//| Listen |
//==========
//get user's guess.
//Touches: g_guess, g_quit,g_wrong
//line count = 7
void Number::listen()
{
	cin >> g_guess; //gets guess int
	if (g_guess == 0)//if user inputs 0 program quits
	{ 
		g_quit = true; //user wants to quit
		return; //ends function
	}
	if (100 < g_guess || 1 > g_guess)//if g_guess is below 1 or above 100 then it is out of bounds
	{
		g_wrong = 1;//value is out of bounds
		g_guess = 0;//resets guess
	}

}


//-------------
//| Check_Num |
//-------------
//checks how close guess is
//Touches: g_guess_cnt, g_prev_delta
//line count = 5
void Number::check_num(int num)
{
	g_guess_cnt++;//increases guess count
	//if there is no difference in value from the generated number and guess
	if (0 == num)	cout << "\nCongratulations! You got the number "<<g_secret<<" in " << g_guess_cnt << " guesses!" << endl;
	// if the value is closer to the generated number
	else if (num < g_prev_delta)	cout << "Getting warmer." << endl;
	// if the value is the same distance as the last delta
	else if (num == g_prev_delta)	cout << "Same Distance. " << endl;
	else// if the value is farther from the generated number
		cout << "Getting colder."<< endl;
}

//===========
//| Respond |
//===========
//checks if the guess is correct
//Touches: g_secret, g_guess, g_quit, g_more, g_wrong, g_prev_delta
//line count = 8
void Number::respond()
{
	if (1 == g_wrong)//if incorrect input
	{ 
		g_wrong = 0; g_guess = g_prev_delta; //changes guess value back to previous guess value
		prompt(); return; }//outputs prompt again
	//subtracts the g_secret value with the g_guess value to see if you are closer to the secret value
	int delta = abs(g_secret - g_guess);
	if (g_quit)	{ g_more = 0; cout << "\nI'm sorry you want to quit early.\n"; return;}//if user wants to quit
	check_num(delta);//checks how close the guess is
	g_prev_delta = delta; g_more = delta;//changes variables
	if (g_more)    prompt(); //returns the prompt again if the guess was incorrect
}

//===========
//| Cleanup |
//===========
//resets the variables
//Touches: g_more, g_secret, g_prev_delta,g_guess, g_quit, g_guess_cnt
//line count = 7
void Number::cleanup()
{
	g_more = 1;//conv. loop test;
	g_secret = 0;//the secret number
	g_prev_delta = 1000;//the previous guess number
	g_guess = 0;//the guess number
	g_quit = false;//checks if user wants to quit early
	g_guess_cnt = 0;//number of guesses the user takes
	cout << "\nThank you for playing the Number Guessing Game!\n \n";//thanks user
}

//==========
//| EndChk |
//==========
//checks if game is done
//Touches:g_more
//line count = 1
int Number::endchk(){ return g_more; }//returns the g_more value to see if game is done

//================
//| Conversation |
//================
//plays the game
//Touches: n/a
//line count = 6
void Number::conversation()
{
	setup();//generates number
	hello();//gives the prompt (guess a number[1-100])
	do
	{
		listen();//gets the players guess
		respond();//checks if the guess is correct
	} while (endchk());//while number has not been guessed or game hasn't been quit
	cleanup();//resets variables
}