#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

vector<vector<int>> bits;

const int maxL = 2e5+10;

void precompute() {
    bits = vector<vector<int>>(maxL, vector<int>(31, 0));

    for(int i = 1; i < maxL; i++) {
        bits[i] = bits[i - 1];
        for(int bit = 0; bit < 31; bit++) {
            if(i >> bit & 1) {
                bits[i][bit]++;
            }
        }
    }
}

void run_cases() {
    int l, r;
    cin >> l >> r;

    int maxSet = 0;

    for(int bit = 0; bit < 31; bit++) {
        maxSet = max(maxSet, bits[r][bit] - bits[l - 1][bit]);
    }

    cout << (r - l + 1 - maxSet) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    precompute();

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}