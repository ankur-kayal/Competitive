#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array

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
    	ll n,k;
    	cin >> n >> k;
    	ll mod = n - 1;
    	if(k % mod == 0) {
    		cout << (n * (k / mod)) - 1 << '\n';
    	}
    	else {
    		cout << (n * (k / mod)) + (k % mod) << '\n';
    	}
    }
}