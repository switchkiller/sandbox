class Solution {
public:
    int trap(vector<int>& height) {
        // get max to the left of i, max to right of i
        // if ith height is less than min(left[i],right[i]), then tap it. minVal-ith height
        int s = height.size();
        int left[s+1], right[s+1];
        left[0] = 0, right[s] = 0;
        for (int i = 1; i <= s; i++){
            left[i] = max(left[i-1],height[i-1]);
        }

        for (int i = s-1; i >= 0; i--){
            right[i] = max(right[i+1],height[i]);
        }

        int count = 0;

        for (int i = 0; i < s; i++){
            if (min(left[i],right[i+1]) > height[i]){
                count += (min(left[i],right[i+1]) - height[i]);
            }
        }

        return count;
    }
};
