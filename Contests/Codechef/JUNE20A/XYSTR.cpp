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
    	string s;
    	cin >> s;
    	int girl = 0, boy = 0;
    	int ans = 0;
    	for(int i=0;i<s.size();i++) {
    		if(s[i] == 'x') {
    			girl++;
    		}
    		if(s[i] == 'y') {
    			boy++;
    		}
    		if(girl > 1) girl--;
    		if(boy > 1) boy--;
    		if(girl == 1 and boy == 1) {
    			ans++;
    			girl = 0;
    			boy = 0;
    		}
    	}
    	cout << ans << '\n';
    }
}