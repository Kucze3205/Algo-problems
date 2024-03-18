#!/bin/bash
for((i = 0; ;i++))do
	echo $i
	echo $i > seed
	./gen < seed > uci.in
	./brut < uci.in > brut.out
	./uci < uci.in > uci.out
	diff -d brut.out uci.out || break;
done
