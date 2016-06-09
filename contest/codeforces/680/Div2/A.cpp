// A. Bear and Five Cards
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

const int INF = -1000000007;

int main(){
    int n = 5;
    int arr[n];
    REP(i,0,n)
        cin >> arr[i];
    sort(arr, arr+n);
    int max=INF;
    int temp = 0, cnt=0, smax=0, sum=0, flag;
    REP(i,0,n){
        if (temp == arr[i] && cnt < 2){
            smax += temp;
            cnt++;
            if (max < smax){
                flag = cnt;
                max = smax;
            }
        }
        else
            temp = arr[i], smax = arr[i], cnt=0;
        sum += arr[i];
    }
    if (flag == 1 || flag == 2)
        sum -= max;
    cout << sum;
    return 0;
}
