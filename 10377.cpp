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
string s;
ll x,y,n,m;
string a[61];
char dir='N';

void right()
{
	if(dir=='N') dir='E';
	else if (dir=='E') dir='S';
	else if(dir=='W') dir='N';
	else if(dir=='S') dir='W';
}
void left()
{
	if(dir=='N') dir='W';
	else if (dir=='E') dir='N';
	else if(dir=='W') dir='S';
	else if(dir=='S') dir='E';
}
void fwd()
{
	if(dir=='N')
	{
		if(a[x-1][y]!='*') x-=1;
	}
	else if(dir=='E')
	{
		if(a[x][y+1]!='*') y+=1;
			
	}
	else if(dir=='S')
	{
		if(a[x+1][y]!='*') x+=1;
	}
	else if(dir=='W')
	{
		if(a[x][y-1]!='*')  y-=1;
	}
	// cout<<x<<" "<<y<<endl;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		getline(cin,s);
		FOR(i,n)
		{
			getline(cin,s);
			a[i]=s;
		}
		cin>>x>>y;
		x--;
		y--;
		char c;
		dir='N';
		while(cin>>c)
		{
			if(c=='R') right();
			else if(c=='L') left();
			else if(c=='F') fwd();
			else if(c=='Q') 
			{
				cout<<x+1<<" "<<y+1<<" "<<dir<<endl;
				break;
			}
		}
	if(t!=0) cout<<endl;
	}
	return 0;
}