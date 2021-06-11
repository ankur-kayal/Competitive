#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        int a, b, c , d, K;
        cin >> a >> b >> c >> d >> K;
        int steps = abs(a - c) + abs(d - b);
        if(steps > K) {
            cout << "NO\n";
        } else if((- steps + K) % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}