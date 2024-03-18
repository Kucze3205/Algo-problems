#!/bin/bash

for ((i = 1; ; i++))
do
	echo $i
	./prz < testy/prz$i.in > prz.out;
	if diff -b prz.out testy/prz$i.out
	then continue;
	else break;
	fi
done
