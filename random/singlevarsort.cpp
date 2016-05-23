#include<iostream>
using namespace std;

int main(){
	int arr[10];
	for (int i = 0; i <= 3; i++)
		cin >> arr[i];
	for (int i = 0; i <= 2; i++){
		arr[i]=arr[i] ^ arr [i+1];
		arr[i+1]=arr[i] ^ arr[i+1];
		arr[i]=arr[i] ^ arr [i+1];
	}
	for (int i = 0; i <= 3; i++)
		cout << " " << arr[i];
	return 0;
}