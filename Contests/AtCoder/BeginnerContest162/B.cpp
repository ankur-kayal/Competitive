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

    ll ans = 0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
    	if(i % 3 ==0 or i % 5 == 0 or i % 15 == 0) {
    		continue;
    	}
    	else {
    		ans+=i;
    	}
    }
    cout << ans;
}