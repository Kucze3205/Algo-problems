#!/bin/bash
for((i = 0; ; i++)) do
	echo $i
	echo $i > seed
	./gen < seed > sum.in
	./brut < sum.in > brut.out
	./sum < sum.in > sum.out
	diff -d brut.out sum.out || break;
done
