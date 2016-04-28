#!/bin/bash
utest="unittest1 unittest2 unittest3 unittest4"
ctest="cardtest1 cardtest2 cardtest3 cardtest4"

rm -f unittestresults.out

for i in $utest $ctest; do
	rm -f dominion.gcda
	echo "---- $i ----" >> unittestresults.out
	./$i >> unittestresults.out 2>&1
	echo >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo >> unittestresults.out
done

rm -f dominion.gnco-fresh
