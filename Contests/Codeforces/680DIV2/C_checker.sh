for ((i=1; ; i++)); do
	echo $i
	./C__Generator $i > in2
	./C__Good < in2 > out2
	./C < in2 > out1
	diff -w out1 out2 || break
done






