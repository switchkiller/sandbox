struct mycomp{
    bool operator()(pair<int, string> a, pair<int, string> b){
        if (a.first == b.first){
            // cout << "Comparing " << a.second << " " << b.second << endl;
            return a.second < b.second;
        }
        return a.first > b.first;
    }
    };

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto word : words){
            mp[word]++;
        }

        priority_queue<pair<int,string>,vector<pair<int,string> >, mycomp > pq;

        for (auto mpitr : mp){
            pq.push({mpitr.second, mpitr.first});
            if (pq.size() > k){
                pq.pop();
            }
        }

        vector<string> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());

        return res;

    }
};
