#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t l, r, k;
    cin >> l >> r >> k;

    int total_elements = r - l + 1;

    if(total_elements == 1 && l != 1) {
        cout << "YES" << '\n';
        return;
    }

    if(l % 2 == 1) {
        l++;
    } 
    if(r % 2 == 1) {
        r--;
    }

    int divisible_by_2 = (r - l) / 2 + 1;

    int left = total_elements - divisible_by_2;

    cout << (left <= k ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}