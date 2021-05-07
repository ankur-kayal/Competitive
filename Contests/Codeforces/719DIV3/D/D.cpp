#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for(auto &u: a)
        cin >> u;

    map<int64_t,int64_t> cnt;
    int64_t ans = 0;
    for(int i=0;i<n;i++) {
        int diff = a[i] - i;
        ans += cnt[diff];
        cnt[diff]++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}