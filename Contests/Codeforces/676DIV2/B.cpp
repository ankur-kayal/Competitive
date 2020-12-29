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
		int n;
		cin >> n;
		char grid[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cin >> grid[i][j];
			}
		}

		vector<pair<int,int>> pts;

		int a = grid[0][1] - '0';
		int b = grid[1][0] - '0';
		int c = grid[n-1][n-2] - '0';
		int d = grid[n-2][n-1] - '0';

		int cnt1 = 0, cnt2 = 0;
		if(a == 0) {
			cnt1++;
		}
		if(b == 0) {
			cnt1++;
		}
		if(c == 0) {
			cnt2++;
		}
		if(d == 0) {
			cnt2++;
		}

		if(cnt1 == cnt2) {
			// cnt1 = 0;
			if(cnt1 == 0) {
				pts.emplace_back(1,2);
				pts.emplace_back(2,1);
			}
			else if(cnt1 == 1) {
				// a == 0 b == 0 c == 1 d == 1
				if(a != 0) {
					pts.emplace_back(1,2);
				}
				else if(b != 0) {
					pts.emplace_back(2,1);
				}
				if(c != 1) {
					pts.emplace_back(n,n-1);
				}
				else if(d != 1) {
					pts.emplace_back(n-1,n);
				}
			}
			else {
				pts.emplace_back(1,2);
				pts.emplace_back(2,1);
			}
		}
		else if(cnt2 > cnt1) {
			// c == 0 d == 0
			if(cnt2 == 2) {
				if(a != 1) {
					pts.emplace_back(1,2);
				}
				else if(b != 1) {
					pts.emplace_back(2,1);
				}
			}
			else {
				if(c != 0) {
					pts.emplace_back(n,n-1);
				}
				else if(d != 0) {
					pts.emplace_back(n-1,n);
				}
			}
			
		}
		else if(cnt1 > cnt2) {
			// a == 0 b== 0
			if(cnt1 == 1) {
				if(a != 0) {
					pts.emplace_back(1,2);
				}
				else if(b != 0) {
					pts.emplace_back(2,1);
				}
			}
			else {
				if(c != 1) {
					pts.emplace_back(n,n-1);
				}
				else if(d != 1) {
					pts.emplace_back(n-1,n);
				}
			}
		}
		cout << pts.size() << '\n';
		for(auto u: pts) {
			cout << u.first << " " << u.second << '\n';
		}
	}
}