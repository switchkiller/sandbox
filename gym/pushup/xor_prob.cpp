/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long int A[n+1], B[n+1], C[n+1];
    for(int i = 0; i < n; i++)
        cin >> A[i];

    for(int i = 0; i < n; i++)
        cin >> B[i];

    for(int i = 0; i < n; i++)
        cin >> C[i];

    long long int final_ans = 0; int j = 0;
    for (int i = 0; i < n; i++){
        bool temp[35];
        for (int j = 0; j <= 30; j++){
            temp[j] = false;
            long long int x = 1 << j;
            if (C[i] & x){
                temp[j] = true;
            }
        }

        int set_bit = 0;
        j = 0;
        while(temp[j] == false){
            j++;
        }
        set_bit = j;
        long long int k = A[i] ^ B[i];
        long long int ans = 0;
        int flag = false;
        for(j = 0; j <= 30; j++){
            long long int t = 1 << j;
            if (temp[j] == false){
                // can do nothing, bit is set
                if (k & t){
                    // do something when kth bit is 1
                    ans |= 1 << j;
                } else {
                    // do something when kth bit is 0
                }
            }
            else {
                if (k & t){
                    // do something when kth bit is 1
                    ans |= 1 << j;
                } else {
                    // do something when kth bit is 0
                    ans |= 1 << j;
                    flag = true;
                }
            }
        }
        if (flag == false){
            ans -= 1 << set_bit;
        }
        final_ans += ans;
    }
    cout << final_ans << endl;
    return 0;
}
