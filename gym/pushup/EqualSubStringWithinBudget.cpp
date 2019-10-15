// Runtime: 12 ms, faster than 80.19% of C++ online submissions for Get Equal Substrings Within Budget.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Get Equal Substrings Within Budget.

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0, n = s.length();
        int maxVal = 0;
        if (s == t) return n;
        int current_window_cost = 0;
        for (int end = 0; end < n; end++){
            current_window_cost += abs(s[end]-t[end]);
            if (abs(s[end] - t[end]) > 0){
                if (current_window_cost <= maxCost){
                    if (current_window_cost == 0){
                        start = end;
                    }

                } else{
                        while(current_window_cost > maxCost
                               && start <= end){
                            current_window_cost -= abs(s[start]-t[start]);
                            start++;
                        }
                        if (current_window_cost == 0){
                            continue;
                        }
                }
            }

            if (current_window_cost <= maxCost){
                maxVal = max(maxVal, end-start+1);
            }
        }
        return maxVal;
    }
};
