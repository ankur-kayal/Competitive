#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	/*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif*/

    ll n,k;
    cin >> n >> k;
    ll a1 = n % k;
    ll a2 = k - a1;
    if(a1 > a2) {
    	cout << a2;
    }
    else {
    	cout << a1;
    }
}