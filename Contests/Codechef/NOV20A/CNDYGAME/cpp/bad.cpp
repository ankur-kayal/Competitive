#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#pragma GCC optimize "trapv"
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
    ll n;
    cin>>n;
    ll a[n],ssp[n+1];
    ll sum,ssum;
    sum=ssum=0;
    ll pos=0;
    bool flag=false;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        ssp[i]=0;
        if(a[i]==1)
        {
            flag=true;
            pos=i;
        }
        if(i==n-1)
        {
            if(a[i]&1)
            {
                sum=((sum%mod)+(a[i]%mod))%mod;
                sum%=mod;
            }
            else
            {
                sum=((sum%mod)+(a[i]-1)%mod)%mod;
                sum%=mod;
            }
            break;
        }
        if(a[i]&1)
        {
            sum=((sum%mod)+(a[i]-1)%mod)%mod;
            sum%=mod;
        }
        else
        {
            sum=((sum%mod)+(a[i]%mod))%mod;
            sum%=mod;
        }
    }
    ssp[0]=a[0]%mod;
    for(ll i=1;i<n;i++)
    {
        if(a[i-1]&1)
        {
            ssp[i]=((ssp[i-1])%mod+(a[i]-1)%mod)%mod;
            ssp[i]%=mod;
        }
        else
        {
            ssp[i]=((ssp[i-1])%mod+(a[i])%mod)%mod;
            ssp[i]%=mod;
        }
    }
    int q;
    cin>>q;
    ll x;
    while(q--)
    {
        cin>>x;
        ll ans=0;
        ll temp=x/n;
        temp%=mod;
        if(flag)
        {
            if(pos==0)
            {
                ans=temp;
                if((x%n)>1 || x==1)
                {
                    ans++;
                }
                ans%=mod;
                cout<<ans<<"\n";
            }
            else if(pos==n-1)
            {
                ans=((temp%mod)*sum)%mod;
                if(x%n)
                {
                    ans=((ans%mod)+(ssp[(x%n)-1]%mod))%mod;
                    ans%=mod;
                }
                cout<<ans<<"\n";
            }
            else
            {
                ll femp=(sum%mod);
                if(a[pos-1]&1)
                {
                    femp++;
                    femp%=mod;
                }
                else
                {
                    femp--;
                }
                ans=((femp%mod)*temp)%mod;
                if(x%n)
                {
                    ans=((ans%mod)+(ssp[(x%n)-1]%mod))%mod;
                    ans%=mod;
                    if(((x%n)-1)>pos)
                    {
                        if(a[pos-1]&1)
                        {
                            ans++;
                            ans%=mod;
                        }
                        else
                        {
                            ans--;
                        }
                    }
                    cout<<ans<<"\n";
                    
                }
                else if(x==n)
                {
                    ll cans=ssp[n-1]%mod;
                    if(a[pos-1]&1)
                    {
                        cans++;
                        cans%=mod;
                    }
                    else
                    {
                        cans--;
                    }
                    cout<<cans<<"\n";
                }
                else
                {
                    ll fep=(((temp-1+mod)%mod)*femp)%mod;
                    fep=((fep%mod)+(ssp[n-1]%mod))%mod;
                    fep%=mod;
                    if(a[pos-1]&1)
                    {
                        fep++;
                        fep%=mod;
                    }
                    else
                    {
                        fep--;
                    }
                    cout<<fep<<"\n";
                    
                }
                
            }
        }
        else
        {
            cout << "Bug" << '\n';
            ans=((temp%mod)*(sum%mod))%mod;
            if(x%n)
            {
                ans=((ans%mod)+(ssp[(x%n)-1]%mod))%mod;
                ans%=mod;
                cout<<ans<<"\n";
            }
            else if(x==n)
            {
                 ll cans=(ssp[n-1])%mod;
                 cout<<cans<<"\n";
            }
            else
            {
                ll fep=(((temp-1+mod)%mod)*(sum%mod))%mod;
                fep=((fep%mod)+(ssp[n-1]%mod))%mod;
                fep%=mod;
                cout<<fep<<"\n";
            }
            
        }
    }
    }
    return 0;
}