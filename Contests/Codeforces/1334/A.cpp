#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

struct stats {
	int p,c,id;
};

bool comp(stats a, stats b) {
	return (a.p == b.p) ? (a.c < b.c) : (a.p < b.p);
}

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
    	int prev_p,prev_c;
    	cin >> prev_p >> prev_c;
    	bool ok = 1;
    	int p,c;
    	int d;
    	for(int i=1;i<n;i++) {
    		cin >> p >> c;
    		if(prev_p == p and prev_c == c) {
    			d = 0;
    		}
    		else if(prev_p < p and prev_c <= c) {
    			d = 0;
    		}
    		else {
    			ok = 0;
    		}
    		prev_p = p;
    		prev_c = c;
    	}
    	
    	cout << (ok ? "YES" : "NO") << '\n';
    }
}