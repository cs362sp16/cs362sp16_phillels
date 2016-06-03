#include "../dominion.h"
#include "../myassert.h"
#include "stdlib.h"

int main() {
	struct gameState* state = calloc(1, sizeof(struct gameState));
	state->whoseTurn =	5;
	newassert(whoseTurn(state) == 5);

	state->whoseTurn = 0;
	newassert(whoseTurn(state) == 0);

	return 0;
}
