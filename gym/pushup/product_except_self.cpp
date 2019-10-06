class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        int right[n+1];
        right[n] = 1;

        for (int i = n-1; i >= 0; i--){
            right[i] = nums[i] * right[i+1];
        }

        int left = 1;

        vector<int> result;

        for (int i = 0; i < n; i++){
            result.push_back(left * right[i+1]);
            left = left * nums[i];
        }

        return result;


    }
};
