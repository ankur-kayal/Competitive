#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    int N = rnd.next(1, 6);
    vector<int> A(N);
    for(auto &u: A)
        u = rnd.next(1, 5);

    println(N);
    println(A);
}