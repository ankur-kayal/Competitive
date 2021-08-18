#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

class DSU {
    public:
    vector<int> p;
    int n;
 
    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
 
    inline int find(int x) {
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }
 
    inline bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

void run_cases() {

    int N, M1, M2;
    cin >> N >> M1 >> M2;

    DSU tree1(N + 1), tree2(N + 1);

    for(int i = 0; i < M1; i++) {
        int u, v;
        cin >> u >> v;
        tree1.unite(u, v);
    }

    for(int i = 0; i < M2; i++) {
        int u, v;
        cin >> u >> v;
        tree2.unite(u, v);
    }

    vector<vector<int>> edges;

    auto add_edge = [&](int u, int v) {
        int parentu1 = tree1.find(u);
        int parentu2 = tree2.find(u);

        int parentv1 = tree1.find(v);
        int parentv2 = tree2.find(v);

        if(parentu1 != parentv1 && parentu2 != parentv2) {
            edges.push_back({u, v});
            tree1.unite(u, v);
            tree2.unite(u, v);
        }
    };

    for(int i = 1; i <= N; i++) {
        add_edge(1, i);
    }

    vector<int> p1, p2;

    for(int i = 1; i <= N; i++) {
        if(tree1.find(i) != tree1.find(1)) {
            p1.push_back(i);
        }
        if(tree2.find(i) != tree2.find(1)) {
            p2.push_back(i);
        }
    }

    int i = 0, j = 0;

    while(i < p1.size() && j < p2.size()) {
        int u = p1[i];
        int v = p2[j];

        if(tree1.find(u) == tree1.find(1) && tree2.find(u) == tree2.find(1)) {
            i++;
        } else if(tree2.find(v) == tree2.find(1) && tree1.find(v) == tree1.find(1)) {
            j++;
        } else {
            add_edge(u, v);
            i++;
            j++;
        }
    }

    cout << edges.size() << '\n';

    for(auto u: edges) {
        cout << u[0] << " " << u[1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}