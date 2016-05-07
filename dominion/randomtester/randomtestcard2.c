#include "../dominion.h"
#include <stdio.h>
#include "stdlib.h"
#include "myassert.h"

enum CARD randcard(){
    return rand() % (treasure_map +1);
}

int main(int argc, char** argv){
	int seed = atoi(argv[1]);
	srand(seed);
	struct gameState state = {0};
	int playernum = rand() % MAX_PLAYERS;
	state.numPlayers = playernum;
	for(int i = 0; i < playernum; i++){
	    int carddeck = rand() % 45;
	    state.deckCount[i] = carddeck;
	    state.handCount[i] = 1;
	    //state.hand[i][0] = sea_hag;
		//state.discardCount[i] = 0;
		state.coins = rand() % 96;
		for(int k = 0; k < carddeck; k++){
			state.deck[i][k] = randcard();
		   }
	}

    for(int i = 0; i < playernum; i++){
	int og_coins = state.coins;

    printf("Testing embargo\n");
	printf("before function call: %d\n", state.coins);
   	int result = cardEffect(embargo, 2, 0, 0, &state, 0, 0);
	printf("after function fall:%d\n", state.coins);
    newassert(!(result == -1));
	newassert((state.coins == (og_coins + 2)));

	state.supplyCount[3] =  -1;
    int result1 = cardEffect(embargo, -1, 0, 0, &state, 0, 0);
    newassert(result1 == -1);
	newassert(state.coins == (og_coins + 4));
    printf("Testing complete on embargo\n");

    }

	return 0;
}
