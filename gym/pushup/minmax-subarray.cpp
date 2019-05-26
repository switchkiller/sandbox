// https://csacademy.com/contest/archive/task/minmax_subarray/
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int cnt = 0x3f3f3f3f, ptr1 = 0, ptr2 = 0;
    int mi = 0x3f3f3f3f, mx = -0x3f3f3f3f;
    while(ptr2 < n){
        if (mi >= arr[ptr2]){
            ptr1 = ptr2++;
            mi = arr[ptr1];
            if (cnt > ptr2-ptr1) cnt = ptr2-ptr1+1;
        }
        else{
            if (mx < arr[ptr2]){
                mx = arr[ptr2];
            }
            ptr2++;
        }
        cout << ptr1 << " " << ptr2 <<endl;
    }
    cout << cnt << endl;
}
