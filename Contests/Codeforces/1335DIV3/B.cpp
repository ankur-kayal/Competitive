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
    	int n,a,b;
    	cin >> n >> a >> b;
    	string ans = "";
    	for(int i=0;i<b;i++) {
    		ans+=char('a' + i);
    	}
    	int mul = n / b + 1;
    	string tmp = "";
    	for(int i=0;i<mul;i++) {
    		tmp+=ans;
    	}
    	for(int i=0;i<n;i++) {
    		cout << tmp[i];
    	}
    	cout << '\n';
    }
}