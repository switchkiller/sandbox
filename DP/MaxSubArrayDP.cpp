#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define REP(a,b) for (int i = (a); i < (b); i++)
int MaxSubArray(int arr[], int size){
  int e=0, s=0;
  REP(0, size){
    e = e + arr[i];
    if (e < 0)
      e = 0;
    if (e > s)
      s = e;
  }
  return s;
}
int main(){
  int arr[MAX], t, n;
  cin >> t;
  while (t--){
    cin >> n;
    memset(arr, 0, sizeof arr);
    REP(0,n)
      cin >> arr[i];
    cout << MaxSubArray(arr, n);
  }
}
