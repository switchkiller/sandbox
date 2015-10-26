// Problem Statement - UVa 352 Seasonal War
#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
#define MAXN 30
char a[MAXN][MAXN];
int n;
int DFS(int i, int j){
 if (i < 0 || i >= n || j < 0 || j >= n || a[i][j] != '1') return 0;
 a[i][j] = '2';
 DFS(i-1,j-1); DFS(i-1, j); DFS(i-1, j+1);
 DFS(i, j-1); DFS(i, j+1);
 DFS(i+1, j-1); DFS(i+1, j); DFS(i+1, j+1);
}
int main(){
 int count = 0, k=0;
 while(cin >> n){
 getchar();
 for (int i = 0; i < n; i++)
	 gets(a[i]);
 for (int i = 0; i < n; i++)
	 for (int j = 0; j < n; j++)
		 if (a[i][j] == '1'){
		 	count++;
			DFS(i,j);
		 }
 printf("Image number %d contains %d war eagles.\n", ++k, count);
 count = 0;
 }
 return 0;
}
