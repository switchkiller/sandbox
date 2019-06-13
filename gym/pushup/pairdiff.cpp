#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while (t--){
    	int n, k;
    	cin >> n;
    	int arr[n];
    	for (int i = 0; i < n; i++){
    	    cin >> arr[i];
    	}
    	cin >> k;
    	sort(arr,arr+n);
    	int sum = 0;
    	for (int i = n-1; i >= 1; i--){
    	    if (arr[i] - arr[i-1] < k){
    	        sum += arr[i] + arr[i-1];
    	        i--;
    	    }
    	}
    	cout << sum << endl;
	}
	return 0;
}
