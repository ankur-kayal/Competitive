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

    int n;
    cin >> n;
    int ds = 0;
    while(n!=0) {
    	ds = ds + (n % 10);
    	n/=10;
    }
    cout << (ds % 5 ? "NO" : "YES");
}