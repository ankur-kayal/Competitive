#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    
    int t = 1;
    println(t);

    int n = rnd.next(1, 10);
    println(n);

    for(int i = 0; i < n; i++) {
        int k = rnd.next(0, min(2, n - 1));
        vector<int> bundle;
        bundle.push_back(k);
        set<int> contains;
        contains.insert(i + 1);
        for(int j = 0; j < k; j++) {
            int x = rnd.next(1, n);
            while(contains.count(x)) {
                x = rnd.next(1, n);
            }
            contains.insert(x);
            bundle.push_back(x);
        }
        println(bundle);
    }
}