for ((i=1; ; i++)); do
    echo $i
    ./gen $i > in2
    ./steven < in2 > out2
    ./neal < in2 > out1
    diff -w out1 out2 || break
done