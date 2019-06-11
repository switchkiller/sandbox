#include <iostream>
using namespace std;

// if we reach [0,0] from [m,n] then path is valid
int numpath(int m, int n){
    if (m < 0 || n < 0) return 0;
    if (m == 0 && n == 0) return 1;
    return numpath(m-1,n)+numpath(m,n-1);
}

int dp[16][16];
int numpathdp(int m, int n){
  if (m < 0 || n < 0) return 0;
  if (dp[m][n] != 0) return dp[m][n];
  if ((m >=0) && (n >= 0))
    dp[m][n] = numpathdp(m-1,n)+numpathdp(m,n-1);
  return dp[m][n];
}

int main() {
	//code
    int t,n, m;
    cin >> t;
    while (t--){
        cin >> m >> n;
        for (int i = 0; i < 16; i++)
          for(int j = 0; j < 16; j++) dp[i][j] = 0;
        dp[0][0] = 1;
        cout << numpathdp(m-1,n-1) << endl;
    }
	return 0;
}
