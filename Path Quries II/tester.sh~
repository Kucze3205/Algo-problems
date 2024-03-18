for((i = 0; ; i++))do
	echo $i
	echo $i > seed
	./gen < seed > ptq2.in
	./brut < ptq2.in > brut.out
	./ptq2 < ptq2.in > ptq2.out
	diff -w brut.out ptq2.out || break;
done
