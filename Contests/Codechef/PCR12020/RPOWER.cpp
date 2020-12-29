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
    	ll ans = 1152921504606846975;
    	ll a,b,d,e;
    	cin >> a >> b >> d >> e;
    	ans = (ans ^ e) & (~(a^b^d));
    	cout << ans << '\n';
    }
}