#include <bits/stdc++.h>
#define MAX 10005
#define INF 999999999
#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;
 typedef    int ll;
 typedef pair<int,int> ii;
 typedef vector<ii> vii;
 typedef vector <ll > vi;


int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
int dp[105][105];
CLR(dp);
for(int i=0;i<=100;i++)
  dp[i][1]=1;
for(int j=1;j<100;j++)
{
  for(int i=0;i<=100;i++)
    for(int k=0;k<=100-i;k++)
    {
      dp[i+k][j+1]+=dp[i][j];
      dp[i+k][j+1]%=1000000;
    }
}
int n,k;
while(scanf("%d %d",&n,&k)==2 && dp[n][k])
  printf("%d\n",dp[n][k]);
  return 0;
}