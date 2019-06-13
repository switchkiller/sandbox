#include <iostream>
using namespace std;
int arr[105], dp[105];


//recursive
int func(int n){
    if (n == 1) return arr[0];
    int ans = -1;
    for (int i = 1; i <= n-1; i++){
        int res = max(arr[n-1],func(i)+func(n-i) );
        ans = max(ans, res);
    }
    return ans;
}


// DP approach
int funcdp(int n){
    if (dp[n-1] != 0) return dp[n-1];
    for (int i = 1; i <= n/2; i++){
        int res = max(arr[n-1],funcdp(i)+funcdp(n-i) );
        dp[n-1] = max(dp[n-1], res);
    }
    return dp[n-1];
}

int main() {
	//code
	int t;
	cin >> t;
	while (t--){
	   int n;
	   cin >> n;
	   for (int i = 0; i < n; i++)
	       dp[i] = 0, arr[i] = 0;
	   for (int i = 0; i < n; i++) cin >> arr[i];
	   dp[0] = arr[0];
	   cout << funcdp(n) << endl;
	}
	return 0;
}
