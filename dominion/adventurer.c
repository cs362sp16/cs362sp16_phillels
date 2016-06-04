#include "cards.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "stdio.h"

int adventurer_action (int drawntreasure, struct gameState *state, int currentPlayer){
  int temphand[MAX_HAND];// moved above the if statement
  int z = 0;// this is the counter for the temp hand
  int cardDrawn;
  while(drawntreasure<2){
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state); //t
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
    drawntreasure++; //t
    else{
      temphand[z]=cardDrawn;
      state->handCount[currentPlayer]--; //t //this should just remove the top card (the most recently drawn one).
      z++;
    }
  }
  while(z-1>=0){
    state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];//t  // discard all cards in play that have been drawn
    z=z-1;
  }
  return 0;
}
