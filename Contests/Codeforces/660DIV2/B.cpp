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
    	if(n == 1) {
    		cout << 8 << '\n';
    		continue;
    	}
    	int count8 = ceil((double)n / 4);
    	for(int i=0;i<n-count8;i++) {
    		cout << 9;
    	}
    	for(int i=0;i<count8;i++) {
    		cout << 8;
    	}
    	cout << '\n';

    }
}	