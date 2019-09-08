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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        maxi = 0;
        findDiameter(root);
        return maxi - 1;
    }

    int findDiameter(TreeNode * root){
        if (!root) return 0;

        int l = findDiameter(root->left);
        int r = findDiameter(root->right);
        if (maxi < (l+r+1))
            maxi = l+r+1;
        return max(l,r)+1;
    }
};
