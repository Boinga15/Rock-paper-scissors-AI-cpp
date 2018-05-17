#include <iostream>
#include <ctime>
#include "ai.h"

Ai::Ai() { // This sets the ai's variabls to 0.
	this->playerUsed[0] = 0;
	this->playerUsed[1] = 0;
	this->playerUsed[2] = 0;
	this->lastPlayerUsed = 0;
}

void Ai::playerMoved(int move) { // Handle the player's choice and save them.
	this->playerUsed[move]++;
}

int Ai::random() { // This ai's stratagy: Just chooses a random choice.
	srand(time(0));
	return rand() % 2;
}

int Ai::Counter(int move) { // This ai's stratagy: Chooses a random choice, but if you play the same thing twice, it will counter that next move (e.g: if you played rock twice, next move it will play paper)
	if (this->lastPlayerUsed == move) {
		this->lastPlayerUsed = move;
		switch (move) {
		case 0:
			return 2;
			break;
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		}
	} else {
		this->lastPlayerUsed = move;
		srand(time(0));
		return rand() % 2;
	}
}

int Ai::RepCounter(int move, bool didWinLastRound) {// Acts like the intermidiete AI, however, if you won last round, it will play to counter the previous move immedietly!
	if (didWinLastRound) {
		switch (this->lastPlayerUsed) {
		case 0:
			return 2;
			break;
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		default:
			break;
		}
	} else {
		if (this->lastPlayerUsed == move) {
			this->lastPlayerUsed = move;
			switch (move) {
			case 0:
				return 2;
				break;
			case 1:
				return 0;
				break;
			case 2:
				return 1;
				break;
			}
		}
		else {
			this->lastPlayerUsed = move;
			srand(time(0));
			return rand() % 2;
		}
	}
}

int Ai::RepetitiveCounter(int playerWonInARow) { // This AI finds which move you are spamming, then it will counter, if two values are the same, it plays at random.
	int mostUsedPlay = 0; // This value keeps track of the number of times the player used this move, depending on the play variable.
	int play = 0; // This value keeps track of the most used move so far.
	bool twoValuesSame = false; // This value keeps track of if two values have been the same.
	for (int i = 0; i < 3; i++) {
		if (playerUsed[i] > mostUsedPlay) {
			mostUsedPlay = playerUsed[i];
			play = i;
		} else if (playerUsed[i] == mostUsedPlay && playerUsed[i] == 0) {
			twoValuesSame = true;
			break;
		}
	}
	if (twoValuesSame) {
		srand(time(0));
		return rand() % 2;
	} else {
		if (playerWonInARow > 1) { // ToS avoid a certian lockup that players can exploit, the AI plays at random if you win twice in a row.
			srand(time(0));
			return rand() % 2;
		}
	}
}