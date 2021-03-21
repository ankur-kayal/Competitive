for ((i=1; ; i++)); do
    echo $i
    ./generator.out $i > in2
    ./C2.out < in2 > out2 || break
done