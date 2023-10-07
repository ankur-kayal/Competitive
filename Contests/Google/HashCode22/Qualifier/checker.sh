ulimit -s unlimited
g++ sol.cpp -o sol.out -std=c++17 -O2 -DLOCAL

echo a
./sol.out < ./input/a.txt > ./output/a.txt 
echo b
./sol.out < ./input/b.txt > ./output/b.txt 
echo c
./sol.out < ./input/c.txt > ./output/c.txt 
echo d
./sol.out < ./input/d.txt > ./output/d.txt 
echo e
./sol.out < ./input/e.txt > ./output/e.txt 
echo f
./sol.out f < ./input/f.txt > ./output/f.txt 