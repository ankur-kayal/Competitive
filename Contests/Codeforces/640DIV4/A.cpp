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
    	int n;
    	cin >> n;
    	vector <int> ans;
    	int mul = 1;
    	while(n != 0) {
    		int rem = n % 10;
    		if(rem != 0) {
    			ans.pb(mul*rem);
    		}
    		mul*=10;
    		n /= 10;
    	}
    	cout << ans.size() << '\n';
    	for(auto u: ans) {
    		cout << u << " ";
    	}
    	cout << '\n';
    }
}