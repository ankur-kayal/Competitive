#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    
    println(1);

    int N = rnd.next(2, 100000);

    vector<int> A(N);

    for(auto &u: A) {
        u = rnd.next(-1e9, 1e9);
    }

    println(N);
    println(A);
}