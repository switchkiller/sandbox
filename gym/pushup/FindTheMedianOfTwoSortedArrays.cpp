// Naive solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        vector<int> ans;

        int i = 0, j = 0, k = 0;

        while(i < n1 && j < n2){
            if (nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            } else{
                ans.push_back(nums2[j]);
                j++;
            }
        }


        while(i < n1){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j < n2){
            ans.push_back(nums2[j]);
            j++;
        }

        k = ans.size();

        if (k % 2 == 0){
            double nas = (ans[k/2] + ans[k/2-1]);
            return nas/2;
        }
        else{
            return (double) ans[k/2];
        }
    }
};
