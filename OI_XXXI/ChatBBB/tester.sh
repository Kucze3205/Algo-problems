#!/bin/bash

for ((i = 1; ; i++))
do
	echo $i
	./cza1 < testy/cza$i.in > cza.out;
	if diff -b cza.out testy/cza$i.out
	then continue;
	else break;
	fi
done
