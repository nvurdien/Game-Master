//Card Guessing Game Class: The computer generates a card that the player has to guess.formats shown in the ReadMe file.
//Navie Vurdien
//email: nvurdien@hotmail.com
#include "stdafx.h"
#include "Card.h"
#include "dout.h"
#include <iostream>
#include <cstdlib>//srand
#include <ctime>//time
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

//-----------------
//| Get_Rand_Suit |
//-----------------
//generates a random suit number
//Touches: g_secret,g_secret_card
//line count = 8
void Card::get_rand_suit()
{
	srand(static_cast<unsigned int>(time(0)));//generate random-like number
	int suit = rand(); //generates random number for the secret suit
	suit = 1 + (suit % 4); //the secret suit
	switch (suit)//translates the generated suit into a number in the 100 for the secret number
	{
	case 1: //1 = clubs
		g_secret = g_secret + 100; g_secret_card = g_secret_card +"Clubs"; break;
	case 2: //2 = diamonds
		g_secret = g_secret + 200; g_secret_card = g_secret_card + "Diamonds"; break;
	case 3://3 = hearts
		g_secret = g_secret + 300; g_secret_card = g_secret_card + "Hearts"; break;
	default://else = spades
		g_secret = g_secret + 400; g_secret_card = g_secret_card + "Spades"; break;
	}
}

//-----------------
//| Get_Rank_Rank |
//-----------------
//generates a random rank number
//Touches: g_secret,g_secret_card
//line count = 8
void Card::get_rand_rank()
{
	srand(static_cast<unsigned int>(time(0)));//generates a random-like number
	g_secret = g_secret + 2 + (rand() % 13); //gets secret rank
	switch (g_secret)//translates the generated suit into a number in the 100 for the secret number
	{
	case 11: //11 = Jack
		g_secret_card = "Jack of ";  break;
	case 12: //12 = Queen
		g_secret_card = "Queen of "; break;
	case 13://13 = King
		g_secret_card = "King of "; break;
	case 14: //14= Ace
		g_secret_card = "Ace of "; break;
	default://else = an integer
		g_secret_card = static_cast<ostringstream*>(&(ostringstream() << g_secret))->str(); g_secret_card = g_secret_card + " of "; break;
	}
}

//==========
//| Set Up |
//==========
//generates secret number by adding the suit and rank
//Touches: rank, g_secret
//line count = 2
void Card::setup()
{
	get_rand_rank();//generates a random rank number
	get_rand_suit();//generates a random suit number
}

//----------
//| Prompt |
//----------
//guess prompt
//Touches: n/a
//line count = 0
void Card::prompt(){ cout << "Guess Rank and Suit: "; } 

//=========
//| Hello |
//=========
//gives the prompt (guess a card)
//Touches: n/a
//line count = 3
void Card::hello()
{ //the greeting
	cout << "I've chosen a secret card that you have to guess.(2-9,J,Q,K,A) (C,D,H,S) " 
		<< endl<<"If you would like to quit early please enter either q or quit"<<endl;
	prompt();//guess prompt
}

//--------------
//| Check_Rank |
//--------------
//changes the letter into number form to add it to the guess value
//Touches: g_guess, g_wrong
//line count = 8
bool Card::check_rank(string rrank)
{
	switch (rrank[0])//checks if the rank is valid to add to the guess value
	{
	case 'A': case 'a': //sees if the rank is ace
		g_guess = g_guess + 14; return true; break;
	case 'J': case 'j': //sees if the rank is jack
		g_guess = g_guess + 11; return true; break;
	case 'Q': case 'q': //sees if the rank is queen
		g_guess = g_guess + 12; return true; break;
	case 'K': case 'k'://sees if the rank is king
		g_guess = g_guess + 13; return true; break;
	default:
		//sees if rank is 10
		if ('1' == rrank.at(0) && '0' == rrank.at(1)){ g_guess = g_guess + 10; return true; } 
		//if it integer, subtracts the char by 48 to give an integer value between (2-9)
		else if ((50 <= rrank.at(0)) || (57 >= rrank.at(0))){ g_guess = g_guess + rrank.at(0) - 48; return true; } 
		else//changes g_wrong to signal the guide to give the user help
			g_wrong = 1; return false;
		break;
	}
}

//--------------
//| Check_Suit |
//--------------
//changes the suit into number form to add it to the guess value
//Touches: g_guess, g_wrong
//line count = 7
void Card::check_suit(string rsuit)
{
	switch (rsuit[rsuit.size() - 1])//checks if the suit is valid to add to the guess value
	{
	case 'C': case 'c': //sees if the suit is clubs
		g_guess = g_guess + 100; break;
	case 'D': case 'd': //sees if the suit is diamond
		g_guess = g_guess + 200; break;
	case 'H': case'h': //sees if the suit is hearts
		g_guess = g_guess + 300; break;
	case 'S': case 's': //sees if the suit is spades
		g_guess = g_guess + 400; break;
	default:
		g_guess = 0;//resets guess to 0
		g_wrong = 1;//and its wrong
		break;
	}
}

