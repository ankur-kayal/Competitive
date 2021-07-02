#include "testlib.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char*argv[]) {
    freopen("log.txt", "w", stderr);
    registerGen(argc, argv, 1);
       
    int n = opt<int>(1);
    int t = rnd.next(0, 1);

    vector<int> p(n);
    forn(i, n)
        if (i > 0)
            p[i] = rnd.wnext(i, t);

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
    for(auto &u: edges) {
        if(u.first > u.second) {
            swap(u.first, u.second);
        }
    }
    sort(edges.begin(), edges.end());


    vector<vector<int>> adj(n);
    for(auto [u, v]: edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << n << endl;
    int moves = 0;
    vector<int> dists(n);

    function<void(int, int)> dfs = [&](int node, int par) -> void {
        for(int child: adj[node]) {
            if(child != par) {
                dists[child] = dists[node] + 1;
                dfs(child, node);
            }
        }
    };
    while(moves <= (n + 1) / 2) {
        char ch;
        cin >> ch;
        if(ch == '?') {
            int v;
            cin >> v;
            --v;
            dists.assign(n, 0);
            dfs(v, -1);
            for(auto u: dists) {
                cout << u << " ";
            }
            cout << endl;
        } else {
            vector<pair<int,int>> ans;
            for(int i = 1; i < n; i++) {
                int u, v;
                cin >> u >> v;
                --u, --v;
                if(u > v)
                    swap(u, v);
                ans.emplace_back(u, v);
            }
            sort(edges.begin(), edges.end());
            sort(ans.begin(), ans.end());
            if(ans != edges) {
                for(auto u: edges) {
                    cerr << u.first + 1 << " " << u.second + 1 << ' ';
                }
                cerr << '\n';
                for(auto u: ans) {
                    cerr << u.first + 1 << " " << u.second << '\n';
                }
                cerr << "WA" << endl;
                exit(1);
            }
            break;
        }
        moves++;
    }
    cerr << moves << endl;
    if(moves > (n + 1) / 2) {
        cerr << "Queries Exceeded!!";
        exit(1);
    } else {
        cerr << "Passed!";
    }
    cout << endl;
}