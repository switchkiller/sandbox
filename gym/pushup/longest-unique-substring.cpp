class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int hashMap[256] = {0};
        int start = 0, n = s.length(), maxLen = -1;
        if (n == 0) return 0;
        for(int end = 0; end < n; end++){
            // if condition holds for end index
            // do something
            int idx = s[end];
            if (hashMap[idx] != 1){
                hashMap[idx] = 1;
            }  else{
               // means that already present in the window
                // check until this element can be added to hash
                while(start <= end && hashMap[idx] == 1){
                    hashMap[s[start++]] = 0;
                }
                hashMap[idx] = 1;
            }

            if (maxLen < (end-start+1)){
                maxLen = end-start+1;
            }

            // else do something
        }
        return maxLen;
    }
};

// 2nd approach
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        vector<int> dict(256, -1);
        int prev = -1;
        for (int i = 0; i < s.length(); i++){
            if (dict[s[i]] > prev)
                prev = dict[s[i]];
            dict[s[i]] = i;
            mx = max(mx, i-prev);
        }
        return mx;
    }
};
