#include "testlib.h"
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int n = rnd.next(1, 10);
    int t = rnd.next(1, 2);
    int k;
    int prob = rnd.next(1,100);
    if(prob <= 50) {
        k = 1;
    } else {
        k = 2;
    }

    vector<int> p(n);
    forn(i, n)
        if (i > 0)
            p[i] = rnd.wnext(i, t);

    println(n,k);
    vector<int> perm(n);
    forn(i, n)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());
    vector<pair<int,int> > edges;

    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    shuffle(edges.begin(), edges.end());

    for (int i = 0; i + 1 < n; i++){
        println(edges[i].first + 1, edges[i].second + 1);
    }

    return 0;
}