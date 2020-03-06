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

    bool validatePlease(TreeNode *root, long min, long max){
        if (root == nullptr) return true;

        bool left = validatePlease(root->left, min, root->val);
        bool right = validatePlease(root->right, root->val, max);

        if (left && right
            && (root->val > min)
            && (root->val < max))
            return true;
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return validatePlease(root, LONG_MIN, LONG_MAX);
    }
};
