#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int pts = n * a;
    if(b > 0) {
        pts += n * b;
    } else {
        int block1 = 0, block0 = 0;
        int cnt1 = 0, cnt0 = 0;
        for(auto u: s) {
            if(u == '1') {
                cnt1++;
                if(cnt0 > 0) {
                    block0++;
                }
                cnt0 = 0;
            } else {
                cnt0++;
                if(cnt1 > 0) {
                    block1++;
                }
                cnt1 = 0;
            }
        }
        if(cnt0 > 0) {
            block0++;
        }
        if(cnt1 > 0) {
            block1++;
        }
        pts += (min(block1, block0) + 1) * b;
    }
    cout << pts << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}