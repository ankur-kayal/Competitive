#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

const int mod = 1e9 + 7;

void execTime(auto start, auto stop) {
    auto duration = duration_cast<milliseconds>(stop - start); 
  
    cout << "Time taken by function: " << duration.count() << " ms" << endl; 
}

vector <ll> ifact(500005), fact(500005), inv(500005);

ll logpow(ll x, ll y) {
    x = x % mod;
    ll res = 1;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % mod;
        }
        y >>=1;
        x = (x * x) % mod;
    }
    return res;
}


void init() {
	fact[1] = 1;
    fact[0] = 1;
	ifact[1] = 1;
    ifact[0] = 1;
    inv[1] = 1;
	for(int i=2;i<=500000;i++) {
		fact[i] = (fact[i-1] * i) % mod;
		inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
	}
    for(int i=2;i<=500000;i++) {
        ifact[i] = (ifact[i-1] * inv[i]) % mod;
    }
}



ll combination(ll n, ll r) {
	ll res = 1;
	ll num = fact[n];
    ll deno = (ifact[n-r] * ifact[r]) % mod;
    res = (num * deno) % mod;
	return res;
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif
    auto start = high_resolution_clock::now();
    init();
    auto stop = high_resolution_clock::now(); 
    // execTime(start,stop);
    // cout << duration.count() << endl; 
    int t;
    cin >> t;
    
    while(t--) {
    	int n;
    	cin >> n;
    	int a[n];
    	map <int,int> cnt;
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	vector <int> unique;
    	for(int i=0;i<n;i++) {
    		cnt[a[i]]++;
    		if(cnt[a[i]] == 1) {
    			unique.pb(a[i]);
    		}
    	}
        if(unique.size() == n) {
            for(int i=1;i<=n;i++) {
                cout << logpow(2,n-i) << " ";
            }
            cout << '\n';
            continue;
        }
    	map <int,vector<ll>> stored;
        for(auto u: unique) {
            ll freq = cnt[u];
            stored[u].resize(freq + 1);
            stored[u][0] = 0;
            for(int i=1;i<=freq;i++) {
                stored[u][i] = (stored[u][i-1] + combination(cnt[u],i)) % mod;
            }
        }
    	// for(int i=0;i<=10;i++) {
    	// 	cout << pow2[i] << " ";
    	// }
    	// cout << '\n';
        ll tot = 0;
    	for(int i=1;i<=n;i++) {
    		ll ans = 0;
    		if(cnt[i] > 0) {
    			for(int j=1;j<=cnt[i];j++) {
    				ll temp = 1;
    				for(auto u: unique) {
    					ll y;
    					if(u < i) {
    						y = min(cnt[u], j-1);
    						
    					}
    					if(u > i) {
    						y = min(cnt[u], j);
    						
    					}
    					if(u != i and y != 0) {
                            ll chosen = stored[u][y];
    						// chosen = combination(cnt[u], y);
                            // cout << u << " " << chosen << '\n';
    						temp = (temp * (1 + chosen)) % mod;
    					}
    					// cout << y << '\n';
    					
    				}
    				// cout << i << " " <<temp << " "  << temp * combination(cnt[i],j)  << " variable"<< "\n\n";
    				ans = (ans + (temp * combination(cnt[i], j))% mod) % mod;
    				// cout << ans << "\n\n";
    			}
    			cout << ans << " ";
                // cout << ans << '\n';
                tot = (tot + ans) % mod;
    		}
    		else {
    			cout << 0 << " ";
    		}
    	}
    	cout << '\n';
        // assert(tot == (mod + pow2[n] - 1) % mod);
        // cout << combination(3,3) << '\n';
    }
}