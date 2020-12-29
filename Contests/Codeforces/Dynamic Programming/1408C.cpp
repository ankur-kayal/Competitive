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

#define ld long double

bool good(vector<ld> &a, ld len, ld m) {
	ld car1 = 0, car2 = len, time1 = m, time2 = m, speed1 = 1, speed2 = 1;
	int n = a.size() - 2;

	// calculating coordinate of car1 after time m
	ld prev = 0;
	for(int i=1;i<=n+1;i++) {
		{
			ld distance = a[i] - a[i-1];
			ld timeTaken = distance / speed1;
			if(timeTaken <= time1) {
				car1 += distance;
				time1 -= timeTaken;
			}
			else {
				car1 += speed1 * time1;
				time1 = 0;
			}
			if(time1 == 0) {
				break;
			}
			prev = a[i];
			speed1++;
		}
	}

	// calculating coordinate of car2 after time m
	prev = len;
	for(int i=n;i>=0;i--) {
		ld distance = a[i+1] - a[i];
		ld timeTaken = distance / speed2;
		if(timeTaken <= time2) {
			car2 -= distance;
			time2 -= timeTaken;
		}
		else {
			car2 -= speed2 * time2;
			time2 = 0;
		}
		if(time2 == 0) {
			break;
		}
		prev = a[i];
		speed2++;
	}

	return car1 <= car2;

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout << setprecision(20) << fixed;
	int t;
	cin >> t;
	while(t--) {
		int n;
		ld len;
		cin >> n >> len;
		vector<ld> a(n+2);
		for(int i=1;i<=n;i++) {
			cin >> a[i];
		}
		a[0] = 0;
		a[n+1] = len;
		ld l = 0;
		ld r = 1e9;

		for(int i=0;i<40;i++) {
			ld m = l + (r - l) / 2;
			if(good(a,len,m)) {
				l = m;
			}
			else {
				r = m;
			}
		}
		cout << l << '\n';
	}
}