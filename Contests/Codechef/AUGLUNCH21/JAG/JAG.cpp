#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> W(N);
    for(auto &u: W)
        cin >> u;

    vector<int64_t> vals;

    for(int i = 0; i < N; i++) {
        vals.push_back(W[i] - i);
    }

    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    if(vals.size() == 1) {
        cout << N << '\n';
    } else {
        cout << 1 << '\n';
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