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
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while (t--)
    {
        ll m;
        cin>>m;
        string s[m+1];
        map<string ,ll> m1;
        ll f=0,ans0=0,ans1=INF;
        FOR(i,m)
        {
            cin>>s[i];
            m1[s[i]]=i;
            ans0=0;
            FOR(k,4)
            {
                int x1=s[i][k]-'0';
                int y1=0;
                int dis1=abs(x1-y1);
                int dis2=10-dis1;
                ans0+=min(dis1,dis2);
            }
            ans1=min(ans1,ans0);
        }
        unionfind(m);
        ed.clear();
        ll c=0,mst=0;
        FOR(i,m)
        {
            FR(j,i,m)
            {
                if(i==j) continue;
                int ans=0;
                FOR(k,4)
                {
                    int x=s[i][k]-'0';
                    int y=s[j][k]-'0';
                    int d1=abs(x-y);
                    int d2=10-d1;
                    ans+=min(d1,d2);
                }
                ed.pb(mp(ans,ii(m1[s[i]],m1[s[j]])));
                c++;
            }
        }
        sort(ed.begin(),ed.end());
        FOR(i,c)
        {
            pair<ll,ii> xy=ed[i];
            if(!sameset(xy.second.first,xy.second.second))
            {
                mst+=xy.first;
                unionset(xy.second.first,xy.second.second);
            }
        }
        
        mst+=ans1;
        cout<<mst<<endl;
    }

    return 0;
}