#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

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
    	int X;
    	cin >> X;
    	int n;
    	cin >> n;
    	vector <int> pass(n);
    	// unordered_map <int,int> count;
    	for(int i=0;i<n;i++) {
    		cin >> pass[i];
    		// count[pass[i]]++;
    	}
    	int m;
    	cin >> m;
    	// unordered_map <int,int> exists;
    	vector <int> poss(m);
    	for(int i=0;i<m;i++) {
    		int temp;
    		cin >> temp;
    		poss[i] = temp;
    		// exists[temp]++;
    	}
    	int ans = 0;
    	int add = 0;
    	for(int i=add;add + n < m and i<add+n;i++) {
    		bool ok = 1;
    		// int diff = poss[i] - pass[0];
    		// if(abs(diff) > X) {
    		// 	add++;
    		// 	continue;
    		// }
    		for(int j=0;j<n;j++){
    			if(abs(poss[i+j] - pass[j]) > X) {
    				ok = 0;
    				break;
    			}
    		}
    		if(ok) {
    			ans++;
    		}
    		add++;
    	}
    	cout << ans << '\n';
    }
}