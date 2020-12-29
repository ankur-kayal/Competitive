#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

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
    	if(n < 31) {
    		cout << "NO" << '\n';
    	}
    	else {
    		cout << "YES" << '\n';
    		int rem1 = n - 30;
    		int rem2 = n - 31;
    		if(rem1 != 6 and rem1 != 10 and rem1 != 14) {
    			cout << "6 10 14 " << rem1 << '\n';
    		}
    		else if(rem2 != 6 and rem2 != 10 and rem2 != 15) {
    			cout << "6 10 15 " << rem2 << '\n';
    		}
    	}
    }
}