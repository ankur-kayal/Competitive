#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t a, b, c, m;
    cin >> a >> b >> c >> m;

    vector<int64_t> o = {a, b, c};
    sort(o.begin(), o.end());

    int64_t low = o[2] - (o[0] + o[1] + 1);

    int64_t high = a + b + c - 3;

    if(low <= m && m <= high) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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