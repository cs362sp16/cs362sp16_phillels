#include "dominion.h"
#include <stdio.h>
#include "stdlib.h"
#include "myassert.h"
#include "stdbool.h"

#define MAX_CARD (treasure_map + 1)

enum CARD randcard(){
    return rand() % (treasure_map +1);
}

int main(int argc, char** argv){
	int seed = atoi(argv[1]);
	srand(seed);
	struct gameState state = {0};
	int playernum = rand() % 2 + 2;
	state.numPlayers = playernum;


    //selecting random kingdomCards

	int checkedArr[10];
	int duplicate = 0;
	int kc = 0;

	for(int p = 0; p < 10; p++) {
		do {
			kc = (randcard() % (MAX_CARD - 7))+7;
			//7 because we don't want to select money or estate cards
			duplicate = 0;
			for(int k = 0; k < p; k++)
				if(checkedArr[k] == kc)
					duplicate = 1;
	     } while (duplicate != 0);
		 checkedArr[p] = kc;
	 }



	initializeGame(playernum, checkedArr, seed, &state);
	while(true){
		int selected;
		int i = 0;
		while(true){
			srand(seed + i);
			selected = rand() % 5;
			if(handCard(selected,&state) < adventurer || handCard(selected,&state) < adventurer){
				break;
			}
			i++;
		}

		int randchoice1 = rand() % 5;
		srand(seed+1);
		int randchoice2 = rand() % 5;
		srand(seed+7);
		int randchoice3 = rand() % 5;
		playCard(selected,randchoice1,randchoice2,randchoice3, &state); //choose a random # between 1-5
    	int card2buy = rand() % 10;
		while(!supplyCount(card2buy, &state)) {
			card2buy++;
			card2buy %= 10;
		}
		buyCard(card2buy,&state);
		if (isGameOver(&state)){
			getWinners(&playernum, &state);
		}
		else(endTurn(&state));

   	}
	return 0;
}
