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
private:
    int maxi;

public:
    int maxPathSumUtil(TreeNode* root) {
        if (!root) return 0;
        // max path can exist in 3 case, in left subtree, in right subtree or combined

        // in case of combined, we simply return max path from any root to given root
        int l = maxPathSumUtil(root->left);
        int r = maxPathSumUtil(root->right);
        int sum = 0;
        if (l >= 0 && r >= 0)
            sum = l + r + root->val;
        else
            sum = max(max(l,r),0) + root->val;
        if (maxi < sum){
            maxi = sum;
        }
        return max(max(l,r),0)+root->val;
    }

    int maxPathSum(TreeNode *root){
        maxi = INT_MIN;
        maxPathSumUtil(root);
        return maxi;
    }
};
