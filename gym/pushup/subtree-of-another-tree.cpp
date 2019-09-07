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
    bool isSubtreeChk(TreeNode *s, TreeNode *t){
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val == t->val){
            return isSubtreeChk(s->left, t->left) && isSubtreeChk(s->right, t->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false; // do something when null

        bool chk = isSubtreeChk(s,t);

        if (chk) return true;
        bool left = isSubtree(s->left, t);
        bool right = isSubtree(s->right, t);

        return (left || right);
    }
};
