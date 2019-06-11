#include <iostream>
using namespace std;

//Recursive
int jump(int n){
    if (n < 0) return 0;
    if (n == 0) return 1;
    return jump(n-1)+jump(n-2)+jump(n-3);
}

// Dynamic
int dp[51], dom[3];
int jump(int n, int x){
    if (dp[n] != 0) return dp[n];
    for (int i = 0; i < x; i++){
        if (n-dom[i] >= 0)
            dp[n] += jump(n-dom[i],x);
    }
    return dp[n];
}

int main() {
	//code
	int t, n;
	cin >> t;
	dom[0] = 1, dom[1] = 2, dom[2] = 3;
	while(t--){
	    dp[0] = 1;
	    for (int i = 1; i < 51; i++) dp[i] = 0;
	    cin >> n;
	    jump(n,3);
	    cout << dp[n] << endl;
	}
	return 0;
}
