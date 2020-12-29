#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int Longest(ll arr[],int n)
{
	vector<pair<ll,pair<int,int>>> v;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			v.push_back(make_pair(arr[i]^arr[j],make_pair(i,j)));
		}
	}
	sort(v.begin(),v.end());
	int dp[n];
	
	for(int i=0;i<n;i++)
	{ dp[i]=1; }
	
	 
	for(auto k : v)
	{
		dp[k.second.second]=max(dp[k.second.second],dp[k.second.first]+1);
		cout << k.first << " " << k.second.first << " " <<  k.second.second << '\n';
	}
	int ans=1;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,dp[i]);
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif
    int n;
    cin>>n;
    ll arr[1000];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    cout<<Longest(arr,n);
	return 0;
}
