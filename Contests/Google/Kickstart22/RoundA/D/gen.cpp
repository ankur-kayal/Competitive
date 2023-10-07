#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);

    int t = 100;
    println(t);
    const long long maxN = 1e12;
    for(int i = 0; i < t; i++) {
        long long A = rnd.next(1LL, maxN);
        long long B = rnd.next(A, maxN);
        println(A, B);
    }
    
}