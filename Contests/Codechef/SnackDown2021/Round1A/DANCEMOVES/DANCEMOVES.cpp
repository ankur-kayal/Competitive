#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int X, Y;
    cin >> X >> Y;

    int ans;

    if(X < Y)  {
        int diff = Y - X;
        ans = (diff + 1) / 2 + (diff & 1);
    } else {
        int diff = X - Y;
        ans = diff; 
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