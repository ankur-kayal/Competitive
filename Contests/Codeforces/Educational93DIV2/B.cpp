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
    	vector <int> a;
    	int l = s.length();
    	int score = 0;
    	for(int i=0;i<l;i++) {
    		if(s[i] == '1') {
    			score++;
    		}
    		else {
    			a.pb(score);
    			score = 0;
    		}
    	}
    	a.pb(score);
    	int ans = 0;
    	sort(a.begin(), a.end(), greater<int>());
    	for(int i=0;i<a.size();i+=2) {
    		ans+=a[i];
    	}
    	cout << ans << '\n';
    }
}