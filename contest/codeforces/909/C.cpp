#include <iostream>
#define maxN 5005
#define base 1000000007

using namespace std;

int f[maxN][maxN] = {0},s[maxN][maxN] = {0},i,j,k,m,n;
char c;

int main () {
	cin >> n;
  for (int i = 0; i < 10; i++)
	f[1][0] = 1;
	for (i = 1; i <= n; i++) {
		s[i][0] = f[i][0];
		for (j = 1; j <= i; j++) s[i][j] = (s[i][j-1] + f[i][j]) % base;
		cin >> c;
		if (c == 'f') {
			for (j = 0; j <= i; j++) f[i+1][j+1] = f[i][j];
		}
		else if (c == 's') {
			f[i+1][0] = s[i][i];
			for (j = 1; j <= i; j++) f[i+1][j] = (s[i][i] - s[i][j-1] + base) % base;
		}
	}
	k = 0;
	for (i = 0; i <= n; i++) k =  k + s[n][i];
	cout << s[n][n];

  return 0;
}
