#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

bool possible(vector<int> A, int target) {
    int N = A.size();
    vector<int> modified;
    for(auto u: A)
        if(u != target) {
            modified.push_back(u);
        }

    vector<int> rev = modified;

    reverse(rev.begin(), rev.end());

    return rev == modified;
}

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    for(int i = 0; i < N; i++) {
        if(A[i] != A[N - i - 1]) {
            if(possible(A, A[i]) || possible(A, A[N - i - 1])) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }

            return;
        }

    }


    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}