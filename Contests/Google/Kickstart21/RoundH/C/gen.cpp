#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    
    int t = 1;
    println(t);

    int N = rnd.next(1, 20);
    string S = "";
    println(N);

    for(int i = 0; i < N; i++) {
        S += to_string(rnd.next(0, 9));
    }
    println(S);
}