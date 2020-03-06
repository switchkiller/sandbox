#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++){
        if (st.empty()){
            st.push(s[i]);
        } else{
            char top = st.top();
            if (top == s[i]){
                st.pop();
            } else{
                st.push(s[i]);
            }
        }
    }
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    if (res == "") return "Empty String";
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
