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
#define INF	9999999999
#define pb push_back
#define FOR(i,f_limit) for(long long int i=0;i<f_limit;i++)
#define FR(i,s_limit,f_limit) for(long long int i=s_limit;i<f_limit;i++)
typedef long long int ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;


bool check(vi vec, int ch)
{
	for(int i=0;i<(int)vec.size();i++)
	{
		if(vec[i]==ch) return true;
	}
	return false;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		vii adj;
		vi col;
		int a,b;
		int n;
		cin>>n;
		adj.assign(n,vi());
		col.assign(n,INF);
		FOR(i,n)
		{
			cin>>a;
			FOR(j,a)
			{
				cin>>b;
				b--;	
				if(b<n)
				{
					if(!check(adj[i],b)) adj[i].pb(b);
					if(!check(adj[b],i)) adj[b].pb(i);
				}				
			}
		}
		 
		int ans =0;
		FOR(i,n)
		{
			if(col[i]==INF)
			{
				queue<int> q;
				q.push(i);
				int c1=0;
				int c2=0;
				col[i]=0;
				bool bip=true;
				c1++;
				while(!q.empty()  )
				{
					int u=q.front();
					q.pop();
					FOR(i,(int)adj[u].size())
					{
						int v=adj[u][i];
						if(col[v]==INF)
						{
							col[v]=1-col[u];
							if(col[v]==0) c1++;
							else c2++;
							q.push(v);
						}
						else if(col[v]==col[u])
						{
							bip=false;
						}
					}
				}
				if(bip) ans+=max(c1,c2);
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}