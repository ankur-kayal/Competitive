#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    

    vector<vector<int>> cases;

    for(int i = 1; i <= 7; i++) {
        for(int k = 1; k <= i; k++) {
            cases.push_back({i, k});
        }
    }

    println(cases.size());
    for(auto u: cases) {
        println(u);
    }
}