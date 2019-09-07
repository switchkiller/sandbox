class Solution {
public:
    bool visited[1000];
    vector<int> graph[26];
    bool visited2[1000];
    bool valid;
    string dfs(int cur){
        visited[cur] = true;
        visited2[cur] = true;
        string result;
        for (auto it : graph[cur]){
            if (visited2[it]){
                valid = false;
                return "";
            }
            if (!visited[it]){
                result += dfs(it);
            }
        }
        visited2[cur] = false;
        char curr = cur+97;
        result += curr;
        return result;
    }

    string alienOrder(vector<string>& words) {
        valid = true;
        string prev_word = "";
        int start = -1;
        for (int i = 0; i < words.size();i++){
            string current_word = words[i];
            if (prev_word != ""){
                //do something
                int x = 0;
                while(current_word[x] == prev_word[x]) x++;
                if (x == current_word.length() && x == prev_word.length()){
                    // Invalid case

                }
                else if(){
                    // do something
                }
                graph[prev_word[x]-97].push_back(current_word[x]-97);
            } else{
                start = current_word[0]-97;
            }
            prev_word = current_word;
        }
        string out = dfs(start);
        if (valid)
            reverse(out.begin(), out.end());
        else
            out = "";
        return out;
    }
};
