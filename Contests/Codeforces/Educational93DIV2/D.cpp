#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

ll calculate(vector <multiset<int,greater<int>>>& edges) {
	ll ans = 0;
	while(true) {
    	vector <pair<int,int>> sides;
    	int ele;
    	if(edges[0].size() > 0) {
    		ele = *edges[0].begin();
    		// cout << ele << '\n';
    		sides.pb(mp(ele,0));
    	}
    	if(edges[1].size() > 0) {
    		ele = *edges[1].begin();
    		// cout << ele << '\n';
    		sides.pb(mp(ele,1));
    	}
    	if(edges[2].size() > 0) {
    		ele = *edges[2].begin();
    		// cout << ele << '\n';
    		sides.pb(mp(ele,2));
    	}
    	sort(sides.begin(),sides.end(), greater<pair<int,int>>());
    	if(sides.size() > 1) {
    		pair<int,int> side1 = sides[0];
    		pair<int,int> side2 = sides[1];
    		edges[side1.ss].erase(side1.ff);
    		edges[side2.ss].erase(side2.ff);;
    		ans += side1.ff * side2.ff;
    		// cout << ans << '\n';
    	}
    	else {
    		break;
    	}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int r,g,b;
    cin >> r >> g >> b;
    vector <multiset <int, greater<int>>> edges(3);
    for(int i=0;i<r;i++) {
    	int x;
    	cin >> x;
    	edges[0].insert(x);
    } 
    for(int i=0;i<g;i++) {
    	int x;
    	cin >> x;
    	edges[1].insert(x);
    } 
    for(int i=0;i<b;i++) {
    	int x;
    	cin >> x;
    	edges[2].insert(x);
    } 

    ll ans = 0;
    ans = max(ans, calculate(edges)); // 0 1 2
    swap(edges[1], edges[2]);
    ans = max(ans, calculate(edges)); // 0 2 1
    swap(edges[0], edges[1]);
    ans = max(ans, calculate(edges)); // 2 0 1
    swap(edges[1], edges[2]);
    ans = max(ans, calculate(edges)); // 2 1 0
    swap(edges[0], edges[1]);
    ans = max(ans, calculate(edges)); // 1 2 0
    swap(edges[1],edges[2]);
    ans = max(ans, calculate(edges)); // 1 0 2

    cout << ans << '\n';
}