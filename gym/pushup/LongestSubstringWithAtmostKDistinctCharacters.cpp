// O(n) solution beats 99.99% TC and 100% SC.
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int hash[256] = {0};
        if (k == 0) return 0;
        if (k >= s.length()) return s.length();
        int count = 0, start = 0, n = s.length();
        int maxVal = 0;
        for (int end = 0; end < n; end++){
            int end_idx = s[end];
            if (hash[end_idx] == 0){
                // do something end is not present in window
                if (count == k){
                    // perform shift operation
                    while(true){
                        int start_idx = s[start];
                        hash[start_idx]--;
                        start++;
                        if (hash[start_idx] == 0) break;
                    }
                    count--;
                }
                if (count == 0) start = end;
                count++;
                hash[end_idx]++;
            } else{
                hash[end_idx]++;
            }
            if (count <= k){
                // cout << end << " " << start << endl;
                maxVal = max(maxVal, end-start+1);
            }
        }
        return maxVal;
    }
};
