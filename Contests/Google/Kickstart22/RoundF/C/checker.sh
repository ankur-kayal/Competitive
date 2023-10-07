g++ C_AC.cpp -o code.out -std=c++17 -O2
g++ gen.cpp -o gen.out -std=c++17 -O2
g++ C.cpp -o brute.out -std=c++17 -O2
for((i = 1; ; ++i)); do
    ./gen.out $i > input_file
    ./code.out < input_file > myAnswer
    ./brute.out < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer