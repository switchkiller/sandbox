// 40/48 pass..is it a good solution O(n) runtime
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int start = 0, n = A.size(), changed_to_zero_cnt = 0;
        int maxVal = INT_MIN;
        int prev_start = 0;
        if (K == 0){
          // handle special case
            return -1;
        }
        for (int end = 0; end < n; end++){
            if (A[end] == 0){
                changed_to_zero_cnt++;
            }
            else {
                maxVal = max(maxVal, end-prev_start+1);
            }
            if (changed_to_zero_cnt == K){
                if (maxVal < (end-start+1)){
                    maxVal = end-start+1;
                    //cout << start << " " << end << endl;
                }
                prev_start = start;
                while(A[start] != 0 && start < end){
                    start++;
                }
                start+=1;
                changed_to_zero_cnt--;
            }
        }
        return maxVal;
    }
};
