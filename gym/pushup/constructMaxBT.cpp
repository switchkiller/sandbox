/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructedMaxBT(vector<int>& nums, int low, int high){
        if (low <= high){
        int maxVal = -1, maxIdx = -1;
        for (int i = low; i <= high; i++){
            if (maxVal < nums[i]){
                maxVal = nums[i];
                maxIdx = i;
            }
        }

        TreeNode *root = new TreeNode(maxVal);

        root->left = constructedMaxBT(nums,low,maxIdx-1);
        root->right = constructedMaxBT(nums,maxIdx+1,high);

        return root;
        }
        else return NULL;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructedMaxBT(nums, 0,nums.size()-1);
    }
};
