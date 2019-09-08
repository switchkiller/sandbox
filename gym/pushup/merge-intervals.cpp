class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
           return a[0] < b[0];
        });

        vector<vector<int>> result;
        pair<int, int> prev_frame;
        for (int i = 0; i < intervals.size(); i++){
            if (i > 0){
                // do something

                if (intervals[i][0] <= prev_frame.second){
                    // combine them
                    if (prev_frame.second < intervals[i][1]){
                        // if new interval has greater limits update
                        prev_frame.second = intervals[i][1];
                    }
                    // else do nothing -> new interval ending time is still smaller
                } else{
                    result.push_back({prev_frame.first, prev_frame.second});
                    prev_frame = {intervals[i][0], intervals[i][1]};
                }
            }
            else{
                prev_frame = {intervals[i][0], intervals[i][1]};
            }

        }
        result.push_back({prev_frame.first, prev_frame.second});
        return result;
    }
};
