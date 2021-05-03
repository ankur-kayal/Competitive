#include <bits/stdc++.h>
using namespace std;

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
    MOD = 1e9 + 7;
    const int maxN = 3e5 + 10;
    Math<long long> m(maxN);
    vector<long long> pow2(maxN,1);
    for(int i=1;i<maxN;i++) {
        pow2[i] = m.mult(pow2[i-1],2);
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long mx = 0;
        vector<long long> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        mx = *max_element(a.begin(), a.end());
        long long cnt = 0;
        for(int i=0;i<n;i++) {
            if(a[i] == mx) {
                cnt++;
            }
        }
        // cout << cnt << '\n';
        long long ans = 0;
        if(cnt & 1) {
            ans = pow2[n];
        }
        else {
            // cerr << ans << '\n';
            long long minus = m.mult(m.nCr(cnt, cnt/2), pow2[n-cnt]);
            // long long minus = ((((m.nCr(cnt,cnt/2)))%MOD)*pow2[N-cnt]) % MOD;
            ans = m.sub(pow2[n] , minus);
        }

        cout << ans << '\n';
    }
}