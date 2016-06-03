#include "../dominion.h"
#include "stdlib.h"
#include "../cards.h"
#include <stdio.h>
#include "myassert.h"

int main(){
	struct gameState* state = calloc(1, sizeof(struct gameState));
	printf("Testing great_hall\n");
	cardEffect(great_hall_action, 0, 0, 0, state, 0, 0);
	newassert(state->numActions == 1);
	printf("Testing complete on great_hall\n");
return 0;
}
