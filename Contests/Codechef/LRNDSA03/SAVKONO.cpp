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
    	int n,z;
    	cin >> n >> z;
    	int ans = 0;
    	priority_queue <int> power;
    	for(int i=0,a;i<n;i++) {
    		cin >> a;
    		power.push(a);
    	}
    	while(!power.empty()) {
    		int e = power.top();
    		power.pop();
    		z = z - e;
    		ans++;
    		power.push(e/2);
    		if(z <= 0) {
    			break;
    		}
    	}
    	if(z <= 0) {
    		cout << ans << '\n';
    	}
    	else {
    		cout << "Evacuate" << '\n';
    	}
    }
}