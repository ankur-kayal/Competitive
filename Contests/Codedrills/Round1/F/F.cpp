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
    int N, M;
    cin >> N >> M;
    vector<array<int, 3>> edges;
    vector<pair<int,int>> A(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = {a, i + 1};
    }

    DSU dsu(N + 1);

    sort(A.begin(), A.end());
    for(int i = 0; i < N - 1; i++) {
        edges.push_back({A[i + 1].first - A[i].first, A[i + 1].second, A[i].second});
    }

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({0, u, v});
    }

    sort(edges.begin(), edges.end());

    int64_t weight = 0;
    vector<pair<int,int>> tree;

    for(auto [w, u, v]: edges) {
        if(dsu.find(u) != dsu.find(v)) {
            weight += w;
            dsu.unite(u, v);
            tree.emplace_back(u, v);
        }
    }
    cout << weight << " " << tree.size() << '\n';
    for(auto [u, v]: tree) {
        cout << u << " " << v << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}