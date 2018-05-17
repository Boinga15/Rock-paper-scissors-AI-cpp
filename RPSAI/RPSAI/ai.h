#pragma once
#define AI_H
#ifdef AI_H

class Ai {
	public:
		Ai();
		int random();
		int Counter(int move);
		int RepCounter(int move, bool didWinLastRound);
		int RepetitiveCounter(int playerWonInARow);
		void playerMoved(int move);
	protected:
		int playerUsed[3] = { 0, 0, 0 };
		int lastPlayerUsed = 0;
};

#endif // AI_H
