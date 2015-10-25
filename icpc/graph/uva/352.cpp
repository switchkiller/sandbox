// Problem Statement - UVa 352 Seasonal War
#include<iostream>
#define MAXN 30
int a[MAXN][MAXN];
int DFS(int i, int j){
 if (i < 0 || i > n || j < 0 || j > n) return; 
 a[i][j] = '2';
 DFS(i-1,j-1); DFS(i-1, j); DFS(i-1, j+1);
 DFS(i, j-1); DFS(i, j+1);
 DFS(i+1, j-1); DFS(i+1, j); DFS(i+1, j+1);
}
int main(){
 int n, count = 0, k=0;
 while(cin>>n){
 for (int i = 0; i < n; i++)
	 gets(a[i]);
 for (int i = 0; i < n; i++)
	 for (int j = 0; j < n; j++)
		 if (a[i][j] == '1'){
		 	count++;
			DFS(i,j);
		 }
 }
 printf("Image number %d contains %d war eagles.\n", ++k, count);
}
