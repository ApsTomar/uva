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

int dp[200][200],arr[205];
int fun(int left,int right)
{
  if(left+1==right) return 0;
  if(dp[left][right]!=-1) return dp[left][right];
  int ans=INF;
  for(int i=left+1;i<right;i++)
    ans=min(ans,fun(left,i)+fun(i,right)+(arr[right]-arr[left]));
    return dp[left][right]=ans;
  
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int len,n;
while(1)
{
  cin>>len;
  if(len==0) break;
  SET(dp);
  arr[0]=0;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>arr[i];
    arr[n+1]=len;
    cout<<"The minimum cutting is "<<fun(0,n+1)<<"."<<endl;;
}

  return 0;
}