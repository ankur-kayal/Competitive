#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    int t = 1000;
    println(t);
    while(t--) {
        int n = 200;
        println(n);
        vector<int> u(200, 1);
        int start = 0;
        vector<int> indices = {0};
        int rounds = 5;
        for(int i=1;i<=rounds;i++) {
            indices.push_back(indices.back() + n / rounds);
        }
        for(int i=0;i<indices.size()-1;i++) {
            for(int j=indices[i];j<indices[i + 1];j++) {
                u[j] = i + 1;
            }
        }
        vector<int> s(200);
        // for(int i=0;i<n;i++) {
        //     u[i] = rnd.next(1, 100);
        // }
        for(int i=0;i<n;i++) {
            s[i] = rnd.next(100'000'000, 1000'000'000);
            // s[i] = 1000'000'000;
        }
        println(u);
        println(s);
    }
    
}