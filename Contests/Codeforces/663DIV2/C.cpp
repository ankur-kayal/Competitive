#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    ll n;
    cin >> n;
    ll f = 1, p = 1;
    for(int i=2;i<=n;i++) {
    	f = (f * i) % mod;
    	p = (p * 2) % mod;
    }
    cout << (f - p + mod) % mod << '\n';
}