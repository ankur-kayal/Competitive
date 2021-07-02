#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int N = rnd.next(2, 200);
    int t = rnd.next(0, 1);
    int Q = N * (N - 1);
    println(N, Q);

    vector<int> p(N);
    forn(i, N)
        if (i > 0)
            p[i] = rnd.wnext(i, t);

    vector<int> perm(N);
    forn(i, N)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());
    vector<pair<int,int> > edges;

    for (int i = 1; i < N; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    shuffle(edges.begin(), edges.end());

    for (int i = 0; i + 1 < N; i++)
        printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(j != i) {
                println(i, j);
            }
        }
    }
    
}