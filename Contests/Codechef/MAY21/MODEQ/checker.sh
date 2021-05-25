for ((i=1; ; i++)); do
    echo $i
    ./gen.out $i > in2
    ./brute.out < in2 > out2
    ./MODEQ_alter.out < in2 > out1
    diff -w out1 out2 || break
done