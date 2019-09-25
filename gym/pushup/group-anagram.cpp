class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> str = strs;
        for (string &s: str)
            sort(s.begin(),s.end());
        map<string, vector<string> > mp;

        for (int i = 0; i < str.size();i++){
            mp[str[i]].push_back(strs[i]);
        }
        vector<vector<string>> result;

        for (auto it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};
