#!/bin/bash

for(( i = 0; ; i++ ))
do
	echo $i > seed
	./gen < seed > pod.in
	./brut < pod.in > brut.out
	./pod < pod.in > pod.out
	if diff -d brut.out pod.out
	then 
		echo "git $i"
	else 
		echo "nie jest git $i"
		break
	fi
done
	
