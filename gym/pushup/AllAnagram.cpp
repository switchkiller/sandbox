class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash[255] = {0};

        for(int i = 0; i < p.length(); i++){
            hash[p[i]]++;
        }
        vector<int> result;
        int count = 0, start = 0, n = s.length(), m = p.length();
        for (int end = 0; end < n; end++){
            hash[s[end]]--;
            if (hash[s[end]] >= 0){
                if (count == 0) start = end;
                count++;
            } else{
                while(hash[s[end]] < 0 && start <= end){
                    hash[s[start]]++;
                    if (hash[s[start]] > 0) count--;
                    start++;
                }
            }
            //cout << start << " " << end << " " << count << endl;

            if (count == m){
                result.push_back(start);
            }
        }
        return result;
    }
};
