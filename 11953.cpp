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

int n,x,y,m,f,answer,cnt;
char a[101][101];
int dr[]={1,1,0,-1,-1,-1, 0, 1};
int dc[]={0,1,1, 1, 0,-1,-1,-1};
int floodfill(int r, int c, char c1, char c2, char c3)
{
	if(r>=n|| r<0 || c>=n || c<0) return 0;
	if(a[r][c]!=c1 && a[r][c]!=c2) return 0;
	int ans=1;
	if(a[r][c]=='x') f=1;
	a[r][c]=c3;
	for(int i=0;i<8;i+=2)
	{
		ans+=floodfill(r+dr[i],c+dc[i],c1,c2,c3);
	}
	return ans;
}
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	ll z=1;
	while(t--)
	{
		cin>>n;
		cnt=0;
		FOR(i,n)
		{
			FOR(j,n) cin>>a[i][j];
		}
		FOR(i,n)
		{
			FOR(j,n)
			{
				if(a[i][j]=='x' || a[i][j]=='@')
				{
					f=0;
					answer=floodfill(i,j,'x','@','#');
					if(f==1) cnt++;
				}
				
			}
		}
		cout<<"Case "<<z++<<": "<<cnt<<endl;
	}
	return 0;
}