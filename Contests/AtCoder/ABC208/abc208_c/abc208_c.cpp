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
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;
    vector<array<int64_t, 2>> order;
    for(int i = 0; i < N; i++) {
        order.push_back({A[i], i});
    }

    sort(order.begin(), order.end());


    int64_t base = (K / N);
    vector<int64_t> sweets(N, base);

    for(int i = 0; i < K % N; i++) {
        sweets[order[i][1]]++;
    }

    for(auto u: sweets) {
        cout << u << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}