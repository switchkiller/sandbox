// Graph connectivity - UVa 459
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define MAXN 26
#define REP(i,v) for (int i = 0; i < v; i++)
#define All(X) X.begin(), X.end()
#define TRvii(c, itr) for (vii::iterator itr = (c).begin(); itr != (c).end(); itr++)
#define BLACK 1
#define WHITE 0
typedef pair<int, int> ii;
typedef vector<int> vii;
vii AdjList[MAXN];
int count = 0;
int dfs_num[MAXN];
void addedge(int x, int y){
    AdjList[x].push_back(y);
    AdjList[y].push_back(x);
}
void initializer(int v){
  REP(i,v)
    dfs_num[i] = WHITE;
}
void DFS(int v){
    dfs_num[v] = BLACK;
    TRvii(AdjList[v],itr){
        if (dfs_num[*itr] == WHITE)
            DFS(*itr);
    }

}
int main(){
    int n, ver;
    string str;
    char top, a, b;
    scanf("%d\n",&n);
    while(n--){
        scanf("%s\n",&top);
        ver = top - 'A';
        //AdjList.resize(ver+1);
        initializer(ver+1);
        while (true){
                getline(cin,str);
                if (str == "") break;
                a = str[0] - 'A';
                b = str[1] - 'B';
                addedge(a,b);
        }
        REP(i, ver+1)
            if (dfs_num[i] == WHITE){
                count++;
                DFS(i);
            }
    }
    printf("%d\n",count);
}
