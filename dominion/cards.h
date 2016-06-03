#ifndef _CARDS_H
#define _CARDS_H

#include "dominion.h"

int smithy_action(int, int, struct gameState*);
int village_action(int, int, struct gameState*);
int great_hall_action(int, int, struct gameState*);
int steward_action(int, int, int, int, int, struct gameState*);
int outpost_action(int, int, struct gameState*);

#endif
