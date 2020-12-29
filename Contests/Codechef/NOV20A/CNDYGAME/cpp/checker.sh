for ((i=100000000; ; i++)); do
	echo $i
	./testgen $i > in2
	./cndygame < in2 > out2
	./bad < in2 > out1
	diff -w out1 out2 || break
done