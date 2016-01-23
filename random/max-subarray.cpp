// Using Divide and Conquer approach to solve the Maximum subarray problem
#include<bits/stdc++.h>
#define REP(a,b) for (int i = (a); i < (b); i++)
#define RREP(a,b) for (int i = (a); i > (b); i--)
#define MAX 50
using namespace std;
int maxval(int a, int b){ return (a > b) ? a : b; }
int maxval(int a, int b, int c) {return maxval(maxval(a,b),c);}
int MaxContSum(int arr[], int low, int mid, int high){
  int sum = 0;
  int left_sum = INT_MIN;
  RREP(mid,low-1){
    sum = sum + arr[i];
    if (left_sum < sum)
      left_sum = sum;
  }
  int right_sum = INT_MIN;
  sum = 0;
  REP(mid+1,high+1){
    sum = sum + arr[i];
    if (right_sum < sum)
      right_sum = sum;
  }
  return left_sum+right_sum;
}
int MaxSubArray(int arr[], int low, int high){
  if (low == high)
    return arr[low];
  int mid = (low+high)/2;
  return maxval(MaxSubArray(arr, low, mid), MaxSubArray(arr,mid+1, high), MaxContSum(arr, low, mid, high));
}
int main(){
  int t, n, arr[MAX];
  cin >> t;
  while (t--){
    cin >> n;
    memset(arr, 0, sizeof arr);
    REP(0, n)
      cin >> arr[i];
    cout << MaxSubArray(arr, 0, n-1);
  }
  return 0;
}
