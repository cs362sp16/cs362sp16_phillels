#include "../dominion.h"
#include "myassert.h"
#include "stdlib.h"

int main() {
	struct gameState* state = calloc(1, sizeof(struct gameState));
	newassert(supplyCount(smithy, state) == 0);

	state->supplyCount[province] =	5;
	newassert(supplyCount(province, state) == 5);

	return 0;
}
