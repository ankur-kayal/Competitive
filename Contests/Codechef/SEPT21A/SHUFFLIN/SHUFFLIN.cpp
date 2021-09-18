#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    int odd = N, even = 0;

    vector<int> A(N);
    for(auto &u: A) {
        cin >> u;
        if(u % 2 == 0) {
            odd--;
            even++;
        }
    }

    int iodd = (N + 1) / 2;
    int ieven = N / 2;

    cout << (min(iodd, even) + min(ieven, odd)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}