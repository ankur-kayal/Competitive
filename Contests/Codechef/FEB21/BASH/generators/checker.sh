for ((i=1; ; i++)); do
    echo $i
    ./generator.out $i > in$i
    ./BASH.out < in$i > out$i
    break
done