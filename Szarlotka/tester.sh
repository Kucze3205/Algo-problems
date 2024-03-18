#!/bin/bash

for((i = 0; ; i++))
do
	echo $i
	echo $i > seed
	./gen < seed > sza.in
	./brut < sza.in > brut.out
	./sza1 < sza.in > sza.out
	if diff -d brut.out sza.out
	then continue;
	else break;
	fi
done
