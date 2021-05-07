#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int64_t compute(vector<int64_t> &a) {
    int64_t md = a[(int)a.size() / 2];
    int64_t res = 0;
    for(auto u: a) {
        res += abs(u - md);
    }
    return res;
}

void run_cases() {
    int n;
    cin >> n;
    vector<int64_t> x;
    for(int i=0;i<n;i++) {
        char ch;
        cin >> ch;
        if(ch == '*') {
            x.push_back(i + 1);
        }
    }
    for(int i=0;i<x.size();i++) {
        x[i] -= i;
    }
    sort(x.begin(), x.end());
    if(x.empty()) {
        cout << "0\n";
        return;
    }
    cout << compute(x) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}