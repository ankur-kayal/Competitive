for ((i=1; ; i++)); do
    echo $i
    ./generator.out $i > in2
    python3 CONSADD.py < in2 > out2
    ./bad.out < in2 > out1
    diff -w out1 out2 || break
done