#include "../dominion.h"
#include "../cards.h"
#include "stdlib.h"
#include <stdio.h>
#include "../myassert.h"

int main(){
	struct gameState* state = calloc(1, sizeof(struct gameState));
	state->whoseTurn = 0;
	state->numPlayers = 2;
	state->deck[0][0] = smithy;
	state->deck[0][1] = village;

	state->deck[1][0] = smithy;
	state->deck[1][1] = village;

	state->deckCount[0] = 2;
	state->deckCount[1] = 2;
	printf("Testing sea_hag\n");
	cardEffect(sea_hag, 0, 0, 0, state, 0, 0);
	newassert(!(state->discardCount[1] == 0));
    newassert(!(state->deck[0][1] == curse));
	newassert((state->deck[1][0]) == curse);
	newassert(!(state->deck[1][1] == village));
	newassert(state->deckCount[1] == 2);
	printf("Testing complete on sea_hag\n");

return 0;
}



//struct gameState* copy = malloc(sizeof(struct gameState));
//memcpy(copy, state, sizeof(struct gameState));
