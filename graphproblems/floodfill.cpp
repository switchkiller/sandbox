#include<iostream>

using namespace std;

#define V 10
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
#define DFS_WHITE -1
#define DFS_BLACK 1

int dfs_num[V]; 

int main(){
    int numComponent = 0;
    REP(i,0,V-1)
      if (dfs_num[i] == DFS_WHITE)

}
