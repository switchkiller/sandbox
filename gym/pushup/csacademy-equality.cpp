// WA - Two pointers
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; long k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	sort(arr, arr+n);
	int ptr1 = 0, ptr2 = n-1, cnt = 0;
	while (ptr1 < ptr2){
		while (abs(arr[ptr2] - arr[ptr1]) > k && ptr2 > ptr1){
		    // cout << ptr1 << " " << ptr2 << endl;
				arr[ptr1]++;
				arr[ptr2]--;
				cnt++;
			}
		if (abs(arr[ptr2]- arr[ptr1]) <= k) ptr1++;
		ptr2--;
	}

	cout << cnt << endl;
	return 0;
}
