#include <bits/stdc++.h>
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

void verify(vector<int64_t> &a, int64_t x, int64_t k) {
    int64_t lcm = a[0];
    int n = a.size();
    for(int i=1;i<n;i++) {
        lcm = (a[i] * lcm) / __gcd(a[i], lcm);
    }
    assert(lcm == x and n == k);
}

vector<int> primeFactors(int64_t n) {  
    set<int> factors;
    while (n % 2 == 0) {  
        factors.insert(2);
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2) { 
        if(n % i == 0) {
            factors.insert(i);
            while (n % i == 0) {  
                n = n/i;  
            } 
        }  
    }   
    if (n > 2)  
        factors.insert(n);
    vector<int> factor(factors.begin(), factors.end());  
    return factor;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // const int maxN = 2e6;
    // vector<int> prime(maxN + 10, 1);
    // prime[0] = 0;
    // prime[1] = 0;
    // for(int i=2;i*i<=maxN;i++) {
    //     if(prime[i]) {
    //         for(int j=i*i;j<=maxN;j+=i) {
    //             prime[j] = 0;
    //         }
    //     }
    // }
    // vector<int> cache;
    int t;
    cin >> t;

    while(t--) {
        int64_t k,x;
        cin >> k >> x;
        int64_t ans = 1e9;
        bool ok = false;
        bool spl = false;
        vector<int64_t> a;
        vector<int> factor = primeFactors(x);
        int mul = 1;
        int64_t ans1 = 0;
        for(auto u: factor) {
            mul *= u;
        }
        if(mul == x and (int)factor.size() <= k) {
            spl = true;
            ans1 = accumulate(factor.begin(), factor.end(), (int64_t)0);
            debug() << imie(factor) imie(ans1);
            for(int i=0;i<-(int)factor.size() + k;i++) {
                ans1++;
            }
        }
        for(int64_t i=2;i*i<=x;i++) {
            if(x % i == 0) {
                if(__gcd(i, x / i) == 1) {
                    debug() << imie(i) imie(x / i);
                    if(i + x / i < ans) {
                        ans = i + x / i;
                        a.clear();
                        a.push_back(i);
                        a.push_back(x / i);
                    }
                    ok = true;
                }
            }
        }
        debug() << imie(ans) imie(ok);
        if(ok) {
            ans += (k - 2);
            for(int i=0;i<k-2;i++) {
                a.push_back(1);
            }
        }
        else {
            ans = x + (k - 1);
            a.push_back(x);
            for(int i=0;i<k-1;i++) {
                a.push_back(1);
            }
        }
        ans = min(ans, x + k - 1);
        verify(a, x, k);
        if(spl) {
            ans = min({ans, ans1, x + (k -1)});
        }
        cout << ans << '\n';
    }
}