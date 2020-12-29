#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int ans;

void thanos(vector <int> a, int l, int r) {
	// cout << l << " " << r << '\n';
	bool ok = 1;
	if(r - l == 1) {
		return;
	}
	for(int i=l+1;i<r;i++) {
		if(a[i-1] > a[i]) {
			ok = 0;
			break;
		} 
	}
	if(ok == 1) {
		ans = max(ans,r - l);
	}
	else {
		thanos(a,l,(l + r)/2);
		thanos(a,(l + r)/2,r);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif

    int n;
    cin >> n;
    vector <int> a(n);
    ans = 1;
    for(int i=0;i<n;i++) {
    	cin >> a[i];
    }
    thanos(a,0,n);
    cout << ans << '\n';
}