#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

/*
type1: ap , bp
type2: bq , aq
*/

void run_cases() {
    int64_t x, y, a, b;
    cin >> x >> y >> a >> b;

    if(x > y) swap(x, y);
    if(a > b) swap(a, b);

    if(a == b) {
        cout << min(x, y) / a << '\n';
        return;
    }

    int64_t l = 0, r = 1e9+100;
    while(r > l + 1) {
        int64_t m = (r + l) / 2;
        bool ok = false;

        int64_t xx = x -  m * a;
        int64_t yy = y -  m * a;

        int64_t diff = (b - a);

        ok = xx >= 0 && yy >= 0 && (xx / diff + yy / diff) >= m;

        if(ok) {
            l = m;
        } else {
            r = m;
        }
    }    

    cout << l << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}