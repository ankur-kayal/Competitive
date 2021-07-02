#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int N = rnd.next(1, 20);
    vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        A[i] = rnd.next(0, int(1e9));
    }
    println(N);
    println(A);
}