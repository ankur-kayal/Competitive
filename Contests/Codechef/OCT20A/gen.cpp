#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxVal = 1073741824;

ll rand(ll a, ll b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	int n = rand(1,2000);

	cout << n << '\n';
	vector<ll> values;
	for(int i=0;i<n;i++) {
		ll x = rand(0,maxVal);
		values.push_back(x);
	}
	for(auto u: values) {
		cout << u << " ";
	}
	cout << '\n';
}