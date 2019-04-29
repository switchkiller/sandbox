#include<stdio.h>
int minimum(int arr[],int x){
    int i;
    int min=arr[0];
    for(i=1;i<x;i++){
        if(min<arr[i]){
            min=arr[i];
        }
    }
    return min;
}
int maximum(int arr[],int x){
    int i;
    int max=arr[0];
    for(i=1;i<x;i++){
        if(max>arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    int mr[40],ev[40];
    int i;

    for(i=0;i<n;i++){
        scanf("%d",&mr[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d",&ev[i]);
    }
    int min= maximum(mr,n);
    int max= minimum(ev,m);
   // printf("%d\t%d\n",min,max);
    if(max<min){
        printf("%d\n",x);
    }
    else{
        int bal;
        bal=(x/min)*max + x%min;
        printf("%d\n",bal);
    }
    return 0;
}
