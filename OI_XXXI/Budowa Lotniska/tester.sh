#!/bin/bash

for ((i = 1; ; i++))
do
	echo $i
	./bud < testy_bud/in/bud$i.in > bud.out;
	if diff -b bud.out testy_bud/out/bud$i.out
	then continue;
	else break;
	fi
done
