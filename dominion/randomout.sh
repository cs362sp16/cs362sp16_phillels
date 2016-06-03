#!/bin/bash
randomtest="randomtestcard1 randomtestcard2 randomtestadventurer"

for i in $randomtest; do
	rm -f dominion.gcda
	rm -f $i.out
	echo "---- $i ----" >> $i.out
	./$i 42 >> $i.out 2>&1
	echo >> $i.out
	gcov dominion.c >> $i.out
	echo >> $i.out
done

rm -f dominion.gnco-fresh
