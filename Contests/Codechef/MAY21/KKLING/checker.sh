# for ((i=1; ; i++)); do
#     echo $i
#     ./gen.out $i > in2
#     ./AC.out < in2 > good
#     ./KKLING_lca.out < in2 > bad
#     diff -w good bad || break
# done

for ((i=1; ; i++)); do
    echo $i
    ./max_gen.out $i > in2
    ./KKLING_lca.out < in2 > good || break
done