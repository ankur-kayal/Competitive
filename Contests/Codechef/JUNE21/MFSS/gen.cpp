#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int maxA = 1e7;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int N = rnd.next(1, 1000);
    vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        A[i] = rnd.next(-maxA, maxA);
    }
    println(N);
    println(A);
}