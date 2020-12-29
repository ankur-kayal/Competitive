#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

void solve() {
	

	int a[n]; // contains all the input numbers
	map <int,int> cnt;
	for(int i=0;i<n;i++) {
		cnt[a[i]]++; //  counting the frequency of all numbers
	}

	target = d;
	map <pair<int,int>, bool> exists; // keeps  track which pair has been taken into account ans {4,5} == {5,4}
	ll ans = 0;
	for(int i=0;i<n;i++) {
		int comp = target - a[i];
		if(cnt[comp] > 0) {
			int x = a[i];
			int y = comp;
			if(x > y) {
				swap(x,y);
			}
			if(exists[mp(x,y)] == false) {
				exists[mp(x,y)] = true;
				ans++;
			}
		}
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

	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}