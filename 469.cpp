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

int n,x,y,m;
string a[101],s;
int dr[]={1,1,0,-1,-1,-1, 0, 1};
int dc[]={0,1,1, 1, 0,-1,-1,-1};
int floodfill(int r, int c, char c1, char c2)
{
	if(r>=n|| r<0 || c>=m || c<0) return 0;
	if(a[r][c]!=c1) return 0;
	int ans=1;
	a[r][c]=c2;
	FOR(i,8)
	{
		ans+=floodfill(r+dr[i],c+dc[i],c1,c2);
	}
	return ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	getline(cin,s);
	getline(cin,s);
	cout<<s;
	while(t--)
	{
		n=0;
		while(getline(cin,s))
		{
			if(s.length()==0) break;
			if(s[0]=='W'|| s[0]=='L') 
			{
				a[n++]=s;
				m=a[0].length();
			}
			else 
			{
				stringstream ss(s);
				ss>>x>>y;
				x--;
				y--;
				FOR(i,n)
				{
					FOR(j,m) if(a[i][j]=='*') a[i][j]='W';
				}
				cout<<floodfill(x,y,'W','*')<<endl;
			}

		}		
		if(t>0) cout<<endl;

	} 

	return 0;
}