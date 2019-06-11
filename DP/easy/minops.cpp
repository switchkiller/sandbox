#include <iostream>
using namespace std;

// start from n=0, perform 2 ops.
// base case n == N return 0, and recursively add 1.
// choose with min ops taken

int inf = 0x3f3f3f;
int dp[10007];
int minops(int n, int N){
    if (n > N) return inf;
    if (n == N) return 0;
    return min(minops(n+1,N),minops(n*2,N)) + 1;
}

// second recursive approach
int minops2(int n){
  if (n < 0) return inf;
  if (n == 0) return 0;
  int temp1 = inf, temp2 = inf;
  if (n%2 == 0)
    temp1 = minops2(n/2);
  temp2 = minops2(n-1);
  return min(temp1, temp2)+1;
}

int minopsdp(int n, int N){
    if (n > N) return inf;
    if (dp[n] != -1) return dp[n];
    dp[n] = min(minopsdp(n+1, N), minopsdp(n*2,N)) + 1;
    return dp[n];
}

int main() {
	//code
	int t, N;
	cin >> t;
	while(t--){
	    cin >> N;
	    for(int i = 0; i < N+1; i++) dp[i] = -1;
	    dp[N] = 0;
	    cout << minopsdp(1,N)+1 << endl;
	    // cout << minops2(N) << endl;
	}
	return 0;
}
