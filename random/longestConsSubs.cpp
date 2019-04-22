#include<map>
vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]] = true;
    int maxLen = -1, startAt=-1;
    for (int i = 0; i < n; i++){
        if (mp[arr[i]]){
            int count = 1, str = arr[i];
            int x = 1;
            while(mp[arr[i]-x]){ x++; count++; str = arr[i]-x; mp[arr[i]-x] = false;}
            x = 1;
            while (mp[arr[i]+x]){ x++; count++; mp[arr[i]-x] = false;}
            if (count > maxLen) {startAt = str; maxLen = count;}
            mp[arr[i]] = false;
        }
    }
    for (int i = startAt; i <= maxLen; i++) cout << i << endl;
}
