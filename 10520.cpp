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
ll dp[25][25];
int n,xy;
ll fun(ll i,ll j)
{
  if(dp[i][j]!=-1) return dp[i][j];
  if(i<j)
  {
    ll a1=0;
    for(ll k=i;k<j;k++)
      a1=max(a1,fun(i,k)+fun(k+1,j));
    dp[i][j]=a1;
  }
  else
  {
    ll a1=0;
    if(i<n)
    {
      for(ll k=i+1;k<=n;k++)
        a1=max(a1,fun(k,1)+fun(k,j));
    }
   ll a2=0;
   if(j>1)
   {
    for(ll k=1;k<j;k++)
      a2=max(a2,fun(i,k)+fun(n,k));
   }
       dp[i][j]=a1+a2;  
    }
    return dp[i][j];
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 while(scanf("%d %d",&n,&xy)==2)
 {
  SET(dp);
  dp[n][1]=xy;
  cout<<fun(1,n)<<endl;
 }





return 0;
}