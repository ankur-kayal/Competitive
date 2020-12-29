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
    	int n,k;
    	cin >> n >> k;
    	int a[n];
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	set <int> av;
    	for(int i=0;i<n;i++) {
    		if(a[i] != i+1) {
    			av.insert(i+1);
    		}
    	}
    	vector <ar<int,3>> ans;
    	int cnt = 0;
    	bool exists = true;
    	if(av.size() == 0) {
    		cout << 0 << '\n';
    		continue;
    	}
    	while(cnt < k) {
    		bool ok = 0;
    		if(av.size() == 0) {
    			break;
    		}
    		int fi = *av.begin();
    		av.erase(fi);
    		if(av.size() == 0) {
    			exists = false;
    			break;
    		}
    		int si = a[fi-1];
    		av.erase(si);
    		if(av.size() == 0) {
    			exists = false;
    			break;
    		}
    		int ti;
    		if(a[si-1] == fi) {
    			ti = *av.begin();
    			av.erase(ti);
    		}
    		else {
    			ti = a[si-1];
    			av.erase(ti);
    		}
    		swap(a[si-1],a[ti-1]);
    		swap(a[si-1],a[fi-1]);
    		ans.pb({fi,si,ti});
    		if(a[fi-1] != fi) {
    			av.insert(fi);
    		}
    		if(a[si-1] != si) {
    			av.insert(si);
    		}
    		if(a[ti-1] != ti) {
    			av.insert(ti);
    		}
    		cnt++;
    	}
    	if(exists and av.size() == 0) {
    		cout << cnt << '\n';
    		for(int i=0;i<cnt;i++) {
    			cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << '\n';
    		}
    	}
    	else {
    		cout << -1 << '\n';
    	}

    }
}