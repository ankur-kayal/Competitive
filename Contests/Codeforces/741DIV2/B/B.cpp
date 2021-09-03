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


void run_cases() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<int> candidates;
    for(auto u: s) {
        candidates.push_back(u - '0');
    }

    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) {
            candidates.push_back((s[i] - '0') * 10 + (s[j] - '0'));
        }
    }

    sort(candidates.begin(), candidates.end());

    for(auto u: candidates) {
        if(!prime[u]) {
            cout << to_string(u).length() << '\n';
            cout << u << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    sieve(int(1e6));

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}