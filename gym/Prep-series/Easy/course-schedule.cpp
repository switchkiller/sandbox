// Leetcode - Course Schedule
// Approach -> Using DFS, catch when loop is deteched

class Solution {
public:
    bool visited[10];
    bool visiting[10];

    bool dfs(int cur, vector<vector<int>>& prerequisites){
        if (visited[cur] == true) return true;
        visiting[cur] = true;
        visited[cur] = true;
        for(auto adj : prerequisites[cur]){
            if (visiting[adj] == true && adj != cur)
                return false;
            if (!visited[adj])
                if (dfs(adj, prerequisites) == false) return false;
        }
        visiting[cur] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        for (int node = 0; node < numCourses; node++)
         if (dfs(node, prerequisites) == false) return false;
        return true;
    }
};
