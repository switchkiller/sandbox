#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)

int main(){
	freopen("in-test.txt" , "r" , stdin);
    freopen("out-test.txt" , "w" , stdout);
	int T;
	int rem;
	long N, temp;
	long long ans;
	cin >> T;
	int arr[10];
	REP(j,0,T){
		int flag = 0, x = 1;
		cin >> N;
		if (N == 0){ 
			cout <<"Case #" << j+1 <<": " << "INSOMNIA" << endl;
			continue;
		}
		memset(arr, 0, sizeof arr );
		while (flag == 0){
			temp = N * (x++);
			// cout << "temp =" << temp << " " << "x=" << x-1 << endl;
			while (temp){
				rem = temp % 10;
				arr[rem] = 1;
				temp = temp / 10;
				// cout << rem << endl;
			}
			REP(i,0,10){
				if (arr[i] == 0){
					flag = 0;
					break;
				}
				else 
					flag = 1;
			}
		}
		cout <<"Case #" << j+1 <<": " <<  N * (--x) << endl;
	}

	return 0;
}