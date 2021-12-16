#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

/*
00101011
*/

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        char c;
        cin >> c;
        A[i] = c - '0';
    }

    vector<vector<int>> moves;

    while(!is_sorted(A.begin(), A.end())) {
        vector<int> indices;
        
        int l = 0, r = N - 1;
        while(l < r) {
            if(A[l] != 1) {
                l++;
                continue;
            }
            if(A[r] != 0) {
                r--;
                continue;
            }
            indices.push_back(l);
            indices.push_back(r);
            l++, r--;
        }

        sort(indices.begin(), indices.end());
        for(int i = 0; i < int(indices.size()) / 2; i++) {
            swap(A[indices[i]], A[indices[indices.size() - i - 1]]);
        }
        moves.push_back(indices);
    }

    cout << moves.size() << '\n';
    for(auto &u: moves) {
        cout << u.size() << " ";
        for(auto v: u) {
            cout << v + 1 << " ";
        }
        cout << '\n';
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