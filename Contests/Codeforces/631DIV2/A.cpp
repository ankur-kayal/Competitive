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
    	int n,x;
    	cin >> n >> x;
    	set <int> a;
    	int tmp;
    	for(int i=0;i<n;i++) {
    		cin >> tmp;
    		a.insert(tmp);
    	}
    	for(int i=1;i<=1000;i++) {
    		if(find(a.begin(),a.end(),i) != a.end()) {
    			continue;
    		}
    		else {
    			a.insert(i);
    			--x;
    		}
    		if(x == 0) {
    			break;
    		}
    	}
    	int v;
    	for(int i=1;i<=1000;i++) {
    		
    		if(find(a.begin(),a.end(),i) == a.end()) {
    			break;
    		}
    		v = i;
    	}
    	cout << v << '\n';
    }
}