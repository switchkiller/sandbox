class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int sz = matrix.size();
        int heap_size = sz*sz-k+1;

        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < sz; i++){
            for (int j = 0; j < sz; j++){
                if (pq.size() < heap_size){
                    pq.push(matrix[i][j]);
                } else {
                    if (pq.top() < matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};
