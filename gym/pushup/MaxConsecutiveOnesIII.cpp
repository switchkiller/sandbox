// 43/48 pass..is it a good solution O(n) runtime
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int start = 0, n = A.size(), changed_zero_to_one_cnt = 0;
        int maxVal = 0;
        int prev_start = 0;
        if (K == 0){
          // handle special case
            for (int end = 0; end < n; end++){
                if (A[end] == 1){
                    start = end;
                    while(end+1 < n && A[end+1] == 1) end++;
                    maxVal = max(maxVal,end-start+1);
                }
            }
            return maxVal;
        }
        for (int end = 0; end < n; end++){
            if (A[end] == 0){
                changed_zero_to_one_cnt++;
            }
            else {
                maxVal = max(maxVal, end-prev_start+1);
            }
            if (changed_zero_to_one_cnt == K){
                if (maxVal < (end-start+1)){
                    maxVal = end-start+1;
                    //cout << start << " " << end << endl;
                }
                prev_start = start;
                while(A[start] != 0 && start < end){
                    start++;
                }
                start+=1;
                changed_zero_to_one_cnt--;
            }
        }
        return maxVal;
    }
};
