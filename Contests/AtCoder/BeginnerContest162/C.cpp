#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	/*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif*/

    int k;
    cin >> k;
    ll ans = 0;
    for(int i=1;i<=k;i++) {
    	for(int j=1;j<=k;j++) {
    		for(int l=1;l<=k;l++) {
    			ans = ans + __gcd(i,__gcd(j,l));
    		}
    	}
    }
    cout << ans;
}