#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

const int N = 5;

const int mod = 1e9 + 7;

ll a[N][N], b[1][N], c[N][N], res[N][N];

void multiply_self() {

	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			res[i][j] = 0;
			for(int k=0;k<N;k++) {
				res[i][j] = (res[i][j] +  a[i][k] * a[k][j])%mod;
			}
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			a[i][j] = res[i][j];
		}
	}
}

void multiply() {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			res[i][j] = 0;
			for(int k=0;k<N;k++) {
				res[i][j] = (res[i][j] +  a[i][k] * c[k][j])%mod;
			}
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			c[i][j] = res[i][j];
		}
	}
}

void matpow(ll y) {
    while (y > 0) {
        if (y & 1)
            multiply();
        y >>=1;
        multiply_self();
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int t;
    cin >> t;
    while(t--) {
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<N;j++) {
    			c[i][j] = 0;
    			a[i][j] = 0;
    			res[i][j] = 0;
    		}
    	}

    	ll n, aa, bb, cc, dd, ee;
        cin >> aa >> bb >> cc >> dd >> ee >> n;
        aa = aa % mod;
        bb = bb% mod;
        cc = cc % mod;
        dd = dd % mod;
        ee = ee % mod;

        a[0][0] = aa;
        a[0][1] = bb;
        a[0][2] = cc;
        a[0][3] = dd;
        a[0][4] = 1;

        a[1][0] = 1;
        a[2][1] = 1;
        a[3][2] = 1;
        a[4][4] = 1;

        c[0][0] = 1;
        c[1][1] = 1;
        c[2][2] = 1;
        c[3][3] = 1;
        c[4][4] = 1;

        matpow(n-4);

        ll ans = 0;

        ll arr[5];
        arr[0] = 3;
        arr[1] = 2;
        arr[2] = 1;
        arr[3] = 0;
        arr[4] = ee;

        for (ll i = 0; i < N; i++)
        {
            ans = (ans + c[0][i] * arr[i]) % mod;
        }
        cout << ans<<"\n";
    }
}