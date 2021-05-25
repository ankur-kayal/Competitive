#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(2, 100);
    println(n);
    vector<int> a(n);
    for(int i=0;i<rnd.next(0, n / 2);i++) {
        int pos = rnd.next(0, n - 1);
        while(a[pos] == 1) {
            pos = rnd.next(0, n - 1);
        } 
        a[pos] = 1;
    }
    println(a);
}   