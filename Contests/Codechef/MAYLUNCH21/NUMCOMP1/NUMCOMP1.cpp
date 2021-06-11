#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
 
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
 
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}
const int maxN = 1e7 + 100;
vector<int> ans(maxN, 0);

void preprocess() {
    sieve(maxN);
    ans[2] = 1;
    for(int i=3;i<maxN;i++) {
        ans[i] = ans[i-1];
        if(prime[i]) {
            ans[i]++;
        } else if(i % 2 == 0 && prime[i / 2] && i / 2 != 2) {
            ans[i]--;
        }
    }
}

void solve() {
    int N;
    cin >> N;
    cout << ans[N] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    preprocess();
    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        solve();
    }
}