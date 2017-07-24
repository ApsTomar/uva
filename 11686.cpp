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
vi dep,ts;
int n,m,x,y,flag=0;
int dfs(int s)
{
	dep[s]=1;
	FOR(j,(int)adj[s].size())
	{
		int u=adj[s][j];
		if(dep[u]==0) dfs(u);	
		else if (dep[u]==1) flag =1;
	}
	dep[s]=2;
	ts.pb(s);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n>>m)
	{
		if(n==0 && m==0) break;
		adj.assign(n+1,vi());
		dep.assign(n+1,0);
		FOR(i,m)
		{
			cin>>x>>y;
			adj[x].pb(y);
		}
		ts.clear();

		flag=0;
		FR(i,1,n+1)
		{
			if(dep[i]==0) dfs(i);
		}
		reverse(ts.begin(),ts.end());
		if(flag==1) 
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		FOR(i,(int)ts.size()) 
		{
			cout<<ts[i]<<endl;
		}
	}
	return 0;
}