#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)

int main(){
	int n, t;
	cin >> n >> t;
	map<int, int> mp;
	int cnt=1, val=1, d=t, res=0, mod=0;
	mp[0] = t;
	while (cnt <= n){
		REP(i,0,cnt){
				mp[mod] += d;
				cout << val << " " << d << endl;
				if (d > 0) res++;
				val++;
			}

		}
		d = (d-1)/2;
		cnt++; mod++;
	}
	cout << res;
	return 0;
}