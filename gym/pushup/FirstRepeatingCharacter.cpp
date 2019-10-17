class Solution {
public:
    int firstRepeatingChar(string s) {
        int minIndex = INT_MAX;
        int n = s.length();
        int hash[255] = {-1};
        for (int end = 0; end < n; end++){
            if (hash[s[end]] != -1){
                minIndex = min(minIndex, hash[s[end]]);
            }
            hash[s[end]] = end;
        }
        return minIndex;
    }
};
