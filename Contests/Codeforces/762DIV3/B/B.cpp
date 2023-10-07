#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

vector<int> special;

void compute() {
    const int upper = 1e9;

    for(int64_t i = 1; i * i <= upper; i++) {
        special.push_back(i * i);
    }

    for(int64_t i = 1; i * i * i <= upper; i++) {
        special.push_back(i * i * i);
    }

    sort(special.begin(), special.end());
    special.erase(unique(special.begin(), special.end()), special.end());
}

void run_cases() {
    int N;
    cin >> N;

    cout << upper_bound(special.begin(), special.end(), N) - special.begin() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    compute();

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}