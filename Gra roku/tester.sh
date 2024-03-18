#!/bin/bash
for((i = 0; ; i++))do
	echo $i > seed
	echo $i
	./gen < seed > gra.in
	./brut < gra.in > brut.out
	./gra < gra.in > gra.out
	diff -d gra.out brut.out || break;
done
