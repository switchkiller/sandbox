// Better than 12% TC :/ Space saving approach

class Solution {
private:
    struct compare{
        bool operator()(pair<string,int> a, pair<string,int> b){
            if (a.second == b.second){
                return a.first < b.first;
            } else{
                return a.second > b.second;
            }
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto word : words){
            mp[word]++;
        }
        vector<string> result;
        priority_queue<pair<string,int> , vector<pair<string,int> >, compare > pq;

        for (auto obj : mp){
            if (pq.size() < k){
                pq.push(obj);
            } else{
                if (pq.top().second < obj.second){
                    pq.pop();
                    pq.push(obj);
                } else if (pq.top().second == obj.second){
                    if (pq.top().first > obj.first){
                        pq.pop();
                        pq.push(obj);
                    }
                }
            }
        }

        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
