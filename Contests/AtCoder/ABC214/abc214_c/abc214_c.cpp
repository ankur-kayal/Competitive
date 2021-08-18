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

    vector<int64_t> S(N);
    for(auto &u: S)
        cin >> u;

    vector<int64_t> T(N);
    for(auto &u: T)
        cin >> u;

    vector<int64_t> A = T;

    auto get_prev = [&](int i) {
        if(i - 1 >= 0) {
            return i - 1;
        }
        return N - 1;
    };

    for(int rot = 0; rot < 10; rot++) {
        for(int i = 0; i < N; i++) {
            A[i] = min(A[i], A[get_prev(i)] + S[get_prev(i)]);
        }
    }

    for(auto u: A)
        cout << u << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}