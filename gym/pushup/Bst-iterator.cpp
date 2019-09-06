/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *root;
    stack<TreeNode *> st;
public:
    void inorder_left(TreeNode *root){
        TreeNode *cp = root;
        while(cp){
            st.push(cp);
            cp = cp->left;
        }
    }

    BSTIterator(TreeNode* root) {
        this->root = root;
        inorder_left(root);
    }

    /** @return the next smallest number */
    int next() {
        if (st.empty()) return -1;
        TreeNode *tp = st.top();
        st.pop();
        if (!tp->left && !tp->right) return tp->val;
        inorder_left(tp->right);
        return tp->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
