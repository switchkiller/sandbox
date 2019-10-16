// Linear Search Approach
class Solution {
public:
    int linear_search(vector<int>& nums, int low, int high, int key){
        int idx = high-1;
        for (vector<int>::reverse_iterator it = nums.rbegin(); it != nums.rend(); it++){
            if (*it == key)
                break;
            idx--;
        }
        if (nums[idx] == key) return idx;
        else return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int cnt = 0;
        vector<int> v;
        for(auto it:nums){
            int res = linear_search(nums,0,nums.size(),target-it);
            if (res != -1 && res != cnt) {
                v.push_back(cnt);
                v.push_back(res);
                return v;
            }
            cnt++;
        }
        return v;
    }
};

// Assuming sorted array is given.
class Solution {
public:
    int binary_search(vector<int>& nums, int low, int high, int key){
        int mid;
        while (high-low > 1){
            mid = low + (high-low)/2;
            if (nums[mid] <= key)
                low = mid;
            else
                high = mid;
        }
        if (nums[low] == key) return low;
        else return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int cnt = 0;
        vector<int> v;
        for(auto it:nums){
            int res = binary_search(nums,0,nums.size(),target-it);
            if (res != -1) {
                v.push_back(cnt);
                v.push_back(res);
                return v;
            }
            cnt++;
        }
        return v;
    }
};

// Store index, sort
class Solution {
public:
    int binary_search(vector< pair<int, int> >& nums, int low, int high, int key){
        int mid;
        while (high-low > 1){
            mid = low + (high-low)/2;
            if (nums[mid].first <= key)
                low = mid;
            else
                high = mid;
        }
        if (nums[low].first == key) return nums[low].second;
        else return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< pair<int, int> > pnum;
        for (int i = 0; i < nums.size(); i++){
            pnum.push_back({nums[i], i});
        }
        sort(pnum.begin(),pnum.end());
        for(auto it:pnum){
            int res = binary_search(pnum,0,pnum.size(),target-it.first);
            if (res != -1) {
                return vector<int> {it.second, res};
            }
        }
        return vector<int> {};
    }
};
