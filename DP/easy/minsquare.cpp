#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int recur1(int N){
    if (N == 1 || N == 0) return N;
    int ans = INF;
    for (int x = 1; x*x <= N; x++)
        ans = min(ans, recur1(N-x*x)+1);
    return ans;
}

int dp[10005];
int recur(int N){
    if (dp[N] != INF) return dp[N];
    for (int x = 1; x*x <= N; x++)
        dp[N] = min(dp[N], recur(N-x*x)+1);
    return dp[N];
}

int main() {
	//code
	int t, N;
	cin >> t;
  for (int i = 0; i < 10005; i++) dp[i] = INF;
  dp[0] = 0; dp[1] = 1;
	while(t--){
	    cin >> N;
	    cout << recur(N) << endl;
	}
	return 0;
}
