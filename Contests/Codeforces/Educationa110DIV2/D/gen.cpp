#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);

    int K = 18;
    int N = (1 << K) - 1;

    string S(N, '?');

    println(K);
    println(S);

    int Q = 2e5;
    println(Q);
    vector<int> query_indices((1 << (K - 1)));
    iota(query_indices.begin(), query_indices.end(), 0);

    int max_ind = query_indices.size();

    char c[] = {'?', '0', '1'};

    while(Q--) {
        int prob = rnd.next(0, 2);
        int index = rnd.next(1, max_ind);
        println(index, c[prob]);
    }
}