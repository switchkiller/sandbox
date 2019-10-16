#include <bits/stdc++.h>
using namespace std;
int arr[101];

// Greedy strategy not working
int greedy(){
  if (n % 2) arr[n++] = 0;
  sort(arr,arr+n);
  int subset1 = 0, subset2 = 0;
  for(int i = 0; i < n/2; i++){
      if (i % 2 == 0)
          subset1 += arr[i] + arr[n-i-1];
        else
            subset2 += arr[i] + arr[n-i-1];
  }
  int ans = abs(subset1-subset2);
  cout << ans << endl;
}

int main() {
	//
	int t;
	cin >> t;
	while (t--){
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; i++){
    	    cin >> arr[i];
    	}
    	//greedy();
	}
	return 0;
}
