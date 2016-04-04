#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i = (a); i < (b); i++)
typedef vector<int> vi;

vi a;


int maxSubArrayProduct(int n){
	int max_ending_here = 1;
	int min_ending_here = 1;
	int max_so_far = -10000;
	for (int i = 0; i < n; i++){

		/* a[i] is positive then max_ending_here increases more and min_ending_here decreases further (But consider case min_ending_here is 1)		*/
		if (a[i] > 0){
			max_ending_here = max_ending_here * a[i];
			min_ending_here = min(min_ending_here,1);
		}

		else if (a[i] == 0){
			max_ending_here = 1;
			min_ending_here = 1;
		}

		/* If a[i] is negative, chances are max_ending_here is maximum of product of min_ending_here * a[i] or it can be 1. 
			and min_ending_here can be less than 1 and or 1 which is possible by prev-max_ending_here * a[i].
		*/
		else{
			int temp = max_ending_here;
			max_ending_here = max(max_ending_here,1);
			min_ending_here = temp * a[i];
		}
		if (max_ending_here > max_so_far)
			max_so_far = max_ending_here;
	}

	return max_so_far;
}

int main(){
	int val;
	while (cin >> val){
		if (val == -999999){
			cout << maxSubArrayProduct(a.size()) << endl;
			a.clear();
			continue;
		}
		a.push_back(val);
	}
	return 0;
}