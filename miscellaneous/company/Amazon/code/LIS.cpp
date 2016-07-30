#include<bits/stdc++.h>
#define N 100
using namespace std;

int dp[N]; // Store the lis upto i

void lis(int arr[], int n){
  for (int i = 0; i < n; i++)
    dp[i] = 1;

  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;

  int max  = 0;
  for (int i = 0; i < n; i++)
    if (max < dp[i]) max = dp[i];

  cout << max;
}

int main(){
  int arr[] = { 10, 22, 31, 33, 24, 25, 26};
  int n = sizeof(arr)/sizeof(arr[0]);
  lis(arr,n);
  return 0;
}
