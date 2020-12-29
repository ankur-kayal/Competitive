#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 rnd (seed);
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
typedef struct node
{
    int prior,size;
    int val;//value stored in the array
    int sum;//whatever info you want to maintain in segtree for each node
    int lazy;//whatever lazy update you want to do
    bool rev;
    bool rev_lazy;
    struct node *l,*r;
}node;
 
typedef node* pnode;
 
node buffer[600001];
pnode tr;
pnode null;
 
int sz(pnode t)
{
    return t?t->size:0;
}
 
void upd_sz(pnode t)
{
    if(t)t->size=sz(t->l)+1+sz(t->r);
}
 
void lazy(pnode t)
{
    if(!t)return;
    t->val+=t->lazy;//operation of lazy
    t->sum+=t->lazy*sz(t);
    t->rev^=t->rev_lazy;
    if(t->rev)
    {
		swap(t->l, t->r);
		t->rev = 0;
	}
    if(t->l)
    {
		t->l->lazy+=t->lazy;//propagate lazy
		t->l->rev_lazy^=t->rev_lazy;
	}
    if(t->r)
    {
		t->r->lazy+=t->lazy;
		t->r->rev_lazy^=t->rev_lazy;
	}
    t->lazy=0; t->rev_lazy=0;
}
 
void reset(pnode t)
{
    if(t)
    {
		t->sum = 0;//no need to reset lazy coz when we call this lazy would itself be propagated
		t->rev = false;
	}
}
 
void combine(pnode& t,pnode l,pnode r)
{//combining two ranges of segtree
    if(!l || !r)return void(t = l?l:r);
    t->sum = l->sum + r->sum;
}
 
void operation(pnode t)
{//operation of segtree
    if(!t)return;
    reset(t);//reset the value of current node assuming it now represents a single element of the array
    lazy(t->l);lazy(t->r);//imp:propagate lazy before combining t->l,t->r;
    combine(t,t->l,t);
    combine(t,t,t->r);
}
 
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
    if(!t)return void(l=r=NULL);
    lazy(t);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to left subtree(l)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else 
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
 
void merge(pnode &t,pnode l,pnode r)
{ //l->leftarray,r->rightarray,t->resulting array
    lazy(l);lazy(r);
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else    merge(r->l,l,r->l),t=r;
    upd_sz(t);
    operation(t);
}
 
node *ptr = buffer;
 
pnode init(int val)
{
    pnode ret = ptr;
    ret->prior=rnd();ret->size=1;
    ret->val=val;
    ret->sum=0;ret->lazy=0;
    ret->rev = false;
    ptr++;
    return ret;
}
 
int range_query(pnode t,int l,int r)
{//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    int ans = (t->sum+t->val)%26;
    //int ans = t->sum;
    merge(mid,L,t);
    merge(t,mid,R);
    return ans;
}
 
void range_update(pnode t,int l,int r,int val)
{//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    t->lazy+=val; //lazy_update
    merge(mid,L,t);
    merge(t,mid,R);
}
 
void range_reverse(pnode t,int l,int r)
{//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    t->rev_lazy^=1; //lazy_update
    merge(mid,L,t);
    merge(t,mid,R);
}
 
char cycshift(char c, int x)
{
	int z = c - 'a';
	z += x;
	z%=26;
	return char(z+'a');
}
 
string s;
 
void initialize(int n)
{
	tr = NULL;
	for(int i = 0; i < n; i++)
	{
		pnode tmp = init(int(s[i]-'a'));
	    merge(tr, tr, tmp);
	}
}
 
void upd(int l, int r, int pos) //split is 0-indexed
{
	pnode L;
	pnode R;
	split(tr, L, R, l-1);
	pnode mid;
	split(R, mid, R, r-l);
	merge(L, L, R);
	pnode L2;
	pnode R2;
	split(L, L2, R2, pos);
	merge(tr, L2, mid);
	merge(tr, tr, R2);
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	initialize(int(s.length()));
	int q; cin >> q;
	while(q--)
	{
		int t, l, r;
		cin>>t>>l>>r;
		l--; r--;
		if(t == 1)
		{
			int pos; cin >> pos; pos--;
			upd(l, r, pos);
		}
		else if(t == 2)
		{
			int c; cin >> c;
			c%=26;
			range_update(tr, l, r, c);
		}
		else
		{
			range_reverse(tr, l, r);
		}
	}
	for(int i = 0; i < s.length(); i++)
	{
		//cerr<<range_query(tr,i,i)<<'\n';
		s[i] = char('a' + range_query(tr,i,i));
	}
	cout << s;
}
 