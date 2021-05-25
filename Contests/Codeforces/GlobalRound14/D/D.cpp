#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> c(n);
    for(int i=0;i<n;i++) {
        cin >> c[i];
        --c[i];
    }
    vector<int> L(n), R(n);
    for(int i=0;i<n;i++) {
        if(i < l) {
            L[c[i]]++;
        } else {
            R[c[i]]++;
        }
    }
    int ans = n;
    for(int i=0;i<n;i++) {
        int x = min(L[i], R[i]);
        ans -= 2 * x;
        L[i] -= x;
        R[i] -= x;
        l -= x;
        r -= x;
    }
    int limit = abs(r - l) / 2;
    int have = 0;
    if(l < r) {
        for(int i=0;i<n;i++) {
            have += R[i] / 2;
        }
    } else {
        for(int i=0;i<n;i++) {
            have += L[i] / 2;
        }
    }
    ans -= min(have, limit);
    ans -= min(l, r);
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