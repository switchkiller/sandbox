class Solution {
public:
    struct myCompare{
      bool operator()(int a, int b){
          return a > b;
      }
    };

    vector<vector<int>> highFive(vector<vector<int>>& items) {

        vector< priority_queue<int,vector<int>,greater<int> > > processing_data(201);
        int count = 0;
        for(int i = 0; i < items.size(); i++){
            if (processing_data[items[i][0]].size() == 0) count++;
            if (processing_data[items[i][0]].size() >= 5){
                int small = processing_data[items[i][0]].top();
                if (small < items[i][1]){
                    processing_data[items[i][0]].pop();
                } else
                    continue;
            }
            processing_data[items[i][0]].push(items[i][1]);
        }
        vector<vector<int>> ans(count);
        count = 0;
        for (int i = 0; i < processing_data.size(); i++){
            if (processing_data[i].size() > 0){
                int ans_s = 0;
                while(processing_data[i].size() > 0){
                    ans_s += processing_data[i].top();
                    processing_data[i].pop();
                }
                ans_s /= 5;
                ans[count].push_back(i);
                ans[count].push_back(ans_s);
                count++;
            }
        }
        return ans;
    }
};
