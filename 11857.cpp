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
ll disjnt()
{
	return numset;
}
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	while (cin>>n>>m)
	{
	   if(n==0 && m==0) break;
	   ll x,y,z;
	   ed.clear();
	   FOR(i,m)
	   {
			cin>>x>>y>>z;
			ed.pb(mp(z,ii(x,y)));
	   }
	   sort(ed.begin(),ed.end());
	   unionfind(n);
	   ll mst=0,ans=-1;
	   FOR(i,m)
	   {
	   		pair<ll,ii> xy=ed[i];
	   		if(!sameset(xy.second.first,xy.second.second))
	   		{
	   			ans=max(ans,xy.first);
	   			mst+=xy.first;
	   			unionset(xy.second.first,xy.second.second);
	   		}
	   }
	   ll disjointsets=disjnt();
	   if(ans==-1 || disjointsets!=1) cout<<"IMPOSSIBLE"<<endl;
	   else cout<<ans<<endl;

	}
	   
	return 0;
}