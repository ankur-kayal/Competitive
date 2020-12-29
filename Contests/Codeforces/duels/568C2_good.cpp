#include <bits/stdc++.h>
using namespace std;

//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;
	vector<int> t(n);
	for(int i=0;i<n;i++) {
		cin >> t[i];
	}
	debug() << imie(t);
 
	vector<int> ans(n);
	priority_queue<int> fail;
	int sum = 0;
	for(int i=0;i<n;i++) {
		sum += t[i];
		int cnt = 0;
		if(sum > m) {
			vector<int> tmp;
			while(sum > m and !fail.empty()) {
				int ele = fail.top();
				fail.pop();
				tmp.push_back(ele);
				sum -= ele;
				cnt++;
			}
			for(auto u: tmp) {
				fail.push(u);
				sum += u;
			}
		}
		fail.push(t[i]);
		ans[i] = cnt;
		debug() << imie(sum);
	}
	for(auto u: ans) {
		cout << u << " ";
	}
	cout << '\n';
}