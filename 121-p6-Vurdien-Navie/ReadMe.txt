----------------
| Contact Info |
----------------
Name: Navie Vurdien 
email: nvurdien@hotmail.com

-----------------
| File Contents |
-----------------
This file contains the following files:
-------------
Created by me
-------------
Card.h
  //Card Guessing Game header file
Game_Master.h
  //Game Master header file
Maze.h
  //Mystery House Maze header file
Nim.h
  //Nim Game header file
Number.h
  //Number Guessing Game header file
games.cpp
  //main function. starts program
Card.cpp
  //Card Guessing Game class. The computer generates a card that the player has to guess.
Game_Master.cpp
  //Game Master Class. the main menu for the games
Maze.cpp
  //Mystery House Maze game. The player needs to find the kitchen in a house to not starve.
Nim.cpp
  //Nim Game. contains the nim game which generates an array with a random number of rows that contain a random number of pins.
Number.cpp
  //Number Guessing Game class. The computer generates a number that the player has to guess.

--------
Imported
--------
(separated some header files into a .h and a .cpp file to separate functions and prototypes)
house-parser.cpp 
  // A test program.
house-sample.txt 
  // A sample house description file.
house_parser.h --- house_parser.cpp
  // The House_parser class and methods.  Parse house desc file.
house.h --- house.cpp
  // The House class and methods.
room.h --- room.cpp
  // The Room class and methods.
token_reader.h --- token_reader.cpp
  // The Token_reader class and methods; opens/reads a file.
perr.h --- perr.cpp
  // Nice fcn to print parser error messages.
dout.h 
  // The CPP DOUT, DZ utilities.

-------------------
| About This File |
-------------------
This file (Project #6) contains both a card and number guessing game, a Nim Game, and a Mystery House game.
When the program is played it opens the menu and asks the player what game they want to play.
They can either enter 1 for the Card Guessing Game, enter 2 for the Number Guessing Game,
enter 3 for the Nim Game, or enter 4 for the Mystery House game.
Picking 0 terminates the program. Any other input returns to the menu
Finishing any game allows the user to return to the menu.
Once the player picks a game the following rules are used for them:

------------------
| Choice 1: Card |
------------------
Rules for the Card Guessing Game:
The program creates a number based on a specific rank and suit and the player must guess the rank and suit the computer generated.
The program will tell the player Getting Warmer when the players guess is closer to the generated card and 
Getting Colder when it is farther from the generated card.
If same distance the program tells the player "Same Distance".
When the player gets the correct answer the program tells the player "Got it!"
When the correct card is guessed, the player is returned to the menu.
If the user wants to quit early they may by inputing quit or q

-------
FORMATS
-------
The format of guesses can either be "rank space suit" or rank suit without a space. Responses can be input with or without caps
ex:
A D for ace of diamonds
3 C for three of clubs
K S for king of spades

AD for ace of diamonds
3c for three of clubs
ks for king of spades

--------------------
| Choice 2: Number |
--------------------
Rules for Number Guessing Game:
The program generates a number and the player must guess it.
The program will tell the player Getting Warmer when the players guess is closer to the generated number and 
Getting Colder when it is farther from the generated number.
If same distance the program tells the player "Same Distance".
When the player gets the correct answer the program tells the player "Got it!"
When the correct number is guessed, the player is returned to the menu.
If the player wants to quit early they may by inputting 0
------
FORMAT
------
Players must enter any number from numbers 1-100 to be a valid guess.
ex:
12
13
80

-----------------
| Choice 3: Nim |
-----------------
Rules for Nim Game:
The program creates an array with a randomly generated size from 3-5 and generates a random number from 3-8 in each cell.
The program asks the player what row the user wants to take pins from and how many pins the user wants to take.
The program will output the row number and "|" to show how many pins remain in each row.
The player wins by taking all the pins before the computer.
If the player enters a number exceeding the total amount of rows, the program will tell the player to input their response again.
If the player picks a row with no pins, the program will tell the user to pick a row with pins.
Once either the player or computer wins, the player returns to the menu.
------
FORMAT
------
The Player must enter their response like so (row #) (pin #) or row (space) pin.
ex:
row pins
2 5
1 2
0 7

---------------------------
| Choice 4: Mystery House |
---------------------------
Rules for Mystery House:
The program imports a house into the file and randomly assigns exits to each room in the house.
The program will start by saying where the user is and a short description of their surroundings as well as warn the player of zombies.
The program will ask the player which direction based on the directions listed they would like to go.
When the player encounters a zombie, they will have to roll a dice to see what happens; there are 5 options:
you kill the zombie! you run to a random room! you find a hiding spot! you run away and find the kitchen! the zombie runs away!
Once the kitchen is found, the player will be rewarded with a sandwich.
If the player would like to quit early they can input q or Q.

------
FORMAT
------
Depending on the directions shown that you can go to. The only directions in this game are: (you may input either lowercase or uppercase)
N
S
W
E
NE
NW
SE
SW
DOWN
UP
n
s
w
e
ne
nw
se
sw
down
up