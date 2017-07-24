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
#define FOR(i,f_limit) for(long long int i=0;i<f_limit;i++)
#define FR(i,s_limit,f_limit) for(long long int i=s_limit;i<f_limit;i++)
typedef long long int ll; 
typedef vector<long long int> vi;
typedef vector<vi> vii;

vi dep,kaddu;
vii v;
ll pappu,lallu,temp;
ll dfs(ll pappu)
{
	dep[pappu]=1;
	for(ll i=0;i<(ll)v[pappu].size();i++)
	{
		lallu=v[pappu][i];
		if(dep[lallu]==0) dfs(lallu);
	}
	kaddu.push_back(pappu);
}
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	while(cin>>n)
	{
		if(n==0) break;
		v.assign(n+1,vi());
		ll num;
		while(cin>>num)
		{
			if(num==0) break;
			// cout<<num;
			while(1)
			{
				cin>>temp;
				if(temp==0) break;
				v[num].push_back(temp);
			}						 
		}
		ll x ;
		cin>>x;
		FOR(i,x)
		{
			cin>>pappu;
			dep.assign(n+1,0);
			kaddu.assign(n+1,0);
			dfs(pappu);  
			ll f=0;
			ll arr[n],kk=0;
			FR(i,1,n+1)
			{
				if(dep[i]==1) 
				{
					FOR(j,(ll)v[i].size()) 
					{
						if(v[i][j]==pappu)
						{
							f=1;
							break;
						}
					}
					if(f==1) break;
				}
			}
			FR(i,1,n+1) 
			{
				if(f==0 && i==pappu) arr[kk++]=i;
				if(dep[i]==0) arr[kk++]=i;
			}
			cout<<kk;
			FOR(i,kk) 
			{
				cout<<" "<<arr[i];
				// if(i+1!=kk) cout<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}