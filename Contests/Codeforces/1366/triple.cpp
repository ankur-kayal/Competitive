#include <bits/stdc++.h>
#include <stdint.h>
#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pi 3.1415926535897932
#define nui 100
using namespace std;
 
 
int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 
	ll t;
	cin >> t;
	while (t--)
	{
		ll p, q, r, a, b, c;
		cin >> p >> q >> r >> a >> b >> c;
		if (p == a && q == b && r == c)
		{
			cout << "0\n";
		}
		else if (p - a == q - b && q - b == r - c)
		{
			cout << "1\n";
		}
		else if (p != 0 && q != 0 && r != 0 && a == 0 && b == 0 && c == 0)
		{
			cout << "1\n";
		}
		else if (a == 0 && b == 0 && c == 0 && ((p != 0 && q != 0 && r == 0) || (p == 0 && q != 0 && r != 0) || (p != 0 && q == 0 & r != 0)))
		{
			cout << "1\n";
		}
		else if (p * b == q * a && q * c == r * b && p != 0 && q != 0 && r != 0 && a != 0 && b != 0 && c != 0)
		{
			cout << "1\n";
		}
		else if ((a == p && b == q && c != r) || (a != p && b == q && c == r) || (a == p && b != q && c == r))
		{
			cout << "1\n";
		}
		else if (p == a && q != b && r != c && q != 0 && r != 0 && b * r == c * q && b != 0 && c != 0 )
		{
			cout << "1\n";
		}
		else if (p == a && q != b && r != c)
		{
			if (b - q == c - r)
			{
				cout << "1\n";
			}
			else
			{
				cout << "2\n";
			}
		}
		else if (p != a && q == b && r != c && p != 0 && r != 0 && a * r == c * p && a != 0 && c != 0)
		{
			cout << "1\n";
		}
		else if (p != a && q == b && r != c)
		{
			if (c - r == a - p)
			{
				cout << "1\n";
			}
			else
			{
				cout << "2\n";
			}
		}
		else if (p != a && q != b && r == c && p != 0 && q != 0 && a * q == b * p && a != 0 && b != 0)
		{
			cout << "1\n";
		}
		else if (p != a && q != b && r == c)
		{
			if (a - p == b - q)
			{
				cout << "1\n";
			}
			else
			{
				cout << "2\n";
			}
		}
		else if (((a - b) * (q - r)) == ((b - c) * (p - q)))
		{
			cout << "2\n";
		}
		else if (((a - b)*r == (p - q)*c) || ((a - c)*q == (p - r)*b) || ((b - c)*p == (q - r)*a))
		{
			cout << "2\n";
		}
		else if (((b * p - q * a) == (c - r) * (p - q)) || ((c * p - a * r) == (b - q) * (p - r)) || ((q * c - b * r) == (a - p) * (q - r)))
		{
 
			cout << "2\n";
		}
		else if (p * b * c == a * q * r || c * q * p == a * b * r || q * a * c == b * p * r)
		{
			cout << "2\n";
		}
		else if ((a - p) == (b + c) - (q + r) || (c - r) == (a + b) - (p + q) || (b - q) == (a + c) - (p + r))
		{
			cout << "2\n";
		}
		else if (((c - r) * (b - a) == a * q - b * p) || ((b - q) * (c - a) == a * r - c * p) || ((a - p) * (c - b) == b * r - c * q))
		{
			cout << "2\n";
		}
		else if ((b * r - q * c) == (a - p)*r || (a * q - p * b) == (c - r)*q || (p * c - r * a) == p * (b - q))
		{
			cout << "2\n";
		}
		else if (((a - p)*c == (b * r - q * c)) || ((c - r)*b == (a * q - p * b)) || ((b - q)*a == (c * p - a * r)))
		{
			cout << "2\n";
		}
		else if (((p * b - a * q) == (c - r)*a) || ((a * r - p * c) == c * (b - q)) || ((c * q - b * r) == b * (a - p)))
		{
			cout << "2\n";
		}
		else if ((a - p == b - q) || (a - p == c - r) || (b - q == c - r))
		{
			cout << "2\n";
		}
		else if ((a * r - p * c == (b - q)*r) || (b * p - q * a == (c - r)*p) || (q * c - r * b == (a - p)*q))
		{
			cout << "2\n";
		}
		else if ((b * r == c * q) || (a * r == c * p) || (a * q == b * p))
		{
			cout << "2\n";
		}
		else
		{
			cout << "3\n";
		}
 
	}
	return 0;
}


3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 1, 0]
3 [2, 0, 1]
3 [2, 0, 1]
3 [2, 0, 1]
3 [2, 0, 1]
3 [2, 0, 1]
2 [2, 0, 1]
2 [2, 0, 1]
2 [2, 0, 1]
2 [2, 0, 1]
2 [2, 0, 1]