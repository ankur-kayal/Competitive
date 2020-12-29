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
    	string s;
    	cin >> s;
    	int num = 1;
    	vector <int> ans(n);
    	queue <int> q[2];
    	for(int i=0;i<n;i++) {
    		int d = s[i] - '0';
    		if(!q[1-d].empty()) {
    			ans[i] = q[1-d].front();
    			q[d].push(ans[i]);
    			q[1-d].pop();
    		}
    		else {
    			q[d].push(num);
    			ans[i] = num;
    			num++;
    		}
    	}
    	cout << num - 1 << '\n';
    	for(auto u : ans) {
    		cout << u << " ";
    	}
    	cout << '\n';
    }
}