class Solution {
public:
    void generateParenthesisUtils(int open, int close,int limit, string temp,vector<string> &res){
        if (open >= limit || close >= limit) return;
        if (open+close  == 2 * (limit-1)){
            res.push_back(temp);
            return;
        }
        if (open > close && close+1 < limit){
            generateParenthesisUtils(open,close+1,limit,temp+")",res);
        }
        if (open+1 < limit)
            generateParenthesisUtils(open+1,close,limit,temp+"(",res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisUtils(0,0,n+1,"",res);
        return res;
    }
};
