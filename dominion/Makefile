CFLAGS = -Wall -fpic -coverage -lm
CC = clang

rngs.o: rngs.h rngs.c
	$(CC) -c rngs.c -g  $(CFLAGS)


dominion.o: dominion.h dominion.c rngs.o cards.o
	$(CC) -c dominion.c -g  $(CFLAGS)

cards.o: cards.h cards.c
	$(CC) -c cards.c -g $(CFLAGS)

playdom: dominion.o playdom.c
	$(CC) -o playdom playdom.c -g dominion.o rngs.o cards.o $(CFLAGS)

interface.o: interface.h interface.c
	$(CC) -c interface.c -g  $(CFLAGS)

player: player.c interface.o dominion.o
	$(CC) -o player player.c -g dominion.o rngs.o interface.o cards.o $(CFLAGS)

unittest: $(WILDCARD unittest/*.c) dominion.o
	$(CC) -o unittest1 unittest/unittest1.c dominion.o rngs.o cards.o $(CFLAGS)
	$(CC) -o unittest2 unittest/unittest2.c dominion.o rngs.o cards.o $(CFLAGS)
	$(CC) -o unittest3 unittest/unittest3.c dominion.o rngs.o cards.o $(CFLAGS)
	$(CC) -o unittest4 unittest/unittest4.c dominion.o rngs.o cards.o $(CFLAGS)

cardtest: $(WILDCARD unittest/*.c) dominion.o
	$(CC) -o cardtest1 cardtest/cardtest1.c dominion.o rngs.o cards.o $(CFLAGS)
	$(CC) -o cardtest2 cardtest/cardtest2.c dominion.o rngs.o cards.o $(CFLAGS)
	$(CC) -o cardtest3 cardtest/cardtest3.c dominion.o rngs.o cards.o $(CFLAGS)
	$(CC) -o cardtest4 cardtest/cardtest4.c dominion.o rngs.o cards.o $(CFLAGS)

autotest: unittest
	./goas.sh > unittestresults.out 

all: playdom player unittest cardtest

clean:
	rm -rf *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
