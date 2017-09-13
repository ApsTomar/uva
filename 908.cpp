#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <math.h>
#include <vector>
#include <bitset>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define PI 3.14159265
#define INF 9999999999
#define EPS 1e-16
#define pb push_back
#define FOR(i,f_limit) for(long long int i=0;i<f_limit;i++)
#define FR(i,s_limit,f_limit) for(long long int i=s_limit;i<f_limit;i++)
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
typedef long long int ll; 
typedef vector<ll> vi;
typedef vector<vi> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<pair<ll,ii> > ed;
vi rnk,p,setsize;
ll numset;
ll unionfind(ll n)
{
    n=200001;
    rnk.assign(n,0);
    setsize.assign(n,1);
    p.assign(n,0);
    numset=n;
    FOR(i,n) p[i]=i;
}
ll findset(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=findset(p[x]); 
}
bool sameset(ll x, ll y)
{
    return findset(x)== findset(y);
}
void unionset(ll a, ll b)
{
    if(!sameset(a,b)) 
    {
        numset--;
        ll x=findset(a);
        ll y=findset(b);
        if(rnk[x]>rnk[y])
        {
            p[y]=x;
            setsize[x]+=setsize[y];
        }
        else 
        {
            p[x]=y;
            setsize[y]+=setsize[x];
            if(rnk[x]==rnk[y]) rnk[y]++;
        }

    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,f=0;
    while(cin>>n)
    {
        if(f) 
        {
            cout<<endl;
        }
        f=1;
        ll s=0,x,y,z;
        FOR(i,n-1)
        {
            cin>>x>>y>>z;
            s+=z;
        }
        ll k;
        cin>>k;
        ed.clear();
        FOR(i,k)
        {
            cin>>x>>y>>z;
            ed.pb(make_pair(z,ii(x,y)));
        }
        ll m,mst=0;
        cin>>m;
        FOR(i,m)
        {
           cin>>x>>y>>z;
           ed.pb(make_pair(z,ii(x,y))); 
        }
        sort(ed.begin(),ed.end());
        unionfind(m+k);
        FOR(i,m+k)
        {
            pair<ll,ii> t=ed[i];
            if(!sameset(t.second.first,t.second.second))
            {
                mst+=t.first;
                unionset(t.second.first,t.second.second);
            }
        }
        cout<<s<<endl<<mst<<endl;

    }


    return 0;
}