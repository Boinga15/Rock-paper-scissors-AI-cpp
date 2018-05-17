#include<iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include<conio.h>
#include "ai.h"

using namespace std;

// Create the AI object:
Ai CP = Ai();

// Create booleans:
bool didWinLastTime = false;
bool OptionSelected = false;

// Create integers:
int playerWins = 0;
int CPWins = 0;
int playerWinsInARow = 0;
int playerMove = 0;
int CPMove = 0;
int CPDifficulty = 0;
int SelectedOption = 0;
int ScoreToWin = 10;

void Game() {
	// Handle the Player's turn:
	SelectedOption = 0;
	OptionSelected = false;

	// Create the action select screen:
	while (!OptionSelected) {
		system("cls");
		// Display the previous moves:
		cout << "Player used: ";
		switch (playerMove) {
		case 0:
			cout << "Rock" << endl;
			break;
		case 1:
			cout << "Scissors" << endl;
			break;
		case 2:
			cout << "Paper" << endl;
			break;
		default:
			break;
		}

		cout << "AI used: ";
		switch (CPMove) {
		case 0:
			cout << "Rock" << endl;
			break;
		case 1:
			cout << "Scissors" << endl;
			break;
		case 2:
			cout << "Paper" << endl;
			break;
		default:
			break;
		}

		cout << "Scores:" << endl;
		cout << "Player: " << playerWins << endl;
		cout << "AI:" << CPWins << endl;
		cout << "Select your move:" << endl;
		cout << "Rock";
		if (SelectedOption == 0) {
			cout << " <===";
		}
		cout << endl;
		cout << "Scissors";
		if (SelectedOption == 1) {
			cout << " <===";
		}
		cout << endl;
		cout << "Paper";
		if (SelectedOption == 2) {
			cout << " <===";
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "use W,S to navigate your options, and X to select a action." << endl;
		if (_kbhit()) {
			switch (_getch()) {
			case 'w':
				SelectedOption--;
				if (SelectedOption < 0) {
					SelectedOption = 0;
				}
				break;
			case 's':
				SelectedOption++;
				if (SelectedOption > 2) {
					SelectedOption = 2;
				}
				break;
			case 'x':
				OptionSelected = true;
				break;
			default:
				break;
			}
		}
		Sleep(40);
	}
	playerMove = SelectedOption;


	// Handle the AI's turn:
	switch (CPDifficulty) {
	case 0:
		CPMove = CP.random();
		break;
	case 1:
		CPMove = CP.Counter(playerMove);
		break;
	case 2:
		CPMove = CP.RepCounter(playerMove, didWinLastTime);
		break;
	case 3:
		CPMove = CP.RepetitiveCounter(playerWinsInARow);
		break;
	default:
		CPMove = CP.Counter(playerMove); // In the case that the selected difficulty is somehow over 3 or under 0, the AI plays like a intermidiete AI.
		break;
	}

	// Check to see who won:
	if (playerMove == 0 && CPMove == 1) { // Yes, this is very repetitive, but, I don't know any other way...
		playerWins++;
		playerWinsInARow++;
	} else if (playerMove == 1 && CPMove == 2) {
		playerWins++;
		playerWinsInARow++;
	} else if (playerMove == 2 && CPMove == 0) {
		playerWins++;
		playerWinsInARow++;
	} else if (CPMove == 0 && playerMove == 1) {
		CPWins++;
		playerWinsInARow = 0;
	} else if (CPMove == 1 && playerMove == 2) {
		CPWins++;
		playerWinsInARow = 0;
	} else if (CPMove == 2 && playerMove == 0) {
		CPWins++;
		playerWinsInARow = 0;
	} else {
		playerWinsInARow = 0;
	}

	// Finally, check to see if the match is over: (The game ends once either the Player or the AI reaches the selected score):
	if (playerWins == ScoreToWin) {
		system("cls");
		cout << "The player won!" << endl;
		system("pause");
	} else if (CPWins == ScoreToWin) {
		system("cls");
		cout << "The AI won!" << endl;
		system("pause");
	} else {
		Game(); // If no one has won yet, it repeats.
	}

}

int main() {
	// This is to make a fake cursor for the main menu:
	
	SelectedOption = 0;
	OptionSelected = false;

	while (!OptionSelected) {
		system("cls");
		cout << "Rock paper scissors AI" << endl;
		cout << "Select Ai stratagy:" << endl;
		cout << "Random";
		if (SelectedOption == 0) {
			cout << " <===";
		}
		cout << endl;
		cout << "Counter";
		if (SelectedOption == 1) {
			cout << " <===";
		}
		cout << endl;
		cout << "Extreme counter";
		if (SelectedOption == 2) {
			cout << " <===";
		}
		cout << endl;
		cout << "Repetitive counter";
		if (SelectedOption == 3) {
			cout << " <===";
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "use W,S to navigate the main menu, and X to select a option." << endl;
		if (_kbhit()) {
			switch (_getch()) {
			case 'w':
				SelectedOption--;
				if (SelectedOption < 0) {
					SelectedOption = 0;
				}
				break;
			case 's':
				SelectedOption++;
				if (SelectedOption > 3) {
					SelectedOption = 3;
				}
				break;
			case 'x':
				OptionSelected = true;
				break;
			default:
				break;
			}
		}
		Sleep(40);
	}
	CPDifficulty = OptionSelected;
	system("cls");
	cout << "Select the score required to win: (10 recommended)" << endl;
	cin >> ScoreToWin;
	system("cls");
	Game();
}

// Copy and paste this into your code if you wanna use the same fake cursor:
// First, however, include the following:
/*
iostream
conio.h
cstdlib
Windows.h
*/
// And this is the code to copy and paste (anything in [] means you need to change it to some text):
/*
SelectedOption = 0;
OptionSelected = false;

while (!OptionSelected) {
system("cls");
cout << "[INSERT HEADERS HERE]" << endl;
cout << "[INSERT OPTION HERE]";  // To add more options copy from here...
if (SelectedOption == 0) {
cout << " <===";
}
cout << endl; // ...to here...
// ...and paste here!
cout << "use [INSERT KEY HERE THAT MAKES CURSOR MOVE UP],[INSERT KEY HERE THAT MAKES CURSOR MOVE DOWN] to navigate the main menu, and [INSERT KEY HERE THAT MAKES CURSOR SELECT] to select a option." << endl;
if (_kbhit()) {
switch (_getch()) {
case 'w': // Set this to the key you want to make the cursor move up.
SelectedOption--;
if (SelectedOption < 0) {
SelectedOption = 0;
}
break;
case 's': // Set this to the key you want to make the cursor move down.
SelectedOption++;
if (SelectedOption > 3) {
SelectedOption = 3;
}
break;
case 'x': // Set this to the key you want to make the cursor select the option it is on.
OptionSelected = true;
break;
default:
break;
}
}
Sleep(40);
}
*/