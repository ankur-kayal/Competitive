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
#define ll long long

const ll mod = 998244353;

// calculates the highest bit set after xor of two numbers
ll calc(ll a, ll b) {
	ll res = a xor b;
	ll ans = -1;
	for(ll i=0;i<32;i++) {
		if((res & (1LL<<i)) != 0) {
			ans = max(ans, i);
		}
	}

	if(ans == -1) {
		return 0;
	}

	return (1LL<<ans);
}

	
ll solve4(vector<ll>& nums) {
	ll a,b,c,d;
	a = nums[0];
	b = nums[1];
	c = nums[2];
	d = nums[3];
	ll ans = 1e18;

	ans = min(ans, calc(a, calc(b, calc(c,d)))); // a b c d
	ans = min(ans, calc(a, calc(c, calc(b,d)))); // a c b d
	ans = min(ans, calc(a, calc(d, calc(c,b)))); // a d b c
	ans = min(ans, calc(b, calc(a, calc(c,d)))); // b a c d
	ans = min(ans, calc(b, calc(c, calc(a,d)))); // b c a d
	ans = min(ans, calc(b, calc(d, calc(c,a)))); // b d a c
	ans = min(ans, calc(c, calc(a, calc(b,d)))); // c a b d
	ans = min(ans, calc(c, calc(b, calc(a,d)))); // c b a d
	ans = min(ans, calc(c, calc(d, calc(a,b)))); // c d a b
	ans = min(ans, calc(d, calc(a, calc(b,c)))); // d a b c
	ans = min(ans, calc(d, calc(b, calc(c,a)))); // d b a c
	ans = min(ans, calc(d, calc(c, calc(b,a)))); // d c b a

	return ans;
}


ll solve3(vector<ll>& nums) {
	ll a,b,c;
	a = nums[0];
	b = nums[1];
	c = nums[2];

	ll ans = 1e18;

	ans = min(ans, calc(a,calc(b,c))); // a b c
	ans = min(ans, calc(b,calc(a,c))); // b a c
	ans = min(ans, calc(c,calc(a,b))); // c a b

	return ans;
}


ll solve2(vector<ll>& nums) {
	return calc(nums[0], nums[1]);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++) {
		cin >> a[i];
	}

	ll ans = 0;

	for(ll i=0;i<n;i++) {
		vector<ll> bits(32,0);
		vector<ll> nums;
		ll maxBit = -1;
		ll sum = 0;
		for(ll j=i;j<n;j++) {
			nums.push_back(a[j]);
			ll tmp = -1;
			for(ll k=0;k<32;k++) {
				if((a[j]&(1LL<<k)) != 0) {
					tmp = k;
					bits[k]++;
				}
			}

			maxBit = max(maxBit, tmp);
			if((ll)nums.size() == 1) {
				sum += nums[0];
			}
			if(maxBit != -1 and (ll)nums.size() > 1) {
				ll cnt = bits[maxBit];

				if(cnt & 1) {
					sum += (1LL << maxBit);
				}
				else {
					if(cnt == 2) {
						if((ll)nums.size() == 2) {
							// sum = (sum +  solve2(nums))%mod;
							sum = sum +  solve2(nums);
						}
						else if((ll)nums.size() == 3) {
							// sum = (sum + solve3(nums))%mod;
							sum = sum + solve3(nums);
						}
						else {
							sum += 0LL;
						}
					}
					else if(cnt == 4) {
						if((ll)nums.size() == 4) {
							// sum = (sum + solve4(nums))%mod;
							sum = sum + solve4(nums);
						}
						else {
							sum += 0LL;
						}
					}
					else {
						sum += 0LL;
					}
				}
			}
			sum = sum % mod;
			// if(i == 3)
			// debug() << imie(i) imie(j) imie(maxBit) imie(sum) imie(nums);
		}
		// debug() << imie(i) imie(sum);
		// break;
		ans = (ans + sum) % mod;
	}

	cout << ans << '\n';
	debug() << imie(clock());

	// vector<ll> test = {4 , 5,6, 7};
	// debug() << imie(solve4(test));


}