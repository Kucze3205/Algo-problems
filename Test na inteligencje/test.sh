#!/bin/bash

for(( i = 0; ; i++ ))
do
	echo $i > seed
	./gen < seed > tes.in
	./tes < tes.in > tes.out
	./brut < tes.in > brut.out
	if diff -b tes.out brut.out
	then
		echo "OK $i"
	else
		echo "NIE OK $i"
		break
	fi
done
