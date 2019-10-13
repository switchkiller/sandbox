class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int start = 0, count = 0;
        if (S.length() < K) return 0;
        int hash[26];
        memset(hash,-1,sizeof hash);
        for (int end = 0; end < S.length(); end++){
            if ((end-start+1) <= K){
                int end_idx = S[end]-97;
                if (hash[end_idx] == -1){
                    hash[end_idx] = end;
                } else {
                    //cout << end << " " << hash[end_idx] << endl;
                    while(start <= hash[end_idx]){
                        int start_idx = S[start]-97;
                        hash[start_idx] = -1;
                        start++;
                    }
                    hash[end_idx] = end;
                }
            }
            if (end-start+1 == K){
                //cout <<S.substr(start, K) << endl;
                count++;
                int start_idx = S[start]-97;
                hash[start_idx] = -1;
                start++;
            }
        }
        return count;
    }
};
