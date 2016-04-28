#include "../dominion.h"
#include <stdlib.h>
#include <string.h>
#include "myassert.h"

int main(){
	struct gameState* state = calloc(1, sizeof(struct gameState));
	struct gameState* copy = malloc(sizeof(struct gameState));
	memcpy(copy, state, sizeof(struct gameState));

	printf("Testing gardens\n");
	cardEffect(gardens, 0, 0, 0, state, 0, 0);

	newassert(!strncmp((const char*)state, (const char*)copy, sizeof(struct gameState)));
	printf("Testing complete on gardens\n");
return 0;
}
