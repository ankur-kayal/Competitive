#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int N = rnd.next(2, 200);
    println(N);
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        A[i] = rnd.next(1, 100);
    }
    println(A);   
}