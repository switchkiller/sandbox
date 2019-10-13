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

    void helper(TreeNode* root, vector<int>& result){
        if (!root) return;
        helper(root->left,result);
        result.push_back(root->val);
        helper(root->right,result);
    }

    void leftNode(TreeNode* root, stack<TreeNode*>& st){
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        //helper(root,result);
        stack<TreeNode*> st;
        leftNode(root,st);
        while(!st.empty()){
            // do something
            TreeNode *temp = st.top();
            result.push_back(temp->val);
            st.pop();
            leftNode(temp->right, st);
        }
        return result;
    }
};
