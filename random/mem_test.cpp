// Clarifying my doubts with memory
// g++ -o mem_test -fstack-protector-all mem_test.cpp not detecting seg fault

#include<bits/stdc++.h>
using namespace std;
#define MAX 5

int fun[MAX];
int N; //= 23;

void func(){
	// for (int i = 4; i++ <= N; i-- ){
	// 	cin >> fun[i];
	// 	cout << fun[i] << " " << i << endl;
	// 	cout << N << " "  << endl;
	// }
	for (int i = 4; i <= 5 ; i++ ){
		cin >> fun[i];
		cout << fun[i] << " " << i << endl;
		cout << N << " "  << endl;
	}
}

int main(){
	// funcfunc();
	N = 5;
	// N = 65;
	func();
	// cout << N << " " << fun[07] << " " << fun[5] << " " << fun[6] << endl;
	return 0;
}