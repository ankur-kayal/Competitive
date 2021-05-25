#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &u: a)
        cin >> u;
    map<int,int> cnt;
    for(auto u: a)
        cnt[u]++;
    cout << n - cnt.begin()->second << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}