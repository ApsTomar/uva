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
#define mp make_pair
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
string s1[50001],s2[50001];
ll w[50001];
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,f=0;
    cin>>t;
    while(t--)
    {
        if(f) cout<<endl;
        f=1;
        ll m;
        cin>>m;
        ll n;
        cin>>n;
        map<string,ll> map1;
        set<string> set1;
        FOR(i,n)
        {
            cin>>s1[i]>>s2[i]>>w[i];
            set1.insert(s1[i]);
            set1.insert(s2[i]);
        }
        ll cnt=0;
        for(set<string>::iterator it=set1.begin();it!=set1.end();it++)
        {
            map1[(*it)]=cnt++;
        }
        ed.clear();
        FOR(i,n)
        {
            ed.pb(mp(w[i],ii(map1[s1[i]],map1[s2[i]])));
        }
        sort(ed.begin(),ed.end());
        unionfind(m);
        ll mst=0;
        FOR(i,n)
        {
            pair<ll,ii> xy=ed[i];
            if(!sameset(xy.second.first,xy.second.second))
            {
                mst+=xy.first;
                unionset(xy.second.first,xy.second.second);
            }
        }
        cout<<mst<<endl;
    }

    return 0;
}
