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

    pair<int,int> tes;
    int a,b;
    cin >> a >> b;
    tes={a,b};
    if(tes == {0,0}) {
    	cout << "OMG" << '\n';
    }
    else {
    	cout << "Knew It!" << '\n';
    }
}