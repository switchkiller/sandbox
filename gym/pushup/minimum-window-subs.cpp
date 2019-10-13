class Solution {
public:
    string minWindow(string s, string t) {
      int start = 0;
      int maxLen = INT_MIN, m = s.length(), n = t.length();
      int hash[256] = {0};
      if (m == 0 || n == 0) return "";
      for (int i = 0; i < n; i++){
        hash[t[i]]++;
      }
      int count = 0, maxIdx = 0;
      for (int end = 0; end < m; end++){
          hash[s[end]]--;
          if (hash[s[end]] >= 0){
              count++;
          }
          while(count == n){
            if (maxLen > (end-start+1)){
              maxLen = end-start+1;
              maxIdx = start;
            }
            hash[s[start]]++;
            if (hash[s[start]] > 0) count--;
            start++;
          }
      }
      return s.substr(maxIdx, maxLen);
    }
};
