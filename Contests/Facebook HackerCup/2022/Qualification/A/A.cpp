#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<int> S(N);
    for(auto &u: S)
        cin >> u;

    map<int,int> cnt;
    for(auto u: S) {
        cnt[u]++;
    }

    if(N > 2 * K) {
        cout << "NO" << '\n';
        return;
    }

    for(auto [value, count]: cnt) {
        if(count > 2) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("a1_validation_input.txt", "r", stdin);
    // freopen("a1_validation_output.txt", "w", stdout);

    /*For final submit*/
    freopen("a1_final_input.txt", "r", stdin);
    freopen("a1_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}