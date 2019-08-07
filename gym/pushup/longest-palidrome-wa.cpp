// Attempt of solve using pruning. WA because of some tricky cases

class Solution {
public:

    bool checkPalindrome(int start, int end, string s){
        if (start < 0 || end >= s.length()) return false;
        if ( start == end || (start == end-1 && s[start] == s[end]) )  return true;
        if (s[start] != s[end]) return false;
        return checkPalindrome(start+1,end-1,s);
    }

    string longestPalindrome(string s) {
        int k = 0, maxVal = -1;
        int index = 0;
        for (int i = 0; i < s.length(); i++){
            while (1){
                if (checkPalindrome(i,i+k,s)){
                    if (maxVal < k){
                        index = i;
                        maxVal = k;
                    }
                    k += 1;
                }
                // pruning fails in this condition may not be true always
                else if (checkPalindrome(i,i+k+1,s)){
                   if (maxVal < k){
                        index = i;
                        maxVal = k+1;
                    }
                    k += 2;
                }
                else
                    break;
            }
            k = maxVal;
        }
        string st;
        for (int i = index; i <= index+maxVal; i++) st += s[i];
        return st;
    }
};
