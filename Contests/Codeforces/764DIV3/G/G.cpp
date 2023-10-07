#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define nl '\n'

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;
 
    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }
 
    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }
 
    int get_size(int x) {
        return -data[find(x)];
    }
 
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
 
        if (x == y)
            return false;
 
        if (-data[x] < -data[y])
            swap(x, y);
 
        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> edges;
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int answer = 0;

    for(int bit = 30; bit >= 0; bit--) {
        union_find tree(N + 1);
        vector<array<int, 3>> valid_edges;
        int edge_count = 0;
        for(int i = 0; i < edges.size(); i++) {
            if(edges[i][2] >> bit & 1) {
                continue;
            }
            valid_edges.push_back(edges[i]);
        }

        for(int i = 0; i < valid_edges.size(); i++) {
            edge_count += tree.unite(valid_edges[i][0], valid_edges[i][1]);
        }

        if(edge_count == N - 1) {
            edges = valid_edges;
        } else {
            answer += (1 << bit);
        }
    }

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}