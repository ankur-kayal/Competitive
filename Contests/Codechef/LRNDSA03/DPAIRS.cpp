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

    unordered_map <int,int> c;
    int n,m;
    cin >> n >> m;
    ll a[n],b[n];
    int tot = n + m - 1;
    for(int i=0;i<n;i++) {
    	cin >> a[i];
    }
    for(int i=0;i<n;i++) {
    	cin >> b[i];
    }
    for(int i=0;i<n;i++) {
    	if(tot == 0) {
    		break;
    	}
    	for(int j=0;j<m;j++) {
    		if(tot == 0) {
    			break;
    		}
    		ll ele = a[i] + b[j];
    		if(c[ele] == 0) {
    			c[ele] = 1;
    			tot--;
    			cout << i << " " << j << '\n';
    		}
    	}
    }
}