for ((i=1; ; i++)); do
	echo $i
	./sso_gen $i > in2
	./sso_good < in2 > out2
	./sso < in2 > out1
	diff -w out1 out2 || break
done






