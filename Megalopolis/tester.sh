for((i = 0; ;i++)) do
	echo $i
	echo $i > seed
	./gen < seed > meg.in
	./meg < meg.in > meg.out
	./brut < meg.in > brut.out
	diff -w meg.out brut.out || break;
done
	
