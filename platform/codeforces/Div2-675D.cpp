#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	set<int> numbers;
	map<int, int> left, right;
	int n, v;
	cin >> n >> v;
	numbers.insert(v);
	for (int i = 0; i < n-1; i++){
		cin >> v;
		set<int, int>::iterator it = numbers.upper_bound(v);
		int result;
		if (it != numbers.end() && left.count(*it) == 0){
			left[*it] = v;
			result = *it;
		}
		else{
			it--;
			right[*it] = v;
			result = *it;
		}
		numbers.insert(v);
		cout << result;

		if (i != n-2) cout << " ";
	}
	return 0;
}