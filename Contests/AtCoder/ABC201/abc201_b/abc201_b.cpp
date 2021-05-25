#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    vector<pair<int, string>> a(n);
    for(int i=0;i<n;i++) {
        string s;
        int t;
        cin >> s >> t;
        a[i] = {t, s};
    }
    sort(a.rbegin(), a.rend());
    cout << a[1].second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}