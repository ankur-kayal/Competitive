#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int val;
    cin >> val;
    return val;
}

void run_cases() {
    int n, t;
    cin >> n >> t;
    // ( ] interval;

    int k;
    cin >> k;

    int r = n;
    int l = 0;
    while(r > l + 1) {
        int m = (r + l) / 2;
        int val = query(l + 1, m);
        int zeros = m - l - val;
        if(k <= zeros) {
            r = m;
        } else {
            k -= zeros;
            l = m;
        }
    }
    cout << "! " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}