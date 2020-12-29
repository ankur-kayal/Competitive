#include<bits/stdc++.h>
using namespace std;

struct tree {
    int two;
    int five;
    int zero;
    int lazy;
};
const int mxN = 1e5 + 10;

tree st[4 * mxN];
int arr[mxN];

void build(int si,int ss,int se) {
    if(ss==se) {
        int x=arr[ss];
        st[si].lazy=-1;
        st[si].two=0;
        st[si].five=0;
        if(arr[ss]==0)
            st[si].zero=1;
        else
            st[si].zero=0;
        while(x % 5 == 0 and x > 0) {
           st[si].five++;
           x/=5;
        }
        while(x % 2 == 0 and x > 0) {
           st[si].two++;
           x/=2;
        }
        return;
    }
    int mid=(ss+se)/2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    st[si].lazy=-1;
    st[si].two=st[2*si].two+st[2*si+1].two;
    st[si].five=st[2*si].five+st[2*si+1].five;
    st[si].zero=st[2*si].zero+st[2*si+1].zero;
}

void update(int si, int ss, int se, int qs, int qe,int val) {
    if(st[si].lazy!=-1) {
        int x=st[si].lazy;
        int two=0,five=0;
        while(x%2==0 and x > 0) {
            x=x/2;
            two++;
        }
        while(x%5==0 and x > 0) {
            x=x/5;
            five++;
        }
        st[si].two=(se-ss+1)*two;
        st[si].five=(se-ss+1)*five;
        st[si].zero=(se-ss+1)*(st[si].lazy==0);
        if(ss!=se)
        {
            st[2*si].lazy=st[si].lazy;
            st[2*si+1].lazy=st[si].lazy;
        }
        st[si].lazy=-1;
    }

    if(se < qs or ss > qe) return;
    if(ss >= qs and se<=qe) {
        int x=val;
        int two=0,five=0;
        while(x % 2 == 0 and x > 0) {
            two++;
            x/=2;
        }
        while(x % 5 == 0 and x > 0) {
            five++;
            x/=5;
        }
        st[si].two=(se-ss+1)*two;
        st[si].five=(se-ss+1)*five;
        st[si].zero=(se-ss+1)*(val==0);
        if(ss!=se) {
            st[2*si].lazy=val;
            st[2*si+1].lazy=val;
        }
        return;
    }
    int mid=(ss+se)/2;
    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si + 1, mid + 1, se, qs, qe, val);
    st[si].two=st[2*si].two+st[2*si+1].two;
    st[si].five=st[2*si].five+st[2*si+1].five;
    st[si].zero=st[2*si].zero+st[2*si+1].zero;
}


tree query(int si, int ss,int se,int qs,int qe) {
    if(st[si].lazy!=-1) {
        int x=st[si].lazy;
        int two=0,five=0;
        while(x % 2 == 0 and x > 0) {
            two++;
            x/=2;
        }
        while(x % 5 == 0 and x > 0) {
            x=x/5;
            five++;
        }
        st[si].two=(se-ss+1)*two;
        st[si].five=(se-ss+1)*five;
        st[si].zero=(se-ss+1)*(st[si].lazy==0);
        if(ss!=se) {
            st[2*si].lazy=st[si].lazy;
            st[2*si+1].lazy=st[si].lazy;
        }
        st[si].lazy=-1;
    }
    if(se < qs or ss > qe) {
        tree temp;
        temp.two=0;
        temp.five=0;
        temp.zero=0;
        return temp;
    }
    if(ss >= qs and se <= qe) {
        return st[si];
    }
    int mid=(ss+se)/2;
    tree temp,left,right;
    left=query(2 * si, ss, mid, qs, qe);
    right=query(2 * si + 1, mid + 1, se, qs, qe);
    temp.two=left.two+right.two;
    temp.five=left.five+right.five;
    temp.zero=left.zero + right.zero;
    return temp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    build(1,1,n);
    int q;
    cin>>q;
    while(q--) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            int qs, qe;
            cin >> qs >> qe;
            tree temp;
            temp=query(1,1,n,qs,qe);
            if(temp.zero)
                cout << 1 << '\n';
            else
                cout << min(temp.two,temp.five) << '\n';
        }
        else {
            int qs, qe, val;
            cin >> qs >> qe >> val;
            update(1,1,n,qs,qe,val);
        }
    }
    return 0;
}
