for ((i=1; ; i++)); do
    echo $i
    ./generator.out $i 1 > in2
    ./MAXTOPO_brute.out < in2 > out2
    ./MAXTOPO.out < in2 > out1
    diff -w out1 out2 || break
done