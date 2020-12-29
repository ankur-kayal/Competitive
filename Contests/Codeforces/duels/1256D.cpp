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

	int t;
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		set<int> ones;
		set<int> zeros;
		for(int i=0;i<n;i++) {
			if(s[i] == '0') {
				zeros.insert(i);
			}
			else {
				ones.insert(i);
			}
		}
		vector<int> ans(n,1);
		while(k > 0) {
			if(ones.size() == 0) {
				break;
			}
			if(zeros.size() == 0) {
				break;
			}
			int ele = zeros.back();
			int target = ones.back();
			if(target > ele) {
				zeros.pop_back();
				ans[ele] = 0;
				marker = ele;
			}
			else {
				int d = ele - target;
				if(d <= k) {
					k-=d;
					ans[target] = 0;
					ones.pop_back();
				}
			}
		}
		for(auto u: ans) {
			cout << u << " ";
		}
		cout << '\n';
	}
}