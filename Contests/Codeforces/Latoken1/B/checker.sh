for ((i=1; ; i++)); do
    echo $i
    ./gen.out $i > in2
    ./B.out < in2 > out2 || break
    # ./<bad program> < in2 > out1
    # diff -w out1 out2 || break
done