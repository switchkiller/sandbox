class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            int t = target - nums[i];
            auto itr = mp.find(t);
            if (itr != mp.end()){
                return {i, itr->second};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
