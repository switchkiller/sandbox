#include<iostream>

#define N 250
using namespace std;

int main(){
  int t, n;
  int arr[N];
  cin >> t;
  while (t--){
    cin >> n;
    int p = 0;
    for (int i = 0; i < n; i++){
      cin >> arr[i];
      p ^= arr[i];
    }
    cout << p << endl;
  }
  return 0;
}
