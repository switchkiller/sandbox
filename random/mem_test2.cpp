#include<bits/stdc++.h>

int main(){
	int a[10], i;
	i = 8;
	i[a] = 37;  // But what's this???
	a[i] = 42;  // Looks normal....FCUK!!!
	std::cout << "Array element = " << i[a] << std::endl;
	return 0;
}