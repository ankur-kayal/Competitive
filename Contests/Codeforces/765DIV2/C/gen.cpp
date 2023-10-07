#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    
    int N = rnd.next(1, 10);
    int L = rnd.next(N + 1, 20);
    int K = rnd.next(0,N - 1);

    vector<int> D;
    D.push_back(0);
    for(int i = 1; i < N; i++) {
        int x = rnd.next(0, L - 1);
        while(count(D.begin(), D.end(), x)) {
            x = rnd.next(0, L - 1);
        }
        D.push_back(x);
    }

    sort(D.begin(), D.end());

    vector<int> A;
    for(int i = 0; i < N; i++) {
        A.push_back(rnd.next(1, 10));
    }

    println(N, L, K);
    println(D);
    println(A);
}