#include <bits/stdc++.h>
#define MAX 1000000
#define INF 999999999
#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;
 typedef  long long  int ll;
 typedef pair<int,int> ii;
 typedef vector<ii> vii;
 typedef vector <ll > vi;

int dp[10005];
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,time;
  while(scanf("%d %d %d",&n ,&m ,&time)==3)
  {
  SET(dp);
  dp[0]=0;
  for(int i=1;i<=time;i++)
  {
    if(i>=n && dp[i-n]!=-1) dp[i]=1+dp[i-n];
    if(i>=m && dp[i-m]!=-1)
    {
      if(dp[i]<1+dp[i-m]) dp[i]=1+dp[i-m];
    }
  }
if(dp[time]!=-1)
  printf("%d\n",dp[time]);
else
{
  for(int i=time;i>=0;i--)
  {
    if(dp[i]!=-1)
    {
      printf("%d %d\n",dp[i],time-i);
      break;
    }
  }
}
}
return 0;
}