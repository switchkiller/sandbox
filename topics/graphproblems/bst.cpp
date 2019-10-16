/*---------------------
| Author: switchkiller |
----------------------*/


#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    bool arr[n][n];
    memset(arr,0,n*n*sizeof(bool));
    for(int i=0;i<=m;i++){
      int a,b;
      cin>>a>>b;
      arr[a-1][b-1]=1;
      arr[b-1][a-1]=1;
    }
    queue<int> qu;
    int str,temp;
    cin>>str;
    temp=str-1;
    bool vstd[n];
    memset(vstd,0,n*sizeof(bool));
    qu.push(str-1);
    int dis[n];
    memset(dis,-1,n*sizeof(int));
    dis[str-1]=0;
    while (!qu.empty()){
      str=qu.front;
      qu.pop();
      for(int i=0;i<n;i++){
        if(arr[str][i] && vstd[i]==0){
          vstd[str]=1;
          qu.push(i);
          if (dis[i]==-1 || dis[i]>(dis[str]+6))
            dis[i]=dis[str]+6;
        }
      }
      for (int i=0;i<n;i++){
        if(i!=temp)
          cout<<dis[i]<<" ";
        cout<<endl;
      }
    }
  }
}
