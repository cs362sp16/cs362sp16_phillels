#include "../dominion.h"
#include <stdio.h>
#include "stdlib.h"
#include "myassert.h"
#include <signal.h>
#include <unistd.h>



enum CARD randcard(){
    return rand() % (treasure_map +1);
}

void infiniteloop(int sig) {
    printf("The function ran too long and might be an infinite loop! \n");
    newassert(0);
}

int main(int argc, char** argv){
    int seed = atoi(argv[1]);
	srand(seed);
	signal(SIGALRM, infiniteloop);

    unsigned short amountTreasure[MAX_PLAYERS] = {0};

	struct gameState state = {0};
	int playernum = rand() % MAX_PLAYERS;
	state.numPlayers = playernum;
	for(int i = 0; i < playernum; i++){
	    int carddeck = rand() % 45;
	    state.deckCount[i] = carddeck;
	    state.handCount[i] = 0;
		state.hand[i][0] = adventurer;
		//count number of treasures given
		for(int k = 1; k < carddeck; k++){
			enum CARD newcard = randcard();
			state.deck[i][k] = newcard;

		    if((newcard == copper || newcard == silver || newcard == gold )  && amountTreasure[i] < 2) {
                amountTreasure[i]++;
            }
		}
	}

	//alarm will go off if it runs for more than 7 seconds
	alarm(7);
    for (int i = 0; i < playernum; i++) {
	   state.numActions = rand() % 15;
	   printf("Testing adventurer\n");
	   cardEffect(adventurer,0,0,0, &state, 0, 0);

	   // The player drew as many treasures as we counted with a maximum of 2
	   newassert(state.handCount[i] == amountTreasure[i]);

	   printf("Testing complete on adventurer\n");
	   // turn alarm off.
	   alarm(0);
   }



   return 0;
 }
