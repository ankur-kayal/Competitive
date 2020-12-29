#include <bits/stdc++.h>
#include <random>
#include <stdint.h>
using namespace std;

//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

// Implementation of the Tonelli-Shanks algoritm as described at:
// https://en.wikipedia.org/wiki/Tonelli-Shanks_algorithm

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int64_t rand(int64_t a, int64_t b) {
    return a + (rng() % (b - a + 1));
}


int p;

int64_t non_quadratic_residue;

int64_t pow(int64_t x, int64_t y, int64_t p) {
    int64_t res = 1;
    x = x % p;

    while(y > 0) {

        if(y & 1) {
            res = (res * x) % p;
        }
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}

bool is_quadratic_residue(int x) {
    if(x % p == 0) {
        return true;
    }
    return pow(x, (p - 1) / 2, p) == 1;
}

// Given an odd prime p and integer n, this is an algorithm to
// find a mod-p square root of n when possible

int64_t tonelli_shanks(int64_t n) {
    // Case when p|n, so n=0(mod p). The square root of 0 is 0.
    if(n % p == 0) {
        return 0;
    }


    // So assume n is coprime to p.
    // Use Eulers criteria to see if n is a quadratic residue.

    if(!is_quadratic_residue(n)) {
        return -1;
    }

    // If p=3(mod 4) and since we know that n is a quadratic residue
    // we can get the square root right now and be done.

    if(p % 4 == 3) {
        return pow(n, (p + 1) / 4, p);
    }

    // So now p=1(mod 4) but this is not used in the algorithm.
    // Write p - 1 = (2^S)Q
    int64_t Q = p - 1;
    int64_t S = 0;

    while(Q % 2 == 0) {
        S += 1;
        Q /= 2;
    }

    // Find a quadratic non-residue of p by brute force search

    // int64_t z = rand(2, p);
    // while(is_quadratic_residue(z)) {
    //     z = rand(2, p);
    // }

    int64_t z = non_quadratic_residue;

    int64_t M = S;
    int64_t c = pow(z, Q, p);
    int64_t t = pow(n, Q, p);
    int64_t R = pow(n, (Q + 1) / 2, p);


    while(t != 1) {

        int64_t i = 0;
        int64_t tmp = t;
        while(tmp != 1) {
            i++;
            tmp = (tmp * tmp) % p;
        }

        int64_t pow2 = 1LL << (M - i - 1);
        int64_t b = pow(c, pow2, p);
        M = i;
        c = (b * b) % p;
        t = (((t * b) % p) * b) % p;
        R = (R * b) % p;
    }
    return R;
}

vector<vector<int>> adj;
vector<int64_t> c, ans, sum, vals;

// sum denotes the cumulative values of ans[i] + a[i + 1] in the subtree
// vals denotes how many roots are there
// c denotes the given c

const int mod = 998244353;
bool exists;

void dfs(int node, int par) {
    sum[node] = 0;
    for(auto child: adj[node]) {
        if(child != par) {
            dfs(child, node);
            c[node] = (c[node] + c[child]) % p;
            sum[node] = (sum[node] + sum[child]) % p;
        }
        if(!exists) {
            return;
        }
    }

    if(!exists) {
        return;
    }

    int64_t tmp = tonelli_shanks(c[node]);
    // int64_t tmp = 2;
    if(tmp == -1) {
        exists = false;
        return;
    }
    else {
        ans[node] = ((tmp - sum[node]) % p + p) % p;
        sum[node] = (sum[node] + ans[node]) % p;
        if(tmp == 0) {
            vals[node] = 1;
        }
        else {
            vals[node] = 2;
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // p = 101;
    // cout << tonelli_shanks(20) << '\n';
    // exit(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n >> p;


        adj = vector<vector<int>>(n + 1, vector<int>());
        c = vector<int64_t>(n + 1);
        ans = vector<int64_t>(n + 1);
        sum = vector<int64_t>(n + 1);
        vals = vector<int64_t>(n + 1);
        for(int i=2;i<=n;i++) {
            int pi;
            cin >> pi;
            adj[pi].push_back(i);
            adj[i].push_back(pi);
        }

        for(int i=1;i<=n;i++) {
            cin >> c[i];
        }

        exists = true;

        non_quadratic_residue = rand(2,p);
        while(is_quadratic_residue(non_quadratic_residue)) {
            non_quadratic_residue = rand(2,p);
        }

        dfs(1, -1);

        if(!exists) {
            cout << 0 << '\n';
            cout << -1 << '\n';
        }
        else {
            int64_t cnt = 1;
            for(int i=1;i<=n;i++) {
                cnt = (cnt * vals[i]) % mod;
            }

            cout << cnt << '\n';
            for(int i=1;i<=n;i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }

    }
}