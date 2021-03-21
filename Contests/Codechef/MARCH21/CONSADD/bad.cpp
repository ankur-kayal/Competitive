#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isConvertible(ll r,ll c,ll x)
{
    ll a[r][c] , b[r][c];

    ll sum_A = 0;
    ll sum_B = 0;

    for(ll i=0;i<r;i++)
    {
        for(ll j=0;j<c;j++)
        {
            scanf("%lld",&a[i][j]);
            sum_A += a[i][j];
        }
    }

    for(ll i=0;i<r;i++)
    {
        for(ll j=0;j<c;j++)
        {
            scanf("%lld",&b[i][j]);
            sum_B += b[i][j];
        }
    }

    if(r >= x && c < x)
    {
        for(ll i=0;i<c;i++)
        {
            for(ll j=0;j<=r-x;j++)
            {
                if(a[j][i] == b[j][i])
                    continue;
                else
                {
                    ll diff = b[j][i] - a[j][i];
                    for(ll var = j; var < j+x; var++)
                    {
                        a[var][i] += diff;
                //      sum_A += diff;
                    }
                }

                if(j == r-x)
                {
                    for(ll var = r-x+1; var < r; var++)
                    {
                        if(a[var][i] != b[var][i])
                        {
                            return false;
                        }
                    }
                }
            }

        }
//      if(sum_A != sum_B) return false;
    }
    else if(r < x && c >= x)
    {
        for(ll i=0;i<r;i++)
        {
            for(ll j=0;j<=c-x;j++)
            {
                if(a[j][i] == b[j][i])
                    continue;
                else
                {
                    ll diff = b[j][i] - a[j][i];
                    for(ll var = j; var < j+x; var++)
                    {
                        a[var][i] += diff;
                //      sum_A += diff;
                    }
                }

                if(j == c-x)
                {
                    for(ll var = c-x+1; var < c; var++)
                    {
                        if(a[var][i] != b[var][i])
                        {
                            return false;
                        }
                    }
                }
            }

        }
//      if(sum_A != sum_B) return false;
    }
    else if(r >= x && c >= x)
    {
        for(ll i=0;i<c;i++)
        {
            for(ll j=0;j<=r-x;j++)
            {
                if(a[j][i] == b[j][i])
                    continue;
                else
                {
                    ll diff = b[j][i] - a[j][i];
                    for(ll var = j; var < j+x; var++)
                    {
                        a[var][i] += diff;
                        sum_A += diff;
                    }
                }
            }
        }
        for(ll i=0;i<r;i++)
        {
            for(ll j=0;j<=c-x;j++)
            {
                if(a[j][i] == b[j][i])
                    continue;
                else
                {
                    ll diff = b[j][i] - a[j][i];
                    for(ll var = j; var < j+x; var++)
                    {
                        a[var][i] += diff;
                        sum_A += diff;
                    }
                }

                if(j == c-x)
                {
                    for(ll var = c-x+1; var < c; var++)
                    {
                        if(a[var][i] != b[var][i])
                        {
                            return false;
                        }
                    }
                }
            }

        }   
        if(sum_A != sum_B) return false;
    }

    return true;
}

void solve()
{
    ll r,c,x;
    scanf("%lld%lld%lld",&r,&c,&x);

    bool ans = isConvertible(r,c,x);

    if(ans)
    printf("Yes\n");
    else
    printf("No\n");
    
}

int main(void)
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}