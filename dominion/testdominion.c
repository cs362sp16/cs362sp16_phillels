#include "dominion.h"
#include <stdio.h>
#include "stdlib.h"
#include "myassert.h"
#include "stdbool.h"
#include "assert.h"


#define MAX_CARD (treasure_map + 1)

enum CARD randcard(){
    return rand() % (treasure_map +1);
}

void print_hand(struct gameState *gs, int player) {
	printf("hand %d: ", player);
	for (int i = 0; i < gs->handCount[player]; ++i) {
		printf("%d, ", gs->hand[player][i]);
	}
	printf("\n");
}

int has_action(struct gameState *gs, int player) {
	for (int i = 0; i < gs->handCount[player]; ++i) {
		if (gs->hand[player][i] >= adventurer) return 1;
	}
	return 0;
}

extern int getCost(int cardNumber);

int main(int argc, char** argv){
	int seed = atoi(argv[1]);
	srand(seed);
	struct gameState state = {0};
	int playernum = (rand() % 2) + 2;
	state.numPlayers = playernum;


    //selecting random kingdomCards

	int checkedArr[10];
	int duplicate = 0;
	int kc = 0;

	for(int p = 0; p < 10; p++) {
		do {
			kc = (randcard() % (MAX_CARD - 7))+7;
			// fuck feast
			if (kc==feast) continue;
			printf("%d\n", kc);
			//7 because we don't want to select money or estate cards
			duplicate = 0;
			for(int k = 0; k < p; k++)
				if(checkedArr[k] == kc)
					duplicate = 1;
	     } while (duplicate != 0);
		 checkedArr[p] = kc;
		 printf("position: %d card: %d\n", p, checkedArr[p]);
	 }

	initializeGame(playernum, kingdomCards(checkedArr[0],checkedArr[1], checkedArr[2],checkedArr[3],checkedArr[4],checkedArr[5],checkedArr[6],checkedArr[7],checkedArr[8],checkedArr[9]), seed, &state);
	int initialcoppercount = fullDeckCount(0,copper,&state);
	assert(getCost(curse) == 0);
	assert(getCost(estate) == 2);
	assert(getCost(duchy) == 5);
	assert(getCost(province) == 8);
	assert(getCost(copper) == 0);
	assert(getCost(silver) == 3);
	assert(getCost(gold) == 6);
	assert(getCost(adventurer) == 6);
	assert(getCost(council_room) == 5);
	assert(getCost(feast) == 4);
	assert(getCost(gardens) == 4);
	assert(getCost(mine) == 5);
	assert(getCost(remodel) == 4);
	assert(getCost(smithy) == 4);
	assert(getCost(village) == 3);
	assert(getCost(baron) == 4);
	assert(getCost(great_hall) == 3);
	assert(getCost(minion) == 5);
	assert(getCost(steward) == 3);
	assert(getCost(tribute) == 5);
	assert(getCost(ambassador) == 3);
	assert(getCost(cutpurse) == 4);
	assert(getCost(embargo) == 2);
	assert(getCost(outpost) == 5);
	assert(getCost(salvager) == 4);
	assert(getCost(sea_hag) == 4);
	assert(getCost(treasure_map) == 4);

	while(true){
		int selected;
		int i = 0;
		print_hand(&state, i);
		if (has_action(&state, i)) {
			while(true){
				//srand(seed + i);
				selected = rand() % 5;
				if(handCard(selected,&state) >= adventurer && handCard(selected,&state) <= treasure_map){
					break;
				}
				i++;
			}

			int randchoice1 = rand() % 5;
			int randchoice2 = rand() % 5;
			int randchoice3 = rand() % 5;
			playCard(selected,randchoice1,randchoice2,randchoice3, &state); //choose a random # between 1-5
		}
		int card2buy = rand() % 10;
		printf(" The card I am initially buying is %d\n", card2buy);
		printf("Supply Count of this card is: %d\n", supplyCount(card2buy, &state));
		printf("The cost of this card is: %d\n", getCost(card2buy));
		printf("The amount of money I have is: %d\n", state.coins);
		while(supplyCount(card2buy, &state) <= 0 && getCost(card2buy) <= state.coins){
		//while(!supplyCount(card2buy, &state) || (!(getCost(card2buy) > state.coins))) {
			card2buy+= rand();
			card2buy %= 10;
			printf("%s\n", "Not enough of that card to purchase" );
		}
		printf("The verified card I'm buying is %d\n", card2buy);
/*
		if(state.coins >= 5){
			buyCard(duchy, &state);
			printf("%s\n", "Duchy bought!" );
	}*/
	//printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> %d\n", card2buy);
		buyCard(card2buy,&state);
		if (isGameOver(&state)){
			getWinners(&playernum, &state);
			return 0;
		}
		else(endTurn(&state));

   	}
	int finalcoppercount = fullDeckCount(0,copper,&state);
	assert(finalcoppercount>=initialcoppercount);
	return 0;
}
