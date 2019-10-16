#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
int main(){
  int money;
  char name[20];
  priority_queue< pair<int, string> > pq;
  pair<int, string> result;
  for (int i = 0; i < 7; i++){
    scanf("%d %s", &money, name);
    pq.push(make_pair(money, name));
  }
  result = pq.top();
  pq.pop();
  printf("%s has %d $\n", ((string)result.second).c_str(), result.first);
  result = pq.top(); pq.pop();
  printf("%s has %d $\n", ((string)result.second).c_str(), result.first);
  return 0;
}
