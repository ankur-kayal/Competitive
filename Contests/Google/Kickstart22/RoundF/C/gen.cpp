#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    
    int t = 1;
    println(t);

    while(t--) {
        int N = rnd.next(1, 15);
        int D = rnd.next(2, 5);
        int X = 1;

        println(N, X, D);
        
        for(int i = 0; i < N; i++) {
            int q = 1;
            int l = rnd.next(1, D - 1);
            int v = rnd.next(1, 10);

            println(q, l, v);
        }
    }

}