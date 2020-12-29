for ((i=1; ; i++)); do
    echo $i
    ./gen $i  > in2
    python3 WINLS1.py < in2 > out2
    ./WINLS1 < in2 > out1
    diff -w out1 out2 || break
done