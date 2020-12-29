#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<float> a;
	while(!cin.eof()) {
		float tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.rbegin(), a.rend());
	int cnt = 0;
	float maxD = 42.195;
	for(auto u: a) {
		if(u < maxD) {
			cnt++;
			cout << u << " ";
		}
		if(cnt == 3) {
			break;
		}
	}
}