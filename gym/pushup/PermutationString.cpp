class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int hash[26] = {0};
        int m = s1.length(), n = s2.length();
        for (int i = 0; i < m; i++){
            hash[s1[i]-97]++;
        }
        int start = 0, count = 0;
        for(int end = 0; end < n; end++){
            int end_idx = s2[end]-97;
            if (hash[end_idx] > 0){
                if (count == 0) start = end;
                count++;
                hash[end_idx]--;
            }
            else{
                while(start <= end){
                    int start_idx = s2[start]-97;
                    hash[start_idx]++;
                    count--;
                    start++;
                    if (hash[end_idx] > 0) break;
                }
                if (hash[end_idx] > 0){
                    if (count == 0) start = end;
                    count++;
                    hash[end_idx]--;
                }
            }

            if (count == m) return true;
        }
        return false;
    }
};
