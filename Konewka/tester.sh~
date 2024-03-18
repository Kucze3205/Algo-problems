#!/bin/bash

for((i = 1; ; i++))do
	echo $i > seed;
	echo $i;
	./gen < seed > kon0.in
	./kon50pkt < kon0.in > brut.out
	./kon < kon0.in > kon.out
	diff -d brut.out kon.out || break;
done
