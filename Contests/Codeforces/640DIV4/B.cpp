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
    	int n,k;
    	cin >> n >> k;
    	if(n % 2 == 0  and 2 * k <= n) {
    		cout << "YES" << '\n';
    		while(k != 1) {
    			cout << 2 << " ";
    			n-=2;
    			k--;
    		}
    		cout << n << '\n';
    	}
    	else if(n % 2 == 0 and k % 2 == 0 and n >= k) {
    		cout << "YES" << '\n';
    		while(k != 1) {
    			cout << 1 << " ";
    			n--;
    			k--;
    		}
    		cout << n << '\n';
    	}
    	else if(n % 2 == 0 and k == n) {
    		cout << "YES" << '\n';
    		while(k--) {
    			cout << 1 << " ";
    		}
    		cout << '\n';
    	}
    	else if(n % 2 == 1 and k % 2 == 1 and n >= k) {
    		cout << "YES" << '\n';
    		while(k != 1) {
    			cout << 1 << " ";
    			n--;
    			k--;
    		}
    		cout << n << '\n';
    	}
    	else {
    		cout << "NO" << '\n';
    	}
    }
}