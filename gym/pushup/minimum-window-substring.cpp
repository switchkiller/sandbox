// WA
class Solution {
public:
    string minWindow(string s, string t) {
        // the resultant string may have repeated character as well as some extra character.
        // result is minimum window which has atleast t's characters.
        if (t.length() > s.length() || t.length() == 0) return "";
        map<char, int> mp, cp;

        for (int i = 0; i < t.length(); i++){
            mp[t[i]]++;
        }

        // find match using t, if found update min window size.
        // Now search for next window, exclude first character of match to next character.

        cp = mp;

        int i = 0, j, count = 0, mn_length = INT_MAX, left = -1, right =-1;
        for (j = 0; j < s.length(); j++){
            if (mp[s[j]] != 0 && j < s.length()) {
                if (cp[s[j]] > 0) count++;
                cp[s[j]]--;
            }
            if (count == t.length()){
                if (mn_length > (j-i+1)) {
                    mn_length = j-i+1;
                    left = i, right = j;
                }
                if (mp[s[i]] !=0){
                    if (cp[s[i]] >= 0)  count -= 1;
                    cp[s[i]]++;
                }
                i++;
                while ((cp[s[i]] < 0 || mp[s[i]] == 0) && i <= j) i++;
            }
        }
        if (count == t.length()){
            if (mn_length > (j-i)) {
                mn_length = j-i;
                left = i, right = j-1;
            }
        }
        string result;
        for (i = left; i <= right; i++ )
            result += s[i];
        return result;
    }
};
