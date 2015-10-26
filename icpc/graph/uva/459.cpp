//Problem Statement - UVa 459 Graph Connectivity
#include<iostream>
#include<cstdio>
#define REP(i,v) for(int i = 0; i < v; i++)
using namespace std;
#define MAXV 26
int graph[MAXV], count;
int find(int x){
    if (graph[x] == x)
      return x;
    return graph[x] = find(graph[x]);
}
void unionn(int i, int j){
    int a = find(i);
    int b = find(j);
    if (a != b){
      graph[a] = b;
      count--;
    }
}

int main(){
  int n;
  char v, temp1, temp2;
  string str;
  int ver;
  bool blank = true;
  scanf("%d", &n);
  while(n--){
    if (blank)
      printf("\n");
    blank = true;
    cin>>v;
    ver = v - 'A';
    count = ver + 1;
    REP(i, count)
      graph[i] = i; //initializer.
    cin.ignore();
    while (true){
      getline(cin, str);
      if (str == "") break;
      temp1 = str[0] - 'A';
      temp2 = str[1] - 'A';
      unionn(temp1, temp2);
    }
    cout<<count<<endl;
    count = 0;
  }
  return 0;
}
