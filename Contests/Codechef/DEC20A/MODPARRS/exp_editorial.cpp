#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MX 239
int n,a[25];
long long fact[MX+5],inv[MX+5],dp[(1<<21)];
long long pow_log(long long x,int y)
{
    if (!y)
    return 1;
    long long ret=pow_log(x,y/2);
    ret=(ret*ret)%mod;
    if (y%2)
    ret=(ret*x)%mod;
    return ret;
}
int sum(int mask) //the sum of the elements in this subset
{
    int ret=0;
    for (int i=0;i<n;i++)
    {
        if (mask&(1<<i))
        ret=(ret+a[i])%MX;
    }
    return ret;
}
void run_tests()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    scanf("%d",&a[i]);
    fact[0]=1;
    for (int i=1;i<=MX;i++)
    fact[i]=(i*fact[i-1])%mod; //factorial
    inv[MX]=pow_log(fact[MX],mod-2);
    for(int i=MX-1;i>=0;i--)
    inv[i]=((i+1)*inv[i+1])%mod; //factorial inverse
    dp[0]=(sum((1<<n)-1)? 1:MX);
    for (int mask=1;mask<(1<<(n-1));mask++)
    {
        int sz=__builtin_popcount(mask); //the size of s
        if (sum((1<<n)-1)==sum(mask)) //the combined element is 0
        {
            for (int i=0;i<n-1;i++)
            {
                if (mask&(1<<i))
                {
                    dp[mask]=(dp[(mask^(1<<i))]*(MX-sz))%mod;
                    break;
                }
            }
        }
        else //the combined element is non-zero
        {
            dp[mask]=(fact[MX]*inv[MX-sz])%mod;
            for (int i=0;i<n-1;i++)
            {
                if (mask&(1<<i))
                dp[mask]=(dp[mask]-dp[mask^(1<<i)]+mod)%mod;
            }
        }
    }
    printf("%d\n",dp[(1<<(n-1))-1]);
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        run_tests();
    }
}