// Subset sum 1D solution.

#include<iostream>
#include<stdio.h>

#define MAX 1000
using namespace std;

bool dp[MAX];

bool subsetSum(int arr[], int n, int k){
  dp[0] = 1;

  for (int i = 0; i <= n; i++)
    for (int j = k; j >= arr[i]; j--)
      dp[j] |= dp[j-arr[i]];

  if (dp[k] == true) return true;
  return false;
}

int main(){
  int arr[] = {1,3,2,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = 5;
  cout << subsetSum(arr, n-1, k);

  return 0;
}
