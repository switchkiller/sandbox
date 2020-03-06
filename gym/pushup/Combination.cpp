class Solution {
public:
    void combinePlease(int start, int end, int remain, vector<vector<int>> &res, vector<int> &temp){
        if (remain == 0){
            res.push_back(temp);
            return;
        }
        if (start == end || (end-start) < remain){
            return;
        }
        temp.push_back(start);
        combinePlease(start+1, end, remain-1, res, temp);
        temp.pop_back();
        combinePlease(start+1, end, remain, res, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        combinePlease(1,n+1,k,res,temp);
        return res;
    }
};
