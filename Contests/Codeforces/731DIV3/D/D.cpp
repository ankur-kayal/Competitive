#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void run_cases() {
    int N;
    cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    Y[0] = 0;

    for(auto &u: X)
        cin >> u;

    int req = X[0] ^ Y[0];
    for(int i = 1; i < N; i++) {
        int have = X[i];
        for(int bit = 0; bit < 31; bit++) {
            if((have & (1 << bit)) == 0 && (req & (1 << bit)) != 0) {
                Y[i] += (1 << bit);
            } 
        }
        req = X[i] ^ Y[i];

    }

    output_vector(Y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}