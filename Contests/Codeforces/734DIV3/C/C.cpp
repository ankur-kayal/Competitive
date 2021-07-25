#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<string> words(N);
    for(auto &u: words) {
        cin >> u;
    }

    int ans = 0;

    for(char c = 'a'; c <= 'e'; c++) {
        // brute force considering that c is the majority character
        vector<int> val(N);
        for(int i = 0; i < N; i++) {
            int cnt = count(words[i].begin(), words[i].end(), c);
            int other = words[i].size() - cnt;
            val[i] = cnt - other;
        }
        sort(val.rbegin(), val.rend());
        int current_sum = 0;
        int used = 0;
        for(auto u: val) {
            current_sum += u;
            if(current_sum <= 0) {
                break;
            }
            used++;
        }
        ans = max(ans, used);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}