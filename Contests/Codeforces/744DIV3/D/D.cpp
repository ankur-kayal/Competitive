#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<pair<int,int>> ans;

    priority_queue<pair<int,int>> pq;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a == 0) continue;
        pq.push({a, i + 1});
    }

    while(pq.size() > 1) {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();

        ans.emplace_back(a.second, b.second);

        a.first--;
        b.first--;

        if(a.first > 0) {
            pq.push(a);
        }

        if(b.first > 0) {
            pq.push(b);
        }
    }

    cout << ans.size() << '\n';

    for(auto [a, b] : ans) {
        cout << a << " " << b << '\n';
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