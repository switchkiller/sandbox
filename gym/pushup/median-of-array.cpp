class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        int low = 0, high = m;

        while(low < high){

            int mid = (low + high)/2;

            int j = (n+m+1)/2-mid;

            if (max(nums1[mid-1],nums2[j-1]) <= min(nums1[mid], nums2[j])){
                low = mid;
                break;
            } else if(nums2[j-1] > nums1[mid]){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        // low is to be processed.

    }
};
