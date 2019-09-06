/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>

using namespace std;

int main(){
    map<string, int> mp1, mp2;

    int n;
    cin >> n;
    if (n == 1) return 0;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp1[s]++;
        reverse(s.begin(),s.end());
        mp2[s]++;
    }

    int count = 0;

    for (map<string,int>::iterator itr = mp1.begin(); itr != mp1.end(); itr++){
        if (mp2[itr->first] != 0){
            count += (itr->second * mp2[itr->first]);
            string temp = itr->first;
            reverse(temp.begin(),temp.end());
            mp1.erase(temp);
        }
    }

    cout << count << endl;


    return 0;
}
