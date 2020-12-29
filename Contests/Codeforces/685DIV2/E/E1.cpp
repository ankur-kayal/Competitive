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

int AND(int i, int j) {
	cout << "AND " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int OR(int i, int j) {
	cout << "OR " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int XOR(int i, int j) {
	cout << "XOR " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int findSum(int X, int R) {
	int ans = 0;
	for(int i=0;i<=16;i++) {
		if((R & (1 << i)) != 0) {
			ans += 1 << i;
			if((X & (1 << i)) == 0) {
				ans += 1 << i;
			}
		}
	}
	return ans;
}

pair<int,int> findFirstTwo(int X, int A) {
	int a = 0;
	int b = 0;
	for(int i=0;i<=16;i++) {
		int Xi = (X & (1 << i));
		int Ai = (A & (1 << i));
		if(Xi == 0 and Ai == 0) {
			// nothing to do;
		}
		else if (Xi == 0 && Ai > 0) { 
            a = ((1 << i) | a);  
            b = ((1 << i) | b);  
        } 
        else if (Xi > 0 && Ai == 0) { 
            a = ((1 << i) | a);  
        } 
	}
	return make_pair(a,b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	
	int X12 = XOR(1, 2);
	int X23 = XOR(2, 3);
	int X13 = X12 ^ X23;
	int A12 = AND(1, 2);
	int A23 = AND(2, 3);
	int A13 = AND(1, 3);

	int p = X12 + 2 * A12;
	int q = X23 + 2 * A23;
	int r = X13 + 2 * A13;
	debug() << imie(p) imie(q) imie(r);

	a[1] = (p - q + r) / 2;
	a[3] = r - a[1];
	a[2] = q - a[3];

	// all correct after this
	for(int i=4;i<=n;i++) {
		int X = XOR(1 , i);
		a[i] = X ^ a[1];
	}
	cout << "! ";
	for(int i=1;i<=n;i++) {
		// assert(a[i] <= n -1);
		cout << a[i] << " ";
	}
}