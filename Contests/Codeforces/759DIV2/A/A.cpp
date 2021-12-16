#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    int height = 1;

    vector<int> A(N);

    for(auto &u: A)
        cin >> u;

    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            if(i - 1 >= 0 && A[i - 1] == 1) {
                height += 5;
            }
            else {
                height += 1;
            }
        } else {
            if(i - 1 >= 0 && A[i - 1] == 0) {
                height = -1;
                break;
            }
        }
    }

    cout << height << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}