//---------
//| Guide |
//---------
//give's user help
//Touches: rank, suit, g_the_card
//line count = 8
void Card::guide()
{
	string rank; string suit; //user's rank and suit
	//asks user to input a rank
	cout << "\nInput a rank from (2-10, J, Q, K): "; getline(cin, rank);
	//asks user to input a suit
	cout << "Input a suit from (C, D, H, S): "; getline(cin, suit); cout << endl;
	//changes the card string to whatever the user input so they can get feedback on if their answer is right
	g_the_card = rank + " " + suit;
	//checks if the user input the rank and suit correctly
	if (check_rank(g_the_card)){ check_suit(g_the_card); }
	//if the user incorrectly input the answer again
	if (g_wrong == 1) { cout << "\nSorry those are invalid values. Please Try Again.\n"; return; }
	//tells user how they can input that answer
	cout << "Please input your answer like this: " << rank << " " << suit << " or " << rank << suit << endl << endl;
	//outputs the answer with prompt to show user example of how it looks like when written the right way
	prompt(); cout << rank << suit << endl;
}

//==========
//| Listen |
//==========
//get user's guess
//Touches: g_guess, g_the_card, g_wrong, g_quit
//line count = 7
void Card::listen()
{	
	getline(cin, g_the_card); //gets the string
	g_guess = 0;//resets guess value
	//if user wants to quit
	if ("Q" == g_the_card || "q" == g_the_card || "quit" == g_the_card || "QUIT" == g_the_card )
	{//changes variables for user to quit early
		g_more = 0; g_quit = true; cout << "\nI'm sorry you want to quit early.\n"; return;
	}
	//if string length is less than 2 or greater than 4 the the string is not the correct length
	if (5 < g_the_card.size() || 2 > g_the_card.size())	{ g_wrong = 1; return; }
	//if the user needs help
	if ("h" == g_the_card || "H" == g_the_card || "help" == g_the_card || "HELP" == g_the_card){ guide(); return; }
	if (check_rank(g_the_card))	check_suit(g_the_card);//changes the rank & suit into number form to add it to the guess value
	else
		guide();//give's user help
}

//--------------
//| Check_Card |
//--------------
//checks how far the the guess is from the actual
//Touches: g_prev_delta, g_guess_cnt
//Line count = 5
void Card::check_card(int card_value)
{
	g_guess_cnt++;//increases the number of guesses
	//if the answer and guess has no difference
	if (0 == card_value)	cout << "\nCongratulations! You got the card "<<g_secret_card<<" in " << g_guess_cnt << " guesses!" << endl; 
	else if (card_value < g_prev_delta)	cout << "Getting warmer." << endl; //closer to the generated card
	else if (card_value == g_prev_delta)	cout << "Same Distance. " << endl; //same distance as the last delta
	else
		cout << "Getting colder. " << endl;//farther from the generated card
}

//===========
//| Respond |
//===========
//checks if the guess is correct
//Touches: delta, g_secret, g_guess,g_wrong, g_prev_delta, g_more, g_quit
//line count = 7
void Card::respond()
{
	if (g_quit){ return; }//if user wants to quit early
	//if the user input an incorrect value it constantly corrects the user until they are correct
	if (g_wrong == 1){ while (g_wrong){ g_wrong = 0; guide();} }
	int delta = abs(g_secret - g_guess);//see if you are closer to the secret value
	check_card(delta);//checks how far the the guess is from the actual
	g_prev_delta = delta; g_more = delta; g_guess = 0;//resets variables
	if (g_more)    prompt(); //returns the prompt again if the guess was incorrect
}

//===========
//| Cleanup |
//===========
//resets variables to default
//Touches: g_more, g_secret, g_prev_delta, g_guess
//line count = 6
void Card::cleanup()
{
	g_more = 1;//conv. loop test;
	g_secret = 0; //the secret number
	g_prev_delta = 1000;//the previous guess number
	g_guess = 0;//the guess number
	g_guess_cnt = 0;//number of guesses the user takes
	g_secret_card = "";
	cout << "\nThank you for playing the Card Guessing Game!\n \n";//thanks user
}

//==========
//| EndChk |
//==========
//checks if game is over
//Touches: g_more
//line count = 0
int Card::endchk(){ return g_more; }

//================
//| Conversation |
//================
//to play the game
//Touches: g_more
//line count = 6
void Card::conversation()
{
	setup();//generates number
	hello();//gives the prompt (guess a card)
		do
		{
			listen();//gets the players guess
			respond();//checks if the guess is correct
		} while (endchk());//while the card still hasn't been guessed
		cleanup();//resets variables to default
}