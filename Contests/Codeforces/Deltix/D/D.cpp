#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

void run_cases() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<int64_t> A(N);

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int64_t mask = 0;
        for(int j = 0; j < M; j++) {
            if(s[j] == '1')
                mask |= (1LL << j);
        }
        A[i] = mask;
    }

    int64_t best_answer = 0;

    for(int iterations = 0; iterations < 10; iterations++) {
        int position = uid(0, N - 1);
        vector<int> bits;
        for(int bit = 0; bit < M; bit++) {
            if(A[position] & (1LL << bit)) {
                bits.push_back(bit);
            }
        }

        int set_bits = bits.size();
        vector<int> cnt(1 << set_bits);
        for(int i = 0; i < N; i++) {
            int mask = 0;
            for(int bit = 0; bit < set_bits; bit++) {
                if(A[i] & (1LL << bits[bit])) {
                    mask |= (1 << bit);
                }
            }
            cnt[mask]++;
        }


        // Do SOS dp 3^n complexity
        // for(int mask = 0; mask < (1 << set_bits); mask++) {
        //     for(int submask = mask; submask > 0; submask = (submask - 1) & mask) {
        //         if(submask != mask)
        //             cnt[submask] += cnt[mask];
        //     }
        // }

        // Do SOS dp, faster n*2^n complexity
        for(int bit = 0; bit < set_bits; bit++) {
            for(int mask = 0; mask < (1 << set_bits); mask++) {
                if(mask & (1 << bit)) {
                    cnt[mask ^ (1 << bit)] += cnt[mask];
                }
            }
        }

        int64_t current_answer = 0;
        // Validate the best answer in this iteration
        for(int mask = 0; mask < (1 << set_bits); mask++) {
            if(cnt[mask] * 2 >= N && __builtin_popcount(mask) > __builtin_popcountll(current_answer)) {
                current_answer = mask;
            }
        }



        if(__builtin_popcountll(current_answer) > __builtin_popcountll(best_answer)) {
            best_answer = 0;
            for(int bit = 0; bit < set_bits; bit++) {
                if(current_answer & (1 << bit))
                    best_answer |= (1LL << bits[bit]);
            }
        }
    }

    for(int bit = 0; bit < M; bit++) {
        cout << ((best_answer & (1LL << bit)) ? "1" : "0");
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