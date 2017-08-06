#include <bits/stdc++.h>
#define MAX 10005
#define INF 999999999
#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;
 typedef  int ll;
 typedef pair<int,int> ii;
 typedef vector<ii> vii;
 typedef vector <ll > vi;

int dp[20005],dp2[20005];
vii v;
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
 // ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[10],f=0,p,q,val;
  char ch;
int coins[]={5,10,20,50,100,200};
for(int i=0;i<=20000;i++)
dp2[i]=INF;
dp2[0]=0;
  for(int i=0;i<6;i++)
    {
      for(int j=coins[i];j<=20000;j++)
      dp2[j]=min(dp2[j],1+dp2[j-coins[i]]);
    }

  while(1)
  {
    int sum=0;
    for(int i=0;i<6;i++)
      cin>>arr[i],sum+=arr[i]*coins[i];
    
    if(sum==0)
      break;
    cin>>p>>ch>>q;
    val=100*p+q;
for(int i=0;i<=20000;i++)
dp[i]=INF;
dp[0]=0;
int used=0;
    for(int i=0;i<6;i++)
    {
      for(int j=sum;j>=1;j--)
      {
        for(int k=1;k<=arr[i];k++)
        {
          if(j-coins[i]*k<0) break;
          if(dp[j]>dp[j-coins[i]*k]+k)
            dp[j]=dp[j-coins[i]*k]+k;
        }

      }
    }

    
int adi=0,ans=INF;
    for(int i=val;i<=sum;i++)
        ans=min(ans,dp[i]+dp2[i-val]);
printf("%3d\n",ans);

  }
  


  return 0;
}