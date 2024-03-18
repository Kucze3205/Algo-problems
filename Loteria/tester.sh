#!/bin/bash
for((i = 0; ; i++))do
	echo $i
	echo $i > seed
	./gen < seed > lot.in
	./brut < lot.in > brut.out
	./lot < lot.in > lot.out
	diff -d lot.out brut.out || break;
done
