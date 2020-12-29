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
    	int x,k;
    	cin >> x >> k;
    	int pf = 0;
    	int tmp = x;
    	for(int i=2;i*i<=tmp;i++) {
    		if(x % i == 0) {
    			while(x % i == 0) {
    				pf++;
    				x/=i;
    			}
    		}
    	}
    	if(x > 2) pf++;
    	cout << (k <= pf ) << '\n';
    }
}