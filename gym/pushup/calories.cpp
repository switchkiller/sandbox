class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int totalPoint = 0, sum = 0;
        int i = 0, j = k-1;
        for (i = 0; i < k; i++){
            sum += calories[i];
        }
        i = 0;
        while (j < calories.size()){
            if (sum < lower) totalPoint -= 1;
            else if (sum > upper) totalPoint += 1;
            sum -= calories[i];
            i++; j++;
            if (j < calories.size())
            sum += calories[j];
        }
        return totalPoint;
    }
};
