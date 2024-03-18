for((i = 0; ; i++))do
	echo $i
	echo $i > seed
	./gen < seed > str.in
	./brut < str.in > brut.out
	./str < str.in > str.out
	diff -d str.out brut.out || break;
done
