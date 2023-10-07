#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


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


void run_cases() {
	int H, W, N, h, w;
	cin >> H >> W >> N >> h >> w;

	vector<vector<int>> A(H + 1, vector<int>(W + 1));

	for(int i = 1; i <= H; i++) {
		for(int j = 1; j <= W; j++) {
			cin >> A[i][j];
		}
	}

	int unique = 0;

	vector<int> cnt(N + 1);


	for(int i = 1; i <= H; i++) {
		for(int j = 1; j <= W; j++) {
			if (cnt[A[i][j]] == 0) {
				unique++;
			}
			cnt[A[i][j]]++;
		}
	}


	for(int k = 0; k <= H - h; k++) {
		vector<int> tmp(N + 1);

		for(int l = 0; l <= W - w; l++) {
			if (l == 0) {
				for (int i = k + 1; i <= k + h; i++) {
					for(int j = l + 1; j <= l + w; j++) {
						cnt[A[i][j]]--;
						tmp[A[i][j]]++;
						if (cnt[A[i][j]] == 0) {
							unique--;
						}
					}
				}
			} 
			else {
				for(int i = k + 1; i <= k + h; i++) {
					cnt[A[i][l]]++;
					int val = A[i][l];
					tmp[A[i][l]]--;
					if (cnt[A[i][l]] == 1) {
						unique++;
					}


					cnt[A[i][l + w]]--;
					if (cnt[A[i][l + w]] == 0) {
						unique--;
					}

					tmp[A[i][l + w]]++;
				}
			}


			cout << unique << ' ';
		}

		for(int i = 1; i <= N; i++) {
			cnt[i] += tmp[i];
			if (cnt[i] == tmp[i] && cnt[i] != 0) {
				unique++;
			}
		} 
		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}