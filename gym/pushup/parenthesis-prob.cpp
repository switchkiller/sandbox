class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        int res = 0;
        for (int i = 0; i < S.length(); i++){
            if (S[i] == '(')
                s.push(S[i]);
            else{
                if (s.empty()){
                    res++;
                }
                else{
                    s.pop();
                }
            }
        }
        while(!s.empty()){
            res++;
            s.pop();
        }
        return res;
    }
};
