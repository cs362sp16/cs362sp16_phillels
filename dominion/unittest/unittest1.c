#include "../dominion.h"
#include "../myassert.h"
#include "stdlib.h"

int main() {
	struct gameState* state = calloc(1, sizeof(struct gameState));

	for(int i = 0; i<27; i++){
		state->supplyCount [i] = 5;
	}
	newassert(!isGameOver(state));


	state->supplyCount[province] =	 0;
	newassert(isGameOver(state));

	state->supplyCount[province] =	5;
	state->supplyCount[duchy] =	0;
	state->supplyCount[estate] =0;
	newassert(!isGameOver(state));

	state->supplyCount[gardens] = 0;
	newassert(isGameOver(state));

}
