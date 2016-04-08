#include "cards.h"
#include "dominion.h"
#include "dominion_helpers.h"

int smithy_action(int currentPlayer, int handPos, struct gameState *state) {
	//+3 Cards
	int i;
	for (i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
 	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}
