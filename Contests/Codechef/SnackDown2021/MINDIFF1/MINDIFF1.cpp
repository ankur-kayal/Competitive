#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<int> degree(N);
    vector<int> values(N, -1);
    vector<vector<int>> adj(N);
    vector<bool> vis(N, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        --u , --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    for(int i = 0; i < N; i++) {
        pq.push({degree[i], i});
    }

    int current_value = N;

    while(!pq.empty()) {
        int node = pq.top().second;
        int current_degree = pq.top().first;
        pq.pop();

        if(current_degree > degree[node]) {
            continue;
        }
        vis[node] = true;

        values[node] = current_value;
        current_value--;

        for(int neighbour: adj[node]) {
            if(!vis[neighbour]) {
                degree[neighbour]--;
                pq.push({degree[neighbour], neighbour});
            }
        }
    }

    int maximum = 0;

    for(int i = 0; i < N; i++) {
        int tmp = 0;
        for(int neighbour: adj[i]) {
            if(values[neighbour] < values[i]) {
                tmp++;
            }
        }
        maximum = max(maximum, tmp);
    }

    cout << maximum << '\n';

    for(int value: values) {
        cout << value << " ";
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