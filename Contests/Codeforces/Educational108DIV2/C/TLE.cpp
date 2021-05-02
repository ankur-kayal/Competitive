#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
       vector<ll>v[200001];
       
       ll students;
       map<ll,ll>university;
       university.clear();
       cin>>students;
    
       vector<ll>serial;
       vector<ll>skill;
       serial.clear();
       skill.clear();
       vector<ll>vv[200001];
       for(int i=0;i<=200001;i++){
        v[i].clear();
        vv[i].clear();
       }
       for(int i=0;i<students;i++){

        int a;
        cin>>a;
        serial.push_back(a);
        university[a]++;
       }
       for(int j=0;j<students;j++){



           int b;
           cin>>b;
           skill.push_back(b);
           int d=serial[j];
           v[d].push_back(b);
           vv[v[d].size()].push_back(d);

       }
    
       for(int k=1;k<=students;k++){


           sort(v[k].begin(),v[k].end());
         reverse(v[k].begin(),v[k].end());


       }
       
      for(int h=1;h<=students;h++){
          for(int g=1;g<v[h].size();g++){
            v[h][g]+=v[h][g-1];
          }
       }
      /* for(int i=1;i<=students;i++){
        for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";
        cout<<endl;
       }*/
      ll strength[students+1];
      memset(strength,0,sizeof strength);
      for(int i=1;i<=students;i++){
            ll amount=0;
        for(int j=0;j<vv[i].size();j++){
            ll u=vv[i][j];
            ll sizee=v[u].size();
            if(sizee%i==0){
                ll value=v[u][sizee-1];
            amount+=value;
            }
            else{
                ll rem=sizee%i;
                ll arek=v[u][sizee-rem-1];
                amount+=arek;
            }
            
        }
         strength[i]=amount;
         ///cout<<" length "<<i<<" "<<amount<<endl;
      }
    for(int o=1;o<=students;o++)cout<<strength[o]<<" ";
    cout<<endl;

    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
