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
typedef vector<long long int> vi;
typedef vector<vi> vii;

vii adj;
vi col;
int a,b;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	while(cin>>n)
	{
		if(n==0) break;
		adj.assign(n+1,vi());
		col.assign(n+1,INF);
		while(cin>>a>>b)
		{
			if(a==0 && b==0) break;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		queue<int> q;
		q.push(1);
		col[1]=0;
		bool bip=true;
		while(!q.empty() && bip)
		{
			int u=q.front();
			q.pop();
			FOR(i,(int)adj[u].size())
			{
				int v=adj[u][i];
				if(col[v]==INF)
				{
					col[v]=1-col[u];
					q.push(v);
				}
				else if(col[u]==col[v]) 
				{
					bip=false;
					break;
				}
			}
		}
		if(bip) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
	return 0;
}