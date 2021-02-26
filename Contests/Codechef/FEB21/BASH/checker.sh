for ((i=1; ; i++)); do
    echo $i
    ./generator.out $i > in
    ./BASH_30.out < in > out
done