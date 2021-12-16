#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    
    vector<vector<int>> cases;
    for(int N = 1; N <= 1000; N++) {
        for(int K = 0; K <= N; K++) {
            cases.push_back({N, K});
        }
    }

    println(cases.size());
    for(auto u: cases) {
        println(u);
    }
}