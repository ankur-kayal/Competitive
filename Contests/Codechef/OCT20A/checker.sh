for ((i=1; ; i++)); do
	echo $i
	./gen $i > in2
	./SEGCOMPR_brute2 < in2 > out2
	./SEGCOMPR_brute1 < in2 > out1
	diff -w out1 out2 || break
done






