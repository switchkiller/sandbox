#include<iostream>
using namespace std;
int main(){
  int N, Q, k, val, cnt = 0;
  int a, b;
  cin >> N >> Q;
  int **arr;
  arr = new int*[N];
  while (N--){
    cin >> k;
    arr[cnt] = new int[k];
    for (int i = 0; i < k; i++){
      cin >> val;
      arr[cnt][i] = val;
    }
  cnt++;
  }
  while (Q--){
    cin >> a >> b;
    cout << arr[a][b] << endl;
  }
  return 0;
}
