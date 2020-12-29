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

vector<int64_t> primeFactors(int64_t n) { 
    vector<int64_t> factors; 
    while (n % 2 == 0) {  
        factors.push_back(2); 
        n = n/2;  
    }    
    for (int64_t i = 3; i <= sqrtl(n); i = i + 2) {  
        while (n % i == 0)  
        {  
            factors.push_back(i);  
            n = n/i;  
        }  
    }    
    if (n > 2)  
        factors.push_back(n);  
    return factors;
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int64_t n;
        cin >> n;

        vector<int64_t> factors = primeFactors(n);
        int val = -1, count = 0, tmp = 0;
        map<int64_t,int64_t> cnt;
        for(auto u: factors) {
            cnt[u]++;
        }
        for(auto u: cnt) {
            if(u.second - 1 > count) {
                count = u.second - 1;
                val = u.first;
            }
        }
        cout << count + 1 << '\n';
        int64_t mul = 1;
        for(int i=0;i<count;i++) {
            cout << val << " ";
            mul *= val;
        }
        cout << n / mul << '\n';
    }
}