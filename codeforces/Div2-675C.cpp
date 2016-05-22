// TC - O(N)
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	map<long long, int> val;
	long long sum=0;
	int ans=N-1;
	for (int i = 0; i < N; i++){
		int v;
		cin >> v;
		sum += v;
		val[sum]++;
		ans = min(ans, N-val[sum]);
	}
	cout << ans << endl;
	return 0;
}