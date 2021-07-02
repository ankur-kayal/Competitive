#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t N;
    cin >> N;
    if(N == 1) {
        cout << "Bob\n";
        return;
    }

    bool ok = true;

    if(N & 1) {
        ok = false;
    }

    if((N & (N - 1)) == 0) {
        int times = 0;
        while(N != 1) {
            N /= 2;
            times++;
        }
        if(times & 1) {
            ok = false;
        }
    }

    cout << (ok ? "Alice" : "Bob") << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}