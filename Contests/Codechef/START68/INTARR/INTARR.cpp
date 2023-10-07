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

	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &u: A)
		cin >> u;

	sort(A.begin(), A.end());
	vector<int> original = A;

	vector<int> B(N);

	for(int i = 0; i < N; i += 2) {
		B[i] = A.back();
		A.pop_back();
	}

	for(int i = 1; i < N; i += 2) {
		B[i] = A.back();
		A.pop_back();
	}

	debug() << imie(B);

	bool ok = true;

	for(int i = 2; i < N; i++) {
		vector<int> tmp = {B[i - 2], B[i - 1], B[i]};


		if (tmp[0] <= tmp[1] && tmp[1] <= tmp[2]) {
			ok = false;
		}

		if (tmp[0] >= tmp[1] && tmp[1] >= tmp[2]) {
			ok = false;
		}
	}

	if (ok) {
		for(auto u: B) {
			cout << u << " ";
		}

		cout << '\n';
		return;
	}

	A = original;

	sort(A.rbegin(), A.rend());

	B = vector<int>(N);

	for(int i = 0; i < N; i += 2) {
		B[i] = A.back();
		A.pop_back();
	}

	for(int i = 1; i < N; i += 2) {
		B[i] = A.back();
		A.pop_back();
	}

	debug() << imie(B);

	ok = true;

	for(int i = 2; i < N; i++) {
		vector<int> tmp = {B[i - 2], B[i - 1], B[i]};


		if (tmp[0] <= tmp[1] && tmp[1] <= tmp[2]) {
			ok = false;
		}

		if (tmp[0] >= tmp[1] && tmp[1] >= tmp[2]) {
			ok = false;
		}
	}

	if (ok) {
		for(auto u: B) {
			cout << u << " ";
		}

		cout << '\n';
		return;
	}


	cout << -1 << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}