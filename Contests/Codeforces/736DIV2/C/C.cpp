#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, M;
    cin >> N >> M;

    // add a directed edge from small to large, 
    // and answer to each query is no of vertices with zero outdegree

    vector<int> outdegree(N + 1);
    int alive = N;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v) {
            swap(u, v);
        }
        if(outdegree[u] == 0) {
            alive--;
        }
        outdegree[u]++;
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int ch;
        cin >> ch;

        if(ch == 1) {
            int u, v;
            cin >> u >> v;
            if(u > v) {
                swap(u, v);
            }
            if(outdegree[u] == 0) {
                alive--;
            }
            outdegree[u]++;
        } else if(ch == 2) {
            int u, v;
            cin >> u >> v;
            if(u > v) {
                swap(u, v);
            }
            outdegree[u]--;
            if(outdegree[u] == 0) {
                alive++;
            }
        } else {
            cout << alive << '\n';
        }
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