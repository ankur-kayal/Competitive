#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxVal = 1e9;

ll rand(ll a, ll b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));
	cout << 1 << '\n';
	const int maxN = 1e5;
	int n = rand(1,10);

	cout << n << '\n';
	set<ll> values;
	while((int)values.size() != n - 1) {
		ll x = rand(1,maxVal);
		values.insert(x);
	}
	values.insert(1);
	vector<int> arr(values.begin(), values.end());
	random_shuffle(arr.begin(), arr.end());
	for(auto u: arr) {
		cout << u << " ";
	}
	cout << '\n';
	const ll maxR = 1e12;
	const int maxQ = 1e5;
	int q = rand(1, 35);
	cout << q << '\n';
	while(q--) {
		ll r = rand(1, 35);
		cout << r << '\n';
	}
}