for ((i=1; ; i++)); do
    echo $i
    ./gen.out $i > in2
    python3 brute.py < in2 > good
    python3 MEXSTR2.py < in2 > bad
    diff -w good bad || break
done