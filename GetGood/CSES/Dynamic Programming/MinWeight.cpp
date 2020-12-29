#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	map<int,int> cnt;
	vector<int> a;
	while(!cin.eof()) {
		int u;
		cin >> u;
		a.push_back(u);
	}
	if((int)a.size() != n) {
		cout << "Wrong Input";
		exit(0);
	}
	sort(a.begin(), a.end());
	long long sum = 0;
	queue<int> left;
	queue<int> ch;
	for(int i=0;i<n;i++) {
		if(cnt[a[i]] > 0) {
			ch.push(a[i]);
		}
		cnt[a[i]]++;
		sum += a[i];
	}

	for(int i=1;i<=1000000;i++) {
		if(i > ch.front() and cnt[i] == 0) {
			sum += (i-ch.front());
			ch.pop();
		}
		if(ch.empty()) {
			break;
		}
	}

	cout << sum;
}