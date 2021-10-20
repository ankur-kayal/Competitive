#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    
    int t = 1;
    println(t);

    int D = rnd.next(2, 1000);
    int N = rnd.next(1, 1000);
    int K = rnd.next(1, N);

    println(D, N, K);

    for(int i = 0; i < N; i++) {
        int h = rnd.next(1, 300000);
        int s = rnd.next(1, D - 1);
        int e = rnd.next(s, D);
        println(h, s, e);
    }
}