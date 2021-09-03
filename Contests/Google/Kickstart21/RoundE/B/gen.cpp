#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int N = rnd.next(1, 10);
    int C = rnd.next(1, N + 10);
    println(N, C);
    for(int i = 0; i < N; i++) {
        int L = rnd.next(1, 20);
        int R = rnd.next(L + 1, 30);
        println(L, R);
    }
}