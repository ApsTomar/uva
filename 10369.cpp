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
vector<pair<double,ii> > ed;
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
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while (t--)
    {
    	ll n,m,c=0;
    	cin>>n>>m;
    	ll x[m],y[m];
    	FOR(i,m)
    	{
    		cin>>x[i]>>y[i];
    	}
    	ed.clear();
    	FOR(i,m)
    	{
    		FR(j,i+1,m)
    		{
    			double dist=sqrt(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j])));
    			ed.pb(mp(dist,ii(i,j)));
    			c++;
    		}
    	}
        sort(ed.begin(),ed.end());
        unionfind(m);
        double dd[c+1];
        ll cnt=0,mst=0;
        FOR(i,c)
        {
            pair<double,ii> xy=ed[i];
            if(!sameset(xy.second.first,xy.second.second))
            {
                mst+=xy.first;
                dd[cnt++]=xy.first;
                unionset(xy.second.first,xy.second.second);
            }
        }
        double ans;
        sort(dd,dd+cnt);
        if(n) ans=dd[cnt-n];
        else ans=dd[cnt-1];
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }

    return 0;
}