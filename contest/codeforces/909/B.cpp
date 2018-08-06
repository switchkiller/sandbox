#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

#define endl '\n'
#define ll long long
#define neg_inf (ll) -1e18

#define max_size 107

ll n;
ll ans;
ll d[max_size];

int main() {
	ios_base::sync_with_stdio(0);

	cin >> n;
	ans = neg_inf;

	for (ll i=0; i < n; i++) {
		for (ll j=i+1; j <= n; j++) {
			for (ll k=i + 1; k <= j; k++) {
				d[k]++;
			}
		}
	}

	for (ll i=0; i <= n; i++) {
		ans = max(ans, d[i]);
	}

	cout << ans << endl;

	return 0;
}
