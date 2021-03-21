#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = 1;

    int r = rnd.next(2, 2);
    int c = rnd.next(2, 2);

    int x = rnd.next(2, min(r,c));

    vector<vector<int>> a(r, vector<int>(c)), b(r, vector<int>(c));

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            a[i][j] = rnd.next(-100, 100);
            b[i][j] = rnd.next(-100, 100);
        }
    }

    println(t);
    println(r,c,x);
    for(auto u: a) {
        println(u);
    }
    for(auto u: b) {
        println(u);
    }
}