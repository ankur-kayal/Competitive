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



int MOD;
template<class T> 
class Math {

public:
    vector<T> fact,invfact,inv;

    Math( int n ) {
        fact.resize(n);
        invfact.resize(n);
        inv.resize(n);
        fact[0] = inv[0] = invfact[0] = 1;
        fact[1] = inv[1] = invfact[1] = 1;
        for(int i=2;i<n;i++) {
            fact[i] = mult( i , fact[i-1] );
            inv[i] = sub( MOD, mult( MOD/i, inv[MOD%i] ) );
            invfact[i] = mult( invfact[i-1], inv[i] );
        }
    }

    T modinv( T x, T m = MOD ) {
        return expo(x,m-2,m);
    }

    T expo( T base, T exp, T m = MOD ) {
        T res = 1;
        while( exp ) {
            if( exp & 1 )
                res = mult( res, base, m );
            base = mult( base, base, m );
            exp >>= 1;
        }
        return res;
    }

    T nCr( T n, T k ) {
        if( k < 0 || k > n ) return 0;
        T ans = fact[n];
        ans = mult( ans , invfact[n-k] );
        ans = mult( ans , invfact[k] );
        return ans;
    }

    T mult( T a, T b, T m = MOD ) {
        return ( a * b ) % m;
    }

    T add( T a, T b, T m=MOD ) {
        return ( a + b ) % m;
    }

    T sub( T a, T b, T m=MOD ) {
        return ( a - b + m ) % m;
    }

    T divide( T a, T b, T m=MOD ) {
        return ( a * modinv( b,m ) ) % m;
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    MOD = 998244353;

    const int maxN = 1e5;
    Math<long long> m(maxN);

    long long ans = m.mult(20, m.modinv(36));
    cout << ans << '\n';
}