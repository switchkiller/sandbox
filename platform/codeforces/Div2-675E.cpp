// XXX incomplete #use dp #segment tree #binaryindexing

#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

const int maxn = 1 << 18;
pair<int, int> tree[maxn*2];

void build(const vector<int> &a, int n){
	REP(i,0,n) tree[maxn+i] = {a[i],i};
	RREP(i,maxn-1,0) tree[i] = max(tree[i*2], tree[i*2+1]);
}

int get(int l, int r){
	pair<int, int> ans{-1,-1};
	for (l+=maxn, r+=maxn+1; l < r; l >>= 1, r >>= 1){
		if (l & 1) ans = max(ans, tree[l++]);
		if (r & 1) ans = max(ans, tree[--r]);
	}
	return ans.second;
}	

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	a[n-1] = n-1;
	REP(i,0,n-1){
		cin >> a[i];
		a[i]--; 
	}
	build(a,n);
	vector<long long> dp(n);
	long long ans = 0;
	dp[n-1] = 0;
	RREP(i,n-2,-1){
		int m = get(i + 1, a[i]);
		dp[i] = dp[m] - (a[i] - m) + n - i - 1;
        ans += dp[i];
	}
	
	cout << ans << endl;
	return 0;
}