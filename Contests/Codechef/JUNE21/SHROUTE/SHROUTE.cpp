#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int64_t INF64 = int64_t(2e18) + 5;
 
struct Dijkstra {
    struct edge {
        int node = -1;
        int64_t weight = 0;
 
        edge() {}
 
        edge(int _node, int64_t _weight) : node(_node), weight(_weight) {}
    };
 
    struct state {
        int64_t dist;
        int node;
 
        state() {}
 
        state(int64_t _dist, int _node) : dist(_dist), node(_node) {}
 
        bool operator<(const state &other) const {
            return dist > other.dist;
        }
    };
 
    int n;
    vector<vector<edge>> adj;
    vector<int64_t> dist;
    vector<int> parent;
 
    Dijkstra(int _n = 0) {
        init(_n);
    }
 
    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }
 
    void add_directional_edge(int a, int b, int64_t weight) {
        adj[a].emplace_back(b, weight);
    }
 
    void add_bidirectional_edge(int a, int b, int64_t weight) {
        add_directional_edge(a, b, weight);
        add_directional_edge(b, a, weight);
    }
 
    void dijkstra_check(priority_queue<state> &pq, int node, int from, int64_t new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            parent[node] = from;
            pq.emplace(new_dist, node);
        }
    }
 
    void dijkstra(const vector<int> &source) {
        if (n == 0) return;
        dist.assign(n, INF64);
        parent.assign(n, -1);
        priority_queue<state> pq;
 
        for (int src : source)
            dijkstra_check(pq, src, -1, 0);
 
        while (!pq.empty()) {
            state top = pq.top();
            pq.pop();
 
            if (top.dist > dist[top.node])
                continue;
 
            for (edge &e : adj[top.node])
                dijkstra_check(pq, e.node, top.node, top.dist + e.weight);
        }
    }
};

void run_cases() {
    int N, M;
    cin >> N >> M;

    Dijkstra graph;
    graph.init(N);

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    vector<int64_t> B(M);
    for(auto &u: B)
        cin >> u;

    int root = 0;

    for(int i = 0; i < N; i++){
        if(A[i] != 0) {
            graph.add_bidirectional_edge(root, i, 0);
        }
    }

    int right = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            right = i;
        }
        else if(A[i] == 0 && right != -1) {
            graph.add_bidirectional_edge(i, right, i - right);
        }
    }

    int left = -1;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] == 2) {
            left = i;
        } else if(A[i] == 0 && left != -1) {
            graph.add_bidirectional_edge(i, left, left - i);
        }
    }

    graph.dijkstra({root});    

    for(auto u: B) {
        cout << (graph.dist[u - 1] != INF64 ? graph.dist[u - 1] : -1) << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}