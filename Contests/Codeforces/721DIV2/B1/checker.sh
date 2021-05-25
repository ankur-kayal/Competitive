for ((i=1; ; i++)); do
    echo $i
    ./gen.out $i > in2
    ./B1.out < in2 > out2 || break
    ./hack.out < in2 > out1 || break
    diff -w out1 out2 || break
done