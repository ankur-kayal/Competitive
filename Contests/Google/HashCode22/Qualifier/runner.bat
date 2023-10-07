g++ -g -Wall -Wshadow -fmax-errors=2 -static -DLOCAL  -Wl,--stack=1073741824 -O2 -std=c++17 main.cpp -o main.exe

rem processing input and output files

main.exe < input/a.txt > output/a.txt
main.exe < input/b.txt > output/b.txt
main.exe < input/c.txt > output/c.txt
main.exe < input/d.txt > output/d.txt
main.exe < input/e.txt > output/e.txt
main.exe < input/f.txt > output/f.txt