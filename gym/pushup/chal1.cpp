// TODO - random codeArena
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[400000];
int mark[100000];
int n,k;
lli arr[100000];
lli solve(int index)
{
  if(index >= n) return 0;
  if(mark[index]!=0)
  {
    return dp[index];
  }
 else
 {
     mark[index]=1;
     lli ret=0;
     dp[index]=max(solve(index+1),solve(index+k+1)+arr[index]);
     return dp[index];
  }
}

int main()
{
	int t;
    cin>>t;
    while(t--){
      cin>>n>>k;
      memset(dp,0,sizeof(dp));
      memset(mark,0,sizeof(mark));
      for(int i=0;i<n;i++)
         cin>>arr[i];
     lli  ans=solve(0);
     cout<<ans<<endl;
   }
}
