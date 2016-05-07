#include "../dominion.h"
#include "../cards.h"
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
	    state.hand[i][0] = sea_hag;
		state.discardCount[i] = 0;
		for(int k = 0; k < carddeck; k++){
			state.deck[i][k] = randcard();
		   }
	}

    for(int i = 0; i < playernum; i++){
    cardEffect(sea_hag, 0, 0, 0, &state, 0, 0);

    printf("Testing sea_hag\n");
    newassert(!(state.discardCount[1] == 0));
	newassert(!(state.discardCount[1] == 1));
    newassert((state.deck[i][0]) == curse);
    printf("Testing complete on sea_hag\n");

}
return 0;
}
