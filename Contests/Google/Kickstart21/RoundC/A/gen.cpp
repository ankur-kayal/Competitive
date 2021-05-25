#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int n = rnd.next(1, 8);
    int k = rnd.next(1, 5);
    string s = "";
    for(int i=0;i<n;i++) {
        s += (rnd.next(0, k - 1) + 'a');
    }
    println(n, k);
    println(s);
}