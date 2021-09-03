#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int k;
    cin >> k;
    for(int i = 1; i < 1000000; i++) {
        if(i % 10 == 3) {
            continue;
        }
        int sum = 0;
        int s = i;
        while(s > 0) {
            sum += s%10;
            s /= 10;
        }
        if(sum % 3 == 0) {
            continue;
        }
        k--;
        if(k == 0) {
            cout << i << '\n';
            return;
        }
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