#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(5);
    for(int i=0;i<5;i++) {
        int t = rnd.next(0, 1);
        int n = rnd.next(100'000, 200'000);
        vector<int> p(n);
        forn(i, n)
            if (i > 0)
                p[i] = rnd.wnext(i, t);

        println(n);
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

        for (int i = 0; i + 1 < n; i++)
            printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
    }
    
}