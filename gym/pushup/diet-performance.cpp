class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int calories_ = 0;
        int start = 0, cnt = 0, current_window_cal = 0;
        if (calories.size() == 0) return 0;
        for (int end = 0; end < calories.size(); end++){
            if (cnt < k){
                current_window_cal += calories[end];
                cnt++;
            }
            if (cnt == k){
                //cout << current_window_cal << endl;
                if (current_window_cal < lower) calories_--;
                if (current_window_cal > upper) calories_++;

                current_window_cal -= calories[start];
                start++;
                cnt--;
            }
        }
        return calories_;
    }
};
