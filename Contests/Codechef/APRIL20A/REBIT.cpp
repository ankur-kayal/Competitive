#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int mod = 998244353;

struct Prob {
	ll zero;
	ll one;
	ll a;
	ll A;
};

ll binpow(ll x, ll y) {
	x = x % mod;
	ll res = 1;
	while(y > 0) {
		if(y & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		y = y >> 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif

    vector <ll> deno(100005);
    deno[0] = 1;
    for(int i=1;i<=100000;i++) {
    	deno[i] = (deno[i-1] * 4) % mod;
    }
    int t;
    cin >> t;
    while(t--) {
    	string s;
    	cin >> s;
    	stack <Prob> operand;
    	stack <char> operation;
    	int c = 0;
    	for(int i=0;i<s.size();i++) {
    		if(s[i] == '#') {
    			c++;
    			Prob ele;
    			ele.zero = 1;
    			ele.one = 1;
    			ele.a = 1;
    			ele. A = 1;
    			operand.push(ele);
    		}
    		else if(s[i] == '&' or s[i] == '|' or s[i] == '^') {
    			operation.push(s[i]);
    		}
    		else if(s[i] == ')') {
    			Prob res;
    			Prob e1 = operand.top();
    			operand.pop();
    			Prob e2 = operand.top();
    			operand.pop();
    			char sign = operation.top();
    			operation.pop();
    			if(sign == '&') {
    				res.one = (e1.one * e2.one) % mod;
    				res.a = ((e1.a * e2.one)%mod + (e1.a * e2.a)%mod + (e1.one * e2.a)%mod) % mod;
    				res.A = ((e1.A * e2.one)%mod + (e1.A * e2.A)%mod + (e1.one * e2.A)%mod) % mod;
    				res.zero = ((e1.zero*e2.zero)%mod + (e1.zero*e2.one)%mod + (e1.zero*e2.a)%mod + (e1.zero*e2.A)%mod + (e1.one*e2.zero)%mod + (e1.a*e2.zero)%mod + (e1.a*e2.A)%mod + (e1.A*e2.zero)%mod + (e1.A*e2.a)%mod) % mod;

    			}
    			if(sign == '|') {
    				res.zero = (e1.zero * e2.zero) % mod;
    				res.a = ((e1.a * e2.zero)%mod + (e1.a * e2.a)%mod + (e1.zero * e2.a)%mod) % mod;
    				res.A = ((e1.A * e2.zero)%mod + (e1.A * e2.A)%mod + (e1.zero * e2.A)%mod) % mod;
    				res.one = ((e1.one*e2.one)%mod + (e1.zero*e2.one)%mod + (e1.one*e2.a)%mod + (e1.one*e2.A)%mod + (e1.one*e2.zero)%mod + (e1.a*e2.one)%mod + (e1.a*e2.A)%mod + (e1.A*e2.one)%mod + (e1.A*e2.a)%mod) % mod;
    			}
    			if(sign == '^') {
    				res.zero = ((e2.zero * e1.zero)%mod + (e1.a * e2.a)%mod + (e1.A * e2.A)%mod + (e1.one * e2.one)%mod) % mod;
    				res.one = ((e1.zero * e2.one)%mod + (e1.one * e2.zero)%mod + (e1.a * e2.A)%mod + (e1.A * e2.a)%mod) % mod;
    				res.a = ((e1.zero * e2.a)%mod + (e1.a * e2.zero)%mod + (e1.one * e2.A)%mod + (e1.A * e2.one)%mod) % mod;
    				res.A = ((e1.zero * e2.A)%mod + (e1.one * e2.a)%mod + (e1.A * e2.zero)%mod + (e1.a * e2.one)%mod) % mod;
    			}
    			operand.push(res);
    		}
    	}
    	Prob ans = operand.top();
    	operand.pop();
    	// cout << c << '\n';
    	// cout << deno[c] << '\n';
    	// cout << ans.zero << " " << ans.one << " " << ans.a << " " << ans.A << '\n';
    	// cout << binpow(deno[c],mod-2) << '\n';
    	// ll ans_one, ans_zero, ans_a, ans_A;
    	ll ans_one = (ans.one * binpow(deno[c],mod-2))%mod;
    	ll ans_zero = (ans.zero * binpow(deno[c],mod-2))%mod;
    	ll ans_a = (ans.a * binpow(deno[c],mod-2))%mod;
    	ll ans_A = (ans.A * binpow(deno[c],mod-2))%mod;
    	cout << ans_zero << " " << ans_one << " " << ans_a << " " << ans_A << '\n';
    }
}