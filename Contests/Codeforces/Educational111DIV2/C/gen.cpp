#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    int t = 1;
    println(t);
    int n = rnd.next(1, 10);
    vector<int> A(n);
    for(auto &u: A)
        u = rnd.next(1, 10);
    println(n);
    println(A);
}