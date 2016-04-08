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

int village_action(int currentPlayer, int handPos, struct gameState *state){
	//+1 Card
	drawCard(currentPlayer, state);

	//+2 Actions
	state->numActions = state->numActions + 2;

	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;


}

int great_hall_action(int currentPlayer, int handPos, struct gameState *state){
	//+1 Card
	drawCard(currentPlayer, state);

	//+1 Actions
	state->numActions++;

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;

}

int steward_action(int choice1, int choice2, int choice3, int currentPlayer, int handPos, struct gameState *state){
	if (choice1 == 1)
  {
	//+2 cards
	drawCard(currentPlayer, state);
	drawCard(currentPlayer, state);
  }
	else if (choice1 == 2)
  {
	//+2 coins
	state->coins = state->coins + 2;
  }
	else
  {
	//trash 2 cards in hand
	discardCard(choice2, currentPlayer, state, 1);
	discardCard(choice3, currentPlayer, state, 1);
  }

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;

}

int outpost_action(int currentPlayer, int handPos, struct gameState *state){
	//set outpost flag
	state->outpostPlayed++;

	//discard card
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}
