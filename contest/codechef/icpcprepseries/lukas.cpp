#include<bits/stdc++.h>
using namespace std;


void kth(int arr[], int n, int k)
{   int i = 0;
    sort(arr, arr+n);
    set<int> s(arr, arr+n);
    //if (k > s.size())
      cout << arr[k-1];
    // else{
    //   for (set<int>::iterator it = s.begin(); it != s.end(); it++){
    //     i++;
    //     if (i == k)
    //       cout << *it;
    // }
      //}
}
int main()
{   int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    kth(arr, n, k);
    return 0;
}
