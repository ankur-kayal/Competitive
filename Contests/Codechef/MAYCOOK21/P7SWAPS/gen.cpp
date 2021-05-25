#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);

    int N = rnd.next(1, 10);
    vector<int> A(N);
    iota(A.begin(), A.end(), 1);
    shuffle(A.begin(), A.end());
    vector<int> P(N);
    iota(P.begin(), P.end(), 1);
    shuffle(P.begin(), P.end());

    println(N);
    println(A);
    println(P);

    int Q = rnd.next(1, 10);
    println(Q);
    while(Q--) {
        int ch = rnd.next(1, 3);
        if(ch == 1) {
            println(ch);
        } else if(ch == 2) {
            int x = rnd.next(1, N - 1);
            int y = rnd.next(x + 1, N);
            println(ch, x, y);
        } else {
            int x = rnd.next(1, N);
            println(ch, x);
        }
    }
}