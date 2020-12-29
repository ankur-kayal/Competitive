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

    map <int,int> count;
    ll n;
    cin >> n;
    for(ll i=2;i*i<=n;i++) {
    	cout << i  << " " << i*i << " " << n/(i*i) << '\n'; 
    	count[n/(i*i)]++;
    }
    cout << "frequency" << '\n';
    for(auto u: count) {
    	cout << u.first << " " << u.second << '\n';
    }
}