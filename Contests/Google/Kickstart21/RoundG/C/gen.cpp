#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    

    println(1);

    int N = rnd.next(1, 500);
    int K = rnd.next(1, 10000);

    vector<int> B(N);
    for(auto &u: B) {
        u = rnd.next(0, K);
    }

    println(N, K);
    println(B);
}