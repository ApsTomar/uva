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

vi dep,ans,ans1;
vii adj;
ll a[101][101],u,reach[101];
ll dfs(ll s, ll check)
{
	if(s==check) return 0;
	dep[s]=1;
	for(ll i=0;i<(ll)adj[s].size();i++)
	{
		u=adj[s][i];
		// if(u==check) continue;
		if(dep[u]==0) dfs(u,check);
	}
	ans1.pb(s);
}
ll dfs2(ll s)
{
	dep[s]=1;
	for(ll i=0;i<(ll)adj[s].size();i++)
	{
		u=adj[s][i];
		if(dep[u]==0) dfs2(u);
	}
	ans.pb(s);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,z=1;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		adj.clear();
		adj.assign(n,vi());
		FOR(i,n)
		{
			FOR(j,n) 
			{
				cin>>a[i][j];
				if(a[i][j]==1) 
				{
					adj[i].pb(j);
				}
			}
		}
		dep.clear();
		dep.assign(n,0);
		ans.clear();
		dfs2(0);
		ll c=0;
		char pr[n][n];
		FOR(i,n)
		{
			FOR(j,n) pr[i][j]='N';
		}
		for(vector<ll>::iterator it=ans.begin();it!=ans.end();it++)
		{
			reach[c++]=(*it);
		}
		FOR(i,n)
		{
			ans1.clear();
			dep.assign(n,0);
			dfs(0,i);
			// for(vector<ll>::iterator it=ans1.begin();it!=ans1.end();it++) cout<<(*it)<<" ";
			// 	cout<<endl;
			FOR(j,c)
			{
				if(find(ans1.begin(),ans1.end(),reach[j])==ans1.end()) pr[i][reach[j]]='Y';
			}
		}
		cout<<"Case "<<z++<<":"<<endl;
		ll f=0;
		FOR(i,2*n)
		{
			if(f==0)
			{
				cout<<"+";
				FOR(j,2*n-1) cout<<"-";
				cout<<"+"<<endl<<"|";
			}
			else 
			{
				FOR(j,n) 
				{
					cout<<pr[i/2][j]<<"|";
				}
				cout<<endl;
			}
			f=1-f;				
		}
		cout<<"+";
		FOR(j,2*n-1) cout<<"-";
		cout<<"+"<<endl;
	
	}
	return 0;
}