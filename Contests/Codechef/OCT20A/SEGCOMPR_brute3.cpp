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

ll countHBit(ll a) {
	ll ans = -1;
	for(ll i=0;i<32;i++) {
		if((a & (1LL<<i)) != 0) {
			ans = max(ans, i);
		}
	}

	return ans;
}

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
		return 0LL;
	}

	return (1LL<<ans) % mod;
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

	vector<ll> hbit(n);
	vector<ll> store(32,0);
	for(ll i=0;i<n;i++) {
		hbit[i] = countHBit(a[i]);
		store[hbit[i]]++;
	}

	debug() << imie(store);

	// debug() << imie(a);
	// debug() << imie(hbit);
	vector<ll> sufsum(n+1,0);
	vector<list<ll>> pos(32);
	for(ll i=0;i<32;i++) {
		pos[i].push_front(n);
	}

	// sumehow calculate the suffix sum
	for(ll i=n-1;i>=0;i--) {
		ll ele = hbit[i];
		if(ele != -1) {
			ll nextHigh = n;
			ll nextpos = n;
			for(ll j=0;j<32;j++) {
				if(j == ele) {
					nextpos = min(nextpos, *pos[j].begin());
				}
				if(j > ele) {
					nextHigh = min(nextHigh, *pos[j].begin());
				}
			}
			// Case 1: nextHigh < nextpos
			if(nextHigh <= nextpos) {
				// sufsum[i] = sufsum[nextHigh] + (nextHigh - i) * (1LL<<ele);
				sufsum[i] = (sufsum[nextHigh] + ((nextHigh - i) * (1LL<<ele))%mod)%mod;
			}
			// Case 2: nextpos < nextHigh ?? critical case
			else if(nextpos < nextHigh) {
				assert((ll)pos[ele].size() > 1);
				ll nextnextpos = *next(pos[ele].begin());
				if(nextnextpos < nextHigh) {
					sufsum[i] = (sufsum[nextnextpos] + ((nextpos - i) * (1LL<<ele))%mod)%mod;
					// sufsum[i] = sufsum[nextnextpos] + (nextpos - i) * (1LL<<ele);
				}
				else {
					sufsum[i] = (sufsum[nextHigh] + ((nextpos - i) * (1LL<<ele))%mod)%mod;
					// sufsum[i] = sufsum[nextHigh] + (nextpos - i) * (1LL<<ele);
				}
			}
			pos[ele].push_front(i);
		}
		else if(i+1 < n){
			sufsum[i] = sufsum[i+1];
		}
		assert(sufsum[i] >= 0);
		
	}

	// debug() << imie(sufsum);

	// for(ll i=0;i<32;i++) {
	// 	debug() << imie(pos[i]);
	// }


	ll ans = 0;

	for(ll i=0;i<n;i++) {
		ll last = min((ll)(i+6),n);
		// ll next = min((ll)(i+6),n);

		vector<ll> bits(32,0);
		vector<ll> nums;
		ll maxBit = -1;
		ll sum = 0;
		ll cnt = 0;
		for(ll j=i;j<last;j++) {
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
				sum = (sum + nums[0])%mod;
				// sum = sum + nums[0];
			}
			if(maxBit != -1 and (ll)nums.size() > 1) {
				cnt = bits[maxBit];

				if(cnt & 1) {
					sum =(sum + (1LL << maxBit))%mod;
					// sum = sum + (1LL << maxBit);
				}
				else {
					if(nums.size() < 5) {
						if((int)nums.size() == 2) {
							sum += solve2(nums);
							// tmp1 = solve2(nums);
						}
						if((int)nums.size() == 3) {
							sum += solve3(nums);
							// tmp1 = solve3(nums);
						}
						if((int)nums.size() == 4) {
							if(cnt != 2)
							sum += solve4(nums);
							// tmp1 = solve4(nums);
						}
					}
					sum = sum % mod;
				}
			}
		}

		// calculating useless value
		ll useless = 0;
		maxBit = -1;
		cnt = 0;
		for(ll j=i;j<last;j++) {
			if(hbit[j] > maxBit) {
				cnt = 1;
				maxBit = hbit[j];
			}
			else if(hbit[j] == maxBit) {
				cnt++;
			}
			if((cnt & 1) and maxBit != -1) {
				useless = (useless + (1LL<<maxBit))%mod;
				// useless = useless + (1LL<<maxBit);
			}
			// debug() << imie(useless) imie(cnt);
		}
		// debug() << imie(last) imie(sum) imie(useless);
		if(last <= n) {
			// if(sufsum[i] - useless < 0) {
			// 	cout << i << " " << sufsum[i] << " " << useless << '\n';
			// }
			// assert((sufsum[i] - useless) >= 0);
			// sum = (sufsum[i] - useless + sum + mod)%mod;
			sum = ((sufsum[i] - useless + mod) % mod + sum)%mod;
		}

		ans = (ans + sum) % mod;
		// if(i == 2) {
		// 	debug() << imie(i) imie(sum);
		// }
		// ans = ans + sum;
		// cout << ans << '\n';
		// break;

		// debug() << imie(i) imie(sum);
	}

	cout << ans % mod << '\n';
}