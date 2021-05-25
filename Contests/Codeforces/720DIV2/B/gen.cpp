#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int n = rnd.next(1, 10);
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        a[i] = rnd.next(1, 100);
    }
    println(n);
    println(a);
}