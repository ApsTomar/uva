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

map<char,int> m;
char c,ch;
string s;
int n,cnt;
vii adj;
vi dep;
int dfs(int s)
{
	dep[s]=1;
	FOR(i,(int)adj[s].size())
	{
		int u=adj[s][i];
		if(dep[u]==0) dfs(u);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0;i<26;i++)
	{
		c=(char)(i+65);
		m[c]=i;
	}
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>ch;
		n=m[ch];
		cnt=0;
		n++;
		adj.assign(n,vi());
		dep.assign(n,0);
		getline(cin,s);
		while(getline(cin,s))
		{
			if(s.length()==0) break;
			int q=m[s[0]];
			int w=m[s[1]];
			adj[q].pb(w);
			adj[w].pb(q);
		}

		FOR(i,n)
		{
			if(dep[i]==0)
			{
				dfs(i);	
				cnt++;			
			}
			
		}

		cout<<cnt<<endl;
		if(t>0) cout<<endl;
	}
	return 0;
}