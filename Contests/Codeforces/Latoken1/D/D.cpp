#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    set<pair<int,int>> edges;

    auto query = [&](int node) {
        cout << "? " << node << endl;
        vector<int> d(N);
        for(auto &u: d)
            cin >> u;
        for(int i = 1; i <= N; i++) {
            if(d[i - 1] == 1) {
                edges.insert({min(i, node), max(i, node)});
            }
        }
        return d;
    };

    auto d = query(1);
    int z = 0;
    for(auto u: d)
        if(u % 2 == 0) {
            z++;
        }

    int target = 0;

    if(z > N / 2) {
        target = 1;
    }

    for(int i = 2; i <= N; i++) {
        if(d[i - 1] % 2 == target) {
            query(i);
        }
    }

    cout << "!" << endl;
    for(auto u: edges) {
        cout << u.first << " " << u.second << endl;
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