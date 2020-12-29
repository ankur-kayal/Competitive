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
    	string s,p,ans="";
    	cin >> s >> p;
    	vector <int> cz(26);
    	for(int i=0;i<s.length();i++) {
    		cz[s[i] - 'a']++;
    	}
    	for(int i=0;i<p.length();i++) {
    		cz[p[i]-'a']--;
    	}
    	for(int i=0;i<26;i++) {
    		if(cz[i] > 0) {
    			for(int j=0;j<cz[i];j++)
    			ans+=(char)('a' + i);
    		}
    	}
    	ans+=(char)('z' + 1);
    	int index = 0;
    	for(int i=0;i<ans.length();i++) {
    		index = i;
    		if(ans[i] > p[0]) {
    			break;
    		}
    	}
    	ans.pop_back();
    	cout << ans.substr(0,index) << p << ans.substr(index) << '\n';
    }
}