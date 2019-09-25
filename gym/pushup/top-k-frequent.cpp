class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it : mp){
            pair<int, int> p = {it.second, it.first};

            if (pq.size() < k){
                pq.push(p);
            } else {
                // check if pq top is less, remove the top
                if (pq.top().first < it.second){
                    pq.pop();
                    pq.push(p);
                }
            }
        }

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
