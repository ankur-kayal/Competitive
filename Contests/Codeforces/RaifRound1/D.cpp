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

	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	vector<pair<int,int>> ans;
	vector<int> rest, one,h(n+1);
	int rcnt = n;
	for(int i=n;i>=1;i--) {
		int pair = -1;
		if(a[i] == 2) {
			if((int)one.size() > 0) {
				pair = one.back();
				one.pop_back();
			}
			else {
				cout << -1 << '\n';
				exit(0);
			}
		}
		else if(a[i] == 3) {
			if((int)rest.size() > 0) {
				pair = rest.back();
				rest.pop_back();
			}
			else if((int)one.size() > 0) {
				pair = one.back();
				one.pop_back();
			}
			else {
				cout << -1 << '\n';
				exit(0);
			}
		}
		if(a[i] == 1) {
			one.push_back(i);
			h[i] = rcnt;
			rcnt--;
			ans.emplace_back(h[i], i);
		}
		else if(a[i] == 2) {
			rest.push_back(i);
			h[i] = h[pair];
			ans.emplace_back(h[i],i);
		}
		else if(a[i] == 3) {
			rest.push_back(i);
			h[i] = rcnt;
			rcnt--;
			ans.emplace_back(h[i], i);
			ans.emplace_back(h[i], pair);
		}

	}
	cout << ans.size() << '\n';
	for(auto u: ans) {
		cout << u.first << " " << u.second << '\n';
	}

}