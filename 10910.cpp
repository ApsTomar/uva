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

int dp[105][105];

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin>>tc;
  while(tc--)
  {
  int i, j, split, N, K,n,k,p;
cin>>n>>k>>p;
  memset(dp, 0, sizeof dp);

  for (i = 0; i <= k; i++)
    dp[i][1] = 1;

  for (j = 1; j < k; j++) 
    for (i = p; i <= k; i++)
      for (split = p; split <= k - i; split++) {
        dp[i + split][j + 1] += dp[i][j];
        
      }


cout<<dp[k][n]<<endl;

}



return 0;
}