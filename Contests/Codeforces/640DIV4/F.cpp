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
    	ar<string,2> ty= {"10","01"};
    	int n0,n1,n2;
    	cin >> n0 >> n1 >> n2;
    	vector <string> ans;
    	for(int i=0;i<n2;i++) {
    		ans.pb("11");
    	}
    	if(n1 > 0)
    	ans.pb("10");
    	n1--;
    	int ind = 1;
    	int i;
    	for(i=0;i<n0;i++) {
    		ans.pb("00");
    	}
    	for(i=0;i<n1;i++) {
    		ans.pb(ty[ind]);
    		ind^=1;
    	}
    	for(i=0;i<ans.size()-1;i++) {
    		cout << ans[i][0];
    	}
    	cout << ans[i] << '\n';
    }
}