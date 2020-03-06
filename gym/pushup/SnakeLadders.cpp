// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    vector<vector<int>> adjList(101);

    // build the board
    // for (int i = 1; i < 100; i++){
    //     adjList[i].push_back(i+1);
    // }
    for (int i = 0; i < ladders.size(); i++){
        int u = ladders[i][0], v = ladders[i][1];
        adjList[u].push_back(v);
    }
    for (int i = 0; i < snakes.size(); i++){
        int u = snakes[i][0], v = snakes[i][1];
        adjList[u].push_back(v);
    }

    int dp[101] = {0};
    bool isPresent[101] = {false};
    queue<int> q;
    q.push(1);
    isPresent[1] = true;
    dp[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++){
            int next = cur+i;
            if (next <= 100){
                if (isPresent[next] == false){
                    isPresent[next] = true;
                    dp[next] = dp[cur] + 1;
                    bool flag = false;
                    for (auto adj : adjList[next]){
                        flag = true;
                        isPresent[adj] = true;
                        dp[adj] = dp[next];
                        q.push(adj);
                    }
                    if (!flag) q.push(next);
                }
            }
        }
    }
    if (dp[100] == 0) return -1;
    return dp[100];
}
