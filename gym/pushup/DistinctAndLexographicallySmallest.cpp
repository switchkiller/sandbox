class Solution {
public:
    string distinctAndLexSmall(string s) {
        string result = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        int hash[255] = {0};
        int start = 0, n = s.length();
        int k = 0;
        for (int end = 0; end < n; end++){
            if (hash[s[end]] == 0){
                k++;
                hash[s[end]] = 1;
            }
        }

        int count = 0;
        for(int end = 0; end < n; end++){

            hash[s[end]]--;
            if (hash[s[end]] < 0){
                // do something as end idx is repeating
                while(hash[s[end]] < 0 && start <= end){
                    hash[s[start]]++;
                    if (hash[s[start]] > 0) count--;
                    start++;
                }
            } else{
                count++;
            }

            if (count == k){
                if (result > s.substr(start,k))
                    result = s.substr(start,k);
            }
        }
        return result;
    }
};
