#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int N = rnd.next(1, 10);
    vector<int> A(N);
    for(auto &u: A)
        u = rnd.next(1, 20);

    println(N);
    println(A);
}