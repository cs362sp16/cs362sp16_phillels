#include "../dominion.h"
#include "stdlib.h"
#include <stdio.h>
#include "../myassert.h"

int main(){
	struct gameState* state = calloc(1, sizeof(struct gameState));
	 state->coins =  2;
	printf("Testing embargo\n");
	int result = cardEffect(embargo, 2, 0, 0, state, 0, 0);
	newassert(!(result == -1));

	 state->supplyCount[3] =  -1;
	int result1 = cardEffect(embargo, 3, 0, 0, state, 0, 0);
	newassert(result1 == -1);
	printf("Testing complete on embargo\n");
return 0;
}
