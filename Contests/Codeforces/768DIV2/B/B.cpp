#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    int target = A.back();

    int moves = 0;
    int index = N - 2;

    while(index >= 0) {
        if(A[index] != target) {
            int after = N - index;
            moves++;
            index -= after;
            index++;
        } else {
            index--;
        }
    }

    cout << moves << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}